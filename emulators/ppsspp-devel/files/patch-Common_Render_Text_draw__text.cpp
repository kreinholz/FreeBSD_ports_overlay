--- Common/Render/Text/draw_text.cpp.orig	2026-05-31 19:44:44 UTC
+++ Common/Render/Text/draw_text.cpp
@@ -1,6 +1,6 @@
 #include "ppsspp_config.h"
 
-#if defined(__linux__) && !defined(__ANDROID__)
+#if defined(__linux__) || defined(__FreeBSD__) && !defined(__ANDROID__)
 # include <dlfcn.h>
 #elif defined(_WIN32)
 # include <windows.h>
@@ -29,13 +29,15 @@ static bool IsRenderDocLoaded() {
 	return false;
 #elif defined(_WIN32)
 	return (GetModuleHandleA("renderdoc.dll") != nullptr);
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 	// Returns a pointer if loaded, otherwise null
 	void* handle = dlopen("librenderdoc.so", RTLD_NOW | RTLD_NOLOAD);
 	if (handle) {
 		dlclose(handle);
 		return true;
 	}
+	return false;
+#else
 	return false;
 #endif
 }
