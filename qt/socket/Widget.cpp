#include "Widget.h"
#include "ui_Widget.h"
#include <QPushButton>
#include <QHostAddress>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    mySocket = new Mysocket;
    mySocketThread = new QThread;
    mySocket->moveToThread(mySocketThread);
    mySocketThread->start();

    connect(this, &Widget::destroyed, this, [=]()
    {
        mySocketThread->quit();
        mySocketThread->wait();
        mySocketThread->deleteLater();
    });

    retryTimer = new QTimer(this);
    connect(retryTimer, &QTimer::timeout, mySocket,&Mysocket::connectServer);
    retryTimer->start(1000);

}

Widget::~Widget()
{
    delete ui;
}



