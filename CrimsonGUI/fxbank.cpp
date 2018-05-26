#include "fxbank.h"

//const

FxBank::FxBank()
{
    //Inicializo todas las variables
    
    //Bank preset
    preset = NONINIT;
    presetAddr ="preset";

    //Compressor
    fx[fxCompressor].name = "Compressor";
    fx[fxCompressor].state = OFF;
    fx[fxCompressor].preset = NONINIT;
    fx[fxCompressor].nParam = 3;
    fx[fxCompressor].stateAddr = "comp/state";
    fx[fxCompressor].presetAddr = "comp/preset";

    fx[fxCompressor].param[pCompThreshold].name = "Threshold";
    fx[fxCompressor].param[pCompThreshold].value = 0;
    fx[fxCompressor].param[pCompThreshold].defValue = DEFAULTPVALUE;
    fx[fxCompressor].param[pCompThreshold].addr = "comp/t";

    fx[fxCompressor].param[pCompGain].name = "Gain";
    fx[fxCompressor].param[pCompGain].value = 0;
    fx[fxCompressor].param[pCompGain].defValue = DEFAULTPVALUE;
    fx[fxCompressor].param[pCompGain].addr = "comp/g";

    fx[fxCompressor].param[pCompRatio].name = "Ratio";
    fx[fxCompressor].param[pCompRatio].value = 0;
    fx[fxCompressor].param[pCompRatio].defValue = DEFAULTPVALUE;
    fx[fxCompressor].param[pCompRatio].addr = "comp/r";

    //Overdrive
    fx[fxOverdrive].name = "Overdrive";
    fx[fxOverdrive].state = OFF;
    fx[fxOverdrive].preset = NONINIT;
    fx[fxOverdrive].nParam = 3;
    fx[fxOverdrive].stateAddr = "over/state";
    fx[fxOverdrive].presetAddr = "over/preset";

    fx[fxOverdrive].param[pOverGain].name = "Gain";
    fx[fxOverdrive].param[pOverGain].value = 0;
    fx[fxOverdrive].param[pOverGain].defValue = DEFAULTOVERDRIVE1G;
    fx[fxOverdrive].param[pOverGain].addr = "over/g";

    fx[fxOverdrive].param[pOverDepth].name = "Depth";
    fx[fxOverdrive].param[pOverDepth].value = 0;
    fx[fxOverdrive].param[pOverDepth].defValue = DEFAULTOVERDRIVE1D;
    fx[fxOverdrive].param[pOverDepth].addr = "over/d";

    fx[fxOverdrive].param[pOverCutoff].name = "Cuttoff";
    fx[fxOverdrive].param[pOverCutoff].value = 0;
    fx[fxOverdrive].param[pOverCutoff].defValue = DEFAULTOVERDRIVE1C;
    fx[fxOverdrive].param[pOverCutoff].addr = "over/c";

    //Equalizer

    fx[fxEqualizer].state = OFF;
    fx[fxEqualizer].preset = NONINIT;
    fx[fxEqualizer].nParam = 5;
    fx[fxEqualizer].stateAddr = "equ/state";
    fx[fxEqualizer].presetAddr = "equ/preset";

    fx[fxEqualizer].param[pEquPreamp].name = "Preamp";
    fx[fxEqualizer].param[pEquPreamp].value = 0;
    fx[fxEqualizer].param[pEquPreamp].defValue = DEFAULTPVALUE;
    fx[fxEqualizer].param[pEquPreamp].addr = "equ/p";

    fx[fxEqualizer].param[pEquBand1].value = 0;
    fx[fxEqualizer].param[pEquBand1].defValue = DEFAULTPVALUE;
    fx[fxEqualizer].param[pEquBand1].addr = "equ/b1";

    fx[fxEqualizer].param[pEquBand2].name = "Band 2";
    fx[fxEqualizer].param[pEquBand2].value = 0;
    fx[fxEqualizer].param[pEquBand2].defValue = DEFAULTPVALUE;
    fx[fxEqualizer].param[pEquBand2].addr = "equ/b2";

    fx[fxEqualizer].param[pEquBand3].name = "Band 3";
    fx[fxEqualizer].param[pEquBand3].value = 0;
    fx[fxEqualizer].param[pEquBand3].defValue = DEFAULTPVALUE;
    fx[fxEqualizer].param[pEquBand3].addr = "equ/b3";

    fx[fxEqualizer].param[pEquBand4].name = "Band 4";
    fx[fxEqualizer].param[pEquBand4].value = 0;
    fx[fxEqualizer].param[pEquBand4].defValue = DEFAULTPVALUE;
    fx[fxEqualizer].param[pEquBand4].addr = "equ/b4";

    //Reverb
    fx[fxReverb].name = "Reverb";
    fx[fxReverb].state = OFF;
    fx[fxReverb].preset = NONINIT;
    fx[fxReverb].nParam = 3;
    fx[fxReverb].stateAddr = "rev/state"; //state quizas pasa a x
    fx[fxReverb].presetAddr = "rev/preset";

    fx[fxReverb].param[pRevDryWet].name = "Dry/Wet";
    fx[fxReverb].param[pRevDryWet].value = 0;
    fx[fxReverb].param[pRevDryWet].defValue = DEFAULTREVERB1DW;
    fx[fxReverb].param[pRevDryWet].addr = "rev/dw";

    fx[fxReverb].param[pRevRoomSize].name = "Room Size";
    fx[fxReverb].param[pRevRoomSize].value = 0;
    fx[fxReverb].param[pRevRoomSize].defValue = DEFAULTREVERB1RS;
    fx[fxReverb].param[pRevRoomSize].addr = "rev/rs";

    fx[fxReverb].param[pRevDamping].name = "Damping";
    fx[fxReverb].param[pRevDamping].value = 0;
    fx[fxReverb].param[pRevDamping].defValue = DEFAULTREVERB1D;
    fx[fxReverb].param[pRevDamping].addr = "rev/d";

    //Delay
    fx[fxDelay].name = "Delay";
    fx[fxDelay].state = OFF;
    fx[fxDelay].preset = NONINIT;
    fx[fxDelay].nParam = 3;
    fx[fxDelay].stateAddr = "del/state"; //state quizas pasa a x
    fx[fxDelay].presetAddr = "del/preset";

    fx[fxDelay].param[pDelLevel].name = "Level";
    fx[fxDelay].param[pDelLevel].value = 0;
    fx[fxDelay].param[pDelLevel].defValue = DEFAULTDELAY1L;
    fx[fxDelay].param[pDelLevel].addr = "del/l";

    fx[fxDelay].param[pDelDelay].name = "Delay";
    fx[fxDelay].param[pDelDelay].value = 0;
    fx[fxDelay].param[pDelDelay].defValue = DEFAULTDELAY1D;
    fx[fxDelay].param[pDelDelay].addr = "del/d";

    fx[fxDelay].param[pDelFeedback].name = "Feedback";
    fx[fxDelay].param[pDelFeedback].value = 0;
    fx[fxDelay].param[pDelFeedback].defValue = DEFAULTDELAY1F;
    fx[fxDelay].param[pDelFeedback].addr = "del/f";
    
    
};
