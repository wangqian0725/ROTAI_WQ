#include "main.h"

/***********************************************************************
*   函 数 名: gpio_init
*   功能说明: GPIO初始化函数
*   形    参：无
*   返 回 值: 无
***********************************************************************/

void gpio_init(void)
{
    GPIO_DeInit(GPIOD);
    GPIO_DeInit(GPIOC);//端口初始化
    
    GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_OUT_PP_HIGH_FAST);
    GPIO_Init(GPIOD, GPIO_PIN_2, GPIO_MODE_OUT_PP_LOW_FAST);
    GPIO_Init(GPIOC, GPIO_PIN_7, GPIO_MODE_OUT_PP_HIGH_FAST);
    GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST);
    GPIO_Init(GPIOC, GPIO_PIN_6, GPIO_MODE_IN_FL_NO_IT);

}