PORTNAME=	ppsspp
PORTVERSION=	1.20.4.424.g676724e
CATEGORIES=	emulators

MAINTAINER=	kreinholz@gmail.com
COMMENT=	PSP emulator in C++ with dynarec JIT for x86, ARM, MIPS
WWW=		https://www.ppsspp.org/

LICENSE=	GPLv2+ BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

# Bi-endian architectures default to big for some reason
NOT_FOR_ARCHS=	powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	only little-endian is supported, see \
		https://github.com/hrydgard/ppsspp/issues/8823

BUILD_DEPENDS=	rapidjson>0:devel/rapidjson

LIB_DEPENDS=	libchdr.so:devel/libchdr \
		libfreetype.so:print/freetype2 \
		libminiupnpc.so:net/miniupnpc \
		libopenxr_loader.so:graphics/openxr \
		libpng.so:graphics/png \
		libsnappy.so:archivers/snappy \
		libzip.so:archivers/libzip \
		libzstd.so:archivers/zstd
		
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		cmake compiler:c++11-lib gl localbase:ldflags pkgconfig \
		desktop-file-utils
USE_GITHUB=	yes
GH_ACCOUNT=	hrydgard
GH_PROJECT=	ppsspp
GH_TAGNAME=	676724e
GH_TUPLE?=	libretro:libretro-common:76a3d54feb0ee0ce9d59b90aa24694f3782063d3:libretrocommon/libretro/libretro-common \
		hrydgard:ppsspp-ffmpeg:18bbf9bf443ff2baceebab63cba85b9314a88b83:ppssppffmpeg/ffmpeg \
		Kingcom:armips:v0.11.0-195-ga8d71f0:armips/ext/armips \
		hrydgard:glslang:2.3-3991-g50e0708e:glslang/ext/glslang \
		KhronosGroup:SPIRV-Cross:4212eef67ed0ca048cb726a6767185504e7695e5:SPIRVCross/ext/SPIRV-Cross \
		unknownbrackets:ppsspp-debugger:9776332f720c854ef26f325a0cf9e32c02115a9c:ppssppdebugger/assets/debugger \
		google:cpu_features:v0.4.1-211-gfd4ffc1:cpu_features/ext/cpu_features \
		RetroAchievements:rcheevos:v12.3.0-8-gebfe8ca:rcheevos/ext/rcheevos \
		erkkah:naett:5f695cfa9fcbf30668a4d3ac4b4abf1cd89a1302:naett/ext/naett \
		hrydgard:ppsspp-lua:7648485f14e8e5ee45e8e39b1eb4d3206dbd405a:ppsspplua/ext/lua \
		hrydgard:nanosvg:478dbb8f7ed11c3d9b20b3986a8ee2283f483ef7:nanosvg/ext/nanosvg \
		Kethen:aemu_postoffice:530fee545c27ffb8524a8f496cbbcfdb687fe8c5:aemu_postoffice/ext/aemu_postoffice \
		Kingcom:filesystem:v1.1.2-171-g3f1c185:filesystem/ext/armips/ext/filesystem
EXCLUDE=	libzip zlib
USE_GL=		glew opengl
CMAKE_ON=	${FREETYPE LIBCHDR LIBZIP MINIUPNPC RAPIDJSON SNAPPY \
		ZSTD:L:S/^/USE_SYSTEM_/} BUILD_BUNDLED_FFMPEG \
		USE_VULKAN_DISPLAY_KHR
CMAKE_OFF=	USE_DISCORD
LDFLAGS+=	-Wl,--as-needed # ICE/SM/X11/Xext
CONFLICTS_INSTALL=	${PORTNAME}-*
EXTRACT_AFTER_ARGS=	${EXCLUDE:S,^,--exclude ,}

OPTIONS_DEFINE=		VULKAN
OPTIONS_DEFAULT=	VULKAN
.if !defined(PPSSPP_SLAVE)
USES+=			shared-mime-info sdl
USE_SDL=		sdl3 ttf3
ELF_FEATURES=		wxneeded:bin/${PORTNAME}
PORTDATA=		assets
DESKTOP_ENTRIES=	"PPSSPP" \
			"" \
			"${PORTNAME}" \
			"${PORTNAME} %f" \
			"Game;Emulators;" \
			""
.endif

.if defined(PPSSPP_SLAVE)
CMAKE_ON+=		LIBRETRO
VARS=			CONFLICTS_INSTALL= DESKTOP_ENTRIES= PLIST= PORTDATA= PKGMESSAGE= SUB_FILES=
.endif

VULKAN_DESC=		Vulkan renderer
VULKAN_RUN_DEPENDS=	${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader

post-patch:
	@${REINPLACE_CMD} -e 's/Linux/${OPSYS}/' ${WRKSRC}/assets/gamecontrollerdb.txt
	@${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,' ${WRKSRC}/UI/NativeApp.cpp
	@${REINPLACE_CMD} -e 's/"unknown"/"${DISTVERSIONFULL}"/' ${WRKSRC}/git-version.cmake

.if defined(PPSSPP_SLAVE)
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/libretro
	${INSTALL_LIB} ${BUILD_WRKSRC}/lib/${PORTNAME}_libretro.so \
		${STAGEDIR}${PREFIX}/lib/libretro/
.for d in applications icons mime ${PORTNAME}
	${RM} -r ${STAGEDIR}${PREFIX}/share/${d}
.endfor
.else
post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/PPSSPPSDL ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.endif

.include <bsd.port.mk>
