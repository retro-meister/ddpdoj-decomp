#ifndef DDPDOJ_PC_DATA_ALIAS_H
#define DDPDOJ_PC_DATA_ALIAS_H

#ifdef __APPLE__
#define PC_ASM_SYMBOL(name) "_" #name
#else
#define PC_ASM_SYMBOL(name) #name
#endif
#define PC_ASM_EXPRESSION(expression) PC_ASM_STRING(expression)
#define PC_ASM_STRING(expression) #expression

/* Bind a PS2 interior label to the same bytes in its native backing array.
 * Keep the alias in the translation unit that defines the array so its
 * address can be emitted in both Mach-O and COFF. */
#define PC_DATA_ALIAS(alias, backing, offset) \
    _Static_assert((offset) >= 0 && (offset) < sizeof(backing), \
                   #alias " lies outside " #backing); \
    __asm__(".globl " PC_ASM_SYMBOL(alias) "\n" \
            ".set " PC_ASM_SYMBOL(alias) ", " PC_ASM_SYMBOL(backing) " + " PC_ASM_EXPRESSION(offset))

#endif
