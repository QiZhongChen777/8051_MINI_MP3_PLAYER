#ifndef __Serial_Function_H__
#define __Serial_Function_H__

// void UART_Init(unsigned int BPS);						//��C���Ҥ��j�v�]�w
//unsigned char UART_GetCh();									//�����r��
void UART_PutCh(unsigned char);							//�o�e�r��
void UART_PutStr_Linefeed(unsigned char);		//�o�e�r��ô���
void UART_PutStr(unsigned char);							//�o�e�r��

#endif