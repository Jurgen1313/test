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
#include <QMessageBox>
#include <QTime>

class MainWindow: public QDialog
{
    Q_OBJECT
public:
    MainWindow();
private:
//    enum Pic {};
    size_t lenght;
    size_t currentLenght;
    size_t Bid;
    double yourMoney;
    double coef;
    QString* Moves;
    int* MovesInt;

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
    QLabel *lTest;

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
    QHBoxLayout *lh7; //test layer

    QVBoxLayout *lv1;

    bool game();

public slots:
    void randPic();
    void resize(QString);
    void setValueHowMuchField(int);
    void setMakeBid(int);
    void setMakeBid(QString);
    void clear();
    void changedYouHave(QString);
};


//class PlayGame: public QObject
//{
//public:
//    PlayGame();
//};
#endif // MAINWINDOW_H
