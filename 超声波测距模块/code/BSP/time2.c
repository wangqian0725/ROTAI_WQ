#include "main.h"

/***********************************************************************
*   �� �� ��: time2_init
*   ����˵��: ��ʱ��2��ʼ������
*   ��    �Σ���
*   �� �� ֵ: ��
***********************************************************************/
void time2_init(void)
{
   
    TIM2_DeInit();//ʱ�ӼĴ�����ʼ��
    TIM2_TimeBaseInit(TIM2_PRESCALER_4, 0xFFFF);//4��Ƶ
    TIM2_ARRPreloadConfig(ENABLE);//ʹ���Զ���װ
    TIM2_ITConfig(TIM2_IT_UPDATE , ENABLE);//���ݸ����ж�

}