# QVorbis
Single header & source, no dependencies, vorbis decoder and playback for Qt.

Note that it currently does not support streaming. This means that the entire file is first decoded to memory before played, which can mean heavy memory usage for larger files.

Huge thanks to [stb_vorbis](https://github.com/nothings/stb/blob/master/stb_vorbis.c) for providing the base.

## Usage
Check provided `demo.cpp` file. (to do)

## License
Like stb_vorbis, do whatever you want with it.