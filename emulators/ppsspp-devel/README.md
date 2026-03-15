# Bleeding edge PPSSPP tracking upstream git commits after the latest release

This started out as a custom Port of PPSSPP that I created to build PPSSPP on FreeBSD against ffmpeg-3.0.2 instead of more broken (for purposes of PSP game compatibility) later versions. However, on 4 December 2024 it became the FreeBSD official port, so for someone wanting to install PPSSPP on FreeBSD, I recommend just using Ports/packages on your system.

This fork of my own port was mainly to prepare for the next PPSSPP release by tweaking the FreeBSD port files as necessary to build more recent upstream git commits to PPSSPP.

Originally, as an experiment I incorporated building bundled ffmpeg into this unofficial ppsspp-devel port. While it can be done, this makes for a far messier Makefile for the emulators/ppsspp port which in turn leads to maintenance overhead. Going forward, I've reverted to the setup used in the official port--setting a build dependency on multimedia/ffmpeg3.
 
Note: PPSSPP sometimes hangs at startup with the Vulkan backend, presumably after updating or rebuilding GPU drivers (NVIDIA in my case). Performing the following steps clears this up and allows PPSSPP to run smoothly again with the Vulkan backend:

```
rm ~/.config/ppsspp/PSP/SYSTEM/CACHE/*
rm ~/.cache/nvidia/GLCache/2908e7a488a0c7c0446063d5e6978db9/af5057cfd6172ecd/*
```

The latter line of course only applies to users with NVIDIA GPUs. This will need to be adjusted accordingly for other GPUs. Additionally, the two directories after GLCache/ will probably vary from system to system--this is just what they're called on mine. 


Old Notes (obsoleted 12 June 2025):

Note: while there is in fact a [ppsspp-ffmpeg](https://github.com/hrydgard/ppsspp-ffmpeg/tree/82049cca2e4c1516ed00a77b502a21f91b7843f4) fork of [ffmpeg-3.0.2](https://github.com/FFmpeg/FFmpeg/tree/c66f4d1ae64dffaf456d05cbdade02054446f499), because ppsspp-ffmpeg's git repository includes compiled libs for a variety of operating systems and architectures, an archive of the most recent git commit is over 435 MB in size! Compare that to a github archive of ffmpeg as of version 3.0.2, at just over 10.6 MB. (Or ~ 7.5 MB for the official tar.xz release on ffmpeg.org).

It's possible to patch the official ffmpeg-3.0.2 archive with forked ppsspp-ffmpeg's improvement commit (as opposed to build-related commits) as a patchfile, so that's the preferred way to do it, rather than forcing users (or package build servers) to download close to an additional 430 MB due to the inclusion of compiled libs in the ppsspp-ffmpeg repository.

While the official FreeBSD port of emulators/ppsspp, as well as my github repository, build PPSSPP with my multimedia/ffmpeg3 port as a build dependency, in this repository I incorporated the retrieval and building of bundled ffmpeg as part of the PPSSPP build process. Frankly, I think it clutters up the PPSSPP port Makefile more than I'd like, so I'll probably leave the main port alone.
