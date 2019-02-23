#include "sender.h"
#include <iostream>

Sender::Sender(QObject *parent) : QObject(parent){
    sender = new QUdpSocket();
}

Sender::~Sender(){
    delete sender;
}

void Sender::send(){
    using std::cout;
    QByteArray datagram = "hello, I'm sender!";

    // broadcast
    sender->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 6665);

    // sender to specific IP
    QHostAddress address = QHostAddress("10.12.11.66");
    sender->writeDatagram(datagram.data(), datagram.size(), address, 6665);
    cout << "Sending\n";
}
