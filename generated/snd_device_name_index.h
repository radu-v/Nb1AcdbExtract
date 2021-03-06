#include "snd_device_enum.h"

static struct name_to_index snd_device_name_index[SND_DEVICE_MAX] = {
	{TO_NAME_INDEX(SND_DEVICE_OUT_HANDSET)}, /* {"SND_DEVICE_OUT_HANDSET", 1} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER)}, /* {"SND_DEVICE_OUT_SPEAKER", 2} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_EXTERNAL_1)}, /* {"SND_DEVICE_OUT_SPEAKER_EXTERNAL_1", 3} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_EXTERNAL_2)}, /* {"SND_DEVICE_OUT_SPEAKER_EXTERNAL_2", 4} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_VBAT)}, /* {"SND_DEVICE_OUT_SPEAKER_VBAT", 6} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_REVERSE)}, /* {"SND_DEVICE_OUT_SPEAKER_REVERSE", 5} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_HEADPHONES)}, /* {"SND_DEVICE_OUT_HEADPHONES", 8} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_HEADPHONES_DSD)}, /* {"SND_DEVICE_OUT_HEADPHONES_DSD", 9} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_HEADPHONES_44_1)}, /* {"SND_DEVICE_OUT_HEADPHONES_44_1", 10} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_LINE)}, /* {"SND_DEVICE_OUT_LINE", 7} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_AND_HEADPHONES)}, /* {"SND_DEVICE_OUT_SPEAKER_AND_HEADPHONES", 11} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_AND_HI_HEADPHONES)}, /* {"SND_DEVICE_OUT_SPEAKER_AND_HI_HEADPHONES", 75} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_AND_LINE)}, /* {"SND_DEVICE_OUT_SPEAKER_AND_LINE", 12} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_AND_HEADPHONES_EXTERNAL_1)}, /* {"SND_DEVICE_OUT_SPEAKER_AND_HEADPHONES_EXTERNAL_1", 13} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_AND_HEADPHONES_EXTERNAL_2)}, /* {"SND_DEVICE_OUT_SPEAKER_AND_HEADPHONES_EXTERNAL_2", 14} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_HANDSET)}, /* {"SND_DEVICE_OUT_VOICE_HANDSET", 15} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_SPEAKER)}, /* {"SND_DEVICE_OUT_VOICE_SPEAKER", 16} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_SPEAKER_VBAT)}, /* {"SND_DEVICE_OUT_VOICE_SPEAKER_VBAT", 18} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_SPEAKER_2)}, /* {"SND_DEVICE_OUT_VOICE_SPEAKER_2", 19} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_SPEAKER_2_VBAT)}, /* {"SND_DEVICE_OUT_VOICE_SPEAKER_2_VBAT", 20} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_HEADPHONES)}, /* {"SND_DEVICE_OUT_VOICE_HEADPHONES", 21} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_LINE)}, /* {"SND_DEVICE_OUT_VOICE_LINE", 22} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_HDMI)}, /* {"SND_DEVICE_OUT_HDMI", 23} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_AND_HDMI)}, /* {"SND_DEVICE_OUT_SPEAKER_AND_HDMI", 24} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_DISPLAY_PORT)}, /* {"SND_DEVICE_OUT_DISPLAY_PORT", 25} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_AND_DISPLAY_PORT)}, /* {"SND_DEVICE_OUT_SPEAKER_AND_DISPLAY_PORT", 26} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_BT_SCO)}, /* {"SND_DEVICE_OUT_BT_SCO", 27} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_BT_SCO_WB)}, /* {"SND_DEVICE_OUT_BT_SCO_WB", 28} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_BT_A2DP)}, /* {"SND_DEVICE_OUT_BT_A2DP", 29} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_AND_BT_A2DP)}, /* {"SND_DEVICE_OUT_SPEAKER_AND_BT_A2DP", 30} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_TTY_FULL_HEADPHONES)}, /* {"SND_DEVICE_OUT_VOICE_TTY_FULL_HEADPHONES", 33} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_TTY_VCO_HEADPHONES)}, /* {"SND_DEVICE_OUT_VOICE_TTY_VCO_HEADPHONES", 34} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_TTY_HCO_HANDSET)}, /* {"SND_DEVICE_OUT_VOICE_TTY_HCO_HANDSET", 35} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_AND_BT_SCO)}, /* {"SND_DEVICE_OUT_SPEAKER_AND_BT_SCO", 31} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_AND_BT_SCO_WB)}, /* {"SND_DEVICE_OUT_SPEAKER_AND_BT_SCO_WB", 32} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_TTY_FULL_USB)}, /* {"SND_DEVICE_OUT_VOICE_TTY_FULL_USB", 36} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_TTY_VCO_USB)}, /* {"SND_DEVICE_OUT_VOICE_TTY_VCO_USB", 37} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_TX)}, /* {"SND_DEVICE_OUT_VOICE_TX", 38} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_AFE_PROXY)}, /* {"SND_DEVICE_OUT_AFE_PROXY", 39} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_USB_HEADSET)}, /* {"SND_DEVICE_OUT_USB_HEADSET", 40} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_USB_HEADSET)}, /* {"SND_DEVICE_OUT_VOICE_USB_HEADSET", 44} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_USB_HEADPHONES)}, /* {"SND_DEVICE_OUT_USB_HEADPHONES", 41} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_USB_HEADPHONES)}, /* {"SND_DEVICE_OUT_VOICE_USB_HEADPHONES", 43} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_AND_USB_HEADSET)}, /* {"SND_DEVICE_OUT_SPEAKER_AND_USB_HEADSET", 42} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_TRANSMISSION_FM)}, /* {"SND_DEVICE_OUT_TRANSMISSION_FM", 45} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_ANC_HEADSET)}, /* {"SND_DEVICE_OUT_ANC_HEADSET", 46} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_ANC_FB_HEADSET)}, /* {"SND_DEVICE_OUT_ANC_FB_HEADSET", 47} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_ANC_HEADSET)}, /* {"SND_DEVICE_OUT_VOICE_ANC_HEADSET", 48} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_ANC_FB_HEADSET)}, /* {"SND_DEVICE_OUT_VOICE_ANC_FB_HEADSET", 49} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_AND_ANC_HEADSET)}, /* {"SND_DEVICE_OUT_SPEAKER_AND_ANC_HEADSET", 50} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_AND_ANC_FB_HEADSET)}, /* {"SND_DEVICE_OUT_SPEAKER_AND_ANC_FB_HEADSET", 51} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_ANC_HANDSET)}, /* {"SND_DEVICE_OUT_ANC_HANDSET", 52} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_PROTECTED)}, /* {"SND_DEVICE_OUT_SPEAKER_PROTECTED", 53} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_SPEAKER_PROTECTED)}, /* {"SND_DEVICE_OUT_VOICE_SPEAKER_PROTECTED", 54} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_SPEAKER_2_PROTECTED)}, /* {"SND_DEVICE_OUT_VOICE_SPEAKER_2_PROTECTED", 55} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_SPEAKER_STEREO_PROTECTED)}, /* {"SND_DEVICE_OUT_VOICE_SPEAKER_STEREO_PROTECTED", 56} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_PROTECTED_VBAT)}, /* {"SND_DEVICE_OUT_SPEAKER_PROTECTED_VBAT", 57} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_SPEAKER_PROTECTED_VBAT)}, /* {"SND_DEVICE_OUT_VOICE_SPEAKER_PROTECTED_VBAT", 58} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_SPEAKER_2_PROTECTED_VBAT)}, /* {"SND_DEVICE_OUT_VOICE_SPEAKER_2_PROTECTED_VBAT", 59} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_PROTECTED_RAS)}, /* {"SND_DEVICE_OUT_SPEAKER_PROTECTED_RAS", 63} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_SPEAKER_PROTECTED_VBAT_RAS)}, /* {"SND_DEVICE_OUT_SPEAKER_PROTECTED_VBAT_RAS", 64} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_HEADPHONES_VOIP)}, /* {"SND_DEVICE_OUT_HEADPHONES_VOIP", 71} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_HI_HEADPHONES_VOIP)}, /* {"SND_DEVICE_OUT_HI_HEADPHONES_VOIP", 72} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_HI_HEADPHONES)}, /* {"SND_DEVICE_OUT_HI_HEADPHONES", 73} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_HI_HEADPHONES_44_1)}, /* {"SND_DEVICE_OUT_HI_HEADPHONES_44_1", 74} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_RINGTONE_SPEAKER)}, /* {"SND_DEVICE_OUT_RINGTONE_SPEAKER", 76} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_RINGTONE_SPEAKER_AND_HEADPHONES)}, /* {"SND_DEVICE_OUT_RINGTONE_SPEAKER_AND_HEADPHONES", 77} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_RINGTONE_SPEAKER_AND_USB_HEADSET)}, /* {"SND_DEVICE_OUT_RINGTONE_SPEAKER_AND_USB_HEADSET", 78} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_RINGTONE_SPEAKER_AND_HI_HEADPHONES)}, /* {"SND_DEVICE_OUT_RINGTONE_SPEAKER_AND_HI_HEADPHONES", 79} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_FQC_VOICE_HANDSET)}, /* {"SND_DEVICE_OUT_FQC_VOICE_HANDSET", 80} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_HAC_VOICE_HANDSET)}, /* {"SND_DEVICE_OUT_HAC_VOICE_HANDSET", 81} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_TTY_HCO_USB_HEADSET)}, /* {"SND_DEVICE_OUT_VOICE_TTY_HCO_USB_HEADSET", 82} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_TTY_VCO_USB_HEADPHONES)}, /* {"SND_DEVICE_OUT_VOICE_TTY_VCO_USB_HEADPHONES", 83} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOICE_TTY_FULL_USB_HEADSET)}, /* {"SND_DEVICE_OUT_VOICE_TTY_FULL_USB_HEADSET", 84} */
	{TO_NAME_INDEX(SND_DEVICE_OUT_VOIP_SPEAKER)}, /* {"SND_DEVICE_OUT_VOIP_SPEAKER", 85} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HANDSET_MIC)}, /* {"SND_DEVICE_IN_HANDSET_MIC", 86} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HANDSET_MIC_EXTERNAL)}, /* {"SND_DEVICE_IN_HANDSET_MIC_EXTERNAL", 87} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HANDSET_MIC_AEC)}, /* {"SND_DEVICE_IN_HANDSET_MIC_AEC", 88} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HANDSET_MIC_NS)}, /* {"SND_DEVICE_IN_HANDSET_MIC_NS", 89} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HANDSET_MIC_AEC_NS)}, /* {"SND_DEVICE_IN_HANDSET_MIC_AEC_NS", 90} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HANDSET_DMIC)}, /* {"SND_DEVICE_IN_HANDSET_DMIC", 91} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HANDSET_DMIC_AEC)}, /* {"SND_DEVICE_IN_HANDSET_DMIC_AEC", 92} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HANDSET_DMIC_NS)}, /* {"SND_DEVICE_IN_HANDSET_DMIC_NS", 93} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HANDSET_DMIC_AEC_NS)}, /* {"SND_DEVICE_IN_HANDSET_DMIC_AEC_NS", 94} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_MIC)}, /* {"SND_DEVICE_IN_SPEAKER_MIC", 95} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_MIC_AEC)}, /* {"SND_DEVICE_IN_SPEAKER_MIC_AEC", 96} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_MIC_NS)}, /* {"SND_DEVICE_IN_SPEAKER_MIC_NS", 97} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_MIC_AEC_NS)}, /* {"SND_DEVICE_IN_SPEAKER_MIC_AEC_NS", 98} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_DMIC)}, /* {"SND_DEVICE_IN_SPEAKER_DMIC", 99} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_DMIC_AEC)}, /* {"SND_DEVICE_IN_SPEAKER_DMIC_AEC", 100} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_DMIC_NS)}, /* {"SND_DEVICE_IN_SPEAKER_DMIC_NS", 101} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_DMIC_AEC_NS)}, /* {"SND_DEVICE_IN_SPEAKER_DMIC_AEC_NS", 102} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HEADSET_MIC)}, /* {"SND_DEVICE_IN_HEADSET_MIC", 103} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HEADSET_MIC_FLUENCE)}, /* {"SND_DEVICE_IN_HEADSET_MIC_FLUENCE", 104} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_SPEAKER_MIC)}, /* {"SND_DEVICE_IN_VOICE_SPEAKER_MIC", 105} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_HEADSET_MIC)}, /* {"SND_DEVICE_IN_VOICE_HEADSET_MIC", 106} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HDMI_MIC)}, /* {"SND_DEVICE_IN_HDMI_MIC", 107} */
	{TO_NAME_INDEX(SND_DEVICE_IN_BT_SCO_MIC)}, /* {"SND_DEVICE_IN_BT_SCO_MIC", 108} */
	{TO_NAME_INDEX(SND_DEVICE_IN_BT_SCO_MIC_NREC)}, /* {"SND_DEVICE_IN_BT_SCO_MIC_NREC", 109} */
	{TO_NAME_INDEX(SND_DEVICE_IN_BT_SCO_MIC_WB)}, /* {"SND_DEVICE_IN_BT_SCO_MIC_WB", 110} */
	{TO_NAME_INDEX(SND_DEVICE_IN_BT_SCO_MIC_WB_NREC)}, /* {"SND_DEVICE_IN_BT_SCO_MIC_WB_NREC", 111} */
	{TO_NAME_INDEX(SND_DEVICE_IN_CAMCORDER_MIC)}, /* {"SND_DEVICE_IN_CAMCORDER_MIC", 112} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_DMIC)}, /* {"SND_DEVICE_IN_VOICE_DMIC", 113} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_SPEAKER_DMIC)}, /* {"SND_DEVICE_IN_VOICE_SPEAKER_DMIC", 114} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_SPEAKER_TMIC)}, /* {"SND_DEVICE_IN_VOICE_SPEAKER_TMIC", 115} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_SPEAKER_QMIC)}, /* {"SND_DEVICE_IN_VOICE_SPEAKER_QMIC", 116} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_TTY_FULL_HEADSET_MIC)}, /* {"SND_DEVICE_IN_VOICE_TTY_FULL_HEADSET_MIC", 117} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_TTY_VCO_HANDSET_MIC)}, /* {"SND_DEVICE_IN_VOICE_TTY_VCO_HANDSET_MIC", 118} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_TTY_HCO_HEADSET_MIC)}, /* {"SND_DEVICE_IN_VOICE_TTY_HCO_HEADSET_MIC", 119} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_TTY_FULL_USB_MIC)}, /* {"SND_DEVICE_IN_VOICE_TTY_FULL_USB_MIC", 120} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_TTY_HCO_USB_MIC)}, /* {"SND_DEVICE_IN_VOICE_TTY_HCO_USB_MIC", 121} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_REC_MIC)}, /* {"SND_DEVICE_IN_VOICE_REC_MIC", 122} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_REC_MIC_NS)}, /* {"SND_DEVICE_IN_VOICE_REC_MIC_NS", 123} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_REC_DMIC_STEREO)}, /* {"SND_DEVICE_IN_VOICE_REC_DMIC_STEREO", 124} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_REC_DMIC_FLUENCE)}, /* {"SND_DEVICE_IN_VOICE_REC_DMIC_FLUENCE", 125} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_RX)}, /* {"SND_DEVICE_IN_VOICE_RX", 126} */
	{TO_NAME_INDEX(SND_DEVICE_IN_USB_HEADSET_MIC)}, /* {"SND_DEVICE_IN_USB_HEADSET_MIC", 127} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_USB_HEADSET_MIC)}, /* {"SND_DEVICE_IN_VOICE_USB_HEADSET_MIC", 129} */
	{TO_NAME_INDEX(SND_DEVICE_IN_UNPROCESSED_USB_HEADSET_MIC)}, /* {"SND_DEVICE_IN_UNPROCESSED_USB_HEADSET_MIC", 130} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_RECOG_USB_HEADSET_MIC)}, /* {"SND_DEVICE_IN_VOICE_RECOG_USB_HEADSET_MIC", 131} */
	{TO_NAME_INDEX(SND_DEVICE_IN_USB_HEADSET_MIC_AEC)}, /* {"SND_DEVICE_IN_USB_HEADSET_MIC_AEC", 128} */
	{TO_NAME_INDEX(SND_DEVICE_IN_USB_HEADSET_MULTI_CHANNEL_MIC)}, /* {"SND_DEVICE_IN_USB_HEADSET_MULTI_CHANNEL_MIC", 132} */
	{TO_NAME_INDEX(SND_DEVICE_IN_UNPROCESSED_USB_HEADSET_MULTI_CHANNEL_MIC)}, /* {"SND_DEVICE_IN_UNPROCESSED_USB_HEADSET_MULTI_CHANNEL_MIC", 134} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_RECOG_USB_HEADSET_MULTI_CHANNEL_MIC)}, /* {"SND_DEVICE_IN_VOICE_RECOG_USB_HEADSET_MULTI_CHANNEL_MIC", 135} */
	{TO_NAME_INDEX(SND_DEVICE_IN_USB_HEADSET_MULTI_CHANNEL_MIC_AEC)}, /* {"SND_DEVICE_IN_USB_HEADSET_MULTI_CHANNEL_MIC_AEC", 133} */
	{TO_NAME_INDEX(SND_DEVICE_IN_CAPTURE_FM)}, /* {"SND_DEVICE_IN_CAPTURE_FM", 136} */
	{TO_NAME_INDEX(SND_DEVICE_IN_AANC_HANDSET_MIC)}, /* {"SND_DEVICE_IN_AANC_HANDSET_MIC", 137} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_FLUENCE_DMIC_AANC)}, /* {"SND_DEVICE_IN_VOICE_FLUENCE_DMIC_AANC", 149} */
	{TO_NAME_INDEX(SND_DEVICE_IN_QUAD_MIC)}, /* {"SND_DEVICE_IN_QUAD_MIC", 138} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HANDSET_STEREO_DMIC)}, /* {"SND_DEVICE_IN_HANDSET_STEREO_DMIC", 139} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_STEREO_DMIC)}, /* {"SND_DEVICE_IN_SPEAKER_STEREO_DMIC", 140} */
	{TO_NAME_INDEX(SND_DEVICE_IN_CAPTURE_VI_FEEDBACK)}, /* {"SND_DEVICE_IN_CAPTURE_VI_FEEDBACK", 141} */
	{TO_NAME_INDEX(SND_DEVICE_IN_CAPTURE_VI_FEEDBACK_MONO_1)}, /* {"SND_DEVICE_IN_CAPTURE_VI_FEEDBACK_MONO_1", 142} */
	{TO_NAME_INDEX(SND_DEVICE_IN_CAPTURE_VI_FEEDBACK_MONO_2)}, /* {"SND_DEVICE_IN_CAPTURE_VI_FEEDBACK_MONO_2", 143} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_SPEAKER_DMIC_BROADSIDE)}, /* {"SND_DEVICE_IN_VOICE_SPEAKER_DMIC_BROADSIDE", 144} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_DMIC_BROADSIDE)}, /* {"SND_DEVICE_IN_SPEAKER_DMIC_BROADSIDE", 145} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_DMIC_AEC_BROADSIDE)}, /* {"SND_DEVICE_IN_SPEAKER_DMIC_AEC_BROADSIDE", 146} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_DMIC_NS_BROADSIDE)}, /* {"SND_DEVICE_IN_SPEAKER_DMIC_NS_BROADSIDE", 147} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_DMIC_AEC_NS_BROADSIDE)}, /* {"SND_DEVICE_IN_SPEAKER_DMIC_AEC_NS_BROADSIDE", 148} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HANDSET_QMIC)}, /* {"SND_DEVICE_IN_HANDSET_QMIC", 150} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_QMIC_AEC)}, /* {"SND_DEVICE_IN_SPEAKER_QMIC_AEC", 151} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_QMIC_NS)}, /* {"SND_DEVICE_IN_SPEAKER_QMIC_NS", 152} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_QMIC_AEC_NS)}, /* {"SND_DEVICE_IN_SPEAKER_QMIC_AEC_NS", 153} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_REC_QMIC_FLUENCE)}, /* {"SND_DEVICE_IN_VOICE_REC_QMIC_FLUENCE", 154} */
	{TO_NAME_INDEX(SND_DEVICE_IN_THREE_MIC)}, /* {"SND_DEVICE_IN_THREE_MIC", 155} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HANDSET_TMIC_FLUENCE_PRO)}, /* {"SND_DEVICE_IN_HANDSET_TMIC_FLUENCE_PRO", 156} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HANDSET_TMIC)}, /* {"SND_DEVICE_IN_HANDSET_TMIC", 157} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HANDSET_TMIC_AEC)}, /* {"SND_DEVICE_IN_HANDSET_TMIC_AEC", 158} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HANDSET_TMIC_NS)}, /* {"SND_DEVICE_IN_HANDSET_TMIC_NS", 159} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HANDSET_TMIC_AEC_NS)}, /* {"SND_DEVICE_IN_HANDSET_TMIC_AEC_NS", 160} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_TMIC_AEC)}, /* {"SND_DEVICE_IN_SPEAKER_TMIC_AEC", 161} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_TMIC_NS)}, /* {"SND_DEVICE_IN_SPEAKER_TMIC_NS", 162} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_TMIC_AEC_NS)}, /* {"SND_DEVICE_IN_SPEAKER_TMIC_AEC_NS", 163} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_REC_TMIC)}, /* {"SND_DEVICE_IN_VOICE_REC_TMIC", 164} */
	{TO_NAME_INDEX(SND_DEVICE_IN_UNPROCESSED_MIC)}, /* {"SND_DEVICE_IN_UNPROCESSED_MIC", 165} */
	{TO_NAME_INDEX(SND_DEVICE_IN_UNPROCESSED_STEREO_MIC)}, /* {"SND_DEVICE_IN_UNPROCESSED_STEREO_MIC", 166} */
	{TO_NAME_INDEX(SND_DEVICE_IN_UNPROCESSED_THREE_MIC)}, /* {"SND_DEVICE_IN_UNPROCESSED_THREE_MIC", 167} */
	{TO_NAME_INDEX(SND_DEVICE_IN_UNPROCESSED_QUAD_MIC)}, /* {"SND_DEVICE_IN_UNPROCESSED_QUAD_MIC", 168} */
	{TO_NAME_INDEX(SND_DEVICE_IN_UNPROCESSED_HEADSET_MIC)}, /* {"SND_DEVICE_IN_UNPROCESSED_HEADSET_MIC", 169} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HANDSET_GENERIC_QMIC)}, /* {"SND_DEVICE_IN_HANDSET_GENERIC_QMIC", 174} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HANDSET_VOIP_DMIC)}, /* {"SND_DEVICE_IN_HANDSET_VOIP_DMIC", 175} */
	{TO_NAME_INDEX(SND_DEVICE_IN_HEADSET_VOIP_MIC)}, /* {"SND_DEVICE_IN_HEADSET_VOIP_MIC", 176} */
	{TO_NAME_INDEX(SND_DEVICE_IN_SPEAKER_VOIP_MIC)}, /* {"SND_DEVICE_IN_SPEAKER_VOIP_MIC", 177} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_HEADSET_DMIC)}, /* {"SND_DEVICE_IN_VOICE_HEADSET_DMIC", 178} */
	{TO_NAME_INDEX(SND_DEVICE_IN_VOICE_HANDSET_MIC_REC)}, /* {"SND_DEVICE_IN_VOICE_HANDSET_MIC_REC", 179} */
};
