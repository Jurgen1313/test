#include <QApplication>
#include <mainwindow.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow *ui = new MainWindow;

    ui->show();
    return app.exec() ;
}

