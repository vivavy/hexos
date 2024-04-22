# hexos-x86_64
HexOS x86-64 distribution

Dependencies:

* [elf2hxe](https://github.com/vivavy/elf2hxe)
* [x86_64-elf-gcc](https://gcc.gnu.org/)
* [python3.11](https://www.python.org/)
* [bootylkaloader](https://github.com/pocom4/bootylkaloader)
* [flat assembler](https://flatassembler.net/)
* [Vimake](https://github.com/vivavy/vimake)

To build the distribution:

1. Install dependencies
2. Run `vimake <arch>`
3. Done!

Note: You can check missing dependencies with `vimake <arch> -d`.

## Folders and files

* `buildenv`: Build environment.
* `dist`: HexOS distribution.
* `docs`: HexOS documentation.
* `src`: HexOS source code.
* `Makefile`: Makefile for building the distribution.
