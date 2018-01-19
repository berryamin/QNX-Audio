/*
 *tef6638.h
*/
#ifndef __TEF6638_H__
#define __TEF6638_H__
#include <audio_driver.h>
#include "variant.h"
#include <hw/i2c.h>


#define TEF6638_I2C_DEV "/dev/i2c2"
#define TEF6638_I2C_SPEED 400000
#define PI 3.14

/* define startUP mode useces etc.*/
#define USECASE 4
#define SAMPLE_RATE 1
#define AUDIO_AUDIO_CFG_ADDR          0x3F
#define AUDIO_MODE_CFG_ADDR           0x00

#define AUDIO_PERIPHERAL_CFG_ADDR     0xA9
#define AUDIO_PERIPHERAL_ADC          0x28
#define AUDIO_PERIPHERAL_FRONT_DAC    0x33
#define AUDIO_PERIPHERAL_REAR_DAC     0x32
#define AUDIO_PERIPHERAL_HOST_OUT0    0x16
#define AUDIO_PERIPHERAL_HOST_OUT1    0x17
#define AUDIO_PERIPHERAL_ENABLE       0x00
#define PRIMARY_INPUT_SELECT_ADDR     0x20
#define SECONDARY_INPUT_SELECT_ADDR   0x28

/*Used for set AUDIO_PERIPHERAL_CFG_ADDR*/
#define AIN0_INPUT                   0x00
#define AIN1_INPUT                   0x01
#define AIN2_INPUT                   0x02
#define AIN3_INPUT                   0x03
#define SLAVE_I2S0_INPUT			 0x0A
#define SLAVE_I2S1_INPUT             0x0B
#define SLAVE_I2S2_INPUT             0x0C//premium feature
#define HOST_I2S_INPUT_OUTPUT        0x14// can config i2s format for HOST_I2S_INPUT ,HOST_I2S0_OUTPUT,HOST_I2S1_OUTPUT   
#define HOST_I2S_INPUT  		     0x15
#define HOST_I2S0_OUTPUT             0X16
#define HOST_I2S1_OUTPUT             0X17
#define HOST_I2S2_OUTPUT             0X18
/***************************************/
#define I2S_FORMAT 					 0x00
#define AIN_CNOFIG_HIGH_COMMON_2V    0x02
#define AIN_CNOFIG_HIGH_COMMON_1V    0x03
#define AIN_CNOFIG_HIGH_COMMON_0_5V  0x04
#define AIN_CONFIG_IPOD              0x05

/*Used for set AUDIO_PERIPHERAL_CFG_ADDR*/

#define Select_Radio                 0x00
#define Select_AIN_0                 0x08
#define Select_AIN_1                 0x09
#define Select_AIN_2                 0x0A
#define Select_SLAVE_I2S0            0x10
#define Select_SLAVE_I2S1            0x11
#define Select_SLAVE_I2S2            0x12   
#define Select_HOST_I2S0             0x13
#define Select_HOST_I2S1             0x14
#define Select_SPDIF            	 0x15
#define Select_INTERNAL_NOISE        0x1E
#define Select_INTERNAL_SINE         0x1F







#define AUDIO_STS_ADDR				  0x00
#define SAMP_FREQ_44KHZ  (44100)
#define SAMP_FREQ_48KHZ  (48000)
/*Used in */
#define MaxLoudBoost 		(18)
#define MaxLoudBoostB       (18)
#define MaxLoudBoostT       (14)

#define FixedBoost 			(48)
#define MainVolMaxP 	(0)
#define ChanlGainMaxP        (6)
#define PeqBoostMaxP         (14)
#define PeqBoostMinP         (-14)

#define GeqBoostMaxP         (0)
#define ToneBoostMaxP        (18)
#define ToneBoostMinP        (-14)

#define MainVolMaxS   (12)
#define ChanlGainMaxS       (6)
#define ToneBoostMaxS         (18)

#define PhonChanlGainMax      (6)
#define NavChanlGainMax		  (6)	


#define NvPhBoostMax 		(12)
#define NvPhAttnAudPath     (12)

/*Used in PrimaryVolumePreset:*/
#define LOUDNESS_BASS_BOOST_VOL_2dB   (0x7FF)/*0.00*/
#define LOUDNESS_BASS_BOOST_VOL_1dB   (0x7E2)/*0.01*/
#define LOUDNESS_TREBLE_BOOST_VOL_2dB (0x7FF)/*0.00*/
#define LOUDNESS_TREBLE_BOOST_VOL_1dB (0x7DB)/*0.01*/
#define FLAT  	  (0)
#define MINUS_INF (-93)

#define MASK_32MSB          (0xFF000000)
#define MASK_MSB            (0x00FF0000)
#define MASK_MBYTE          (0x0000FF00)
#define MASK_LSB            (0x000000FF)

#define BYTE_ALIGN          (0x8)
#define TWO_BYTE_ALIGN      (0x10)
#define THREE_BYTE_ALIGN    (0x18)

#define AUDIO_Y_Loudf_MaxBstBass 				(0x6F1)
#define AUDIO_Y_Loudf_MaxBstTreble 				(0x5F6)
#define AUDIO_X_WavTab_UselIO_I2C_MODE 			(0x000000)
#define AUDIO_X_WavTab_Control_Click			(0xFFFFFF)
#define AUDIO_X_WavTab_Control_Clack 			(0x000001)



#define dBstep (1)//dB
#define NvPhStep (NvPhBoostMax + 36)/100//db

static snd_mixer_voice_t stereo_voices[] = {
	{SND_MIXER_VOICE_LEFT, 0},
	{SND_MIXER_VOICE_RIGHT, 0},
	{SND_MIXER_VOICE_REAR_LEFT, 0},
	{SND_MIXER_VOICE_REAR_RIGHT, 0},
	{SND_MIXER_VOICE_CENTER, 0},
	{SND_MIXER_VOICE_WOOFER, 0}
};
/*filter caculate*/

enum filter_type{
    Flat_Response,
	First_Order_Low_Pass,	
	First_Order_High_Pass,
	First_Order_Shelving_Low_Pass,
	First_Order_Shelving_High_Pass,
	Second_Order_Peak_Notch,
	Second_Order_Shelving,
	Second_Order_Peaking,
	Second_Order_Low_Pass,
	Second_Order_High_Pass,
	Third_Order_Low_Pass,
	Third_Order_High_Pass,
	Fourth_Order_Low_Pass,
	Fourth_Order_High_Pass,
	Sixth_Order_Low_Pass,
	Sixth_Order_High_Pass,
	Eighth_Order_Low_Pass,
	Eighth_Order_High_Pass,
} ;

typedef struct filter_coeffients{
     float a1;
	 float a2;
	 float b0;
	 float b1;
	 float b2;
	 float Gb;
	 float a01;
	 float a02;
	 float a11;
	 float a12;
	 float b00;
	 float b01;
	 float b02;
	 float b10;
	 float b11;
	 float b12;
	 float a21;
	 float b20;
	 float a22;
	 float b21;
	 float b22;
	 float a31;
	 float a32;
	 float b30;
	 float b31;
	 float b32;
	 
}filter_coeffients_t;
typedef struct filter_param{
     int32_t type;
	 int32_t fs;
	 int32_t fc;
	 int32_t gain;
	 float   q;
}filter_param_t;
/*filter caculate end*/



#define Tone_Bass_Fc  (120)
#define Tone_TREBLE_Fc (5000)
#define Tone_Bass_Q    (2.0)
#define Tone_Treble_Q  (1.0)
#define Tone_Gain_Default (0)
#define BASS_FILTER_TYPE (First_Order_Shelving_Low_Pass)
#define TREBLE_FILTER_TYPE (First_Order_Shelving_High_Pass)
#define MID_FILTER_TYPE (Flat_Response)

static volatile uint32_t SamplingFrequency = SAMP_FREQ_48KHZ;



enum
{
    PRIMARY_CHANNEL = 0,
    SECONDARY_CHANNEL ,
    PHONE_CHANNEL ,
    NAV_CHANNEL ,
    NUM_OF_CHANNEL,
};
static int32_t pcm_devices[NUM_OF_CHANNEL] = {
	PRIMARY_CHANNEL, 
	SECONDARY_CHANNEL,
	PHONE_CHANNEL,
	NAV_CHANNEL,
};

static struct snd_mixer_element_volume1_range output_volume_range[NUM_OF_CHANNEL] = {
	{0, 127, -90, MainVolMaxP},//primary volume
	{0, 127, -90, MainVolMaxS},//secondary volume
	{0, 100, -36, NvPhBoostMax},//phone volume
	{0, 100, -36, NvPhBoostMax},//navigation	volume
};
static struct snd_mixer_element_volume1_range input_volume_range[NUM_OF_CHANNEL] = {
	{0, 127, -90, MainVolMaxP},//primary volume
	{0, 127, -90, MainVolMaxS},//secondary volume
	
};

static struct snd_mixer_element_volume1_range output_gain_range[NUM_OF_CHANNEL] = {
	{0, 100, -60, ChanlGainMaxP},//channel gain
	{0, 100, -60, ChanlGainMaxS},
    {0, 100, -36, PhonChanlGainMax},
    {0, 100, -36, NavChanlGainMax},
};

enum {
	PAN_LEFT_RIGHT ,
	PAN_FRONT_REAR,
	PAN_BOTTOM_UP,
	NUM_OF_PAN
};

static struct snd_mixer_element_pan_control1_range pan_range[NUM_OF_PAN] = {
	{SND_MIXER_PAN_LEFT_RIGHT, 0, 100, 0, 66},
	{SND_MIXER_PAN_FRONT_REAR, 0, 100, 0, 66},
	{SND_MIXER_PAN_BOTTOM_UP, 0, 100, 0, 66}

};

static struct snd_mixer_element_tone_control1_info tone_info[] = {
	{SND_MIXER_TC1_BASS|SND_MIXER_TC1_TREBLE, 0, 100,  ToneBoostMinP, ToneBoostMaxP, 0, 100,  ToneBoostMinP, ToneBoostMaxP},
	{SND_MIXER_TC1_BASS|SND_MIXER_TC1_TREBLE, 0, 100,  ToneBoostMinP, ToneBoostMaxP, 0, 100,  ToneBoostMinP, ToneBoostMaxP},
};


static int main_volume[32] = {
    -90, -70, -60, -54, -48, -42, -36, -30, -26, -23, 
	-21, -20, -19, -18, -17, -16, -15, -14, -13, -12, 
	-11, -10,  -9,  -8,  -7,  -6,  -5,  -4,  -3,  -2,  
	 -1,   0,  
};


static int channel_gain[][12]={
    {-60, -50, -40, -30, -25, -20, -15, -10, -3, -2, -1, ChanlGainMaxP },
    {-60, -50, -40, -30, -25, -20, -15, -10, -3, -2, -1, ChanlGainMaxP }                                                    
};


static int tone_control_gain[12]={
    ToneBoostMinP, -11, -8 , -5, -2, 0 , 1, 3, 5, 7, 16, ToneBoostMaxP
};

static int phone_nav_gain[34]={
    -36, -30, -29, -28, -27, -26, -25, -23, -20, -19,
	-18, -17, -16, -15, -14, -13, -12, -10,  -8,  -7,
	 -5,  -4,  -2,  -1,   0,   1,   2,   4,   5,   6,
	  7,   8,  10,  12,

};

static int phone_nav_volume[34]={
    -36, -30, -29, -28, -27, -26, -25, -23, -20, -19,
	-18, -17, -16, -15, -14, -13, -12, -10,  -8,  -7,
	 -5,  -4,  -2,  -1,   0,   1,   2,   4,   5,   6,
	  7,   8,  10,  12,

};


typedef struct {
   int gain1;
   int gain2;
} audio_pan_t;
static audio_pan_t audio_fade_gain[15] = {
//front   rear 
  {0,     63 },
  {0,     45 },
  {0,     28 },
  {0,     15 },
  {0,     9  },
  {0,     5  },
  {0,     2  },
  {0,     0  },
  {2,     0  },
  {5,     0  },
  {9,     0  },
  {15,    0  },
  {28,    0  },
  {45,    0  },
  {63,    0  },
};

static audio_pan_t audio_balance_gain[15] = {
//Left   Right
  {0,     63 },
  {0,     45 },
  {0,     28 },
  {0,     15 },
  {0,     9  },
  {0,     5  },
  {0,     2  },
  {0,     0  },
  {2,     0  },
  {5,     0  },
  {9,     0  },
  {15,    0  },
  {28,    0  },
  {45,    0  },
  {63,    0  },
};




/*Begin: Register addr define*/
#define AUDIO_X_AD01InL                               0xF202BCUL
#define AUDIO_X_AD01InR                               0xF202BDUL
#define AUDIO_X_AD23InL                               0xF202BEUL
#define AUDIO_X_AD23InR                               0xF202BFUL
#define AUDIO_X_ALE_InPntr                            0xF20762UL
#define AUDIO_X_ALE_OutL                              0xF20763UL
#define AUDIO_X_ALE_OutR                              0xF20764UL
#define AUDIO_X_ALE_PAR_EQU_LinRefSpecSq1             0xF2076BUL
#define AUDIO_X_ALE_PAR_EQU_LinRefSpecSq2             0xF2076CUL
#define AUDIO_X_ALE_PAR_EQU_LinRefSpecSq3             0xF2076DUL
#define AUDIO_X_ALE_PAR_EQU_OnOff                     0xF20767UL
#define AUDIO_X_ALE_PAR_Gain1                         0xF20777UL
#define AUDIO_X_ALE_PAR_Gain2                         0xF20778UL
#define AUDIO_X_ALE_PAR_Gain3                         0xF20779UL
#define AUDIO_X_ALE_PAR_Gain4                         0xF2077AUL
#define AUDIO_X_ALE_PAR_LEV_FilterGain_Exp            0xF20776UL
#define AUDIO_X_ALE_PAR_LEV_Gain1                     0xF20772UL
#define AUDIO_X_ALE_PAR_LEV_Gain2                     0xF20774UL
#define AUDIO_X_ALE_PAR_LEV_LS_Gain                   0xF20771UL
#define AUDIO_X_ALE_PAR_LEV_OnOff                     0xF20766UL
#define AUDIO_X_ALE_PAR_LEV_RelDecay1Gain             0xF20773UL
#define AUDIO_X_ALE_PAR_LEV_RelLevel1Thrs             0xF20775UL
#define AUDIO_X_ALE_PAR_LIM_Lower                     0xF2076FUL
#define AUDIO_X_ALE_PAR_LIM_Threshold                 0xF2076EUL
#define AUDIO_X_ALE_PAR_OnOff                         0xF20765UL
#define AUDIO_X_ALE_PAR_OutS_Gain                     0xF20769UL
#define AUDIO_X_ALE_PAR_PassThrough_Gain              0xF2076AUL
#define AUDIO_X_ALE_PAR_Reference_Level_Exp           0xF20768UL
#define AUDIO_X_AUB2_AGCMaxGain                       0xF204E0UL
#define AUDIO_X_AUB2_InPntr                           0xF205D2UL
#define AUDIO_X_AUB2_Mode                             0xF204D9UL
#define AUDIO_X_AUB2_out1                             0xF20336UL
#define AUDIO_X_AUB2_out2                             0xF20337UL
#define AUDIO_X_AUB2_TargetLevel                      0xF204DDUL
#define AUDIO_X_CenterInPntr                          0xF205B7UL
#define AUDIO_X_CheckSum_Control                      0xF20485UL
#define AUDIO_X_CheckSum_Result                       0xF20486UL
#define AUDIO_X_CheckSum_Start                        0xF20484UL
#define AUDIO_X_Chime_Cl_Out                          0xF2032BUL
#define AUDIO_X_Chime_Out                             0xF2032AUL
#define AUDIO_X_CompExp_InPntr                        0xF205C0UL
#define AUDIO_X_CompExp_OutPL                         0xF202FAUL
#define AUDIO_X_CompExp_OutPR                         0xF202FBUL
#define AUDIO_X_CompExp_PonE                          0xF204E4UL
#define AUDIO_X_CompExp_switch                        0xF204E3UL
#define AUDIO_X_CompExp_Th                            0xF204E9UL
#define AUDIO_X_DCfilt_OutPL                          0xF20314UL
#define AUDIO_X_DCfilt_OutPR                          0xF20315UL
#define AUDIO_X_DCfilt_OutSL                          0xF20316UL
#define AUDIO_X_DCfilt_OutSR                          0xF20317UL
#define AUDIO_X_Delay_C_InPntr                        0xF205DCUL
#define AUDIO_X_Delay_F_InPntr                        0xF205DAUL
#define AUDIO_X_Delay_FL_Out                          0xF20304UL
#define AUDIO_X_Delay_FR_Out                          0xF20305UL
#define AUDIO_X_Delay_InitFlag                        0xF206E9UL
#define AUDIO_X_Delay_Length1_In                      0xF206E3UL
#define AUDIO_X_Delay_Length2_In                      0xF206E4UL
#define AUDIO_X_Delay_Length3_In                      0xF206E5UL
#define AUDIO_X_Delay_Length4_In                      0xF206E6UL
#define AUDIO_X_Delay_Length5_In                      0xF206E7UL
#define AUDIO_X_Delay_Length6_In                      0xF206E8UL
#define AUDIO_X_Delay_R_InPntr                        0xF205DBUL
#define AUDIO_X_Delay_RL_Out                          0xF20306UL
#define AUDIO_X_Delay_RR_Out                          0xF20307UL
#define AUDIO_X_Delay_Start                           0xF206E2UL
#define AUDIO_X_Delay_Sw_InPntr                       0xF205DDUL
#define AUDIO_X_Delay_SwL_Out                         0xF20308UL
#define AUDIO_X_Delay_SwR_Out                         0xF20309UL
#define AUDIO_X_Dmph_OutPL                            0xF20318UL
#define AUDIO_X_Dmph_OutPR                            0xF20319UL
#define AUDIO_X_Dmph_OutSL                            0xF2031AUL
#define AUDIO_X_Dmph_OutSR                            0xF2031BUL
#define AUDIO_X_Dmph_SPDIF_Mask                       0xF2026CUL
#define AUDIO_X_EasyP_BackupIndex                     0xF202BBUL
#define AUDIO_X_EasyP_Index                           0xF202B9UL
#define AUDIO_X_Eq_OutFL                              0xF202FEUL
#define AUDIO_X_Eq_OutFR                              0xF202FFUL
#define AUDIO_X_Eq_OutRL                              0xF20300UL
#define AUDIO_X_Eq_OutRR                              0xF20301UL
#define AUDIO_X_Eq_OutSwL                             0xF20302UL
#define AUDIO_X_Eq_OutSwR                             0xF20303UL
#define AUDIO_X_FastMute_FlagIOMask                   0xF2049FUL
#define AUDIO_X_FCLim_FlgGenDSPIO_Polarity            0xF20496UL
#define AUDIO_X_FCLim_FlgGenFlagFR                    0xF2049BUL
#define AUDIO_X_FCLim_FlgGenFlagRS                    0xF2049EUL
#define AUDIO_X_FCLim_FlgGenFlagSwL                   0xF2049CUL
#define AUDIO_X_FCLim_FlgGenFlagSwR                   0xF2049DUL
#define AUDIO_X_FCLim_FlgGenMaskFR                    0xF20497UL
#define AUDIO_X_FCLim_FlgGenMaskRS                    0xF2049AUL
#define AUDIO_X_FCLim_FlgGenMaskSwL                   0xF20498UL
#define AUDIO_X_FCLim_FlgGenMaskSwR                   0xF20499UL
#define AUDIO_X_FCLim_MinGainFR                       0xF2048EUL
#define AUDIO_X_FCLim_MinGainRS                       0xF20494UL
#define AUDIO_X_FCLim_MinGainSwL                      0xF20490UL
#define AUDIO_X_FCLim_MinGainSwR                      0xF20492UL
#define AUDIO_X_FDACpntr                              0xF20487UL
#define AUDIO_X_FInPntr                               0xF205B4UL
#define AUDIO_X_FrontOutL                             0xF202F2UL
#define AUDIO_X_FrontOutR                             0xF202F3UL
#define AUDIO_X_FSupBInPntr                           0xF20753UL
#define AUDIO_X_FSupInPntr                            0xF205C3UL
#define AUDIO_X_FVolInPntr                            0xF205BAUL
#define AUDIO_X_GEq_OutFL                             0xF2030AUL
#define AUDIO_X_GEq_OutFR                             0xF2030BUL
#define AUDIO_X_GEqInPntr                             0xF205CFUL
#define AUDIO_X_GPF_LInPntr                           0xF205D3UL
#define AUDIO_X_GPF_OutL                              0xF2031CUL
#define AUDIO_X_GPF_OutR                              0xF2031DUL
#define AUDIO_X_GPF_RInPntr                           0xF205D4UL
#define AUDIO_X_GPF2_InPntr                           0xF205D5UL
#define AUDIO_X_GPF2_OutL                             0xF2031EUL
#define AUDIO_X_GPF2_OutR                             0xF2031FUL
#define AUDIO_X_GPF3_LInPntr                          0xF205D6UL
#define AUDIO_X_GPF3_OutL                             0xF20320UL
#define AUDIO_X_GPF3_OutR                             0xF20321UL
#define AUDIO_X_GPF3_RInPntr                          0xF205D7UL
#define AUDIO_X_GPF4_InPntr                           0xF205D8UL
#define AUDIO_X_GPF4_OutL                             0xF20322UL
#define AUDIO_X_GPF4_OutR                             0xF20323UL
#define AUDIO_X_GPF5_InPntr                           0xF205D9UL
#define AUDIO_X_GPF5_OutL                             0xF20324UL
#define AUDIO_X_GPF5_OutR                             0xF20325UL
#define AUDIO_X_Gsa_Bar321                            0xF2074FUL
#define AUDIO_X_Gsa_Bar654                            0xF2074EUL
#define AUDIO_X_Gsa_Bar987                            0xF2074DUL
#define AUDIO_X_Gsa_InPntr                            0xF205F3UL
#define AUDIO_X_Gsa_Thresh1                           0xF20739UL
#define AUDIO_X_Gsa_Thresh2                           0xF2073AUL
#define AUDIO_X_Gsa_Thresh3                           0xF2073BUL
#define AUDIO_X_Gsa_Thresh4                           0xF2073CUL
#define AUDIO_X_Gsa_Thresh5                           0xF2073DUL
#define AUDIO_X_Gsa_Thresh6                           0xF2073EUL
#define AUDIO_X_Gsa_Thresh7                           0xF2073FUL
#define AUDIO_X_Gsa_Thresh8                           0xF20740UL
#define AUDIO_X_HIIS0InL                              0xF202C0UL
#define AUDIO_X_HIIS0InR                              0xF202C1UL
#define AUDIO_X_HIIS0Outpntr                          0xF20489UL
#define AUDIO_X_HIIS1InL                              0xF202C2UL
#define AUDIO_X_HIIS1InR                              0xF202C3UL
#define AUDIO_X_HIIS1Outpntr                          0xF2048AUL
#define AUDIO_X_IBblnd_An2DigRate                     0xF20270UL
#define AUDIO_X_IBblnd_AnInPntr                       0xF205AEUL
#define AUDIO_X_IBblnd_Dig2AnRate                     0xF20271UL
#define AUDIO_X_IBblnd_DigInPntr                      0xF205AFUL
#define AUDIO_X_IBblnd_OutL                           0xF202F0UL
#define AUDIO_X_IBblnd_OutR                           0xF202F1UL
#define AUDIO_X_InputFlagIIS0                         0xF202D5UL
#define AUDIO_X_InputFlagIIS1                         0xF202D1UL
#define AUDIO_X_InputFlagIIS2                         0xF202CDUL
#define AUDIO_X_InputFlagSPDIF                        0xF202D9UL
#define AUDIO_X_Keycode                               0xF20255UL
#define AUDIO_X_Loudf_DynSwtch                        0xF204B1UL
#define AUDIO_X_Loudf_HldThrshB                       0xF204B7UL
#define AUDIO_X_Loudf_HldThrshT                       0xF204BCUL
#define AUDIO_X_Loudf_InPntr                          0xF205D1UL
#define AUDIO_X_Loudf_LevInPntr                       0xF204BEUL
#define AUDIO_X_Loudf_OutL                            0xF2030EUL
#define AUDIO_X_Loudf_OutR                            0xF2030FUL
#define AUDIO_X_MkSubwLeft                            0xF202FCUL
#define AUDIO_X_MkSubwRight                           0xF202FDUL
#define AUDIO_X_Mute_StpAttDac                        0xF204A0UL
#define AUDIO_X_Mute_StpAttN                          0xF20298UL
#define AUDIO_X_Mute_StpAttP                          0xF20292UL
#define AUDIO_X_Mute_StpAttS                          0xF20295UL
#define AUDIO_X_Mute_StpAttT                          0xF2029BUL
#define AUDIO_X_Mute_StpRelDac                        0xF204A1UL
#define AUDIO_X_Mute_StpRelN                          0xF20299UL
#define AUDIO_X_Mute_StpRelP                          0xF20293UL
#define AUDIO_X_Mute_StpRelS                          0xF20296UL
#define AUDIO_X_Mute_StpRelT                          0xF2029CUL
#define AUDIO_X_MuteSix_StpAtt                        0xF2029EUL
#define AUDIO_X_MuteSix_StpRel                        0xF2029FUL
#define AUDIO_X_Navb4EQ                               0xF20312UL
#define AUDIO_X_NavBackInPntr                         0xF205BEUL
#define AUDIO_X_NavOut                                0xF202E0UL
#define AUDIO_X_NChanSelPntr                          0xF205B2UL
#define AUDIO_X_NG_OutL                               0xF2032CUL
#define AUDIO_X_NG_OutR                               0xF2032DUL
#define AUDIO_X_PChannelMode_OutL                     0xF2032EUL
#define AUDIO_X_PChannelMode_OutR                     0xF2032FUL
#define AUDIO_X_PChanSelPntr                          0xF205ACUL
#define AUDIO_X_PCHIME_AngleIncr_LFO                  0xF206B3UL
#define AUDIO_X_PCHIME_ControlStatusReg               0xF206BFUL
#define AUDIO_X_PCHIME_Env1_AttackIncr                0xF206B5UL
#define AUDIO_X_PCHIME_Env1_DelaySamples              0xF206B4UL
#define AUDIO_X_PCHIME_Env1_SustainSamples            0xF206B6UL
#define AUDIO_X_PCHIME_Env2_AttackIncr                0xF206B8UL
#define AUDIO_X_PCHIME_Env2_DelaySamples              0xF206B7UL
#define AUDIO_X_PCHIME_Env2_SustainSamples            0xF206B9UL
#define AUDIO_X_PCHIME_Env3_AttackIncr                0xF206BBUL
#define AUDIO_X_PCHIME_Env3_DelaySamples              0xF206BAUL
#define AUDIO_X_PCHIME_Env3_SustainSamples            0xF206BCUL
#define AUDIO_X_PCHIME_NrRepetitions                  0xF206BDUL
#define AUDIO_X_PCHIME_out                            0xF205F6UL
#define AUDIO_X_PCHIME_RepeatSamples                  0xF206BEUL
#define AUDIO_X_PCHIME_SoftMute_CurrentVolume         0xF206ACUL
#define AUDIO_X_PDC2_Out                              0xF2055DUL
#define AUDIO_X_Phonb4EQ                              0xF20313UL
#define AUDIO_X_PhonBackInPntr                        0xF205BFUL
#define AUDIO_X_PhonOut                               0xF202E1UL
#define AUDIO_X_PProcSelPntr                          0xF205B0UL
#define AUDIO_X_PrimInModePntr                        0xF205F5UL
#define AUDIO_X_pSRCInputFlag1                        0xF202C6UL
#define AUDIO_X_pSRCInputFlag2                        0xF202C7UL
#define AUDIO_X_pSRCInputFlag3                        0xF202C8UL
#define AUDIO_X_PToneControl_InPntr                   0xF205D0UL
#define AUDIO_X_PVol_InPntr                           0xF205B8UL
#define AUDIO_X_QPD_COUNTMAX1                         0xF2033BUL
#define AUDIO_X_QPD_COUNTMAX2                         0xF2033DUL
#define AUDIO_X_QPD_InPntr11                          0xF205E2UL
#define AUDIO_X_QPD_InPntr12                          0xF205E3UL
#define AUDIO_X_QPD_InPntr21                          0xF205E4UL
#define AUDIO_X_QPD_InPntr22                          0xF205E5UL
#define AUDIO_X_QPD_MaxIn1                            0xF20338UL
#define AUDIO_X_QPD_MaxIn2                            0xF20339UL
#define AUDIO_X_QPD_NonAverPeak1                      0xF20327UL
#define AUDIO_X_QPD_NonAverPeak2                      0xF20329UL
#define AUDIO_X_QPD_Peak1                             0xF20326UL
#define AUDIO_X_QPD_Peak2                             0xF20328UL
#define AUDIO_X_RDACpntr                              0xF20488UL
#define AUDIO_X_RearOutL                              0xF202F4UL
#define AUDIO_X_RearOutR                              0xF202F5UL
#define AUDIO_X_RInPntr                               0xF205B5UL
#define AUDIO_X_RSupBInPntr                           0xF20754UL
#define AUDIO_X_RSupInPntr                            0xF205C4UL
#define AUDIO_X_RVolInPntr                            0xF205BBUL
#define AUDIO_X_SCD_InPntr00                          0xF20676UL
#define AUDIO_X_SCD_InPntr01                          0xF20677UL
#define AUDIO_X_SCD_InPntr1                           0xF20678UL
#define AUDIO_X_SCD_InPntr2                           0xF20679UL
#define AUDIO_X_SCD_InPntr3                           0xF2067AUL
#define AUDIO_X_SCD_Peak0                             0xF2067BUL
#define AUDIO_X_SCD_Peak1                             0xF2067CUL
#define AUDIO_X_SCD_Peak2                             0xF2067DUL
#define AUDIO_X_SCD_Peak3                             0xF2067EUL
#define AUDIO_X_SCD_SWFlags                           0xF2061EUL
#define AUDIO_X_SCD_Thresh0                           0xF2067FUL
#define AUDIO_X_SCD_Thresh1                           0xF20680UL
#define AUDIO_X_SCD_Thresh2                           0xF20681UL
#define AUDIO_X_SCD_Thresh3                           0xF20682UL
#define AUDIO_X_SChanSelPntr                          0xF205ADUL
#define AUDIO_X_SecOutL                               0xF202F8UL
#define AUDIO_X_SecOutR                               0xF202F9UL
#define AUDIO_X_SinGen_OutL                           0xF2032CUL
#define AUDIO_X_SinGen_OutR                           0xF2032DUL
#define AUDIO_X_SProcSelPntr                          0xF205B1UL
#define AUDIO_X_SRC_Out_Ch1_L                         0xF2011DUL
#define AUDIO_X_SRC_Out_Ch1_R                         0xF2011EUL
#define AUDIO_X_SRC_Out_Ch2_L                         0xF2011FUL
#define AUDIO_X_SRC_Out_Ch2_R                         0xF20120UL
#define AUDIO_X_SRC_Out_Ch3_L                         0xF20121UL
#define AUDIO_X_SRC_Out_Ch3_R                         0xF20122UL
#define AUDIO_X_SRC1InL                               0xF2011DUL
#define AUDIO_X_SRC1InR                               0xF2011EUL
#define AUDIO_X_SRC2InL                               0xF2011FUL
#define AUDIO_X_SRC2InR                               0xF20120UL
#define AUDIO_X_SRC3InL                               0xF20121UL
#define AUDIO_X_SRC3InR                               0xF20122UL
#define AUDIO_X_SrcSw_AndMask                         0xF202B7UL
#define AUDIO_X_SrcSw_DmphModPntrA                    0xF202B0UL
#define AUDIO_X_SrcSw_DmphModPntrB                    0xF202B1UL
#define AUDIO_X_SrcSw_OrMask                          0xF202B8UL
#define AUDIO_X_SSupInPntr                            0xF205C6UL
#define AUDIO_X_SubwInPntr                            0xF205B6UL
#define AUDIO_X_Sup_ChiInPntr                         0xF205CBUL
#define AUDIO_X_Sup_ExtInPntr                         0xF205CAUL
#define AUDIO_X_Sup_NInPntr                           0xF205C8UL
#define AUDIO_X_Sup_PDC2InPntr                        0xF205C7UL
#define AUDIO_X_Sup_TInPntr                           0xF205C9UL
#define AUDIO_X_SupB_InPntr1                          0xF20757UL
#define AUDIO_X_SupB_InPntr2                          0xF20758UL
#define AUDIO_X_SupB_InPntr3                          0xF20759UL
#define AUDIO_X_SupB_InPntr4                          0xF2075AUL
#define AUDIO_X_SupB_OutFL                            0xF2075BUL
#define AUDIO_X_SupB_OutFR                            0xF2075CUL
#define AUDIO_X_SupB_OutRL                            0xF2075DUL
#define AUDIO_X_SupB_OutRR                            0xF2075EUL
#define AUDIO_X_SupB_OutSW                            0xF2075FUL
#define AUDIO_X_SupB_OutSWR                           0xF20760UL
#define AUDIO_X_SVolInPntr                            0xF205BDUL
#define AUDIO_X_SwFInPntr                             0xF205C1UL
#define AUDIO_X_SwOutL                                0xF202F6UL
#define AUDIO_X_SwOutR                                0xF202F7UL
#define AUDIO_X_SwRInPntr                             0xF205C2UL
#define AUDIO_X_SWRSupBInPntr                         0xF20756UL
#define AUDIO_X_SWSupBInPntr                          0xF20755UL
#define AUDIO_X_SwSupInPntr                           0xF205C5UL
#define AUDIO_X_SwVolInPntr                           0xF205BCUL
#define AUDIO_X_TChanSelPntr                          0xF205B3UL
#define AUDIO_X_ToneOutPL                             0xF2030CUL
#define AUDIO_X_ToneOutPR                             0xF2030DUL
#define AUDIO_X_Tsq_addmul_Bk                         0xF20581UL
#define AUDIO_X_Tsq_ArLinStpA_Bk                      0xF20578UL
#define AUDIO_X_Tsq_ArRelCoef                         0xF20567UL
#define AUDIO_X_Tsq_ArRelCoef_Bk                      0xF20579UL
#define AUDIO_X_Tsq_ChangeThreshold                   0xF20583UL
#define AUDIO_X_Tsq_Cntr0                             0xF2056BUL
#define AUDIO_X_Tsq_CrosFStp_Bk                       0xF20577UL
#define AUDIO_X_Tsq_DecayThreshold                    0xF20584UL
#define AUDIO_X_Tsq_repeate                           0xF2056EUL
#define AUDIO_X_Tsq_repeate_Bk                        0xF2057AUL
#define AUDIO_X_Tsq_T1_Bk                             0xF2057DUL
#define AUDIO_X_Tsq_T2_Bk                             0xF2057EUL
#define AUDIO_X_Tsq_T3_Bk                             0xF2057FUL
#define AUDIO_X_Tsq_T4_Bk                             0xF20580UL
#define AUDIO_X_Tsq_TA_Bk                             0xF2057BUL
#define AUDIO_X_Tsq_TB_Bk                             0xF2057CUL
#define AUDIO_X_UpdatC_NrOfCoeff                      0xF202B9UL
#define AUDIO_X_UpdatC_StartYaddr                     0xF202B8UL
#define AUDIO_X_VersionNr                             0xF20254UL
#define AUDIO_X_Vol_Boost12dB                         0xF20289UL
#define AUDIO_X_Vol_OneOverMaxBoostP                  0xF2028CUL
#define AUDIO_X_Vol_OneOverMaxBoostS                  0xF2028FUL
#define AUDIO_X_Vol_OutFL                             0xF202E8UL
#define AUDIO_X_Vol_OutFR                             0xF202E9UL
#define AUDIO_X_Vol_OutPL                             0xF202E2UL
#define AUDIO_X_Vol_OutPR                             0xF202E3UL
#define AUDIO_X_Vol_OutRL                             0xF202EAUL
#define AUDIO_X_Vol_OutRR                             0xF202EBUL
#define AUDIO_X_Vol_OutScalSL                         0xF20310UL
#define AUDIO_X_Vol_OutScalSR                         0xF20311UL
#define AUDIO_X_Vol_OutSL                             0xF202EEUL
#define AUDIO_X_Vol_OutSR                             0xF202EFUL
#define AUDIO_X_Vol_OutSwL                            0xF202ECUL
#define AUDIO_X_Vol_OutSwR                            0xF202EDUL
#define AUDIO_X_Vol_UnscalBMTGEQP                     0xF2028DUL
#define AUDIO_X_WavTab_Control                        0xF205FBUL
#define AUDIO_X_WavTab_FlagIOFMask                    0xF20609UL
#define AUDIO_X_WavTab_Pointer                        0xF205FDUL
#define AUDIO_X_WavTab_Ram_BuffEnd                    0xF2093FUL
#define AUDIO_X_WavTab_Ram_BuffStart                  0xF20761UL
#define AUDIO_X_WavTab_TacEndPntr                     0xF20605UL
#define AUDIO_X_WavTab_TacStartPntr                   0xF20604UL
#define AUDIO_X_WavTab_TicEndPntr                     0xF20603UL
#define AUDIO_X_WavTab_TicStartPntr                   0xF20602UL
#define AUDIO_X_WavTab_UseIOFlag                      0xF20607UL
#define AUDIO_X_WavTab_UseRamFlag                     0xF20606UL
#define AUDIO_X_ZeroSigL                              0xF202DEUL
#define AUDIO_X_ZeroSigR                              0xF202DFUL

/* AUDIO Y memory absolute addresses */
#define AUDIO_Y_ALE_PAR_EQU_InvRefSpecSq1             0xF2471AUL
#define AUDIO_Y_ALE_PAR_EQU_InvRefSpecSq2             0xF2471BUL
#define AUDIO_Y_ALE_PAR_EQU_InvRefSpecSq3             0xF2471CUL
#define AUDIO_Y_ALE_PAR_EQU_PersEq1                   0xF24717UL
#define AUDIO_Y_ALE_PAR_EQU_PersEq2                   0xF24718UL
#define AUDIO_Y_ALE_PAR_EQU_PersEq3                   0xF24719UL
#define AUDIO_Y_ALE_PAR_filter2_A1                    0xF2470BUL
#define AUDIO_Y_ALE_PAR_filter2_B0                    0xF2470AUL
#define AUDIO_Y_ALE_PAR_filter2_B1                    0xF24709UL
#define AUDIO_Y_ALE_PAR_filter3_A1                    0xF2470DUL
#define AUDIO_Y_ALE_PAR_filter3_B0                    0xF2470EUL
#define AUDIO_Y_ALE_PAR_filter3_B1                    0xF2470CUL
#define AUDIO_Y_ALE_PAR_Headroom_Gain                 0xF24708UL
#define AUDIO_Y_ALE_PAR_LEV_FilterGain1               0xF2470FUL
#define AUDIO_Y_ALE_PAR_LEV_FilterGain2               0xF24710UL
#define AUDIO_Y_ALE_PAR_LEV_FilterGain3               0xF24711UL
#define AUDIO_Y_ALE_PAR_LIM_AttackGain_HI             0xF24713UL
#define AUDIO_Y_ALE_PAR_LIM_AttackGain_LO             0xF24712UL
#define AUDIO_Y_ALE_PAR_LIM_ReleaseGain_HI            0xF24715UL
#define AUDIO_Y_ALE_PAR_LIM_ReleaseGain_LO            0xF24714UL
#define AUDIO_Y_ALE_PAR_Reference_Level_Gain          0xF24716UL
#define AUDIO_Y_BMT_a1bHP                             0xF24605UL
#define AUDIO_Y_BMT_a1bHS                             0xF24622UL
#define AUDIO_Y_BMT_a1bLP                             0xF24606UL
#define AUDIO_Y_BMT_a1bLS                             0xF24623UL
#define AUDIO_Y_BMT_a1mHP                             0xF245FDUL
#define AUDIO_Y_BMT_a1mHS                             0xF2461AUL
#define AUDIO_Y_BMT_a1mLP                             0xF245FEUL
#define AUDIO_Y_BMT_a1mLS                             0xF2461BUL
#define AUDIO_Y_BMT_a1tP                              0xF24610UL
#define AUDIO_Y_BMT_a1tS                              0xF2462DUL
#define AUDIO_Y_BMT_a2bHP                             0xF24607UL
#define AUDIO_Y_BMT_a2bHS                             0xF24624UL
#define AUDIO_Y_BMT_a2bLP                             0xF24608UL
#define AUDIO_Y_BMT_a2bLS                             0xF24625UL
#define AUDIO_Y_BMT_a2mHP                             0xF245FFUL
#define AUDIO_Y_BMT_a2mHS                             0xF2461CUL
#define AUDIO_Y_BMT_a2mLP                             0xF24600UL
#define AUDIO_Y_BMT_a2mLS                             0xF2461DUL
#define AUDIO_Y_BMT_a2tP                              0xF24611UL
#define AUDIO_Y_BMT_a2tS                              0xF2462EUL
#define AUDIO_Y_BMT_b0bHP                             0xF24609UL
#define AUDIO_Y_BMT_b0bHS                             0xF24626UL
#define AUDIO_Y_BMT_b0bLP                             0xF2460AUL
#define AUDIO_Y_BMT_b0bLS                             0xF24627UL
#define AUDIO_Y_BMT_b0mHP                             0xF24601UL
#define AUDIO_Y_BMT_b0mHS                             0xF2461EUL
#define AUDIO_Y_BMT_b0mLP                             0xF24602UL
#define AUDIO_Y_BMT_b0mLS                             0xF2461FUL
#define AUDIO_Y_BMT_b0tP                              0xF24612UL
#define AUDIO_Y_BMT_b0tS                              0xF2462FUL
#define AUDIO_Y_BMT_b1bHP                             0xF2460BUL
#define AUDIO_Y_BMT_b1bHS                             0xF24628UL
#define AUDIO_Y_BMT_b1bLP                             0xF2460CUL
#define AUDIO_Y_BMT_b1bLS                             0xF24629UL
#define AUDIO_Y_BMT_b1tP                              0xF24613UL
#define AUDIO_Y_BMT_b1tS                              0xF24630UL
#define AUDIO_Y_BMT_b2bHP                             0xF2460DUL
#define AUDIO_Y_BMT_b2bHS                             0xF2462AUL
#define AUDIO_Y_BMT_b2bLP                             0xF2460EUL
#define AUDIO_Y_BMT_b2bLS                             0xF2462BUL
#define AUDIO_Y_BMT_b2tP                              0xF24614UL
#define AUDIO_Y_BMT_b2tS                              0xF24631UL
#define AUDIO_Y_BMT_GbasP                             0xF2460FUL
#define AUDIO_Y_BMT_GbasS                             0xF2462CUL
#define AUDIO_Y_BMT_GmidP                             0xF24603UL
#define AUDIO_Y_BMT_GmidS                             0xF24620UL
#define AUDIO_Y_BMT_GtreP                             0xF24615UL
#define AUDIO_Y_BMT_GtreS                             0xF24632UL
#define AUDIO_Y_CompExp_a0a                           0xF24385UL
#define AUDIO_Y_CompExp_a0dH                          0xF24374UL
#define AUDIO_Y_CompExp_a0dL                          0xF24373UL
#define AUDIO_Y_CompExp_a1a                           0xF24386UL
#define AUDIO_Y_CompExp_b1a                           0xF24384UL
#define AUDIO_Y_CompExp_b1dH                          0xF24376UL
#define AUDIO_Y_CompExp_b1dL                          0xF24375UL
#define AUDIO_Y_CompExp_ExpL                          0xF24383UL
#define AUDIO_Y_CompExp_GExp                          0xF24382UL
#define AUDIO_Y_CompExp_K3                            0xF2437DUL
#define AUDIO_Y_CompExp_K4                            0xF2437EUL
#define AUDIO_Y_CompExp_scal                          0xF24387UL
#define AUDIO_Y_DCfilt_a1A                            0xF242DAUL
#define AUDIO_Y_DCfilt_a1B                            0xF242DDUL
#define AUDIO_Y_DCfilt_b0A                            0xF242DCUL
#define AUDIO_Y_DCfilt_b0B                            0xF242DFUL
#define AUDIO_Y_DCfilt_b1A                            0xF242DBUL
#define AUDIO_Y_DCfilt_b1B                            0xF242DEUL
#define AUDIO_Y_EQ4_a11H                              0xF24563UL
#define AUDIO_Y_EQ4_a11L                              0xF24562UL
#define AUDIO_Y_EQ4_a12H                              0xF24561UL
#define AUDIO_Y_EQ4_a12L                              0xF24560UL
#define AUDIO_Y_EQ4_a21H                              0xF2456AUL
#define AUDIO_Y_EQ4_a21L                              0xF24569UL
#define AUDIO_Y_EQ4_a22H                              0xF24568UL
#define AUDIO_Y_EQ4_a22L                              0xF24567UL
#define AUDIO_Y_EQ4_a31                               0xF2456EUL
#define AUDIO_Y_EQ4_a32                               0xF2456DUL
#define AUDIO_Y_EQ4_a41                               0xF24572UL
#define AUDIO_Y_EQ4_a42                               0xF24571UL
#define AUDIO_Y_EQ4_b10H                              0xF2455FUL
#define AUDIO_Y_EQ4_b10L                              0xF2455EUL
#define AUDIO_Y_EQ4_b20H                              0xF24566UL
#define AUDIO_Y_EQ4_b20L                              0xF24565UL
#define AUDIO_Y_EQ4_b30                               0xF2456CUL
#define AUDIO_Y_EQ4_b40                               0xF24570UL
#define AUDIO_Y_EQ4_Gb1                               0xF24564UL
#define AUDIO_Y_EQ4_Gb2                               0xF2456BUL
#define AUDIO_Y_EQ4_Gb3                               0xF2456FUL
#define AUDIO_Y_EQ4_Gb4                               0xF24573UL
#define AUDIO_Y_EqFL_a11H                             0xF243ECUL
#define AUDIO_Y_EqFL_a11L                             0xF243EBUL
#define AUDIO_Y_EqFL_a12H                             0xF243EAUL
#define AUDIO_Y_EqFL_a12L                             0xF243E9UL
#define AUDIO_Y_EqFL_a21H                             0xF243F3UL
#define AUDIO_Y_EqFL_a21L                             0xF243F2UL
#define AUDIO_Y_EqFL_a22H                             0xF243F1UL
#define AUDIO_Y_EqFL_a22L                             0xF243F0UL
#define AUDIO_Y_EqFL_a31H                             0xF243FAUL
#define AUDIO_Y_EqFL_a31L                             0xF243F9UL
#define AUDIO_Y_EqFL_a32H                             0xF243F8UL
#define AUDIO_Y_EqFL_a32L                             0xF243F7UL
#define AUDIO_Y_EqFL_a41H                             0xF24401UL
#define AUDIO_Y_EqFL_a41L                             0xF24400UL
#define AUDIO_Y_EqFL_a42H                             0xF243FFUL
#define AUDIO_Y_EqFL_a42L                             0xF243FEUL
#define AUDIO_Y_EqFL_a51H                             0xF24460UL
#define AUDIO_Y_EqFL_a51L                             0xF2445FUL
#define AUDIO_Y_EqFL_a52H                             0xF24462UL
#define AUDIO_Y_EqFL_a52L                             0xF24461UL
#define AUDIO_Y_EqFL_a61H                             0xF2446AUL
#define AUDIO_Y_EqFL_a61L                             0xF24469UL
#define AUDIO_Y_EqFL_a62H                             0xF2446CUL
#define AUDIO_Y_EqFL_a62L                             0xF2446BUL
#define AUDIO_Y_EqFL_a71H                             0xF24474UL
#define AUDIO_Y_EqFL_a71L                             0xF24473UL
#define AUDIO_Y_EqFL_a72H                             0xF24476UL
#define AUDIO_Y_EqFL_a72L                             0xF24475UL
#define AUDIO_Y_EqFL_b10H                             0xF243E8UL
#define AUDIO_Y_EqFL_b10L                             0xF243E7UL
#define AUDIO_Y_EqFL_b20H                             0xF243EFUL
#define AUDIO_Y_EqFL_b20L                             0xF243EEUL
#define AUDIO_Y_EqFL_b30H                             0xF243F6UL
#define AUDIO_Y_EqFL_b30L                             0xF243F5UL
#define AUDIO_Y_EqFL_b40H                             0xF243FDUL
#define AUDIO_Y_EqFL_b40L                             0xF243FCUL
#define AUDIO_Y_EqFL_b50H                             0xF2445AUL
#define AUDIO_Y_EqFL_b50L                             0xF24459UL
#define AUDIO_Y_EqFL_b51H                             0xF2445CUL
#define AUDIO_Y_EqFL_b51L                             0xF2445BUL
#define AUDIO_Y_EqFL_b52H                             0xF2445EUL
#define AUDIO_Y_EqFL_b52L                             0xF2445DUL
#define AUDIO_Y_EqFL_b60H                             0xF24464UL
#define AUDIO_Y_EqFL_b60L                             0xF24463UL
#define AUDIO_Y_EqFL_b61H                             0xF24466UL
#define AUDIO_Y_EqFL_b61L                             0xF24465UL
#define AUDIO_Y_EqFL_b62H                             0xF24468UL
#define AUDIO_Y_EqFL_b62L                             0xF24467UL
#define AUDIO_Y_EqFL_b70H                             0xF2446EUL
#define AUDIO_Y_EqFL_b70L                             0xF2446DUL
#define AUDIO_Y_EqFL_b71H                             0xF24470UL
#define AUDIO_Y_EqFL_b71L                             0xF2446FUL
#define AUDIO_Y_EqFL_b72H                             0xF24472UL
#define AUDIO_Y_EqFL_b72L                             0xF24471UL
#define AUDIO_Y_EqFL_Gc1                              0xF243EDUL
#define AUDIO_Y_EqFL_Gc2                              0xF243F4UL
#define AUDIO_Y_EqFL_Gc3                              0xF243FBUL
#define AUDIO_Y_EqFL_Gc4                              0xF24402UL
#define AUDIO_Y_EqFR_a11H                             0xF24408UL
#define AUDIO_Y_EqFR_a11L                             0xF24407UL
#define AUDIO_Y_EqFR_a12H                             0xF24406UL
#define AUDIO_Y_EqFR_a12L                             0xF24405UL
#define AUDIO_Y_EqFR_a21H                             0xF2440FUL
#define AUDIO_Y_EqFR_a21L                             0xF2440EUL
#define AUDIO_Y_EqFR_a22H                             0xF2440DUL
#define AUDIO_Y_EqFR_a22L                             0xF2440CUL
#define AUDIO_Y_EqFR_a31H                             0xF24416UL
#define AUDIO_Y_EqFR_a31L                             0xF24415UL
#define AUDIO_Y_EqFR_a32H                             0xF24414UL
#define AUDIO_Y_EqFR_a32L                             0xF24413UL
#define AUDIO_Y_EqFR_a41H                             0xF2441DUL
#define AUDIO_Y_EqFR_a41L                             0xF2441CUL
#define AUDIO_Y_EqFR_a42H                             0xF2441BUL
#define AUDIO_Y_EqFR_a42L                             0xF2441AUL
#define AUDIO_Y_EqFR_a51H                             0xF2447EUL
#define AUDIO_Y_EqFR_a51L                             0xF2447DUL
#define AUDIO_Y_EqFR_a52H                             0xF24480UL
#define AUDIO_Y_EqFR_a52L                             0xF2447FUL
#define AUDIO_Y_EqFR_a61H                             0xF24488UL
#define AUDIO_Y_EqFR_a61L                             0xF24487UL
#define AUDIO_Y_EqFR_a62H                             0xF2448AUL
#define AUDIO_Y_EqFR_a62L                             0xF24489UL
#define AUDIO_Y_EqFR_a71H                             0xF24492UL
#define AUDIO_Y_EqFR_a71L                             0xF24491UL
#define AUDIO_Y_EqFR_a72H                             0xF24494UL
#define AUDIO_Y_EqFR_a72L                             0xF24493UL
#define AUDIO_Y_EqFR_b10H                             0xF24404UL
#define AUDIO_Y_EqFR_b10L                             0xF24403UL
#define AUDIO_Y_EqFR_b20H                             0xF2440BUL
#define AUDIO_Y_EqFR_b20L                             0xF2440AUL
#define AUDIO_Y_EqFR_b30H                             0xF24412UL
#define AUDIO_Y_EqFR_b30L                             0xF24411UL
#define AUDIO_Y_EqFR_b40H                             0xF24419UL
#define AUDIO_Y_EqFR_b40L                             0xF24418UL
#define AUDIO_Y_EqFR_b50H                             0xF24478UL
#define AUDIO_Y_EqFR_b50L                             0xF24477UL
#define AUDIO_Y_EqFR_b51H                             0xF2447AUL
#define AUDIO_Y_EqFR_b51L                             0xF24479UL
#define AUDIO_Y_EqFR_b52H                             0xF2447CUL
#define AUDIO_Y_EqFR_b52L                             0xF2447BUL
#define AUDIO_Y_EqFR_b60H                             0xF24482UL
#define AUDIO_Y_EqFR_b60L                             0xF24481UL
#define AUDIO_Y_EqFR_b61H                             0xF24484UL
#define AUDIO_Y_EqFR_b61L                             0xF24483UL
#define AUDIO_Y_EqFR_b62H                             0xF24486UL
#define AUDIO_Y_EqFR_b62L                             0xF24485UL
#define AUDIO_Y_EqFR_b70H                             0xF2448CUL
#define AUDIO_Y_EqFR_b70L                             0xF2448BUL
#define AUDIO_Y_EqFR_b71H                             0xF2448EUL
#define AUDIO_Y_EqFR_b71L                             0xF2448DUL
#define AUDIO_Y_EqFR_b72H                             0xF24490UL
#define AUDIO_Y_EqFR_b72L                             0xF2448FUL
#define AUDIO_Y_EqFR_Gc1                              0xF24409UL
#define AUDIO_Y_EqFR_Gc2                              0xF24410UL
#define AUDIO_Y_EqFR_Gc3                              0xF24417UL
#define AUDIO_Y_EqFR_Gc4                              0xF2441EUL
#define AUDIO_Y_EqN_a01H                              0xF2463EUL
#define AUDIO_Y_EqN_a01L                              0xF2463DUL
#define AUDIO_Y_EqN_a02H                              0xF24640UL
#define AUDIO_Y_EqN_a02L                              0xF2463FUL
#define AUDIO_Y_EqN_a11H                              0xF24648UL
#define AUDIO_Y_EqN_a11L                              0xF24647UL
#define AUDIO_Y_EqN_a12H                              0xF2464AUL
#define AUDIO_Y_EqN_a12L                              0xF24649UL
#define AUDIO_Y_EqN_b00H                              0xF24638UL
#define AUDIO_Y_EqN_b00L                              0xF24637UL
#define AUDIO_Y_EqN_b01H                              0xF2463AUL
#define AUDIO_Y_EqN_b01L                              0xF24639UL
#define AUDIO_Y_EqN_b02H                              0xF2463CUL
#define AUDIO_Y_EqN_b02L                              0xF2463BUL
#define AUDIO_Y_EqN_b10H                              0xF24642UL
#define AUDIO_Y_EqN_b10L                              0xF24641UL
#define AUDIO_Y_EqN_b11H                              0xF24644UL
#define AUDIO_Y_EqN_b11L                              0xF24643UL
#define AUDIO_Y_EqN_b12H                              0xF24646UL
#define AUDIO_Y_EqN_b12L                              0xF24645UL
#define AUDIO_Y_EqRL_a11H                             0xF24424UL
#define AUDIO_Y_EqRL_a11L                             0xF24423UL
#define AUDIO_Y_EqRL_a12H                             0xF24422UL
#define AUDIO_Y_EqRL_a12L                             0xF24421UL
#define AUDIO_Y_EqRL_a21H                             0xF2442BUL
#define AUDIO_Y_EqRL_a21L                             0xF2442AUL
#define AUDIO_Y_EqRL_a22H                             0xF24429UL
#define AUDIO_Y_EqRL_a22L                             0xF24428UL
#define AUDIO_Y_EqRL_a31H                             0xF24432UL
#define AUDIO_Y_EqRL_a31L                             0xF24431UL
#define AUDIO_Y_EqRL_a32H                             0xF24430UL
#define AUDIO_Y_EqRL_a32L                             0xF2442FUL
#define AUDIO_Y_EqRL_a41H                             0xF24439UL
#define AUDIO_Y_EqRL_a41L                             0xF24438UL
#define AUDIO_Y_EqRL_a42H                             0xF24437UL
#define AUDIO_Y_EqRL_a42L                             0xF24436UL
#define AUDIO_Y_EqRL_a51H                             0xF2449CUL
#define AUDIO_Y_EqRL_a51L                             0xF2449BUL
#define AUDIO_Y_EqRL_a52H                             0xF2449EUL
#define AUDIO_Y_EqRL_a52L                             0xF2449DUL
#define AUDIO_Y_EqRL_a61H                             0xF244A6UL
#define AUDIO_Y_EqRL_a61L                             0xF244A5UL
#define AUDIO_Y_EqRL_a62H                             0xF244A8UL
#define AUDIO_Y_EqRL_a62L                             0xF244A7UL
#define AUDIO_Y_EqRL_a71H                             0xF244B0UL
#define AUDIO_Y_EqRL_a71L                             0xF244AFUL
#define AUDIO_Y_EqRL_a72H                             0xF244B2UL
#define AUDIO_Y_EqRL_a72L                             0xF244B1UL
#define AUDIO_Y_EqRL_b10H                             0xF24420UL
#define AUDIO_Y_EqRL_b10L                             0xF2441FUL
#define AUDIO_Y_EqRL_b20H                             0xF24427UL
#define AUDIO_Y_EqRL_b20L                             0xF24426UL
#define AUDIO_Y_EqRL_b30H                             0xF2442EUL
#define AUDIO_Y_EqRL_b30L                             0xF2442DUL
#define AUDIO_Y_EqRL_b40H                             0xF24435UL
#define AUDIO_Y_EqRL_b40L                             0xF24434UL
#define AUDIO_Y_EqRL_b50H                             0xF24496UL
#define AUDIO_Y_EqRL_b50L                             0xF24495UL
#define AUDIO_Y_EqRL_b51H                             0xF24498UL
#define AUDIO_Y_EqRL_b51L                             0xF24497UL
#define AUDIO_Y_EqRL_b52H                             0xF2449AUL
#define AUDIO_Y_EqRL_b52L                             0xF24499UL
#define AUDIO_Y_EqRL_b60H                             0xF244A0UL
#define AUDIO_Y_EqRL_b60L                             0xF2449FUL
#define AUDIO_Y_EqRL_b61H                             0xF244A2UL
#define AUDIO_Y_EqRL_b61L                             0xF244A1UL
#define AUDIO_Y_EqRL_b62H                             0xF244A4UL
#define AUDIO_Y_EqRL_b62L                             0xF244A3UL
#define AUDIO_Y_EqRL_b70H                             0xF244AAUL
#define AUDIO_Y_EqRL_b70L                             0xF244A9UL
#define AUDIO_Y_EqRL_b71H                             0xF244ACUL
#define AUDIO_Y_EqRL_b71L                             0xF244ABUL
#define AUDIO_Y_EqRL_b72H                             0xF244AEUL
#define AUDIO_Y_EqRL_b72L                             0xF244ADUL
#define AUDIO_Y_EqRL_Gc1                              0xF24425UL
#define AUDIO_Y_EqRL_Gc2                              0xF2442CUL
#define AUDIO_Y_EqRL_Gc3                              0xF24433UL
#define AUDIO_Y_EqRL_Gc4                              0xF2443AUL
#define AUDIO_Y_EqRR_a11H                             0xF24440UL
#define AUDIO_Y_EqRR_a11L                             0xF2443FUL
#define AUDIO_Y_EqRR_a12H                             0xF2443EUL
#define AUDIO_Y_EqRR_a12L                             0xF2443DUL
#define AUDIO_Y_EqRR_a21H                             0xF24447UL
#define AUDIO_Y_EqRR_a21L                             0xF24446UL
#define AUDIO_Y_EqRR_a22H                             0xF24445UL
#define AUDIO_Y_EqRR_a22L                             0xF24444UL
#define AUDIO_Y_EqRR_a31H                             0xF2444EUL
#define AUDIO_Y_EqRR_a31L                             0xF2444DUL
#define AUDIO_Y_EqRR_a32H                             0xF2444CUL
#define AUDIO_Y_EqRR_a32L                             0xF2444BUL
#define AUDIO_Y_EqRR_a41H                             0xF24455UL
#define AUDIO_Y_EqRR_a41L                             0xF24454UL
#define AUDIO_Y_EqRR_a42H                             0xF24453UL
#define AUDIO_Y_EqRR_a42L                             0xF24452UL
#define AUDIO_Y_EqRR_a51H                             0xF244BAUL
#define AUDIO_Y_EqRR_a51L                             0xF244B9UL
#define AUDIO_Y_EqRR_a52H                             0xF244BCUL
#define AUDIO_Y_EqRR_a52L                             0xF244BBUL
#define AUDIO_Y_EqRR_a61H                             0xF244C4UL
#define AUDIO_Y_EqRR_a61L                             0xF244C3UL
#define AUDIO_Y_EqRR_a62H                             0xF244C6UL
#define AUDIO_Y_EqRR_a62L                             0xF244C5UL
#define AUDIO_Y_EqRR_a71H                             0xF244CEUL
#define AUDIO_Y_EqRR_a71L                             0xF244CDUL
#define AUDIO_Y_EqRR_a72H                             0xF244D0UL
#define AUDIO_Y_EqRR_a72L                             0xF244CFUL
#define AUDIO_Y_EqRR_b10H                             0xF2443CUL
#define AUDIO_Y_EqRR_b10L                             0xF2443BUL
#define AUDIO_Y_EqRR_b20H                             0xF24443UL
#define AUDIO_Y_EqRR_b20L                             0xF24442UL
#define AUDIO_Y_EqRR_b30H                             0xF2444AUL
#define AUDIO_Y_EqRR_b30L                             0xF24449UL
#define AUDIO_Y_EqRR_b40H                             0xF24451UL
#define AUDIO_Y_EqRR_b40L                             0xF24450UL
#define AUDIO_Y_EqRR_b50H                             0xF244B4UL
#define AUDIO_Y_EqRR_b50L                             0xF244B3UL
#define AUDIO_Y_EqRR_b51H                             0xF244B6UL
#define AUDIO_Y_EqRR_b51L                             0xF244B5UL
#define AUDIO_Y_EqRR_b52H                             0xF244B8UL
#define AUDIO_Y_EqRR_b52L                             0xF244B7UL
#define AUDIO_Y_EqRR_b60H                             0xF244BEUL
#define AUDIO_Y_EqRR_b60L                             0xF244BDUL
#define AUDIO_Y_EqRR_b61H                             0xF244C0UL
#define AUDIO_Y_EqRR_b61L                             0xF244BFUL
#define AUDIO_Y_EqRR_b62H                             0xF244C2UL
#define AUDIO_Y_EqRR_b62L                             0xF244C1UL
#define AUDIO_Y_EqRR_b70H                             0xF244C8UL
#define AUDIO_Y_EqRR_b70L                             0xF244C7UL
#define AUDIO_Y_EqRR_b71H                             0xF244CAUL
#define AUDIO_Y_EqRR_b71L                             0xF244C9UL
#define AUDIO_Y_EqRR_b72H                             0xF244CCUL
#define AUDIO_Y_EqRR_b72L                             0xF244CBUL
#define AUDIO_Y_EqRR_Gc1                              0xF24441UL
#define AUDIO_Y_EqRR_Gc2                              0xF24448UL
#define AUDIO_Y_EqRR_Gc3                              0xF2444FUL
#define AUDIO_Y_EqRR_Gc4                              0xF24456UL
#define AUDIO_Y_EqSwC_a01H                            0xF244D8UL
#define AUDIO_Y_EqSwC_a01L                            0xF244D7UL
#define AUDIO_Y_EqSwC_a02H                            0xF244DAUL
#define AUDIO_Y_EqSwC_a02L                            0xF244D9UL
#define AUDIO_Y_EqSwC_a11H                            0xF244E2UL
#define AUDIO_Y_EqSwC_a11L                            0xF244E1UL
#define AUDIO_Y_EqSwC_a12H                            0xF244E4UL
#define AUDIO_Y_EqSwC_a12L                            0xF244E3UL
#define AUDIO_Y_EqSwC_a21H                            0xF244ECUL
#define AUDIO_Y_EqSwC_a21L                            0xF244EBUL
#define AUDIO_Y_EqSwC_a22H                            0xF244EEUL
#define AUDIO_Y_EqSwC_a22L                            0xF244EDUL
#define AUDIO_Y_EqSwC_a31H                            0xF244F6UL
#define AUDIO_Y_EqSwC_a31L                            0xF244F5UL
#define AUDIO_Y_EqSwC_a32H                            0xF244F8UL
#define AUDIO_Y_EqSwC_a32L                            0xF244F7UL
#define AUDIO_Y_EqSwC_b00H                            0xF244D2UL
#define AUDIO_Y_EqSwC_b00L                            0xF244D1UL
#define AUDIO_Y_EqSwC_b01H                            0xF244D4UL
#define AUDIO_Y_EqSwC_b01L                            0xF244D3UL
#define AUDIO_Y_EqSwC_b02H                            0xF244D6UL
#define AUDIO_Y_EqSwC_b02L                            0xF244D5UL
#define AUDIO_Y_EqSwC_b10H                            0xF244DCUL
#define AUDIO_Y_EqSwC_b10L                            0xF244DBUL
#define AUDIO_Y_EqSwC_b11H                            0xF244DEUL
#define AUDIO_Y_EqSwC_b11L                            0xF244DDUL
#define AUDIO_Y_EqSwC_b12H                            0xF244E0UL
#define AUDIO_Y_EqSwC_b12L                            0xF244DFUL
#define AUDIO_Y_EqSwC_b20H                            0xF244E6UL
#define AUDIO_Y_EqSwC_b20L                            0xF244E5UL
#define AUDIO_Y_EqSwC_b21H                            0xF244E8UL
#define AUDIO_Y_EqSwC_b21L                            0xF244E7UL
#define AUDIO_Y_EqSwC_b22H                            0xF244EAUL
#define AUDIO_Y_EqSwC_b22L                            0xF244E9UL
#define AUDIO_Y_EqSwC_b30H                            0xF244F0UL
#define AUDIO_Y_EqSwC_b30L                            0xF244EFUL
#define AUDIO_Y_EqSwC_b31H                            0xF244F2UL
#define AUDIO_Y_EqSwC_b31L                            0xF244F1UL
#define AUDIO_Y_EqSwC_b32H                            0xF244F4UL
#define AUDIO_Y_EqSwC_b32L                            0xF244F3UL
#define AUDIO_Y_EqT_a01H                              0xF24652UL
#define AUDIO_Y_EqT_a01L                              0xF24651UL
#define AUDIO_Y_EqT_a02H                              0xF24654UL
#define AUDIO_Y_EqT_a02L                              0xF24653UL
#define AUDIO_Y_EqT_a11H                              0xF2465CUL
#define AUDIO_Y_EqT_a11L                              0xF2465BUL
#define AUDIO_Y_EqT_a12H                              0xF2465EUL
#define AUDIO_Y_EqT_a12L                              0xF2465DUL
#define AUDIO_Y_EqT_b00H                              0xF2464CUL
#define AUDIO_Y_EqT_b00L                              0xF2464BUL
#define AUDIO_Y_EqT_b01H                              0xF2464EUL
#define AUDIO_Y_EqT_b01L                              0xF2464DUL
#define AUDIO_Y_EqT_b02H                              0xF24650UL
#define AUDIO_Y_EqT_b02L                              0xF2464FUL
#define AUDIO_Y_EqT_b10H                              0xF24656UL
#define AUDIO_Y_EqT_b10L                              0xF24655UL
#define AUDIO_Y_EqT_b11H                              0xF24658UL
#define AUDIO_Y_EqT_b11L                              0xF24657UL
#define AUDIO_Y_EqT_b12H                              0xF2465AUL
#define AUDIO_Y_EqT_b12L                              0xF24659UL
#define AUDIO_Y_FCLim_AttHFR                          0xF24362UL
#define AUDIO_Y_FCLim_AttHRS                          0xF2436EUL
#define AUDIO_Y_FCLim_AttHSwL                         0xF24366UL
#define AUDIO_Y_FCLim_AttHSwR                         0xF2436AUL
#define AUDIO_Y_FCLim_AttLFR                          0xF24361UL
#define AUDIO_Y_FCLim_AttLRS                          0xF2436DUL
#define AUDIO_Y_FCLim_AttLSwL                         0xF24365UL
#define AUDIO_Y_FCLim_AttLSwR                         0xF24369UL
#define AUDIO_Y_FCLim_DecHFR                          0xF24360UL
#define AUDIO_Y_FCLim_DecHRS                          0xF2436CUL
#define AUDIO_Y_FCLim_DecHSwL                         0xF24364UL
#define AUDIO_Y_FCLim_DecHSwR                         0xF24368UL
#define AUDIO_Y_FCLim_DecLFR                          0xF2435FUL
#define AUDIO_Y_FCLim_DecLRS                          0xF2436BUL
#define AUDIO_Y_FCLim_DecLSwL                         0xF24363UL
#define AUDIO_Y_FCLim_DecLSwR                         0xF24367UL
#define AUDIO_Y_FCLim_GainHFR                         0xF2436FUL
#define AUDIO_Y_FCLim_GainHRS                         0xF24372UL
#define AUDIO_Y_FCLim_GainHSwL                        0xF24370UL
#define AUDIO_Y_FCLim_GainHSwR                        0xF24371UL
#define AUDIO_Y_GEq_a11H                              0xF24544UL
#define AUDIO_Y_GEq_a11L                              0xF24543UL
#define AUDIO_Y_GEq_a12H                              0xF24542UL
#define AUDIO_Y_GEq_a12L                              0xF24541UL
#define AUDIO_Y_GEq_a21H                              0xF2454BUL
#define AUDIO_Y_GEq_a21L                              0xF2454AUL
#define AUDIO_Y_GEq_a22H                              0xF24549UL
#define AUDIO_Y_GEq_a22L                              0xF24548UL
#define AUDIO_Y_GEq_a31H                              0xF24552UL
#define AUDIO_Y_GEq_a31L                              0xF24551UL
#define AUDIO_Y_GEq_a32H                              0xF24550UL
#define AUDIO_Y_GEq_a32L                              0xF2454FUL
#define AUDIO_Y_GEq_a41                               0xF24556UL
#define AUDIO_Y_GEq_a42                               0xF24555UL
#define AUDIO_Y_GEq_a51                               0xF2455AUL
#define AUDIO_Y_GEq_a52                               0xF24559UL
#define AUDIO_Y_GEq_b10H                              0xF24540UL
#define AUDIO_Y_GEq_b10L                              0xF2453FUL
#define AUDIO_Y_GEq_b20H                              0xF24547UL
#define AUDIO_Y_GEq_b20L                              0xF24546UL
#define AUDIO_Y_GEq_b30H                              0xF2454EUL
#define AUDIO_Y_GEq_b30L                              0xF2454DUL
#define AUDIO_Y_GEq_b40                               0xF24554UL
#define AUDIO_Y_GEq_b50                               0xF24558UL
#define AUDIO_Y_GEq_Gc1                               0xF24545UL
#define AUDIO_Y_GEq_Gc2                               0xF2454CUL
#define AUDIO_Y_GEq_Gc3                               0xF24553UL
#define AUDIO_Y_GEq_Gc4                               0xF24557UL
#define AUDIO_Y_GEq_Gc5                               0xF2455BUL
#define AUDIO_Y_Gsa_a11H                              0xF24697UL
#define AUDIO_Y_Gsa_a11L                              0xF24694UL
#define AUDIO_Y_Gsa_a12H                              0xF2469DUL
#define AUDIO_Y_Gsa_a12L                              0xF2469AUL
#define AUDIO_Y_Gsa_a13H                              0xF246A3UL
#define AUDIO_Y_Gsa_a13L                              0xF246A0UL
#define AUDIO_Y_Gsa_a14                               0xF246A6UL
#define AUDIO_Y_Gsa_a15                               0xF246A9UL
#define AUDIO_Y_Gsa_a16                               0xF246ACUL
#define AUDIO_Y_Gsa_a17                               0xF246AFUL
#define AUDIO_Y_Gsa_a18                               0xF246B2UL
#define AUDIO_Y_Gsa_a19                               0xF246B5UL
#define AUDIO_Y_Gsa_a21H                              0xF24698UL
#define AUDIO_Y_Gsa_a21L                              0xF24695UL
#define AUDIO_Y_Gsa_a22H                              0xF2469EUL
#define AUDIO_Y_Gsa_a22L                              0xF2469BUL
#define AUDIO_Y_Gsa_a23H                              0xF246A4UL
#define AUDIO_Y_Gsa_a23L                              0xF246A1UL
#define AUDIO_Y_Gsa_a24                               0xF246A7UL
#define AUDIO_Y_Gsa_a25                               0xF246AAUL
#define AUDIO_Y_Gsa_a26                               0xF246ADUL
#define AUDIO_Y_Gsa_a27                               0xF246B0UL
#define AUDIO_Y_Gsa_a28                               0xF246B3UL
#define AUDIO_Y_Gsa_a29                               0xF246B6UL
#define AUDIO_Y_Gsa_b01H                              0xF24699UL
#define AUDIO_Y_Gsa_b01L                              0xF24696UL
#define AUDIO_Y_Gsa_b02H                              0xF2469FUL
#define AUDIO_Y_Gsa_b02L                              0xF2469CUL
#define AUDIO_Y_Gsa_b03H                              0xF246A5UL
#define AUDIO_Y_Gsa_b03L                              0xF246A2UL
#define AUDIO_Y_Gsa_b04                               0xF246A8UL
#define AUDIO_Y_Gsa_b05                               0xF246ABUL
#define AUDIO_Y_Gsa_b06                               0xF246AEUL
#define AUDIO_Y_Gsa_b07                               0xF246B1UL
#define AUDIO_Y_Gsa_b08                               0xF246B4UL
#define AUDIO_Y_Gsa_b09                               0xF246B7UL
#define AUDIO_Y_Gsa_ga                                0xF24693UL
#define AUDIO_Y_Gsa_Gp1                               0xF246C1UL
#define AUDIO_Y_Gsa_Gp2                               0xF246C2UL
#define AUDIO_Y_Gsa_Gp3                               0xF246C3UL
#define AUDIO_Y_Gsa_Gp4                               0xF246C4UL
#define AUDIO_Y_Gsa_Gp5                               0xF246C5UL
#define AUDIO_Y_Gsa_Gp6                               0xF246C6UL
#define AUDIO_Y_Gsa_Gp7                               0xF246C7UL
#define AUDIO_Y_Gsa_Gp8                               0xF246C8UL
#define AUDIO_Y_Gsa_Gp9                               0xF246C9UL
#define AUDIO_Y_Gsa_KmH                               0xF246CDUL
#define AUDIO_Y_Gsa_KmL                               0xF246CCUL
#define AUDIO_Y_Gsa_KpH                               0xF246CBUL
#define AUDIO_Y_Gsa_KpL                               0xF246CAUL
#define AUDIO_Y_IBblnd_Vol                            0xF242ECUL
#define AUDIO_Y_IIR2GPF2_a1H                          0xF24514UL
#define AUDIO_Y_IIR2GPF2_a1L                          0xF24513UL
#define AUDIO_Y_IIR2GPF2_a2H                          0xF24516UL
#define AUDIO_Y_IIR2GPF2_a2L                          0xF24515UL
#define AUDIO_Y_IIR2GPF2_b0H                          0xF2450EUL
#define AUDIO_Y_IIR2GPF2_b0L                          0xF2450DUL
#define AUDIO_Y_IIR2GPF2_b1H                          0xF24510UL
#define AUDIO_Y_IIR2GPF2_b1L                          0xF2450FUL
#define AUDIO_Y_IIR2GPF2_b2H                          0xF24512UL
#define AUDIO_Y_IIR2GPF2_b2L                          0xF24511UL
#define AUDIO_Y_IIR2GPF3L_a1H                         0xF2451EUL
#define AUDIO_Y_IIR2GPF3L_a1L                         0xF2451DUL
#define AUDIO_Y_IIR2GPF3L_a2H                         0xF24520UL
#define AUDIO_Y_IIR2GPF3L_a2L                         0xF2451FUL
#define AUDIO_Y_IIR2GPF3L_b0H                         0xF24518UL
#define AUDIO_Y_IIR2GPF3L_b0L                         0xF24517UL
#define AUDIO_Y_IIR2GPF3L_b1H                         0xF2451AUL
#define AUDIO_Y_IIR2GPF3L_b1L                         0xF24519UL
#define AUDIO_Y_IIR2GPF3L_b2H                         0xF2451CUL
#define AUDIO_Y_IIR2GPF3L_b2L                         0xF2451BUL
#define AUDIO_Y_IIR2GPF3R_a1H                         0xF24528UL
#define AUDIO_Y_IIR2GPF3R_a1L                         0xF24527UL
#define AUDIO_Y_IIR2GPF3R_a2H                         0xF2452AUL
#define AUDIO_Y_IIR2GPF3R_a2L                         0xF24529UL
#define AUDIO_Y_IIR2GPF3R_b0H                         0xF24522UL
#define AUDIO_Y_IIR2GPF3R_b0L                         0xF24521UL
#define AUDIO_Y_IIR2GPF3R_b1H                         0xF24524UL
#define AUDIO_Y_IIR2GPF3R_b1L                         0xF24523UL
#define AUDIO_Y_IIR2GPF3R_b2H                         0xF24526UL
#define AUDIO_Y_IIR2GPF3R_b2L                         0xF24525UL
#define AUDIO_Y_IIR2GPF4_a1H                          0xF24532UL
#define AUDIO_Y_IIR2GPF4_a1L                          0xF24531UL
#define AUDIO_Y_IIR2GPF4_a2H                          0xF24534UL
#define AUDIO_Y_IIR2GPF4_a2L                          0xF24533UL
#define AUDIO_Y_IIR2GPF4_b0H                          0xF2452CUL
#define AUDIO_Y_IIR2GPF4_b0L                          0xF2452BUL
#define AUDIO_Y_IIR2GPF4_b1H                          0xF2452EUL
#define AUDIO_Y_IIR2GPF4_b1L                          0xF2452DUL
#define AUDIO_Y_IIR2GPF4_b2H                          0xF24530UL
#define AUDIO_Y_IIR2GPF4_b2L                          0xF2452FUL
#define AUDIO_Y_IIR2GPF5_a1H                          0xF2453CUL
#define AUDIO_Y_IIR2GPF5_a1L                          0xF2453BUL
#define AUDIO_Y_IIR2GPF5_a2H                          0xF2453EUL
#define AUDIO_Y_IIR2GPF5_a2L                          0xF2453DUL
#define AUDIO_Y_IIR2GPF5_b0H                          0xF24536UL
#define AUDIO_Y_IIR2GPF5_b0L                          0xF24535UL
#define AUDIO_Y_IIR2GPF5_b1H                          0xF24538UL
#define AUDIO_Y_IIR2GPF5_b1L                          0xF24537UL
#define AUDIO_Y_IIR2GPF5_b2H                          0xF2453AUL
#define AUDIO_Y_IIR2GPF5_b2L                          0xF24539UL
#define AUDIO_Y_IIR2GPFL_a1H                          0xF24500UL
#define AUDIO_Y_IIR2GPFL_a1L                          0xF244FFUL
#define AUDIO_Y_IIR2GPFL_a2H                          0xF24502UL
#define AUDIO_Y_IIR2GPFL_a2L                          0xF24501UL
#define AUDIO_Y_IIR2GPFL_b0H                          0xF244FAUL
#define AUDIO_Y_IIR2GPFL_b0L                          0xF244F9UL
#define AUDIO_Y_IIR2GPFL_b1H                          0xF244FCUL
#define AUDIO_Y_IIR2GPFL_b1L                          0xF244FBUL
#define AUDIO_Y_IIR2GPFL_b2H                          0xF244FEUL
#define AUDIO_Y_IIR2GPFL_b2L                          0xF244FDUL
#define AUDIO_Y_IIR2GPFR_a1H                          0xF2450AUL
#define AUDIO_Y_IIR2GPFR_a1L                          0xF24509UL
#define AUDIO_Y_IIR2GPFR_a2H                          0xF2450CUL
#define AUDIO_Y_IIR2GPFR_a2L                          0xF2450BUL
#define AUDIO_Y_IIR2GPFR_b0H                          0xF24504UL
#define AUDIO_Y_IIR2GPFR_b0L                          0xF24503UL
#define AUDIO_Y_IIR2GPFR_b1H                          0xF24506UL
#define AUDIO_Y_IIR2GPFR_b1L                          0xF24505UL
#define AUDIO_Y_IIR2GPFR_b2H                          0xF24508UL
#define AUDIO_Y_IIR2GPFR_b2L                          0xF24507UL
#define AUDIO_Y_Loudf_a1bH                            0xF2458AUL
#define AUDIO_Y_Loudf_a1bL                            0xF24589UL
#define AUDIO_Y_Loudf_a1t                             0xF24591UL
#define AUDIO_Y_Loudf_a2bH                            0xF2458CUL
#define AUDIO_Y_Loudf_a2bL                            0xF2458BUL
#define AUDIO_Y_Loudf_a2t                             0xF24592UL
#define AUDIO_Y_Loudf_alphaB                          0xF2459BUL
#define AUDIO_Y_Loudf_alphaT                          0xF245A2UL
#define AUDIO_Y_Loudf_b0bH                            0xF2458EUL
#define AUDIO_Y_Loudf_b0bL                            0xF2458DUL
#define AUDIO_Y_Loudf_b0t                             0xF24593UL
#define AUDIO_Y_Loudf_b1t                             0xF24594UL
#define AUDIO_Y_Loudf_b2bH                            0xF24590UL
#define AUDIO_Y_Loudf_b2bL                            0xF2458FUL
#define AUDIO_Y_Loudf_b2t                             0xF24595UL
#define AUDIO_Y_Loudf_Gbas                            0xF24596UL
#define AUDIO_Y_Loudf_GchanCorrect                    0xF245AEUL
#define AUDIO_Y_Loudf_Gtre                            0xF24597UL
#define AUDIO_Y_Loudf_KmBH                            0xF2459FUL
#define AUDIO_Y_Loudf_KmBL                            0xF2459EUL
#define AUDIO_Y_Loudf_KmTH                            0xF245A6UL
#define AUDIO_Y_Loudf_KmTL                            0xF245A5UL
#define AUDIO_Y_Loudf_KpBH                            0xF2459DUL
#define AUDIO_Y_Loudf_KpBL                            0xF2459CUL
#define AUDIO_Y_Loudf_KpTH                            0xF245A4UL
#define AUDIO_Y_Loudf_KpTL                            0xF245A3UL
#define AUDIO_Y_Loudf_MaxBstB                         0xF245A0UL
#define AUDIO_Y_Loudf_MaxBstT                         0xF245A7UL
#define AUDIO_Y_Loudf_OffsB                           0xF2459AUL
#define AUDIO_Y_Loudf_OffsT                           0xF245A1UL
#define AUDIO_Y_Loudf_StatLev                         0xF24599UL
#define AUDIO_Y_Loudf_StatLevT                        0xF24598UL
#define AUDIO_Y_Mute_N                                0xF2433DUL
#define AUDIO_Y_Mute_P                                0xF2433BUL
#define AUDIO_Y_Mute_S                                0xF2433CUL
#define AUDIO_Y_Mute_T                                0xF2433EUL
#define AUDIO_Y_MuteSix_FL                            0xF2433FUL
#define AUDIO_Y_MuteSix_FR                            0xF24340UL
#define AUDIO_Y_MuteSix_RL                            0xF24341UL
#define AUDIO_Y_MuteSix_RR                            0xF24342UL
#define AUDIO_Y_MuteSix_SwL                           0xF24343UL
#define AUDIO_Y_MuteSix_SwR                           0xF24344UL
#define AUDIO_Y_NG_a01                                0xF24577UL
#define AUDIO_Y_NG_a02                                0xF2457AUL
#define AUDIO_Y_NG_a03                                0xF2457DUL
#define AUDIO_Y_NG_a11                                0xF24576UL
#define AUDIO_Y_NG_a12                                0xF24579UL
#define AUDIO_Y_NG_a13                                0xF2457CUL
#define AUDIO_Y_NG_b11                                0xF24578UL
#define AUDIO_Y_NG_b12                                0xF2457BUL
#define AUDIO_Y_NG_b13                                0xF2457EUL
#define AUDIO_Y_NG_GL                                 0xF2457FUL
#define AUDIO_Y_NG_GR                                 0xF24580UL
#define AUDIO_Y_PCHIME_Ampli_LFO                      0xF24671UL
#define AUDIO_Y_PCHIME_Env1_DecayCoef_LSB             0xF24675UL
#define AUDIO_Y_PCHIME_Env1_DecayCoef_MSB             0xF24674UL
#define AUDIO_Y_PCHIME_Env1_DelayVolume               0xF24673UL
#define AUDIO_Y_PCHIME_Env2_DecayCoef_LSB             0xF24678UL
#define AUDIO_Y_PCHIME_Env2_DecayCoef_MSB             0xF24677UL
#define AUDIO_Y_PCHIME_Env2_DelayVolume               0xF24676UL
#define AUDIO_Y_PCHIME_Env3_DecayCoef_LSB             0xF2467BUL
#define AUDIO_Y_PCHIME_Env3_DecayCoef_MSB             0xF2467AUL
#define AUDIO_Y_PCHIME_Env3_DelayVolume               0xF24679UL
#define AUDIO_Y_PCHIME_Freq1_LSB                      0xF24660UL
#define AUDIO_Y_PCHIME_Freq1_MSB                      0xF2465FUL
#define AUDIO_Y_PCHIME_Freq2_LSB                      0xF24663UL
#define AUDIO_Y_PCHIME_Freq2_MSB                      0xF24662UL
#define AUDIO_Y_PCHIME_Freq3_LSB                      0xF24666UL
#define AUDIO_Y_PCHIME_Freq3_MSB                      0xF24665UL
#define AUDIO_Y_PCHIME_Freq4_LSB                      0xF24669UL
#define AUDIO_Y_PCHIME_Freq4_MSB                      0xF24668UL
#define AUDIO_Y_PCHIME_Freq5_LSB                      0xF2466CUL
#define AUDIO_Y_PCHIME_Freq5_MSB                      0xF2466BUL
#define AUDIO_Y_PCHIME_Freq6_LSB                      0xF2466FUL
#define AUDIO_Y_PCHIME_Freq6_MSB                      0xF2466EUL
#define AUDIO_Y_PCHIME_Offset_LFO                     0xF24672UL
#define AUDIO_Y_PCHIME_SMute_DecayCoef_LSB            0xF2467DUL
#define AUDIO_Y_PCHIME_SMute_DecayCoef_MSB            0xF2467CUL
#define AUDIO_Y_PCHIME_Volume1                        0xF24661UL
#define AUDIO_Y_PCHIME_Volume2                        0xF24664UL
#define AUDIO_Y_PCHIME_Volume3                        0xF24667UL
#define AUDIO_Y_PCHIME_Volume4                        0xF2466AUL
#define AUDIO_Y_PCHIME_Volume5                        0xF2466DUL
#define AUDIO_Y_PCHIME_Volume6                        0xF24670UL
#define AUDIO_Y_QPD_kmH1                              0xF24584UL
#define AUDIO_Y_QPD_kmH2                              0xF24588UL
#define AUDIO_Y_QPD_kmL1                              0xF24583UL
#define AUDIO_Y_QPD_kmL2                              0xF24587UL
#define AUDIO_Y_QPD_kpH1                              0xF24582UL
#define AUDIO_Y_QPD_kpH2                              0xF24586UL
#define AUDIO_Y_QPD_kpL1                              0xF24581UL
#define AUDIO_Y_QPD_kpL2                              0xF24585UL
#define AUDIO_Y_RstChk                                0xF246E9UL
#define AUDIO_Y_SCD_kmH0                              0xF24685UL
#define AUDIO_Y_SCD_kmH1                              0xF24689UL
#define AUDIO_Y_SCD_kmH2                              0xF2468DUL
#define AUDIO_Y_SCD_kmH3                              0xF24691UL
#define AUDIO_Y_SCD_kmL0                              0xF24684UL
#define AUDIO_Y_SCD_kmL1                              0xF24688UL
#define AUDIO_Y_SCD_kmL2                              0xF2468CUL
#define AUDIO_Y_SCD_kmL3                              0xF24690UL
#define AUDIO_Y_SCD_kpH0                              0xF24683UL
#define AUDIO_Y_SCD_kpH1                              0xF24687UL
#define AUDIO_Y_SCD_kpH2                              0xF2468BUL
#define AUDIO_Y_SCD_kpH3                              0xF2468FUL
#define AUDIO_Y_SCD_kpL0                              0xF24682UL
#define AUDIO_Y_SCD_kpL1                              0xF24686UL
#define AUDIO_Y_SCD_kpL2                              0xF2468AUL
#define AUDIO_Y_SCD_kpL3                              0xF2468EUL
#define AUDIO_Y_SinGen_aHbak                          0xF245F5UL
#define AUDIO_Y_SinGen_aLbak                          0xF245F6UL
#define AUDIO_Y_SinGen_GL                             0xF245FBUL
#define AUDIO_Y_SinGen_GR                             0xF245FCUL
#define AUDIO_Y_SinGen_Init                           0xF245F7UL
#define AUDIO_Y_Sup_ChionFL                           0xF2439BUL
#define AUDIO_Y_Sup_ChionFR                           0xF2439CUL
#define AUDIO_Y_Sup_ChionRL                           0xF2439DUL
#define AUDIO_Y_Sup_ChionRR                           0xF2439EUL
#define AUDIO_Y_Sup_ChionSL                           0xF243A1UL
#define AUDIO_Y_Sup_ChionSR                           0xF243A2UL
#define AUDIO_Y_Sup_ChionSW                           0xF2439FUL
#define AUDIO_Y_Sup_ChionSwR                          0xF243A0UL
#define AUDIO_Y_Sup_ExtonFL                           0xF24393UL
#define AUDIO_Y_Sup_ExtonFR                           0xF24394UL
#define AUDIO_Y_Sup_ExtonRL                           0xF24395UL
#define AUDIO_Y_Sup_ExtonRR                           0xF24396UL
#define AUDIO_Y_Sup_ExtonSL                           0xF24399UL
#define AUDIO_Y_Sup_ExtonSR                           0xF2439AUL
#define AUDIO_Y_Sup_ExtonSW                           0xF24397UL
#define AUDIO_Y_Sup_ExtonSwR                          0xF24398UL
#define AUDIO_Y_Sup_Filta                             0xF243AFUL
#define AUDIO_Y_Sup_Filtb                             0xF243B0UL
#define AUDIO_Y_Sup_NonFL                             0xF24388UL
#define AUDIO_Y_Sup_NonFR                             0xF24389UL
#define AUDIO_Y_Sup_NonRL                             0xF2438AUL
#define AUDIO_Y_Sup_NonRR                             0xF2438BUL
#define AUDIO_Y_Sup_NonSW                             0xF2438CUL
#define AUDIO_Y_Sup_PDC1onFL                          0xF243A3UL
#define AUDIO_Y_Sup_PDC1onFR                          0xF243A4UL
#define AUDIO_Y_Sup_PDC1onRL                          0xF243A5UL
#define AUDIO_Y_Sup_PDC1onRR                          0xF243A6UL
#define AUDIO_Y_Sup_PDC1onSL                          0xF243A9UL
#define AUDIO_Y_Sup_PDC1onSR                          0xF243AAUL
#define AUDIO_Y_Sup_PDC1onSW                          0xF243A7UL
#define AUDIO_Y_Sup_PDC1onSwR                         0xF243A8UL
#define AUDIO_Y_Sup_PDC2onFL                          0xF243ABUL
#define AUDIO_Y_Sup_PDC2onFR                          0xF243ACUL
#define AUDIO_Y_Sup_PDC2onRL                          0xF243ADUL
#define AUDIO_Y_Sup_PDC2onRR                          0xF243AEUL
#define AUDIO_Y_Sup_sChionFL                          0xF246E1UL
#define AUDIO_Y_Sup_sChionFR                          0xF246E2UL
#define AUDIO_Y_Sup_sChionRL                          0xF246E3UL
#define AUDIO_Y_Sup_sChionRR                          0xF246E4UL
#define AUDIO_Y_Sup_sChionSL                          0xF246E7UL
#define AUDIO_Y_Sup_sChionSR                          0xF246E8UL
#define AUDIO_Y_Sup_sChionSW                          0xF246E5UL
#define AUDIO_Y_Sup_sChionSwR                         0xF246E6UL
#define AUDIO_Y_Sup_sExtonFL                          0xF246D9UL
#define AUDIO_Y_Sup_sExtonFR                          0xF246DAUL
#define AUDIO_Y_Sup_sExtonRL                          0xF246DBUL
#define AUDIO_Y_Sup_sExtonRR                          0xF246DCUL
#define AUDIO_Y_Sup_sExtonSL                          0xF246DFUL
#define AUDIO_Y_Sup_sExtonSR                          0xF246E0UL
#define AUDIO_Y_Sup_sExtonSW                          0xF246DDUL
#define AUDIO_Y_Sup_sExtonSwR                         0xF246DEUL
#define AUDIO_Y_Sup_sNonFL                            0xF246CEUL
#define AUDIO_Y_Sup_sNonFR                            0xF246CFUL
#define AUDIO_Y_Sup_sNonRL                            0xF246D0UL
#define AUDIO_Y_Sup_sNonRR                            0xF246D1UL
#define AUDIO_Y_Sup_sNonSW                            0xF246D2UL
#define AUDIO_Y_Sup_sTonFL                            0xF246D3UL
#define AUDIO_Y_Sup_sTonFR                            0xF246D4UL
#define AUDIO_Y_Sup_sTonRL                            0xF246D5UL
#define AUDIO_Y_Sup_sTonRR                            0xF246D6UL
#define AUDIO_Y_Sup_sTonSW                            0xF246D7UL
#define AUDIO_Y_Sup_sTonSwR                           0xF246D8UL
#define AUDIO_Y_Sup_TonFL                             0xF2438DUL
#define AUDIO_Y_Sup_TonFR                             0xF2438EUL
#define AUDIO_Y_Sup_TonRL                             0xF2438FUL
#define AUDIO_Y_Sup_TonRR                             0xF24390UL
#define AUDIO_Y_Sup_TonSW                             0xF24391UL
#define AUDIO_Y_Sup_TonSwR                            0xF24392UL
#define AUDIO_Y_SupB_In1onFL                          0xF246EEUL
#define AUDIO_Y_SupB_In1onFR                          0xF246F2UL
#define AUDIO_Y_SupB_In1onRL                          0xF246F6UL
#define AUDIO_Y_SupB_In1onRR                          0xF246FAUL
#define AUDIO_Y_SupB_In1onSW                          0xF246FEUL
#define AUDIO_Y_SupB_In1onSWR                         0xF24702UL
#define AUDIO_Y_SupB_In2onFL                          0xF246EFUL
#define AUDIO_Y_SupB_In2onFR                          0xF246F3UL
#define AUDIO_Y_SupB_In2onRL                          0xF246F7UL
#define AUDIO_Y_SupB_In2onRR                          0xF246FBUL
#define AUDIO_Y_SupB_In2onSW                          0xF246FFUL
#define AUDIO_Y_SupB_In2onSWR                         0xF24703UL
#define AUDIO_Y_SupB_In3onFL                          0xF246F0UL
#define AUDIO_Y_SupB_In3onFR                          0xF246F4UL
#define AUDIO_Y_SupB_In3onRL                          0xF246F8UL
#define AUDIO_Y_SupB_In3onRR                          0xF246FCUL
#define AUDIO_Y_SupB_In3onSW                          0xF24700UL
#define AUDIO_Y_SupB_In3onSWR                         0xF24704UL
#define AUDIO_Y_SupB_In4onFL                          0xF246F1UL
#define AUDIO_Y_SupB_In4onFR                          0xF246F5UL
#define AUDIO_Y_SupB_In4onRL                          0xF246F9UL
#define AUDIO_Y_SupB_In4onRR                          0xF246FDUL
#define AUDIO_Y_SupB_In4onSW                          0xF24701UL
#define AUDIO_Y_SupB_In4onSWR                         0xF24705UL
#define AUDIO_Y_TG2_VL                                0xF245F3UL
#define AUDIO_Y_TG2_VR                                0xF245F4UL
#define AUDIO_Y_Tsq_ArType_Bk                         0xF243CDUL
#define AUDIO_Y_Tsq_c02_Bk                            0xF243E4UL
#define AUDIO_Y_Tsq_c1_Bk                             0xF243E5UL
#define AUDIO_Y_Tsq_c3_Bk                             0xF243E6UL
#define AUDIO_Y_Tsq_ChimeVol                          0xF243C8UL
#define AUDIO_Y_Tsq_ChimeVol_Bk                       0xF243E3UL
#define AUDIO_Y_Tsq_Copied                            0xF243CAUL
#define AUDIO_Y_Tsq_SeqStat                           0xF243B2UL
#define AUDIO_Y_Tsq_SeqStat_Bk                        0xF243CEUL
#define AUDIO_Y_Tsq_T1b1Htone_Bk                      0xF243D0UL
#define AUDIO_Y_Tsq_T1b1Ltone_Bk                      0xF243CFUL
#define AUDIO_Y_Tsq_T1Clip_Bk                         0xF243D2UL
#define AUDIO_Y_Tsq_T1Type_Bk                         0xF243D3UL
#define AUDIO_Y_Tsq_T1Vtone_Bk                        0xF243D1UL
#define AUDIO_Y_Tsq_T2b1Htone_Bk                      0xF243D5UL
#define AUDIO_Y_Tsq_T2b1Ltone_Bk                      0xF243D4UL
#define AUDIO_Y_Tsq_T2Clip_Bk                         0xF243D7UL
#define AUDIO_Y_Tsq_T2Type_Bk                         0xF243D8UL
#define AUDIO_Y_Tsq_T2Vtone_Bk                        0xF243D6UL
#define AUDIO_Y_Tsq_T3b1Htone_Bk                      0xF243DAUL
#define AUDIO_Y_Tsq_T3b1Ltone_Bk                      0xF243D9UL
#define AUDIO_Y_Tsq_T3Clip_Bk                         0xF243DCUL
#define AUDIO_Y_Tsq_T3Type_Bk                         0xF243DDUL
#define AUDIO_Y_Tsq_T3Vtone_Bk                        0xF243DBUL
#define AUDIO_Y_Tsq_T4b1Htone_Bk                      0xF243DFUL
#define AUDIO_Y_Tsq_T4b1Ltone_Bk                      0xF243DEUL
#define AUDIO_Y_Tsq_T4Clip_Bk                         0xF243E1UL
#define AUDIO_Y_Tsq_T4Type_Bk                         0xF243E2UL
#define AUDIO_Y_Tsq_T4Vtone_Bk                        0xF243E0UL
#define AUDIO_Y_UpdatC_Coeff0                         0xF242CEUL
#define AUDIO_Y_UpdatC_Coeff1                         0xF242CFUL
#define AUDIO_Y_UpdatC_Coeff2                         0xF242D0UL
#define AUDIO_Y_UpdatC_Coeff3                         0xF242D1UL
#define AUDIO_Y_UpdatC_Coeff4                         0xF242D2UL
#define AUDIO_Y_UpdatC_Coeff5                         0xF242D3UL
#define AUDIO_Y_UpdatC_Coeff6                         0xF242D4UL
#define AUDIO_Y_UpdatC_Coeff7                         0xF242D5UL
#define AUDIO_Y_UpdatC_Coeff8                         0xF242D6UL
#define AUDIO_Y_UpdatC_Coeff9                         0xF242D7UL
#define AUDIO_Y_UpdatC_CoeffA                         0xF242D8UL
#define AUDIO_Y_UpdatC_CoeffB                         0xF242D9UL
#define AUDIO_Y_Vol_BalPL                             0xF242F3UL
#define AUDIO_Y_Vol_BalPR                             0xF242F4UL
#define AUDIO_Y_Vol_BalSL                             0xF242F9UL
#define AUDIO_Y_Vol_BalSR                             0xF242FAUL
#define AUDIO_Y_Vol_BalSwL                            0xF242F7UL
#define AUDIO_Y_Vol_BalSwR                            0xF242F8UL
#define AUDIO_Y_Vol_ChanGainN                         0xF2432CUL
#define AUDIO_Y_Vol_ChanGainPFL                       0xF24324UL
#define AUDIO_Y_Vol_ChanGainPFR                       0xF24325UL
#define AUDIO_Y_Vol_ChanGainPRL                       0xF24326UL
#define AUDIO_Y_Vol_ChanGainPRR                       0xF24327UL
#define AUDIO_Y_Vol_ChanGainSL                        0xF2432AUL
#define AUDIO_Y_Vol_ChanGainSR                        0xF2432BUL
#define AUDIO_Y_Vol_ChanGainSwL                       0xF24328UL
#define AUDIO_Y_Vol_ChanGainSwR                       0xF24329UL
#define AUDIO_Y_Vol_ChanGainT                         0xF2432DUL
#define AUDIO_Y_Vol_DesScalBMTP                       0xF24345UL
#define AUDIO_Y_Vol_DesScalBMTS                       0xF24349UL
#define AUDIO_Y_Vol_DesScalGEq                        0xF24348UL
#define AUDIO_Y_Vol_FadF                              0xF242F1UL
#define AUDIO_Y_Vol_FadR                              0xF242F2UL
#define AUDIO_Y_Vol_FadSwL                            0xF242F5UL
#define AUDIO_Y_Vol_FadSwR                            0xF242F6UL
#define AUDIO_Y_Vol_Filtera                           0xF242EEUL
#define AUDIO_Y_Vol_Filterb                           0xF242EDUL
#define AUDIO_Y_Vol_FLonSwL                           0xF24357UL
#define AUDIO_Y_Vol_FLonSwR                           0xF2435BUL
#define AUDIO_Y_Vol_FRonSwL                           0xF24358UL
#define AUDIO_Y_Vol_FRonSwR                           0xF2435CUL
#define AUDIO_Y_Vol_Main1P                            0xF2431EUL
#define AUDIO_Y_Vol_Main1S                            0xF24320UL
#define AUDIO_Y_Vol_Main2P                            0xF2431FUL
#define AUDIO_Y_Vol_Main2S                            0xF24321UL
#define AUDIO_Y_Vol_Nav                               0xF2431CUL
#define AUDIO_Y_Vol_Phon                              0xF2431DUL
#define AUDIO_Y_Vol_RLonSwL                           0xF24359UL
#define AUDIO_Y_Vol_RLonSwR                           0xF2435DUL
#define AUDIO_Y_Vol_RRonSwL                           0xF2435AUL
#define AUDIO_Y_Vol_RRonSwR                           0xF2435EUL
#define AUDIO_Y_Vol_ScalF                             0xF242FDUL
#define AUDIO_Y_Vol_ScalR                             0xF242FEUL
#define AUDIO_Y_Vol_ScalS                             0xF24301UL
#define AUDIO_Y_Vol_ScalSwL                           0xF242FFUL
#define AUDIO_Y_Vol_ScalSwR                           0xF24300UL
#define AUDIO_Y_Vol_SignFL                            0xF2434DUL
#define AUDIO_Y_Vol_SignFR                            0xF2434EUL
#define AUDIO_Y_Vol_SignRL                            0xF2434FUL
#define AUDIO_Y_Vol_SignRR                            0xF24350UL
#define AUDIO_Y_Vol_SignSwL                           0xF24351UL
#define AUDIO_Y_Vol_SignSwR                           0xF24352UL
#define AUDIO_Y_Vol_SrcScalN                          0xF24355UL
#define AUDIO_Y_Vol_SrcScalP                          0xF242FBUL
#define AUDIO_Y_Vol_SrcScalS                          0xF24354UL
#define AUDIO_Y_Vol_SrcScalT                          0xF24356UL
#define AUDIO_Y_Vol_UpScalF                           0xF24302UL
#define AUDIO_Y_Vol_UpScalR                           0xF24303UL
#define AUDIO_Y_Vol_UpScalS                           0xF24306UL
#define AUDIO_Y_Vol_UpScalSwL                         0xF24304UL
#define AUDIO_Y_Vol_UpScalSwR                         0xF24305UL

/* AUDIO EasyP entries */
#define AUDIO_EASYP_ALE_Disable                       0x00FEUL
#define AUDIO_EASYP_ALE_Enable                        0x00FCUL
#define AUDIO_EASYP_AUB2_Disable                      0x0056UL
#define AUDIO_EASYP_AUB2_Enable                       0x0055UL
#define AUDIO_EASYP_CheckSum_Enable                   0x008EUL
#define AUDIO_EASYP_Chime_Enable                      0x0088UL
#define AUDIO_EASYP_Chime_PSAlt                       0x007CUL
#define AUDIO_EASYP_Chime_PSBle1                      0x007EUL
#define AUDIO_EASYP_Chime_PSCci                       0x007AUL
#define AUDIO_EASYP_Chime_PSFsb                       0x0076UL
#define AUDIO_EASYP_Chime_PSKii                       0x0078UL
#define AUDIO_EASYP_ChimePDC_Disable                  0x00E0UL
#define AUDIO_EASYP_ClickClack_Disable                0x00DCUL
#define AUDIO_EASYP_ClickClack_Enable                 0x00DEUL
#define AUDIO_EASYP_CompExp_CompExpExpOnly            0x004FUL
#define AUDIO_EASYP_CompExp_CompExpHigh               0x004CUL
#define AUDIO_EASYP_CompExp_CompExpLow                0x004EUL
#define AUDIO_EASYP_CompExp_CompExpMid                0x004DUL
#define AUDIO_EASYP_CompExp_Update                    0x0038UL
#define AUDIO_EASYP_DCDeemphFilter_I2S1A              0x0058UL
#define AUDIO_EASYP_DCDeemphFilter_I2S1B              0x0060UL
#define AUDIO_EASYP_DCDeemphFilter_NoDmphA            0x005EUL
#define AUDIO_EASYP_DCDeemphFilter_NoDmphB            0x0066UL
#define AUDIO_EASYP_DCDeemphFilter_SPdif1A            0x005AUL
#define AUDIO_EASYP_DCDeemphFilter_SPdif1B            0x0062UL
#define AUDIO_EASYP_GPF_Disable                       0x0080UL
#define AUDIO_EASYP_GPF_headroom                      0x0096UL
#define AUDIO_EASYP_GPF2_Disable                      0x0082UL
#define AUDIO_EASYP_GPF2_headroom                     0x0098UL
#define AUDIO_EASYP_GPF3_Disable                      0x0084UL
#define AUDIO_EASYP_GPF3_headroom                     0x009AUL
#define AUDIO_EASYP_GPF4_Disable                      0x0094UL
#define AUDIO_EASYP_GPF4_headroom                     0x009CUL
#define AUDIO_EASYP_GPF5_Disable                      0x00A8UL
#define AUDIO_EASYP_GPF5_headroom                     0x00A6UL
#define AUDIO_EASYP_GraphEQ_9Band_Disable             0x0052UL
#define AUDIO_EASYP_GraphEQ_9Band_Enable              0x0086UL
#define AUDIO_EASYP_GSA_Disable                       0x0051UL
#define AUDIO_EASYP_GSA_Enable                        0x0050UL
#define AUDIO_EASYP_Limit_LimitRSOnRear               0x0039UL
#define AUDIO_EASYP_Limit_LimitRSOnSec                0x003AUL
#define AUDIO_EASYP_Loudf_StaticCoupled               0x00B0UL
#define AUDIO_EASYP_Loudf_StaticIndep                 0x00AEUL
#define AUDIO_EASYP_NoiseGen_Enable                   0x008CUL
#define AUDIO_EASYP_NoiseGen_NoiseOnPrim              0x0068UL
#define AUDIO_EASYP_NoiseGen_NoiseOnSec               0x006AUL
#define AUDIO_EASYP_NoiseGen_SinGen_CheckSum_Disable  0x0092UL
#define AUDIO_EASYP_PchannelMonoLeft                  0x0072UL
#define AUDIO_EASYP_PchannelMonoRight                 0x0074UL
#define AUDIO_EASYP_PchannelStereo                    0x0070UL
#define AUDIO_EASYP_PCHIME_Disable                    0x00A4UL
#define AUDIO_EASYP_PCHIME_Enable                     0x00A2UL
#define AUDIO_EASYP_PCHIME_IMGpreset                  0x0042UL
#define AUDIO_EASYP_PEQ_Center_IIR_passthrough        0x00E2UL
#define AUDIO_EASYP_PEQ_Center_IIR2_headroom          0x00E4UL
#define AUDIO_EASYP_PEQ_Center_IIR3                   0x00E6UL
#define AUDIO_EASYP_PEQ_Center_IIR4_headroom          0x00E8UL
#define AUDIO_EASYP_PEQ_Center_IIR6_headroom          0x00EAUL
#define AUDIO_EASYP_PEQ_Center_IIR8_headroom          0x00ECUL
#define AUDIO_EASYP_PEQ_Sw_IIR_passthrough            0x00EEUL
#define AUDIO_EASYP_PEQ_Sw_IIR2_headroom              0x00F0UL
#define AUDIO_EASYP_PEQ_Sw_IIR3                       0x00F2UL
#define AUDIO_EASYP_PEQ_Sw_IIR4_headroom              0x00F4UL
#define AUDIO_EASYP_PEQ_Sw_IIR6_headroom              0x00F6UL
#define AUDIO_EASYP_PEQ_Sw_IIR8_headroom              0x00F8UL
#define AUDIO_EASYP_SinGen_Enable                     0x0090UL
#define AUDIO_EASYP_SinGen_SineOnPrim                 0x003DUL
#define AUDIO_EASYP_SinGen_SineOnSec                  0x003EUL
#define AUDIO_EASYP_SrcSw_AIN0onA                     0x0019UL
#define AUDIO_EASYP_SrcSw_AIN0onB                     0x001AUL
#define AUDIO_EASYP_SrcSw_AIN1onA                     0x001DUL
#define AUDIO_EASYP_SrcSw_AIN1onB                     0x001EUL
#define AUDIO_EASYP_SrcSw_AIN23onA                    0x0021UL
#define AUDIO_EASYP_SrcSw_AIN23onB                    0x0022UL
#define AUDIO_EASYP_SrcSw_AIN2onPhone                 0x0035UL
#define AUDIO_EASYP_SrcSw_AIN3onNav                   0x0033UL
#define AUDIO_EASYP_SrcSw_HostI2S0onA                 0x002FUL
#define AUDIO_EASYP_SrcSw_HostI2S0onB                 0x0030UL
#define AUDIO_EASYP_SrcSw_HostI2S1onA                 0x0031UL
#define AUDIO_EASYP_SrcSw_HostI2S1onB                 0x0032UL
#define AUDIO_EASYP_SrcSw_I2S0onA                     0x0023UL
#define AUDIO_EASYP_SrcSw_I2S0onB                     0x0024UL
#define AUDIO_EASYP_SrcSw_I2S1onA                     0x0025UL
#define AUDIO_EASYP_SrcSw_I2S1onB                     0x0026UL
#define AUDIO_EASYP_SrcSw_I2S2onA                     0x0027UL
#define AUDIO_EASYP_SrcSw_I2S2onB                     0x0028UL
#define AUDIO_EASYP_SrcSw_IBOConA                     0x0017UL
#define AUDIO_EASYP_SrcSw_IBOConB                     0x0018UL
#define AUDIO_EASYP_SrcSw_SPDIFonA                    0x002BUL
#define AUDIO_EASYP_SrcSw_SPDIFonB                    0x002CUL
#define AUDIO_EASYP_SrcSw_Tuner1onA                   0x0013UL
#define AUDIO_EASYP_SrcSw_Tuner1onB                   0x0014UL
#define AUDIO_EASYP_SupPos_BypassSmooth               0x00CAUL
#define AUDIO_EASYP_SupPos_PDC2Disable                0x00BEUL
#define AUDIO_EASYP_SupPos_PDC2Enable                 0x00BCUL
#define AUDIO_EASYP_SupPos_Smooth1                    0x00C8UL
#define AUDIO_EASYP_UpdateCoeff_Coeff10               0x000AUL
#define AUDIO_EASYP_UpdateCoeff_Coeff11               0x000BUL
#define AUDIO_EASYP_UpdateCoeff_Coeff12               0x000CUL
#define AUDIO_EASYP_UpdateCoeff_Coeff2                0x0002UL
#define AUDIO_EASYP_UpdateCoeff_Coeff3                0x0003UL
#define AUDIO_EASYP_UpdateCoeff_Coeff4                0x0004UL
#define AUDIO_EASYP_UpdateCoeff_Coeff5                0x0005UL
#define AUDIO_EASYP_UpdateCoeff_Coeff6                0x0006UL
#define AUDIO_EASYP_UpdateCoeff_Coeff7                0x0007UL
#define AUDIO_EASYP_UpdateCoeff_Coeff8                0x0008UL
#define AUDIO_EASYP_UpdateCoeff_Coeff9                0x0009UL
/*end of Register Addr define*/


/*
* ****************   Tables Begin  **********************
*/


/* dB 2 Linear conversion Table     */
/* Generated by MATLAB scripts      */
/* unversioned                      */
/*  dB2Lin(x) = POWER(10, - x/20)   */
/*                                  */
/* 12 bits Coefficients LSB aligned */
/* Type UInt32 for BBP driver       */
/*                                  */
/* MIN_INF included                 */
/* array size + 1                   */

static const uint32_t table_dB2Lin[-MINUS_INF + 1] =
{
    0x07FF,   /*  00dB =  1.00 */
    0x0721,   /* -01dB =  0.89 */
    0x065A,   /* -02dB    */
    0x05A8,   /* -03dB    */
    0x050A,   /* -04dB    */
    0x047D,   /* -05dB    */
    0x0400,   /* -06dB    */
    0x0390,   /* -07dB    */
    0x032D,   /* -08dB    */
    0x02D4,   /* -09dB    */
    0x0285,   /* -10dB    */
    0x023F,   /* -11dB    */
    0x0200,   /* -12dB    */
    0x01C8,   /* -13dB    */
    0x0196,   /* -14dB    */
    0x016A,   /* -15dB    */
    0x0143,   /* -16dB    */
    0x011F,   /* -17dB    */
    0x0100,   /* -18dB    */
    0x00E4,   /* -19dB    */
    0x00CB,   /* -20dB    */
    0x00B5,   /* -21dB    */
    0x00A1,   /* -22dB    */
    0x0090,   /* -23dB    */
    0x0080,   /* -24dB    */
    0x0072,   /* -25dB    */
    0x0066,   /* -26dB    */
    0x005B,   /* -27dB    */
    0x0051,   /* -28dB    */
    0x0048,   /* -29dB    */
    0x0040,   /* -30dB    */
    0x0039,   /* -31dB    */
    0x0033,   /* -32dB    */
    0x002D,   /* -33dB    */
    0x0028,   /* -34dB    */
    0x0024,   /* -35dB    */
    0x0020,   /* -36dB    */
    0x001D,   /* -37dB    */
    0x0019,   /* -38dB    */
    0x0017,   /* -39dB    */
    0x0014,   /* -40dB    */
    0x0012,   /* -41dB    */
    0x0010,   /* -42dB    */
    0x000E,   /* -43dB    */
    0x000D,   /* -44dB    */
    0x000B,   /* -45dB    */
    0x000A,   /* -46dB =  0.01 */
    0x0009,   /* -47dB =  0.00 */
    0x0008,   /* -48dB    */
    0x0007,   /* -49dB    */
    0x0006,   /* -50dB    */
    0x0006,   /* -51dB    */
    0x0005,   /* -52dB    */
    0x0004,   /* -53dB    */
    0x0004,   /* -54dB    */
    0x0004,   /* -55dB    */
    0x0003,   /* -56dB    */
    0x0003,   /* -57dB    */
    0x0003,   /* -58dB    */
    0x0002,   /* -59dB    */
    0x0002,   /* -60dB    */
    0x0002,   /* -61dB    */
    0x0002,   /* -62dB    */
    0x0001,   /* -63dB    */
    0x0001,   /* -64dB    */
    0x0001,   /* -65dB =  0.00 */
    0x0001,   /* -66dB =  0.00 */
    0x0001,   /* -67dB =  0.00 */
    0x0001,   /* -68dB =  0.00 */
    0x0001,   /* -69dB =  0.00 */
    0x0001,   /* -70dB =  0.00 */
    0x0001,   /* -71dB =  0.00 */
    0x0001,   /* -72dB =  0.00 */
    0x0000,   /* -73dB =  0.00 */
    0x0000,   /* -74dB =  0.00 */
    0x0000,   /* -75dB =  0.00 */
    0x0000,   /* -76dB =  0.00 */
    0x0000,   /* -77dB =  0.00 */
    0x0000,   /* -78dB =  0.00 */
    0x0000,   /* -79dB =  0.00 */
    0x0000,   /* -80dB =  0.00 */
    0x0000,   /* -81dB =  0.00 */
    0x0000,   /* -82dB =  0.00 */
    0x0000,   /* -83dB =  0.00 */
    0x0000,   /* -84dB =  0.00 */
    0x0000,   /* -85dB =  0.00 */
    0x0000,   /* -86dB =  0.00 */
    0x0000,   /* -87dB =  0.00 */
    0x0000,   /* -88dB =  0.00 */
    0x0000,   /* -89dB =  0.00 */
    0x0000,   /* -90dB =  0.00 */
    0x0000,   /* -91dB =  0.00 */
    0x0000,   /* -92dB =  0.00 */
    0x0000    /* -Infinite dB     */
};/* dB2Lin */






/* coefs are dependant on (fs, f_cutoff)            */
/* b1b does not exist */
/* Table Construction: a1bL, a1bH, a2bL, a2bH, b0bL, b0bH, b2bL, b2bH */
static const uint16_t table_Loudness_BassCoeffs[32] =
{ 
    0x505, 0x7e3, 0x0e5, 0xc1c, 0x10b, 0x000, 0x10b, 0x000, /* fc =  80, fs = SAMP_FREQ_44KHZ */
    0x01f, 0x7cb, 0x0a1, 0xc34, 0x3a0, 0x000, 0x3a0, 0x000, /* fc = 150, fs = SAMP_FREQ_44KHZ */
    0x762, 0x7e5, 0x6db, 0xc19, 0x0e2, 0x000, 0x0e2, 0x000, /* fc =  80, fs = SAMP_FREQ_48KHZ */
    0x24a, 0x7cf, 0x794, 0xc2f, 0x311, 0x000, 0x311, 0x000  /* fc = 150, fs = SAMP_FREQ_48KHZ */
};

/* coefs are dependant on (fs, f_cutoff)            */
/* Table Construction: a1t, a2t, b0t, b1t, b2t */
static const uint16_t table_Loudness_TrebleCoeffs[10] =
{ 
    0x230, 0x000, 0x318, 0xce8, 0x000, /* fc = 4000, fs = SAMP_FREQ_44KHZ */
    0x24F, 0x000, 0x327, 0xcd9, 0x000  /* fc = 4000, fs = SAMP_FREQ_48KHZ */
};









/* used in PrimaryVolumePreset(): */

/* user Bass boost: */
/* StatLev value as a function of BassBoost e [0, 18] */
static const uint16_t table_Loudness_BassB[19] =
{
    0x07ff,  /* 0 dB */
    0x06f1,
    0x0675,
    0x060d,
    0x05ae,
    0x0552,
    0x04f9,
    0x049f,
    0x0444,
    0x03e8,
    0x0389,
    0x0327,
    0x02c2,
    0x0259,
    0x01eb,
    0x0179,
    0x0101,
    0x0084,
    0x0000  /* +18 dB */
};

/* Loudness as a function of Volume (in dB) */
/* this is for Bass Boost Curve*/
static const uint16_t table_Loudness_BassB_curve[26] =
{ 
    0x0784, 0x076a, 0x0750, 0x072c, 0x0703, 0x06d6, 0x06a5, 0x066c, /* 0, .. -7 dB */
    0x062d, 0x05e7, 0x0599, 0x0544, 0x04e7, 0x0483, 0x0418, 0x03a6, /* -8, .. -15 dB */
    0x032d, 0x02b2, 0x0234, 0x01b8, 0x0142, 0x00d8, 0x007e, 0x003a, /* -16, .. -23 dB */    
    0x000f, 0x0000                                                  /* -24, -25 dB */
};



/* Loudness as a function of Volume (in dB) */
/* this is for Treble Boost Curve */
static const uint16_t table_Loudness_TrebleB_curve[26] =
{
    0x0784, 0x076a, 0x0750, 0x072c, 0x0703, 0x06d6, 0x06a5, 0x066c, /* 0, .. -7 dB */
    0x062d, 0x05e7, 0x0599, 0x0544, 0x04e7, 0x0483, 0x0418, 0x03a6, /* -8, .. -15 dB */
    0x032d, 0x02b2, 0x0234, 0x01b8, 0x0142, 0x00d8, 0x007e, 0x003a, /* -16, .. -23 dB */
    0x000f, 0x0000                                                  /* -24, -25 dB */
};
/*
*********************6638 control api****************************
*/
int audio_calc_x ( double val );

short int audio_calc_y ( double val );

int tef6638_recv ( int fd,	uint8_t* data, int data_num, uint8_t*  buf, int size, uint8_t slave_addr);

int tef6638_send(int fd,  uint8_t* data, int data_num, uint8_t slave_addr);
int  tef6638_write_x_reg(int fd, const int addr,const int *data,int data_num,uint8_t slave_addr);
int tef6638_read_x_reg ( int fd,const int addr, int *data, int data_num ,uint8_t slave_addr);

int tef6638_read_y_reg (int fd, const int addr, short int *data, int data_num ,uint8_t slave_addr );

int tef6638_write ( int fd , const char addr, const char *data, const int data_num, uint8_t slave_addr);

int tef6638_write_y_reg ( int fd, const int addr, short int *data, int data_num , uint8_t slave_addr);

int tef6638_write_y_reg_scratch ( int fd, const int addr, short int *data, int data_num , uint8_t slave_addr);
/*
*************************filter coeaffients calculate************************************
*/
void filter_calculate(filter_param_t* param, filter_coeffients_t* coefficents);
/*
*********************************filter coeaffients calculate end*************************

*/










#endif
