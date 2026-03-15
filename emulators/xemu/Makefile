PORTNAME=	xemu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.134
CATEGORIES=	emulators

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
		py311-numpy>0:math/py-numpy \
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
		libslirp.so:net/libslirp \
		libpcap.so.1:net/libpcap \
		libcurl.so:ftp/curl \
		libsamplerate.so:audio/libsamplerate \
		libxxhash.so.0:devel/xxhash

USES=		gl gmake gnome pkgconfig python:build sdl shebangfix
USE_GL=		gl
USE_GNOME=	gtk30 glib20
USE_SDL=	sdl3 image3
SHEBANG_GLOB=	*.sh

USE_GITHUB=	yes
GH_ACCOUNT=	xemu-project
GH_TUPLE=	mborgerson:genconfig:42f85f9a2457e61d7e32542c07723565a284fcd6:genconfig/subprojects/genconfig \
		xemu-project:imgui:b911105fca3ca1b025706dd168e5798070f143a1:imgui/subprojects/imgui \
		xemu-project:implot:8553562dbb2025fd520f4bed57b094767b96c670:implot/subprojects/implot \
		qemu:keycodemapdb:f5772a62ec52591ff6870b7e8ef32482371f22c6:keycodemapdb/subprojects/keycodemapdb \
		xemu-project:nv2a_vsh_cpu:561fe80da57a881f89000256b459440c0178a7ce:nv2avshcpu/subprojects/nv2a_vsh_cpu \
		marzer:tomlplusplus:30172438cee64926dc41fdd9c11fb3ba5b2ba9de:tomlplusplus/subprojects/tomlplusplus

USE_GITLAB=	nodefault
GL_TUPLE=	qemu-project:berkeley-softfloat-3:b64af41c3276f97f0e181920400ee056b9c88037:berkeleysoftfloat3/subprojects/berkeley-softfloat-3 \
		qemu-project:berkeley-testfloat-3:e7af9751d9f9fd3b47911f51a5cfd08af256a9ab:berkeleytestfloat3/subprojects/berkeley-testfloat-3

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

XEMU_VERSION=	0.8.134
XEMU_COMMIT=	fc9980d2962cbec656253106ea2e121fab1e68d4

post-extract:
	@${CP} ${WRKSRC}/subprojects/packagefiles/berkeley-softfloat-3/* ${WRKSRC}/subprojects/berkeley-softfloat-3/
	@${CP} ${WRKSRC}/subprojects/packagefiles/berkeley-testfloat-3/* ${WRKSRC}/subprojects/berkeley-testfloat-3/

.include <bsd.port.pre.mk>

# Fix build on FreeBSD 15+ where native inotify is available
.if exists(/usr/include/sys/inotify.h)
EXTRA_PATCHES+= ${FILESDIR}/inotify-meson.build ${FILESDIR}/inotify-util_meson.build
.else
EXTRA_PATCHES+= ${FILESDIR}/kqueue-meson.build
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f -name "*.py" | \
		${XARGS} ${REINPLACE_CMD} -e 's|python3|python${PYTHON_VER}|g'
	@${FIND} ${WRKSRC} -type f -name "*.sh" | \
		${XARGS} ${REINPLACE_CMD} -e 's|python3|python${PYTHON_VER}|g'
	@${REINPLACE_CMD} -e 's|%%XEMU_VERSION%%|${XEMU_VERSION}|' \
		${WRKSRC}/XEMU_VERSION
	@${REINPLACE_CMD} -e 's|%%XEMU_COMMIT%%|${XEMU_COMMIT}|' \
		${WRKSRC}/XEMU_COMMIT
	@${REINPLACE_CMD} -e 's|SDL3_image|sdl3-image|' \
		${WRKSRC}/meson.build

OPTIONS_DEFINE=		AVX2 AVX512BW GETTEXT JACK PIPEWIRE PIXMAN PNG \
			PULSEAUDIO SNDIO SPICE SPICE_PROTOCOL VIRGLRENDERER
OPTIONS_DEFAULT=	AVX2 GETTEXT JACK PIPEWIRE PIXMAN PNG PULSEAUDIO SNDIO \
			VIRGLRENDERER

AVX2_DESC=		Build with AVX2 optimizations (requires Intel Haswell or newer CPU)
AVX2_VARS=		build_sh_args+="--enable-avx2"
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
