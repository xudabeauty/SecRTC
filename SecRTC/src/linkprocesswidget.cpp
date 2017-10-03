#include<Qtwidgets>
#include "../inlcude/linkprocesswidget.h"
#include"../inlcude/processtreeview.h"

LinkProcessWidget::LinkProcessWidget()
{
createMainWdget();
}
LinkProcessWidget::~LinkProcessWidget()
{
}
void LinkProcessWidget::createMainWdget()
{
processLayout=new QVBoxLayout();
processButtonLayout=new QHBoxLayout();

processTreeView=new ProcessTreeView();
getProcessButton=new QPushButton(tr("获取进程列表"));
killProcessButton=new QPushButton(tr("结束选中的进程"));
processButtonLayout->addStretch();
processButtonLayout->addWidget(getProcessButton);
processButtonLayout->addStretch();
processButtonLayout->addWidget(killProcessButton);
processButtonLayout->addStretch();

processLayout->addWidget(processTreeView);
processLayout->addLayout(processButtonLayout);
setLayout(processLayout);
}
