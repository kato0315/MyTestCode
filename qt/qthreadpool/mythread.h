#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QRunnable>
#include <QObject>

#include <QVector>

//生成随机数
class Generate : public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);
    void run() override;
public slots:
    void recvNum(int num);


private:
    int m_num;
signals:
    void sendArray(QVector<int>);

};

class BubbleSort : public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);
    void run() override;
public slots:
    void recvArray(QVector<int> list);


private:
    QVector<int> m_list;
signals:
    void finish(QVector<int>);

};

class QuickSort :public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit QuickSort(QObject *parent = nullptr);
    void run() override;
public slots:
    void recvArray(QVector<int> list);


private:
    void quickSort(QVector<int> &s,int l ,int r);

private:
    QVector<int> m_list;
signals:
    void finish(QVector<int>);

};

#endif // MYTHREAD_H
