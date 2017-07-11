#include <QApplication>
#include <mainwindow.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow *ui = new MainWindow;
    ui->show();

    FirstPlayer *P1 = new FirstPlayer;
    ui->setMoney(P1->getMoney());

    QObject::connect(ui, SIGNAL(Play(const int* const, const int, const int)), P1, SLOT(playGame(const int* const, const int, const int)));
    QObject::connect(P1, SIGNAL(changedMoney(const int)), ui, SLOT(Money(const int)));
    QObject::connect(ui, SIGNAL(newGame()),P1,SLOT(newPGame()));

    return app.exec() ;
}

