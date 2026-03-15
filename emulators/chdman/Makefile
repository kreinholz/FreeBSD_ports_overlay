PORTNAME=	chdman
DISTVERSION=	0.285
CATEGORIES=	emulators games

MAINTAINER=	kreinholz@gmail.com
COMMENT=	chdman tool from MAME: a multi-purpose emulation framework
WWW=		https://mamedev.org/

LICENSE=	GPLv2
LICENSE_COMB=	single
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 armv7 i386 powerpc powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	not yet ported to any architecture other than armv7, arm64, x86, and powerpc*

USES=		cmake compiler:c++17-lang localbase ninja pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	kreinholz
GH_PROJECT=	chdman
GH_TAGNAME=	f539f3d

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/chdman ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
