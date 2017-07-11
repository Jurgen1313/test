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
    void setMoney(const int);
private:
//    enum Pic {};
    size_t lenght;
    size_t currentLenght;
    size_t Bid;

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

private slots:
    void randPic();
    void resize(QString);
    void setValueHowMuchField(int);
    void setMakeBid(int);
    void setMakeBid(QString);
    void clear();
    void changedYouHave(QString);
    void Money(const int);

signals:
    void Play(const int* const, const int, const int);
    void newGame();
};

class Player: public QObject
{
    Q_OBJECT
private:
    double yourMoney;
    double coef;
    double Bid;
public:
    Player(int money = 500):yourMoney(money), coef(1), Bid(0){}
    virtual ~Player(){}
    int getMoney() const;
    void setMoney(const int);
    int getCoef() const;
    void setCoef(const int);
    virtual bool game(const int* const, const int) = 0;
public slots:
    void playGame(const int* const, const int, const int);
    void newPGame();
signals:
    void changedMoney(const int);
};

class FirstPlayer: public Player
{
public:
    FirstPlayer(int money = 500): Player(money){}
    ~FirstPlayer(){}
    bool game(const int* const, const int);
};

#endif // MAINWINDOW_H
