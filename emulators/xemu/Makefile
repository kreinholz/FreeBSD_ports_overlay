PORTNAME=	xemu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.138
CATEGORIES=	emulators
MASTER_SITES=	https://github.com/xemu-project/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}

SUBPROJECT_DIST=	mborgerson-dsp56300-v0.1.3_GH0.tar.gz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${SUBPROJECT_DIST}:subproject

EXTRACT_ONLY=	${_DISTFILES:M*${EXTRACT_SFX}} ${_DISTFILES:M*crate}

MASTER_SITES+=	https://github.com

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
		py312-pillow>0:graphics/py-pillow \
		py312-pip>0:devel/py-pip \
		py312-pyyaml>0:devel/py-pyyaml \
		py312-sphinx>0:textproc/py-sphinx \
		py312-sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme \
		py312-tomli>0:textproc/py-tomli \
		rpm2cpio>0:archivers/rpm2cpio \
		socat>0:net/socat \
		tesseract>0:graphics/tesseract \
		xorriso>0:sysutils/xorriso \
		nlohmann-json>0:devel/nlohmann-json \
		rust>0:lang/rust

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libepoxy.so:graphics/libepoxy \
		libffi.so:devel/libffi \
		libpulse.so:audio/pulseaudio \
		libslirp.so:net/libslirp \
		libsndio.so:audio/sndio \
		libpcap.so.1:net/libpcap \
		libcurl.so:ftp/curl \
		libsamplerate.so:audio/libsamplerate \
		libxxhash.so.0:devel/xxhash

USES=		cargo gl gmake gnome pkgconfig python:3.9+,build sdl \
		shebangfix tar:zst
USE_GL=		gl
USE_GNOME=	gtk30 glib20
USE_SDL=	sdl3 image3
PYTHON_BUILD_DEPENDS=	${PYNUMPY}
SHEBANG_GLOB=	*.sh

DSP_SUBPROJ=	dsp56300-0.1.3

DSP_WRKSRC=	${WRKSRC}/subprojects/dsp56300/${DSP_SUBPROJ}

CARGO_CARGOTOML=	${DSP_WRKSRC}/Cargo.toml
CARGO_CARGOLOCK=	${DSP_WRKSRC}/Cargo.lock

# To regenerate the list of CARGO_CRATES, run 'make cargo-crates'
CARGO_CRATES=	aho-corasick-1.1.4 \
                allocator-api2-0.2.21 \
                anstream-1.0.0 \
                anstyle-1.0.14 \
                anstyle-parse-1.0.0 \
                anstyle-query-1.1.5 \
                anstyle-wincon-3.0.11 \
                anyhow-1.0.102 \
                ar_archive_writer-0.5.1 \
                arbitrary-1.4.2 \
                bitflags-1.3.2 \
                bitflags-2.11.1 \
                bumpalo-3.20.2 \
                cbindgen-0.29.3 \
                cc-1.2.63 \
                cfg-if-1.0.4 \
                chumsky-0.13.0 \
                clap-4.6.1 \
                clap_builder-4.6.0 \
                clap_derive-4.6.1 \
                clap_lex-1.1.0 \
                colorchoice-1.0.5 \
                cranelift-assembler-x64-0.132.0 \
                cranelift-assembler-x64-meta-0.132.0 \
                cranelift-bforest-0.132.0 \
                cranelift-bitset-0.132.0 \
                cranelift-codegen-0.132.0 \
                cranelift-codegen-meta-0.132.0 \
                cranelift-codegen-shared-0.132.0 \
                cranelift-control-0.132.0 \
                cranelift-entity-0.132.0 \
                cranelift-frontend-0.132.0 \
                cranelift-isle-0.132.0 \
                cranelift-jit-0.132.0 \
                cranelift-module-0.132.0 \
                cranelift-native-0.132.0 \
                cranelift-srcgen-0.132.0 \
                crossbeam-deque-0.8.6 \
                crossbeam-epoch-0.9.18 \
                crossbeam-utils-0.8.21 \
                either-1.15.0 \
                equivalent-1.0.2 \
                errno-0.3.14 \
                fastrand-2.4.1 \
                find-msvc-tools-0.1.9 \
                fnv-1.0.7 \
                foldhash-0.1.5 \
                foldhash-0.2.0 \
                getrandom-0.4.2 \
                gimli-0.33.0 \
                hashbrown-0.15.5 \
                hashbrown-0.16.1 \
                hashbrown-0.17.0 \
                heck-0.5.0 \
                id-arena-2.3.0 \
                indexmap-2.14.0 \
                is_terminal_polyfill-1.70.2 \
                itoa-1.0.18 \
                leb128fmt-0.1.0 \
                libc-0.2.185 \
                libm-0.2.16 \
                linux-raw-sys-0.12.1 \
                log-0.4.29 \
                logos-0.16.1 \
                logos-codegen-0.16.1 \
                logos-derive-0.16.1 \
                mach2-0.4.3 \
                memchr-2.8.0 \
                memmap2-0.2.3 \
                object-0.37.3 \
                once_cell-1.21.4 \
                once_cell_polyfill-1.70.2 \
                owo-colors-4.3.0 \
                prettyplease-0.2.37 \
                proc-macro2-1.0.106 \
                psm-0.1.31 \
                quote-1.0.45 \
                r-efi-6.0.0 \
                rayon-1.12.0 \
                rayon-core-1.13.0 \
                regalloc2-0.15.1 \
                regex-automata-0.4.14 \
                regex-syntax-0.8.10 \
                region-3.0.2 \
                rustc-hash-2.1.2 \
                rustix-1.1.4 \
                semver-1.0.28 \
                serde-1.0.228 \
                serde_core-1.0.228 \
                serde_derive-1.0.228 \
                serde_json-1.0.149 \
                serde_spanned-1.1.1 \
                shlex-2.0.1 \
                smallvec-1.15.1 \
                stable_deref_trait-1.2.1 \
                stacker-0.1.24 \
                strsim-0.11.1 \
                syn-2.0.117 \
                target-lexicon-0.13.5 \
                tempfile-3.27.0 \
                toml-0.9.12+spec-1.1.0 \
                toml_datetime-0.7.5+spec-1.1.0 \
                toml_parser-1.1.2+spec-1.1.0 \
                toml_writer-1.1.1+spec-1.1.0 \
                unicode-ident-1.0.24 \
                unicode-segmentation-1.13.2 \
                unicode-xid-0.2.6 \
                utf8parse-0.2.2 \
                wasip2-1.0.3+wasi-0.2.9 \
                wasip3-0.4.0+wasi-0.3.0-rc-2026-01-06 \
                wasm-encoder-0.244.0 \
                wasm-metadata-0.244.0 \
                wasmparser-0.244.0 \
                wasmtime-internal-core-45.0.0 \
                wasmtime-internal-jit-icache-coherence-45.0.0 \
                windows-link-0.2.1 \
                windows-sys-0.52.0 \
                windows-sys-0.61.2 \
                windows-targets-0.52.6 \
                windows_aarch64_gnullvm-0.52.6 \
                windows_aarch64_msvc-0.52.6 \
                windows_i686_gnu-0.52.6 \
                windows_i686_gnullvm-0.52.6 \
                windows_i686_msvc-0.52.6 \
                windows_x86_64_gnu-0.52.6 \
                windows_x86_64_gnullvm-0.52.6 \
                windows_x86_64_msvc-0.52.6 \
                winnow-0.7.15 \
                winnow-1.0.2 \
                wit-bindgen-0.51.0 \
                wit-bindgen-0.57.1 \
                wit-bindgen-core-0.51.0 \
                wit-bindgen-rust-0.51.0 \
                wit-bindgen-rust-macro-0.51.0 \
                wit-component-0.244.0 \
                wit-parser-0.244.0 \
                zmij-1.0.21

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

post-extract:
	@${CP} ${WRKSRC}/subprojects/packagefiles/berkeley-softfloat-3/* ${WRKSRC}/subprojects/berkeley-softfloat-3/
	@${CP} ${WRKSRC}/subprojects/packagefiles/berkeley-testfloat-3/* ${WRKSRC}/subprojects/berkeley-testfloat-3/
	@${CP} ${DISTDIR}/${SUBPROJECT_DIST} ${WRKSRC}/subprojects/dsp56300/
	@${MV} ${WRKSRC}/subprojects/dsp56300/${SUBPROJECT_DIST} ${WRKSRC}/subprojects/dsp56300/dsp56300-0.1.3.tar.gz
	@${TAR} -xf ${DISTDIR}/${SUBPROJECT_DIST} \
		-C ${WRKSRC}/subprojects/dsp56300
	@${MKDIR} ${DSP_WRKSRC}/cargo-crates
.for crate in ${CARGO_CRATES}
	@if [ -d "${WRKDIR}/${crate}" ]; then \
		${MV} ${WRKDIR}/${crate} ${DSP_WRKSRC}/cargo-crates/; \
	fi
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|python3|python${PYTHON_VER}|g' \
		${WRKSRC}/scripts/pack-file.py \
		${WRKSRC}/build.sh

OPTIONS_DEFINE=		AVX512BW GETTEXT JACK PIPEWIRE PIXMAN PNG \
			PULSEAUDIO SNDIO SPICE SPICE_PROTOCOL VIRGLRENDERER
OPTIONS_DEFAULT=	GETTEXT JACK PIPEWIRE PIXMAN PNG PULSEAUDIO SNDIO \
			VIRGLRENDERER

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
