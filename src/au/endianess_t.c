#include "defs.h"
#include "endianess_t.h"

// antonio: wiggly-custom-code start
// endianessT reverses bits
Word32 endianessT(Word16 value) {
    //return value;

    Word16 bitIndex = 0;
    Word32 accumulator = 0;

    do {
        while ((value >> bitIndex & 1) != 0) {
            Word16 exp = 15 - bitIndex;
            bitIndex++;
            double powResult = pow(2.0, exp);
            accumulator = (Word16) (accumulator + powResult);
            if (bitIndex == 16) {
                return accumulator;
            }
        }
        bitIndex++;
    } while (bitIndex != 16);

    return accumulator;
}

/* Original decompiled
 * Word16 endianessT(Word16 param_1) {
    //return param_1;

    int iVar1;
    unsigned int uVar2;
    int iVar3;
    double dVar4;

    uVar2 = 0;
    iVar3 = 0;
    do {
        while (((int) param_1 >> (uVar2 & 0x1f) & 1U) != 0) {
            iVar1 = 0xf - uVar2;
            uVar2 = uVar2 + 1;
            dVar4 = pow(2.0, (double) iVar1);
            iVar3 = (int) (short) (int) ((double) iVar3 + dVar4);
            if (uVar2 == 0x10) {
                return iVar3;
            }
        }
        uVar2 = uVar2 + 1;
    } while (uVar2 != 0x10);
    return iVar3;
}
 */
// antonio: wiggly-custom-code end