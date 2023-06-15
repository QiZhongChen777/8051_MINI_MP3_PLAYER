#include<AT89X51.h>
#include<stdio.h>
#include<string.h>
#include "Serial_Function.h"
#include "MP3_Function.h"
#include "LCD_Function.h"

#define Start_Byte			0x7E
#define Version_Byte		0xFF
#define Command_Length	0x06
#define Acknowledge			0x00
#define End_Byte				0xEF

static unsigned char Command_line[10]={0};

void Execute_CMD(unsigned char CMD, unsigned char Par1, unsigned char Par2)
{
	unsigned char k;
	unsigned int checksum = 0;
	Command_line[0] = Start_Byte;
	
	Command_line[1] = Version_Byte;
	Command_line[2] = Command_Length;
	Command_line[3] = CMD;
	Command_line[4] = Acknowledge;
	Command_line[5] = Par1;
	Command_line[6] = Par2;	
	Command_line[7] = End_Byte;
	for(k=0;k<8;k++)
	{
		UART_PutCh(Command_line[k]);
	}
}
void Play()
{
  Execute_CMD(0x0D,0,0);  
  Delay_ms(300);
}

void PlayNext()
{
	Execute_CMD(0x01,0,0);  
  Delay_ms(300);	
}

void PlayPrev()
{
	Execute_CMD(0x02,0,0);  
  Delay_ms(300);	
}


void Pause()
{
  Execute_CMD(0x0E,0,0);  
	Delay_ms(300);
}

void Stop()
{
  Execute_CMD(0x16,0,0);  
	Delay_ms(300);
}


void AddVolume()
{
  Execute_CMD(0x04,0,0);
  Delay_ms(300);
}

void SubVolume()
{
  Execute_CMD(0x05,0,0);
  Delay_ms(300);
}

void PlayAll()
{
  Execute_CMD(0x11,0,1);  
  Delay_ms(300);
}


void Set_Random()
{
  Execute_CMD(0x18,0,0); 
  Delay_ms(300);
}


void SetVolume(unsigned char volume)
{
  Execute_CMD(0x06, 0, volume); // Set the volume (0x00~0x1E)
  Delay_ms(300);
}

//////////////////////////////////////////////////////////////////////
void GetVolume()
{
	Execute_CMD(0x43,0,0);
	Delay_ms(300);
}

void Get_Play_Status() 
{
	Execute_CMD(0x42,0,0);
	Delay_ms(300);
}

void Turn_On_Single_Repeat()
{
  Execute_CMD(0x19,0,0); 
  Delay_ms(500);
}

void Turn_Off_Single_Repeat()
{
  Execute_CMD(0x19,0,1); 
  Delay_ms(500);
}


//////////////////////////////////////////////////////////////////////

void MP3_init(unsigned char volume)
{	
	SetVolume(volume);
	PlayAll();
	Play();
	Pause();
}

void Delay_ms(int n)
{
	unsigned int i,j;
	for (i = 0;i < n;i++)
		for (j = 0;j < 120;j++);  
}