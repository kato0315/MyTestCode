#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QVector>

//生成随机数
class Generate : public QThread
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);

public slots:
    void recvNum(int num);
protected:
    void run() override;
private:
    int m_num;
signals:
    void sendArray(QVector<int>);

};

class BubbleSort : public QThread
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);

public slots:
    void recvArray(QVector<int> list);
protected:
    void run() override;
private:
    QVector<int> m_list;
signals:
    void finish(QVector<int>);

};

class QuickSort : public QThread
{
    Q_OBJECT
public:
    explicit QuickSort(QObject *parent = nullptr);

public slots:
    void recvArray(QVector<int> list);
protected:
    void run() override;
private:
    void quickSort(QVector<int> &s,int l ,int r);

private:
    QVector<int> m_list;
signals:
    void finish(QVector<int>);

};

#endif // MYTHREAD_H
