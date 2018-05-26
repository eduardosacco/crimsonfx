#include "crimson.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Crimson crimson;

    return a.exec();
}
