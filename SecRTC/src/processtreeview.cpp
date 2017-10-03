#include<QtWidgets>
#include"../inlcude/processtreeview.h"
ProcessTreeView::ProcessTreeView()
{
iposition=0;
mainModel=new QStandardItemModel();

mainModel->setColumnCount(5);
mainModel->setHeaderData(0,Qt::Horizontal,tr("映像名称"));
mainModel->setHeaderData(1,Qt::Horizontal,tr("PID"));
mainModel->setHeaderData(2,Qt::Horizontal,tr("内存"));
mainModel->setHeaderData(3,Qt::Horizontal,tr("映像路径"));
mainModel->setHeaderData(4,Qt::Horizontal,tr("描述"));
this->setModel(mainModel);
}

ProcessTreeView::~ProcessTreeView()
{

}

void ProcessTreeView::rebuildInfo()
{
mainModel->clear();
iposition=0;

mainModel->setColumnCount(5);
mainModel->setHeaderData(0,Qt::Horizontal,tr("映像名称"));
mainModel->setHeaderData(1,Qt::Horizontal,tr("PID"));
mainModel->setHeaderData(2,Qt::Horizontal,tr("内存"));
mainModel->setHeaderData(3,Qt::Horizontal,tr("映像路径"));
mainModel->setHeaderData(4,Qt::Horizontal,tr("描述"));
}

void ProcessTreeView::addOneProcessitem(QString srProcess,QString strPid,QString strMen,QString strPart,QString strDes)
{
    QStandardItem*item;

     item=new QStandardItem(QString(srProcess));
     mainModel->setItem(iposition,0,item);

     item=new QStandardItem(QString(strPid));
     mainModel->setItem(iposition,1,item);

     item=new QStandardItem(QString(strPart));
     mainModel->setItem(iposition,2,item);

     item=new QStandardItem(QString(strPart));
     mainModel->setItem(iposition,3,item);

     item=new QStandardItem(QString(strDes));
     mainModel->setItem(iposition,4,item);

     iposition++;
}

QString ProcessTreeView::getStrNowProcess()
{
    return strNowProcess;
}

