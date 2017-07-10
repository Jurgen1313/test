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
#include <QSlider>
#include <QString>

class MainWindow: public QDialog
{
    Q_OBJECT
public:
    MainWindow();
private:
    size_t lenght;
    size_t Bid;

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

    QSlider *sMakeBid;
    QSlider *sHowMuchFields;

    QHBoxLayout *lh1;
    QHBoxLayout *lh2;
    QHBoxLayout *lh3;
    QHBoxLayout *lh4;
    QHBoxLayout *lh5;
    QHBoxLayout *lh6;

//    QHBoxLayout *l1;
//    QHBoxLayout *l2;
    QVBoxLayout *lv1;

public slots:
    void randPic();
    void resize(QString);
    void setValueHowMuchField(int);
    void setMakeBid(int);
    void setMakeBid(QString);
};
#endif // MAINWINDOW_H
