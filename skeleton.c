#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "../libc_impl.h"
#include "../helpers.h"

#define RM_RN 0
#define RM_RZ 1
#define RM_RP 2
#define RM_RM 3

union FloatReg {
    float f[2];
    uint32_t w[2];
    double d;
};

#define cvt_w_d(f) \
    ((fcsr & RM_RZ) ? ((isnan(f) || f <= -2147483649.0 || f >= 2147483648.0) ? (fcsr |= 0x40, 2147483647) : (int)f) : (assert(0), 0))

#define cvt_w_s(f) cvt_w_d((double)f)

int func(uint8_t *mem, int argc, char *argv[]) {
    const uint32_t zero = 0;
    uint32_t at = 0, v0 = 0, v1 = 0, a0 = 0, a1 = 0, a2 = 0, a3 = 0, t0 = 0, t1 = 0, t2 = 0,
    t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0,
    s6 = 0, s7 = 0, t8 = 0, t9 = 0, k0 = 0, k1 = 0, gp = 0, sp = 0, fp = 0, s8 = 0, ra = 0;
    uint32_t lo = 0, hi = 0;
    union FloatReg f0 = {{0, 0}}, f2 = {{0, 0}}, f4 = {{0, 0}}, f6 = {{0, 0}}, f8 = {{0, 0}},
    f10 = {{0, 0}}, f12 = {{0, 0}}, f14 = {{0, 0}}, f16 = {{0, 0}}, f18 = {{0, 0}}, f20 = {{0, 0}},
    f22 = {{0, 0}}, f24 = {{0, 0}}, f26 = {{0, 0}}, f28 = {{0, 0}}, f30 = {{0, 0}};
    int cf = 0;
    uint32_t fcsr = 1;
    void *dest = NULL;
    uint64_t temp64;
#include "dummy.c"
}
