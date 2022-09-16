#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << QThread::currentThreadId();
    test = new Test;
    testThread = new QThread;
    test->moveToThread(testThread);
    testThread->start();
    connect(this, &MainWindow::destroyed, this, [=]()
    {
        testThread->quit();
        testThread->wait();
        testThread->deleteLater();
        qDebug() << "delete test Thread";
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    delete test;
}


Test::Test()
{
    testTimer = new QTimer;
    connect(testTimer, &QTimer::timeout, this, &Test::testFun);
    testTimer->start(2000);
}

Test::~Test()
{
    qDebug() << QThread::currentThreadId();
    delete testTimer;
}

void Test::testFun()
{
    qDebug() << "testing";
    qDebug() << QThread::currentThreadId();
}
