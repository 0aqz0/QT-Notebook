#include "sender.h"
#include <iostream>
#include <QtDebug>

Sender::Sender(QObject *parent) : QObject(parent){
    sender = new QUdpSocket();
    qDebug() << "I'm Sender";
}

Sender::~Sender(){
    delete sender;
}

void Sender::send(){
    QByteArray datagram = "hello, I'm sender!";

    // broadcast
    sender->writeDatagram(datagram.data(), datagram.size(), QHostAddress::LocalHost, 6665);

    // sender to specific IP
//    QHostAddress address = QHostAddress("10.12.11.66");
//    sender->writeDatagram(datagram.data(), datagram.size(), address, 6665);
    qDebug() << "sending!!!";
}
