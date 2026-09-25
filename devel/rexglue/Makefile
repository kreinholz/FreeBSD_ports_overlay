PORTNAME=	rexglue-sdk
DISTVERSION=	v0.10.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	kreinholz@gmail.com
COMMENT=	ReXGlue converts Xbox 360 PowerPC code into portable C++ that runs natively on modern platforms
WWW=		https://github.com/rexglue/rexglue-sdk/tree/main

LICENSE=	custom
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_NAME=	Tom Clay
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON= rexglue only supports ARM64/AARCH64 and X86_64/AMD64

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols \
		vulkan-headers>0:graphics/vulkan-headers

# Note: in poudriere, unlike live system, USE_XORG fails with
# bundled SDL3 submodule, so we must list xorg components here
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libvulkan.so:graphics/vulkan-loader \
		libX11.so:x11/libX11 \
		libXcursor.so:x11/libXcursor \
		libXext.so:x11/libXext \
		libXi.so:x11/xinput \
		libXfixes.so:x11/libXfixes \
		libXrandr.so:x11/libXrandr \
		libXss.so:x11/libXScrnSaver \
		libXtst.so:x11/libXtst

USES=		cmake compiler:c++23-lang pkgconfig xorg

# To do - currently, pkg-plist is hardcoded to a Release build. This will need to be fixed
OPTIONS_SINGLE=		CMAKE_BUILD
OPTIONS_SINGLE_CMAKE_BUILD=	RELEASE DEBUG RELWITHDEBINFO

OPTIONS_DEFAULT=	RELEASE

RELEASE_DESC=		Build Release version
DEBUG_DESC=			Build Debug version
RELWITHDEBINFO_DESC=	Build RelWithDebInfo version

RELEASE_CMAKE_ON=	-DCMAKE_BUILD_TYPE:STRING=Release
DEBUG_CMAKE_ON=		-DCMAKE_BUILD_TYPE:STRING=Debug
RELWITHDEBINFO_CMAKE_ON=	-DCMAKE_BUILD_TYPE:STRING=RelWithDebInfo

CMAKE_ARGS+=	-DCMAKE_NO_PRESETS=ON \
		-DCMAKE_CXX_STANDARD=23 \
		
CMAKE_BUILD_DIR=	${WRKSRC}/out/build/linux-${ARCH}

.include <bsd.port.options.mk>

.if ${ARCH} == amd64
CFLAGS+=	-march=x86-64-v2
CXXFLAGS+=	-march=x86-64-v2
.endif

.if ${OSVERSION} < 1501000
IGNORE=	requires FreeBSD 15.1 or later due to libc++ shortcomings
.endif

USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	rexglue
GH_PROJECT=	rexglue-sdk
GH_TAGNAME=	${DISTVERSION}
GH_TUPLE?=	kyz:libmspack:v1.11:libmspack/thirdparty/libmspack \
		KhronosGroup:glslang:8.13.3743-252-gf4f1d8a3:glslang/thirdparty/glslang \
		wmarti:FFmpeg:0604b464c7cb4ebc94940cf1f324a3b26b87717c:FFmpeg/thirdparty/FFmpeg \
		marzer:tomlplusplus:30172438cee64926dc41fdd9c11fb3ba5b2ba9de:tomlplusplus/thirdparty/tomlplusplus \
		simd-everywhere:simde:71fd833d9666141edcd1d3c109a80e228303d8d7:simde/thirdparty/simde \
		Cyan4973:xxHash:e626a72bc2321cd320e953a0ccf1584cad60f363:xxHash/thirdparty/xxHash \
		gabime:spdlog:v1.2.1-2548-g79524ddd:spdlog/thirdparty/spdlog \
		fmtlib:fmt:407c905e45ad75fc29bf0f9bb7c5c2fd3475976f:fmt/thirdparty/fmt \
		catchorg:Catch2:v3.12.0:Catch2/thirdparty/catch2 \
		nemtrif:utfcpp:v2.3.4-141-g63d64de:utfcpp/thirdparty/utfcpp \
		KhronosGroup:Vulkan-Headers:v1.4.357:VulkanHeaders/thirdparty/vulkan-headers \
		GPUOpen-LibrariesAndSDKs:VulkanMemoryAllocator:v2.1.0-982-g1d8f600:VulkanMemoryAllocator/thirdparty/vulkan-memory-allocator \
		ocornut:imgui:v1.62-5055-g6d910d548:imgui/thirdparty/imgui \
		KhronosGroup:SPIRV-Tools:v2022.4-1284-g9a49b088:SPIRVTools/thirdparty/spirv-tools \
		KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-498-g29981f6:SPIRVHeaders/thirdparty/spirv-headers \
		CLIUtils:CLI11:v1.7.1-618-gbfffd37:CLI11/thirdparty/cli11 \
		pavel-kirienko:o1heap:388a73fd9007300e5130c5fe352d9ce3288b6dde:o1heap/thirdparty/o1heap \
		libsdl-org:SDL:8bf3b7215ad9fc3deb583c6a3a37c6c67f2e24e4:SDL/thirdparty/sdl3 \
		pantor:inja:7d1b4600b68595085a949743331c2e5673f511ea:inja/thirdparty/inja \
		wolfpld:tracy:05cceee0df3b8d7c6fa87e9638af311dbabc63cb:tracy/thirdparty/tracy \
		nemequ:munit:v0.2.0-37-gda8f734:munit/thirdparty/simde/test/munit

LDFLAGS+=	-Wl,--as-needed

PREFIX=		${LOCALBASE}/rexglue-sdk	# avoid system lib conflicts

post-extract:
	@${TOUCH} ${WRKSRC}/thirdparty/cli11/.git
	@${TOUCH} ${WRKSRC}/thirdparty/libmspack/.git
	@${TOUCH} ${WRKSRC}/thirdparty/FFmpeg/.git
	@${TOUCH} ${WRKSRC}/thirdparty/tomlplusplus/.git
	@${TOUCH} ${WRKSRC}/thirdparty/simde/.git
	@${TOUCH} ${WRKSRC}/thirdparty/xxHash/.git
	@${TOUCH} ${WRKSRC}/thirdparty/spdlog/.git
	@${TOUCH} ${WRKSRC}/thirdparty/fmt/.git
	@${TOUCH} ${WRKSRC}/thirdparty/utfcpp/.git
	@${TOUCH} ${WRKSRC}/thirdparty/imgui/.git
	@${TOUCH} ${WRKSRC}/thirdparty/sdl3/.git
	@${TOUCH} ${WRKSRC}/thirdparty/vulkan-headers/.git
	@${TOUCH} ${WRKSRC}/thirdparty/vulkan-memory-allocator/.git
	@${TOUCH} ${WRKSRC}/thirdparty/spirv-headers/.git
	@${TOUCH} ${WRKSRC}/thirdparty/spirv-tools/.git
	@${TOUCH} ${WRKSRC}/thirdparty/glslang/.git
	@${TOUCH} ${WRKSRC}/thirdparty/tracy/.git
	@${ECHO_CMD} "SDL-rexglue-bundled-g8bf3b7215" > \
		${WRKSRC}/thirdparty/sdl3/REVISION.txt

post-patch:
	@${CP} ${FILESDIR}/config.h ${WRKSRC}/thirdparty/FFmpeg/

.include <bsd.port.mk>
