#include "pc_replay_storage.h"
#include "pc_data_alias.h"

_Alignas(64) PcReplayStorage pc_replay;
_Alignas(64) u8 g_replay_file_loaded[PC_REPLAY_CARD_SIZE];

PC_DATA_ALIAS(g_replay_file_as_SaveHeader, pc_replay, 0x0);

/* Checksum field in the loaded card replay, after its 1 KiB header. */
PC_DATA_ALIAS(D_006C4AE8, g_replay_file_loaded, 0x202e8);
