#include<QtWidgets>
#include"../inlcude/listwidgetitem.h"
ListWidgetItem::ListWidgetItem()
{

}
ListWidgetItem::~ListWidgetItem()
{

}
void ListWidgetItem::createConnectList(const QString ip,QListWidgetItem*elem,QListWidget*obj)
{
    //QListWidgetItem *elem;

    //elem = new QListWidgetItem(QIcon(":/res/images/connected.png"), "127.0.0.1 ", this);
    //elem = new LinkListWidget(QIcon(":/res/images/connected.png"), "127.0.0.1 ", this);
    elem = new QListWidgetItem(QIcon(":/res/images/connected.png"), ip, obj);

}
