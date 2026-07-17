--- launcher/HardwareInfo.cpp.orig	2026-07-16 15:50:59 UTC
+++ launcher/HardwareInfo.cpp
@@ -21,12 +21,14 @@
 #include <QDebug>
 #include <QStringList>
 
+#if defined(Q_OS_MACOS) || defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 #if defined(Q_OS_MACOS) || defined(Q_OS_LINUX)
 namespace {
 QString afterColon(QString str)
 {
     return str.remove(0, str.indexOf(':') + 2).trimmed();
 }
+#endif
 
 template <typename F>
 bool readFromOutput(const char* command, F function)
@@ -55,7 +57,6 @@ bool readFromOutput(const char* command, F function)
     }
 
     return true;
-}
 }  // namespace
 #endif
 
