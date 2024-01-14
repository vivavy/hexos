#include <enhancecpp.hpp>
#include <armv8a.hpp>
#include <mmu.hpp>
#include <uart.hpp>
#include <time.hpp>

nomangle void kernel_main(void) {
	mmu::init();
	uart::init();

	uart::puts((u8 *)"Success\n");
	do {armv8a::wfe();} while (1);
}

nomangle void exc_handler() {return;}
