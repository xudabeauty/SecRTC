#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QtWidgets/QMainWindow>
#include<QtWidgets/QLabel>

//namespace Ui {
//class MainWindow;
//}
class QLabel;
class QSplitter;
class QMenu;
class QToolBar;
class QAction;
class QSpinBox;
class QLineEdit;
class  QPushButton;

class QSplitter;
class QHBoxLayout;
class QVBoxLayout;

class LinkListWidget;
class MainTabWidget;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void sleep(unsigned int sleepTime);
//private slots:
//    void screenshot();
//    void camera();
//    void about();


private:
   // Ui::MainWindow *ui;
    void createMainWedget();//创建主窗口
    void createAction();//创建动作
     void createMenu();//创建主菜单
    void createToolBars();//创建工具栏
    void createStatus();//创建状态栏


    QLabel *statusLable;//状态栏标签

    QLabel *currenLinkLabel;//当前连接标签
    QLabel *currPortLable;//连接端口标签
    QLabel *passwordLable;//密码标签

    QLineEdit*currLinkEdit;
    QSpinBox*currPortSpin;
    QLineEdit*passwordEdit;

    QPushButton*linkButton;//手动连接按钮

    LinkListWidget *linkListWdget;//连接主机树形显示

    MainTabWidget*mainTabWidget;//标签管理

    QHBoxLayout *topLayout;//顶部窗口
    QSplitter*bottomSplitter;//底部窗口
    QVBoxLayout*mainLayout;//主窗口

    QWidget*mainWidget;

     QMenu *fileMenu;//文件子菜单指针
     QMenu*toolsMenu;//工具子菜单
     QMenu*setMenu;//设置菜单
     QMenu*helpMenu;//帮助菜单

    QToolBar*fileToolBar;//工具栏
    QToolBar*workToolBar;
    QToolBar*infoToolBar;
    QToolBar*aboutTooBar;

    QAction *auto_connAction;//自动上线
    QAction*screenShotAction;//屏幕捕获
    QAction*camareAction;//开启摄像头
    QAction*configAction;//服务端配置

    QAction*settingAtion;//设置
    QAction*minAction;//最小化
    QAction*exitAction;//退出
    QAction*aboutAction;//关于本程序


};



#endif // MAINWINDOW_H
