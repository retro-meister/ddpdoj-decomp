extern unsigned short rng_cursor;
extern unsigned short work_reg_0;
extern signed char rng_values[256];

void func_002010A0(void)
{
    ++*(unsigned char *)&rng_cursor;
    work_reg_0 = rng_cursor;
    *(unsigned char *)&work_reg_0 = rng_values[work_reg_0];
}
