#include "crimson.h"

#include <QApplication>
#include <QFile>
#include <QTime>
#include <QDateTime>
#include <QSplashScreen>

void myMessageHandler( const QString &msg)
{
    QFile outFile("log.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QDateTime date;
    QTextStream ts(&outFile);

    QByteArray localMsg = msg.toLocal8Bit();

    ts << date.currentDateTime().toString() << ": " <<localMsg.constData() << endl;
}

int main(int argc, char *argv[])
{
//    //Cambio el gestor de mensajes por uno custom
//    qInstallMessageHandler(myMessageHandler);

//    //Abro o creo archivo de Log
//    QFile outFile("log.txt");
//    //Borro si ahbia un archivo viejo
//    outFile.resize(0);

    //Creo la aplicacion
    QApplication a(argc, argv);
    //Aviso a la aplicacion los nombres correpondientes
    a.setOrganizationName("Crimson");
    a.setApplicationName("Fx16");

//    //Splash screen
//    QSplashScreen *splash = new QSplashScreen;
//    splash->setPixmap(QPixmap(":/img/img/crimsonSplash.png"));
//    splash->showFullScreen();
//    splash->show();
//    //BLOCKING Delay
//    QTime dieTime= QTime::currentTime().addSecs(5);
//    while (QTime::currentTime() < dieTime)
//    {
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
//    //cierro el splashscreen
//    splash->close();

    //Corro el programa principal
    Crimson crimson;

    return a.exec();
}
