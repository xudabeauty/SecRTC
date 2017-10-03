#ifndef FILETREEVIEW_H
#define FILETREEVIEW_H
#include<QTreeView>
class QFileSystemModel;

class FileTreeView:public QTreeView
{
Q_OBJECT
public:
    FileTreeView();
    ~FileTreeView();
private:
    QFileSystemModel*fileModel;
};
#endif // FILETREEVIEW_H
