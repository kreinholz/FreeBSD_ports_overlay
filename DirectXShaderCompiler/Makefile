PORTNAME=	DirectXShaderCompiler
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.2605.37
CATEGORIES=	devel
MASTER_SITES=	https://github.com/microsoft/${PORTNAME}/archive/refs/tags/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-v${DISTVERSION}

MAINTAINER=	kreinholz@gmail.com
COMMENT=	compiler and related tools to compile HLSL programs into DXIL for DirectX and SPIR-V for Vulkan
WWW=		https://github.com/microsoft/DirectXShaderCompiler

LICENSE_FILE=	${WRKSRC}/LICENSE.TXT
LICENSE_NAME=	LLVM
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake:testing compiler:c++17-lang python:build

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
GH_PROJECT=	DirectXShaderCompiler
GH_TUPLE?=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-498-g29981f6:SPIRVHeaders/external/SPIRV-Headers \
		KhronosGroup:SPIRV-Tools:v2022.4-1308-g1c336172:SPIRVTools/external/SPIRV-Tools \
		microsoft:DirectX-Headers:980971e835876dc0cde415e8f9bc646e64667bf7:DirectXHeaders/external/DirectX-Headers

USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

CMAKE_ARGS+=	-C ${FILESDIR}/PredefinedParams.cmake \

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_LibXml2 \
		CMAKE_DISABLE_FIND_PACKAGE_MetalIRConverter \
		HSLS_ENABLE_FIXED_VER \
		LLVM_INSTALL_TOOLCHAIN_ONLY

CMAKE_OFF=	HLSL_INCLUDE_TESTS \
		HLSL_SUPPORT_QUERY_GIT_COMMIT_INFO \
		LLVM_BUILD_TOOLS \
		LLVM_INCLUDE_TESTS \
		LLVM_INCLUDE_UTILS \
		SPIRV_BUILD_TESTS

CMAKE_TESTING_ON=	HLSL_INCLUDE_TESTS \
			SPIRV_BUILD_TESTS

#		-DLLVM_ENABLE_ASSERTIONS=ON \
#		-DLLVM_LIT_ARGS="-v" \
#		-DHLSL_OPTIONAL_PROJS_IN_DEFAULT=ON \
#		-DCMAKE_NO_SYSTEM_FROM_IMPORTED=ON \
#		-DCMAKE_BUILD_TYPE=Release \
#		-DCMAKE_IGNORE_PREFIX_PATH="${LOCALBASE}" \
#		-DCMAKE_IGNORE_PATH="${LOCALBASE}/include"

.include <bsd.port.mk>
