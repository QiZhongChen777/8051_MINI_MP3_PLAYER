#ifndef __LCD_Function_H__
#define __LCD_Function_H__

void LCD_reset();
void LCD_senddata(unsigned char Data);			//show char
void LCD_write_string(unsigned char *str);	//show string
void LCD_Cmd(unsigned char Cmd);
void LCD_Clear_Display();								//²M°£¿Ã¹õ
void LCD_GotoXY(unsigned int row,unsigned int col);
void LCD_Music_Sign(unsigned int row,unsigned int col);
void LCD_Volume_Sign(unsigned int row,unsigned int col);
void LCD_Single_Sign(unsigned int row,unsigned int col);
void LCD_PlayAll_Sign(unsigned int row,unsigned int col);



void Delay_25us(unsigned int n);

#endif
