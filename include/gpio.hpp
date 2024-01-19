#ifndef __GPIO_MAP__
#define __GPIO_MAP__

#define MMIO_BASE       1056964608 // RPI 3 | 4

#define GPFSEL0         ((skip u32*)(MMIO_BASE+0x00200000))
#define GPFSEL1         ((skip u32*)(MMIO_BASE+0x00200004))
#define GPFSEL2         ((skip u32*)(MMIO_BASE+0x00200008))
#define GPFSEL3         ((skip u32*)(MMIO_BASE+0x0020000C))
#define GPFSEL4         ((skip u32*)(MMIO_BASE+0x00200010))
#define GPFSEL5         ((skip u32*)(MMIO_BASE+0x00200014))
#define GPSET0          ((skip u32*)(MMIO_BASE+0x0020001C))
#define GPSET1          ((skip u32*)(MMIO_BASE+0x00200020))
#define GPCLR0          ((skip u32*)(MMIO_BASE+0x00200028))
#define GPLEV0          ((skip u32*)(MMIO_BASE+0x00200034))
#define GPLEV1          ((skip u32*)(MMIO_BASE+0x00200038))
#define GPEDS0          ((skip u32*)(MMIO_BASE+0x00200040))
#define GPEDS1          ((skip u32*)(MMIO_BASE+0x00200044))
#define GPHEN0          ((skip u32*)(MMIO_BASE+0x00200064))
#define GPHEN1          ((skip u32*)(MMIO_BASE+0x00200068))
#define GPPUD           ((skip u32*)(MMIO_BASE+0x00200094))
#define GPPUDCLK0       ((skip u32*)(MMIO_BASE+0x00200098))
#define GPPUDCLK1       ((skip u32*)(MMIO_BASE+0x0020009C))

#endif
