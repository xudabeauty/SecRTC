#ifndef LINKLITWIDGET_H
#define LINKLITWIDGET_H
#include<QtWidgets/QListWidget>
class QStandardItemModel;
class ListWidgetItem;

class LinkListWidget:public QListWidget
{
    Q_OBJECT
public:
    LinkListWidget();
    ~LinkListWidget();
    void addListItem(const QString ip);
};
#endif // LINKLITWIDGET_H
