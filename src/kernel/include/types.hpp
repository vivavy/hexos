#if defined(__x86_64__) || defined(_M_X64) // annoying but all is okay
    #include <arch/amd64/types.hpp>
#elif defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86)
    #include <arch/ia32/types.hpp>
#elif defined(__ARM_ARCH_7S__)
    #include <arch/aarch32/types.hpp>
#elif defined(__aarch64__) || defined(_M_ARM64)
    #include <arch/aarch64/types.hpp>
#elif defined(mips) || defined(__mips__) || defined(__mips)
    #include <arch/mips/types.hpp>
#elif defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__PPC__) || defined(_ARCH_PPC)
    #include <arch/ppc/types.hpp>
#endif
