/*
Implementation by Ronny Van Keer, hereby denoted as "the implementer".

For more information, feedback or questions, please refer to our website:
https://keccak.team/

To the extent possible under law, the implementer has waived all copyright
and related or neighboring rights to the source code in this file.
http://creativecommons.org/publicdomain/zero/1.0/

---

Please refer to SnP-documentation.h for more details.
*/

#ifndef _KeccakP_200_SnP_h_
#define _KeccakP_200_SnP_h_

#ifdef __cplusplus
extern "C" {
#endif

#define KeccakP200_implementation      "8-bit optimized AVR assembler implementation"
#define KeccakP200_stateSizeInBytes    25
#define KeccakP200_stateAlignment      8

void KeccakP200_StaticInitialize( void );
/* #define   KeccakP200_StaticInitialize() */
void KeccakP200_Initialize(void *state);
void KeccakP200_AddByte(void *state, unsigned char data, unsigned int offset);
/* #define   KeccakP200_AddByte(argS, argData, argOffset)    ((unsigned char*)argS)[argOffset] ^= (argData) */
void KeccakP200_AddBytes(void *state, const unsigned char *data, unsigned int offset, unsigned int length);
void KeccakP200_OverwriteBytes(void *state, const unsigned char *data, unsigned int offset, unsigned int length);
void KeccakP200_OverwriteWithZeroes(void *state, unsigned int byteCount);
void KeccakP200_Permute_Nrounds(void *state, unsigned int nrounds);
void KeccakP200_Permute_18rounds(void *state);
void KeccakP200_ExtractBytes(const void *state, unsigned char *data, unsigned int offset, unsigned int length);
void KeccakP200_ExtractAndAddBytes(const void *state, const unsigned char *input, unsigned char *output, unsigned int offset, unsigned int length);

#ifdef __cplusplus
}
#endif

#endif
