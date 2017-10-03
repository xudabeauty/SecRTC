#ifndef LINKFILEWIDGET_H
#define LINKFILEWIDGET_H
#include<QtWidgets>
class QAction;
class QToolBar;
class QVBoxLayout;
class FileTreeView;
class LinkFileWidget:public QWidget
{
Q_OBJECT
public:
    LinkFileWidget();
     ~LinkFileWidget();

    void createAction();
    void createToolBar();
    void createMainWeiget();
private:
    QAction *cutAction;
    QAction*copyAction;
    QAction*pasteAction;
    QAction*deleteAction;
    QAction*uploadAction;
    QAction*downloadAction;

    QToolBar*fileToolBar;
    FileTreeView*fileTreeView;

    QVBoxLayout*filelistlayout;


};
#endif // LINKFILEWIDGET_H
