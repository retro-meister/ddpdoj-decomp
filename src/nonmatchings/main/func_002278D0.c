typedef struct {
    signed char unk0;
    signed char state;
    short unk2;
    short value;
} Fade;

extern Fade D_0028EC18;
extern void *D_00270850[];

extern void func_002274C0(void *, void **, int);


static void func_00227440(Fade *fade) {
    switch (fade->state) {
    case 0:
        break;
    case 1:
        fade->value += 4;
        if (fade->value >= 0x80) {
            fade->value = 0x80;
            fade->state = 0;
        }
        break;
    case 2:
        fade->value -= 4;
        if (0 >= fade->value) {
            fade->value = 0;
            fade->state = 0;
        }
        break;
    }
}


void func_002278D0(void)
{
    func_00227440(&D_0028EC18);
    func_002274C0(&D_0028EC18, D_00270850, 7);
}
