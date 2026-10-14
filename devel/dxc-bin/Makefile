PORTNAME=	DirectXShaderCompiler
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.2407
CATEGORIES=	devel
MASTER_SITES=	https://github.com/microsoft/${PORTNAME}/archive/refs/tags/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-v${DISTVERSION}

MAINTAINER=	kreinholz@gmail.com
COMMENT=	compiler and related tools to compile HLSL programs into DXIL for DirectX and SPIR-V for Vulkan
WWW=		https://github.com/microsoft/DirectXShaderCompiler

LICENSE_FILE=	${WRKSRC}/LICENSE.TXT
LICENSE_NAME=	LLVM
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	clang18:devel/llvm18

USES=		cmake:testing compiler:c++11-lang python:build

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
GH_PROJECT=	DirectXShaderCompiler
GH_TAGNAME=	416fab6
GH_TUPLE?=	KhronosGroup:SPIRV-Headers:2acb319:SPIRVHeaders/external/SPIRV-Headers \
		KhronosGroup:SPIRV-Tools:0cfe9e7:SPIRVTools/external/SPIRV-Tools \
		microsoft:DirectX-Headers:980971e835876dc0cde415e8f9bc646e64667bf7:DirectXHeaders/external/DirectX-Headers

USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

CMAKE_ARGS+=	-C ${FILESDIR}/PredefinedParams.cmake \
		-DCMAKE_BUILD_TYPE=Release

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_LibXml2 \
		CMAKE_DISABLE_FIND_PACKAGE_MetalIRConverter \
		ENABLE_SPIRV_CODEGEN

CMAKE_OFF=	LLVM_APPEND_VC_REV \
		SPIRV_BUILD_TESTS

CC=		clang18
CXX=		clang++18
CPP=		clang-cpp18

.include <bsd.port.mk>
