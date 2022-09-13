#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*writeLoginHistroy("192.168.3.32", "pub1");
    writeLoginHistroy("192.168.3.32", "pub2");
    writeLoginHistroy("192.168.3.32", "pub1");
    writeLoginHistroy("a.ylserver.com:4443", "zhang");
    qDebug() << readLoginHistroy();
    deleteLoginHistroy("192.168.3.32", "pub2");
    deleteLoginHistroy("192.168.3.32", "pub3");
    qDebug() << readLoginHistroy();*/
    WindowsVmInfo winInfo;
    winInfo.vmName = "test3";
    winInfo.account = "cccc";
    winInfo.password = "ddd";

    writeWindowsVmInfo("192.168.3.32", "pub1", winInfo);
    writeWindowsVmInfo("a.ylserver.com:4443", "zhang", winInfo);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::writeLoginHistroy(QString IP, QString account)
{
    QString filePath = QCoreApplication::applicationDirPath() + "/etc/loginHistroy.json";
    QJsonDocument document = readJsonDocument(filePath);
    QJsonArray loginArray;
    QJsonObject loginObject = newLoginHistroy(IP, account);

    if (!document.isNull()) {
        loginArray = document.array();
        for (QJsonArray::Iterator it = loginArray.begin(); it != loginArray.end(); it++) {
            QJsonObject object = it->toObject();
            if ((object.value("IP").toString() == IP) && (object.value("Account").toString() == account)) {
                return;
            }
        }
    }
    loginArray.append(loginObject);
    writeJsonDocument(filePath, loginArray);
}

QStringList MainWindow::readLoginHistroy()
{
    QString filePath = QCoreApplication::applicationDirPath() + "/etc/loginHistroy.json";
    QJsonDocument document = readJsonDocument(filePath);
    QJsonArray loginArray;
    QStringList loginHistroy;

    if (!document.isNull()) {
        loginArray = document.array();
        for (QJsonArray::Iterator it = loginArray.begin(); it != loginArray.end(); it++) {
            QJsonObject object = it->toObject();
            QString login = object.value("IP").toString() + "\n" + object.value("Account").toString();
            loginHistroy.append(login);
        }
    }

    return loginHistroy;
}

void MainWindow::deleteLoginHistroy(QString IP, QString account)
{
    QString filePath = QCoreApplication::applicationDirPath() + "/etc/loginHistroy.json";
    QJsonDocument document = readJsonDocument(filePath);
    QJsonArray loginArray;
    QJsonObject loginObject = newLoginHistroy(IP, account);

    if (!document.isNull()) {
        loginArray = document.array();
        for (QJsonArray::Iterator it = loginArray.begin(); it != loginArray.end(); it++) {
            QJsonObject object = it->toObject();
            if ((object.value("IP").toString() == IP) && (object.value("Account").toString() == account)) {
                loginArray.removeAt(it.i);
                writeJsonDocument(filePath, loginArray);
                return;
            }
        }
    }
}

WindowsVmInfo MainWindow::readWindowsVmInfo(QString IP, QString account, QString vmName)
{
    QString filePath = QCoreApplication::applicationDirPath() + "/etc/loginHistroy.json";
    QJsonDocument document = readJsonDocument(filePath);
    QJsonArray loginArray, vmArray;
    QJsonObject loginObject = newLoginHistroy(IP, account);
    WindowsVmInfo winInfo;

    if (!document.isNull()) {
        loginArray = document.array();
        for (QJsonArray::Iterator it = loginArray.begin(); it != loginArray.end(); it++) {
            QJsonObject object = it->toObject();
            if ((object.value("IP").toString() == IP) && (object.value("Account").toString() == account)) {
                vmArray = object.value("Vm").toArray();
            }
        }
        for (QJsonArray::Iterator it = vmArray.begin(); it != vmArray.end(); it++) {
            QJsonObject object = it->toObject();
            if (object.value("Name").toString() == vmName) {
                winInfo.vmName = vmName;
                winInfo.account = object.value("VmAccount").toString();
                winInfo.password = object.value("VmPassword").toString();
            }
        }
    }

    return winInfo;
}

void MainWindow::writeWindowsVmInfo(QString IP, QString account, WindowsVmInfo winInfo)
{
    QString filePath = QCoreApplication::applicationDirPath() + "/etc/loginHistroy.json";
    QJsonDocument document = readJsonDocument(filePath);
    QJsonArray loginArray;
    //QJsonObject vmObject = newVmObject(winInfo);

    if (!document.isNull()) {
        loginArray = document.array();
        for (QJsonArray::Iterator it = loginArray.begin(); it != loginArray.end(); it++) {
            QJsonObject object = it->toObject();
            if ((object.value("IP").toString() == IP) && (object.value("Account").toString() == account)) {
                //找到对应的账号,移除对应object
                loginArray.removeAt(it.i);
                qDebug () << "found account";
                QJsonObject modifiedObject = modifyVmInfo(object, winInfo);
                //修改object后，添加object，退出循环
                loginArray.append(modifiedObject);
                break;
            }

        }

    }
    qDebug() << "write window info:" << loginArray;
    writeJsonDocument(filePath, loginArray);
}

QJsonDocument MainWindow::readJsonDocument(QString filePath)
{
    QJsonDocument document;
    QFile jsonFile(filePath);
    if (!jsonFile.open(QFile::ReadWrite)) {
        qDebug() << "file open error";
        return document;
    }
    document = QJsonDocument::fromJson(jsonFile.readAll());
    jsonFile.close();

    return document;
}

void MainWindow::writeJsonDocument(QString filePath, QJsonArray array)
{
    QFile jsonFile(filePath);
    QJsonDocument document;
    document.setArray(array);
    if (!jsonFile.open(QFile::WriteOnly | QFile::Truncate)) {
        qDebug() << "file open error";
        return;
    }
    jsonFile.write(document.toJson());
    jsonFile.close();
}


QJsonObject MainWindow::newLoginHistroy(QString IP, QString account)
{
    QJsonArray array;
    QJsonObject loginObject;

    loginObject.insert("IP", IP);
    loginObject.insert("Account", account);
    loginObject.insert("Vm", array);

    return loginObject;
}



QJsonObject MainWindow::newVmObject(WindowsVmInfo winInfo)
{
    QJsonObject vmObject;

    vmObject.insert("Name", winInfo.vmName);
    vmObject.insert("VmAccount", winInfo.account);
    vmObject.insert("VmPassword", winInfo.password);

    return vmObject;
}

QJsonObject MainWindow::modifyVmInfo(QJsonObject object, WindowsVmInfo winInfo)
{
    QJsonObject vmObject = newVmObject(winInfo);
    QJsonArray vmArray = object.value("Vm").toArray();
    qDebug() << "object:" << object;
    qDebug() << "vmArray:" << vmArray.count();
    object.remove("Vm");
    for (QJsonArray::Iterator it1 = vmArray.begin(); it1 != vmArray.end(); it1++) {
        QJsonObject rmObject = it1->toObject();
        //qDebug() << "object:" << object;
        if (rmObject.value("Name").toString() == winInfo.vmName) {
            vmArray.removeAt(it1.i);
            break;
        }
    }
    vmArray.append(vmObject);
    object.insert("Vm",vmArray);
    qDebug() << "modify vm info:"<< object;

    return object;
}
