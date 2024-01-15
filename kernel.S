	.arch armv8-a
	.file	"main.cpp"
	.text
	.align	2
	.p2align 4,,11
	.global	_ZN4mbox4callEh
	.type	_ZN4mbox4callEh, %function
_ZN4mbox4callEh:
.LFB6:
	.cfi_startproc
	and	w0, w0, 15
	adrp	x4, .LANCHOR0
	add	x4, x4, :lo12:.LANCHOR0
	mov	x2, 47256
	orr	w0, w0, w4
	movk	x2, 0x3f00, lsl 16
	.p2align 3,,7
.L2:
	// Start of user assembly
// 46 "include/mbox.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w1, [x2]
	tbnz	w1, #31, .L2
	mov	x1, 47264
	mov	x2, 47256
	movk	x1, 0x3f00, lsl 16
	mov	x3, 47232
	movk	x2, 0x3f00, lsl 16
	movk	x3, 0x3f00, lsl 16
	str	w0, [x1]
	.p2align 3,,7
.L5:
	// Start of user assembly
// 54 "include/mbox.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w1, [x2]
	tbnz	x1, 30, .L5
	ldr	w1, [x3]
	cmp	w1, w0
	bne	.L5
	ldr	w1, [x4, 4]
	mov	w0, -2147483648
	cmp	w1, w0
	cset	w0, eq
	ret
	.cfi_endproc
.LFE6:
	.size	_ZN4mbox4callEh, .-_ZN4mbox4callEh
	.align	2
	.p2align 4,,11
	.global	_ZN4uart4initEv
	.type	_ZN4uart4initEv, %function
_ZN4uart4initEv:
.LFB7:
	.cfi_startproc
	mov	x1, 4144
	adrp	x0, .LANCHOR0
	movk	x1, 0x3f20, lsl 16
	add	x2, x0, :lo12:.LANCHOR0
	mov	w3, 36
	str	wzr, [x1]
	mov	w1, 32770
	str	w3, [x0, #:lo12:.LANCHOR0]
	movk	w1, 0x3, lsl 16
	str	wzr, [x2, 4]
	mov	w0, 12
	str	w1, [x2, 8]
	mov	w3, 8
	str	w0, [x2, 12]
	mov	w1, 2
	str	w3, [x2, 16]
	mov	w0, 2304
	str	w1, [x2, 20]
	movk	w0, 0x3d, lsl 16
	str	w0, [x2, 24]
	mov	x1, 47256
	orr	w3, w2, w3
	str	wzr, [x2, 28]
	movk	x1, 0x3f00, lsl 16
	str	wzr, [x2, 32]
	.p2align 3,,7
.L8:
	// Start of user assembly
// 46 "include/mbox.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w0, [x1]
	tbnz	w0, #31, .L8
	mov	x0, 47264
	mov	x1, 47256
	movk	x0, 0x3f00, lsl 16
	mov	x4, 47232
	movk	x1, 0x3f00, lsl 16
	movk	x4, 0x3f00, lsl 16
	str	w3, [x0]
	.p2align 3,,7
.L15:
	// Start of user assembly
// 54 "include/mbox.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w0, [x1]
	tbnz	x0, 30, .L15
	ldr	w0, [x4]
	cmp	w3, w0
	bne	.L15
	mov	x3, 4
	ldr	w0, [x2, 4]
	movk	x3, 0x3f20, lsl 16
	mov	x2, 148
	mov	w4, 16384
	movk	x2, 0x3f20, lsl 16
	ldr	w1, [x3]
	movk	w4, 0x2, lsl 16
	mov	w0, 150
	and	w1, w1, -258049
	orr	w1, w1, w4
	str	w1, [x3]
	str	wzr, [x2]
	.p2align 3,,7
.L10:
	// Start of user assembly
// 49 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	subs	w0, w0, #1
	bne	.L10
	mov	x1, 152
	mov	w2, 49152
	movk	x1, 0x3f20, lsl 16
	mov	w0, 150
	str	w2, [x1]
	.p2align 3,,7
.L11:
	// Start of user assembly
// 54 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	subs	w0, w0, #1
	bne	.L11
	mov	x2, 152
	mov	x1, 4164
	movk	x2, 0x3f20, lsl 16
	movk	x1, 0x3f20, lsl 16
	mov	x0, 4132
	mov	w3, 2047
	movk	x0, 0x3f20, lsl 16
	str	wzr, [x2]
	str	w3, [x1]
	mov	w3, 2
	str	w3, [x0]
	mov	w3, 11
	str	w3, [x2, 3984]
	mov	w2, 112
	str	w2, [x1, -24]
	mov	w1, 769
	str	w1, [x0, 12]
	ret
	.cfi_endproc
.LFE7:
	.size	_ZN4uart4initEv, .-_ZN4uart4initEv
	.align	2
	.p2align 4,,11
	.global	_ZN4uart4waitEv
	.type	_ZN4uart4waitEv, %function
_ZN4uart4waitEv:
.LFB8:
	.cfi_startproc
	mov	x1, 4120
	movk	x1, 0x3f20, lsl 16
	.p2align 3,,7
.L17:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w0, [x1]
	tbnz	x0, 5, .L17
	ret
	.cfi_endproc
.LFE8:
	.size	_ZN4uart4waitEv, .-_ZN4uart4waitEv
	.align	2
	.p2align 4,,11
	.global	_ZN4uart4putcEj
	.type	_ZN4uart4putcEj, %function
_ZN4uart4putcEj:
.LFB9:
	.cfi_startproc
	mov	x2, 4120
	movk	x2, 0x3f20, lsl 16
	.p2align 3,,7
.L20:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w1, [x2]
	tbnz	x1, 5, .L20
	mov	x1, 4096
	movk	x1, 0x3f20, lsl 16
	str	w0, [x1]
	ret
	.cfi_endproc
.LFE9:
	.size	_ZN4uart4putcEj, .-_ZN4uart4putcEj
	.align	2
	.p2align 4,,11
	.global	_ZN4uart4getcEv
	.type	_ZN4uart4getcEv, %function
_ZN4uart4getcEv:
.LFB10:
	.cfi_startproc
	mov	x1, 4120
	movk	x1, 0x3f20, lsl 16
	.p2align 3,,7
.L23:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w0, [x1]
	tbnz	x0, 5, .L23
	mov	x1, 4096
	movk	x1, 0x3f20, lsl 16
	ldr	w0, [x1]
	and	w0, w0, 255
	cmp	w0, 13
	beq	.L26
	ret
	.p2align 2,,3
.L26:
	ldr	w0, [x1]
	and	w0, w0, 255
	ret
	.cfi_endproc
.LFE10:
	.size	_ZN4uart4getcEv, .-_ZN4uart4getcEv
	.align	2
	.p2align 4,,11
	.global	_ZN4uart4putsEPh
	.type	_ZN4uart4putsEPh, %function
_ZN4uart4putsEPh:
.LFB11:
	.cfi_startproc
	ldrb	w3, [x0]
	cbz	w3, .L27
	mov	x2, 4120
	mov	x4, 4096
	movk	x2, 0x3f20, lsl 16
	movk	x4, 0x3f20, lsl 16
	mov	w5, 13
	.p2align 3,,7
.L28:
	cmp	w3, 10
	beq	.L30
.L29:
	add	x0, x0, 1
	.p2align 3,,7
.L31:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w1, [x2]
	tbnz	x1, 5, .L31
	str	w3, [x4]
	ldrb	w3, [x0]
	cbnz	w3, .L28
.L27:
	ret
	.p2align 2,,3
.L30:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w1, [x2]
	tbnz	x1, 5, .L30
	str	w5, [x4]
	ldrb	w3, [x0]
	b	.L29
	.cfi_endproc
.LFE11:
	.size	_ZN4uart4putsEPh, .-_ZN4uart4putsEPh
	.align	2
	.p2align 4,,11
	.global	_ZN4uart4putsEPKc
	.type	_ZN4uart4putsEPKc, %function
_ZN4uart4putsEPKc:
.LFB25:
	.cfi_startproc
	ldrb	w3, [x0]
	cbz	w3, .L37
	mov	x2, 4120
	mov	x4, 4096
	movk	x2, 0x3f20, lsl 16
	movk	x4, 0x3f20, lsl 16
	mov	w5, 13
	.p2align 3,,7
.L38:
	cmp	w3, 10
	beq	.L40
.L39:
	add	x0, x0, 1
	.p2align 3,,7
.L41:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w1, [x2]
	tbnz	x1, 5, .L41
	str	w3, [x4]
	ldrb	w3, [x0]
	cbnz	w3, .L38
.L37:
	ret
	.p2align 2,,3
.L40:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w1, [x2]
	tbnz	x1, 5, .L40
	str	w5, [x4]
	ldrb	w3, [x0]
	b	.L39
	.cfi_endproc
.LFE25:
	.size	_ZN4uart4putsEPKc, .-_ZN4uart4putsEPKc
	.align	2
	.p2align 4,,11
	.global	_ZN4uart3hexEj
	.type	_ZN4uart3hexEj, %function
_ZN4uart3hexEj:
.LFB13:
	.cfi_startproc
	mov	x2, 4120
	mov	x5, 4096
	mov	w3, 28
	mov	w7, 55
	mov	w6, 48
	movk	x2, 0x3f20, lsl 16
	movk	x5, 0x3f20, lsl 16
	.p2align 3,,7
.L50:
	lsr	w1, w0, w3
	and	w1, w1, 15
	cmp	w1, 9
	csel	w4, w7, w6, hi
	add	w4, w4, w1
	.p2align 3,,7
.L49:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w1, [x2]
	tbnz	x1, 5, .L49
	sub	w3, w3, #4
	str	w4, [x5]
	cmn	w3, #4
	bne	.L50
	ret
	.cfi_endproc
.LFE13:
	.size	_ZN4uart3hexEj, .-_ZN4uart3hexEj
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align	3
.LC0:
	.string	": "
	.text
	.align	2
	.p2align 4,,11
	.global	_ZN4uart4dumpEPv
	.type	_ZN4uart4dumpEPv, %function
_ZN4uart4dumpEPv:
.LFB14:
	.cfi_startproc
	mov	x5, x0
	add	x0, x0, 512
	cmp	x5, x0
	bcs	.L54
	add	x14, x5, 16
	mov	x13, 32
	cmp	x14, x0
	mov	w8, w13
	adrp	x16, .LC0
	mov	x0, 4120
	mov	x3, 4096
	csinc	x13, x13, xzr, ls
	mov	x9, x14
	add	x16, x16, :lo12:.LC0
	mov	w12, 55
	mov	w11, 48
	movk	x0, 0x3f20, lsl 16
	movk	x3, 0x3f20, lsl 16
	mov	w15, 13
	mov	x7, 55
	mov	x6, 48
	mov	w10, 46
	mov	w17, 10
.L77:
	mov	w18, w5
	mov	w4, 28
	.p2align 3,,7
.L58:
	lsr	w1, w18, w4
	and	w1, w1, 15
	cmp	w1, 9
	csel	w2, w12, w11, hi
	add	w2, w1, w2
	.p2align 3,,7
.L57:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w1, [x0]
	tbnz	x1, 5, .L57
	sub	w4, w4, #4
	str	w2, [x3]
	cmn	w4, #4
	bne	.L58
	mov	x4, x16
	mov	w2, 58
	.p2align 3,,7
.L59:
	add	x4, x4, 1
	.p2align 3,,7
.L62:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w1, [x0]
	tbnz	x1, 5, .L62
	str	w2, [x3]
	ldrb	w2, [x4]
	cbz	w2, .L96
	cmp	w2, 10
	bne	.L59
	.p2align 3,,7
.L61:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w1, [x0]
	tbnz	x1, 5, .L61
	str	w15, [x3]
	ldrb	w2, [x4]
	b	.L59
.L96:
	mov	x4, 0
	.p2align 3,,7
.L71:
	ldrb	w2, [x4, x5]
	ubfx	x1, x2, 4, 4
	cmp	x1, 9
	csel	x18, x7, x6, hi
	add	x18, x18, x1
	.p2align 3,,7
.L65:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w1, [x0]
	tbnz	x1, 5, .L65
	and	w1, w2, 15
	and	x2, x2, 15
	cmp	w1, 10
	str	w18, [x3]
	csel	x1, x6, x7, cc
	add	x2, x1, x2
	.p2align 3,,7
.L67:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w1, [x0]
	tbnz	x1, 5, .L67
	str	w2, [x3]
	.p2align 3,,7
.L68:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w1, [x0]
	tbnz	x1, 5, .L68
	and	x1, x4, 3
	str	w8, [x3]
	cmp	x1, 3
	beq	.L70
.L69:
	add	x4, x4, 1
	cmp	x4, 16
	bne	.L71
	mov	x4, x5
	.p2align 3,,7
.L74:
	ldrb	w2, [x4]
	sub	w1, w2, #32
	and	w1, w1, 255
	cmp	w1, 95
	csel	w2, w2, w10, cc
	.p2align 3,,7
.L73:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w1, [x0]
	tbnz	x1, 5, .L73
	add	x4, x4, 1
	str	w2, [x3]
	cmp	x9, x4
	bne	.L74
	.p2align 3,,7
.L75:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w1, [x0]
	tbnz	x1, 5, .L75
	str	w15, [x3]
	.p2align 3,,7
.L76:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w1, [x0]
	tbnz	x1, 5, .L76
	str	w17, [x3]
	add	x9, x9, 16
	subs	x13, x13, #1
	mov	x5, x14
	beq	.L54
	add	x14, x14, 16
	b	.L77
	.p2align 2,,3
.L70:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w1, [x0]
	tbnz	x1, 5, .L70
	str	w8, [x3]
	b	.L69
.L54:
	ret
	.cfi_endproc
.LFE14:
	.size	_ZN4uart4dumpEPv, .-_ZN4uart4dumpEPv
	.section	.rodata.str1.8
	.align	3
.LC1:
	.string	"ERROR: 4k granule or 36 bit address space not supported\n"
	.text
	.align	2
	.p2align 4,,11
	.global	_ZN3mmu4initEv
	.type	_ZN3mmu4initEv, %function
_ZN3mmu4initEv:
.LFB15:
	.cfi_startproc
	adrp	x2, .LC2
	adrp	x3, .LC5
	adrp	x0, _data
	add	x0, x0, :lo12:_data
	ldr	q3, [x2, #:lo12:.LC2]
	adrp	x2, .LC3
	fmov	d0, x0
	adrp	x1, _end
	ldr	q16, [x2, #:lo12:.LC3]
	add	x1, x1, :lo12:_end
	adrp	x2, .LC4
	adrp	x5, .LC7
	ldr	q6, [x3, #:lo12:.LC5]
	adrp	x3, .LC6
	ushr	d2, d0, 12
	adrp	x4, _end+8192
	ldr	q7, [x2, #:lo12:.LC4]
	add	x4, x4, :lo12:_end+8192
	ldr	q4, [x3, #:lo12:.LC6]
	adrp	x2, _end+12288
	mov	x3, 12280
	add	x2, x2, :lo12:_end+12288
	adrp	x0, _end+8200
	add	x3, x1, x3
	add	x0, x0, :lo12:_end+8200
	ldr	q5, [x5, #:lo12:.LC7]
	mov	x5, 1859
	orr	x4, x4, x5
	orr	x5, x2, x5
	str	x4, [x1]
	str	x5, [x1, 8192]
	.p2align 3,,7
.L98:
	mov	v0.16b, v3.16b
	add	v3.2d, v3.2d, v16.2d
	cmhi	v1.2d, v0.2d, v7.2d
	shl	v0.2d, v0.2d, 21
	bsl	v1.16b, v6.16b, v4.16b
	orr	v0.16b, v0.16b, v5.16b
	orr	v0.16b, v0.16b, v1.16b
	str	q0, [x0], 16
	cmp	x0, x3
	bne	.L98
	adrp	x0, .LC8
	adrp	x4, .LC3
	dup	v2.2d, v2.d[0]
	add	x3, x1, 16384
	ldr	q3, [x0, #:lo12:.LC8]
	mov	x0, 1605
	movk	x0, 0x3fe0, lsl 16
	movk	x0, 0x40, lsl 48
	str	x0, [x1, 12280]
	adrp	x0, .LC9
	ldr	q16, [x4, #:lo12:.LC3]
	ldr	q7, [x0, #:lo12:.LC9]
	adrp	x0, .LC10
	ldr	q6, [x0, #:lo12:.LC10]
	adrp	x0, .LC11
	ldr	q4, [x0, #:lo12:.LC11]
	adrp	x0, .LC12
	ldr	q5, [x0, #:lo12:.LC12]
.L99:
	mov	v0.16b, v3.16b
	add	v3.2d, v3.2d, v16.2d
	cmhs	v1.2d, v7.2d, v0.2d
	cmhs	v17.2d, v0.2d, v2.2d
	shl	v0.2d, v0.2d, 12
	orr	v1.16b, v1.16b, v17.16b
	orr	v0.16b, v0.16b, v5.16b
	bsl	v1.16b, v6.16b, v4.16b
	orr	v0.16b, v0.16b, v1.16b
	str	q0, [x2], 16
	cmp	x2, x3
	bne	.L99
	mov	x4, 5639
	adrp	x0, _end+20480
	movk	x4, 0x3f20, lsl 16
	add	x0, x0, :lo12:_end+20480
	mov	x3, 1795
	movk	x4, 0x40, lsl 48
	orr	x0, x0, x3
	orr	x2, x2, x3
	str	x2, [x1, 8184]
	str	x0, [x1, 20472]
	str	x4, [x1, 20480]
	// Start of user assembly
// 106 "include/mmu.hpp" 1
	mrs x0, id_aa64mmfr0_el1
// 0 "" 2
	// End of user assembly
	ands	x2, x0, 15
	mov	x3, 268435455
	ccmp	x0, x3, 2, ne
	bhi	.L113
	mov	x0, 1279
	movk	x0, 0x44, lsl 16
	// Start of user assembly
// 117 "include/mmu.hpp" 1
	msr mair_el1, x0
// 0 "" 2
	// End of user assembly
	mov	x0, 13593
	movk	x0, 0xb519, lsl 16
	orr	x2, x0, x2, lsl 32
	// Start of user assembly
// 134 "include/mmu.hpp" 1
	msr tcr_el1, x2; isb
// 0 "" 2
	// End of user assembly
	add	x0, x1, 1
	// Start of user assembly
// 138 "include/mmu.hpp" 1
	msr ttbr0_el1, x0
// 0 "" 2
	// End of user assembly
	mov	x0, 4097
	add	x1, x1, x0
	// Start of user assembly
// 140 "include/mmu.hpp" 1
	msr ttbr1_el1, x1
// 0 "" 2
// 143 "include/mmu.hpp" 1
	dsb ish; isb; mrs x0, sctlr_el1
// 0 "" 2
	// End of user assembly
	mov	x1, -4127
	movk	x1, 0xfcf7, lsl 16
	and	x0, x0, x1
	mov	x1, 2049
	movk	x1, 0xc0, lsl 16
	orr	x0, x0, x1
	// Start of user assembly
// 154 "include/mmu.hpp" 1
	msr sctlr_el1, x0; isb
// 0 "" 2
	// End of user assembly
.L97:
	ret
.L113:
	adrp	x3, .LC1
	mov	x1, 4120
	mov	x4, 4096
	add	x3, x3, :lo12:.LC1
	mov	w2, 69
	movk	x1, 0x3f20, lsl 16
	movk	x4, 0x3f20, lsl 16
	mov	w5, 13
	.p2align 3,,7
.L100:
	add	x3, x3, 1
	.p2align 3,,7
.L104:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w0, [x1]
	tbnz	x0, 5, .L104
	str	w2, [x4]
	ldrb	w2, [x3]
	cbz	w2, .L97
	cmp	w2, 10
	bne	.L100
	.p2align 3,,7
.L103:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w0, [x1]
	tbnz	x0, 5, .L103
	str	w5, [x4]
	ldrb	w2, [x3]
	b	.L100
	.cfi_endproc
.LFE15:
	.size	_ZN3mmu4initEv, .-_ZN3mmu4initEv
	.align	2
	.p2align 4,,11
	.global	_ZN4time11wait_cyclesEj
	.type	_ZN4time11wait_cyclesEj, %function
_ZN4time11wait_cyclesEj:
.LFB16:
	.cfi_startproc
	cbz	w0, .L114
	sub	w0, w0, #1
	.p2align 3,,7
.L116:
	// Start of user assembly
// 15 "include/time.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	sub	w0, w0, #1
	cmn	w0, #1
	bne	.L116
.L114:
	ret
	.cfi_endproc
.LFE16:
	.size	_ZN4time11wait_cyclesEj, .-_ZN4time11wait_cyclesEj
	.align	2
	.p2align 4,,11
	.global	_ZN4time5sleepEj
	.type	_ZN4time5sleepEj, %function
_ZN4time5sleepEj:
.LFB17:
	.cfi_startproc
	// Start of user assembly
// 21 "include/time.hpp" 1
	mrs x1, cntfrq_el0
// 0 "" 2
// 23 "include/time.hpp" 1
	mrs x2, cntpct_el0
// 0 "" 2
	// End of user assembly
	mov	x3, 63439
	lsr	x1, x1, 3
	movk	x3, 0xe353, lsl 16
	uxtw	x0, w0
	movk	x3, 0x9ba5, lsl 32
	movk	x3, 0x20c4, lsl 48
	umulh	x1, x1, x3
	lsr	x1, x1, 4
	mul	x1, x1, x0
	lsr	x1, x1, 3
	umulh	x1, x1, x3
	lsr	x1, x1, 4
	.p2align 3,,7
.L122:
	// Start of user assembly
// 28 "include/time.hpp" 1
	mrs x0, cntpct_el0
// 0 "" 2
	// End of user assembly
	sub	x0, x0, x2
	cmp	x0, x1
	bcc	.L122
	ret
	.cfi_endproc
.LFE17:
	.size	_ZN4time5sleepEj, .-_ZN4time5sleepEj
	.align	2
	.p2align 4,,11
	.global	_ZN4time10get_uptimeEv
	.type	_ZN4time10get_uptimeEv, %function
_ZN4time10get_uptimeEv:
.LFB18:
	.cfi_startproc
	mov	x2, 12296
	mov	x3, 12292
	movk	x2, 0x3f00, lsl 16
	movk	x3, 0x3f00, lsl 16
	ldr	w0, [x2]
	ldr	w1, [x3]
	ldr	w4, [x2]
	cmp	w4, w0
	beq	.L125
	ldr	w0, [x2]
	ldr	w1, [x3]
.L125:
	uxtw	x1, w1
	orr	x0, x1, x0, lsl 32
	ret
	.cfi_endproc
.LFE18:
	.size	_ZN4time10get_uptimeEv, .-_ZN4time10get_uptimeEv
	.section	.rodata.str1.8
	.align	3
.LC13:
	.string	"Unable to set screen resolution to 1024x768x32\n"
	.text
	.align	2
	.p2align 4,,11
	.global	_ZN2fb4initE15FramebufferInfo
	.type	_ZN2fb4initE15FramebufferInfo, %function
_ZN2fb4initE15FramebufferInfo:
.LFB19:
	.cfi_startproc
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	mov	w3, w0
	lsr	x4, x0, 32
	str	x0, [sp]
	str	w1, [sp, 8]
	// Start of user assembly
// 21 "include/time.hpp" 1
	mrs x1, cntfrq_el0
// 0 "" 2
// 23 "include/time.hpp" 1
	mrs x2, cntpct_el0
// 0 "" 2
	// End of user assembly
	mov	x0, 63439
	lsr	x1, x1, 3
	movk	x0, 0xe353, lsl 16
	mov	x5, 34464
	movk	x0, 0x9ba5, lsl 32
	movk	x5, 0x1, lsl 16
	movk	x0, 0x20c4, lsl 48
	umulh	x1, x1, x0
	lsr	x1, x1, 4
	mul	x1, x1, x5
	lsr	x1, x1, 3
	umulh	x1, x1, x0
	lsr	x1, x1, 4
	.p2align 3,,7
.L127:
	// Start of user assembly
// 28 "include/time.hpp" 1
	mrs x0, cntpct_el0
// 0 "" 2
	// End of user assembly
	sub	x0, x0, x2
	cmp	x1, x0
	bhi	.L127
	adrp	x0, .LANCHOR0
	add	x1, x0, :lo12:.LANCHOR0
	mov	w2, 140
	mov	w5, 32771
	str	w2, [x0, #:lo12:.LANCHOR0]
	movk	w5, 0x4, lsl 16
	str	wzr, [x1, 4]
	mov	w0, 8
	str	w5, [x1, 8]
	mov	w2, 32772
	str	w0, [x1, 12]
	movk	w2, 0x4, lsl 16
	str	w0, [x1, 16]
	mov	w12, 32777
	str	w3, [x1, 20]
	movk	w12, 0x4, lsl 16
	str	w4, [x1, 24]
	mov	w11, 32773
	str	w2, [x1, 28]
	movk	w11, 0x4, lsl 16
	str	w0, [x1, 32]
	mov	w5, 4
	str	w0, [x1, 36]
	mov	w10, 32774
	str	w3, [x1, 40]
	movk	w10, 0x4, lsl 16
	str	w4, [x1, 44]
	mov	w9, 1
	str	w12, [x1, 48]
	mov	w8, 1
	str	w0, [x1, 52]
	movk	w8, 0x4, lsl 16
	str	w0, [x1, 56]
	mov	w7, 4096
	str	wzr, [x1, 60]
	mov	w6, 8
	str	wzr, [x1, 64]
	movk	w6, 0x4, lsl 16
	str	w11, [x1, 68]
	mov	x2, 47256
	str	w5, [x1, 72]
	orr	w3, w1, w0
	ldr	w4, [sp, 8]
	movk	x2, 0x3f00, lsl 16
	str	w5, [x1, 76]
	str	w4, [x1, 80]
	str	w10, [x1, 84]
	str	w5, [x1, 88]
	str	w5, [x1, 92]
	str	w9, [x1, 96]
	str	w8, [x1, 100]
	str	w0, [x1, 104]
	str	w0, [x1, 108]
	str	w7, [x1, 112]
	str	wzr, [x1, 116]
	str	w6, [x1, 120]
	str	w5, [x1, 124]
	str	w5, [x1, 128]
	str	wzr, [x1, 132]
	str	wzr, [x1, 136]
	.p2align 3,,7
.L128:
	// Start of user assembly
// 46 "include/mbox.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w0, [x2]
	tbnz	w0, #31, .L128
	mov	x0, 47264
	mov	x2, 47256
	movk	x0, 0x3f00, lsl 16
	mov	x4, 47232
	movk	x2, 0x3f00, lsl 16
	movk	x4, 0x3f00, lsl 16
	str	w3, [x0]
	.p2align 3,,7
.L144:
	// Start of user assembly
// 54 "include/mbox.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w0, [x2]
	tbnz	x0, 30, .L144
	ldr	w0, [x4]
	cmp	w3, w0
	bne	.L144
	ldr	w2, [x1, 4]
	mov	w0, -2147483648
	cmp	w2, w0
	bne	.L138
	ldr	w0, [x1, 80]
	cmp	w0, 32
	beq	.L146
	adrp	x3, .LC13
	mov	x1, 4120
	mov	x4, 4096
	add	x3, x3, :lo12:.LC13
	mov	w2, 85
	movk	x1, 0x3f20, lsl 16
	movk	x4, 0x3f20, lsl 16
	mov	w5, 13
	.p2align 3,,7
.L132:
	add	x3, x3, 1
	.p2align 3,,7
.L136:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w0, [x1]
	tbnz	x0, 5, .L136
	str	w2, [x4]
	ldrb	w2, [x3]
	cbz	w2, .L126
	cmp	w2, 10
	bne	.L132
	.p2align 3,,7
.L135:
	// Start of user assembly
// 67 "include/uart.hpp" 1
	nop
// 0 "" 2
	// End of user assembly
	ldr	w0, [x1]
	tbnz	x0, 5, .L135
	str	w5, [x4]
	ldrb	w2, [x3]
	b	.L132
.L138:
	mov	x1, 4120
	mov	x4, 4096
	adrp	x3, .LC13
	mov	w2, 85
	add	x3, x3, :lo12:.LC13
	movk	x1, 0x3f20, lsl 16
	movk	x4, 0x3f20, lsl 16
	mov	w5, 13
	b	.L132
.L146:
	ldr	w0, [x1, 112]
	cbz	w0, .L138
	ldr	w0, [x1, 112]
	and	w0, w0, 1073741823
	str	w0, [x1, 112]
	ldr	w5, [x1, 20]
	ldr	w4, [x1, 24]
	ldr	w3, [x1, 132]
	ldr	w2, [x1, 96]
	ldr	w0, [x1, 112]
	stp	w5, w4, [x1, 144]
	uxtw	x0, w0
	stp	w3, w2, [x1, 152]
	str	x0, [x1, 160]
.L126:
	add	sp, sp, 16
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE19:
	.size	_ZN2fb4initE15FramebufferInfo, .-_ZN2fb4initE15FramebufferInfo
	.align	2
	.p2align 4,,11
	.global	_ZN2fb5printEiiPc
	.type	_ZN2fb5printEiiPc, %function
_ZN2fb5printEiiPc:
.LFB20:
	.cfi_startproc
	ldrb	w3, [x2]
	cbz	w3, .L170
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	adrp	x12, .LANCHOR0
	add	x12, x12, :lo12:.LANCHOR0
	mov	x29, sp
	stp	x19, x20, [sp, 16]
	.cfi_offset 19, -32
	.cfi_offset 20, -24
	adrp	x19, _binary_src_uart_graphics_fonts_font_psf_start
	add	x19, x19, :lo12:_binary_src_uart_graphics_fonts_font_psf_start
	ldr	x16, [x12, 160]
	mov	w14, 1
	ldr	w13, [x19, 8]
	mov	w8, 16777215
	ldr	w30, [x19, 16]
	ldr	w18, [x19, 20]
	uxtw	x13, w13
	ldr	w20, [x19, 28]
	ldr	w11, [x19, 24]
	add	w15, w20, 7
	sub	w4, w20, #1
	add	x17, x16, w20, uxtw 2
	str	x21, [sp, 32]
	.cfi_offset 21, -16
	lsr	w15, w15, 3
	add	w21, w20, w14
	lsl	w14, w14, w4
	b	.L160
	.p2align 2,,3
.L175:
	cmp	w3, 10
	bne	.L173
	add	w1, w1, w11
	mov	w0, 0
.L150:
	ldrb	w3, [x2, 1]!
	cbz	w3, .L174
.L160:
	mul	w7, w3, w18
	cmp	w3, w30
	add	x7, x7, x13
	csel	x7, x7, x13, cc
	cmp	w3, 13
	bne	.L175
	ldrb	w3, [x2, 1]!
	mov	w0, 0
	cbnz	w3, .L160
.L174:
	ldp	x19, x20, [sp, 16]
	ldr	x21, [sp, 32]
	ldp	x29, x30, [sp], 48
	.cfi_remember_state
	.cfi_restore 30
	.cfi_restore 29
	.cfi_restore 21
	.cfi_restore 19
	.cfi_restore 20
	.cfi_def_cfa_offset 0
	ret
	.p2align 2,,3
.L173:
	.cfi_restore_state
	cbz	w11, .L155
	ldr	w9, [x12, 152]
	lsl	w3, w0, 2
	add	x7, x19, x7
	madd	w9, w1, w9, w3
	cbz	w20, .L155
	mov	w10, 0
	.p2align 3,,7
.L154:
	sxtw	x6, w9
	mov	w4, w14
	add	x3, x16, x6
	add	x6, x17, x6
	.p2align 3,,7
.L159:
	ldrb	w5, [x7]
	tst	w5, w4
	bne	.L156
	str	wzr, [x3], 4
	asr	w4, w4, 1
	cmp	x3, x6
	bne	.L159
	ldr	w3, [x12, 152]
	add	w10, w10, 1
	add	x7, x7, x15
	add	w9, w9, w3
	cmp	w10, w11
	bne	.L154
.L155:
	add	w0, w0, w21
	b	.L150
	.p2align 2,,3
.L156:
	str	w8, [x3], 4
	asr	w4, w4, 1
	cmp	x3, x6
	bne	.L159
	ldr	w3, [x12, 152]
	add	w10, w10, 1
	add	x7, x7, x15
	add	w9, w9, w3
	cmp	w10, w11
	bne	.L154
	b	.L155
.L170:
	.cfi_def_cfa_offset 0
	.cfi_restore 19
	.cfi_restore 20
	.cfi_restore 21
	.cfi_restore 29
	.cfi_restore 30
	ret
	.cfi_endproc
.LFE20:
	.size	_ZN2fb5printEiiPc, .-_ZN2fb5printEiiPc
	.align	2
	.p2align 4,,11
	.global	_ZN2fb5flushEv
	.type	_ZN2fb5flushEv, %function
_ZN2fb5flushEv:
.LFB21:
	.cfi_startproc
	adrp	x2, .LANCHOR0
	add	x2, x2, :lo12:.LANCHOR0
	ldp	w0, w1, [x2, 144]
	mul	w0, w0, w1
	cbz	w0, .L176
	mov	x0, 0
	.p2align 3,,7
.L178:
	ldr	x1, [x2, 160]
	strb	wzr, [x1, x0]
	add	x0, x0, 1
	ldp	w1, w3, [x2, 144]
	mul	w1, w1, w3
	cmp	w1, w0
	bhi	.L178
.L176:
	ret
	.cfi_endproc
.LFE21:
	.size	_ZN2fb5flushEv, .-_ZN2fb5flushEv
	.section	.rodata.str1.8
	.align	3
.LC14:
	.string	"Success\n"
	.align	3
.LC15:
	.string	"Hello, World!"
	.text
	.align	2
	.p2align 4,,11
	.global	kernel_main
	.type	kernel_main, %function
kernel_main:
.LFB22:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	x19, [sp, 16]
	.cfi_offset 19, -16
	adrp	x19, .LANCHOR0
	add	x19, x19, :lo12:.LANCHOR0
	bl	_ZN4uart4initEv
	bl	_ZN3mmu4initEv
	adrp	x0, .LC14
	add	x0, x0, :lo12:.LC14
	bl	_ZN4uart4putsEPh
	ldr	x0, [x19, 168]
	ldr	w1, [x19, 176]
	bl	_ZN2fb4initE15FramebufferInfo
	mov	w1, 0
	mov	w0, 0
	adrp	x2, .LC15
	add	x2, x2, :lo12:.LC15
	bl	_ZN2fb5printEiiPc
	ldp	w0, w1, [x19, 144]
	mul	w0, w0, w1
	cbz	w0, .L186
	mov	x0, 0
	.p2align 3,,7
.L185:
	ldr	x1, [x19, 160]
	strb	wzr, [x1, x0]
	add	x0, x0, 1
	ldp	w1, w2, [x19, 144]
	mul	w1, w1, w2
	cmp	w1, w0
	bhi	.L185
.L186:
	// Start of user assembly
// 15 "include/armv8a.hpp" 1
	wfe
// 0 "" 2
// 15 "include/armv8a.hpp" 1
	wfe
// 0 "" 2
	// End of user assembly
	b	.L186
	.cfi_endproc
.LFE22:
	.size	kernel_main, .-kernel_main
	.align	2
	.p2align 4,,11
	.global	exc_handler
	.type	exc_handler, %function
exc_handler:
.LFB23:
	.cfi_startproc
	ret
	.cfi_endproc
.LFE23:
	.size	exc_handler, .-exc_handler
	.global	fb_info
	.global	_ZN2fb6bufferE
	.global	isrgb
	.global	pitch
	.global	height
	.global	width
	.global	_ZN4mbox6bufferE
	.section	.rodata.cst16,"aM",@progbits,16
	.align	4
.LC2:
	.xword	1
	.xword	2
	.align	4
.LC3:
	.xword	2
	.xword	2
	.align	4
.LC4:
	.xword	503
	.xword	503
	.align	4
.LC5:
	.xword	516
	.xword	516
	.align	4
.LC6:
	.xword	768
	.xword	768
	.align	4
.LC7:
	.xword	18014398509483073
	.xword	18014398509483073
	.align	4
.LC8:
	.xword	0
	.xword	1
	.align	4
.LC9:
	.xword	127
	.xword	127
	.align	4
.LC10:
	.xword	18014398509481984
	.xword	18014398509481984
	.align	4
.LC11:
	.xword	128
	.xword	128
	.align	4
.LC12:
	.xword	1859
	.xword	1859
	.bss
	.align	4
	.set	.LANCHOR0,. + 0
	.type	_ZN4mbox6bufferE, %object
	.size	_ZN4mbox6bufferE, 144
_ZN4mbox6bufferE:
	.zero	144
	.type	width, %object
	.size	width, 4
width:
	.zero	4
	.type	height, %object
	.size	height, 4
height:
	.zero	4
	.type	pitch, %object
	.size	pitch, 4
pitch:
	.zero	4
	.type	isrgb, %object
	.size	isrgb, 4
isrgb:
	.zero	4
	.type	_ZN2fb6bufferE, %object
	.size	_ZN2fb6bufferE, 8
_ZN2fb6bufferE:
	.zero	8
	.type	fb_info, %object
	.size	fb_info, 12
fb_info:
	.zero	12
	.ident	"GCC: (GNU) 13.0.0 20220728 (experimental)"
