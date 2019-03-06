#ifndef THREADRECEIVER_H
#define THREADRECEIVER_H

#include <QUdpSocket>


class ThreadReceiver
{
public:
    static ThreadReceiver* instance();
    bool readDatagrams();
    QUdpSocket* receiveSocket;
private:
    ThreadReceiver();
    ~ThreadReceiver();
    static ThreadReceiver* _instance;
};

#endif // THREADRECEIVER_H
