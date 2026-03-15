# FreeBSD port of Cemu - Wii U emulator

This is an unofficial FreeBSD port of Cemu, a Wii U emulator (https://cemu.info).

Cemu can be built with or without wayland support. I haven't tested it under wayland, only X11.

This FreeBSD build of Cemu is capable of running both commercial and homebrew Wii U games. Both the Vulkan and OpenGL backends work on my NVIDIA GPU. Sound works as well.

To build on FreeBSD (amd64 or aarch64):

Clone this repository:

git clone git@github.com:kreinholz/Cemu.git

cd Cemu

sudo make install clean

(Alternatively, run 'make install clean' as root)

As of commit 4efa40c, 22 July 2025, the Cemu project merged my patches, so Cemu can now be compiled on FreeBSD without patching the official sources.

As of commit 0860959, 23 July 2025, the Cemu project upgraded the required version of wxWidgets to 3.3.1, so I had to create an unofficial FreeBSD port, x11-toolkits/wxgtk33, in order to supply this dependency. If you want to build my unofficial Cemu port on FreeBSD, please install my unofficial wxgtk33 port first.
