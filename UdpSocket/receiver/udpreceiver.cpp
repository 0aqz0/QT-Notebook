#include "udpreceiver.h"

UDPReceiver::UDPReceiver(QObject* parent) : QObject(parent)
{
    receiver = new QUdpSocket();
    receiver->bind(QHostAddress::LocalHost, 6666);
    connect(receiver, SIGNAL(readyRead()), this, SLOT(readDatagrams()));
}

UDPReceiver::~UDPReceiver(){
    receiver->abort();
}

void UDPReceiver::readDatagrams(){
    while(receiver->hasPendingDatagrams()){
        QByteArray datagram;
        datagram.resize(receiver->pendingDatagramSize());
        receiver->readDatagram(datagram.data(), datagram.size());
        m_data = QString::fromStdString(datagram.toStdString());
        emit dataChanged();
        qDebug() << "Receiving: " << datagram.data();
    }
}
