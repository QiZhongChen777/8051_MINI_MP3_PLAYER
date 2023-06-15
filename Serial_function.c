#include<AT89X51.h>
#include "Serial_Function.h"

// void UART_Init(unsigned int BPS) 
// {
// 	SCON = 0x50; 
// 	TMOD = 0x20;               
// 	TH1 = 256 - (28800/BPS); 
// 	TL1 = 256 - (28800/BPS); 
// 	TR1 = 1;
// }
///////////////////////////////////////////////////////////
void delay_1ms(int n)
{
	unsigned int i,j;
	for (i=0; i < n; i++)
	for (j=0; j < 120; j++) ;
}
///////////////////////////////////////////////////////////
void UART_PutStr_Linefeed(unsigned char *str) 
{
	while (*str != '\0') 
	{
		SBUF = *str++;
		while( TI == 0 ); 
		TI = 0;
	}
	UART_PutCh(0x0A);
	UART_PutCh(0x0D);
}
///////////////////////////////////////////////////////////
void UART_PutStr(unsigned char *str) 
{
	while (*str != '\0') 
	{
		SBUF = *str++;
		while( TI == 0 ); 
		TI = 0;
	}
}
///////////////////////////////////////////////////////////
unsigned char UART_GetCh()
{
	unsigned char UART_DATA = 0;	
	while( RI == 0);
	RI = 0;
	UART_DATA = SBUF; 
	return UART_DATA;
}
///////////////////////////////////////////////////////////
void UART_PutCh(unsigned char UART_DATA) 
{
	SBUF = UART_DATA;
	while( TI == 0 ); 
	TI = 0; 
}
