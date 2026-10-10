--- utils/version/gen_version.py.orig	2026-10-10 14:30:28 UTC
+++ utils/version/gen_version.py
@@ -36,12 +36,12 @@ def is_dirty():
     return output.decode('ASCII').strip()
 
 def is_dirty():
-    diff = get_output_of(["git", "diff", "HEAD", "--shortstat"])
+    diff = ""
     return len(diff.strip()) != 0
 
 def get_last_commit_sha():
     try:
-        sha = get_output_of(["git", "rev-parse", "--short", "HEAD"])
+        sha = "6e0fab36d"
         if is_dirty():
             sha += "-dirty"
         return sha
@@ -50,13 +50,13 @@ def get_current_branch():
 
 def get_current_branch():
     try:
-        return get_output_of(["git", "rev-parse", "--abbrev-ref", "HEAD"])
+        return "main"
     except subprocess.CalledProcessError:
         return "private"
 
 def get_commit_count(sha):
     try:
-        return get_output_of(["git", "rev-list", "--count", sha])
+        return "5565"
     except subprocess.CalledProcessError:
         return 0
     
