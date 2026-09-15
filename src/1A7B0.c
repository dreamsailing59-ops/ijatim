#include "common.h"

INCLUDE_ASM("asm/nonmatchings/1A7B0", func_80019BB0);

// INCLUDE_ASM("asm/nonmatchings/1A7B0", func_80019C60);
u8* func_80019C60(u8* arg0, u8* arg1) {
    u8 temp_v0;
    u8* var_a1;
    u8* var_v1;

    var_a1 = arg1;
    var_v1 = arg0;
    do {
        temp_v0 = *var_a1;
        var_a1 += 1;
        *var_v1 = temp_v0;
        var_v1 += 1;
    } while (temp_v0 != 0);
    return arg0;
}

// INCLUDE_ASM("asm/nonmatchings/1A7B0", func_80019C80);
u8* func_80019C80(u8* arg0, u8* arg1, s32 arg2) {
    u8* cur = arg0;

    if (arg2 > 0) {
        do {
            u8* p = cur;
            u8 val = *arg1;

            cur = p + 1;
            if (val != 0) {
                arg1++;
            } else {
                val = 0;
            }
            arg2--;
            *p = val;
        } while (arg2 > 0);
    }
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/1A7B0", func_80019CBC);

INCLUDE_ASM("asm/nonmatchings/1A7B0", func_80019CF4);

INCLUDE_ASM("asm/nonmatchings/1A7B0", func_80019D34);
