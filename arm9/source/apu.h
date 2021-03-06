/***********************************************************/
/* This source is part of SNEmulDS                         */
/* ------------------------------------------------------- */
/* (c) 1997-1999, 2006-2007 archeide, All rights reserved. */
/***********************************************************/
/*
This program is free software; you can redistribute it and/or 
modify it under the terms of the GNU General Public License as 
published by the Free Software Foundation; either version 2 of 
the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
GNU General Public License for more details.
*/

#ifndef __apu_h__
#define __apu_h__

#include "common.h"
/*
struct s_apu
{
#if 0	
  uchar		*MEM;
  uchar		DSP[0x80];
  int		Port1, Port2, Port3, Port4;
  uchar		CONTROL, DSP_address;

  uint32	T0_LATCH, T1_LATCH, T2_LATCH;

// sound
  int		MasterVolume, MasterPanning;
  uchar		DSP_channel[8];

//sample
  uchar		sample_nb[256];
  ushort	CheckSum[256], Sample_len[256];
  uchar		sample_cnt;
  uchar         need_decode[8];
  short         samp[0x8000];

// voice 
  long		Voice_pos[8], old_Voice_pos[8];
  uchar		Voice_envx[8], Voice_start_envx[8];
  uchar		Voice_mode[8];
  uchar		Voice_volume[8];
  uchar  	Voice_SL[8];
  ushort	Voice_AR[8], Voice_DR[8], Voice_SR[8];
  int           Voice_envpos[8];
#endif  

  int	    skipper_cnt1;
  int	    skipper_cnt2;
  int	    skipper_cnt3;
  int	    skipper_cnt4;
  
  int		counter;
};

struct s_apu2
{
// timers
  uint32    T0, T1, T2;
  uint32 	TIM0, TIM1, TIM2;
  uint32	CNT0, CNT1, CNT2;
};

#define PORT_SNES_TO_SPC ((volatile uint8*)memUncached((void *)0x3000000-8))
#define PORT_SPC_TO_SNES ((volatile uint8*)memUncached((void *)0x3000000-4))

#define APU_RAM_ADDRESS ((uint8*)memUncached((void *)0x3000000-0x12000))
#define APU_ADDR_CNT ((volatile uint32*)memUncached((void *)0x3000000-60))
#define APU_ADDR_CMD ((volatile uint32*)memUncached((void *)0x3000000-16))
#define APU_ADDR_BLK ((volatile uint32*)memUncached((void *)0x3000000-24))
#define APU_ADDR_BLKP ((volatile uint8*)memUncached((void *)0x3000000-24))
*/

#define APU_RAM_ADDRESS     ((uint8*)(0x6010000))

#endif


#ifdef __cplusplus
extern "C" {
#endif

//extern struct s_apu	APU;
//extern struct s_apu2 *APU2;

extern void	APU_reset();
extern void	APU_nice_reset();
extern void	APU_pause();
extern void	APU_stop();
extern void	APU_playSpc();
extern void	APU_saveSpc();
extern void	APU_loadSpc();
extern void	APU_clear();
extern void APU_playSong(uint8 *data, int size);
extern void APU_command(uint32 command);

#ifdef __cplusplus
}
#endif
