namespace AcdbData
{
    public enum AcdbDevices : int
    {
        SND_DEVICE_NONE = 0,
        SND_DEVICE_OUT_HANDSET = 1,
        SND_DEVICE_OUT_SPEAKER = 2,
        SND_DEVICE_OUT_SPEAKER_EXTERNAL_1 = 3,
        SND_DEVICE_OUT_SPEAKER_EXTERNAL_2 = 4,
        SND_DEVICE_OUT_SPEAKER_REVERSE = 5,
        SND_DEVICE_OUT_SPEAKER_VBAT = 6,
        SND_DEVICE_OUT_LINE = 7,
        SND_DEVICE_OUT_HEADPHONES = 8,
        SND_DEVICE_OUT_HEADPHONES_DSD = 9,
        SND_DEVICE_OUT_HEADPHONES_44_1 = 10,
        SND_DEVICE_OUT_SPEAKER_AND_HEADPHONES = 11,
        SND_DEVICE_OUT_SPEAKER_AND_LINE = 12,
        SND_DEVICE_OUT_SPEAKER_AND_HEADPHONES_EXTERNAL_1 = 13,
        SND_DEVICE_OUT_SPEAKER_AND_HEADPHONES_EXTERNAL_2 = 14,
        SND_DEVICE_OUT_VOICE_HANDSET = 15,
        SND_DEVICE_OUT_VOICE_SPEAKER = 16,
        SND_DEVICE_OUT_VOICE_SPEAKER_VBAT = 18,
        SND_DEVICE_OUT_VOICE_SPEAKER_2 = 19,
        SND_DEVICE_OUT_VOICE_SPEAKER_2_VBAT = 20,
        SND_DEVICE_OUT_VOICE_HEADPHONES = 21,
        SND_DEVICE_OUT_VOICE_LINE = 22,
        SND_DEVICE_OUT_HDMI = 23,
        SND_DEVICE_OUT_SPEAKER_AND_HDMI = 24,
        SND_DEVICE_OUT_DISPLAY_PORT = 25,
        SND_DEVICE_OUT_SPEAKER_AND_DISPLAY_PORT = 26,
        SND_DEVICE_OUT_BT_SCO = 27,
        SND_DEVICE_OUT_BT_SCO_WB = 28,
        SND_DEVICE_OUT_BT_A2DP = 29,
        SND_DEVICE_OUT_SPEAKER_AND_BT_A2DP = 30,
        SND_DEVICE_OUT_SPEAKER_AND_BT_SCO = 31,
        SND_DEVICE_OUT_SPEAKER_AND_BT_SCO_WB = 32,
        SND_DEVICE_OUT_VOICE_TTY_FULL_HEADPHONES = 33,
        SND_DEVICE_OUT_VOICE_TTY_VCO_HEADPHONES = 34,
        SND_DEVICE_OUT_VOICE_TTY_HCO_HANDSET = 35,
        SND_DEVICE_OUT_VOICE_TTY_FULL_USB = 36,
        SND_DEVICE_OUT_VOICE_TTY_VCO_USB = 37,
        SND_DEVICE_OUT_VOICE_TX = 38,
        SND_DEVICE_OUT_AFE_PROXY = 39,
        SND_DEVICE_OUT_USB_HEADSET = 40,
        SND_DEVICE_OUT_USB_HEADPHONES = 41,
        SND_DEVICE_OUT_SPEAKER_AND_USB_HEADSET = 42,
        SND_DEVICE_OUT_VOICE_USB_HEADPHONES = 43,
        SND_DEVICE_OUT_VOICE_USB_HEADSET = 44,
        SND_DEVICE_OUT_TRANSMISSION_FM = 45,
        SND_DEVICE_OUT_ANC_HEADSET = 46,
        SND_DEVICE_OUT_ANC_FB_HEADSET = 47,
        SND_DEVICE_OUT_VOICE_ANC_HEADSET = 48,
        SND_DEVICE_OUT_VOICE_ANC_FB_HEADSET = 49,
        SND_DEVICE_OUT_SPEAKER_AND_ANC_HEADSET = 50,
        SND_DEVICE_OUT_SPEAKER_AND_ANC_FB_HEADSET = 51,
        SND_DEVICE_OUT_ANC_HANDSET = 52,
        SND_DEVICE_OUT_SPEAKER_PROTECTED = 53,
        SND_DEVICE_OUT_VOICE_SPEAKER_PROTECTED = 54,
        SND_DEVICE_OUT_VOICE_SPEAKER_2_PROTECTED = 55,
        SND_DEVICE_OUT_VOICE_SPEAKER_STEREO_PROTECTED = 56,
        SND_DEVICE_OUT_SPEAKER_PROTECTED_VBAT = 57,
        SND_DEVICE_OUT_VOICE_SPEAKER_PROTECTED_VBAT = 58,
        SND_DEVICE_OUT_VOICE_SPEAKER_2_PROTECTED_VBAT = 59,
        SND_DEVICE_OUT_SPEAKER_PROTECTED_RAS = 63,
        SND_DEVICE_OUT_SPEAKER_PROTECTED_VBAT_RAS = 64,
        SND_DEVICE_OUT_HEADPHONES_VOIP = 71,
        SND_DEVICE_OUT_HI_HEADPHONES_VOIP = 72,
        SND_DEVICE_OUT_HI_HEADPHONES = 73,
        SND_DEVICE_OUT_HI_HEADPHONES_44_1 = 74,
        SND_DEVICE_OUT_SPEAKER_AND_HI_HEADPHONES = 75,
        SND_DEVICE_OUT_RINGTONE_SPEAKER = 76,
        SND_DEVICE_OUT_RINGTONE_SPEAKER_AND_HEADPHONES = 77,
        SND_DEVICE_OUT_RINGTONE_SPEAKER_AND_USB_HEADSET = 78,
        SND_DEVICE_OUT_RINGTONE_SPEAKER_AND_HI_HEADPHONES = 79,
        SND_DEVICE_OUT_FQC_VOICE_HANDSET = 80,
        SND_DEVICE_OUT_HAC_VOICE_HANDSET = 81,
        SND_DEVICE_OUT_VOICE_TTY_HCO_USB_HEADSET = 82,
        SND_DEVICE_OUT_VOICE_TTY_VCO_USB_HEADPHONES = 83,
        SND_DEVICE_OUT_VOICE_TTY_FULL_USB_HEADSET = 84,
        SND_DEVICE_OUT_VOIP_SPEAKER = 85,
        SND_DEVICE_IN_HANDSET_MIC = 86,
        SND_DEVICE_IN_HANDSET_MIC_EXTERNAL = 87,
        SND_DEVICE_IN_HANDSET_MIC_AEC = 88,
        SND_DEVICE_IN_HANDSET_MIC_NS = 89,
        SND_DEVICE_IN_HANDSET_MIC_AEC_NS = 90,
        SND_DEVICE_IN_HANDSET_DMIC = 91,
        SND_DEVICE_IN_HANDSET_DMIC_AEC = 92,
        SND_DEVICE_IN_HANDSET_DMIC_NS = 93,
        SND_DEVICE_IN_HANDSET_DMIC_AEC_NS = 94,
        SND_DEVICE_IN_SPEAKER_MIC = 95,
        SND_DEVICE_IN_SPEAKER_MIC_AEC = 96,
        SND_DEVICE_IN_SPEAKER_MIC_NS = 97,
        SND_DEVICE_IN_SPEAKER_MIC_AEC_NS = 98,
        SND_DEVICE_IN_SPEAKER_DMIC = 99,
        SND_DEVICE_IN_SPEAKER_DMIC_AEC = 100,
        SND_DEVICE_IN_SPEAKER_DMIC_NS = 101,
        SND_DEVICE_IN_SPEAKER_DMIC_AEC_NS = 102,
        SND_DEVICE_IN_HEADSET_MIC = 103,
        SND_DEVICE_IN_HEADSET_MIC_FLUENCE = 104,
        SND_DEVICE_IN_VOICE_SPEAKER_MIC = 105,
        SND_DEVICE_IN_VOICE_HEADSET_MIC = 106,
        SND_DEVICE_IN_HDMI_MIC = 107,
        SND_DEVICE_IN_BT_SCO_MIC = 108,
        SND_DEVICE_IN_BT_SCO_MIC_NREC = 109,
        SND_DEVICE_IN_BT_SCO_MIC_WB = 110,
        SND_DEVICE_IN_BT_SCO_MIC_WB_NREC = 111,
        SND_DEVICE_IN_CAMCORDER_MIC = 112,
        SND_DEVICE_IN_VOICE_DMIC = 113,
        SND_DEVICE_IN_VOICE_SPEAKER_DMIC = 114,
        SND_DEVICE_IN_VOICE_SPEAKER_TMIC = 115,
        SND_DEVICE_IN_VOICE_SPEAKER_QMIC = 116,
        SND_DEVICE_IN_VOICE_TTY_FULL_HEADSET_MIC = 117,
        SND_DEVICE_IN_VOICE_TTY_VCO_HANDSET_MIC = 118,
        SND_DEVICE_IN_VOICE_TTY_HCO_HEADSET_MIC = 119,
        SND_DEVICE_IN_VOICE_TTY_FULL_USB_MIC = 120,
        SND_DEVICE_IN_VOICE_TTY_HCO_USB_MIC = 121,
        SND_DEVICE_IN_VOICE_REC_MIC = 122,
        SND_DEVICE_IN_VOICE_REC_MIC_NS = 123,
        SND_DEVICE_IN_VOICE_REC_DMIC_STEREO = 124,
        SND_DEVICE_IN_VOICE_REC_DMIC_FLUENCE = 125,
        SND_DEVICE_IN_VOICE_RX = 126,
        SND_DEVICE_IN_USB_HEADSET_MIC = 127,
        SND_DEVICE_IN_USB_HEADSET_MIC_AEC = 128,
        SND_DEVICE_IN_VOICE_USB_HEADSET_MIC = 129,
        SND_DEVICE_IN_UNPROCESSED_USB_HEADSET_MIC = 130,
        SND_DEVICE_IN_VOICE_RECOG_USB_HEADSET_MIC = 131,
        SND_DEVICE_IN_USB_HEADSET_MULTI_CHANNEL_MIC = 132,
        SND_DEVICE_IN_USB_HEADSET_MULTI_CHANNEL_MIC_AEC = 133,
        SND_DEVICE_IN_UNPROCESSED_USB_HEADSET_MULTI_CHANNEL_MIC = 134,
        SND_DEVICE_IN_VOICE_RECOG_USB_HEADSET_MULTI_CHANNEL_MIC = 135,
        SND_DEVICE_IN_CAPTURE_FM = 136,
        SND_DEVICE_IN_AANC_HANDSET_MIC = 137,
        SND_DEVICE_IN_QUAD_MIC = 138,
        SND_DEVICE_IN_HANDSET_STEREO_DMIC = 139,
        SND_DEVICE_IN_SPEAKER_STEREO_DMIC = 140,
        SND_DEVICE_IN_CAPTURE_VI_FEEDBACK = 141,
        SND_DEVICE_IN_CAPTURE_VI_FEEDBACK_MONO_1 = 142,
        SND_DEVICE_IN_CAPTURE_VI_FEEDBACK_MONO_2 = 143,
        SND_DEVICE_IN_VOICE_SPEAKER_DMIC_BROADSIDE = 144,
        SND_DEVICE_IN_SPEAKER_DMIC_BROADSIDE = 145,
        SND_DEVICE_IN_SPEAKER_DMIC_AEC_BROADSIDE = 146,
        SND_DEVICE_IN_SPEAKER_DMIC_NS_BROADSIDE = 147,
        SND_DEVICE_IN_SPEAKER_DMIC_AEC_NS_BROADSIDE = 148,
        SND_DEVICE_IN_VOICE_FLUENCE_DMIC_AANC = 149,
        SND_DEVICE_IN_HANDSET_QMIC = 150,
        SND_DEVICE_IN_SPEAKER_QMIC_AEC = 151,
        SND_DEVICE_IN_SPEAKER_QMIC_NS = 152,
        SND_DEVICE_IN_SPEAKER_QMIC_AEC_NS = 153,
        SND_DEVICE_IN_VOICE_REC_QMIC_FLUENCE = 154,
        SND_DEVICE_IN_THREE_MIC = 155,
        SND_DEVICE_IN_HANDSET_TMIC_FLUENCE_PRO = 156,
        SND_DEVICE_IN_HANDSET_TMIC = 157,
        SND_DEVICE_IN_HANDSET_TMIC_AEC = 158,
        SND_DEVICE_IN_HANDSET_TMIC_NS = 159,
        SND_DEVICE_IN_HANDSET_TMIC_AEC_NS = 160,
        SND_DEVICE_IN_SPEAKER_TMIC_AEC = 161,
        SND_DEVICE_IN_SPEAKER_TMIC_NS = 162,
        SND_DEVICE_IN_SPEAKER_TMIC_AEC_NS = 163,
        SND_DEVICE_IN_VOICE_REC_TMIC = 164,
        SND_DEVICE_IN_UNPROCESSED_MIC = 165,
        SND_DEVICE_IN_UNPROCESSED_STEREO_MIC = 166,
        SND_DEVICE_IN_UNPROCESSED_THREE_MIC = 167,
        SND_DEVICE_IN_UNPROCESSED_QUAD_MIC = 168,
        SND_DEVICE_IN_UNPROCESSED_HEADSET_MIC = 169,
        SND_DEVICE_IN_HANDSET_GENERIC_QMIC = 174,
        SND_DEVICE_IN_HANDSET_VOIP_DMIC = 175,
        SND_DEVICE_IN_HEADSET_VOIP_MIC = 176,
        SND_DEVICE_IN_SPEAKER_VOIP_MIC = 177,
        SND_DEVICE_IN_VOICE_HEADSET_DMIC = 178,
        SND_DEVICE_IN_VOICE_HANDSET_MIC_REC = 179,
        SND_DEVICE_MAX,
    };
}
