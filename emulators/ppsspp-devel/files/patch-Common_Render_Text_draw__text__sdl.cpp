--- Common/Render/Text/draw_text_sdl.cpp.orig	2026-10-15 19:05:59 UTC
+++ Common/Render/Text/draw_text_sdl.cpp
@@ -12,6 +12,7 @@
 #include "Common/File/Path.h"
 #include "Common/Render/Text/draw_text.h"
 #include "Common/Render/Text/draw_text_sdl.h"
+#include <clocale>
 
 #if defined(USE_SDL3_TTF)
 
