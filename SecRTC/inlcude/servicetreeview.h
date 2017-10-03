#ifndef SERVICETREEVIEW_H
#define SERVICETREEVIEW_H
#include<QTreeView>
#include<QString>

class QStandardItemModel;
class QModelIndex;
class ServiceTreeView:public QTreeView
{
    Q_OBJECT
public:
    ServiceTreeView();
    ~ServiceTreeView();
    void rebuildInfo();

    void addOneSericeItem(QString strService,QString strPid,QString strDes,QString strState,QString strWorkGroup);

    void setNowSlectService(QModelIndex&index);
    QString getsStrNowService();

private:
     QStandardItemModel*mainModle;
     QString strNowService;
     int iPosition;
};

#endif // SERVICETREEVIEW_H
