//--------------------------------------------------------------------------------------------------
//              COMMS.H
//--------------------------------------------------------------------------------------------------

#ifndef COMMS_H
#define COMMS_H


//*****************************************************************
//                  DEFINES
//*****************************************************************
#define PORTPD 8888     // Puerto para comunicaciones con Pd
#define PORTQT 8889     // Puerto al cual esta escuchando Qt

#include <QObject>
#include <QUdpSocket>

//*****************************************************************
//                  COMMS
//*****************************************************************
class Comms : public QObject
{
    Q_OBJECT

public:
    explicit Comms(QObject *parent = nullptr);

    void oscSendInt(QString oscAddress, int position);

private:
    QUdpSocket *socket;
    QByteArray *oscMessage;

};

#endif // COMMS_H
