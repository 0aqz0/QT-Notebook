#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H
#include <QtNetwork>
#include <QQmlEngine>

class UDPReceiver : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString data READ data NOTIFY dataChanged)
public:
    static QObject* instance(QQmlEngine*, QJSEngine* engine){
        static UDPReceiver* instance = new UDPReceiver(engine);
        return instance;
    }
    ~UDPReceiver();
    QString data(){
        return m_data;
    }
private:
    explicit UDPReceiver(QObject *parent=nullptr);
    QUdpSocket* receiver;
    QString m_data;
signals:
    void dataChanged();
private slots:
    void readDatagrams();
};

#endif // UDPRECEIVER_H
