#ifndef FX_H
#define FX_H

//Valores por defecto de carga de settings
#define OVERDRIVE1DEFAULTG 20
#define OVERDRIVE1DEFAULTD 50
#define OVERDRIVE1DEFAULTC 80

#define REVERB1DEFAULTDW 50
#define REVERB1DEFAULTRS 50
#define REVERB1DEFAULTD 20

#define DELAY1DEFAULTL 60
#define DELAY1DEFAULTD 20
#define DELAY1DEFAULTF 15

class Fx
{
public:
    Fx();

    int mainPreset=0;

    struct Overdrive1
    {
        float gain;
        float depth;
        float cutoff;

        int preset;

        const char *pdAddrGain = "over/g";
        const char *pdAddrDepth = "over/d";
        const char *pdAddrCuttof = "over/c";


    }overdrive1;

    struct Reverb1
    {
        float dryWet;
        float roomSize;
        float damping;

        int preset;

        const char *pdAddrWet = "rev/dw";
        const char *pdAddrDamping = "rev/d";
        const char *pdAddrRoomSize = "rev/rs";

    }reverb1;

    struct Delay1
    {
        float level;
        float delay;
        float feedback;

        int preset;

        const char *pdAddrLevel = "del/l";
        const char *pdAddrDelay = "del/d";
        const char *pdAddrFeedback = "del/f";

    }delay1;


};

#endif // FX_H
