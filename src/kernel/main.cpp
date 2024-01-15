#include <cppdlc.hpp>
#include <armv8a.hpp>
#include <mmu.hpp>
#include <uart.hpp>
#include <time.hpp>

nomangle nil kernel_main(void) {
	mmu::init();
	uart::init();

	uart::puts("Success\n");
	do {armv8a::wfe();} while (1);
}

nomangle nil exc_handler() {return;}
