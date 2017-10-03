#include<QtWidgets>
#include"../inlcude/linkservicewidget.h"
#include"../inlcude/servicetreeview.h"
LinkServiceWidget::LinkServiceWidget()
{
    createMainWeiget();
}
LinkServiceWidget::~LinkServiceWidget()
{

}

void LinkServiceWidget::createMainWeiget()
{
    serviceLayout=new QVBoxLayout();
    servieButtonLayout=new QHBoxLayout();

    serviceTreeView=new ServiceTreeView();
    getserviceButton=new QPushButton(tr("获取服务列表"));
    runServiceButton=new QPushButton(tr("自动运行服务"));
    killServiceButton=new QPushButton(tr("关闭选中的服务"));
     servieButtonLayout->addStretch();
     servieButtonLayout->addWidget(getserviceButton);
     servieButtonLayout->addStretch();
     servieButtonLayout->addWidget(runServiceButton);
     servieButtonLayout->addStretch();
     servieButtonLayout->addWidget(killServiceButton);
     servieButtonLayout->addStretch();

     serviceLayout->addWidget(serviceTreeView);
     serviceLayout->addLayout(servieButtonLayout);

     setLayout(serviceLayout);

}
