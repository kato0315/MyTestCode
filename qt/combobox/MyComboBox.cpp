#include "MyComboBox.h"

#include <QHBoxLayout>
#include <QDebug>

ComboItem::ComboItem(const QString &text, QWidget *parent)
    : QWidget(parent),
      textValue(text),
      btn(new QPushButton("delete", this))
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    btn->setFixedSize(30,30);
    layout->addStretch();
    layout->addWidget(btn);
    layout->setMargin(0);
    layout->setSpacing(0);

    connect(btn, &QPushButton::clicked, this, [this]{
       emit itemClicked(textValue);
    });
}

ComboItem::~ComboItem()
{
    qDebug() << "delete" << textValue;
}

QString ComboItem::text()
{
    return textValue;
}

MyComboBox::MyComboBox(QWidget *parent)
    : QComboBox(parent),
      itemList(new QListWidget)
{
    setModel(itemList->model());
    setView(itemList);

}

void MyComboBox::setRemovableItems(const QStringList &items)
{
    itemList->clear();
    if (items.isEmpty())
        return;

    for (int i = 0; i < items.count(); i++) {
        QListWidgetItem* widget_item = new QListWidgetItem(itemList);
        ComboItem *item = new ComboItem(items.at(i), itemList);
        widget_item->setData(Qt::DisplayRole, items.at(i));
        itemList->setItemWidget(widget_item, item);//Sets the widget to be displayed in the given item.

        connect(item, &ComboItem::itemClicked, this, [this, widget_item](){
            itemList->takeItem(itemList->row(widget_item));//ListWidget移除目标Widget
            delete widget_item;
        });
    }

}


