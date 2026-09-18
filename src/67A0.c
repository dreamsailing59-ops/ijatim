#include "common.h"

typedef struct {
    u8 pad0[0x10];
    u32 *unk10;
} UnkArg0;

INCLUDE_ASM("asm/nonmatchings/67A0", func_80005BA0);

INCLUDE_ASM("asm/nonmatchings/67A0", func_80005CFC);

// INCLUDE_ASM("asm/nonmatchings/67A0", func_80005D10);
void func_80005D10(u16 arg0, s32 arg1, u8 arg2) {
    func_80005BA0(arg0, arg1, arg2);
}

// INCLUDE_ASM("asm/nonmatchings/67A0", func_80005D30);
void func_80005D30(u8 *arg0) {
    arg0[9] = 2;
    func_80041B80(arg0 + 0x48);
}

// INCLUDE_ASM("asm/nonmatchings/67A0", func_80005D54);
s32 func_80005D54(UnkArg0 *arg0) {
    if (arg0->unk10[0] != 0xDEADBEAF || arg0->unk10[1] != 0xDEADBEAF) {
        return 0;
    } else {
        return 1;
    }
}

// INCLUDE_ASM("asm/nonmatchings/67A0", func_80005D88);
s32 func_80005D88(u8 *arg0) {
    if (func_800408E0(arg0 + 0x2C, arg0 + 0x28, 0) == -1) {
        return 0;
    }
    return *(s32 *)(arg0 + 0x28);
}

// INCLUDE_ASM("asm/nonmatchings/67A0", func_80005DC8);
s32 func_80005DC8(u8 *arg0) {
    func_800408E0(arg0 + 0x2C, arg0 + 0x28, 1);
    return *(s32 *)(arg0 + 0x28);
}

INCLUDE_ASM("asm/nonmatchings/67A0", func_80005DFC);

// INCLUDE_ASM("asm/nonmatchings/67A0", func_80005E74);
void func_80005E74(u8 *arg0) {
    s32 arg1 = *(s32 *)(arg0 + 4);
    arg0[2] |= 0x40;
    func_8003D480(arg1, arg0, 1);
}

INCLUDE_ASM("asm/nonmatchings/67A0", func_80005EA4);

INCLUDE_ASM("asm/nonmatchings/67A0", func_80005F30);

// INCLUDE_ASM("asm/nonmatchings/67A0", func_80005F68);
s32 func_80005F68(void) {
    return 0;
}

// INCLUDE_ASM("asm/nonmatchings/67A0", func_80005F70);
s32 func_80005F70(s32 arg0) {
    s32 temp_s1;

    temp_s1 = func_800018DC(arg0 * 4 + 0x1C, 0);
    func_8003C430(temp_s1, temp_s1 + 0x1C, arg0);
    return temp_s1;
}

// INCLUDE_ASM("asm/nonmatchings/67A0", func_80005FC0);
s32 func_80005FC0(u8 *arg0) {
    func_800408E0(arg0, arg0 + 0x18, 1);
    return *(s32 *)(arg0 + 0x18);
}

// INCLUDE_ASM("asm/nonmatchings/67A0", func_80005FF0);
s32 func_80005FF0(u8 *arg0) {
    if (func_800408E0(arg0, arg0 + 0x18, 0) == -1) {
        return 0;
    }
    return *(s32 *)(arg0 + 0x18);
}

INCLUDE_ASM("asm/nonmatchings/67A0", func_8000602C);
