#include <QApplication>
#include <QWidget>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWidget *gui = new MainWidget;
    gui->show();
    return app.exec();
}

