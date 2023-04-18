#include "Mysocket.h"

#include <QDebug>
#include <QThread>
#include <QHostAddress>
#include <QThread>

void Mysocket::connectServer()
{
    qDebug() << QThread::currentThread();
    if (tcpSocket == nullptr) {
        qDebug() << "new socket";
        tcpSocket = new QTcpSocket(this);
        connect(tcpSocket, &QTcpSocket::connected, this, [=](){
            emit connected();
        });
        connect(tcpSocket, &QTcpSocket::disconnected, this, [=](){
            tcpSocket->close();
            tcpSocket->deleteLater();
            tcpSocket = nullptr;
        });
        connect(tcpSocket, &QTcpSocket::readyRead, this, [=](){
            qDebug() << tcpSocket->readAll();
        });
    }


    if(tcpSocket->state() == QTcpSocket::UnconnectedState){
        tcpSocket->connectToHost(QHostAddress("192.168.3.75"), 9890);
        qDebug() << "connect to host";
    }

}


