#ifndef LINKPROCESSWIDGET_H
#define LINKPROCESSWIDGET_H
#include <QWidget>
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class FileTreeView;
class ProcessTreeView;
class LinkProcessWidget:public QWidget
{
Q_OBJECT
public:
   LinkProcessWidget();
  ~LinkProcessWidget();

   void createMainWdget();
private:
   ProcessTreeView*processTreeView;
   QPushButton*getProcessButton;
   QPushButton*killProcessButton;

   QVBoxLayout*processLayout;
   QHBoxLayout*processButtonLayout;
};
#endif // LINKPROCESSWIDGET_H
