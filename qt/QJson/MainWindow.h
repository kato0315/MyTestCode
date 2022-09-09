#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct WindowsVmInfo{
    int index;
    QString vmName;
    QString account;
    QString password;

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void writeLoginHistroy(QString IP, QString account);
    QStringList readLoginHistroy();
    void deleteLoginHistroy(QString IP, QString account);
    WindowsVmInfo readWindowsVmInfo(QString IP, QString account, QString vmName);
    void writeWindowsVmInfo(QString IP, QString account,WindowsVmInfo winInfo);


    QJsonDocument readJsonDocument(QString filePath);
    void writeJsonDocument(QString filePath, QJsonArray array);
    QJsonObject newLoginHistroy(QString IP, QString account);
    QJsonObject newVmObject(WindowsVmInfo winInfo);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
