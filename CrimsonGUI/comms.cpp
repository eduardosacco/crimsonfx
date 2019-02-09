#include "comms.h"

#include "tinyosc.h"    //Funciones para escritura y parseo de mensajes en protocolo OSC
#include <math.h>
#include <string.h>
#include <qdatetime.h>

//Direcciones OSC para envio de parametros

Comms::Comms(QObject *parent) :
    QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost,PORTQT);
    connect(socket,SIGNAL(readyRead()),this, SLOT(readyRead()));
}

void Comms::oscSendInt(QString oscAddress, int position )
{
    char buffer[128];
    // write the OSC packet to the buffer
    // returns the number of bytes written to the buffer, negative on error
    // note that tosc_write will clear the entire buffer before writing to it
    int len = int(tosc_writeMessage( buffer, sizeof(buffer),
        oscAddress.toLatin1(),     // the address
        "i",            // the format; 'f':32-bit float, 's':ascii string, 'i':32-bit integer
        position));     // the integer

    socket->writeDatagram(QByteArray(buffer,len),QHostAddress::LocalHost,PORTPD);

    qDebug() << QString::fromLatin1(buffer) << " " << QString::number(position) ; //Debug MSG
}
