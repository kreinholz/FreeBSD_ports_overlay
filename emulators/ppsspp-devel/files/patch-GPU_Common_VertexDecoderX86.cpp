--- GPU/Common/VertexDecoderX86.cpp.orig	2026-10-15 18:46:09 UTC
+++ GPU/Common/VertexDecoderX86.cpp
@@ -1300,24 +1300,19 @@ void VertexDecoderJitCache::Jit_PosFloat() {
 }
 
 void VertexDecoderJitCache::Jit_PosFloat() {
-	// Load the constants we need.
-	alignas(16) static const float fltMax[4] = {FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX,};
-	alignas(16) static const float fltMaxNeg[4] = {-FLT_MAX, -FLT_MAX, -FLT_MAX, -FLT_MAX,};
-	if (RipAccessible(&fltMax)) {
-		MOVAPS(fpScratchReg2, M(&fltMax));  // rip accessible
-		MOVAPS(fpScratchReg3, M(&fltMaxNeg));
+	if (cpu_info.Mode64bit) {
+		MOV(64, R(tempReg1), MDisp(srcReg, dec_->posoff));
+		MOV(32, R(tempReg3), MDisp(srcReg, dec_->posoff + 8));
+		MOV(64, MDisp(dstReg, dec_->decFmt.posoff), R(tempReg1));
+		MOV(32, MDisp(dstReg, dec_->decFmt.posoff + 8), R(tempReg3));
 	} else {
-		MOV(PTRBITS, R(tempReg1), ImmPtr(&fltMax));
-		MOVAPS(fpScratchReg2, MatR(tempReg1));
-		MOV(PTRBITS, R(tempReg1), ImmPtr(&fltMaxNeg));
-		MOVAPS(fpScratchReg3, MatR(tempReg1));
+		MOV(32, R(tempReg1), MDisp(srcReg, dec_->posoff));
+		MOV(32, R(tempReg2), MDisp(srcReg, dec_->posoff + 4));
+		MOV(32, R(tempReg3), MDisp(srcReg, dec_->posoff + 8));
+		MOV(32, MDisp(dstReg, dec_->decFmt.posoff), R(tempReg1));
+		MOV(32, MDisp(dstReg, dec_->decFmt.posoff + 4), R(tempReg2));
+		MOV(32, MDisp(dstReg, dec_->decFmt.posoff + 8), R(tempReg3));
 	}
-
-	MOVUPS(fpScratchReg, MDisp(srcReg, dec_->posoff));
-	MINPS(fpScratchReg, R(fpScratchReg2));
-	MAXPS(fpScratchReg, R(fpScratchReg3));
-	// Just store 4 floats. We'll overwrite the last one with other components or the next vertex.
-	MOVUPS(MDisp(dstReg, dec_->decFmt.posoff), fpScratchReg);
 }
 
 void VertexDecoderJitCache::Jit_PosS8Skin() {
