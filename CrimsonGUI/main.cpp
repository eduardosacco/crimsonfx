#include "crimson.h"

#include <QApplication>
#include <QFile>
#include <QTime>
#include <QDateTime>
#include <QSplashScreen>
#include <QFontDatabase>

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

    QApplication a(argc, argv);

    int fontId = QFontDatabase::addApplicationFont(":/fonts/DejaVuSans.ttf");
    if(fontId != -1){
        QFont font = QFont("DejaVu Sans Book");
        a.setFont(font);
        qDebug() << "Loaded font correctly";
    }

    //Aviso a la aplicacion los nombres correpondientes
    a.setOrganizationName("Crimson");
    a.setApplicationName("Fx16");


    //Corro el programa principal
    Crimson crimson;

    return a.exec();
}
