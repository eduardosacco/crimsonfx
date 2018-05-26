#ifndef FX_H
#define FX_H

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

#define NONINIT -1
#define OFF 0
#define ON 1

class Fx
{
public:
    Fx();

    struct Bank
    {
        int preset = NONINIT;

        bool overdrive1State = OFF;
        bool reverb1State = OFF;
        bool delay1State = OFF;

        //Direcciones para guardado en crimsonSettings
        //Ultimo bank preset utilizado
        const char *addrPreset = "bank/preset";

        const char *addrOverdrive1Preset = "bank/overPreset";
        const char *addrOverdrive1State = "bank/overState";
        const char *addrReverb1Preset = "bank/revPreset";
        const char *addrReverb1State = "bank/revState";
        const char *addrDelay1Preset = "bank/delPreset";
        const char *addrDelay1State = "bank/delState";

    }bank;

    struct Overdrive1
    {
        int gain=0;
        int depth=0;
        int cutoff=0;

        int preset=NONINIT;

        const char *addrGain = "over/g";
        const char *addrDepth = "over/d";
        const char *addrCuttof = "over/c";


    }overdrive1;

    struct Reverb1
    {
        int dryWet=0;
        int roomSize=0;
        int damping=0;

        int preset=NONINIT;

        const char *addrWet = "rev/dw";
        const char *addrDamping = "rev/d";
        const char *addrRoomSize = "rev/rs";

    }reverb1;

    struct Delay1
    {
        int level=0;
        int delay=0;
        int feedback=0;

        int preset=NONINIT;

        const char *addrLevel = "del/l";
        const char *addrDelay = "del/d";
        const char *addrFeedback = "del/f";

    }delay1;


};

#endif // FX_H
