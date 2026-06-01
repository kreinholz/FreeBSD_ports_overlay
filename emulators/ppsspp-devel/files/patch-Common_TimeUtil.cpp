--- Common/TimeUtil.cpp.orig	2026-05-31 20:09:42 UTC
+++ Common/TimeUtil.cpp
@@ -245,6 +245,8 @@ double time_to_unix_utc(double t) {
 }
 
 double time_to_unix_utc(double t) {
+	struct timeval tv;
+	gettimeofday(&tv, nullptr);
 	return (double)tv.tv_sec + (double)tv.tv_usec * (1.0 / micros) + t;
 }
 
