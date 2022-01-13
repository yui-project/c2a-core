#ifndef SEQUENCE_ITEMS_H_
#define SEQUENCE_ITEMS_H_

#include <src_core/TlmCmd/common_tlm_cmd_packet.h>
#include "../../../TlmCmd/command_definitions.h"
#include <src_core/TlmCmd/block_command_table.h>

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// SIを使うことはもう非推奨！！！
// 普通のBCを使うこと！！！！
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void SI_finish_transition(CTCP* packet);

void SI_start_hk_tlm(CTCP* packet);

// BC展開
void SI_deploy_block(CTCP* packet, int line_no, bct_id_t block_no);


#endif // SEQUENCE_ITEMS_H_
