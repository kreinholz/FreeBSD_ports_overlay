--- ext/naett-lib/src/naett_curl.c.orig	2026-10-15 20:01:46 UTC
+++ ext/naett-lib/src/naett_curl.c
@@ -1,6 +1,6 @@
 // PPSSPP addition - not part of upstream naett. See naett_curl.h.
 
-#if __linux__ && !__ANDROID__
+#if (__linux__ || defined(__FreeBSD__)) && !__ANDROID__
 
 #define NAETT_CURL_INTERNAL
 #include "naett_curl.h"
