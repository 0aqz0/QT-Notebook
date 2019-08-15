#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "udpreceiver.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterSingletonType<UDPReceiver>("UDP", 1, 0, "UDPReceiver", &UDPReceiver::instance);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
