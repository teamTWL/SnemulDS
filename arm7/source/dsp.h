#ifndef apu_snes
#define apu_snes
struct _DspChannel {
    int sampleSpeed;
    int samplePos;
    int envCount;
    int envSpeed;
    s16 prevDecode[4];
    s16 decoded[16];
    u16 decaySpeed;
    u16 sustainSpeed;
    s16 envx;
    s16 prevSamp1, prevSamp2;
    u16 blockPos;
    s16 leftCalcVolume;
    s16 rightCalcVolume;
    u8 envState;
    u8 sustainLevel;
    s8 leftVolume;
    s8 rightVolume;
    s8 keyWait;
    bool active;
    u8 brrHeader;
    bool echoEnabled;
} ALIGNED;
typedef struct _DspChannel DspChannel;

// DSP Register defintions

// Channel specific
#define DSP_VOL_L		0x00
#define DSP_VOL_R		0x01
#define DSP_PITCH_L		0x02
#define DSP_PITCH_H		0x03
#define DSP_SRC			0x04
#define DSP_ADSR1		0x05
#define DSP_ADSR2		0x06
#define DSP_GAIN		0x07
#define DSP_ENVX		0x08
#define DSP_OUTX		0x09

// Global
#define DSP_MAINVOL_L	0x0C
#define DSP_MAINVOL_R	0x1C
#define DSP_ECHOVOL_L	0x2C
#define DSP_ECHOVOL_R	0x3C
#define DSP_KON			0x4C
#define DSP_KOF			0x5C
#define DSP_FLAG		0x6C
#define DSP_ENDX		0x7C

#define DSP_EFB			0x0D
#define DSP_PMOD		0x2D
#define DSP_NOV			0x3D
#define DSP_EON			0x4D
#define DSP_DIR			0x5D
#define DSP_ESA			0x6D
#define DSP_EDL			0x7D

// Envelope state definitions
#define ENVSTATE_NONE       0
#define ENVSTATE_ATTACK		1
#define ENVSTATE_DECAY		2
#define ENVSTATE_SUSTAIN	3
#define ENVSTATE_RELEASE	4
#define ENVSTATE_DIRECT		5
#define ENVSTATE_INCREASE	6
#define ENVSTATE_BENTLINE	7
#define ENVSTATE_DECREASE	8
#define ENVSTATE_DECEXP		9

#endif


#ifdef __cplusplus
extern "C" {
#endif

extern u8 DSP_MEM[0x100];
extern u16 dspPreamp;
// externs from dspmixer.S
extern u32 DecodeSampleBlockAsm(u8 *blockPos, s16 *samplePos, DspChannel *channel);
extern u8 channelNum;
extern void DspMixSamplesStereo(u32 samples, u16 *mixBuf);
extern void DspWriteByte(u8 val, u8 address);
extern void DspSetEndOfSample(u32 channel);
extern DspChannel channels[8];
extern void DspReset();
extern void DspPrepareStateAfterReload();

#ifdef __cplusplus
}
#endif
