#include "common.h"

s32 func_80025680();                                  /* extern */
s32 func_800259D0(s32);                               /* extern */
s32 func_80025AE4();                                  /* extern */
s32 func_8002CBC0(void /* this might also take a s32 */);                                /* extern */
s32 func_800344BC(s32);                               /* extern */

INCLUDE_ASM("asm/nonmatchings/30290", func_8002F690);

INCLUDE_ASM("asm/nonmatchings/30290", func_8002F710);

INCLUDE_ASM("asm/nonmatchings/30290", func_8002F898);

INCLUDE_ASM("asm/nonmatchings/30290", func_8002F9EC);

// INCLUDE_ASM("asm/nonmatchings/30290", func_8002FB40);
void func_8002FB40(void) {
    func_80025680();
}

// INCLUDE_ASM("asm/nonmatchings/30290", func_8002FB5C);
void func_8002FB5C(void) {
    func_80025AE4();
}

INCLUDE_ASM("asm/nonmatchings/30290", func_8002FB78);

INCLUDE_ASM("asm/nonmatchings/30290", func_8002FBE4);

INCLUDE_ASM("asm/nonmatchings/30290", func_8002FC7C);

INCLUDE_ASM("asm/nonmatchings/30290", func_8002FC88);

INCLUDE_ASM("asm/nonmatchings/30290", func_8002FCEC);

INCLUDE_ASM("asm/nonmatchings/30290", func_8002FD2C);

INCLUDE_ASM("asm/nonmatchings/30290", func_8002FDC8);

// INCLUDE_ASM("asm/nonmatchings/30290", func_8002FE4C);
s32 func_8002FE4C(s32 arg0) {

    if (func_8002CBC0() != -1) {
        return arg0;
    }

    return -1;
}

INCLUDE_ASM("asm/nonmatchings/30290", func_8002FE84);

INCLUDE_ASM("asm/nonmatchings/30290", func_8002FED8);

INCLUDE_ASM("asm/nonmatchings/30290", func_8002FF3C);

INCLUDE_ASM("asm/nonmatchings/30290", func_8002FFA0);

INCLUDE_ASM("asm/nonmatchings/30290", func_80030004);

INCLUDE_ASM("asm/nonmatchings/30290", func_80030068);

INCLUDE_ASM("asm/nonmatchings/30290", func_800300CC);

INCLUDE_ASM("asm/nonmatchings/30290", func_8003014C);

INCLUDE_ASM("asm/nonmatchings/30290", func_80030168);

INCLUDE_ASM("asm/nonmatchings/30290", func_800301C4);

INCLUDE_ASM("asm/nonmatchings/30290", func_800301F0);

INCLUDE_ASM("asm/nonmatchings/30290", func_80030234);

INCLUDE_ASM("asm/nonmatchings/30290", func_80030280);

INCLUDE_ASM("asm/nonmatchings/30290", func_800302CC);

INCLUDE_ASM("asm/nonmatchings/30290", func_800303A0);

INCLUDE_ASM("asm/nonmatchings/30290", func_800303E8);

INCLUDE_ASM("asm/nonmatchings/30290", func_80030430);

INCLUDE_ASM("asm/nonmatchings/30290", func_80030450);

INCLUDE_ASM("asm/nonmatchings/30290", func_80030514);

// INCLUDE_ASM("asm/nonmatchings/30290", func_80030534);
void func_80030534(s32 arg0) {
    func_800344BC(arg0 & 0xFF);
}

INCLUDE_ASM("asm/nonmatchings/30290", func_80030550);

// INCLUDE_ASM("asm/nonmatchings/30290", func_8003056C);
void func_8003056C(s32 arg0) {
    func_800259D0(arg0 & 0xFF);
}

INCLUDE_ASM("asm/nonmatchings/30290", func_80030588);
