#include "threadreceiver.h"
#include <thread>

ThreadReceiver* ThreadReceiver::_instance = 0;

namespace {
    std::thread* _thread = nullptr;
    int PORT = 6666;
}

ThreadReceiver::ThreadReceiver(){
    receiveSocket = new QUdpSocket();
    receiveSocket->bind(QHostAddress::AnyIPv4, PORT, QUdpSocket::ShareAddress);

    _thread = new std::thread([ = ] {readDatagrams();});
}


ThreadReceiver::~ThreadReceiver(){
    receiveSocket->abort();
    if(_thread)
        delete _thread;
}

ThreadReceiver* ThreadReceiver::instance(){
    if(_instance == 0)
        _instance = new ThreadReceiver();
    return _instance;
}

bool ThreadReceiver::readDatagrams(){
    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
//        qDebug() << "I'm in the thread.";
        while(receiveSocket->state() == QUdpSocket::BoundState && receiveSocket->hasPendingDatagrams()){
            QByteArray datagram;
            datagram.resize(receiveSocket->pendingDatagramSize());
            receiveSocket->readDatagram(datagram.data(), datagram.size());
            qDebug() << "Receiving: " << datagram.data();
        }
    }

    return true;
}
