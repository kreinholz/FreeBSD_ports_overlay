--- build.sh.orig	2025-09-07 15:26:13 UTC
+++ build.sh
@@ -79,7 +79,7 @@ package_macos() {
     python3 ./scripts/gen-license.py --version-file=macos-libs/$target_arch/INSTALLED > dist/LICENSE.txt
 }
 
-package_linux() {
+package_freebsd() {
     rm -rf dist
     mkdir -p dist
     cp build/qemu-system-i386 dist/xemu
@@ -193,11 +193,11 @@ case "$platform" in # Adjust compilation options based
 }
 
 case "$platform" in # Adjust compilation options based on platform
-    Linux)
-        echo 'Compiling for Linux...'
+    FreeBSD)
+        echo 'Compiling for FreeBSD...'
         sys_cflags='-Wno-error=redundant-decls'
         opts="$opts --disable-werror"
-        postbuild='package_linux'
+        postbuild='package_freebsd'
         ;;
     Darwin)
         echo "Compiling for MacOS for $target_arch..."
@@ -269,6 +269,6 @@ set -x # Print commands from now on
     ${opts} \
     "$@"
 
-time make -j"${job_count}" ${target} 2>&1 | tee build.log
+time gmake -j"${job_count}" ${target} 2>&1 | tee build.log
 
 "${postbuild}" # call post build functions
