--- src/core/dumping/ffmpeg_backend.cpp.orig	2026-09-15 18:16:22 UTC
+++ src/core/dumping/ffmpeg_backend.cpp
@@ -175,11 +175,25 @@ bool FFmpegVideoStream::Init(FFmpegMuxer& muxer, const
     auto pixel_format_opt = FFmpeg::av_dict_get(options, "pixel_format", nullptr, 0);
     if (pixel_format_opt) {
         sw_pixel_format = FFmpeg::av_get_pix_fmt(pixel_format_opt->value);
-    } else if (codec->pix_fmts) {
+
+// FFmpeg 7/8/9
+#if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(61, 13, 100)
+    const enum AVPixelFormat* supported_pix_fmts = nullptr;
+    int ret = FFmpeg::avcodec_get_supported_config(codec_context.get(), codec,
+		AV_CODEC_CONFIG_PIX_FMTS, 0,
+		reinterpret_cast<const void**>(&supported_pix_fmts), nullptr);
+    if (ret >= 0 && supported_pix_fmts) {
+	sw_pixel_format = GetPixelFormat(codec_context.get(), supported_pix_fmts);
+    } else {
+	sw_pixel_format = AV_PIX_FMT_YUV420P;
+    }
+#else
+    if (codec->pix_fmts) {
         sw_pixel_format = GetPixelFormat(codec_context.get(), codec->pix_fmts);
     } else {
         sw_pixel_format = AV_PIX_FMT_YUV420P;
     }
+#endif
     if (sw_pixel_format == AV_PIX_FMT_NONE) {
         // This encoder requires HW context configuration.
         if (!InitHWContext(codec)) {
@@ -468,12 +482,31 @@ bool FFmpegAudioStream::Init(FFmpegMuxer& muxer) {
     // Configure audio codec context
     codec_context->codec_type = AVMEDIA_TYPE_AUDIO;
     codec_context->bit_rate = Settings::values.audio_bitrate;
-    if (codec->sample_fmts) {
-        codec_context->sample_fmt = codec->sample_fmts[0];
+
+// FFmpeg 7/8/9
+#if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(61, 13, 100)
+    const enum AVSampleFormat* supported_sample_fmts = nullptr;
+    int ret_fmt = FFmpeg::avcodec_get_supported_config(codec_context.get(), codec, AV_CODEC_CONFIG_SAMPLE_FORMAT, 0, reinterpret_cast<const void**>(&supported_sample_fmts), nullptr);
+    codec_context->sample_fmt = (ret_fmt >= 0 && supported_sample_fmts && supported_sample_fmts[0] != AV_SAMPLE_FMT_NONE) ? supported_sample_fmts[0] : AV_SAMPLE_FMT_S16P;
+#else
+    codec_context->sample_fmt = (codec->sample_fmts) ? codec->sample_fmts[0] : AV_SAMPLE_FMT_S16P;
+#endif
+
+#if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(61, 13, 100)
+    const int* supported_rates = nullptr;
+    int ret_rate = FFmpeg::avcodec_get_supported_config(codec_context.get(), codec, AV_CODEC_CONFIG_SAMPLE_RATE, 0, reinterpret_cast<const void**>(&supported_rates), nullptr);
+    if (ret_rate >= 0 && supported_rates && supported_rates[0] ! 0) {
+	codec_context->sample_rate = supported_rates[0];
+	for (const int* ptr = supported_rates; *ptr; ptr++) {
+	    if (*ptr == AudioCore::native_sample_rate) {
+		codec_context->sample_rate = AudioCore::native_sample_rate;
+		break;
+	    }
+	}
     } else {
-        codec_context->sample_fmt = AV_SAMPLE_FMT_S16P;
+	codec_context->sample_rate = AudioCore::native_sample_rate;
     }
-
+#else
     if (codec->supported_samplerates) {
         codec_context->sample_rate = codec->supported_samplerates[0];
         // Prefer native sample rate if supported
@@ -488,6 +521,7 @@ bool FFmpegAudioStream::Init(FFmpegMuxer& muxer) {
     } else {
         codec_context->sample_rate = AudioCore::native_sample_rate;
     }
+#endif
     codec_context->time_base.num = 1;
     codec_context->time_base.den = codec_context->sample_rate;
 #if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(59, 24, 100) // lavc 59.24.100
@@ -956,7 +990,7 @@ std::string FormatDefaultValue(const AVOption* option,
     case AV_OPT_TYPE_VIDEO_RATE: {
         return ToStdString(option->default_val.str);
     }
-    case AV_OPT_TYPE_CHANNEL_LAYOUT: {
+    case AV_OPT_TYPE_CHLAYOUT: {
         return fmt::format("{:#x}", option->default_val.i64);
     }
     default:
