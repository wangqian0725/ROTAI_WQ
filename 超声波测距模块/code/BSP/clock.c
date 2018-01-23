#include "main.h"

/***********************************************************************
*   �� �� ��: clk_init
*   ����˵��: ʱ�ӳ�ʼ���������л����ⲿ4Mʱ��
*   ��    �Σ���
*   �� �� ֵ: ��
***********************************************************************/
void clk_init(void)
{
    CLK_DeInit();//ʱ����ؼĴ�����ʼ��
    CLK_HSECmd(ENABLE);//ʹ���ⲿ����ʱ��
    CLK_ClockSwitchCmd(ENABLE);//ʹ��ʱ���л�����
    ErrorStatus clk_return_status;//�Զ��л����ⲿʱ�ӣ��ر��жϣ��ر�ԭʱ��
    clk_return_status = CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSE, DISABLE, CLK_CURRENTCLOCKSTATE_DISABLE);
    if (clk_return_status == ERROR)  //SUCCESS or ERROR
    {
      clk_init(); //�л�ʧ�����³�ʼ��
    };
}