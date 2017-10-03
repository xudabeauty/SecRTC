#include<QtWidgets>
#include"../inlcude/servicetreeview.h"
ServiceTreeView::ServiceTreeView()
{
iPosition=0;

mainModle=new QStandardItemModel;
mainModle->setColumnCount(5);
mainModle->setHeaderData(0,Qt::Horizontal,tr("映像名称"));
mainModle->setHeaderData(1,Qt::Horizontal,tr("PID"));
mainModle->setHeaderData(2,Qt::Horizontal,tr("描述"));
mainModle->setHeaderData(3,Qt::Horizontal,tr("服务状态"));
mainModle->setHeaderData(4,Qt::Horizontal,tr("工作组"));
this->setModel(mainModle);
}
ServiceTreeView::~ServiceTreeView()
{

}

void ServiceTreeView::rebuildInfo()
{
mainModle->clear();
iPosition=0;
mainModle=new QStandardItemModel;
mainModle->setColumnCount(5);
mainModle->setHeaderData(0,Qt::Horizontal,tr("映像名称"));
mainModle->setHeaderData(1,Qt::Horizontal,tr("PID"));
mainModle->setHeaderData(2,Qt::Horizontal,tr("描述"));
mainModle->setHeaderData(3,Qt::Horizontal,tr("服务状态"));
mainModle->setHeaderData(4,Qt::Horizontal,tr("工作组"));
}


void ServiceTreeView::addOneSericeItem(QString strService, QString strPid,  QString strdes, QString strState, QString strWorkGroup)
{
QStandardItem * item;

item=new QStandardItem(QString(strService));
mainModle->setItem(iPosition,0,item);

item=new QStandardItem(QString(strPid));
mainModle->setItem(iPosition,1,item);

item=new QStandardItem(QString(strdes));
mainModle->setItem(2,iPosition,item);

item=new QStandardItem(QString(strState));
mainModle->setItem(3,iPosition,item);

item=new QStandardItem(QString(strWorkGroup));
mainModle->setItem(4,iPosition,item);

}


QString ServiceTreeView::getsStrNowService()
{
    return strNowService;
}

void ServiceTreeView::setNowSlectService(QModelIndex &index)
{
    strNowService=mainModle->data(index,0).toString();
}

