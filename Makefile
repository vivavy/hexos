CWNO1 = -Wno-array-bounds -Wno-stringop-overflow -Wno-register -Wno-unused-function
CWNO2 = -Wno-sign-compare
CWNO = ${CWNO1} ${CWNO2}
LDFLAGS = -T scripts/linker.ld -o kernel.elf -ffreestanding -O2 -nostdlib
INCLUDE = include
CFLAGS = -ffreestanding -c -S src/kernel/main.cpp -o kernel.S -O2 -Wall -Werror -Wextra -I ${INCLUDE}
OBJECTS = boot-armv8a.o kernel.o # psf.o sfn.o
OUTFILE = boot.img
RAM = 1024
BOARD = raspi3b

test:  # nested calls. very useful, but unstable technique
	@make image >/dev/null
	@make debug >/dev/null
	@make clear >/dev/null
	@clear

clear:
	@rm -f kernel.elf ${OBJECTS} kernel.S

font:
	@aarch64-elf-ld -r -b binary -o psf.o res/fonts/font_psf.psf
	@aarch64-elf-ld -r -b binary -o sfn.o res/fonts/font_sfn.sfn

image: boot kernel font
	@aarch64-elf-gcc ${LDFLAGS} ${OBJECTS}
	@aarch64-elf-objcopy kernel.elf -O binary ${OUTFILE}

boot:
	@aarch64-elf-as -c src/boot/armv8a.S -I ${INCLUDE} -o boot-armv8a.o

kernel:
	@aarch64-elf-g++ ${CFLAGS} ${CWNO}
	@aarch64-elf-as -c kernel.S -o kernel.o

debug:
	@qemu-system-aarch64 -M ${BOARD} -kernel ${OUTFILE} \
		-serial stdio -m ${RAM} 2>/dev/null
