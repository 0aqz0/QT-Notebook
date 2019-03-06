#include "receiver.h"
#include <QDebug>

Receiver::Receiver(QObject* parent) : QObject(parent)
{
    receiver = new QUdpSocket();
    receiver->bind(QHostAddress::LocalHost, 6666);
    connect(receiver, SIGNAL(readyRead()), this, SLOT(readDatagrams()));
    qDebug() << "I'm Receiver";
}

Receiver::~Receiver(){
    delete receiver;
}

void Receiver::readDatagrams(){
    while(receiver->hasPendingDatagrams()){
        QByteArray datagram;
        datagram.resize(receiver->pendingDatagramSize());
        receiver->readDatagram(datagram.data(), datagram.size());
        qDebug() << "Receiving: " << datagram.data();
    }
}
