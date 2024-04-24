ENTRY (_start)

SECTIONS{
    . = 0x001000;

    .text :{
        text_start = .;
        *(.text)
    }

    .rodata : {
        *(.rodata)
    }

    .data : {
        *(.data)
        end_data = .;
    }

    .bss : {
        sbss = .;
        *(COMMON)
        *(.bss)
        ebss = .;
    }

    .xbss : {
        endkernel = .;
    }
}
