#include "common.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

void func_00210EA0(void);
void func_00211140(void);
void func_00211420(void);
void func_00211720(void);
void func_00211920(void);
void func_002119A0(void);
void func_00211E90(void);
void func_00211F40(void);

extern u16 D_00246C50[];
extern u16 D_00247080[];
extern u16 D_00255470[];
extern u16 D_002554B0_as_u16_a[];
extern u16 D_0025F770_as_u16_a[];
extern u16 D_0025FBB0_as_u16_a[];
extern u16 D_0025FBF0_as_u16_a[];
extern u16 D_0025FC30_as_u16_a[];
extern u16 D_0025FC70_as_u16_a[];
extern u16 D_0025FCB0_as_u16_a[];
extern u16 D_0025FCF0_as_u16_a[];
extern u16 D_0025FD30_as_u16_a[];
extern u16 D_0025FD70_as_u16_a[];
extern u16 D_0025FDB0_as_u16_a[];
extern u16 D_00260FF0[];
extern u16 D_002610F0[];
extern u16 D_00261D30[];
extern u16 D_00261DF0[];
extern u16 D_00261F30[];
extern u16 D_00261FF0[];
extern u16 D_00262030[];
extern u16 D_00262070[];
extern u16 D_002620B0[];
extern u16 D_00262230[];
extern u16 D_00262270[];
extern u16 D_002622B0[];
extern u16 D_002622F0[];
extern u16 D_00262330[];
extern u16 D_00262370[];
extern u16 D_002623F0_as_u16_a[];
extern u16 D_00262430_as_u16_a[];
extern u16 D_00262470[];
extern u16 D_002624B0[];
extern u16 D_002687B0_as_u16_a[];
extern u16 D_00269750[];
extern u16 D_00269780[];
extern u16 D_002697B0[];
extern u16 D_00274040[];
extern u16 D_00274840[];
extern u16 D_00275040[];
extern u32 D_0028DFD4_as_u32;
extern u32 D_0028DFD8_as_u32;
extern u16 D_0028E078_as_u16_a[];
extern u16 D_0028E080_as_u16_a[];
extern u32 g_p2_lives_as_u32;
extern u32 g_p1_lives_as_u32;
extern u16 D_002962E0_as_u16_a[];
extern u16 D_00299764[];
extern u16 D_00299780[];
extern u16 D_00299D30_as_u16_a[];
extern u16 D_0029A12C_as_u16_a[];
extern u16 D_0029A530[];
extern u16 D_0029AA40_as_u16_a[];
extern u16 D_0029CEA0[];
extern u16 D_0029D710_as_u16_a[];
extern u16 D_0029D730_as_u16_a[];
extern u16 D_0029D750_as_u16_a[];
extern u16 D_0029D770_as_u16_a[];
extern u16 D_0029D790_as_u16_a[];
extern u16 D_0029DD90_as_u16_a[];
extern u16 D_0029E390_as_u16_a[];
extern u16 D_0029EA50_as_u16_a[];
extern u16 D_0029F110_as_u16_a[];
extern u16 D_0029F180_as_u16_a[];
extern u16 g_player2_as_u16_a[];
extern u16 g_player1_as_u16_a[];
extern u16 g_deferred_text_as_u16_a[];
extern u16 D_002BAF30[];
extern u16 D_002BAF3A[];
extern u16 D_002BAF50[];
extern u16 D_002BAFAA[];
extern u16 D_002BB470_as_u16_a[];
extern u16 D_002BB4B0_as_u16_a[];
extern u16 D_002BC7C0_as_u16_a[];
extern u16 D_002BD440[];
extern u16 D_002BF3EA_as_u16_a[];
extern u16 D_002BF400[];
extern u16 D_002BF4F0_as_u16_a[];
extern void func_00130250(void);
extern void func_00130260(void);
extern void input_get_p1_held(void);
extern void input_get_p2_held(void);
extern void input_get_p1_pressed(void);
extern void input_get_p2_pressed(void);

extern u16 D_002693C8[];
extern u16 D_002693D6[];
extern u16 D_00269718[];
extern u16 D_00269728[];
extern u16 D_00269738[];
extern u16 D_00269808[];
extern u16 D_00269816[];
extern u16 D_00269848[];
extern u16 D_00269856[];
extern u16 D_00269864[];
extern u16 D_00269872[];
extern u16 D_00269880[];
extern u16 D_0026988E[];
extern u16 D_0026989C[];
extern u16 D_002698B6[];
extern u16 D_002698C2[];
extern u16 D_002698CE[];
extern u16 D_002698DA[];
extern u16 D_002698E6[];
extern u16 D_002698F2[];
extern u16 D_002698FE[];
extern u16 D_0026990A[];
extern u16 D_00269926[];
extern u16 D_00269932[];
extern u16 D_0026993E[];
extern u16 D_0026994A[];
extern u16 D_00269956[];
extern u16 D_00269962[];
extern u16 D_0026996E[];
extern u16 D_0026997A[];
extern u16 D_00269986[];
extern u16 D_00269992[];
extern u16 D_0026999E[];
extern u16 D_002699AA[];
extern u16 D_002699B6[];
extern u16 D_002699C2[];
extern u16 D_002699CE[];
extern u16 D_002699DA[];
extern u16 D_002699E6[];
extern u16 D_002699F2[];
extern u16 D_002699FE[];
extern u16 D_00269CD4[];
extern u16 D_00269CD8[];
extern u16 D_00269CDC[];
extern u16 D_00269CE0[];
extern u16 D_00269CF4[];
extern u16 D_00269CF8[];
extern u16 D_00269CFC[];
extern u16 D_00269D00[];
extern u16 D_00269D1C[];
extern u16 D_00269D2C[];
extern u16 D_00269E26[];
extern u16 D_00269E46[];
extern u16 D_00269E66[];
extern u16 D_00269E86[];
extern u16 D_00269EA6[];
extern u16 D_00269EC6[];
extern u16 D_00269EE6[];
extern u16 D_00269F06[];
extern u16 D_00269F26[];
extern u16 D_00269F46[];
extern u16 D_00269F66[];
extern u16 D_00269F86[];
extern u16 D_00269FA6[];
extern u16 D_00269FC6[];
extern u16 D_00269FE6[];
extern u16 D_0026A006[];
extern u16 D_0026A026[];
extern u16 D_0026A046[];
extern u16 D_0026A066[];
extern u16 D_0026A086[];
extern u16 D_0026A0A6[];
extern u16 D_0026A0C6[];
extern u16 D_0026A0E6[];
extern u16 D_0026A106[];
extern u16 D_0026A126[];
extern u16 D_0026A146[];
extern u16 D_0026A166[];
extern u16 D_0026A186[];
extern u16 D_0026A1A6[];
extern u16 D_0026A1C6[];
extern u16 D_0026A1E6[];
extern u16 D_0026A206[];
extern u16 D_0026A226[];
extern u16 D_0026A246[];
extern u16 D_0026A268[];
extern u16 D_0026A278[];
extern u16 D_0026A288[];
extern u16 D_0026A3F8[];
extern u16 D_0026A628[];
extern u16 D_0026A636[];
extern u16 D_0026A644[];
extern u16 D_0026A652[];
extern u16 D_0026B588[];
extern u16 D_0026B596[];
extern u16 D_0026B5A4[];
extern u16 D_0026B5B2[];
extern u16 D_0026B5C0[];
extern u16 D_0026B5CE[];
extern u16 D_0026B5DC[];
extern u16 D_0026C798[];
extern u16 D_0026C7A6[];
extern u16 D_0026C7B6[];
extern u16 D_0026C7C2[];
extern u16 D_0026C7CE[];
extern u16 D_0026C7DA[];
extern u16 D_0026C7E6[];
extern u16 D_0026C7F2[];
extern u16 D_0026C8C8[];
extern u16 D_0026C8D6[];
extern u16 D_0026C8E4[];
extern u16 D_0026C8F2[];
extern u16 D_0026C900[];
extern u16 D_0026C90E[];
extern u16 D_0026CBC8[];
extern u16 D_0026CBD6[];
extern u16 D_0026CBE4[];
extern u16 D_0026D8A8[];
extern u16 D_0026D8B6[];
extern u16 D_0026D8C4[];
extern u16 D_0026D8D2[];
extern u16 D_0026D8E0[];
extern u16 D_0026D8EE[];
extern u16 D_0026D8FC[];
extern u16 D_0026D90A[];
extern u16 D_0026D918[];
extern u16 D_0026D926[];
extern u16 D_0026D934[];
extern u16 D_0026D942[];
extern u16 D_0026D950[];
extern u16 D_0026D95E[];
extern u16 D_0026D96C[];
extern u16 D_0026D97A[];
extern u16 D_0026D996[];
extern u16 D_0026D9A2[];
extern u16 D_0026D9AE[];

void func_0020F550(void) {
    STORE_POINTER(D_002693C8, D_002624B0);
    STORE_POINTER(D_002693D6, D_002554B0_as_u16_a);
    STORE_POINTER(D_00269718, D_00269750);
    STORE_POINTER(D_00269728, D_00269780);
    STORE_POINTER(D_00269738, D_002697B0);
    STORE_POINTER(D_00269808, D_00262470);
    STORE_POINTER(D_00269816, D_002554B0_as_u16_a);
    STORE_POINTER(D_00269848, D_00261F30);
    STORE_POINTER(D_00269856, D_00261FF0);
    STORE_POINTER(D_00269864, D_00262030);
    STORE_POINTER(D_00269872, D_00262070);
    STORE_POINTER(D_00269880, D_002620B0);
    STORE_POINTER(D_0026988E, D_002622B0);
    STORE_POINTER(D_0026989C, D_00260FF0);
    STORE_POINTER(D_002698B6, D_002554B0_as_u16_a);
    STORE_POINTER(D_002698C2, D_002554B0_as_u16_a);
    STORE_POINTER(D_002698CE, D_002554B0_as_u16_a);
    STORE_POINTER(D_002698DA, D_002554B0_as_u16_a);
    STORE_POINTER(D_002698E6, D_002554B0_as_u16_a);
    STORE_POINTER(D_002698F2, D_002554B0_as_u16_a);
    STORE_POINTER(D_002698FE, D_002554B0_as_u16_a);
    STORE_POINTER(D_0026990A, D_002554B0_as_u16_a);
    STORE_POINTER(D_00269926, D_00255470);
    STORE_POINTER(D_00269932, D_00255470);
    STORE_POINTER(D_0026993E, D_00255470);
    STORE_POINTER(D_0026994A, D_00255470);
    STORE_POINTER(D_00269956, D_00255470);
    STORE_POINTER(D_00269962, D_00255470);
    STORE_POINTER(D_0026996E, D_00255470);
    STORE_POINTER(D_0026997A, D_00255470);
    STORE_POINTER(D_00269986, D_00255470);
    STORE_POINTER(D_00269992, D_00255470);
    STORE_POINTER(D_0026999E, D_00255470);
    STORE_POINTER(D_002699AA, D_00255470);
    STORE_POINTER(D_002699B6, D_00255470);
    STORE_POINTER(D_002699C2, D_00255470);
    STORE_POINTER(D_002699CE, D_00255470);
    STORE_POINTER(D_002699DA, D_00255470);
    STORE_POINTER(D_002699E6, D_00255470);
    STORE_POINTER(D_002699F2, D_00255470);
    STORE_POINTER(D_002699FE, D_00255470);
    STORE_POINTER(D_00269CD4, func_00130250);
    STORE_POINTER(D_00269CD8, input_get_p1_held);
    STORE_POINTER(D_00269CDC, input_get_p1_pressed);
    STORE_POINTER(D_00269CE0, D_002BF3EA_as_u16_a);
    STORE_POINTER(D_00269CF4, func_00130260);
    STORE_POINTER(D_00269CF8, input_get_p2_held);
    STORE_POINTER(D_00269CFC, input_get_p2_pressed);
    STORE_POINTER(D_00269D00, D_002BF400);
    STORE_POINTER(D_00269D1C, &g_p1_lives_as_u32);
    STORE_POINTER(D_00269D2C, &g_p2_lives_as_u32);
    STORE_POINTER(D_00269E26, D_0029CEA0);
    STORE_POINTER(D_00269E46, g_player1_as_u16_a);
    STORE_POINTER(D_00269E66, g_player2_as_u16_a);
    STORE_POINTER(D_00269E86, D_0029F180_as_u16_a);
    STORE_POINTER(D_00269EA6, D_0029F110_as_u16_a);
    STORE_POINTER(D_00269EC6, D_0029E390_as_u16_a);
    STORE_POINTER(D_00269EE6, D_0029EA50_as_u16_a);
    STORE_POINTER(D_00269F06, D_0029DD90_as_u16_a);
    STORE_POINTER(D_00269F26, D_0029D790_as_u16_a);
    STORE_POINTER(D_00269F46, D_0029D770_as_u16_a);
    STORE_POINTER(D_00269F66, D_0029D750_as_u16_a);
    STORE_POINTER(D_00269F86, D_0029D730_as_u16_a);
    STORE_POINTER(D_00269FA6, D_0029D710_as_u16_a);
    STORE_POINTER(D_00269FC6, D_0028E080_as_u16_a);
    STORE_POINTER(D_00269FE6, D_0028E078_as_u16_a);
    STORE_POINTER(D_0026A006, D_002BC7C0_as_u16_a);
    STORE_POINTER(D_0026A026, D_002BD440);
    STORE_POINTER(D_0026A046, D_002BB4B0_as_u16_a);
    STORE_POINTER(D_0026A066, &D_0028DFD8_as_u32);
    STORE_POINTER(D_0026A086, &D_0028DFD4_as_u32);
    STORE_POINTER(D_0026A0A6, D_002BF4F0_as_u16_a);
    STORE_POINTER(D_0026A0C6, D_00299D30_as_u16_a);
    STORE_POINTER(D_0026A0E6, D_0029A12C_as_u16_a);
    STORE_POINTER(D_0026A106, g_deferred_text_as_u16_a);
    STORE_POINTER(D_0026A126, D_002BAF50);
    STORE_POINTER(D_0026A146, D_002BAFAA);
    STORE_POINTER(D_0026A166, D_002BAF30);
    STORE_POINTER(D_0026A186, D_002BAF3A);
    STORE_POINTER(D_0026A1A6, D_002962E0_as_u16_a);
    STORE_POINTER(D_0026A1C6, D_002BB470_as_u16_a);
    STORE_POINTER(D_0026A1E6, D_0029A530);
    STORE_POINTER(D_0026A206, D_00299764);
    STORE_POINTER(D_0026A226, D_0029AA40_as_u16_a);
    STORE_POINTER(D_0026A246, D_00299780);
    STORE_POINTER(D_0026A268, D_00274040);
    STORE_POINTER(D_0026A278, D_00274840);
    STORE_POINTER(D_0026A288, D_00275040);
    STORE_POINTER(D_0026A3F8, D_00261DF0);
    STORE_POINTER(D_0026A628, D_00262430_as_u16_a);
    STORE_POINTER(D_0026A636, D_002623F0_as_u16_a);
    STORE_POINTER(D_0026A644, D_0025F770_as_u16_a);
    STORE_POINTER(D_0026A652, D_002687B0_as_u16_a);
    STORE_POINTER(D_0026B588, D_00262230);
    STORE_POINTER(D_0026B596, D_00262270);
    STORE_POINTER(D_0026B5A4, D_002622F0);
    STORE_POINTER(D_0026B5B2, D_00262330);
    STORE_POINTER(D_0026B5C0, D_00262370);
    STORE_POINTER(D_0026B5CE, D_00261F30);
    STORE_POINTER(D_0026B5DC, D_002622B0);
    STORE_POINTER(D_0026C798, D_002610F0);
    STORE_POINTER(D_0026C7A6, D_00246C50);
    STORE_POINTER(D_0026C7B6, D_00261D30);
    STORE_POINTER(D_0026C7C2, D_00261D30);
    STORE_POINTER(D_0026C7CE, D_00261D30);
    STORE_POINTER(D_0026C7DA, D_00261D30);
    STORE_POINTER(D_0026C7E6, D_00261D30);
    STORE_POINTER(D_0026C7F2, D_00261D30);
    STORE_POINTER(D_0026C8C8, D_0025FBB0_as_u16_a);
    STORE_POINTER(D_0026C8D6, D_0025FBF0_as_u16_a);
    STORE_POINTER(D_0026C8E4, D_0025FC30_as_u16_a);
    STORE_POINTER(D_0026C8F2, D_0025FC70_as_u16_a);
    STORE_POINTER(D_0026C900, D_0025FCB0_as_u16_a);
    STORE_POINTER(D_0026C90E, D_0025FCF0_as_u16_a);
    STORE_POINTER(D_0026CBC8, D_0025FD30_as_u16_a);
    STORE_POINTER(D_0026CBD6, D_0025FD70_as_u16_a);
    STORE_POINTER(D_0026CBE4, D_0025FDB0_as_u16_a);
    STORE_POINTER(D_0026D8A8, D_002610F0);
    STORE_POINTER(D_0026D8B6, D_00247080);
    STORE_POINTER(D_0026D8C4, D_00247080);
    STORE_POINTER(D_0026D8D2, D_00247080);
    STORE_POINTER(D_0026D8E0, D_00247080);
    STORE_POINTER(D_0026D8EE, D_00247080);
    STORE_POINTER(D_0026D8FC, D_00247080);
    STORE_POINTER(D_0026D90A, D_00247080);
    STORE_POINTER(D_0026D918, D_00247080);
    STORE_POINTER(D_0026D926, D_00247080);
    STORE_POINTER(D_0026D934, D_00247080);
    STORE_POINTER(D_0026D942, D_00247080);
    STORE_POINTER(D_0026D950, D_00247080);
    STORE_POINTER(D_0026D95E, D_00247080);
    STORE_POINTER(D_0026D96C, D_00247080);
    STORE_POINTER(D_0026D97A, D_00247080);
    STORE_POINTER(D_0026D996, D_00261D30);
    STORE_POINTER(D_0026D9A2, D_00261D30);
    STORE_POINTER(D_0026D9AE, D_00261D30);
}

extern u16 D_00244930[];
extern u16 D_00249E90[];
extern u16 D_0025FA30_as_u16_a[];
extern u16 D_0025FA70_as_u16_a[];
extern u16 D_0025FE70_as_u16_a[];
extern u16 D_0025FEB0_as_u16_a[];
extern u16 D_0025FEF0_as_u16_a[];
extern u16 D_00261D70[];
extern u16 D_0026ED30[];
extern u16 D_0026ED40[];
extern u16 D_0026ED50[];
extern u16 D_0026ED60[];
extern u16 D_0026ED70[];
extern u16 D_0028DC70[];

extern u16 D_0026DF78[];
extern u16 D_0026DF86[];
extern u16 D_0026DF94[];
extern u16 D_0026DFA2[];
extern u16 D_0026DFB0[];
extern u16 D_0026DFC8[];
extern u16 D_0026DFD6[];
extern u16 D_0026E938[];
extern u16 D_0026E946[];
extern u16 D_0026E954[];
extern u16 D_0026E962[];
extern u16 D_0026E970[];
extern u16 D_0026ED10_as_u16_a[];
extern u16 D_0026ED12[];
extern u16 D_0026ED14[];
extern u16 D_0026ED18[];
extern u16 D_0026ED1C[];
extern u16 D_0026ED20[];
extern u16 D_0026ED24[];
extern u16 D_0026ED28[];
extern u16 D_0026ED2C[];
extern u16 D_0026F328[];
extern u16 D_0026F336[];
extern u16 D_0026F346[];
extern u16 D_0026F448[];
extern u16 D_0026F456[];
extern u16 D_0026F464[];
extern u16 D_0026F472[];
extern u16 D_0028DC68_as_u16_a[];
extern u16 D_0028DC6A[];
extern u16 D_0028DC6C[];

void func_002108C0(void) {
    STORE_POINTER(D_0026DF78, D_0025FA30_as_u16_a);
    STORE_POINTER(D_0026DF86, D_0025FA70_as_u16_a);
    STORE_POINTER(D_0026DF94, D_0025FA70_as_u16_a);
    STORE_POINTER(D_0026DFA2, D_0025FA70_as_u16_a);
    STORE_POINTER(D_0026DFB0, D_00244930);
    STORE_POINTER(D_0026DFC8, D_002610F0);
    STORE_POINTER(D_0026DFD6, D_00244930);
    STORE_POINTER(D_0026E938, D_0025FA30_as_u16_a);
    STORE_POINTER(D_0026E946, D_0025FA70_as_u16_a);
    STORE_POINTER(D_0026E954, D_0025FA70_as_u16_a);
    STORE_POINTER(D_0026E962, D_0025FA70_as_u16_a);
    STORE_POINTER(D_0026E970, D_00261D70);
    reg_tmp.w = (u32)D_0026ED30;
    D_0026ED10_as_u16_a[0] = reg_tmp.h[1];
    D_0026ED12[0] = reg_tmp.h[0];
    STORE_POINTER(D_0026ED14, D_0026ED40);
    STORE_POINTER(D_0026ED18, D_0026ED50);
    STORE_POINTER(D_0026ED1C, D_0026ED60);
    STORE_POINTER(D_0026ED20, D_0026ED30);
    STORE_POINTER(D_0026ED24, D_0026ED40);
    STORE_POINTER(D_0026ED28, D_0026ED50);
    STORE_POINTER(D_0026ED2C, D_0026ED60);
    reg_tmp.w = (u32)D_0026ED70;
    D_0028DC68_as_u16_a[0] = reg_tmp.h[1];
    D_0028DC6A[0] = reg_tmp.h[0];
    STORE_POINTER(D_0028DC6C, D_0028DC70);
    STORE_POINTER(D_0026F328, D_002610F0);
    STORE_POINTER(D_0026F336, D_00249E90);
    STORE_POINTER(D_0026F346, D_00261D30);
    STORE_POINTER(D_0026F448, D_0025FE70_as_u16_a);
    STORE_POINTER(D_0026F456, D_0025FEB0_as_u16_a);
    STORE_POINTER(D_0026F464, D_0025FEF0_as_u16_a);
    STORE_POINTER(D_0026F472, D_00261D70);
}

extern u8 D_002BAE90[];

#ifdef DEATH_LABEL
extern s8 D_0028E2A4_as_s8;
#endif

void func_00210C90(void) {
    s32 var_a1;
    u8 *temp_a2;

    var_a1 = 0;
    do {
        temp_a2 = D_002BAE90 + var_a1;
        (*(s8 *)((u8 *)(temp_a2) + (0))) = 0;
        var_a1 += 8;
        (*(s8 *)((u8 *)(temp_a2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (7))) = 0;
    } while (var_a1 < 0x20);
    *(s8 *)(reg_a5 + 3) = 1;
    ENTITY(reg_a6)->draw.sh = 0x60;
    ENTITY(reg_a6)->sprite.sh = 0x10;
#ifdef DEATH_LABEL
    D_0028E2A4_as_s8 = 0x78;
#endif
}

s32 func_001317E0();
s32 func_00133070();
s32 func_0013B920();
s32 func_0013C300();
s32 func_0013C350();
s32 func_0022B660();
s32 func_002376F0();
s32 func_00237790();
extern u8 D_00269920[];
extern u16 g_loop;
extern u16 g_stage;
extern u8 D_0028ED7C;
#ifdef DEATH_LABEL
s32 stage_load_step();
extern u8 D_0028E2A4;
extern u8 g_game_mode;
extern s16 g_loaded_stage;
extern u8 D_0028ED60;
extern u8 death_D_00290568;
#endif

void func_00210D00() {
    u16 temp_a0;
    u16 temp_v1;

    reg_a6 = D_002BAE90;
    func_00211420();
    if (*(u8 *)(reg_a5 + 3) == 0) {
        func_00210C90();
        return;
    }
#ifdef DEATH_LABEL
    if (D_0028E2A4 != 0) {
        D_0028E2A4 -= 1;
    }
    if ((D_0028E2A4 == 0) && (g_loaded_stage != g_stage) && (D_0028E2A4 == 0)) {
        stage_load_step();
    }
#endif
    temp_v1 = ENTITY(reg_a6)->draw.h;
    if (temp_v1 != 0) {
        ENTITY(reg_a6)->draw.h = (u16) (temp_v1 - 1);
        return;
    }
    func_00210EA0();
    func_00211140();
    if (ENTITY(reg_a6)->look.h == 0) {
        temp_a0 = ENTITY(reg_a6)->sprite.h;
        if (temp_a0 != 0) {
#ifdef DEATH_LABEL
            if (temp_a0 == 1) {
                if (g_loaded_stage != g_stage) {
                    return;
                }
                if ((g_game_mode == 2) && (D_0028ED60 == 0)) {
                    death_D_00290568 = 1;
                    *(s16 *)reg_a5 = 0;
                    return;
                }
            }
            {
#else
            if ((temp_a0 != 1) || (func_00133070() == 0) || (func_0022B660() != 0)) {
#endif
                ENTITY(reg_a6)->sprite.h -= 1;
                if (ENTITY(reg_a6)->sprite.h == 0) {
                    reg_a0 = D_00269920;
                    func_0013B920();
                    ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_d0.h[1];
                    ENTITY(reg_a6)->hit_x_plus.h = (u16) reg_d0.h[0];
                }
            }
        } else {
            reg_d0.h[1] = ENTITY(reg_a6)->hit_y_minus.h;
            reg_d0.h[0] = ENTITY(reg_a6)->hit_x_plus.h;
            func_0013C350();
            if (cond_flag == 0) {
                reg_d0.h[1] = ENTITY(reg_a6)->hit_y_minus.h;
                reg_d0.h[0] = ENTITY(reg_a6)->hit_x_plus.h;
                func_0013C300();
                if (D_0028ED7C == 2) {
                    if ((g_loop == 1) && (g_stage == 4)) {
                        func_002376F0();
                        return;
                    }
                    func_00237790();
                    return;
                }
                func_001317E0();
                *(s16 *)reg_a5 = 0;
            }
        }
    }
}

s32 func_0013EAF0();
s32 func_0018D950();
s32 func_0018D990();
s32 func_0018D9B0();
s32 func_001A9180();
s32 func_001AC3A0();
extern s32 g_p1_extend_score;
extern u16 g_p1_score_digits;
extern u16 g_p1_lives;
extern u16 D_0029CD90[];
extern s16 g_player1[];
extern u8 D_0029F261[];
extern u8 D_0029F285[];
#ifdef DEATH_LABEL
extern u16 D_00684C80[];
#endif

void func_00210EA0(void) {
    u8 *p;

    if (*(u8 *)(reg_a6 + 5) & 1) {
        goto block_3;
    }
    *(u8 *)(reg_a6 + 5) |= 1;
    if (g_player1[0] >= 0) {
        goto block_2;
    }
    g_p1_extend_score = -1;
    if (g_p1_score_digits != 0) {
        goto block_2;
    }
    *(u16 *)(reg_a6 + 0xE) += 1;
    if (g_loop == 0) {
        *(u16 *)(reg_a6 + 6) = 1;
        return;
    }
    *(u16 *)(reg_a6 + 6) = 2;
    return;
block_1:
    *(u16 *)(reg_a6 + 0xE) -= 1;
block_2:
    *(u8 *)(reg_a6 + 5) |= 0x80;
block_rts:
    return;
block_3:
    if (*(u8 *)(reg_a6 + 5) & 0x80) {
        goto block_rts;
    }
    if (*(u16 *)(reg_a6 + 6) == 1) {
        switch (g_p1_lives) {
        case 0:
            goto block_1;
        }
        reg_d0.w = 0x01000000;
        func_001A9180();
        g_p1_lives -= 1;
        func_001AC3A0();
        *(s16 *)(reg_a6 + 0xA) = 0x30;
        *(u8 *)(reg_a6 + 0x11) |= 1;
        func_0018D9B0();
        func_0018D990();
        func_0018D950();
    } else if (*(u16 *)(reg_a6 + 6) == 2) {
        if (g_p1_lives != 0) {
            reg_d0.w = MAIN_OR_DEATH_LABEL(0x05000000, 0x07000000);
            func_001A9180();
            g_p1_lives -= 1;
            func_001AC3A0();
            *(s16 *)(reg_a6 + 0xA) = 0x30;
            *(u8 *)(reg_a6 + 0x11) |= 1;
            func_0018D9B0();
            func_0018D990();
            func_0018D950();
        } else {
            *(u16 *)(reg_a6 + 6) = 3;
        }
    } else if (*(u16 *)(reg_a6 + 6) == 3) {
        if (!(D_0029F261[0] & 0x40) && D_0029CD90[0] != 0) {
            reg_d0.w = 0x10000000;
            func_001A9180();
            D_0029CD90[0] = 0;
            func_0013EAF0();
            *(s16 *)(reg_a6 + 0xA) = 0x30;
            *(u8 *)(reg_a6 + 0x11) |= 1;
            func_0018D9B0();
            func_0018D990();
            func_0018D950();
        } else {
            *(u16 *)(reg_a6 + 6) = 4;
        }
    } else {
        p = (u8 *)(u32)D_0029F285;
        if (*p == 0) {
            goto block_1;
        }
        reg_d0.w = 0x01000000;
#ifdef DEATH_LABEL
        if (D_00684C80[1] == 2) {
            *(s32 *)&reg_d0 = 0x01000000;
        } else if (D_00684C80[1] == 4) {
            reg_d0.w = 0x01500000;
        } else {
            reg_d0.w = 0x03000000;
        }
#endif
        func_001A9180();
        *p -= 1;
        func_0013EAF0();
        *(s16 *)(reg_a6 + 0xA) = 0x30;
        *(u8 *)(reg_a6 + 0x11) |= 1;
        func_0018D9B0();
        func_0018D990();
        func_0018D950();
    }
}

s32 func_0013EB60();
s32 func_001A9190();
s32 func_001AC5F0();
extern s32 g_p2_extend_score;
extern u16 g_p2_score_digits;
extern u16 g_p2_lives;
extern u16 D_0029CD80[];
extern s16 g_player2[];
extern u8 D_0029F1F1[];
extern u8 D_0029F215[];
#ifdef DEATH_LABEL
extern u16 D_00684C80[];
#endif

void func_00211140(void) {
    u8 *p;

    if (*(u8 *)(reg_a6 + 4) & 1) {
        goto block_3;
    }
    *(u8 *)(reg_a6 + 4) |= 1;
    if (g_player2[0] >= 0) {
        goto block_2;
    }
    g_p2_extend_score = -1;
    if (g_p2_score_digits != 0) {
        goto block_2;
    }
    *(u16 *)(reg_a6 + 0xE) += 1;
    if (g_loop == 0) {
        *(u16 *)(reg_a6 + 8) = 1;
        return;
    }
    *(u16 *)(reg_a6 + 8) = 2;
    return;
block_1:
    *(u16 *)(reg_a6 + 0xE) -= 1;
block_2:
    *(u8 *)(reg_a6 + 4) |= 0x80;
block_rts:
    return;
block_3:
    if (*(u8 *)(reg_a6 + 4) & 0x80) {
        goto block_rts;
    }
    if (*(u16 *)(reg_a6 + 8) == 1) {
        switch (g_p2_lives) {
        case 0:
            goto block_1;
        }
        reg_d0.w = 0x01000000;
        func_001A9190();
        g_p2_lives -= 1;
        func_001AC5F0();
        *(s16 *)(reg_a6 + 0xA) = 0x30;
        if (*(u16 *)(reg_a6 + 0x10) & 1) {
            *(u8 *)(reg_a6 + 0x11) &= 0xFE;
        } else {
            func_0018D9B0();
            func_0018D990();
            func_0018D950();
        }
        return;
    }
    if (*(u16 *)(reg_a6 + 8) == 2) {
        if (g_p2_lives != 0) {
            reg_d0.w = MAIN_OR_DEATH_LABEL(0x05000000, 0x07000000);
            func_001A9190();
            g_p2_lives -= 1;
            func_001AC5F0();
            if (*(u16 *)(reg_a6 + 0x10) & 1) {
                *(u8 *)(reg_a6 + 0x11) &= 0xFE;
            } else {
                *(s16 *)(reg_a6 + 0xA) = 0x30;
                func_0018D9B0();
                func_0018D990();
                func_0018D950();
            }
            return;
        }
        *(u16 *)(reg_a6 + 8) = 3;
        return;
    }
    if (*(u16 *)(reg_a6 + 8) == 3) {
        if (!(D_0029F1F1[0] & 0x40) && D_0029CD80[0] != 0) {
            reg_d0.w = 0x10000000;
            func_001A9190();
            D_0029CD80[0] = 0;
            func_0013EB60();
            if (*(u16 *)(reg_a6 + 0x10) & 1) {
                *(u8 *)(reg_a6 + 0x11) &= 0xFE;
            } else {
                *(s16 *)(reg_a6 + 0xA) = 0x30;
                func_0018D9B0();
                func_0018D990();
                func_0018D950();
            }
            return;
        }
        *(u16 *)(reg_a6 + 8) = 4;
        return;
    }
    p = (u8 *)(u32)D_0029F215;
    if (*p == 0) {
        goto block_1;
    }
    reg_d0.w = 0x01000000;
#ifdef DEATH_LABEL
    if (D_00684C80[3] == 2) {
        *(s32 *)&reg_d0 = 0x01000000;
    } else if (D_00684C80[3] == 4) {
        reg_d0.w = 0x01500000;
    } else {
        reg_d0.w = 0x03000000;
    }
#endif
    func_001A9190();
    *p -= 1;
    func_0013EB60();
    if (*(u16 *)(reg_a6 + 0x10) & 1) {
        *(u8 *)(reg_a6 + 0x11) &= 0xFE;
    } else {
        *(s16 *)(reg_a6 + 0xA) = 0x30;
        func_0018D9B0();
        func_0018D990();
        func_0018D950();
    }
}

void func_00211420(void) {
}

s32 entity_follow_scroll();
extern u16 g_side_scroll_step[];

void func_00211430(void) {
    entity_follow_scroll();
    reg_d1.h[0] = g_side_scroll_step[0];
    ENTITY(reg_a6)->x.h -= reg_d1.h[0];
}

extern u16 g_two_player_game;

void func_00211470(void) {
    reg_d3.sw = 0x1D;
    if (g_loop == 0) {
        if (g_two_player_game == 0) {
            goto block_3;
        }
    } else {
block_3:
        reg_d3.sw = 0xE;
    }
}

extern s32 D_00299780_as_s32_a[];


void func_002114A0(void) {
    memset(D_00299780_as_s32_a, 0, 0x5A6);
}


void wreck_spawn(void) {
    u32 tmp;

    func_00211470();
    reg_a0 = (u8 *) D_00299780;
loop_1:
    if (*(u16 *) reg_a0 != 0) goto next_1;
    func_00211920();
    cond_flag = 0;
    return;
next_1:
    reg_a0 += 0x30;
    tmp = reg_d3.h[0] - 1;
    reg_d3.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d3.w = 0;
    cond_flag = 1;
    reg_d3.h[0] -= 1;
}


void func_00211550(void) {
    u32 tmp;

    func_00211470();
    reg_a0 = (u8 *) D_00299780;
loop_1:
    if (*(u16 *) reg_a0 != 0) goto next_1;
    func_00211E90();
    cond_flag = 0;
    return;
next_1:
    reg_a0 += 0x30;
    tmp = reg_d3.h[0] - 1;
    reg_d3.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d3.w = 0;
    cond_flag = 1;
    reg_d3.h[0] -= 1;
}


void func_002115E0(void) {
    u32 tmp;

    func_00211470();
    reg_a0 = (u8 *) D_00299780;
loop_1:
    if (*(u16 *) reg_a0 != 0) goto next_1;
    func_00211F40();
    cond_flag = 0;
    return;
next_1:
    reg_a0 += 0x30;
    tmp = reg_d3.h[0] - 1;
    reg_d3.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d3.w = 0;
    cond_flag = 1;
    reg_d3.h[0] -= 1;
}

extern u8 D_002515A0[];
extern u16 D_0028E3E0;
extern u16 D_0028E3EC;
extern u16 D_00299D20[];

void func_00211670(void) {
    u32 temp_a0;

    reg_d7.h[0] = D_00299D20[0];
    if (reg_d7.h[0] != 0) {
        reg_d5.w = 0;
        reg_d7.h[0] -= 1;
        reg_d4.h[0] = 0xFFC0;
        reg_d2.h[0] = 0x3FF;
        reg_d6.h[0] = D_0028E3EC;
        reg_a4 = D_002515A0;
        reg_tmp.h[0] = reg_d6.h[0];
        reg_d6.h[0] <<= 0xF;
        temp_a0 = reg_d6.h[0];
        reg_tmp.h[0] >>= 1;
        reg_d6.h[0] = temp_a0 | reg_tmp.h[0];
        reg_tmp.w = reg_d6.w;
        reg_d6.h[0] = D_0028E3E0;
        reg_d6.h[1] = reg_tmp.h[0];
        func_00211720();
    }
}

typedef void (*Fn)(void);

extern u8 D_00299780_as_u8_a[];
extern u8 *reg_call_target_as_u8_p;

void func_00211720(void) {
    u32 t1;

    reg_a6 = (u8 *)D_00299780_as_u8_a;
    goto loop_1;
skip_1:
    reg_a6 += 0x30;
loop_1:
    if (!(0 > (s64)ENTITY(reg_a6)->flags.sh)) {
        goto skip_1;
    }
    if (0 > (s64)(s32)reg_d6.w) {
        goto block_1;
    }
    reg_tmp.h[1] = ENTITY(reg_a6)->hit_x_plus.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->hit_x_minus.h;
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = ENTITY(reg_a6)->hit_y_plus.h;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->hit_y_plus.h -= 4;
    if (0 > (s64)ENTITY(reg_a6)->hit_y_plus.sh) {
        ENTITY(reg_a6)->hit_y_plus.h = ENTITY(reg_a6)->hit_y_minus.h;
    }
block_1:
    func_00211430();
    if (reg_d6.h[0] != 0) {
        goto block_2;
    }
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x20);
    if (ENTITY(reg_a6)->y.sh < reg_d0.sh[0]) {
        goto block_3;
    }
block_2:
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->misc.b.user;
    reg_a0 = *(u8 **)(reg_a4 + reg_d0.h[0]);
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
    reg_a6 += 0x30;
    t1 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t1;
    if (((s64)((s64)(t1 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
    return;
block_3:
    ENTITY(reg_a6)->flags.sh = 0;
    D_00299D20[0] -= 1;
    reg_a6 += 0x30;
    t1 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t1;
    if (((s64)((s64)(t1 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
}

extern u8 D_00251700[];
extern u32 D_0028E9A0;

void func_00211920(void) {
    D_0028E9A0 = reg_d0.w;
    reg_d3.h[0] = reg_d0.h[0];
    reg_d3.h[0] &= 0x3C;
    reg_a2 = (u8 *)(*(u16 **)(D_00251700 + (reg_d3.h[0] & ~3)));
    *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
    reg_a2 += 2;
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    func_002119A0();
}

s32 rng_next_bit();
s32 func_00201230();
s32 func_00201270();
s32 func_00202B50();
extern u8 D_0028E855;
extern u16 D_00299D22[];
extern u16 D_00299D24[];

#define W0(o) (*(u16 *)(reg_a0 + (o)))
#define W6(o) (*(u16 *)(reg_a6 + (o)))
#define NEXT_W() (*(u16 *)reg_a2)

void func_002119A0(void) {
    u32 save_d0;
    u8 *save_a6;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

    if (g_stage != 4) goto next_1;
    if (D_0028E855 & 0x40) goto block_set;
next_1:
    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a6 = reg_a6;
    reg_d5.h[0] = W0(2);
    reg_d7.h[0] = W0(4);
    W0(2) += 0x4400;
    func_00211470();
    reg_d6.h[0] = reg_d3.h[0];
    D_00299D22[0] = 2;
    D_00299D24[0] = 0xA;
    reg_a6 = (u8 *)D_00299780_as_u8_a;
loop_2:
    if (W6(0) == 0) goto next_6;
    if (W6(4) != reg_d7.h[0]) goto next_3;
    if (D_00299D22[0] == 0) goto block_kill;
    D_00299D22[0] -= 1;
next_3:
    if (g_loop == 0) goto next_4;
    reg_d0.h[0] = W6(0);
    reg_d0.h[0] &= 0x3C;
    reg_d0.h[0] -= 4;
    if (reg_d0.h[0] != 0) goto next_4;
    reg_tmp.h[0] = D_00299D24[0];
    D_00299D24[0] -= 1;
    if (reg_tmp.h[0] == 0) goto block_kill;
    reg_d3.h[0] = reg_d7.h[0];
    reg_d2.h[0] = reg_d5.h[0];
    func_00202B50();
    if (reg_d0.h[0] >= 0xA00) goto next_6;
    goto block_kill;
next_4:
    reg_d3.h[0] = reg_d7.h[0];
    reg_d2.h[0] = reg_d5.h[0];
    func_00202B50();
    if (reg_d0.h[0] >= 0x800) goto next_6;
block_kill:
    W0(0) = 0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a6 = save_a6;
    reg_d0.w = D_0028E9A0;
    return;
next_6:
    reg_a6 += 0x30;
    if ((s16)(--reg_d6.h[0]) >= 0) goto loop_2;
    W0(2) = reg_d5.h[0];
    W0(4) = reg_d7.h[0];
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a6 = save_a6;
block_set:
    W0(6) = NEXT_W();
    reg_a2 += 2;
    W0(8) = NEXT_W();
    reg_a2 += 2;
    reg_d3.w = 0;
    rng_next_bit();
    if (reg_d0.b[0] != 0) goto next_7;
    reg_d3.b[0] |= 0x20;
next_7:
    reg_a0[0x1D] = reg_d3.b[0];
    W0(0xE) = NEXT_W();
    reg_a2 += 2;
    W0(0x18) = NEXT_W();
    reg_a2 += 2;
    reg_a0[0x1C] = 0x1E;
    func_00201230();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    W0(0x10) = reg_d0.h[0];
    W0(0x12) = NEXT_W();
    reg_a2 += 2;
    reg_a0[0x1F] = reg_d1.b[0];
    W0(0x20) = NEXT_W();
    reg_a2 += 2;
    reg_tmp.h[0] = NEXT_W();
    reg_a2 += 2;
    if (0 > (s16) reg_tmp.h[0]) {
        rng_next_bit();
    } else if (!reg_tmp.h[0]) {
        func_00201230();
    } else {
        func_00201270();
    }
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a2 += reg_d0.h[0];
    W0(0x14) = *(u16 *)(reg_a2 + 0);
    W0(0x16) = *(u16 *)(reg_a2 + 2);
    reg_tmp.h[1] = W0(0x14);
    reg_tmp.h[0] = W0(0x16);
    reg_a2 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W0(0x10);
    W0(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a2 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    W0(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a2 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_d0.w = 0;
    reg_a0[0x1E] = reg_d0.b[0];
    cond_flag = 0;
    reg_d0.w = D_0028E9A0;
    D_00299D20[0] += 1;
}

void func_00211E90(void) {
    D_0028E9A0 = reg_d0.w;
    *(s8 *)(reg_a0 + 0x1E) = 0x1F;
    reg_d3.h[0] = reg_d0.h[0];
    reg_d3.h[0] &= 0x3C;
    reg_a2 = *(u8 **)(D_00251700 + (reg_d3.h[0] & ~3));
    *(u16 *)reg_a0 = (u16) *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_d3.h[1] = ENTITY(reg_a6)->y.h;
    reg_d3.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w += reg_d2.w;
    *(u16 *)(reg_a0 + 2) = (u16) reg_d3.h[1];
    *(u16 *)(reg_a0 + 4) = (u16) reg_d3.h[0];
    func_002119A0();
}

void func_00211F40(void) {
    D_0028E9A0 = reg_d0.w;
    *(s8 *)(reg_a0 + 0x1E) = 0x1F;
    reg_d3.h[0] = reg_d0.h[0];
    reg_d3.h[0] &= 0x3C;
    reg_a2 = (u8 *)(*(u16 **)(D_00251700 + (reg_d3.h[0] & ~3)));
    *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
    reg_a2 += 2;
    *(u16 *)(reg_a0 + 2) = reg_d2.h[1];
    *(u16 *)(reg_a0 + 4) = reg_d2.h[0];
    func_002119A0();
}
