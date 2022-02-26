/**
 * @file
 * @brief 各種コマンドの実行管理
 */
#ifndef COMMAND_DISPATCHER_H_
#define COMMAND_DISPATCHER_H_

#include "../System/TimeManager/obc_time.h"
#include "common_cmd_packet.h"
#include "packet_list.h"
#include <src_user/TlmCmd/command_definitions.h>

/**
 * @struct CDIS_ExecInfo
 * @brief  コマンド実行情報
 */
typedef struct
{
  ObcTime time;       //!< 実行時刻
  CMD_CODE code;      //!< 実行コマンドID
  CCP_EXEC_STS sts;   //!< 実行結果
} CDIS_ExecInfo;

/**
 * @struct CommandDispatcher
 * @brief  CommandDispatcher の Info 構造体
 */
typedef struct
{
  CDIS_ExecInfo prev;       //!< 前回のコマンド実行情報
  CDIS_ExecInfo prev_err;   //!< 最後にエラーが出たコマンド実行情報
  uint32_t error_counter;   //!< エラーカウンタ
  int lockout;
  int stop_on_error;
  PacketList* pli;          //!< コマンドキュー
} CommandDispatcher;

CommandDispatcher CDIS_init(PacketList* pli);

void CDIS_dispatch_command(CommandDispatcher* cdis);

void CDIS_clear_command_list(CommandDispatcher* cdis);

void CDIS_clear_error_status(CommandDispatcher* cdis);

#endif
