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
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];
extern u16 D_002A2400_as_u16_a[];
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
extern void func_0016A8B0(void);
extern void func_0016A8C0(void);
extern void func_0016A8D0(void);
extern void func_0016A8E0(void);

extern u16 D_002693C8[];
extern u16 D_002693CA[];
extern u16 D_002693D6[];
extern u16 D_002693D8[];
extern u16 D_00269718[];
extern u16 D_0026971A[];
extern u16 D_00269728[];
extern u16 D_0026972A[];
extern u16 D_00269738[];
extern u16 D_0026973A[];
extern u16 D_00269808[];
extern u16 D_0026980A[];
extern u16 D_00269816[];
extern u16 D_00269818[];
extern u16 D_00269848[];
extern u16 D_0026984A[];
extern u16 D_00269856[];
extern u16 D_00269858[];
extern u16 D_00269864[];
extern u16 D_00269866[];
extern u16 D_00269872[];
extern u16 D_00269874[];
extern u16 D_00269880[];
extern u16 D_00269882[];
extern u16 D_0026988E[];
extern u16 D_00269890[];
extern u16 D_0026989C[];
extern u16 D_0026989E[];
extern u16 D_002698B6[];
extern u16 D_002698B8[];
extern u16 D_002698C2[];
extern u16 D_002698C4[];
extern u16 D_002698CE[];
extern u16 D_002698D0[];
extern u16 D_002698DA[];
extern u16 D_002698DC[];
extern u16 D_002698E6[];
extern u16 D_002698E8[];
extern u16 D_002698F2[];
extern u16 D_002698F4[];
extern u16 D_002698FE[];
extern u16 D_00269900[];
extern u16 D_0026990A[];
extern u16 D_0026990C[];
extern u16 D_00269926[];
extern u16 D_00269928[];
extern u16 D_00269932[];
extern u16 D_00269934[];
extern u16 D_0026993E[];
extern u16 D_00269940[];
extern u16 D_0026994A[];
extern u16 D_0026994C[];
extern u16 D_00269956[];
extern u16 D_00269958[];
extern u16 D_00269962[];
extern u16 D_00269964[];
extern u16 D_0026996E[];
extern u16 D_00269970[];
extern u16 D_0026997A[];
extern u16 D_0026997C[];
extern u16 D_00269986[];
extern u16 D_00269988[];
extern u16 D_00269992[];
extern u16 D_00269994[];
extern u16 D_0026999E[];
extern u16 D_002699A0[];
extern u16 D_002699AA[];
extern u16 D_002699AC[];
extern u16 D_002699B6[];
extern u16 D_002699B8[];
extern u16 D_002699C2[];
extern u16 D_002699C4[];
extern u16 D_002699CE[];
extern u16 D_002699D0[];
extern u16 D_002699DA[];
extern u16 D_002699DC[];
extern u16 D_002699E6[];
extern u16 D_002699E8[];
extern u16 D_002699F2[];
extern u16 D_002699F4[];
extern u16 D_002699FE[];
extern u16 D_00269A00[];
extern u16 D_00269CD4[];
extern u16 D_00269CD6[];
extern u16 D_00269CD8[];
extern u16 D_00269CDA[];
extern u16 D_00269CDC[];
extern u16 D_00269CDE[];
extern u16 D_00269CE0[];
extern u16 D_00269CE2[];
extern u16 D_00269CF4[];
extern u16 D_00269CF6[];
extern u16 D_00269CF8[];
extern u16 D_00269CFA[];
extern u16 D_00269CFC[];
extern u16 D_00269CFE[];
extern u16 D_00269D00[];
extern u16 D_00269D02[];
extern u16 D_00269D1C[];
extern u16 D_00269D1E[];
extern u16 D_00269D2C[];
extern u16 D_00269D2E[];
extern u16 D_00269E26[];
extern u16 D_00269E28[];
extern u16 D_00269E46[];
extern u16 D_00269E48[];
extern u16 D_00269E66[];
extern u16 D_00269E68[];
extern u16 D_00269E86[];
extern u16 D_00269E88[];
extern u16 D_00269EA6[];
extern u16 D_00269EA8[];
extern u16 D_00269EC6[];
extern u16 D_00269EC8[];
extern u16 D_00269EE6[];
extern u16 D_00269EE8[];
extern u16 D_00269F06[];
extern u16 D_00269F08[];
extern u16 D_00269F26[];
extern u16 D_00269F28[];
extern u16 D_00269F46[];
extern u16 D_00269F48[];
extern u16 D_00269F66[];
extern u16 D_00269F68[];
extern u16 D_00269F86[];
extern u16 D_00269F88[];
extern u16 D_00269FA6[];
extern u16 D_00269FA8[];
extern u16 D_00269FC6[];
extern u16 D_00269FC8[];
extern u16 D_00269FE6[];
extern u16 D_00269FE8[];
extern u16 D_0026A006[];
extern u16 D_0026A008[];
extern u16 D_0026A026[];
extern u16 D_0026A028[];
extern u16 D_0026A046[];
extern u16 D_0026A048[];
extern u16 D_0026A066[];
extern u16 D_0026A068[];
extern u16 D_0026A086[];
extern u16 D_0026A088[];
extern u16 D_0026A0A6[];
extern u16 D_0026A0A8[];
extern u16 D_0026A0C6[];
extern u16 D_0026A0C8[];
extern u16 D_0026A0E6[];
extern u16 D_0026A0E8[];
extern u16 D_0026A106[];
extern u16 D_0026A108[];
extern u16 D_0026A126[];
extern u16 D_0026A128[];
extern u16 D_0026A146[];
extern u16 D_0026A148[];
extern u16 D_0026A166[];
extern u16 D_0026A168[];
extern u16 D_0026A186[];
extern u16 D_0026A188[];
extern u16 D_0026A1A6[];
extern u16 D_0026A1A8[];
extern u16 D_0026A1C6[];
extern u16 D_0026A1C8[];
extern u16 D_0026A1E6[];
extern u16 D_0026A1E8[];
extern u16 D_0026A206[];
extern u16 D_0026A208[];
extern u16 D_0026A226[];
extern u16 D_0026A228[];
extern u16 D_0026A246[];
extern u16 D_0026A248[];
extern u16 D_0026A268[];
extern u16 D_0026A26A[];
extern u16 D_0026A278[];
extern u16 D_0026A27A[];
extern u16 D_0026A288[];
extern u16 D_0026A28A[];
extern u16 D_0026A3F8[];
extern u16 D_0026A3FA[];
extern u16 D_0026A628[];
extern u16 D_0026A62A[];
extern u16 D_0026A636[];
extern u16 D_0026A638[];
extern u16 D_0026A644[];
extern u16 D_0026A646[];
extern u16 D_0026A652[];
extern u16 D_0026A654[];
extern u16 D_0026B588[];
extern u16 D_0026B58A[];
extern u16 D_0026B596[];
extern u16 D_0026B598[];
extern u16 D_0026B5A4[];
extern u16 D_0026B5A6[];
extern u16 D_0026B5B2[];
extern u16 D_0026B5B4[];
extern u16 D_0026B5C0[];
extern u16 D_0026B5C2[];
extern u16 D_0026B5CE[];
extern u16 D_0026B5D0[];
extern u16 D_0026B5DC[];
extern u16 D_0026B5DE[];
extern u16 D_0026C798[];
extern u16 D_0026C79A[];
extern u16 D_0026C7A6[];
extern u16 D_0026C7A8[];
extern u16 D_0026C7B6[];
extern u16 D_0026C7B8[];
extern u16 D_0026C7C2[];
extern u16 D_0026C7C4[];
extern u16 D_0026C7CE[];
extern u16 D_0026C7D0[];
extern u16 D_0026C7DA[];
extern u16 D_0026C7DC[];
extern u16 D_0026C7E6[];
extern u16 D_0026C7E8[];
extern u16 D_0026C7F2[];
extern u16 D_0026C7F4[];
extern u16 D_0026C8C8[];
extern u16 D_0026C8CA[];
extern u16 D_0026C8D6[];
extern u16 D_0026C8D8[];
extern u16 D_0026C8E4[];
extern u16 D_0026C8E6[];
extern u16 D_0026C8F2[];
extern u16 D_0026C8F4[];
extern u16 D_0026C900[];
extern u16 D_0026C902[];
extern u16 D_0026C90E[];
extern u16 D_0026C910[];
extern u16 D_0026CBC8[];
extern u16 D_0026CBCA[];
extern u16 D_0026CBD6[];
extern u16 D_0026CBD8[];
extern u16 D_0026CBE4[];
extern u16 D_0026CBE6[];
extern u16 D_0026D8A8[];
extern u16 D_0026D8AA[];
extern u16 D_0026D8B6[];
extern u16 D_0026D8B8[];
extern u16 D_0026D8C4[];
extern u16 D_0026D8C6[];
extern u16 D_0026D8D2[];
extern u16 D_0026D8D4[];
extern u16 D_0026D8E0[];
extern u16 D_0026D8E2[];
extern u16 D_0026D8EE[];
extern u16 D_0026D8F0[];
extern u16 D_0026D8FC[];
extern u16 D_0026D8FE[];
extern u16 D_0026D90A[];
extern u16 D_0026D90C[];
extern u16 D_0026D918[];
extern u16 D_0026D91A[];
extern u16 D_0026D926[];
extern u16 D_0026D928[];
extern u16 D_0026D934[];
extern u16 D_0026D936[];
extern u16 D_0026D942[];
extern u16 D_0026D944[];
extern u16 D_0026D950[];
extern u16 D_0026D952[];
extern u16 D_0026D95E[];
extern u16 D_0026D960[];
extern u16 D_0026D96C[];
extern u16 D_0026D96E[];
extern u16 D_0026D97A[];
extern u16 D_0026D97C[];
extern u16 D_0026D996[];
extern u16 D_0026D998[];
extern u16 D_0026D9A2[];
extern u16 D_0026D9A4[];
extern u16 D_0026D9AE[];
extern u16 D_0026D9B0[];

void func_0020F550(void) {
    reg_tmp.w = (u32)D_002624B0;
    D_002693C8[0] = reg_tmp.h[1];
    D_002693CA[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002554B0_as_u16_a;
    D_002693D6[0] = reg_tmp.h[1];
    D_002693D8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00269750;
    D_00269718[0] = reg_tmp.h[1];
    D_0026971A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00269780;
    D_00269728[0] = reg_tmp.h[1];
    D_0026972A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002697B0;
    D_00269738[0] = reg_tmp.h[1];
    D_0026973A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00262470;
    D_00269808[0] = reg_tmp.h[1];
    D_0026980A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002554B0_as_u16_a;
    D_00269816[0] = reg_tmp.h[1];
    D_00269818[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261F30;
    D_00269848[0] = reg_tmp.h[1];
    D_0026984A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261FF0;
    D_00269856[0] = reg_tmp.h[1];
    D_00269858[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00262030;
    D_00269864[0] = reg_tmp.h[1];
    D_00269866[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00262070;
    D_00269872[0] = reg_tmp.h[1];
    D_00269874[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002620B0;
    D_00269880[0] = reg_tmp.h[1];
    D_00269882[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002622B0;
    D_0026988E[0] = reg_tmp.h[1];
    D_00269890[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00260FF0;
    D_0026989C[0] = reg_tmp.h[1];
    D_0026989E[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002554B0_as_u16_a;
    D_002698B6[0] = reg_tmp.h[1];
    D_002698B8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002554B0_as_u16_a;
    D_002698C2[0] = reg_tmp.h[1];
    D_002698C4[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002554B0_as_u16_a;
    D_002698CE[0] = reg_tmp.h[1];
    D_002698D0[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002554B0_as_u16_a;
    D_002698DA[0] = reg_tmp.h[1];
    D_002698DC[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002554B0_as_u16_a;
    D_002698E6[0] = reg_tmp.h[1];
    D_002698E8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002554B0_as_u16_a;
    D_002698F2[0] = reg_tmp.h[1];
    D_002698F4[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002554B0_as_u16_a;
    D_002698FE[0] = reg_tmp.h[1];
    D_00269900[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002554B0_as_u16_a;
    D_0026990A[0] = reg_tmp.h[1];
    D_0026990C[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_00269926[0] = reg_tmp.h[1];
    D_00269928[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_00269932[0] = reg_tmp.h[1];
    D_00269934[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_0026993E[0] = reg_tmp.h[1];
    D_00269940[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_0026994A[0] = reg_tmp.h[1];
    D_0026994C[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_00269956[0] = reg_tmp.h[1];
    D_00269958[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_00269962[0] = reg_tmp.h[1];
    D_00269964[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_0026996E[0] = reg_tmp.h[1];
    D_00269970[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_0026997A[0] = reg_tmp.h[1];
    D_0026997C[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_00269986[0] = reg_tmp.h[1];
    D_00269988[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_00269992[0] = reg_tmp.h[1];
    D_00269994[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_0026999E[0] = reg_tmp.h[1];
    D_002699A0[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_002699AA[0] = reg_tmp.h[1];
    D_002699AC[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_002699B6[0] = reg_tmp.h[1];
    D_002699B8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_002699C2[0] = reg_tmp.h[1];
    D_002699C4[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_002699CE[0] = reg_tmp.h[1];
    D_002699D0[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_002699DA[0] = reg_tmp.h[1];
    D_002699DC[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_002699E6[0] = reg_tmp.h[1];
    D_002699E8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_002699F2[0] = reg_tmp.h[1];
    D_002699F4[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00255470;
    D_002699FE[0] = reg_tmp.h[1];
    D_00269A00[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)func_00130250;
    D_00269CD4[0] = reg_tmp.h[1];
    D_00269CD6[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)func_0016A8B0;
    D_00269CD8[0] = reg_tmp.h[1];
    D_00269CDA[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)func_0016A8D0;
    D_00269CDC[0] = reg_tmp.h[1];
    D_00269CDE[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002BF3EA_as_u16_a;
    D_00269CE0[0] = reg_tmp.h[1];
    D_00269CE2[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)func_00130260;
    D_00269CF4[0] = reg_tmp.h[1];
    D_00269CF6[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)func_0016A8C0;
    D_00269CF8[0] = reg_tmp.h[1];
    D_00269CFA[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)func_0016A8E0;
    D_00269CFC[0] = reg_tmp.h[1];
    D_00269CFE[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002BF400;
    D_00269D00[0] = reg_tmp.h[1];
    D_00269D02[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)&g_p1_lives_as_u32;
    D_00269D1C[0] = reg_tmp.h[1];
    D_00269D1E[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)&g_p2_lives_as_u32;
    D_00269D2C[0] = reg_tmp.h[1];
    D_00269D2E[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0029CEA0;
    D_00269E26[0] = reg_tmp.h[1];
    D_00269E28[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0029F260_as_u16_a;
    D_00269E46[0] = reg_tmp.h[1];
    D_00269E48[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0029F1F0_as_u16_a;
    D_00269E66[0] = reg_tmp.h[1];
    D_00269E68[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0029F180_as_u16_a;
    D_00269E86[0] = reg_tmp.h[1];
    D_00269E88[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0029F110_as_u16_a;
    D_00269EA6[0] = reg_tmp.h[1];
    D_00269EA8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0029E390_as_u16_a;
    D_00269EC6[0] = reg_tmp.h[1];
    D_00269EC8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0029EA50_as_u16_a;
    D_00269EE6[0] = reg_tmp.h[1];
    D_00269EE8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0029DD90_as_u16_a;
    D_00269F06[0] = reg_tmp.h[1];
    D_00269F08[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0029D790_as_u16_a;
    D_00269F26[0] = reg_tmp.h[1];
    D_00269F28[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0029D770_as_u16_a;
    D_00269F46[0] = reg_tmp.h[1];
    D_00269F48[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0029D750_as_u16_a;
    D_00269F66[0] = reg_tmp.h[1];
    D_00269F68[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0029D730_as_u16_a;
    D_00269F86[0] = reg_tmp.h[1];
    D_00269F88[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0029D710_as_u16_a;
    D_00269FA6[0] = reg_tmp.h[1];
    D_00269FA8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0028E080_as_u16_a;
    D_00269FC6[0] = reg_tmp.h[1];
    D_00269FC8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0028E078_as_u16_a;
    D_00269FE6[0] = reg_tmp.h[1];
    D_00269FE8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002BC7C0_as_u16_a;
    D_0026A006[0] = reg_tmp.h[1];
    D_0026A008[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002BD440;
    D_0026A026[0] = reg_tmp.h[1];
    D_0026A028[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002BB4B0_as_u16_a;
    D_0026A046[0] = reg_tmp.h[1];
    D_0026A048[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)&D_0028DFD8_as_u32;
    D_0026A066[0] = reg_tmp.h[1];
    D_0026A068[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)&D_0028DFD4_as_u32;
    D_0026A086[0] = reg_tmp.h[1];
    D_0026A088[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002BF4F0_as_u16_a;
    D_0026A0A6[0] = reg_tmp.h[1];
    D_0026A0A8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00299D30_as_u16_a;
    D_0026A0C6[0] = reg_tmp.h[1];
    D_0026A0C8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0029A12C_as_u16_a;
    D_0026A0E6[0] = reg_tmp.h[1];
    D_0026A0E8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002A2400_as_u16_a;
    D_0026A106[0] = reg_tmp.h[1];
    D_0026A108[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002BAF50;
    D_0026A126[0] = reg_tmp.h[1];
    D_0026A128[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002BAFAA;
    D_0026A146[0] = reg_tmp.h[1];
    D_0026A148[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002BAF30;
    D_0026A166[0] = reg_tmp.h[1];
    D_0026A168[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002BAF3A;
    D_0026A186[0] = reg_tmp.h[1];
    D_0026A188[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002962E0_as_u16_a;
    D_0026A1A6[0] = reg_tmp.h[1];
    D_0026A1A8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002BB470_as_u16_a;
    D_0026A1C6[0] = reg_tmp.h[1];
    D_0026A1C8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0029A530;
    D_0026A1E6[0] = reg_tmp.h[1];
    D_0026A1E8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00299764;
    D_0026A206[0] = reg_tmp.h[1];
    D_0026A208[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0029AA40_as_u16_a;
    D_0026A226[0] = reg_tmp.h[1];
    D_0026A228[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00299780;
    D_0026A246[0] = reg_tmp.h[1];
    D_0026A248[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00274040;
    D_0026A268[0] = reg_tmp.h[1];
    D_0026A26A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00274840;
    D_0026A278[0] = reg_tmp.h[1];
    D_0026A27A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00275040;
    D_0026A288[0] = reg_tmp.h[1];
    D_0026A28A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261DF0;
    D_0026A3F8[0] = reg_tmp.h[1];
    D_0026A3FA[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00262430_as_u16_a;
    D_0026A628[0] = reg_tmp.h[1];
    D_0026A62A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002623F0_as_u16_a;
    D_0026A636[0] = reg_tmp.h[1];
    D_0026A638[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025F770_as_u16_a;
    D_0026A644[0] = reg_tmp.h[1];
    D_0026A646[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002687B0_as_u16_a;
    D_0026A652[0] = reg_tmp.h[1];
    D_0026A654[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00262230;
    D_0026B588[0] = reg_tmp.h[1];
    D_0026B58A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00262270;
    D_0026B596[0] = reg_tmp.h[1];
    D_0026B598[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002622F0;
    D_0026B5A4[0] = reg_tmp.h[1];
    D_0026B5A6[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00262330;
    D_0026B5B2[0] = reg_tmp.h[1];
    D_0026B5B4[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00262370;
    D_0026B5C0[0] = reg_tmp.h[1];
    D_0026B5C2[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261F30;
    D_0026B5CE[0] = reg_tmp.h[1];
    D_0026B5D0[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002622B0;
    D_0026B5DC[0] = reg_tmp.h[1];
    D_0026B5DE[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002610F0;
    D_0026C798[0] = reg_tmp.h[1];
    D_0026C79A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00246C50;
    D_0026C7A6[0] = reg_tmp.h[1];
    D_0026C7A8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261D30;
    D_0026C7B6[0] = reg_tmp.h[1];
    D_0026C7B8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261D30;
    D_0026C7C2[0] = reg_tmp.h[1];
    D_0026C7C4[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261D30;
    D_0026C7CE[0] = reg_tmp.h[1];
    D_0026C7D0[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261D30;
    D_0026C7DA[0] = reg_tmp.h[1];
    D_0026C7DC[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261D30;
    D_0026C7E6[0] = reg_tmp.h[1];
    D_0026C7E8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261D30;
    D_0026C7F2[0] = reg_tmp.h[1];
    D_0026C7F4[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FBB0_as_u16_a;
    D_0026C8C8[0] = reg_tmp.h[1];
    D_0026C8CA[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FBF0_as_u16_a;
    D_0026C8D6[0] = reg_tmp.h[1];
    D_0026C8D8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FC30_as_u16_a;
    D_0026C8E4[0] = reg_tmp.h[1];
    D_0026C8E6[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FC70_as_u16_a;
    D_0026C8F2[0] = reg_tmp.h[1];
    D_0026C8F4[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FCB0_as_u16_a;
    D_0026C900[0] = reg_tmp.h[1];
    D_0026C902[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FCF0_as_u16_a;
    D_0026C90E[0] = reg_tmp.h[1];
    D_0026C910[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FD30_as_u16_a;
    D_0026CBC8[0] = reg_tmp.h[1];
    D_0026CBCA[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FD70_as_u16_a;
    D_0026CBD6[0] = reg_tmp.h[1];
    D_0026CBD8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FDB0_as_u16_a;
    D_0026CBE4[0] = reg_tmp.h[1];
    D_0026CBE6[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002610F0;
    D_0026D8A8[0] = reg_tmp.h[1];
    D_0026D8AA[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00247080;
    D_0026D8B6[0] = reg_tmp.h[1];
    D_0026D8B8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00247080;
    D_0026D8C4[0] = reg_tmp.h[1];
    D_0026D8C6[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00247080;
    D_0026D8D2[0] = reg_tmp.h[1];
    D_0026D8D4[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00247080;
    D_0026D8E0[0] = reg_tmp.h[1];
    D_0026D8E2[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00247080;
    D_0026D8EE[0] = reg_tmp.h[1];
    D_0026D8F0[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00247080;
    D_0026D8FC[0] = reg_tmp.h[1];
    D_0026D8FE[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00247080;
    D_0026D90A[0] = reg_tmp.h[1];
    D_0026D90C[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00247080;
    D_0026D918[0] = reg_tmp.h[1];
    D_0026D91A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00247080;
    D_0026D926[0] = reg_tmp.h[1];
    D_0026D928[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00247080;
    D_0026D934[0] = reg_tmp.h[1];
    D_0026D936[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00247080;
    D_0026D942[0] = reg_tmp.h[1];
    D_0026D944[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00247080;
    D_0026D950[0] = reg_tmp.h[1];
    D_0026D952[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00247080;
    D_0026D95E[0] = reg_tmp.h[1];
    D_0026D960[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00247080;
    D_0026D96C[0] = reg_tmp.h[1];
    D_0026D96E[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00247080;
    D_0026D97A[0] = reg_tmp.h[1];
    D_0026D97C[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261D30;
    D_0026D996[0] = reg_tmp.h[1];
    D_0026D998[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261D30;
    D_0026D9A2[0] = reg_tmp.h[1];
    D_0026D9A4[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261D30;
    D_0026D9AE[0] = reg_tmp.h[1];
    D_0026D9B0[0] = reg_tmp.h[0];
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
extern u16 D_0026DF7A[];
extern u16 D_0026DF86[];
extern u16 D_0026DF88[];
extern u16 D_0026DF94[];
extern u16 D_0026DF96[];
extern u16 D_0026DFA2[];
extern u16 D_0026DFA4[];
extern u16 D_0026DFB0[];
extern u16 D_0026DFB2[];
extern u16 D_0026DFC8[];
extern u16 D_0026DFCA[];
extern u16 D_0026DFD6[];
extern u16 D_0026DFD8[];
extern u16 D_0026E938[];
extern u16 D_0026E93A[];
extern u16 D_0026E946[];
extern u16 D_0026E948[];
extern u16 D_0026E954[];
extern u16 D_0026E956[];
extern u16 D_0026E962[];
extern u16 D_0026E964[];
extern u16 D_0026E970[];
extern u16 D_0026E972[];
extern u16 D_0026ED10_as_u16_a[];
extern u16 D_0026ED12[];
extern u16 D_0026ED14[];
extern u16 D_0026ED16[];
extern u16 D_0026ED18[];
extern u16 D_0026ED1A[];
extern u16 D_0026ED1C[];
extern u16 D_0026ED1E[];
extern u16 D_0026ED20[];
extern u16 D_0026ED22[];
extern u16 D_0026ED24[];
extern u16 D_0026ED26[];
extern u16 D_0026ED28[];
extern u16 D_0026ED2A[];
extern u16 D_0026ED2C[];
extern u16 D_0026ED2E[];
extern u16 D_0026F328[];
extern u16 D_0026F32A[];
extern u16 D_0026F336[];
extern u16 D_0026F338[];
extern u16 D_0026F346[];
extern u16 D_0026F348[];
extern u16 D_0026F448[];
extern u16 D_0026F44A[];
extern u16 D_0026F456[];
extern u16 D_0026F458[];
extern u16 D_0026F464[];
extern u16 D_0026F466[];
extern u16 D_0026F472[];
extern u16 D_0026F474[];
extern u16 D_0028DC68_as_u16_a[];
extern u16 D_0028DC6A[];
extern u16 D_0028DC6C[];
extern u16 D_0028DC6E[];

void func_002108C0(void) {
    reg_tmp.w = (u32)D_0025FA30_as_u16_a;
    D_0026DF78[0] = reg_tmp.h[1];
    D_0026DF7A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FA70_as_u16_a;
    D_0026DF86[0] = reg_tmp.h[1];
    D_0026DF88[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FA70_as_u16_a;
    D_0026DF94[0] = reg_tmp.h[1];
    D_0026DF96[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FA70_as_u16_a;
    D_0026DFA2[0] = reg_tmp.h[1];
    D_0026DFA4[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00244930;
    D_0026DFB0[0] = reg_tmp.h[1];
    D_0026DFB2[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002610F0;
    D_0026DFC8[0] = reg_tmp.h[1];
    D_0026DFCA[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00244930;
    D_0026DFD6[0] = reg_tmp.h[1];
    D_0026DFD8[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FA30_as_u16_a;
    D_0026E938[0] = reg_tmp.h[1];
    D_0026E93A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FA70_as_u16_a;
    D_0026E946[0] = reg_tmp.h[1];
    D_0026E948[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FA70_as_u16_a;
    D_0026E954[0] = reg_tmp.h[1];
    D_0026E956[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FA70_as_u16_a;
    D_0026E962[0] = reg_tmp.h[1];
    D_0026E964[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261D70;
    D_0026E970[0] = reg_tmp.h[1];
    D_0026E972[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0026ED30;
    D_0026ED10_as_u16_a[0] = reg_tmp.h[1];
    D_0026ED12[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0026ED40;
    D_0026ED14[0] = reg_tmp.h[1];
    D_0026ED16[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0026ED50;
    D_0026ED18[0] = reg_tmp.h[1];
    D_0026ED1A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0026ED60;
    D_0026ED1C[0] = reg_tmp.h[1];
    D_0026ED1E[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0026ED30;
    D_0026ED20[0] = reg_tmp.h[1];
    D_0026ED22[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0026ED40;
    D_0026ED24[0] = reg_tmp.h[1];
    D_0026ED26[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0026ED50;
    D_0026ED28[0] = reg_tmp.h[1];
    D_0026ED2A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0026ED60;
    D_0026ED2C[0] = reg_tmp.h[1];
    D_0026ED2E[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0026ED70;
    D_0028DC68_as_u16_a[0] = reg_tmp.h[1];
    D_0028DC6A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0028DC70;
    D_0028DC6C[0] = reg_tmp.h[1];
    D_0028DC6E[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_002610F0;
    D_0026F328[0] = reg_tmp.h[1];
    D_0026F32A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00249E90;
    D_0026F336[0] = reg_tmp.h[1];
    D_0026F338[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261D30;
    D_0026F346[0] = reg_tmp.h[1];
    D_0026F348[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FE70_as_u16_a;
    D_0026F448[0] = reg_tmp.h[1];
    D_0026F44A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FEB0_as_u16_a;
    D_0026F456[0] = reg_tmp.h[1];
    D_0026F458[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_0025FEF0_as_u16_a;
    D_0026F464[0] = reg_tmp.h[1];
    D_0026F466[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261D70;
    D_0026F472[0] = reg_tmp.h[1];
    D_0026F474[0] = reg_tmp.h[0];
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
extern u8 D_0028E290;
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
                if ((D_0028E290 == 2) && (D_0028ED60 == 0)) {
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
extern s16 D_0029F260[];
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
    if (D_0029F260[0] >= 0) {
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
extern s16 D_0029F1F0[];
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
    if (D_0029F1F0[0] >= 0) {
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
extern u16 D_0029C06C[];

void func_00211430(void) {
    entity_follow_scroll();
    reg_d1.h[0] = D_0029C06C[0];
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


void func_002114C0(void) {
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
extern u8 *jtbl_0028E3F4_as_u8_p;

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
    jtbl_0028E3F4_as_u8_p = reg_a0;
    ((Fn)jtbl_0028E3F4_as_u8_p)();
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
extern u16 *reg_a2_as_u16_p;

void func_00211920(void) {
    D_0028E9A0 = reg_d0.w;
    reg_d3.h[0] = reg_d0.h[0];
    reg_d3.h[0] &= 0x3C;
    reg_a2_as_u16_p = *(u16 **)(D_00251700 + (reg_d3.h[0] & ~3));
    *(u16 *)(reg_a0 + 0) = *reg_a2_as_u16_p;
    reg_a2_as_u16_p += 1;
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
    reg_a2_as_u16_p = *(u16 **)(D_00251700 + (reg_d3.h[0] & ~3));
    *(u16 *)(reg_a0 + 0) = *reg_a2_as_u16_p;
    reg_a2_as_u16_p += 1;
    *(u16 *)(reg_a0 + 2) = reg_d2.h[1];
    *(u16 *)(reg_a0 + 4) = reg_d2.h[0];
    func_002119A0();
}
