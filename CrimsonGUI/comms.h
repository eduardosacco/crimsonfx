//*****************************************************************************
// asdadasd es un modulo que brinda funciones para que la interfaz grafica se
// comunique con Pd a traves de Universal Datagram Protocol (UDP) y el
// protocolo Open Sound Control
//*****************************************************************************

#ifndef COMMS_H
#define COMMS_H


#define PORTPD 8888     //Puerto para comunicaciones con Pd

#define PORTQT 8889     //Puerto al cual esta escuchando Qt

#include <QObject>
#include <QUdpSocket>

class Comms : public QObject
{
    Q_OBJECT

public:
    explicit Comms(QObject *parent = nullptr);

    //Direcciones OSC para envio de parametros

    //OVERDRIVE
    static const QString oscOverdrive1State;
    static const QString oscOverdrive1Gain;
    static const QString oscOverdrive1Depth;
    static const QString oscOverdrive1Cutoff;

    //REVERB
    static const QString oscReverb1State;
    static const QString oscReverb1DryWet;
    static const QString oscReverb1Damping;
    static const QString oscReverb1RoomSize;

    //DELAY
    static const QString oscDelay1State;
    static const QString oscDelay1Level;
    static const QString oscDelay1Delay;
    static const QString oscDelay1Feedback;

    void oscSendInt(QString oscAddress, int position);

private:
    QUdpSocket *socket;
    QByteArray *oscMessage;

};

#endif // COMMS_H
