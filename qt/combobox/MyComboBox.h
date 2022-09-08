#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#include <QComboBox>
#include <QListWidget>
#include <QPushButton>

class ComboItem : public QWidget
{
    Q_OBJECT
public:
    explicit ComboItem(const QString &text,QWidget *parent = nullptr);
    ~ComboItem();
    QString text();

private:
    QString textValue;
    QPushButton *btn;

signals:
    void itemClicked(QString);
};

class MyComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit MyComboBox(QWidget *parent = nullptr);
    void setRemovableItems(const QStringList &items);

private:
    QListWidget *itemList;
};

#endif // MYCOMBOBOX_H
