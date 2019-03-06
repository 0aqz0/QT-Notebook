#include <QCoreApplication>
#include "threadreceiver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ThreadReceiver::instance();

    return a.exec();
}
