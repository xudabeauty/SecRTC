#include<QtWidgets>
#include "../inlcude/linkfilewidget.h"
#include"../inlcude/filetreeview.h"

LinkFileWidget::LinkFileWidget()
{
      createAction();
      createToolBar();
      createMainWeiget();

}
LinkFileWidget::~LinkFileWidget()
{

}
void LinkFileWidget::createAction()
{
fileTreeView=new FileTreeView();
cutAction=new QAction(tr("剪切"),this);
cutAction->setIcon(QIcon(":/res/images/file_cut.png"));
cutAction->setStatusTip(tr("剪切选中的文件"));

copyAction=new QAction(tr("复制"),this);
copyAction->setIcon(QIcon(":/res/images/file_copy.png"));
copyAction->setStatusTip(tr("复制选中的文件"));

pasteAction=new QAction(tr("粘贴"),this);
pasteAction->setIcon(QIcon(":/res/images/file_paste.png"));
pasteAction->setStatusTip(tr("粘贴文件"));

deleteAction=new QAction(tr("删除"),this);
deleteAction->setIcon(QIcon(":/res/images/file_delete.png"));
deleteAction->setStatusTip(tr("删除选中的文件"));

uploadAction=new QAction(tr("上传"),this);
uploadAction->setIcon(QIcon(":/res/images/file_upload.png"));
uploadAction->setStatusTip(tr("从本地上传文件到目标当前目录"));

downloadAction=new QAction(tr("下载"),this);
downloadAction->setIcon(QIcon(":/res/images/file_download.png"));
downloadAction->setStatusTip(tr("下载选中的文件到本地磁盘"));
}

void LinkFileWidget::createToolBar()
{
fileToolBar=new QToolBar();
fileToolBar->setIconSize(QSize(20,20));
fileToolBar->addSeparator();
fileToolBar->addAction(cutAction);
fileToolBar->addAction(copyAction);
fileToolBar->addAction(pasteAction);
fileToolBar->addAction(deleteAction);
fileToolBar->addSeparator();
fileToolBar->addAction(uploadAction);
fileToolBar->addAction(downloadAction);
}

void LinkFileWidget::createMainWeiget()
{
filelistlayout=new QVBoxLayout();
filelistlayout->addWidget(fileToolBar);
filelistlayout->addWidget(fileTreeView);
setLayout(filelistlayout);
}
