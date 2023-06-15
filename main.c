#include<AT89X51.h>
#include<stdio.h>
#include<stdlib.h>
#include "Button_Function.h"
#include "LCD_Function.h"
#include "Serial_Function.h"
#include "MP3_Function.h"
#define DATA_BUS P0
#define Start_Volume 0x0F
#define Key_one 0x01					
#define Key_two 0x02
#define Key_three 0x03
#define Key_four 0x04
#define Key_five 0x05
#define Key_six 0x06
#define Key_seven 0x07	
#define Key_eight 0x08
#define Key_night 0x09
unsigned char KeyCode = 0;
unsigned char KeyRam = 0;				
unsigned char PreKeyRam = 0;		
unsigned char KeyCnt = 0;				
unsigned char NoKeyCnt = 0;			
unsigned char Key_Value = 0;
unsigned char T30ms_cnt = 3;
unsigned char Play_Status = 0,Volume = 0;
sbit SW_1 = P3^4;
sbit SW_2 = P3^5;
sbit SW_3 = P3^6;
sbit SW_4 = P3^7;
sbit DS_2 = P1^0;
sbit DS_3 = P1^1;
sbit DS_4 = P1^2;
sbit DS_5 = P1^3;
bit UART_S = 0;									//串列中斷開始接收
bit UART_E = 0;									//串列中斷結束接收
bit UART_T = 0;	
// PS = 0XBC;
char VolumeString[10]={0};
char TEST[]="MP3_PLAYER_VER1";
unsigned char FeedBack_line[10]={0x7E,0xFF,0x06};
unsigned char Data_cnt = 0;
void ConvertVolumeToString(unsigned char Volume, char *VolumeString);
void MP3_Interface();
void MP3_Volume();
void Key_Function();
/////////////////////////////////////////////////////////////////////////////////////////////////
void main()
{
	LCD_reset();
	Delay_ms(5);
	LCD_write_string(TEST);		
	
	TMOD = 0x21;
	PS = 1;	
	EA = 1;	ES = 1;
	SCON = 0x50;             
	TH1 = 256 - (28800/9600); 
	TR1 = 1;
	TL0 = (65536 - 10000) % 256;
	TH0 = (65536 - 10000) / 256;
	TR0 = 1;
	ET0 = 1;	
	Delay_ms(1000);
	if(FeedBack_line[3] == 0x3f)
	{
		if(FeedBack_line[6] == 0x01)
		{
			LCD_GotoXY(1,0);
			LCD_write_string("USB:ON");	
		}
		else if(FeedBack_line[6] == 0x02)
		{
			LCD_GotoXY(1,0);
			LCD_write_string("SD :ON");
		}
		else if(FeedBack_line[6] == 0x03)
		{
			LCD_GotoXY(1,0);
			LCD_write_string("USB/SD:ON");
		}
	}	
	
	MP3_init(Start_Volume);
	Get_Play_Status();	
	MP3_Volume();	
	LCD_Clear_Display();
	Delay_ms(10);	
	LCD_PlayAll_Sign(0,0);
	while(1)
	{
		Key_Function();
		MP3_Interface();
	}
}

void timer0_isr() interrupt 1												
{
	TL0 = (65536 - 10000) % 256;
	TH0 = (65536 - 10000) / 256;
	if(--T30ms_cnt == 0 )
	{	
		T30ms_cnt = 3;
		ReadKey(&KeyRam);
		Key_Value = GetKey(&KeyCode,&KeyRam,&PreKeyRam,&KeyCnt,&NoKeyCnt);		
	}
}

void Serial(void) interrupt 4
{
	if(RI)                         
	{
		RI = 0;                       
		if(SBUF == 0x7E)
		{
			UART_S = 1;
			FeedBack_line[Data_cnt] = SBUF;
			Data_cnt++;
		}
		else if(UART_S && !UART_E)
		{
			if(SBUF == 0xEF)
			{	
				UART_E = 1;
				if(FeedBack_line[3] == 0x43)
				{
					Volume = FeedBack_line[6];		
				}
				if(FeedBack_line[3] == 0x42)
				{
					Play_Status = FeedBack_line[6];		
				}
			}
			FeedBack_line[Data_cnt] = SBUF;
			Data_cnt++;
		}
		else
		{
			UART_S = 0;
			UART_E = 0;
			Data_cnt = 0; 
		}
	}
	else
	{
		RI = 1;		
	}
}



void ConvertVolumeToString(unsigned char Volume, char *VolumeString)
{
    unsigned char temp = Volume;
    unsigned char digitCount = 0;
    do 
		{
			digitCount++;
			temp /= 10;
    }while (temp != 0);
    VolumeString[digitCount] = '\0';    
    while (digitCount > 0) 
		{
			digitCount--;
			VolumeString[digitCount] = '0' + (Volume % 10);
			Volume /= 10;
    }
}

void MP3_Interface()
{
		LCD_Music_Sign(0,4);
		if((Play_Status) == 0x01)
		{
			LCD_write_string(":Playing");			
		}
		else if((Play_Status) == 0x02)
		{
			LCD_write_string(":Paused ");
		//			LCD_senddata(0x10);
		}
		else
		{
			LCD_write_string(":Stopped");			
		}
		LCD_Volume_Sign(1,4);
		LCD_write_string(":");
		ConvertVolumeToString(Volume,VolumeString);
		LCD_write_string(VolumeString);
		if(Volume < 10)
		{
			LCD_senddata(0x10);
		}
}


void MP3_Volume()
{
	GetVolume();
	ConvertVolumeToString(Volume,VolumeString);
}


void Key_Function()
{
	if(Key_Value != 0)
	{		
		switch(Key_Value)
		{
			case Key_one:
				
				Play();
				Execute_CMD(0x42,0,0);
				Key_Value = 0;
				KeyCode = 0;
				break;		
								
			case Key_two:
									
				Pause();
				Execute_CMD(0x42,0,0);
				Key_Value = 0;
				KeyCode = 0;
				break;
				
			case Key_three:
				
				AddVolume();
				Execute_CMD(0x43,0,0);
				Key_Value = 0;
				KeyCode = 0;
				break;
				
			case Key_four:
				
				SubVolume();
				Execute_CMD(0x43,0,0);
				Key_Value = 0;
				KeyCode = 0;
				break;
			
			case Key_five:
				
				PlayNext();
				Play();
				Execute_CMD(0x42,0,0);
				Key_Value = 0;
				KeyCode = 0;
				break;
			
			case Key_six:
				
				PlayPrev();
				Play();
				Execute_CMD(0x42,0,0);
				Key_Value = 0;
				KeyCode = 0;
				break;
			
			case Key_seven:
								
				Turn_On_Single_Repeat();
				LCD_Single_Sign(0,0);
				Key_Value = 0;
				break;
			
			case Key_eight:				
				
				Turn_Off_Single_Repeat();
				PlayAll();
				LCD_PlayAll_Sign(0,0);
				Key_Value = 0;
				break;
			
			case Key_night:
				
				Stop();
				Execute_CMD(0x42,0,0);
				Key_Value = 0;
				KeyCode = 0;
				break;	
			
			default:
				
				Key_Value = 0;
				KeyCode = 0;
				break;
		}
	}
}

	