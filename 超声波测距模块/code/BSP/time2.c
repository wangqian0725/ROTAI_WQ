#include "main.h"

/***********************************************************************
*   函 数 名: time2_init
*   功能说明: 定时器2初始化函数
*   形    参：无
*   返 回 值: 无
***********************************************************************/
void time2_init(void)
{
   
    TIM2_DeInit();//时钟寄存器初始化
    TIM2_TimeBaseInit(TIM2_PRESCALER_4, 0xFFFF);//4分频
    TIM2_ARRPreloadConfig(ENABLE);//使能自动重装
    TIM2_ITConfig(TIM2_IT_UPDATE , ENABLE);//数据更新中断

}