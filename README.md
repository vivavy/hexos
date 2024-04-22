# hexos
HexOS distribution

Dependencies:

* [elf2hxe](https://github.com/vivavy/elf2hxe)
* [<your_arch>-elf-gcc](https://gcc.gnu.org/)
* [python3.11](https://www.python.org/)
* [flat assembler](https://flatassembler.net/)
* [Vimake](https://github.com/vivavy/vimake)

To build the distribution:

1. Install dependencies
2. Run `vimake <arch>`
3. Done!

Note: You can check missing dependencies with `vimake <arch> -d`.

## Folders and files

* `dist`: HexOS distribution.
* `docs`: HexOS documentation.
* `src`: HexOS source code.
* `Vimake`: Vimake file for building the distributions.

## Contributions
Pocom4 with [bootylkaloader](https://github.com/pocom4/bootylkaloader) that is used to load the kernel.
