#define LOG

#include "crimson.h"
#include <QApplication>
#include <QFile>
#include <QTime>
#include <QDateTime>
#include <QSplashScreen>
#include <QFontDatabase>

#ifdef LOG

Crimson *crimson;

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QFile outFile("log.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QDateTime date;
    QTextStream ts(&outFile);

    QByteArray localMsg = msg.toLocal8Bit();

    ts << date.currentDateTime().toString() << ": " <<localMsg.constData() << endl;
    if (crimson)
    {
        crimson->sendDebugMes(date.currentDateTime().toString() + " : " +msg);
    }
}

#endif

int main(int argc, char *argv[])
{

#ifdef LOG
    //Cambio el gestor de mensajes por uno custom
    qInstallMessageHandler(myMessageOutput);
    //Abro o creo archivo de Log
    QFile outFile("log.txt");
    //Borro si ahbia un archivo viejo
    outFile.resize(0);
#endif

    QApplication a(argc, argv);

    int fontId = QFontDatabase::addApplicationFont(":/resources/DejaVuSans.ttf");
    if(fontId != -1){
        QFont font = QFont("DejaVu Sans Book");
        a.setFont(font);
        qDebug() << "Loaded font correctly";
    }

    //Aviso a la aplicacion los nombres correpondientes
    a.setOrganizationName("Crimson");
    a.setApplicationName("Fx16");

    //Corro el programa principal
    crimson = new Crimson;

    return a.exec();
}
