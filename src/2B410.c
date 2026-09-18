#include "common.h"

typedef struct {
    /* 0x00 */ u8 pad[4];
    /* 0x04 */ u16 unk4;
} Struct8002BC04;

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002A810);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002A964);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002AA58);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002ABDC);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002ACE8);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002AE50);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002AF44);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002B084);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002B16C);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002B364);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002B4DC);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002B574);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002B698);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002B73C);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002B7F4);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002B8F0);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002B9CC);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002BA2C);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002BA8C);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002BB04);

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002BBAC);

// INCLUDE_ASM("asm/nonmatchings/2B410", func_8002BC04);
s32 func_8002BC04(Struct8002BC04 *arg0, Struct8002BC04 *arg1) {
    return arg0->unk4 - arg1->unk4;
}

// INCLUDE_ASM("asm/nonmatchings/2B410", func_8002BC14);
s32 func_8002BC14(u16* arg0, u16* arg1) {
    return *arg0 - *arg1;
}

// INCLUDE_ASM("asm/nonmatchings/2B410", func_8002BC24);
s32 func_8002BC24(Struct8002BC04* arg0, Struct8002BC04* arg1) {
    return arg0->unk4 - arg1->unk4;
}

// INCLUDE_ASM("asm/nonmatchings/2B410", func_8002BC34);
s32 func_8002BC34(Struct8002BC04* arg0, Struct8002BC04* arg1) {
    return arg0->unk4 - arg1->unk4;
}

INCLUDE_ASM("asm/nonmatchings/2B410", func_8002BC44);
