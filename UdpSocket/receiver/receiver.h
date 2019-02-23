#ifndef RECEIVER_H
#define RECEIVER_H

#include <QtNetwork>
#include <QQmlEngine>

class Receiver : public QObject
{
    Q_OBJECT
public:
    Receiver(QObject* parent = nullptr);
    ~Receiver();
private:
    QUdpSocket *receiver;
private slots:
    void readDatagrams();
};

#endif // RECEIVER_H
