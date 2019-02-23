#ifndef SENDER_H
#define SENDER_H

#include <QObject>
#include <QQmlEngine>
#include <QtNetwork>

namespace {

}

class Sender : public QObject
{
    Q_OBJECT
public:
    static QObject* instance(QQmlEngine *, QJSEngine *engine){
        static Sender *instance = new Sender(engine);
        return instance;
    }
    ~Sender();
    Q_INVOKABLE void send();
private:
    explicit Sender(QObject *parent = nullptr);
    QUdpSocket* sender;
};

#endif // SENDER_H
