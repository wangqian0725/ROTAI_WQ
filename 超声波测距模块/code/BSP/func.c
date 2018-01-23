#include "main.h"

/***********************************************************************
*   函 数 名: EIGHT
*   功能说明: 发射8个40KHz方波
*   形    参：无
*   返 回 值: 无
***********************************************************************/
void EIGHT(void)  
{
	unsigned char i;
	sim();  //总中断关闭
	TPWR_L;  //232 供电
	delay_us(95);  //耗时95us
        
        /*发送脉冲同时应该打开计时器2，这样测量更精准？*/
	TIM2_Cmd(ENABLE);//打开定时器2
        
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
	/*!!!  这里涉及到MAX232从接收信号到放大信号的时间，
        量更加精准，需要根据datasheet加入等待时间*/
	delay_us(2);  //1.5 - 3.0 us等待脉冲发送完成
	
	TPWR_H;//232 断电
	rim();  //总中断开启
}

/***********************************************************************
*   函 数 名: get_data
*   功能说明: 进行一次测距
*   形    参：无
*   返 回 值: 距离值
***********************************************************************/
u16 get_data(void)
{
    u16 time_data;
    u16 length_data;
    EIGHT();//发送脉冲
    BitStatus bit_status;
    bit_status = GPIO_ReadInputPin(GPIOC, GPIO_PIN_6);
    if (bit_status == SET)  //SET or RESET
    {
      time_data = TIM2_GetCounter();//1us记一次 获取时间us
      TIM2_Cmd(DISABLE);//关闭定时器
    };
    length_data = time_data *10/58;//单位mm
    return length_data;
      
}

