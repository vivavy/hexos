#include <types.hpp>

namespace rd {
    enum rights {
        D = 1ULL << 0,
        Cr = 1ULL << 1,
        Cw = 1ULL << 2,
        Cx = 1ULL << 3,
        Gr = 1ULL << 4,
        Gw = 1ULL << 5,
        Gx = 1ULL << 6,
        Or = 1ULL << 7,
        Ow = 1ULL << 8,
        Ox = 1ULL << 9,
        r1 = 1ULL << 1,
        w1 = 1ULL << 2,
        x1 = 1ULL << 3,
        r2 = 1ULL << 4,
        w2 = 1ULL << 5,
        x2 = 1ULL << 6,
        r3 = 1ULL << 7,
        w3 = 1ULL << 8,
        x3 = 1ULL << 9,
    };
};
