--- ext/naett-lib/src/naett_internal.h.orig	2026-10-15 19:56:19 UTC
+++ ext/naett-lib/src/naett_internal.h
@@ -27,6 +27,10 @@
 #include <curl/curl.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <curl/curl.h>
+#endif
+
 #if __ANDROID__
 #include <jni.h>
 #include <pthread.h>
@@ -102,7 +106,7 @@ typedef struct {
     pthread_t workerThread;
     int closeRequested;
 #endif
-#if __LINUX__
+#if __LINUX__ || defined(__FreeBSD__)
     struct curl_slist* headerList;
 #endif
 #if __WINDOWS__
