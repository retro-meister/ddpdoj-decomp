#include "pc_replay_storage.h"

_Alignas(64) PcReplayStorage pc_replay;
_Alignas(64) u8 g_replay_file_loaded[PC_REPLAY_CARD_SIZE];
