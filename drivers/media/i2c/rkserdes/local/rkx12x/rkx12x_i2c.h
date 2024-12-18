/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2024 Rockchip Electronics Co., Ltd.
 *
 */

#ifndef __RKX12X_I2C_H__
#define __RKX12X_I2C_H__

#include <linux/i2c.h>

/* i2c register array */
#define RKX12X_I2C_REG_NULL	0xFFFFFFFF // array flag: end
#define RKX12X_I2C_REG_DELAY	0xFFFFFFFE // array flag: delay

struct rkx12x_i2c_regval {
	u32 reg_addr; // register address: 32bits
	u32 reg_val; // register value: 32bits
	u32 val_mask; // value mask: 32bits
};

struct rkx12x_i2c_init_seq {
	struct rkx12x_i2c_regval *reg_init_seq;
	u32 reg_seq_size;
	u32 seq_item_size; // sizeof(struct rkx12x_i2c_regval) = 12 bytes
};

/* rkx12x register i2c read / write api */
int rkx12x_i2c_reg_read(struct i2c_client *client, u32 reg, u32 *val);
int rkx12x_i2c_reg_write(struct i2c_client *client, u32 reg, u32 val);
int rkx12x_i2c_reg_update(struct i2c_client *client, u32 reg, u32 mask, u32 val);

/* rkx12x i2c init sequence api */
int rkx12x_i2c_load_init_seq(struct device *dev, struct device_node *node,
				struct rkx12x_i2c_init_seq *init_seq);
int rkx12x_i2c_run_init_seq(struct i2c_client *client,
				struct rkx12x_i2c_init_seq *init_seq);

#endif /* __RKX12X_I2C_H__ */
