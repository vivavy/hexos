CPP_EXCEPTIONS = -Wno-array-bounds -Wno-stringop-overflow -Wno-write-strings -Wno-register -Wno-unused-function

test:
	@make image >/dev/null
	@make debug >/dev/null

image: boot kernel
	@aarch64-elf-gcc -T linker.ld -o hexos.elf -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc
	@aarch64-elf-objcopy hexos.elf -O binary hexos.img
	@rm -f hexos.elf boot.o kernel.o kernel.S

boot:
	@aarch64-elf-as -c armstub.S -o boot.o

kernel:
	@aarch64-elf-g++ -ffreestanding -c -S kernel.cpp -o kernel.S -O2 -Wall -Wextra -I include ${CPP_EXCEPTIONS}
	@aarch64-elf-as -c  kernel.S -o kernel.o

debug:
	@qemu-system-aarch64 -M raspi3b -kernel hexos.img -serial stdio -m 1024 2>/dev/null
