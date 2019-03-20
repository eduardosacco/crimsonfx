//--------------------------------------------------------------------------------------------------
//              COMMS.CPP
//--------------------------------------------------------------------------------------------------
#include "comms.h"

#include "tinyosc.h"    // Funciones para escritura y parseo de mensajes en protocolo OSC
#include <math.h>
#include <string.h>
#include <qdatetime.h>

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
    // Escribe paquete OSC al buffer
    // Devuelve numero de bytes escritos al buffer, negativo si hay error
    // borra el buffer antes de escribir nuevamente
    int len = int(tosc_writeMessage( buffer, sizeof(buffer),
        oscAddress.toLatin1(),     // direccion OSC
        "i",            // formato; 'f':32-bit float, 's':ascii string, 'i':32-bit integer
        position));     // dato a enviar

    // Envio el dato por UDP
    socket->writeDatagram(QByteArray(buffer,len),QHostAddress::LocalHost, PORTPD);

    qDebug() << QString::fromLatin1(buffer) << " " << QString::number(position) ; //Debug MSG
}
