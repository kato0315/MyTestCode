#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QThread>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class Test : public QObject
{
    Q_OBJECT
public:
    Test();
    ~Test();

private:
    QTimer *testTimer;
private slots:
    void testFun();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Test *test;
    QThread *testThread;
};
#endif // MAINWINDOW_H
