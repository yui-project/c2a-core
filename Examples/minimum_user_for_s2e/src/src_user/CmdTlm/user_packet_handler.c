#pragma section REPRO
/**
 * @file   user_packet_handler.c
 * @brief  packet_handlerのコマンドルーター，コマンドアナライザのユーザー定義部分
 */
#include "user_packet_handler.h"
// #include "../Applications/DriverInstances/di_tobc.h"
// #include "../Applications/DriverInstances/di_aobc.h"

#define PH_AOBC_CMD_LIST_MAX   (16)          //!< AOBC CMD QUEUEサイズ
#define PH_TOBC_CMD_LIST_MAX   (16)          //!< TOBC CMD QUEUEサイズ

static PH_ACK PH_add_aobc_cmd_(const CTCP* packet);
static PH_ACK PH_add_tobc_cmd_(const CTCP* packet);

PacketList PH_aobc_cmd_list;
PacketList PH_tobc_cmd_list;

static PL_Node PH_aobc_cmd_stock_[PH_AOBC_CMD_LIST_MAX];
static PL_Node PH_tobc_cmd_stock_[PH_TOBC_CMD_LIST_MAX];


void PH_user_init(void)
{
  PL_initialize(PH_aobc_cmd_stock_, PH_AOBC_CMD_LIST_MAX, &PH_aobc_cmd_list);
  PL_initialize(PH_tobc_cmd_stock_, PH_TOBC_CMD_LIST_MAX, &PH_tobc_cmd_list);
}


PH_ACK PH_user_analyze_cmd(const CTCP* packet)
{
  switch (CCP_get_dest_type(packet))
  {
  case TCP_CMD_DEST_TYPE_TO_AOBC:
    return (PH_add_aobc_cmd_(packet) == PH_SUCCESS) ? PH_FORWARDED : PH_PL_LIST_FULL;
  case TCP_CMD_DEST_TYPE_TO_TOBC:
    return (PH_add_tobc_cmd_(packet) == PH_SUCCESS) ? PH_FORWARDED : PH_PL_LIST_FULL;
  default:
    // TCP_CMD_DEST_TYPE_TO_ME
    // TCP_CMD_DEST_TYPE_TO_MOBC （自分）
    // 宛先不明
    // はここに
    return PH_UNKNOWN;
  }
}


CCP_EXEC_STS PH_user_cmd_router(const CTCP* packet)
{
  switch (CCP_get_dest_id(packet))
  {
  case TCP_APID_AOBC_CMD:
    // AOBCに配送
    // return DI_AOBC_dispatch_command(packet);
  case TCP_APID_TOBC_CMD:
    // TOBCに配送
    // return DI_TOBC_dispatch_command(packet);
  default:
    // 該当する配送先が定義されていない場合。
    return CCP_EXEC_ROUTING_FAILED;
  }
}


static PH_ACK PH_add_aobc_cmd_(const CTCP* packet)
{
  (void)packet;
#if 0
  PL_ACK ack = PL_push_back(&PH_aobc_cmd_list, packet);

  if (ack != PL_SUCCESS) return PH_PL_LIST_FULL;
#endif
  return PH_SUCCESS;
}


static PH_ACK PH_add_tobc_cmd_(const CTCP* packet)
{
  (void)packet;
#if 0
  PL_ACK ack = PL_push_back(&PH_tobc_cmd_list, packet);

  if (ack != PL_SUCCESS) return PH_PL_LIST_FULL;
#endif
  return PH_SUCCESS;
}

#pragma section
