#include "crimson.h"

#include <QApplication>
#include <QFile>
#include <QDateTime>

//void myMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
//{
//     QString txt;
//     QDateTime date;

//     txt = msg;
//     txt.prepend(" - ");
//     txt.prepend(date.currentDateTime().toString());

//     QFile outFile("log.txt");
//     outFile.open(QIODevice::WriteOnly | QIODevice::Append);
//     QTextStream ts(&outFile);
//     ts << txt <<endl;

//}

void myMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QFile outFile("log.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QDateTime date;
    QTextStream ts(&outFile);

    QByteArray localMsg = msg.toLocal8Bit();
//    switch (type)
//    {
//        case QtDebugMsg:
//            fprintf(outFile, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
//            break;
//        case QtInfoMsg:
//            fprintf(outFile, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
//            break;
//        case QtWarningMsg:
//            fprintf(outFile, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
//            break;
//        case QtCriticalMsg:
//            fprintf(outFile, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
//            break;
//        case QtFatalMsg:
//            fprintf(outFile, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
//            abort();
//    }
    ts << date.currentDateTime().toString() << ": " <<localMsg.constData() << endl;
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(myMessageHandler);

    QFile outFile("log.txt");
    outFile.resize(0);

    QApplication a(argc, argv);

    a.setOrganizationName("Crimson");
    a.setApplicationName("Fx16");

    Crimson crimson;

    return a.exec();
}
