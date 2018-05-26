#include "comms.h"

#include "tinyosc.h"    //Funciones para escritura y parseo de mensajes en protocolo OSC
#include <math.h>
#include <string.h>

//Direcciones OSC para envio de parametros

//OVERDRIVE
 const QString Comms::oscOverdrive1State = "/over/x";
 const QString Comms::oscOverdrive1Gain = "/over/g";
 const QString Comms::oscOverdrive1Depth = "/over/d";
 const QString Comms::oscOverdrive1Cutoff = "/over/c";

//REVERB
 const QString Comms::oscReverb1State = "/rev/x";
 const QString Comms::oscReverb1DryWet = "/rev/dw";
 const QString Comms::oscReverb1Damping = "/rev/d";
 const QString Comms::oscReverb1RoomSize = "/rev/rs";

//DELAY
 const QString Comms::oscDelay1State = "/del/x";
 const QString Comms::oscDelay1Level = "/del/l";
 const QString Comms::oscDelay1Delay = "/del/d";
 const QString Comms::oscDelay1Feedback = "/del/f";

Comms::Comms(QObject *parent) :
    QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost,PORTQT);
    connect(socket,SIGNAL(readyRead()),this, SLOT(readyRead()));
}

void Comms::readyRead()
{
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());
    QHostAddress senderAddress;
    quint16 senderPort;

    socket->readDatagram(buffer.data(), buffer.size(), &senderAddress, &senderPort);

    qDebug() << "Message from: " << senderAddress.toString();
    qDebug() << " " << senderPort;
    qDebug() << "Message: " << buffer;
}

void Comms::oscSendInt(QString oscAddress, int position )
{

    char buffer[128];
    // write the OSC packet to the buffer
    // returns the number of bytes written to the buffer, negative on error
    // note that tosc_write will clear the entire buffer before writing to it
    int len = tosc_writeMessage( buffer, sizeof(buffer),
        oscAddress.toLatin1(),     // the address
        "i",            // the format; 'f':32-bit float, 's':ascii string, 'i':32-bit integer
        position        // the integer
                                 );

    socket->writeDatagram(QByteArray(buffer,len),QHostAddress::LocalHost,PORTPD);

    qDebug() << QString::fromLatin1(buffer) << " " << QString::number(position) ; //si queres debuggear en QT

}
