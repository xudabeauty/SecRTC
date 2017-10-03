#ifndef LINKSERVICEWIDGET_H
#define LINKSERVICEWIDGET_H
#include<Qwidget>
class QHBoxLayout;
class QVBoxLayout;
class QPushButton;
class ServiceTreeView;

class LinkServiceWidget:public QWidget
{
Q_OBJECT
public:
    LinkServiceWidget();
    ~LinkServiceWidget();
    void createMainWeiget();
private:
    ServiceTreeView*serviceTreeView;
    QPushButton*getserviceButton;
    QPushButton*runServiceButton;
    QPushButton*killServiceButton;

    QVBoxLayout*serviceLayout;
    QHBoxLayout*servieButtonLayout;
};

#endif // LINKSERVICEWIDGET_H
