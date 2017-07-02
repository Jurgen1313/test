#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstdlib>
#include <ctime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void GameOver();
    int whoWin (int* Field, size_t& Player1Wins_, size_t& Player2Wins_);
    void robotNumber(int* Field);
    int getStartGame() const;
    int getPlayer1() const;
    int getPlayer2() const;
    int getWhosMove() const;
    int* getField();

private slots:
//    void on_pushButton_clicked();

    void on_pushStartButton_clicked();

    void on_ttt_0_0_clicked();

    void on_ttt_1_0_clicked();

    void on_ttt_2_0_clicked();

    void on_ttt_0_1_clicked();

    void on_ttt_1_1_clicked();

    void on_ttt_2_1_clicked();

    void on_ttt_0_2_clicked();

    void on_ttt_1_2_clicked();

    void on_ttt_2_2_clicked();

private:
    Ui::MainWindow *ui;

    const size_t n = 3; // Col
    const size_t m = 3; // Row
    size_t Player1Wins = 0;
    size_t Player2Wins = 0;
    int inputCount = 0;
    int StartGame = 0;

//    int time_val = time(NULL);
//    srand(time(NULL));

    int Player1 = 0; // 0 - BOT
    int Player2 = 0; // 1 - Human
    int PlayerMoves[9] = {0};

    // tic tac toe ---> ttt
    // ttt[cellNumber] = 10 ---> O
    // ttt[cellNumber] = 11 ---> X

    static const size_t tttLenght = 9;
    int tttField [tttLenght];// = {1,2,3,4,5,6,7,8,9};

};

#endif // MAINWINDOW_H
