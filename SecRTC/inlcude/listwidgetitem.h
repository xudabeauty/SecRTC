#ifndef LISTEIDGETITEM_H
#define LISTEIDGETITEM_H
#include<QtWidgets>
class QListWidgetItem;

class ListWidgetItem:public QWidget

{
    Q_OBJECT
public:

    ListWidgetItem();
    ~ListWidgetItem();
    void createConnectList(const QString ip,QListWidgetItem*elem,QListWidget *listitem);


};

#endif // LISTEIDGETITEM_H
