#include "mainwindow.h"
#include <QApplication>
#include<QtWidgets/qsplashscreen.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen splashScreen;

    splashScreen.setPixmap(QPixmap(":/res/images/logo.png"));
    splashScreen.show();
    MainWindow *w=new MainWindow;
    w->sleep(1000);
    w->show();
    splashScreen.finish(w);
    //delete splashScreen;
    return a.exec();
}
