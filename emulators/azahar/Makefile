PORTNAME=	azahar
DISTVERSION=	2125.1.1
CATEGORIES=	emulators
MASTER_SITES=	https://github.com/azahar-emu/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}-unified-source-${DISTVERSION}

MAINTAINER=	kreinholz@gmail.com
COMMENT=	Nintendo 3DS emulator/debugger
WWW=		https://azahar-emu.org

LICENSE=	GPLv2+ ISCL
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/license.txt
LICENSE_FILE_ISCL=	${WRKSRC}/externals/cubeb/LICENSE

BROKEN_aarch64=	build fails on aarch64 with system boost-libs

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		cpp-httplib>0:www/cpp-httplib \
		glslang>0:graphics/glslang \
		robin-map>0:devel/robin-map \
		spirv-tools>0:graphics/spirv-tools \
		vulkan-headers>0:graphics/vulkan-headers

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libCatch2.so:devel/catch2 \
		libenet.so:net/enet \
		libfaad.so:audio/faad \
		libfmt.so:devel/libfmt \
		libinih.so:devel/inih \
		libSoundTouch.so:audio/soundtouch \
		libxxhash.so:devel/xxhash \
		libZycore.so:devel/zycore-c \
		libZydis.so:devel/zydis

USES=		cmake:testing compiler:c++17-lang localbase:ldflags pkgconfig \
		ssl tar:xz

CMAKE_ON=	Boost_USE_SHARED_LIBS \
		USE_SYSTEM_BOOST \
		USE_SYSTEM_CATCH2 \
		USE_SYSTEM_CPP_HTTPLIB \
		USE_SYSTEM_ENET \
		USE_SYSTEM_FAAD \
		USE_SYSTEM_FFMPEG_HEADERS \
		USE_SYSTEM_FMT \
		USE_SYSTEM_GLSLANG \
		USE_SYSTEM_INIH \
		USE_SYSTEM_JSON \
		USE_SYSTEM_OPENSSL \
		USE_SYSTEM_SOUNDTOUCH \
		USE_SYSTEM_SPIRV_TOOLS \
		USE_SYSTEM_SDL2 \
		USE_SYSTEM_VULKAN_HEADERS \
		USE_SYSTEM_XXHASH

CMAKE_OFF=	ENABLE_LIBUSB \
		ENABLE_OPENAL

LDFLAGS+=	-Wl,--as-needed

OPTIONS_DEFINE=		ALSA FFMPEG JACK PULSEAUDIO SNDIO VULKAN
OPTIONS_DEFAULT=	FFMPEG JACK PULSEAUDIO SNDIO VULKAN
OPTIONS_SINGLE=		GUI
OPTIONS_SINGLE_GUI=	LIBRETRO QT
OPTIONS_EXCLUDE:=	${OPTIONS_EXCLUDE} ${OPTIONS_SINGLE_GUI}
OPTIONS_SLAVE?=		QT

LIBRETRO_DESC=		libretro core for games/retroarch
LIBRETRO_CMAKE_BOOL=	ENABLE_LIBRETRO
LIBRETRO_PLIST_FILES=	lib/libretro/${PORTNAME}_libretro.so
LIBRETRO_VARS=		CONFLICTS_INSTALL= DESKTOP_ENTRIES= PLIST= PORTDATA= PKGMESSAGE= SUB_FILES=
LIBRETRO_CFLAGS=	-fPIC
QT_USES=		desktop-file-utils qt:6 shared-mime-info sdl
USE_SDL=		sdl2
QT_CMAKE_BOOL=		ENABLE_QT ENABLE_QT_TRANSLATION ENABLE_SDL2
USE_QT+=		base multimedia tools translations svg

ALSA_BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib
ALSA_CMAKE_BOOL=	USE_ALSA

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	ENABLE_FFMPEG_AUDIO_DECODER ENABLE_FFMPEG_VIDEO_DUMPER

JACK_BUILD_DEPENDS=	jackit>0:audio/jack
JACK_CMAKE_BOOL=	USE_JACK

PULSEAUDIO_BUILD_DEPENDS=pulseaudio>0:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSE

SNDIO_BUILD_DEPENDS=	sndio>0:audio/sndio
SNDIO_CMAKE_BOOL=	USE_SNDIO

VULKAN_DESC=		Vulkan renderer (experimental)
VULKAN_BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
VULKAN_CMAKE_BOOL=	ENABLE_VULKAN

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/@GIT_BRANCH@/master/' \
		-e 's/@GIT_DESC@/${GH_TAGNAME}/' \
		-e 's/@BUILD_FULLNAME@/${PORTVERSION}/' \
		${WRKSRC}/src/common/scm_rev.cpp.in

do-install-LIBRETRO-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/${LIBRETRO_PLIST_FILES:H}
	${INSTALL_LIB} ${BUILD_WRKSRC}/bin/Release/${PORTNAME}_libretro.so \
		${STAGEDIR}${PREFIX}/${LIBRETRO_PLIST_FILES:H}
.if ${OPTIONS_SLAVE} == LIBRETRO
.  for d in applications icons mime ${PORTNAME}
	${RM} -r ${STAGEDIR}${PREFIX}/share/${d}
.  endfor
.endif

do-install-QT-on:
	${RM} ${STAGEDIR}${PREFIX}/lib/libcitra_room.a

.include <bsd.port.post.mk>
