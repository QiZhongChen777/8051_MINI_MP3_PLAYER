#ifndef __MP3_Function_H__
#define __MP3_Function_H__

void Execute_CMD(unsigned char CMD, unsigned char Par1, unsigned char Par2);
void Delay_ms(int n);
void Play();
void PlayNext();
void PlayPrev();
void SetVolume(unsigned char volume);
void Pause();
void Stop();
void AddVolume();
void SubVolume();
void PlayAll();
void Set_Random();

void GetVolume();
void Get_Play_Status();

void Turn_On_Single_Repeat();
void Turn_Off_Single_Repeat();

void MP3_init(unsigned char volume);

#endif