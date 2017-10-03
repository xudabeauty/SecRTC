#ifndef PROCESSTREEVIEW_H
#define PROCESSTREEVIEW_H

#include <QTreeView>
#include<QString>
class QStandardItemModel;
class QModelIndex;
class ProcessTreeView:public QTreeView
{
Q_OBJECT
public:
    ProcessTreeView();
    ~ProcessTreeView();

    void rebuildInfo();

    void addOneProcessitem(QString srProcess,QString strPid,QString strMen,QString strPart,QString strDes);

    void setNowSelectProcess(QModelIndex &index);

     QString getStrNowProcess();

private:
     QStandardItemModel *mainModel;
     QString strNowProcess;
     int iposition;
};
#endif // PROCESSTREEVIEW_H
