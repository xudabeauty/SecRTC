#include<QtWidgets>
#include "../inlcude/linklistwidget.h"
#include"../inlcude/listwidgetitem.h"

LinkListWidget::LinkListWidget()
{
    QListWidget * pthis=this;
     QListWidgetItem *elem;
     ListWidgetItem* list= new ListWidgetItem;
     const QString ip="127.0.0.1";
     list->createConnectList(ip,elem,pthis);
   // elem = new ListWidgetItem(QIcon(":/res/images/connected.png"), "127.0.0.1 ", this);
    //elem = new ListWidgetItem(QIcon(":/res/images/connected.png"), "127.0.0.1 ", this)
     //elem = new QListWidgetItem(QIcon(":/res/images/connected.png"), "127.0.0.1 ", this);
   const QString ips="192.168.1.103";

     addListItem(ips);
}

LinkListWidget::~LinkListWidget( )
{


}
void LinkListWidget::addListItem(const QString ip)
{
     QListWidget * pthis=this;
     QListWidgetItem *elem;
     ListWidgetItem* list= new ListWidgetItem;
     //const QString ip="127.0.0.1";
     list->createConnectList(ip,elem,pthis);

}


