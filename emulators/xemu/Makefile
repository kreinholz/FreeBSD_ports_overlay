PORTNAME=	xemu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.134
CATEGORIES=	emulators
MASTER_SITES=	https://github.com/xemu-project/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	kreinholz@gmail.com
COMMENT=	A free and open-source application that emulates the original \
		Microsoft Xbox game console, enabling people to play their \
		original Xbox games on Windows, macOS, and Linux systems
WWW=		https://xemu.app/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gdb>0:devel/gdb \
		cdrkit-genisoimage>0:sysutils/genisoimage \
		cdrtools>0:sysutils/cdrtools \
		bash>0:shells/bash \
		cmake-core>0:devel/cmake-core \
		meson>0:devel/meson \
		ninja>0:devel/ninja \
		bison>0:devel/bison \
		ccache>0:devel/ccache \
		cmocka>0:sysutils/cmocka \
		cyrus-sasl>0:security/cyrus-sasl2 \
		diffutils>0:textproc/diffutils \
		gsed>0:textproc/gsed \
		gtk-vnc>0:net/gtk-vnc \
		json-c>0:devel/json-c \
		libjpeg-turbo>0:graphics/libjpeg-turbo \
		libtasn1>0:security/libtasn1 \
		mtools>0:filesystems/mtools \
		opencv>0:graphics/opencv \
		py311-pillow>0:graphics/py-pillow \
		py311-pip>0:devel/py-pip \
		py311-pyyaml>0:devel/py-pyyaml \
		py311-sphinx>0:textproc/py-sphinx \
		py311-sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme \
		py311-tomli>0:textproc/py-tomli \
		rpm2cpio>0:archivers/rpm2cpio \
		socat>0:net/socat \
		tesseract>0:graphics/tesseract \
		xorriso>0:sysutils/xorriso \
		nlohmann-json>0:devel/nlohmann-json

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libepoxy.so:graphics/libepoxy \
		libffi.so:devel/libffi \
		libpulse.so:audio/pulseaudio \
		libslirp.so:net/libslirp \
		libsndio.so:audio/sndio \
		libpcap.so.1:net/libpcap \
		libcurl.so:ftp/curl \
		libsamplerate.so:audio/libsamplerate \
		libxxhash.so.0:devel/xxhash

USES=		gl gmake gnome pkgconfig python:3.9+,build sdl shebangfix tar:zst
USE_GL=		gl
USE_GNOME=	gtk30 glib20
USE_SDL=	sdl3 image3
PYTHON_BUILD_DEPENDS=	${PYNUMPY}
SHEBANG_GLOB=	*.sh

LDFLAGS+=	-Wl,--as-needed

MESON_ARGS+=	--wrap-mode=nodownload

PLIST_FILES=	bin/xemu \
		share/applications/xemu.desktop \
		share/applications/xemu.metainfo.xml \
		share/icons/hicolor/scalable/apps/xemu.svg \
		share/icons/hicolor/256x256/apps/xemu.png \
		share/icons/hicolor/128x128/apps/xemu.png \
		share/icons/hicolor/64x64/apps/xemu.png \
		share/icons/hicolor/48x48/apps/xemu.png \
		share/icons/hicolor/32x32/apps/xemu.png \
		share/icons/hicolor/24x24/apps/xemu.png

post-extract:
	@${CP} ${WRKSRC}/subprojects/packagefiles/berkeley-softfloat-3/* ${WRKSRC}/subprojects/berkeley-softfloat-3/
	@${CP} ${WRKSRC}/subprojects/packagefiles/berkeley-testfloat-3/* ${WRKSRC}/subprojects/berkeley-testfloat-3/

post-patch:
	@${REINPLACE_CMD} -e 's|python3|python${PYTHON_VER}|g' \
		${WRKSRC}/scripts/pack-file.py \
		${WRKSRC}/build.sh

OPTIONS_DEFINE=		AVX512BW GETTEXT JACK PIPEWIRE PIXMAN PNG \
			PULSEAUDIO SNDIO SPICE SPICE_PROTOCOL VIRGLRENDERER
OPTIONS_DEFAULT=	GETTEXT JACK PIPEWIRE PIXMAN PNG PULSEAUDIO SNDIO \
			VIRGLRENDERER

AVX512BW_DESC=		Build with AVX512BW optimizations (requires Intel Skylake or newer CPU)
AVX512BW_VARS=		build_sh_args+="--enable-avx512bw"
GETTEXT_DESC=		Localization of the GTK+ user interface
GETTEXT_BUILD_DEPENDS=	gettext-tools>0:devel/gettext-tools
GETTEXT_VARS=		build_sh_args+="--enable-gettext"
JACK_DESC=		JACK sound support
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_VARS=		build_sh_args+="--enable-jack"
PIPEWIRE_DESC=		PipeWire sound support
PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_VARS=		build_sh_args+="--enable-pipewire"
PIXMAN_DESC=		Build with pixman support
PIXMAN_LIB_DEPENDS=	libpixman-1.so:x11/pixman
PIXMAN_VARS=		build_sh_args+="--enable-pixman"
PNG_DESC=		PNG support with libpng
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_VARS=		build_sh_args+="--enable-png"
PULSEAUDIO_DESC=	PulseAudio sound support
PULSEAUDIO_BUILD_DEPENDS=	pulseaudio>0:audio/pulseaudio
PULSEAUDIO_VARS=	build_sh_args+="--enable-pa"
SNDIO_DESC=		sndio sound support
SNDIO_BUILD_DEPENDS=	sndio>0:audio/sndio
SNDIO_VARS=		build_sh_args+="--enable-sndio"
SPICE_DESC=		Spice server support
SPICE_LIB_DEPENDS=	libspice-server.so:devel/libspice-server
SPICE_VARS=		build_sh_args+="--enable-spice"
SPICE_PROTOCOL_DESC=	Spice protocol support
SPICE_PROTOCOL_BUILD_DEPENDS=	spice-protocol>0:devel/spice-protocol
SPICE_PROTOCOL_VARS=	build_sh_args+="--enable-spice-protocol"
VIRGLRENDERER_DESC=	virgl rendering support
VIRGLRENDERER_BUILD_DEPENDS=	virglrenderer>0:x11/virglrenderer
VIRGLRENDERER_VARS=	build_sh_args+="--enable-virglrenderer"

do-build:
	cd ${WRKSRC} && ./build.sh --disable-docs --disable-download --enable-sdl-image ${BUILD_SH_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dist/xemu ${STAGEDIR}${PREFIX}/bin/xemu
	${INSTALL_KLD} ${WRKSRC}/ui/xemu.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_KLD} ${WRKSRC}/xemu.metainfo.xml ${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_KLD} ${WRKSRC}/ui/icons/xemu.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps
	${INSTALL_KLD} ${WRKSRC}/ui/icons/xemu_256x256.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/xemu.png
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps
	${INSTALL_KLD} ${WRKSRC}/ui/icons/xemu_128x128.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/xemu.png
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps
	${INSTALL_KLD} ${WRKSRC}/ui/icons/xemu_64x64.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/xemu.png
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps
	${INSTALL_KLD} ${WRKSRC}/ui/icons/xemu_48x48.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/xemu.png
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps
	${INSTALL_KLD} ${WRKSRC}/ui/icons/xemu_32x32.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/xemu.png
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/24x24/apps
	${INSTALL_KLD} ${WRKSRC}/ui/icons/xemu_24x24.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/24x24/apps/xemu.png

.include <bsd.port.mk>
