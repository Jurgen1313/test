#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->ttt_0_0->setEnabled(false);
    ui->ttt_0_1->setEnabled(false);
    ui->ttt_0_2->setEnabled(false);
    ui->ttt_1_0->setEnabled(false);
    ui->ttt_1_1->setEnabled(false);
    ui->ttt_1_2->setEnabled(false);
    ui->ttt_2_0->setEnabled(false);
    ui->ttt_2_1->setEnabled(false);
    ui->ttt_2_2->setEnabled(false);
    ui->pushStartButton->setEnabled(true);
    ui->whosMove->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getStartGame() const
{
    return StartGame;
}

int MainWindow::getPlayer1() const
{
    return Player1;
}

int MainWindow::getPlayer2() const
{
    return Player2;
}
int MainWindow::getWhosMove() const
{
    if (ui->whosMove->text() == "Player 1 move")
        return 1;
    if (ui->whosMove->text() == "Player 2 move")
        return 2;
}

void MainWindow::GameOver()
{
    ui->pushStartButton->setEnabled(true);
    ui->groupBox->setEnabled(true);
    ui->groupBox_2->setEnabled(true);
    ui->ttt_0_0->setEnabled(false);
    ui->ttt_0_1->setEnabled(false);
    ui->ttt_0_2->setEnabled(false);
    ui->ttt_1_0->setEnabled(false);
    ui->ttt_1_1->setEnabled(false);
    ui->ttt_1_2->setEnabled(false);
    ui->ttt_2_0->setEnabled(false);
    ui->ttt_2_1->setEnabled(false);
    ui->ttt_2_2->setEnabled(false);
    inputCount = 0;
    for (size_t i = 0; i < 9; ++i)
        tttField[i] = 0;

    StartGame = 0;


}

void MainWindow::on_pushStartButton_clicked()
{
    ui->pushStartButton->setEnabled(false);
    ui->groupBox->setEnabled(false);
    ui->groupBox_2->setEnabled(false);

    ui->ttt_0_0->setEnabled(true);
//    ui->ttt_0_0->colorCount(QT::red);
    ui->ttt_0_1->setEnabled(true);
    ui->ttt_0_2->setEnabled(true);
    ui->ttt_1_0->setEnabled(true);
    ui->ttt_1_1->setEnabled(true);
    ui->ttt_1_2->setEnabled(true);
    ui->ttt_2_0->setEnabled(true);
    ui->ttt_2_1->setEnabled(true);
    ui->ttt_2_2->setEnabled(true);

    ui->ttt_0_0->setText("");
    ui->ttt_0_1->setText("");
    ui->ttt_0_2->setText("");
    ui->ttt_1_0->setText("");
    ui->ttt_1_1->setText("");
    ui->ttt_1_2->setText("");
    ui->ttt_2_0->setText("");
    ui->ttt_2_1->setText("");
    ui->ttt_2_2->setText("");


    if (ui->radioButton_P1_Bot->isChecked())
        Player1 = 0;
    else
        Player1 = 1;
    if (ui->radioButton_P2_Bot->isChecked())
        Player2 = 0;
    else
        Player2 = 1;

    if (Player1 == 0)
        ui->label1->setText("BOT");
    else
        ui->label1->setText("HUMAN");
    if (Player2 == 0)
        ui->label2->setText("BOT");
    else
        ui->label2->setText("HUMAN");

    for (size_t i = 0; i < tttLenght; ++i)
        tttField[i] = i;

    ui->whosMove->setText("Player 1 move");
    StartGame = 1;

}

//int* getField()
//{
//    return tttField;
//}
void MainWindow::robotNumber(int* Field)
{
    int cellNumber;
    cellNumber = rand() % 9 + 1;
    --cellNumber;
    while (Field[cellNumber] == 10 || Field[cellNumber] == 11)
    {
        cellNumber = rand() % 9 + 1;
        --cellNumber;
    }
//    std::cout << "random : " << cellNumber + 1 << std::endl;
//    return cellNumber;
}

int MainWindow::whoWin (int* Field, size_t& Player1Wins_, size_t& Player2Wins_)
{
//    int Winner = 0;
    size_t Col = 3;
    size_t lenght = 9;
    //Check horizontal
    for (size_t i = 0; i <  Col; ++i)
    {
        int sumO = 0;
        int sumX = 0;
        for (size_t j = 0; j < Col; ++j)
        {
            if (Field[i + Col * j] == 10)
                ++sumO;
            else if (Field[i + Col * j] == 11)
                ++sumX;
        }
        if (sumO == 3)
        {
//            std::cout << "Win Player 1" << std::endl;
            ui->whosMove->setText("WIN Player 1 ");
            ++Player1Wins_;
//            Winner = 1;
            return 1;
        }
        if (sumX == 3)
        {
//            std::cout << "Win Player 2" << std::endl;
            ui->whosMove->setText("WIN Player 2 ");
            ++Player2Wins_;
//            Winner = 1;
            return 1;
        }
    }

    //Check vertical
    for (size_t i = 0; i < Col; ++i)
    {
        int sumO = 0;
        int sumX = 0;
        for (size_t j = 0; j < Col; ++j)
        {
            if (Field[j + Col * i] == 10)
                ++sumO;
            else if (Field[j + Col * i] == 11)
                ++sumX;
        }
        if (sumO == 3)
        {
//            std::cout << "Win Player 1" << std::endl;
            ui->whosMove->setText("WIN Player 1 ");
            ++Player1Wins_;
//            Winner = 1;
            return 1;
        }
        if (sumX == 3)
        {
//            std::cout << "Win Player 2" << std::endl;
            ui->whosMove->setText("WIN Player 2 ");
            ++Player2Wins_;
//            Winner = 1;
            return 1;
        }
    }

    int sumO = 0;
    int sumX = 0;
    //Check diagonals leftUpper ---> rightLower
    for (size_t i = 0; i < Col; ++i)
    {
        if (Field[i + Col * i] == 10)
            ++sumO;
        else if (Field[i + Col * i] == 11)
            ++sumX;
//        cout << "i : " << i << "  " << Field[i + Col * i] << endl;
        if (sumO == 3)
        {
//            std::cout << "Win Player 1" << std::endl;
            ui->whosMove->setText("WIN Player 1 ");
            ++Player1Wins_;
//            Winner = 1;
            return 1;
        }
        if (sumX == 3)
        {
//            std::cout << "Win Player 2" << std::endl;
            ui->whosMove->setText("WIN Player 2 ");
            ++Player2Wins_;
//            Winner = 1;
            return 1;
        }
    }

    sumO = 0;
    sumX = 0;
    //Check diagonals leftLower ---> rightUpper
    for (size_t i = (Col - 1); i < (lenght -1); i += 2)
    {
        if (Field[i] == 10)
            ++sumO;
        else if (Field[i] == 11)
            ++sumX;
//        std::cout << "i : " << i << "  " << Field[i] << std::endl;
        if (sumO == 3)
        {
//            std::cout << "Win Player 1" << std::endl;
            ui->whosMove->setText("WIN Player 1 ");
            ++Player1Wins_;
//            Winner = 1;
            return 1;
        }
        if (sumX == 3)
        {
//            std::cout << "Win Player 2" << std::endl;
            ui->whosMove->setText("WIN Player 2 ");
            ++Player2Wins_;
//            Winner = 1;
            return 1;
        }
    }
//    if (Winner)
//    {
//        return 1;
//    }
    return 0;
}


void MainWindow::on_ttt_0_0_clicked()
{
    if (ui->whosMove->text() == "Player 1 move")
    {
        tttField[0] = 10;
        ui->ttt_0_0->setText("O");
        ui->ttt_0_0->setEnabled(false);
        if (whoWin(tttField, Player1Wins, Player2Wins))
        {
            GameOver();
            return;
        }
        ui->whosMove->setText("Player 2 move");
    }
    else
    {
        tttField[0] = 11;
        ui->ttt_0_0->setText("X");
        ui->ttt_0_0->setEnabled(false);
        if (whoWin(tttField, Player1Wins, Player2Wins))
        {
            GameOver();
            return;
        }
        ui->whosMove->setText("Player 1 move");;
    }

    ++inputCount;
    if (inputCount == 9)
    {
        GameOver();
        ui->whosMove->setText("DRAW GAME");
    }
}

void MainWindow::on_ttt_1_0_clicked()
{
    if (ui->whosMove->text() == "Player 1 move")
    {
        tttField[1] = 10;
        ui->ttt_1_0->setText("O");
        ui->ttt_1_0->setEnabled(false);
        if (whoWin(tttField, Player1Wins, Player2Wins))
        {
            GameOver();
            return;
        }
        ui->whosMove->setText("Player 2 move");
    }
    else
    {
        tttField[1] = 11;
        ui->ttt_1_0->setText("X");
        ui->ttt_1_0->setEnabled(false);
        if (whoWin(tttField, Player1Wins, Player2Wins))
        {
            GameOver();
            return;
        }
        ui->whosMove->setText("Player 1 move");
    }
    ++inputCount;
    if (inputCount == 9)
    {
        GameOver();
        ui->whosMove->setText("DRAW GAME");
    }
}

void MainWindow::on_ttt_2_0_clicked()
{
    if (ui->whosMove->text() == "Player 1 move")
    {
        tttField[2] = 10;
        ui->ttt_2_0->setText("O");
        ui->ttt_2_0->setEnabled(false);
        if (whoWin(tttField, Player1Wins, Player2Wins))
        {
            GameOver();
            return;
        }
        ui->whosMove->setText("Player 2 move");
    }
    else
    {
        tttField[2] = 11;
        ui->ttt_2_0->setText("X");
        ui->ttt_2_0->setEnabled(false);
        if (whoWin(tttField, Player1Wins, Player2Wins))
        {
            GameOver();
            return;
        }
        ui->whosMove->setText("Player 1 move");
    }
    ++inputCount;
    if (inputCount == 9)
    {
        GameOver();
        ui->whosMove->setText("DRAW GAME");
    }
}

void MainWindow::on_ttt_0_1_clicked()
{
    if (ui->whosMove->text() == "Player 1 move")
    {
        tttField[3] = 10;
        ui->ttt_0_1->setText("O");
        ui->ttt_0_1->setEnabled(false);
        if (whoWin(tttField, Player1Wins, Player2Wins))
        {
            GameOver();
            return;
        }
        ui->whosMove->setText("Player 2 move");
    }
    else
    {
        tttField[3] = 11;
        ui->ttt_0_1->setText("X");
        ui->ttt_0_1->setEnabled(false);
        if (whoWin(tttField, Player1Wins, Player2Wins))
        {
            GameOver();
            return;
        }
        ui->whosMove->setText("Player 1 move");
    }
    ++inputCount;
    if (inputCount == 9)
    {
        GameOver();
        ui->whosMove->setText("DRAW GAME");
    }
}

void MainWindow::on_ttt_1_1_clicked()
{
    if (ui->whosMove->text() == "Player 1 move")
    {
        tttField[4] = 10;
        ui->ttt_1_1->setText("O");
        ui->ttt_1_1->setEnabled(false);
        if (whoWin(tttField, Player1Wins, Player2Wins))
        {
            GameOver();
            return;
        }
        ui->whosMove->setText("Player 2 move");
    }
    else
    {
        tttField[4] = 11;
        ui->ttt_1_1->setText("X");
        ui->ttt_1_1->setEnabled(false);
        if (whoWin(tttField, Player1Wins, Player2Wins))
        {
            GameOver();
            return;
        }
        ui->whosMove->setText("Player 1 move");
    }
    ++inputCount;
    if (inputCount == 9)
    {
        GameOver();
        ui->whosMove->setText("DRAW GAME");
    }
}

void MainWindow::on_ttt_2_1_clicked()
{
    if (ui->whosMove->text() == "Player 1 move")
    {
        tttField[5] = 10;
        ui->ttt_2_1->setText("O");
        ui->ttt_2_1->setEnabled(false);
        if (whoWin(tttField, Player1Wins, Player2Wins))
        {
            GameOver();
            return;
        }
        ui->whosMove->setText("Player 2 move");
    }
    else
    {
        tttField[5] = 11;
        ui->ttt_2_1->setText("X");
        ui->ttt_2_1->setEnabled(false);
        if (whoWin(tttField, Player1Wins, Player2Wins))
        {
            GameOver();
            return;
        }
        ui->whosMove->setText("Player 1 move");
    }
    ++inputCount;
    if (inputCount == 9)
    {
        GameOver();
        ui->whosMove->setText("DRAW GAME");
    }
}

void MainWindow::on_ttt_0_2_clicked()
{
    if (ui->whosMove->text() == "Player 1 move")
    {
        tttField[6] = 10;
        ui->ttt_0_2->setText("O");
        ui->ttt_0_2->setEnabled(false);
        if (whoWin(tttField, Player1Wins, Player2Wins))
        {
            GameOver();
            return;
        }
        ui->whosMove->setText("Player 2 move");
    }
    else
    {
        tttField[6] = 11;
        ui->ttt_0_2->setText("X");
        ui->ttt_0_2->setEnabled(false);
        if (whoWin(tttField, Player1Wins, Player2Wins))
        {
            GameOver();
            return;
        }
        ui->whosMove->setText("Player 1 move");
    }
    ++inputCount;
    if (inputCount == 9)
    {
        GameOver();
        ui->whosMove->setText("DRAW GAME");
    }
}

void MainWindow::on_ttt_1_2_clicked()
{
    if (ui->whosMove->text() == "Player 1 move")
    {
        tttField[7] = 10;
        ui->ttt_1_2->setText("O");
        ui->ttt_1_2->setEnabled(false);
        if (whoWin(tttField, Player1Wins, Player2Wins))
        {
            GameOver();
            return;
        }
        ui->whosMove->setText("Player 2 move");
    }
    else
    {
        tttField[7] = 11;
        ui->ttt_1_2->setText("X");
        ui->ttt_1_2->setEnabled(false);
        if (whoWin(tttField, Player1Wins, Player2Wins))
        {
            GameOver();
            return;
        }
        ui->whosMove->setText("Player 1 move");
    }
    ++inputCount;
    if (inputCount == 9)
    {
        GameOver();
        ui->whosMove->setText("DRAW GAME");
    }
}

void MainWindow::on_ttt_2_2_clicked()
{
    if (ui->whosMove->text() == "Player 1 move")
    {
        tttField[8] = 10;
        ui->ttt_2_2->setText("O");
        ui->ttt_2_2->setEnabled(false);
        if (whoWin(tttField, Player1Wins, Player2Wins))
        {
            GameOver();
            return;
        }
        ui->whosMove->setText("Player 2 move");
    }
    else
    {
        tttField[8] = 11;
        ui->ttt_2_2->setText("X");
        ui->ttt_2_2->setEnabled(false);
        if (whoWin(tttField, Player1Wins, Player2Wins))
        {
            GameOver();
            return;
        }
        ui->whosMove->setText("Player 1 move");
    }
    ++inputCount;
    if (inputCount == 9)
    {
        GameOver();
        ui->whosMove->setText("DRAW GAME");
    }
}

