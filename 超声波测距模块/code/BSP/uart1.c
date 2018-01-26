#include "main.h"

/*********************************************************************************
*   �� �� ��: UART1_Congfiguration
*   ����˵��: UART1 ���ú���
*   ��    �Σ���
*   �� �� ֵ: ��
*********************************************************************************/
void UART1_Congfiguration(void)
{
    //���ô��ڲ���Ϊ��������115200��8λ����λ��1λֹͣλ����У�飬��ֹͬ�����䣬������շ���
    UART1_Init((u32)9600,UART1_WORDLENGTH_8D,UART1_STOPBITS_1,UART1_PARITY_NO,UART1_SYNCMODE_CLOCK_DISABLE,UART1_MODE_TXRX_ENABLE);
    UART1_ITConfig(UART1_IT_RXNE_OR, ENABLE);//ʹ�ܽ����ж�
    UART1_Cmd(ENABLE);//ʹ��UART1        
}

/*********************************************************************************
*   �� �� ��: UART1_Send_Byte
*   ����˵��: UART1�������ݺ���
*   ��    �Σ�u8 byte  һ�η���һ���ֽ�
*   �� �� ֵ: ��
*********************************************************************************/
void UART1_Send_Byte(u8 byte)
{
    UART1_SendData8(byte);//UART1����8λ����
    while(UART1_GetFlagStatus(UART1_FLAG_TXE)==RESET);//�ȴ��������
}