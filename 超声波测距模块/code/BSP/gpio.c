#include "main.h"

/***********************************************************************
*   �� �� ��: gpio_init
*   ����˵��: GPIO��ʼ������
*   ��    �Σ���
*   �� �� ֵ: ��
***********************************************************************/

void gpio_init(void)
{
    GPIO_DeInit(GPIOD);
    GPIO_DeInit(GPIOC);//�˿ڳ�ʼ��
    
    GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_OUT_PP_HIGH_FAST);
    GPIO_Init(GPIOD, GPIO_PIN_2, GPIO_MODE_OUT_PP_LOW_FAST);
    GPIO_Init(GPIOC, GPIO_PIN_7, GPIO_MODE_OUT_PP_HIGH_FAST);
    GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST);
    GPIO_Init(GPIOC, GPIO_PIN_6, GPIO_MODE_IN_FL_NO_IT);

}