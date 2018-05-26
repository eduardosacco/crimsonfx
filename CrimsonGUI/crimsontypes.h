#ifndef CRIMSONTYPES_H
#define CRIMSONTYPES_H

//CRIMSON TYPEDEFS ******************************
typedef struct
{
    int gain;
    int depth;
    int cutoff;
}FxOverdrive1;

typedef struct
{
    int dryWet;
    int roomSize;
    int damping;
}FxReverb1;

typedef struct
{
    int level;
    int delay;
    int feedback;
}FxDelay1;

#endif // CRIMSONTYPES_H
