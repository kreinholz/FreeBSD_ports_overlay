--- utils/GetCommitInfo.py.orig	2026-10-10 15:13:06 UTC
+++ utils/GetCommitInfo.py
@@ -6,16 +6,14 @@ def git_get_commit_hash():
 
 def git_get_commit_hash():
     try:
-        return subprocess.check_output(
-            ['git', 'rev-parse', '--short=8', 'HEAD']).decode('ascii').strip()
+        return "416fab6b"
     except subprocess.CalledProcessError:
         return "00000000"
 
 
 def git_get_commit_count():
     try:
-        return subprocess.check_output(
-            ['git', 'rev-list', '--count', 'HEAD']).decode('ascii').strip()
+        return "4662"
     except subprocess.CalledProcessError:
         return 0
 
