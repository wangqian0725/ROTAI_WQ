#include "main.h"

/***********************************************************************
*   函 数 名: clk_init
*   功能说明: 时钟初始化函数，切换到外部4M时钟
*   形    参：无
*   返 回 值: 无
***********************************************************************/
void clk_init(void)
{
    CLK_DeInit();//时钟相关寄存器初始化
    CLK_HSECmd(ENABLE);//使能外部高速时钟
    CLK_ClockSwitchCmd(ENABLE);//使能时钟切换功能
    ErrorStatus clk_return_status;//自动切换到外部时钟，关闭中断，关闭原时钟
    clk_return_status = CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSE, DISABLE, CLK_CURRENTCLOCKSTATE_DISABLE);
    if (clk_return_status == ERROR)  //SUCCESS or ERROR
    {
      clk_init(); //切换失败重新初始化
    };
}