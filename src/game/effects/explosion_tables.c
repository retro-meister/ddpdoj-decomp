/* Explosion scripts and frames. */
#include "common.h"
#include "explosion_scripts.h"

void entity_draw_layer1();
void entity_draw_layer2();
void entity_draw_layer3();
void entity_draw_layer4();
void entity_draw_layer5();

ExplosionScriptEntry explosion_scripts[34] = {
    { { 0, 1 }, { 2, 3 } }, { { 4, 5 }, { 6, 7 } },
    { { 8, 9 }, { 10, 11 } }, { { 12, 13 }, { 14, 15 } },
    { { 16, 17 }, { 18, 19 } }, { { 20, 21 }, { 22, 23 } },
    { { 24, 25 }, { 26, 27 } }, { { 28, 29 }, { 30, 31 } },
    { { 32, 33 }, { 34, 35 } }, { { 36, 37 }, { 38, 39 } },
    { { 40, 41 }, { 42, 43 } }, { { 44, 45 }, { 46, 47 } },
    { { 48, 49 }, { 50, 51 } }, { { 52, 53 }, { 54, 55 } },
    { { 56, 57 }, { 58, 59 } }, { { 60, 61 }, { 62, 63 } },
    { { 64, 65 }, { 66, 67 } }, { { 68, 69 }, { 70, 71 } },
    { { 72, 73 }, { 74, 75 } }, { { 76, 77 }, { 78, 79 } },
    { { 80, 81 }, { 82, 83 } }, { { 84, 85 }, { 86, 87 } },
    { { 88, 89 }, { 90, 91 } }, { { 92, 93 }, { 94, 95 } },
    { { 96, 97 }, { 98, 99 } }, { { 100, 101 }, { 102, 103 } },
    { { 104, 105 }, { 106, 107 } }, { { 108, 109 }, { 110, 111 } },
    { { 112, 113 }, { 114, 115 } }, { { 116, 117 }, { 118, 119 } },
    { { 120, 121 }, { 122, 123 } }, { { 124, 125 }, { 126, 127 } },
    { { 128, 129 }, { 130, 131 } }, { { 132, 133 }, { 134, 135 } },
};

ExplosionScriptEntry explosion_scripts_b[34] = {
    { { 0, 1 }, { 2, 3 } }, { { 4, 5 }, { 6, 7 } },
    { { 8, 9 }, { 10, 11 } }, { { 12, 13 }, { 14, 15 } },
    { { 16, 17 }, { 18, 19 } }, { { 20, 21 }, { 22, 23 } },
    { { 24, 25 }, { 26, 27 } }, { { 28, 29 }, { 30, 31 } },
    { { 32, 33 }, { 34, 35 } }, { { 36, 37 }, { 38, 39 } },
    { { 40, 41 }, { 42, 43 } }, { { 44, 45 }, { 46, 47 } },
    { { 48, 49 }, { 50, 51 } }, { { 52, 53 }, { 54, 55 } },
    { { 56, 57 }, { 58, 59 } }, { { 60, 61 }, { 62, 63 } },
    { { 64, 65 }, { 66, 67 } }, { { 68, 69 }, { 70, 71 } },
    { { 72, 73 }, { 74, 75 } }, { { 76, 77 }, { 78, 79 } },
    { { 80, 81 }, { 82, 83 } }, { { 84, 85 }, { 86, 87 } },
    { { 88, 89 }, { 90, 91 } }, { { 92, 93 }, { 94, 95 } },
    { { 96, 97 }, { 98, 99 } }, { { 100, 101 }, { 102, 103 } },
    { { 104, 105 }, { 106, 107 } }, { { 108, 109 }, { 110, 111 } },
    { { 112, 113 }, { 114, 115 } }, { { 116, 117 }, { 118, 119 } },
    { { 120, 121 }, { 122, 123 } }, { { 124, 125 }, { 126, 127 } },
    { { 128, 129 }, { 130, 131 } }, { { 132, 133 }, { 134, 135 } },
};

struct ExplosionScript12Frames explosion_script_00 = {
    { EXPLOSION_SET_LOOK, 0x0618, -0x0600, -0x0300 },
    {
        { 0, 0x1286 }, { 0, 0x1287 }, { 0, 0x1288 }, { 0, 0x1289 },
        { 0, 0x128A }, { 0, 0x128B }, { 0, 0x128C }, { 0, 0x128D },
        { 0, 0x128E }, { 0, 0x128F }, { 0, 0x1290 }, { 0, 0x1291 },
    },
};

u16 explosion_timings_00[16] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    EXPLOSION_TIMING_END,
};

struct ExplosionTwoPhaseScript12Frames explosion_script_b_00 = {
    {
        { EXPLOSION_SET_LOOK, 0x0A38, -0x0A00, -0x0700 },
        { EXPLOSION_MOVE, 0, 0x0200, 0 },
        { { 0, 0x12DE }, { 0, 0x12DF }, { 0, 0x12E0 } },
    },
    { EXPLOSION_SET_LOOK, 0x0618, -0x0600, -0x0300 },
    { EXPLOSION_MOVE, 0, -0x0200, 0 },
    {
        { 0, 0x1286 }, { 0, 0x1287 }, { 0, 0x1288 }, { 0, 0x1289 },
        { 0, 0x128A }, { 0, 0x128B }, { 0, 0x128C }, { 0, 0x128D },
        { 0, 0x128E }, { 0, 0x128F }, { 0, 0x1290 }, { 0, 0x1291 },
    },
};

u16 explosion_timings_b_00[16] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, EXPLOSION_TIMING_END,
};

struct ExplosionScript12Frames explosion_script_02 = {
    { EXPLOSION_SET_LOOK, 0x0828, -0x0800, -0x0500 },
    {
        { 0, 0x1292 }, { 0, 0x1293 }, { 0, 0x1294 }, { 0, 0x1295 },
        { 0, 0x1296 }, { 0, 0x1297 }, { 0, 0x1298 }, { 0, 0x1299 },
        { 0, 0x129A }, { 0, 0x129B }, { 0, 0x129C }, { 0, 0x129D },
    },
};

u16 explosion_timings_02[16] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    EXPLOSION_TIMING_END,
};

struct ExplosionTwoPhaseScript12Frames explosion_script_b_02 = {
    {
        { EXPLOSION_SET_LOOK, 0x0A38, -0x0A00, -0x0700 },
        { EXPLOSION_MOVE, 0, 0x0200, 0 },
        { { 0, 0x12DE }, { 0, 0x12DF }, { 0, 0x12E0 } },
    },
    { EXPLOSION_SET_LOOK, 0x0828, -0x0800, -0x0500 },
    { EXPLOSION_MOVE, 0, -0x0200, 0 },
    {
        { 0, 0x1292 }, { 0, 0x1293 }, { 0, 0x1294 }, { 0, 0x1295 },
        { 0, 0x1296 }, { 0, 0x1297 }, { 0, 0x1298 }, { 0, 0x1299 },
        { 0, 0x129A }, { 0, 0x129B }, { 0, 0x129C }, { 0, 0x129D },
    },
};

u16 explosion_timings_b_02[16] = {
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, EXPLOSION_TIMING_END,
};

struct ExplosionScript12Frames explosion_script_04 = {
    { EXPLOSION_SET_LOOK, 0x0A38, -0x0A00, -0x0700 },
    {
        { 0, 0x12D2 }, { 0, 0x12D3 }, { 0, 0x12D4 }, { 0, 0x12D5 },
        { 0, 0x12D6 }, { 0, 0x12D7 }, { 0, 0x12D8 }, { 0, 0x12D9 },
        { 0, 0x12DA }, { 0, 0x12DB }, { 0, 0x12DC }, { 0, 0x12DD },
    },
};

u16 explosion_timings_04[16] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    EXPLOSION_TIMING_END,
};

struct ExplosionTwoPhaseScript12Frames explosion_script_b_04 = {
    {
        { EXPLOSION_SET_LOOK, 0x0A38, -0x0A00, -0x0700 },
        { EXPLOSION_MOVE, 0, 0x0200, 0 },
        { { 0, 0x12DE }, { 0, 0x12DF }, { 0, 0x12E0 } },
    },
    { EXPLOSION_SET_LOOK, 0x0A38, -0x0A00, -0x0700 },
    { EXPLOSION_MOVE, 0, -0x0200, 0 },
    {
        { 0, 0x12D2 }, { 0, 0x12D3 }, { 0, 0x12D4 }, { 0, 0x12D5 },
        { 0, 0x12D6 }, { 0, 0x12D7 }, { 0, 0x12D8 }, { 0, 0x12D9 },
        { 0, 0x12DA }, { 0, 0x12DB }, { 0, 0x12DC }, { 0, 0x12DD },
    },
};

u16 explosion_timings_b_04[16] = {
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, EXPLOSION_TIMING_END,
};

struct ExplosionScript24Frames explosion_script_06 = {
    { EXPLOSION_SET_LOOK, 0x0C40, -0x0C00, -0x0800 },
    { EXPLOSION_MOVE, 0, 0x0400, 0 },
    {
        { 0, 0x12BA }, { 0, 0x12BB }, { 0, 0x12BC }, { 0, 0x12BD },
        { 0, 0x12BE }, { 0, 0x12BF }, { 0, 0x12C0 }, { 0, 0x12C1 },
        { 0, 0x12C2 }, { 0, 0x12C3 }, { 0, 0x12C4 }, { 0, 0x12C5 },
        { 0, 0x12C6 }, { 0, 0x12C7 }, { 0, 0x12C8 }, { 0, 0x12C9 },
        { 0, 0x12CA }, { 0, 0x12CB }, { 0, 0x12CC }, { 0, 0x12CD },
        { 0, 0x12CE }, { 0, 0x12CF }, { 0, 0x12D0 }, { 0, 0x12D1 },
    },
};

u16 explosion_timings_06[32] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    EXPLOSION_TIMING_END,
};

struct ExplosionTwoPhaseScript24Frames explosion_script_b_06 = {
    {
        { EXPLOSION_SET_LOOK, 0x1470, -0x1400, -0x0E00 },
        { EXPLOSION_MOVE, 0, 0x0A00, 0 },
        { { 0, 0x121A }, { 0, 0x121B }, { 0, 0x121C } },
    },
    { EXPLOSION_SET_LOOK, 0x0C40, -0x0C00, -0x0800 },
    { EXPLOSION_MOVE, 0, -0x0600, 0 },
    {
        { 0, 0x12BA }, { 0, 0x12BB }, { 0, 0x12BC }, { 0, 0x12BD },
        { 0, 0x12BE }, { 0, 0x12BF }, { 0, 0x12C0 }, { 0, 0x12C1 },
        { 0, 0x12C2 }, { 0, 0x12C3 }, { 0, 0x12C4 }, { 0, 0x12C5 },
        { 0, 0x12C6 }, { 0, 0x12C7 }, { 0, 0x12C8 }, { 0, 0x12C9 },
        { 0, 0x12CA }, { 0, 0x12CB }, { 0, 0x12CC }, { 0, 0x12CD },
        { 0, 0x12CE }, { 0, 0x12CF }, { 0, 0x12D0 }, { 0, 0x12D1 },
    },
};

u16 explosion_timings_b_06[32] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, EXPLOSION_TIMING_END,
};

struct ExplosionScript28Frames explosion_script_08 = {
    { EXPLOSION_SET_LOOK, 0x1060, -0x1000, -0x0C00 },
    { EXPLOSION_MOVE, 0, 0x0800, 0 },
    {
        { 0, 0x124A }, { 0, 0x124B }, { 0, 0x124C }, { 0, 0x124D },
        { 0, 0x124E }, { 0, 0x124F }, { 0, 0x1250 }, { 0, 0x1251 },
        { 0, 0x1252 }, { 0, 0x1253 }, { 0, 0x1254 }, { 0, 0x1255 },
        { 0, 0x1256 }, { 0, 0x1257 }, { 0, 0x1258 }, { 0, 0x1259 },
        { 0, 0x125A }, { 0, 0x125B }, { 0, 0x125C }, { 0, 0x125D },
        { 0, 0x125E }, { 0, 0x125F }, { 0, 0x1260 }, { 0, 0x1261 },
        { 0, 0x1262 }, { 0, 0x1263 }, { 0, 0x1264 }, { 0, 0x1265 },
    },
};

u16 explosion_timings_08[32] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, EXPLOSION_TIMING_END,
};

struct ExplosionTwoPhaseScript28Frames explosion_script_b_08 = {
    {
        { EXPLOSION_SET_LOOK, 0x1470, -0x1400, -0x0E00 },
        { EXPLOSION_MOVE, 0, 0x0A00, 0 },
        { { 0, 0x121A }, { 0, 0x121B }, { 0, 0x121C } },
    },
    { EXPLOSION_SET_LOOK, 0x1060, -0x1000, -0x0C00 },
    { EXPLOSION_MOVE, 0, -0x0200, 0 },
    {
        { 0, 0x124A }, { 0, 0x124B }, { 0, 0x124C }, { 0, 0x124D },
        { 0, 0x124E }, { 0, 0x124F }, { 0, 0x1250 }, { 0, 0x1251 },
        { 0, 0x1252 }, { 0, 0x1253 }, { 0, 0x1254 }, { 0, 0x1255 },
        { 0, 0x1256 }, { 0, 0x1257 }, { 0, 0x1258 }, { 0, 0x1259 },
        { 0, 0x125A }, { 0, 0x125B }, { 0, 0x125C }, { 0, 0x125D },
        { 0, 0x125E }, { 0, 0x125F }, { 0, 0x1260 }, { 0, 0x1261 },
        { 0, 0x1262 }, { 0, 0x1263 }, { 0, 0x1264 }, { 0, 0x1265 },
    },
};

u16 explosion_timings_b_08[32] = {
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, EXPLOSION_TIMING_END,
};

struct ExplosionScript32Frames explosion_script_10 = {
    { EXPLOSION_SET_LOOK, 0x1470, -0x1400, -0x0E00 },
    { EXPLOSION_MOVE, 0, 0x0C00, 0 },
    {
        { 0, 0x1266 }, { 0, 0x1267 }, { 0, 0x1268 }, { 0, 0x1269 },
        { 0, 0x126A }, { 0, 0x126B }, { 0, 0x126C }, { 0, 0x126D },
        { 0, 0x126E }, { 0, 0x126F }, { 0, 0x1270 }, { 0, 0x1271 },
        { 0, 0x1272 }, { 0, 0x1273 }, { 0, 0x1274 }, { 0, 0x1275 },
        { 0, 0x1276 }, { 0, 0x1277 }, { 0, 0x1278 }, { 0, 0x1279 },
        { 0, 0x127A }, { 0, 0x127B }, { 0, 0x127C }, { 0, 0x127D },
        { 0, 0x127E }, { 0, 0x127F }, { 0, 0x1280 }, { 0, 0x1281 },
        { 0, 0x1282 }, { 0, 0x1283 }, { 0, 0x1284 }, { 0, 0x1285 },
    },
};

u16 explosion_timings_10[40] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, EXPLOSION_TIMING_END,
};

struct ExplosionScript35Frames explosion_script_b_10 = {
    { EXPLOSION_SET_LOOK, 0x1470, -0x1400, -0x0E00 },
    { EXPLOSION_MOVE, 0, 0x0C00, 0 },
    {
        { 0, 0x121A }, { 0, 0x121B }, { 0, 0x121C }, { 0, 0x1266 },
        { 0, 0x1267 }, { 0, 0x1268 }, { 0, 0x1269 }, { 0, 0x126A },
        { 0, 0x126B }, { 0, 0x126C }, { 0, 0x126D }, { 0, 0x126E },
        { 0, 0x126F }, { 0, 0x1270 }, { 0, 0x1271 }, { 0, 0x1272 },
        { 0, 0x1273 }, { 0, 0x1274 }, { 0, 0x1275 }, { 0, 0x1276 },
        { 0, 0x1277 }, { 0, 0x1278 }, { 0, 0x1279 }, { 0, 0x127A },
        { 0, 0x127B }, { 0, 0x127C }, { 0, 0x127D }, { 0, 0x127E },
        { 0, 0x127F }, { 0, 0x1280 }, { 0, 0x1281 }, { 0, 0x1282 },
        { 0, 0x1283 }, { 0, 0x1284 }, { 0, 0x1285 },
    },
};

u16 explosion_timings_b_10[40] = {
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, EXPLOSION_TIMING_END,
};

struct ExplosionScript24Frames explosion_script_12 = {
    { EXPLOSION_SET_LOOK, 0x0828, -0x0800, -0x0500 },
    { EXPLOSION_MOVE, 0, 0x0300, 0 },
    {
        { 0, 0x11E2 }, { 0, 0x11E3 }, { 0, 0x11E4 }, { 0, 0x11E5 },
        { 0, 0x11E6 }, { 0, 0x11E7 }, { 0, 0x11E8 }, { 0, 0x11E9 },
        { 0, 0x11EA }, { 0, 0x11EB }, { 0, 0x11EC }, { 0, 0x11ED },
        { 0, 0x11EE }, { 0, 0x11EF }, { 0, 0x11F0 }, { 0, 0x11F1 },
        { 0, 0x11F2 }, { 0, 0x11F3 }, { 0, 0x11F4 }, { 0, 0x11F5 },
        { 0, 0x11F6 }, { 0, 0x11F7 }, { 0, 0x11F8 }, { 0, 0x11F9 },
    },
};

u16 explosion_timings_12[32] = {
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    EXPLOSION_TIMING_END,
};

struct ExplosionScript32Frames explosion_script_14 = {
    { EXPLOSION_SET_LOOK, 0x0E50, -0x0E00, -0x0A00 },
    { EXPLOSION_MOVE, 0, 0x0600, 0 },
    {
        { 0, 0x11FA }, { 0, 0x11FB }, { 0, 0x11FC }, { 0, 0x11FD },
        { 0, 0x11FE }, { 0, 0x11FF }, { 0, 0x1200 }, { 0, 0x1201 },
        { 0, 0x1202 }, { 0, 0x1203 }, { 0, 0x1204 }, { 0, 0x1205 },
        { 0, 0x1206 }, { 0, 0x1207 }, { 0, 0x1208 }, { 0, 0x1209 },
        { 0, 0x120A }, { 0, 0x120B }, { 0, 0x120C }, { 0, 0x120D },
        { 0, 0x120E }, { 0, 0x120F }, { 0, 0x1210 }, { 0, 0x1211 },
        { 0, 0x1212 }, { 0, 0x1213 }, { 0, 0x1214 }, { 0, 0x1215 },
        { 0, 0x1216 }, { 0, 0x1217 }, { 0, 0x1218 }, { 0, 0x1219 },
    },
};

u16 explosion_timings_14[40] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2,
    2, 2, 2, 2, 2, 3, 3, 3, EXPLOSION_TIMING_END,
};

struct ExplosionScript28Frames explosion_script_16 = {
    { EXPLOSION_SET_LOOK, 0x0E50, -0x0E00, -0x0A00 },
    { EXPLOSION_MOVE, 0, 0x0600, 0 },
    {
        { 0, 0x129E }, { 0, 0x129F }, { 0, 0x12A0 }, { 0, 0x12A1 },
        { 0, 0x12A2 }, { 0, 0x12A3 }, { 0, 0x12A4 }, { 0, 0x12A5 },
        { 0, 0x12A6 }, { 0, 0x12A7 }, { 0, 0x12A8 }, { 0, 0x12A9 },
        { 0, 0x12AA }, { 0, 0x12AB }, { 0, 0x12AC }, { 0, 0x12AD },
        { 0, 0x12AE }, { 0, 0x12AF }, { 0, 0x12B0 }, { 0, 0x12B1 },
        { 0, 0x12B2 }, { 0, 0x12B3 }, { 0, 0x12B4 }, { 0, 0x12B5 },
        { 0, 0x12B6 }, { 0, 0x12B7 }, { 0, 0x12B8 }, { 0, 0x12B9 },
    },
};

u16 explosion_timings_16[32] = {
    0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3,
    3, 3, 3, 3, EXPLOSION_TIMING_END,
};

struct ExplosionScript33Frames explosion_script_18 = {
    { EXPLOSION_SET_LOOK, 0x1470, -0x1400, -0x0E00 },
    { EXPLOSION_MOVE, 0, 0x0E00, 0 },
    {
        { 0, 0x121D }, { 0, 0x121E }, { 0, 0x121F }, { 0, 0x1220 },
        { 0, 0x1221 }, { 0, 0x1222 }, { 0, 0x1223 }, { 0, 0x1224 },
        { 0, 0x1225 }, { 0, 0x1226 }, { 0, 0x1227 }, { 0, 0x1228 },
        { 0, 0x1229 }, { 0, 0x122A }, { 0, 0x122B }, { 0, 0x122C },
        { 0, 0x122D }, { 0, 0x122E }, { 0, 0x122F }, { 0, 0x1230 },
        { 0, 0x1231 }, { 0, 0x1232 }, { 0, 0x1233 }, { 0, 0x1234 },
        { 0, 0x1235 }, { 0, 0x1236 }, { 0, 0x1237 }, { 0, 0x1238 },
        { 0, 0x1239 }, { 0, 0x123A }, { 0, 0x123B }, { 0, 0x123C },
        { 0, 0x123D },
    },
};

u16 explosion_timings_18[40] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 2, 2, 2, 2, 2, 2, EXPLOSION_TIMING_END,
};

struct ExplosionScript18Frames explosion_scripts_20 = {
    { EXPLOSION_SET_LOOK, 0x0A38, -0x0A00, -0x0700 },
    { EXPLOSION_MOVE, 0, 0x0300, 0 },
    {
        { 0, 0x12DE }, { 0, 0x12DF }, { 0, 0x12E0 }, { 0, 0x12E1 },
        { 0, 0x12E2 }, { 0, 0x12E3 }, { 0, 0x12E4 }, { 0, 0x12E5 },
        { 0, 0x12E6 }, { 0, 0x12E7 }, { 0, 0x12E8 }, { 0, 0x12E9 },
        { 0, 0x12EA }, { 0, 0x12EB }, { 0, 0x12EC }, { 0, 0x12ED },
        { 0, 0x12EE }, { 0, 0x12EF },
    },
};

u16 explosion_timings_20[24] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, EXPLOSION_TIMING_END,
};

struct ExplosionTwoPhaseScript32Frames explosion_scripts_22 = {
    {
        { EXPLOSION_SET_LOOK, 0x1470, -0x1400, -0x0E00 },
        { EXPLOSION_MOVE, 0, 0x0A00, 0 },
        { { 0, 0x121A }, { 0, 0x121B }, { 0, 0x121C } },
    },
    { EXPLOSION_SET_LOOK, 0x0E50, -0x0E00, -0x0A00 },
    { EXPLOSION_MOVE, 0, -0x0400, 0 },
    {
        { 0, 0x11FA }, { 0, 0x11FB }, { 0, 0x11FC }, { 0, 0x11FD },
        { 0, 0x11FE }, { 0, 0x11FF }, { 0, 0x1200 }, { 0, 0x1201 },
        { 0, 0x1202 }, { 0, 0x1203 }, { 0, 0x1204 }, { 0, 0x1205 },
        { 0, 0x1206 }, { 0, 0x1207 }, { 0, 0x1208 }, { 0, 0x1209 },
        { 0, 0x120A }, { 0, 0x120B }, { 0, 0x120C }, { 0, 0x120D },
        { 0, 0x120E }, { 0, 0x120F }, { 0, 0x1210 }, { 0, 0x1211 },
        { 0, 0x1212 }, { 0, 0x1213 }, { 0, 0x1214 }, { 0, 0x1215 },
        { 0, 0x1216 }, { 0, 0x1217 }, { 0, 0x1218 }, { 0, 0x1219 },
    },
};

u16 explosion_timings_22[40] = {
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, EXPLOSION_TIMING_END,
};

struct ExplosionTwoPhaseScript28Frames explosion_scripts_24 = {
    {
        { EXPLOSION_SET_LOOK, 0x1470, -0x1400, -0x0E00 },
        { EXPLOSION_MOVE, 0, 0x0A00, 0 },
        { { 0, 0x121A }, { 0, 0x121B }, { 0, 0x121C } },
    },
    { EXPLOSION_SET_LOOK, 0x0E50, -0x0E00, -0x0A00 },
    { EXPLOSION_MOVE, 0, -0x0400, 0 },
    {
        { 0, 0x129E }, { 0, 0x129F }, { 0, 0x12A0 }, { 0, 0x12A1 },
        { 0, 0x12A2 }, { 0, 0x12A3 }, { 0, 0x12A4 }, { 0, 0x12A5 },
        { 0, 0x12A6 }, { 0, 0x12A7 }, { 0, 0x12A8 }, { 0, 0x12A9 },
        { 0, 0x12AA }, { 0, 0x12AB }, { 0, 0x12AC }, { 0, 0x12AD },
        { 0, 0x12AE }, { 0, 0x12AF }, { 0, 0x12B0 }, { 0, 0x12B1 },
        { 0, 0x12B2 }, { 0, 0x12B3 }, { 0, 0x12B4 }, { 0, 0x12B5 },
        { 0, 0x12B6 }, { 0, 0x12B7 }, { 0, 0x12B8 }, { 0, 0x12B9 },
    },
};

u16 explosion_timings_24[32] = {
    0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 3, 3, 3, 3, 3, 3, EXPLOSION_TIMING_END,
};

struct ExplosionScript36Frames explosion_scripts_26 = {
    { EXPLOSION_SET_LOOK, 0x1470, -0x1400, -0x0E00 },
    { EXPLOSION_MOVE, 0, 0x0E00, 0 },
    {
        { 0, 0x121A }, { 0, 0x121B }, { 0, 0x121C }, { 0, 0x121D },
        { 0, 0x121E }, { 0, 0x121F }, { 0, 0x1220 }, { 0, 0x1221 },
        { 0, 0x1222 }, { 0, 0x1223 }, { 0, 0x1224 }, { 0, 0x1225 },
        { 0, 0x1226 }, { 0, 0x1227 }, { 0, 0x1228 }, { 0, 0x1229 },
        { 0, 0x122A }, { 0, 0x122B }, { 0, 0x122C }, { 0, 0x122D },
        { 0, 0x122E }, { 0, 0x122F }, { 0, 0x1230 }, { 0, 0x1231 },
        { 0, 0x1232 }, { 0, 0x1233 }, { 0, 0x1234 }, { 0, 0x1235 },
        { 0, 0x1236 }, { 0, 0x1237 }, { 0, 0x1238 }, { 0, 0x1239 },
        { 0, 0x123A }, { 0, 0x123B }, { 0, 0x123C }, { 0, 0x123D },
    },
};

u16 explosion_timings_26[40] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2,
    EXPLOSION_TIMING_END,
};

struct ExplosionScript12Frames explosion_scripts_28 = {
    { EXPLOSION_SET_LOOK, 0x0828, -0x0800, -0x0500 },
    {
        { 0, 0x123E }, { 0, 0x123F }, { 0, 0x1240 }, { 0, 0x1241 },
        { 0, 0x1242 }, { 0, 0x1243 }, { 0, 0x1244 }, { 0, 0x1245 },
        { 0, 0x1246 }, { 0, 0x1247 }, { 0, 0x1248 }, { 0, 0x1249 },
    },
};

u16 explosion_timings_28[16] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    EXPLOSION_TIMING_END,
};

struct ExplosionTwoPhaseScript24Frames explosion_scripts_30 = {
    {
        { EXPLOSION_SET_LOOK, 0x1470, -0x1400, -0x0E00 },
        { EXPLOSION_MOVE, 0, 0x0A00, 0 },
        { { 0, 0x121A }, { 0, 0x121B }, { 0, 0x121C } },
    },
    { EXPLOSION_SET_LOOK, 0x0828, -0x0800, -0x0500 },
    { EXPLOSION_MOVE, 0, -0x0800, 0 },
    {
        { 0, 0x11E2 }, { 0, 0x11E3 }, { 0, 0x11E4 }, { 0, 0x11E5 },
        { 0, 0x11E6 }, { 0, 0x11E7 }, { 0, 0x11E8 }, { 0, 0x11E9 },
        { 0, 0x11EA }, { 0, 0x11EB }, { 0, 0x11EC }, { 0, 0x11ED },
        { 0, 0x11EE }, { 0, 0x11EF }, { 0, 0x11F0 }, { 0, 0x11F1 },
        { 0, 0x11F2 }, { 0, 0x11F3 }, { 0, 0x11F4 }, { 0, 0x11F5 },
        { 0, 0x11F6 }, { 0, 0x11F7 }, { 0, 0x11F8 }, { 0, 0x11F9 },
    },
};

u16 explosion_timings_30[32] = {
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, EXPLOSION_TIMING_END,
};

struct ExplosionScript15Frames explosion_scripts_32 = {
    { EXPLOSION_SET_LOOK, 0x0A38, -0x0A00, -0x0700 },
    { EXPLOSION_MOVE, 0, 0x0200, 0 },
    {
        { 0, 0x12E1 }, { 0, 0x12E2 }, { 0, 0x12E3 }, { 0, 0x12E4 },
        { 0, 0x12E5 }, { 0, 0x12E6 }, { 0, 0x12E7 }, { 0, 0x12E8 },
        { 0, 0x12E9 }, { 0, 0x12EA }, { 0, 0x12EB }, { 0, 0x12EC },
        { 0, 0x12ED }, { 0, 0x12EE }, { 0, 0x12EF },
    },
};

struct ExplosionLifetimeTable explosion_scripts_33 = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, EXPLOSION_TIMING_END, 0 },
    { entity_draw_layer1, entity_draw_layer2, entity_draw_layer3, entity_draw_layer4, entity_draw_layer5 },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};
