/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2020 MediaTek Inc.
 */

#ifndef _FW_LOG_EMI_H
#define _FW_LOG_EMI_H

struct FW_LOG_EMI_SUB_CTRL {
	enum ENUM_FW_LOG_CTRL_TYPE type;
	uint32_t base_addr;
	uint32_t buf_base_addr;
	uint32_t length;
	uint32_t rp; /* read pointer */
	uint32_t irp; /* internal read pointer, used by driver */
	uint32_t wp; /* write pointer */
	uint32_t iwp; /* internal write pointer, used by fw */
	uint8_t *buffer;
};

struct FW_LOG_EMI_SUB_STATS {
	uint32_t handle_size;
};

struct FW_LOG_EMI_STATS {
	unsigned long update_period; /* in ms */
	uint32_t request;
	uint32_t skipped;
	uint32_t handled;
	struct FW_LOG_EMI_SUB_STATS sub_stats[ENUM_FW_LOG_CTRL_TYPE_NUM];
};

struct FW_LOG_EMI_CTRL {
	u_int8_t initialized;
	u_int8_t started;
	uint32_t base_addr;
	struct FW_LOG_EMI_SUB_CTRL sub_ctrls[ENUM_FW_LOG_CTRL_TYPE_NUM];
	void *priv;
	struct FW_LOG_EMI_STATS stats;
};

int32_t fw_log_emi_handler(void);
uint32_t fw_log_emi_start(struct ADAPTER *ad);
void fw_log_emi_stop(struct ADAPTER *ad);
uint32_t fw_log_emi_init(struct ADAPTER *ad);
void fw_log_emi_deinit(struct ADAPTER *ad);

#endif /* _FW_LOG_EMI_H */

