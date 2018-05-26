#ifndef FXBANK_H
#define FXBANK_H

#define PRESET1 1
#define PRESET2 2
#define PRESET3 3

#define PARAM0 0
#define PARAM1 1
#define PARAM2 2
#define PARAM3 3
#define PARAM4 4
#define PARAM5 5

#define MAXEFFECTS 8
#define MAXPARAM 6

//Valores por defecto de carga de settings
#define DEFAULTPRESET 1
#define DEFAULTSTATE 0

#define DEFAULTOVERDRIVE1G 20
#define DEFAULTOVERDRIVE1D 50
#define DEFAULTOVERDRIVE1C 80

#define DEFAULTREVERB1DW 50
#define DEFAULTREVERB1RS 50
#define DEFAULTREVERB1D 20

#define DEFAULTDELAY1L 60
#define DEFAULTDELAY1D 20
#define DEFAULTDELAY1F 15

//Default param value para los que todavia no estan definidos
#define DEFAULTPVALUE 50

#define NONINIT -1
#define OFF 0
#define ON 1

#include <QString>

//NEWTYPES Y ENUMS
typedef struct
{
    const char * name;
    int value;
    int defValue;
    const char *addr;

}Parameter;

typedef struct
{
    const char *name;
    //Estado del efecto On o OFF
    bool state;
    //Numero de parametros del efecto
    int nParam;
    //Para acceder a crimsonSettings se usa concatenando el numero del banco N
    //Refiere al estado del efecto guardado en el banco N
    const char *stateAddr;
    //Refiere al preset del efecto guardado en el banco N
    const char *presetAddr;
    //Parametros de cada efecto
    Parameter param[MAXPARAM];

}Effect;

//++++++++++ Enumerations ++++++++++
//All effects
enum {fxCompressor,fxDistortion,fxOverdrive,fxEqualizer,fxChorus,fxFlanger,fxReverb,fxDelay};

//Parameters for each effect
enum {pCompRMSPeak,pCompThreshold,pCompRatio,pCompLookAhead,pCompResp,pCompGain};
enum {pDistoGain,pDistoDepth,pDistoCutoff};
enum {pOverGain,pOverDepth,pOverCutoff};
enum {pEquPreamp,pEquBand1,pEquBand2,pEquBand3,pEquBand4,pEquBand5};
enum {pChorusFF,pChorusDelay,pChorusFB,pChorusBlend};
enum {pFlangerFF,pFlangerDelay,pFlangerFB,pFlangerBlend};
enum {pDelLevel,pDelDelay,pDelFeedback};
enum {pRevDryWet,pRevDamping,pRevRoomSize};



//*****************************************************************
//                  FX CLASS
//*****************************************************************

class FxBank
{
public:
    FxBank();

    int preset;
    const char *presetAddr;
    Effect fx[MAXEFFECTS];

};

#endif // FXBANK_H
