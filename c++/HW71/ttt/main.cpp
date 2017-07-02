#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    while (w.getStartGame())
    {/*
        if ((w.getPlayer1() == 0 && w.getWhosMove() == 1)||(w.getPlayer2() == 0 && w.getWhosMove() == 2))
            w.robotNumber(w.getField());*/
    }


    return a.exec();
}
