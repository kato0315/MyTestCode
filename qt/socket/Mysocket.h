#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QTcpSocket>
#include <QObject>
#include <QTimer>


class Mysocket : public QObject
{
    Q_OBJECT
public slots:
    void connectServer();
    void deleteSocket();
private:
    QTcpSocket *tcpSocket = nullptr;
signals:
    void connected();
};

#endif // MYSOCKET_H
