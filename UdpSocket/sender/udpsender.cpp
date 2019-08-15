#include "udpsender.h"

UDPSender::UDPSender(QObject *parent) : QObject(parent){
    sender = new QUdpSocket();
}

UDPSender::~UDPSender(){
    sender->abort();
}

void UDPSender::send(QString data){
    QByteArray datagram = data.toLocal8Bit();
    sender->writeDatagram(datagram.data(), datagram.size(), QHostAddress::LocalHost, 6666);
    qDebug() << "sending: " << datagram.data();
}
