#ifndef THREADRECEIVER_H
#define THREADRECEIVER_H
#include <QUdpSocket>

class ThreadReceiver
{
public:
    static ThreadReceiver* instance();
    ~ThreadReceiver();
private:
    ThreadReceiver();
    static ThreadReceiver* _instance;
    QUdpSocket* receiveSocket;
    void readDatagrams();
};

#endif // THREADRECEIVER_H
