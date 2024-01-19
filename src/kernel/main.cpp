#include <cppdlc.hpp>
#include <armv8a.hpp>
#include <mmu.hpp>
#include <uart.hpp>
// #include <time.hpp>
// #include <fb.hpp>

nomangle nil kernel_main() {
	uart::init();
	mmu::init();

	// uart::putc('X');

	uart::puts("Success\n");

	// fb::init();

	// fb::print(0, 0, (char *)"Hello, World!");
	// fb::flush();

	// uart::puts("Still alive\n");
	
	do armv8a::wfe(); while (true);
}

nomangle nil exc_handler() {return;}
