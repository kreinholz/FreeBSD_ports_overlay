PORTNAME=	cemu-project
PORTVERSION=	2.6.242.g4ee027d
CATEGORIES=	emulators

MAINTAINER=	kreinholz@gmail.com
COMMENT=	Wii U Emulator
WWW=		https://cemu.info

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON= Espresso Recompiler backends only for aarch64, amd64

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers \
		rapidjson>0:devel/rapidjson \
		boost-libs>0:devel/boost-libs \
		glm>0:math/glm \
		glslang>0:graphics/glslang \
		spirv-tools>0:graphics/spirv-tools \
		libfmt>0:devel/libfmt \
		png>0:graphics/png

LIB_DEPENDS=	libpugixml.so:textproc/pugixml \
		libcurl.so:ftp/curl \
		libzip.so:archivers/libzip \
		libboost_program_options.so:devel/boost-libs \
		libwx_baseu-3.3.so:x11-toolkits/wxgtk33 \
		libwx_gtk3u_core-3.3.so:x11-toolkits/wxgtk33 \
		libwx_gtk3u_gl-3.3.so:x11-toolkits/wxgtk33 \
		libwx_gtk3u_propgrid-3.3.so:x11-toolkits/wxgtk33

USES=		cmake compiler:c++20-lang desktop-file-utils gl gnome \
		libtool perl5 pkgconfig sdl ssl xorg

USE_GITHUB=	yes
GH_ACCOUNT=	cemu-project
GH_PROJECT=	Cemu
GH_TAGNAME=	4ee027d
GH_TUPLE?=	mozilla:cubeb:2071354a69aca7ed6df3b4222e305746c2113f60:cubeb/dependencies/cubeb \
		arsenm:sanitizers-cmake:aab6948fa863bc1cbe5d0850bc46b9ef02ed4c1a:sanitizerscmake/dependencies/cubeb/cmake/sanitizers-cmake \
		Exzap:ZArchive:d2c717730092c7bf8cbb033b12fd4001b7c4d932:ZArchive/dependencies/ZArchive \
		ocornut:imgui:f65bcf481ab34cd07d3909aab1479f409fa79f2f:imgui/dependencies/imgui \
		fujitsu:xbyak_aarch64:v1.1.1-20-g904b892:xbyak_aarch64/dependencies/xbyak_aarch64

USE_GL=		gl glut
USE_GNOME=	gtk30
USE_SDL=	sdl3
USE_XORG=	x11

CMAKE_ARGS+=	-DENABLE_BLUEZ:BOOL=OFF \
		-DENABLE_DISCORD_RPC:BOOL=OFF \
		-DENABLE_FERAL_GAMEMODE:BOOL=OFF \
		-DENABLE_HIDAPI:BOOL=OFF \
		-DENABLE_VCPKG:BOOL=OFF

MAKE_ENV+=	DESTDIR="${STAGEDIR}"

ELF_FEATURES=	wxneeded:bin/Cemu

LDFLAGS+=	-Wl,--as-needed

DEBUG_CMAKE_ON=	wxWidgets_USE_DEBUG

OPTIONS_DEFINE=		NLS WAYLAND
OPTIONS_DEFAULT=	NLS WAYLAND
NLS_PLIST_SUB=		NLS=""

WAYLAND_DESC=		Build with Wayland support
WAYLAND_CMAKE_BOOL=	ENABLE_WAYLAND
WAYLAND_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland

pre-configure:
	@${PATCH} -d ${WRKSRC}/dependencies/xbyak_aarch64 -p1 < ${FILESDIR}/xbyak_aarch64_src_util_impl_freebsd.h.patch
	@${PATCH} -d ${WRKSRC}/dependencies/xbyak_aarch64 -p1 < ${FILESDIR}/xbyak_aarch64_src_util_impl.cpp.patch
	@${PATCH} -d ${WRKSRC}/dependencies/xbyak_aarch64 -p1 < ${FILESDIR}/xbyak_aarch64_xbyak_aarch64_xbyak_aarch64_util.h.patch

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Cemu_release ${STAGEDIR}${PREFIX}/bin/Cemu
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/dist/linux/info.cemu.Cemu.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/dist/linux/info.cemu.Cemu.metainfo.xml ${STAGEDIR}${PREFIX}/share/applications

	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps
	${INSTALL_DATA} ${WRKSRC}/dist/linux/info.cemu.Cemu.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps

	@${MKDIR} ${STAGEDIR}${PREFIX}/share/Cemu/gameProfiles/default
	${INSTALL_DATA} ${WRKSRC}/bin/gameProfiles/default/* ${STAGEDIR}${PREFIX}/share/Cemu/gameProfiles/default
	${INSTALL_DATA} ${WRKSRC}/dist/network_services.xml ${STAGEDIR}${PREFIX}/share/Cemu

	@${MKDIR} ${STAGEDIR}${PREFIX}/share/Cemu/resources/sharedFonts
	${INSTALL_DATA} ${WRKSRC}/bin/resources/sharedFonts/*.ttf ${STAGEDIR}${PREFIX}/share/Cemu/resources/sharedFonts
	
post-install-NLS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/Cemu/resources
	(cd ${WRKSRC}/bin/resources && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/Cemu/resources)

.include <bsd.port.mk>
