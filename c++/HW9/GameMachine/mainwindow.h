#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QVector>
#include <QPushButton>
#include <QLineEdit>

class MainWindow: public QDialog
{
    Q_OBJECT
public:
    MainWindow();
private:
    size_t lenght;

    QLabel *lYouHave;
    QLabel *lMakeBid;
    QLabel *lHowMuchFields;
    QLabel *lDollar;
    QLabel *labelPix1;// = new QLabel;
    QLabel *labelPix2;// = new QLabel;
    QLabel *labelPix3;// = new QLabel;
    QLabel *labelPix4;// = new QLabel;
    QLabel *labelPix5;// = new QLabel;
    QLabel *labelPix6;// = new QLabel;

    QLineEdit *elYouHave;
    QLineEdit *elMakeBid;
    QLineEdit *elHowMuchFields;

    QPushButton *bRun;
    QPushButton *bQuit;
    QPushButton *bClear;

    QPixmap pix1;
    QPixmap pix2;
    QPixmap pix3;
    QPixmap pix4;
    QPixmap pix5;
    QPixmap pix6;
    QVector<QLabel*> labels;
    QVector<QPixmap> pictures;
    QHBoxLayout *l1;
    QHBoxLayout *l2;
    QVBoxLayout *v1;

public slots:
    void randPic();
};
#endif // MAINWINDOW_H
