#ifndef LINKCMDWIDGET_H
#define LINKCMDWIDGET_H
#include<QtWidgets>
class QTextEdit;
class QLabel;
class QLineEdit;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class LinkCmdWidget:public QWidget
{
      Q_OBJECT
public:
    LinkCmdWidget();
    ~LinkCmdWidget();
    void createMainWidget();
private:
    QTextEdit*cmdTextEdit;//输出显示窗口
    QLabel* cmdLabel;//命令输入标签
    QLineEdit*cmdInputEdit;//发送命令按钮
    QPushButton*sendButton;

    QVBoxLayout*cmdlayout;//窗口控制
    QHBoxLayout*cmdButtonlayout;//底部窗口

};
#endif // LINKCMDWIDGET_H
