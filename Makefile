CPP_EXCEPTIONS = -Wno-array-bounds -Wno-stringop-overflow -Wno-write-strings -Wno-register -Wno-unused-function -Wno-overflow -Wno-sign-compare

test:
	@make image >/dev/null
	@make debug >/dev/null

font:
	@aarch64-elf-ld -r -b binary -o psf.o res/fonts/font_psf.psf
	# aarch64-elf-ld -r -b binary -o sfn.o res/fonts/font_sfn.sfn

image: boot kernel font
	@aarch64-elf-gcc -T scripts/linker.ld -o hexos.elf -ffreestanding \
		-O2 -nostdlib boot.o psf.o kernel.o
	@aarch64-elf-objcopy hexos.elf -O binary hexos.img
	@rm -f hexos.elf boot.o kernel.o kernel.S font.o

boot:
	@aarch64-elf-as -c src/boot/armv8a.S -I include -o boot.o

kernel:
	@aarch64-elf-g++ -ffreestanding -c -S src/kernel/main.cpp \
		-o kernel.S -O3 -Wall -Werror -Wno-error \
		-Wextra -I include ${CPP_EXCEPTIONS}
	@aarch64-elf-as -c  kernel.S -o kernel.o

debug:
	@qemu-system-aarch64 -M raspi3b -kernel hexos.img \
		-serial stdio -m 1024 2>/dev/null
