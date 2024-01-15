#include <cppdlc.hpp>
#include <armv8a.hpp>
#include <mmu.hpp>
#include <uart.hpp>
#include <time.hpp>
#include <fb.hpp>

FBInfo fb_info;

nomangle nil kernel_main(void) {
	uart::init();
	mmu::init();

	uart::puts("Success\n");

	fb::init(fb_info);

	fb::print(0, 0, (char *)"Hello, World!");
	fb::flush();
	
	do {armv8a::wfe();} while (1);
}

nomangle nil exc_handler() {return;}
