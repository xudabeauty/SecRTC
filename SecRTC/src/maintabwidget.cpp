#include<QtWidgets>
#include "../inlcude/maintabwidget.h"
#include "../inlcude/linkfilewidget.h"
#include "../inlcude/linkcmdwidget.h"
#include "../inlcude/linkprocesswidget.h"
#include"../inlcude/linkservicewidget.h"

MainTabWidget::MainTabWidget()
{
    createMainWeiget();

    this->setTabPosition(QTabWidget::South);
    this->setDocumentMode(false);
    this->addTab(linkFileWidget,tr("远程文件管理"));
    this->addTab(linkProcessWidget,tr("远程进程管理"));
    this->addTab(linkServiceWidget,tr("远程服务管理"));
    this->addTab(linkCmdWidget,tr("远程cmd控制"));


}
MainTabWidget::~MainTabWidget()
{

}
void MainTabWidget::createMainWeiget()
{
    linkCmdWidget=new LinkCmdWidget();
    linkFileWidget=new LinkFileWidget();
    linkProcessWidget=new LinkProcessWidget();
    linkServiceWidget=new LinkServiceWidget();

}

