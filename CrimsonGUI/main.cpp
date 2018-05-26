#include "crimson.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName("Crimson");
    a.setApplicationName("Fx16");

    Crimson crimson;

    return a.exec();
}
