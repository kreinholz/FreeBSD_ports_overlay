--- ui/xemu-os-utils-linux.c.orig	2026-03-03 15:07:43 UTC
+++ ui/xemu-os-utils-linux.c
@@ -21,8 +21,8 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <assert.h>
-#include <glib.h>
-#include <glib/gprintf.h>
+#include <glib-2.0/glib.h>
+#include <glib-2.0/glib/gprintf.h>
 
 static char *read_file_if_possible(const char *path)
 {
@@ -54,7 +54,7 @@ const char *xemu_get_os_info(void)
 	if (!attempted_init) {
 		char *os_release = NULL;
 
-		// Try to get the Linux distro "pretty name" from /etc/os-release
+		// Try to get the FreeBSD "pretty name" from /etc/os-release
 		char *os_release_file = read_file_if_possible("/etc/os-release");
 		if (os_release_file != NULL) {
 			char *pretty_name = strstr(os_release_file, "PRETTY_NAME=\"");
@@ -73,7 +73,7 @@ const char *xemu_get_os_info(void)
 		}
 
 		os_info = g_strdup_printf("%s",
-			os_release ? os_release : "Unknown Distro"
+			os_release ? os_release : "Unknown FreeBSD"
 			);
 		if (os_release) {
 			free(os_release);
