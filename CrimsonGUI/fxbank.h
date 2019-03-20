//--------------------------------------------------------------------------------------------------
//              FXBANK.H
//--------------------------------------------------------------------------------------------------

#ifndef FXBANK_H
#define FXBANK_H

//*****************************************************************
//                  DEFINES
//*****************************************************************
#define PARAM0 0
#define PARAM1 1
#define PARAM2 2
#define PARAM3 3
#define PARAM4 4
#define PARAM5 5

#define MAXEFFECTS 8
#define MAXPARAM 6

// Valores por defecto de carga de settings
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

#define DEFAULTPVALUE 50

#define NONINIT -1
#define OFF 0
#define ON 1

#include <QString>

//*****************************************************************
//                  TYPEDEF PARAMETRO
//*****************************************************************
typedef struct
{
    const char * name;  // Nombre
    int value;          // Valor actual
    int defValue;       // Valor por defecto
    const char *addr;   // Direccion de valor del parametro en crimsonSettings

}Parameter;

//*****************************************************************
//                  TYPEDEF EFECTO
//*****************************************************************
typedef struct
{
    bool state;
    const char *name;           // Estado del efecto On o OFF
    int nParam;                 // Numero de parametros del efecto
    const char *stateAddr;      // Direccion de estado del efecto en crimsonSettings
    Parameter param[MAXPARAM];  // Parametros de cada efecto

}Effect;

//*****************************************************************
//                  ENUMS
//*****************************************************************

// Presets
enum {bPreset1, bPreset2, bPreset3, bPreset4, bPreset5, bPreset6};

// Efectos
enum {fxCompressor,fxDistortion,fxOverdrive,fxEqualizer,fxChorus,fxFlanger,fxReverb,fxDelay}; //8 Fx

// Parametros de cada efecto
enum {pCompThreshold,pCompRatio,pCompLookAhead,pCompResp,pCompGain};                //6
enum {pDistoGain,pDistoDepth,pDistoCutoff};                                         //3
enum {pOverGain,pOverDepth,pOverCutoff};                                            //3
enum {pEquPreamp,pEquBand1,pEquBand2,pEquBand3,pEquBand4,pEquBand5};                //6
enum {pChorusFF,pChorusDelay,pChorusFB,pChorusBlend};                               //4
enum {pFlangerFF,pFlangerDelay,pFlangerFB,pFlangerBlend};                           //4
enum {pDelLevel,pDelDelay,pDelFeedback};                                            //3
enum {pRevDryWet,pRevRoomSize,pRevDamping};                                         //3

//*****************************************************************
//                  FXBANK CLASS
//*****************************************************************
class FxBank
{
public:
    FxBank();

    int preset;                 // Preset actual
    const char *presetAddr;     // Direccion de preset actual en crimsonSettings
    Effect fx[MAXEFFECTS];      // Banco de efectos
};

#endif // FXBANK_H
