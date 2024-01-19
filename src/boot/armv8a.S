#define CORE(n)#0xd8+(n*8)

.section ".text.boot"

.global _start
_start:
    // read cpu id
    // mrs x0, mpidr_el1
    // and x0, x0, #3
    // cbnz x0, run

    // cpu id == 0
    // ldr x0, =run
    // mov x1, CORE(1)
    // str x0, [x1]

run:
    // set top of stack just before our code (stack grows to a lower address per AAPCS64)
    ldr     x1, =_start

    // set up EL1
    mrs     x0, CurrentEL
    and     x0, x0, #12 // clear reserved bits

    // running at EL3?
    cmp     x0, #12
    bne     check_el2
    // should never be executed, just for completeness
    mov     x2, #0x5b1
    msr     scr_el3, x2
    mov     x2, #0x3c9
    msr     spsr_el3, x2
    adr     x2, check_el2
    msr     elr_el3, x2
    eret

    // running at EL2?
check_el2:
    cmp     x0, #4
    beq     kmain
    msr     sp_el1, x1
    // enable CNTP for EL1
    mrs     x0, cnthctl_el2
    orr     x0, x0, #3
    msr     cnthctl_el2, x0
    msr     cntvoff_el2, xzr
    // disable coprocessor traps
    mov     x0, #0x33FF
    msr     cptr_el2, x0
    msr     hstr_el2, xzr
    mov     x0, #(3 << 20)
    msr     cpacr_el1, x0
    // enable AArch64 in EL1
    mov     x0, #(1 << 31)      // AArch64
    orr     x0, x0, #(1 << 1)   // SWIO hardwired on Pi3
    msr     hcr_el2, x0
    mrs     x0, hcr_el2
    // Setup SCTLR access
    mov     x2, #0x0800
    movk    x2, #0x30d0, lsl #16
    msr     sctlr_el1, x2
    // set up exception handlers
    ldr     x2, =_vectors
    msr     vbar_el1, x2
    // change execution level to EL1
    mov     x2, #0x3c4
    msr     spsr_el2, x2
    adr     x2, kmain
    msr     elr_el2, x2
    eret

kmain:
    // Stack pointer
    ldr     x0, =_start
    mov     sp, x0

    // Core ID
    mrs x0, mpidr_el1
    and x0, x0, #3

    bl      kernel_main

halt:
    wfe
    b       halt

    // important, code has to be properly aligned
    .align 11
_vectors:
    // synchronous
    .align  7
    mov     x0, #0
    mrs     x1, esr_el1
    mrs     x2, elr_el1
    mrs     x3, spsr_el1
    mrs     x4, far_el1
    b       exc_handler

    // IRQ
    .align  7
    mov     x0, #1
    mrs     x1, esr_el1
    mrs     x2, elr_el1
    mrs     x3, spsr_el1
    mrs     x4, far_el1
    b       exc_handler

    // FIQ
    .align  7
    mov     x0, #2
    mrs     x1, esr_el1
    mrs     x2, elr_el1
    mrs     x3, spsr_el1
    mrs     x4, far_el1
    b       exc_handler

    // SError
    .align  7
    mov     x0, #3
    mrs     x1, esr_el1
    mrs     x2, elr_el1
    mrs     x3, spsr_el1
    mrs     x4, far_el1
    b       exc_handler
