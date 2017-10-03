#include<QtWidgets>
#include "../inlcude/linkcmdwidget.h"
LinkCmdWidget::LinkCmdWidget()
{
    createMainWidget();
}
LinkCmdWidget::~LinkCmdWidget()
{

}
void LinkCmdWidget::createMainWidget()
{
cmdTextEdit=new QTextEdit();
cmdTextEdit->setReadOnly(true);
cmdLabel=new QLabel(tr("命令输入"));
cmdInputEdit=new QLineEdit();
sendButton=new QPushButton(tr("远程执行"));

cmdlayout=new QVBoxLayout();
cmdButtonlayout=new QHBoxLayout();

cmdButtonlayout->addWidget(cmdLabel);
cmdButtonlayout->addWidget(cmdInputEdit);
cmdButtonlayout->addWidget(sendButton);

cmdlayout->addWidget(cmdTextEdit);
cmdlayout->addLayout(cmdButtonlayout);
setLayout(cmdlayout);
}





