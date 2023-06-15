#include<AT89X51.h>
#include<stdio.h>
#include "LCD_Function.h"
#include "MP3_Function.h"
#define DATA_BUS P0
sbit RS=P2^0;
sbit RW=P2^1;
sbit EN=P2^2;

void LCD_reset()   
{
	LCD_Cmd(0x38);    
	LCD_Cmd(0x0c);  
	LCD_Cmd(0x06); 
	LCD_Cmd(0x01); 
	LCD_Cmd(0x02); 
}
///////////////////////////////////////////////////////////
void LCD_senddata(unsigned char Data)   
{
	DATA_BUS = Data;  
	RS=1; RW=0; EN=1;
	Delay_25us(2);
	EN=0;           
}
///////////////////////////////////////////////////////////
void LCD_Cmd(unsigned char Cmd)     
{
	DATA_BUS = Cmd;  
	RS=0; RW=0; EN=1; 
	Delay_25us(2);     
	EN=0;           
}
///////////////////////////////////////////////////////////
void LCD_write_string(unsigned char *str)
{
  while(*str != '\0') 
	{
    LCD_senddata(*str++);
  }
}

///////////////////////////////////////////////////////////
void Delay_25us(unsigned int n)                   
{
	unsigned int i,j;
	for (i=0; i < n; i++)
					for (j=0; j < 3; j++) ;      
}
//======================================================

void LCD_Clear_Display()        
{
	LCD_Cmd(0x01);         
}

//======================================================

void LCD_GotoXY(unsigned int row,unsigned int col)
{
	if (row == 0) LCD_Cmd(0x80+col);
	else LCD_Cmd(0xC0+col);
}

//////////////////////////////////////////////////////////////////
void LCD_Volume_Sign(unsigned int row,unsigned int col)
{
	LCD_Cmd(0X48);
	LCD_senddata(0X01);	
	LCD_Cmd(0X49);
	LCD_senddata(0X03);	
	LCD_Cmd(0X4A);
	LCD_senddata(0X07);	
	LCD_Cmd(0X4B);
	LCD_senddata(0X1F);	
	LCD_Cmd(0X4C);
	LCD_senddata(0X1F);	
	LCD_Cmd(0X4D);
	LCD_senddata(0X07);	
	LCD_Cmd(0X4E);
	LCD_senddata(0X03);	
	LCD_Cmd(0X4F);
	LCD_senddata(0X01);
	
	LCD_GotoXY(row,col);
	Delay_25us(1);
	LCD_senddata(0x01);
}

void LCD_Music_Sign(unsigned int row,unsigned int col)
{
	LCD_Cmd(0X40);
	LCD_senddata(0X01);	
	LCD_Cmd(0X41);
	LCD_senddata(0X03);	
	LCD_Cmd(0X42);
	LCD_senddata(0X05);	
	LCD_Cmd(0X43);
	LCD_senddata(0X09);	
	LCD_Cmd(0X44);
	LCD_senddata(0X09);	
	LCD_Cmd(0X45);
	LCD_senddata(0X0B);	
	LCD_Cmd(0X46);
	LCD_senddata(0X1B);	
	LCD_Cmd(0X47);
	LCD_senddata(0X18);
	
	LCD_GotoXY(row,col);
	Delay_25us(1);
	LCD_senddata(0x00);
}

void LCD_Single_Sign(unsigned int row,unsigned int col)
{	
	LCD_GotoXY(row,col);
	Delay_25us(1);
	LCD_senddata(0x02);
	
	LCD_Cmd(0X58);
	LCD_senddata(0X00);	
	LCD_Cmd(0X59);
	LCD_senddata(0X04);	
	LCD_Cmd(0X5A);
	LCD_senddata(0X06);	
	LCD_Cmd(0X5B);
	LCD_senddata(0X1f);	
	LCD_Cmd(0X5C);
	LCD_senddata(0X06);	
	LCD_Cmd(0X5D);
	LCD_senddata(0X04);	
	LCD_Cmd(0X5E);
	LCD_senddata(0X00);	
	LCD_Cmd(0X5F);
	LCD_senddata(0X00);
	
	LCD_GotoXY(row,col+1);
	Delay_25us(1);
	LCD_senddata(0x03);
	
	LCD_Cmd(0X60);
	LCD_senddata(0X00);	
	LCD_Cmd(0X61);
	LCD_senddata(0X00);	
	LCD_Cmd(0X62);
	LCD_senddata(0X04);	
	LCD_Cmd(0X63);
	LCD_senddata(0X0c);	
	LCD_Cmd(0X64);
	LCD_senddata(0X04);	
	LCD_Cmd(0X65);
	LCD_senddata(0X04);	
	LCD_Cmd(0X66);
	LCD_senddata(0X0e);	
	LCD_Cmd(0X67);
	LCD_senddata(0X00);
	
	LCD_GotoXY(row,col+2);
	Delay_25us(1);
	LCD_senddata(0x04);
	
	LCD_GotoXY(row+1,col);
	Delay_25us(1);
	LCD_senddata(0x05);

	LCD_GotoXY(row+1,col+1);
	Delay_25us(1);
	LCD_senddata(0x06);	
	
	LCD_GotoXY(row+1,col+2);
	Delay_25us(1);
	LCD_senddata(0x07);
}




void LCD_PlayAll_Sign(unsigned int row,unsigned int col)
{
	LCD_Cmd(0X50);
	LCD_senddata(0X00);	
	LCD_Cmd(0X51);
	LCD_senddata(0X00);	
	LCD_Cmd(0X52);
	LCD_senddata(0X00);	
	LCD_Cmd(0X53);
	LCD_senddata(0X01);	
	LCD_Cmd(0X54);
	LCD_senddata(0X02);	
	LCD_Cmd(0X55);
	LCD_senddata(0X04);	
	LCD_Cmd(0X56);
	LCD_senddata(0X08);	
	LCD_Cmd(0X57);
	LCD_senddata(0X08);
	
	LCD_GotoXY(row,col);
	Delay_25us(1);
	LCD_senddata(0x02);
	
	LCD_Cmd(0X58);
	LCD_senddata(0X00);	
	LCD_Cmd(0X59);
	LCD_senddata(0X00);	
	LCD_Cmd(0X5A);
	LCD_senddata(0X00);	
	LCD_Cmd(0X5B);
	LCD_senddata(0X1f);	
	LCD_Cmd(0X5C);
	LCD_senddata(0X00);	
	LCD_Cmd(0X5D);
	LCD_senddata(0X00);	
	LCD_Cmd(0X5E);
	LCD_senddata(0X00);	
	LCD_Cmd(0X5F);
	LCD_senddata(0X00);
	
	LCD_GotoXY(row,col+1);
	Delay_25us(1);
	LCD_senddata(0x03);
	
	LCD_Cmd(0X60);
	LCD_senddata(0X00);	
	LCD_Cmd(0X61);
	LCD_senddata(0X10);	
	LCD_Cmd(0X62);
	LCD_senddata(0X18);	
	LCD_Cmd(0X63);
	LCD_senddata(0X1c);	
	LCD_Cmd(0X64);
	LCD_senddata(0X18);	
	LCD_Cmd(0X65);
	LCD_senddata(0X10);	
	LCD_Cmd(0X66);
	LCD_senddata(0X00);	
	LCD_Cmd(0X67);
	LCD_senddata(0X00);
	
	LCD_GotoXY(row,col+2);
	Delay_25us(1);
	LCD_senddata(0x04);
	
	LCD_Cmd(0X68);
	LCD_senddata(0X00);	
	LCD_Cmd(0X69);
	LCD_senddata(0X01);	
	LCD_Cmd(0X6A);
	LCD_senddata(0X03);	
	LCD_Cmd(0X6B);
	LCD_senddata(0X07);	
	LCD_Cmd(0X6C);
	LCD_senddata(0X03);	
	LCD_Cmd(0X6D);
	LCD_senddata(0X01);	
	LCD_Cmd(0X6E);
	LCD_senddata(0X00);	
	LCD_Cmd(0X6F);
	LCD_senddata(0X00);
	
	LCD_GotoXY(row+1,col);
	Delay_25us(1);
	LCD_senddata(0x05);
	
	LCD_Cmd(0X70);
	LCD_senddata(0X00);	
	LCD_Cmd(0X71);
	LCD_senddata(0X00);	
	LCD_Cmd(0X72);
	LCD_senddata(0X00);	
	LCD_Cmd(0X73);
	LCD_senddata(0X1f);	
	LCD_Cmd(0X74);
	LCD_senddata(0X00);	
	LCD_Cmd(0X75);
	LCD_senddata(0X00);	
	LCD_Cmd(0X76);
	LCD_senddata(0X00);	
	LCD_Cmd(0X77);
	LCD_senddata(0X00);
	
	LCD_GotoXY(row+1,col+1);
	Delay_25us(1);
	LCD_senddata(0x06);
	
	LCD_Cmd(0X78);
	LCD_senddata(0X02);	
	LCD_Cmd(0X79);
	LCD_senddata(0X02);	
	LCD_Cmd(0X7A);
	LCD_senddata(0X04);	
	LCD_Cmd(0X7B);
	LCD_senddata(0X18);	
	LCD_Cmd(0X7C);
	LCD_senddata(0X00);	
	LCD_Cmd(0X7D);
	LCD_senddata(0X00);	
	LCD_Cmd(0X7E);
	LCD_senddata(0X00);	
	LCD_Cmd(0X7F);
	LCD_senddata(0X00);
	
	LCD_GotoXY(row+1,col+2);
	Delay_25us(1);
	LCD_senddata(0x07);
}



