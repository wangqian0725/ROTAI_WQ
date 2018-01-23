#include "main.h"

/***********************************************************************
*   �� �� ��: EIGHT
*   ����˵��: ����8��40KHz����
*   ��    �Σ���
*   �� �� ֵ: ��
***********************************************************************/
void EIGHT(void)  
{
	unsigned char i;
	sim();  //���жϹر�
	TPWR_L;  //232 ����
	delay_us(95);  //��ʱ95us
        
        /*��������ͬʱӦ�ô򿪼�ʱ��2��������������׼��*/
	TIM2_Cmd(ENABLE);//�򿪶�ʱ��2
        
	for(i=0;i<7;i++)
	{
		T1_H;
		T2_L;
		delay_us(12);
		
		T1_L;
		T2_H;
		delay_us(11);
	}

	T1_H;
	T2_L;
	delay_us(12);
		
	T1_L;
	T2_H;
	/*!!!  �����漰��MAX232�ӽ����źŵ��Ŵ��źŵ�ʱ�䣬
        �����Ӿ�׼����Ҫ����datasheet����ȴ�ʱ��*/
	delay_us(2);  //1.5 - 3.0 us�ȴ����巢�����
	
	TPWR_H;//232 �ϵ�
	rim();  //���жϿ���
}

/***********************************************************************
*   �� �� ��: get_data
*   ����˵��: ����һ�β��
*   ��    �Σ���
*   �� �� ֵ: ����ֵ
***********************************************************************/
u16 get_data(void)
{
    u16 time_data;
    u16 length_data;
    EIGHT();//��������
    BitStatus bit_status;
    bit_status = GPIO_ReadInputPin(GPIOC, GPIO_PIN_6);
    if (bit_status == SET)  //SET or RESET
    {
      time_data = TIM2_GetCounter();//1us��һ�� ��ȡʱ��us
      TIM2_Cmd(DISABLE);//�رն�ʱ��
    };
    length_data = time_data *10/58;//��λmm
    return length_data;
      
}

