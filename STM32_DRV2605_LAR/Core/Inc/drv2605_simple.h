/*
 * drv2605_simple.h
 *
 *  Created on: 2025年11月17日
 *      Author: 15039
 */
#ifndef DRV2605_SIMPLE_H
#define DRV2605_SIMPLE_H

#include "main.h"
#include "i2c.h"

#define DRV2605_ADDR 0x5A << 1  // I2C地址

// 寄存器地址
#define DRV2605_REG_STATUS 0x00
#define DRV2605_REG_MODE 0x01
#define DRV2605_REG_RTP_INPUT 0x02
#define DRV2605_REG_LIB_SEL 0x03
#define DRV2605_REG_GO 0x0C

// 模式设置
#define DRV2605_MODE_INT_TRIG 0x00
#define DRV2605_MODE_RTP 0x05

// 函数声明
uint8_t DRV2605_SimpleInit(I2C_HandleTypeDef *hi2c);
void DRV2605_SimpleVibrate(I2C_HandleTypeDef *hi2c, uint8_t strength);

#endif
