#ifndef MAINTABWIDGET_H
#define MAINTABWIDGET_H
#include<QtWidgets/QTableWidget>
#endif // MAINTABWIDGET_H
class LinkCmdWidget;
class LinkFileWidget;
class LinkProcessWidget;
class LinkServiceWidget;
class MainTabWidget:public QTabWidget
{
         Q_OBJECT
public:
    MainTabWidget();
    ~MainTabWidget();

    void createMainWeiget();
private:
    LinkCmdWidget*linkCmdWidget;
    LinkFileWidget*linkFileWidget;
    LinkProcessWidget*linkProcessWidget;
    LinkServiceWidget*linkServiceWidget;
};
