/*
 * drv2605_simple.c
 *
 *  Created on: Nov 17, 2025
 *      Author: 15039
 */

#include "drv2605_simple.h"

// 最简单的初始化
uint8_t DRV2605_SimpleInit(I2C_HandleTypeDef *hi2c)
{
    uint8_t status;

    // 1. 检查设备ID
    if(HAL_I2C_Mem_Read(hi2c, DRV2605_ADDR, 0x00, 1, &status, 1, 100) != HAL_OK)
    {
        return 0; // 通信失败
    }

    // 2. 设置模式为实时播放（最简单）
    uint8_t mode = DRV2605_MODE_RTP;
    if(HAL_I2C_Mem_Write(hi2c, DRV2605_ADDR, 0x01, 1, &mode, 1, 100) != HAL_OK)
    {
        return 0;
    }

    return 1; // 初始化成功
}

// 最简单的振动函数
void DRV2605_SimpleVibrate(I2C_HandleTypeDef *hi2c, uint8_t strength)
{
    // 直接设置实时播放值，范围0-127
    HAL_I2C_Mem_Write(hi2c, DRV2605_ADDR, 0x02, 1, &strength, 1, 100);
}
