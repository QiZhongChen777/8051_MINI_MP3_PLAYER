#include<AT89X51.h>
#define Key_one 0x01					
#define Key_two 0x02
#define Key_three 0x03
#define Key_four 0x04		
#define Key_five 0x05	
#define Key_six 0x06
#define Key_seven 0x07	
#define Key_eight 0x08
#define Key_night 0x09

sbit SW_1 = P3^4;
sbit SW_2 = P3^5;
sbit SW_3 = P3^6;
sbit SW_4 = P3^7;

void ReadKey(unsigned char* KeyRam)
{
	(*KeyRam) = 0;
	if((SW_1 == 0) && (SW_2 != 0) && (SW_3 != 0)&& (SW_4 != 0))
	{	
		(*KeyRam) = 1;
	}
	else if((SW_2 == 0) && (SW_1 != 0))
	{
		(*KeyRam) = 2;
	}
	else if((SW_3 == 0) && (SW_1 != 0))
	{
		(*KeyRam) = 3;
	}
	else if((SW_4 == 0) && (SW_1 != 0))
	{
		(*KeyRam) = 4;
	}
	else if((SW_1 == 0) && (SW_4 == 0))
	{
		(*KeyRam) = 5;
	}
}

unsigned char GetKey(unsigned char* KeyCode,unsigned char* KeyRam,unsigned char* PreKeyRam,unsigned char* KeyCnt,unsigned char* NoKeyCnt)	
{
	if((*KeyRam) != 0)
	{
		if((*KeyRam) == (*PreKeyRam))
		{
			(*NoKeyCnt) = 0;
			(*KeyCnt)++;
			if((*KeyCnt) == 1)
			{
				switch((*KeyRam))
				{
					case 0x01:	
						(*KeyCode) = Key_one;	
						break;
					case 0x02:
						(*KeyCode) = Key_two;	
						break;
					case 0x03:	
						(*KeyCode) = Key_three;	
						break;
					case 0x04:	
						(*KeyCode) = Key_four;		
						break;
					case 0x05:	
						(*KeyCode) = Key_night;		
						break;
					
					default:
						break;
				}
			}
			if((*KeyCnt) == 15)
			{
				switch((*KeyRam))
				{
					case 0x01: (*KeyCode) = Key_five; break;
 					case 0x02: (*KeyCode) = Key_six; break;
 					case 0x03: (*KeyCode) = Key_seven; break;
 					case 0x04: (*KeyCode) = Key_eight; break;
					case 0x05: (*KeyCode) = Key_night; break;

					default:
						break;
				}	
			}
			if((*KeyCnt) > 200)
			{
				(*KeyCnt) = 200;
			}
		}
		else
		{
			(*PreKeyRam)=(*KeyRam);			
		}		
	}
	else
	{
		(*NoKeyCnt)++;
		if((*NoKeyCnt) > 2)
		{
			(*PreKeyRam)=0;
			(*KeyCnt)=0;
			(*NoKeyCnt)=0;
			switch((*KeyCode))
			{
				case 0x01:	
					(*KeyCode) = Key_one;
					(*NoKeyCnt)=5;
					break;
				case 0x02:
					(*KeyCode) = Key_two;
					(*NoKeyCnt)=5;
					break;
				case 0x03:	
					(*KeyCode) = Key_three;
					(*NoKeyCnt)=5;
					break;
				case 0x04:	
					(*KeyCode) = Key_four;
					(*NoKeyCnt)=5;
					break;
				case 0x05:	
					(*KeyCode) = Key_night;
					(*NoKeyCnt)=5;				
						break;
				default:
					(*KeyCode)=0;
					break;
			}
		}		
	}
	return (*KeyCode);
}
