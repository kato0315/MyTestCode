#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "MyComboBox.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList str_list;
    for (int i = 0; i < 5; i++) {
        str_list.push_back(QString("192.168.3.32\ntest%1").arg(i));
    }

    ui->comboBoxB->setRemovableItems(str_list);
}

MainWindow::~MainWindow()
{
    delete ui;
}

