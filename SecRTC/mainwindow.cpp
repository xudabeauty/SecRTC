#include<QtWidgets>
#include"mainwindow.h"
#include "inlcude/linklistwidget.h"
#include"inlcude/maintabwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)

{
    this->resize(1000,650);
    createMainWedget();
    createAction();
    createMenu();
    createToolBars();
    createStatus();
    setWindowIcon(QIcon(":/res/ico/main.ico"));
    setWindowTitle(tr("SecRet"));

}
void MainWindow::createMainWedget()
{
   currenLinkLabel=new QLabel(tr("连接主机"));
   currPortLable=new QLabel(tr("连接端口"));
   passwordLable=new QLabel(tr("连接密码"));

   currLinkEdit=new QLineEdit();
   currLinkEdit->setText("127.0.0.1");
   currLinkEdit->setMaxLength(15);

   currPortSpin=new QSpinBox();
   currPortSpin->setRange(1,65535);
   currPortSpin->setValue(5921);

   passwordEdit=new QLineEdit();
   //passwordEdit->setEchoMode(QLine::Password);

   linkButton=new QPushButton("连接");

   topLayout=new QHBoxLayout();
   topLayout->addWidget(currenLinkLabel);
   topLayout->addWidget(currLinkEdit);
   topLayout->addWidget(currPortLable);
   topLayout->addWidget(currPortSpin);
   topLayout->addWidget(passwordLable);
   topLayout->addWidget(passwordEdit);
   topLayout->addWidget(linkButton);

   linkListWdget=new LinkListWidget ();
   mainTabWidget=new MainTabWidget();

   bottomSplitter=new QSplitter(Qt::Horizontal);
   bottomSplitter->addWidget(linkListWdget);
   bottomSplitter->addWidget(mainTabWidget);
   bottomSplitter->setStretchFactor(1,1);

   mainLayout=new QVBoxLayout();
   mainLayout->addLayout(topLayout);
   mainLayout->addWidget(bottomSplitter);

   mainWidget=new QWidget();
   mainWidget->setLayout(mainLayout);
   this->setCentralWidget(mainWidget);

}


void MainWindow::createMenu()
{
    fileMenu=this->menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(auto_connAction);
    fileMenu->addAction(screenShotAction);
    fileMenu->addAction(camareAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

     setMenu=this->menuBar()->addMenu(tr("设置"));
     setMenu->addAction(configAction);
     setMenu->addSeparator();
     setMenu->addAction(settingAtion);

     toolsMenu=this->menuBar()->addMenu(tr("工具"));

     helpMenu=this->menuBar()->addMenu(tr("帮助"));
     helpMenu->addAction(aboutAction);
}

void MainWindow::createToolBars()
{
    fileToolBar=addToolBar(tr("文件"));
    fileToolBar->setIconSize(QSize(60,70));
    fileToolBar->addAction(auto_connAction);
    fileToolBar->addSeparator();
    fileToolBar->addAction(screenShotAction);
    fileToolBar->addSeparator();
    fileToolBar->addAction(settingAtion);

    workToolBar=addToolBar(tr("设置"));
    workToolBar->setIconSize(QSize(60,70));
    workToolBar->addAction(auto_connAction);
    workToolBar->addSeparator();
    workToolBar->addAction(settingAtion);

    infoToolBar=addToolBar(tr("其他"));
    infoToolBar->setIconSize(QSize(60,70));
    infoToolBar->addAction(minAction);
    infoToolBar->addSeparator();
    infoToolBar->addAction(exitAction);

    aboutTooBar=addToolBar(tr("关于"));
    aboutTooBar->setIconSize(QSize(60,70));
    aboutTooBar->addAction(aboutAction);
}
 void MainWindow::createStatus()
 {
  statusLable=new QLabel(tr("SecRet"));
  statusLable->setAlignment(Qt::AlignHCenter);
  statusLable->setMinimumSize(statusLable->sizeHint());

  this->statusBar()->addWidget(statusLable);
 }

 void MainWindow::createAction()
 {
    auto_connAction=new QAction(tr("自动上线"),this);
    auto_connAction->setIcon(QIcon(":/res/images/auto_conn.png"));
    auto_connAction->setStatusTip("自动上线设置");

    screenShotAction=new QAction(tr("屏幕捕获"),this);
    screenShotAction->setIcon(QIcon(":/res/images/screenshot.png"));
    screenShotAction->setStatusTip(tr("捕获被控端桌面"));
    //connect(screenShotAction, SIGNAL(triggered()), this, SLOT(screenshot()));

    camareAction=new QAction(tr("开启摄像头"),this);
    camareAction->setIcon(QIcon(":/res/images/camare.png"));
    camareAction->setStatusTip(tr("开启被控制的摄像头"));
    //connect(camareAction, SIGNAL(triggered()), this, SLOT(camare()));


    configAction=new QAction(tr("服务器配置"),this);
    configAction->setIcon(QIcon(":/res/images/config.png"));
    configAction->setStatusTip(tr("服务器配置"));

    settingAtion=new QAction(tr("程序设置"),this);
    settingAtion->setIcon(QIcon(":/res/images/setting.png"));
    settingAtion->setStatusTip(tr("程序设置"));

    minAction=new QAction(tr("最小化窗口"),this);
    minAction->setIcon(QIcon(":/res/images/min.png"));
    minAction->setStatusTip(tr("最小化程序窗口"));
    //connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    exitAction=new QAction(tr("退出程序"),this);
    exitAction->setIcon(QIcon(":/res/images/exit.png"));
    exitAction->setStatusTip(tr("退出程序"));
     //connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

    aboutAction=new QAction(tr("关于本程序"),this);
    aboutAction->setIcon(QIcon(":/res/images/about.png"));
    aboutAction->setStatusTip(tr("关于本程序"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
}


 void MainWindow::sleep(unsigned int sleepTime)
 {
QTime dieTime=QTime::currentTime().addMSecs(sleepTime);
while(QTime::currentTime()<dieTime)
{
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}
 }

MainWindow::~MainWindow()
{
   // delete ui;
}
