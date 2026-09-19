PORTNAME=	rexglue-sdk
DISTVERSION=	v0.10.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/rexglue/${PORTNAME}/archive/refs/tags/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	kreinholz@gmail.com
COMMENT=	ReXGlue converts Xbox 360 PowerPC code into portable C++ that runs natively on modern platforms
WWW=		https://github.com/rexglue/rexglue-sdk/tree/main

LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_NAME=	Tom Clay
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON= rexglue only supports ARM64/AARCH64 and X86_64/AMD64

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols

LIB_DEPENDS=	libimgui.so:x11-toolkits/imgui \
		libfmt.so:devel/libfmt \
		libspdlog.so:devel/spdlog \
		libwayland-client.so:graphics/wayland

USES=		cmake compiler:c++23-lang pkgconfig sdl xorg

CMAKE_ARGS+=	-DCMAKE_NO_PRESETS=ON \
		-DCMAKE_CXX_STANDARD=23 \
		-DCMAKE_BUILD_TYPE=Release
CMAKE_BUILD_DIR=	${WRKSRC}/out/build/linux-${ARCH}

CFLAGS+=	-march=x86-64-v2
CXXFLAGS+=	-march=x86-64-v2

USE_SDL=	sdl3
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	rexglue
GH_TUPLE?=	kyz:libmspack:v1.11:libmspack/thirdparty/libmspack \
		KhronosGroup:glslang:8.13.3743-252-gf4f1d8a3:glslang/thirdparty/glslang \
		wmarti:FFmpeg:0604b464c7cb4ebc94940cf1f324a3b26b87717c:FFmpeg/thirdparty/FFmpeg \
		marzer:tomlplusplus:30172438cee64926dc41fdd9c11fb3ba5b2ba9de:tomlplusplus/thirdparty/tomlplusplus \
		simd-everywhere:simde:71fd833d9666141edcd1d3c109a80e228303d8d7:simde/thirdparty/simde \
		Cyan4973:xxHash:e626a72bc2321cd320e953a0ccf1584cad60f363:xxHash/thirdparty/xxHash \
		catchorg:Catch2:v3.12.0:Catch2/thirdparty/catch2 \
		nemtrif:utfcpp:v2.3.4-141-g63d64de:utfcpp/thirdparty/utfcpp \
		KhronosGroup:Vulkan-Headers:v1.4.357:VulkanHeaders/thirdparty/vulkan-headers \
		GPUOpen-LibrariesAndSDKs:VulkanMemoryAllocator:v2.1.0-982-g1d8f600:VulkanMemoryAllocator/thirdparty/vulkan-memory-allocator \
		KhronosGroup:SPIRV-Tools:v2022.4-1284-g9a49b088:SPIRVTools/thirdparty/spirv-tools \
		KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-498-g29981f6:SPIRVHeaders/thirdparty/spirv-headers \
		CLIUtils:CLI11:v1.7.1-618-gbfffd37:CLI11/thirdparty/cli11 \
		pavel-kirienko:o1heap:388a73fd9007300e5130c5fe352d9ce3288b6dde:o1heap/thirdparty/o1heap \
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
	@${TOUCH} ${WRKSRC}/thirdparty/utfcpp/.git

post-patch:
	@${CP} ${FILESDIR}/config.h ${WRKSRC}/thirdparty/FFmpeg/

.include <bsd.port.mk>
