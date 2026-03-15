--- src/citra_qt/dumping/option_set_dialog.cpp.orig	2026-01-18 17:24:43 UTC
+++ src/citra_qt/dumping/option_set_dialog.cpp
@@ -27,7 +27,7 @@ static const std::unordered_map<AVOptionType, const ch
     {AV_OPT_TYPE_STRING, QT_TR_NOOP("string")},
     {AV_OPT_TYPE_DICT, QT_TR_NOOP("dictionary")},
     {AV_OPT_TYPE_VIDEO_RATE, QT_TR_NOOP("video rate")},
-    {AV_OPT_TYPE_CHANNEL_LAYOUT, QT_TR_NOOP("channel layout")},
+    {AV_OPT_TYPE_CHLAYOUT, QT_TR_NOOP("channel layout")},
 }};
 
 static const std::unordered_map<AVOptionType, const char*> TypeDescriptionMap{{
@@ -39,7 +39,7 @@ static const std::unordered_map<AVOptionType, const ch
     {AV_OPT_TYPE_DICT,
      QT_TR_NOOP("Comma-splitted list of &lt;key>=&lt;value>. Do not put spaces.")},
     {AV_OPT_TYPE_VIDEO_RATE, QT_TR_NOOP("&lt;num>/&lt;den>, or preset values like 'pal'.")},
-    {AV_OPT_TYPE_CHANNEL_LAYOUT, QT_TR_NOOP("Hexadecimal channel layout mask starting with '0x'.")},
+    {AV_OPT_TYPE_CHLAYOUT, QT_TR_NOOP("Hexadecimal channel layout mask starting with '0x'.")},
 }};
 
 /// Get the preset values of an option. returns {display value, real value}
