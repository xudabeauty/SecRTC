#include<QtWidgets>
#include"inlcude/filetreeview.h"

FileTreeView::FileTreeView()
{
fileModel=new QFileSystemModel();

fileModel->setRootPath("");
this->setModel(fileModel);
this->setAnimated(false);
this->setIndentation(20);

}
FileTreeView::~FileTreeView()
{

}
