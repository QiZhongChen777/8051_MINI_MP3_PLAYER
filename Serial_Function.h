#ifndef __Serial_Function_H__
#define __Serial_Function_H__

// void UART_Init(unsigned int BPS);						//串列環境及鮑率設定
//unsigned char UART_GetCh();									//接收字元
void UART_PutCh(unsigned char);							//發送字元
void UART_PutStr_Linefeed(unsigned char);		//發送字串並換行
void UART_PutStr(unsigned char);							//發送字串

#endif