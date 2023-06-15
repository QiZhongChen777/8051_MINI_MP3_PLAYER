#include<AT89X51.h>
#include<stdio.h>
#include "Button_Function.h"
#include "LCD_Function.h"
#include "MP3_Function.h"

#define Key_one 0x01					
#define Key_two 0x02
#define Key_three 0x03
#define Key_four 0x04
#define Key_five 0x05
#define Key_six 0x06
#define Key_seven 0x07	
#define Key_eight 0x08
#define Key_night 0x09

//void Key_Function(unsigned char *Key_Value,unsigned char *KeyCode)
//{
//	if(*Key_Value != 0)
//	{
//		if(Key_Value == Key_seven || Key_Value == Key_eight)
//		{
//			ES = 0;
//		}
//		else
//		{
//			ES = 1;
//		}
//		
//		switch(*Key_Value)
//		{
//			case Key_one:
//				
//				Play();
//				Execute_CMD(0x42,0,0);
//				*Key_Value = 0;
//				*KeyCode = 0;
//				break;		
//								
//			case Key_two:
//									
//				Pause();
//				Execute_CMD(0x42,0,0);
//				*Key_Value = 0;
//				*KeyCode = 0;
//				break;
//				
//			case Key_three:
//				
//				AddVolume();
//				Execute_CMD(0x43,0,0);
//				*Key_Value = 0;
//				*KeyCode = 0;
//				break;
//				
//			case Key_four:
//				
//				SubVolume();
//				Execute_CMD(0x43,0,0);
//				*Key_Value = 0;
//				*KeyCode = 0;
//				break;
//			
//			case Key_five:
//				
//				PlayNext();
//				Play();
//				Execute_CMD(0x42,0,0);
//				*Key_Value = 0;
//				*KeyCode = 0;
//				break;
//			
//			case Key_six:
//				
//				PlayPrev();
//				Play();
//				Execute_CMD(0x42,0,0);
//				*Key_Value = 0;
//				*KeyCode = 0;
//				break;
//			
//			case Key_seven:
//				
//				AddVolume();
//				*Key_Value = 0;
//				break;
//			
//			case Key_eight:
//				
//				SubVolume();
//				*Key_Value = 0;
//				break;
//			
//			case Key_night:
//				
//				Stop();
//				Execute_CMD(0x42,0,0);
//				*Key_Value = 0;
//				*KeyCode = 0;
//				break;	
//			
//			default:
//				
//				*Key_Value = 0;
//				*KeyCode = 0;
//				break;
//		}
//	}
//}