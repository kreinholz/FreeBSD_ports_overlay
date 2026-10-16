--- ext/naett-lib/src/naett_linux.c.orig	2026-10-15 19:59:06 UTC
+++ ext/naett-lib/src/naett_linux.c
@@ -1,6 +1,6 @@
 #include "naett_internal.h"
 
-#if __linux__ && !__ANDROID__
+#if (__linux__ || defined(__FreeBSD__)) && !__ANDROID__
 
 // PPSSPP: libcurl is dlopen'd rather than linked, see naett_curl.h. This header stands in
 // for <curl/curl.h> and redirects the curl_* calls below through function pointers.
