#ifndef UDPSENDER_H
#define UDPSENDER_H
#include <QQmlEngine>
#include <QtNetwork>

class UDPSender : public QObject
{
    Q_OBJECT
public:
    static QObject* instance(QQmlEngine*, QJSEngine* engine){
        static UDPSender* instance = new UDPSender(engine);
        return instance;
    }
    ~UDPSender();
    Q_INVOKABLE void send(QString data);
private:
    explicit UDPSender(QObject* parent=nullptr);
    QUdpSocket* sender;
};

#endif // UDPSENDER_H
