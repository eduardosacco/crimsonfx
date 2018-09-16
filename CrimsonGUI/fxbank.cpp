#include "fxbank.h"

//const

FxBank::FxBank()
{
    //Inicializo todas las variables
    
    //Bank preset
    preset = NONINIT;
    presetAddr ="preset";

    //Compressor ++++++++++++++++++++++++++++++++++++++++++++++++++
    fx[fxCompressor].name = "Compressor";
    fx[fxCompressor].state = OFF;
    fx[fxCompressor].nParam = 5;
    fx[fxCompressor].stateAddr = "comp/state";

//    //No hace falta que el usuario pueda elegir entre RMS y Peak
//    fx[fxCompressor].param[pCompRMSPeak].name = "RMS/Peak";
//    fx[fxCompressor].param[pCompRMSPeak].value = 0;
//    fx[fxCompressor].param[pCompRMSPeak].defValue = 0;
//    fx[fxCompressor].param[pCompRMSPeak].addr = "comp/rp";

    fx[fxCompressor].param[pCompThreshold].name = "Threshold";
    fx[fxCompressor].param[pCompThreshold].value = 0;
    fx[fxCompressor].param[pCompThreshold].defValue = DEFAULTPVALUE;
    fx[fxCompressor].param[pCompThreshold].addr = "comp/t";

    fx[fxCompressor].param[pCompRatio].name = "Ratio";
    fx[fxCompressor].param[pCompRatio].value = 0;
    fx[fxCompressor].param[pCompRatio].defValue = DEFAULTPVALUE;
    fx[fxCompressor].param[pCompRatio].addr = "comp/r";

    fx[fxCompressor].param[pCompLookAhead].name = "Lookahead";
    fx[fxCompressor].param[pCompLookAhead].value = 0;
    fx[fxCompressor].param[pCompLookAhead].defValue = DEFAULTPVALUE;
    fx[fxCompressor].param[pCompLookAhead].addr = "comp/l";

    fx[fxCompressor].param[pCompResp].name = "Response";
    fx[fxCompressor].param[pCompResp].value = 0;
    fx[fxCompressor].param[pCompResp].defValue = DEFAULTPVALUE;
    fx[fxCompressor].param[pCompResp].addr = "comp/re";

    fx[fxCompressor].param[pCompGain].name = "Gain";
    fx[fxCompressor].param[pCompGain].value = 0;
    fx[fxCompressor].param[pCompGain].defValue = DEFAULTPVALUE;
    fx[fxCompressor].param[pCompGain].addr = "comp/g";

    //Overdrive ++++++++++++++++++++++++++++++++++++++++++++++++++
    fx[fxOverdrive].name = "Overdrive";
    fx[fxOverdrive].state = OFF;
    fx[fxOverdrive].nParam = 3;
    fx[fxOverdrive].stateAddr = "over/state";

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

    //Distortion ++++++++++++++++++++++++++++++++++++++++++++++++++
    fx[fxDistortion].name = "Distortion";
    fx[fxDistortion].state = OFF;
    fx[fxDistortion].nParam = 3;
    fx[fxDistortion].stateAddr = "dist/state";

    fx[fxDistortion].param[pDistoGain].name = "Gain";
    fx[fxDistortion].param[pDistoGain].value = 0;
    fx[fxDistortion].param[pDistoGain].defValue = DEFAULTOVERDRIVE1G;
    fx[fxDistortion].param[pDistoGain].addr = "dist/g";

    fx[fxDistortion].param[pDistoDepth].name = "Depth";
    fx[fxDistortion].param[pDistoDepth].value = 0;
    fx[fxDistortion].param[pDistoDepth].defValue = DEFAULTOVERDRIVE1D;
    fx[fxDistortion].param[pDistoDepth].addr = "dist/d";

    fx[fxDistortion].param[pDistoCutoff].name = "Cuttoff";
    fx[fxDistortion].param[pDistoCutoff].value = 0;
    fx[fxDistortion].param[pDistoCutoff].defValue = DEFAULTOVERDRIVE1C;
    fx[fxDistortion].param[pDistoCutoff].addr = "dist/c";

    //Equalizer ++++++++++++++++++++++++++++++++++++++++++++++++++
    fx[fxEqualizer].name = "Equalizer";
    fx[fxEqualizer].state = OFF;
    fx[fxEqualizer].nParam = 6;
    fx[fxEqualizer].stateAddr = "equ/state";

    fx[fxEqualizer].param[pEquPreamp].name = "Preamp";
    fx[fxEqualizer].param[pEquPreamp].value = 0;
    fx[fxEqualizer].param[pEquPreamp].defValue = DEFAULTPVALUE;
    fx[fxEqualizer].param[pEquPreamp].addr = "equ/p";

    fx[fxEqualizer].param[pEquBand1].name = "Band 1";
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

    fx[fxEqualizer].param[pEquBand5].name = "Band 5";
    fx[fxEqualizer].param[pEquBand5].value = 0;
    fx[fxEqualizer].param[pEquBand5].defValue = DEFAULTPVALUE;
    fx[fxEqualizer].param[pEquBand5].addr = "equ/b5";

    //Chorus ++++++++++++++++++++++++++++++++++++++++++++++++++
    fx[fxChorus].name = "Chorus";
    fx[fxChorus].state = OFF;
    fx[fxChorus].nParam = 4;
    fx[fxChorus].stateAddr = "cho/state"; //state quizas pasa a x

    fx[fxChorus].param[pChorusFF].name = "Feedforward";
    fx[fxChorus].param[pChorusFF].value = 0;
    fx[fxChorus].param[pChorusFF].defValue = DEFAULTREVERB1DW;
    fx[fxChorus].param[pChorusFF].addr = "cho/ff";

    fx[fxChorus].param[pChorusDelay].name = "Delay";
    fx[fxChorus].param[pChorusDelay].value = 0;
    fx[fxChorus].param[pChorusDelay].defValue = DEFAULTREVERB1RS;
    fx[fxChorus].param[pChorusDelay].addr = "cho/d";

    fx[fxChorus].param[pChorusFB].name = "Feedback";
    fx[fxChorus].param[pChorusFB].value = 0;
    fx[fxChorus].param[pChorusFB].defValue = DEFAULTREVERB1D;
    fx[fxChorus].param[pChorusFB].addr = "cho/fb";

    fx[fxChorus].param[pChorusBlend].name = "Blend";
    fx[fxChorus].param[pChorusBlend].value = 0;
    fx[fxChorus].param[pChorusBlend].defValue = DEFAULTREVERB1D;
    fx[fxChorus].param[pChorusBlend].addr = "cho/b";

    //Flanger ++++++++++++++++++++++++++++++++++++++++++++++++++
    fx[fxFlanger].name = "Flanger";
    fx[fxFlanger].state = OFF;
    fx[fxFlanger].nParam = 4;
    fx[fxFlanger].stateAddr = "fla/state";

    fx[fxFlanger].param[pFlangerFF].name = "Feedforward";
    fx[fxFlanger].param[pFlangerFF].value = 0;
    fx[fxFlanger].param[pFlangerFF].defValue = DEFAULTREVERB1DW;
    fx[fxFlanger].param[pFlangerFF].addr = "fla/ff";

    fx[fxFlanger].param[pFlangerDelay].name = "Delay";
    fx[fxFlanger].param[pFlangerDelay].value = 0;
    fx[fxFlanger].param[pFlangerDelay].defValue = DEFAULTREVERB1RS;
    fx[fxFlanger].param[pFlangerDelay].addr = "fla/d";

    fx[fxFlanger].param[pFlangerFB].name = "Feedback";
    fx[fxFlanger].param[pFlangerFB].value = 0;
    fx[fxFlanger].param[pFlangerFB].defValue = DEFAULTREVERB1D;
    fx[fxFlanger].param[pFlangerFB].addr = "fla/fb";

    fx[fxFlanger].param[pFlangerBlend].name = "Blend";
    fx[fxFlanger].param[pFlangerBlend].value = 0;
    fx[fxFlanger].param[pFlangerBlend].defValue = DEFAULTREVERB1D;
    fx[fxFlanger].param[pFlangerBlend].addr = "fla/b";

    //Reverb ++++++++++++++++++++++++++++++++++++++++++++++++++
    fx[fxReverb].name = "Reverb";
    fx[fxReverb].state = OFF;
    fx[fxReverb].nParam = 3;
    fx[fxReverb].stateAddr = "rev/state"; //state quizas pasa a x

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

    //Delay ++++++++++++++++++++++++++++++++++++++++++++++++++
    fx[fxDelay].name = "Delay";
    fx[fxDelay].state = OFF;
    fx[fxDelay].nParam = 3;
    fx[fxDelay].stateAddr = "del/state"; //state quizas pasa a x

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
