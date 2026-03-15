--- src/core/dumping/ffmpeg_backend.cpp.orig	2026-01-18 17:26:13 UTC
+++ src/core/dumping/ffmpeg_backend.cpp
@@ -956,7 +956,7 @@ std::string FormatDefaultValue(const AVOption* option,
     case AV_OPT_TYPE_VIDEO_RATE: {
         return ToStdString(option->default_val.str);
     }
-    case AV_OPT_TYPE_CHANNEL_LAYOUT: {
+    case AV_OPT_TYPE_CHLAYOUT: {
         return fmt::format("{:#x}", option->default_val.i64);
     }
     default:
