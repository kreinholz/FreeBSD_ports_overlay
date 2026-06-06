PORTNAME=	chdman
DISTVERSION=	0.288
CATEGORIES=	emulators games

MAINTAINER=	kreinholz@gmail.com
COMMENT=	chdman tool from MAME: a multi-purpose emulation framework
WWW=		https://mamedev.org/

LICENSE=	GPLv2
LICENSE_COMB=	single
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 armv7 i386 powerpc powerpc64le
ONLY_FOR_ARCHS_REASON=	not yet ported to any architecture other than armv7, arm64, x86, and little endian powerpc*

USES=		cmake compiler:c++20-lang localbase ninja pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	kreinholz
GH_PROJECT=	chdman
GH_TAGNAME=	6b0eabb

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/chdman ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
