#include <mainwindow.h>


MainWindow::MainWindow()
{
//    Bid = 0;
    bRun = new QPushButton ("GO!!!");
    bRun->setEnabled(false);
    bQuit = new QPushButton ("QUIT");
    bClear = new QPushButton ("NEW GAME");

    labelPix1 = new QLabel;
    labelPix2 = new QLabel;
    labelPix3 = new QLabel;
    labelPix4 = new QLabel;
    labelPix5 = new QLabel;
    labelPix6 = new QLabel;
    lTest = new QLabel ("test layer");

    lYouHave = new QLabel ("You have : ");
    lMakeBid = new QLabel ("Make your bid : ");
    lHowMuchFields = new QLabel ("How much fields? :");
    lDollar = new QLabel (" $ ");

    elYouHave = new QLineEdit ("0");
    elYouHave->setEnabled(false);
    elMakeBid = new QLineEdit ("0");
    elHowMuchFields = new QLineEdit ("3");

    pix1 = {"../GameMachine/2.jpg"};
    pix2 = {"../GameMachine/4.jpg"};
    pix3 = {"../GameMachine/1.gif"};
    pix4 = {"../GameMachine/3.gif"};
    pix5 = {"../GameMachine/5.jpg"};
    pix6 = {"../GameMachine/6.jpg"};

    labels = {labelPix1, labelPix2, labelPix3, labelPix4, labelPix5, labelPix6};

    lenght = (size_t)labels.size();
    Moves = new QString [lenght+1];
    MovesInt = new int [lenght];
    currentLenght = elHowMuchFields->text().toUInt();

    pictures = {pix1, pix2, pix3, pix4, pix5, pix6};

    sMakeBid = new QSlider (Qt::Horizontal);
    sMakeBid->setMinimum(0);
    sMakeBid->setMaximum(elYouHave->text().toUInt());
    sMakeBid->setValue(Bid);

    sHowMuchFields = new QSlider (Qt::Horizontal);
    sHowMuchFields->setMinimum(2);
    sHowMuchFields->setMaximum(lenght);
    sHowMuchFields->setValue(3);

    lh1 = new QHBoxLayout;
    lh2 = new QHBoxLayout;
    lh3 = new QHBoxLayout;
    lh4 = new QHBoxLayout;
    lh5 = new QHBoxLayout;
    lh6 = new QHBoxLayout;
    lh7 = new QHBoxLayout;

    lv1 = new QVBoxLayout;

    lh1->addWidget(lYouHave);
    lh1->addWidget(elYouHave);
    lh1->addWidget(lDollar);

    lh2->addWidget(lMakeBid);
    lh2->addWidget(elMakeBid);
    lh2->addWidget(lDollar);
    lh2->addWidget(sMakeBid);

    lh3->addWidget(lHowMuchFields);
    lh3->addWidget(elHowMuchFields);
    lh3->addWidget(sHowMuchFields);

    for (size_t i = 0; i < lenght; ++i)
    {
        labels[i]->setPixmap(pictures[0]);
        if (currentLenght <= i)
            labels[i]->setEnabled(false);
        lh4->addWidget(labels[i]);
    }

    lh5->addWidget(bRun);

    lh6->addWidget(bClear);
    lh6->addWidget(bQuit);

    lv1->addLayout(lh1);
    lv1->addLayout(lh2);
    lv1->addLayout(lh3);
    lv1->addLayout(lh4);
    lv1->addLayout(lh5);
    lv1->addLayout(lh6);
    lv1->addLayout(lh7);

    connect(bQuit, SIGNAL (clicked()), this, SLOT(close() ));
    connect(bRun,  SIGNAL (clicked()), this, SLOT(randPic()));
    connect(bClear, SIGNAL(clicked()), this, SLOT(clear()));

    connect(elYouHave, SIGNAL (textChanged(QString)), this, SLOT(changedYouHave(QString)));

    connect(elHowMuchFields, SIGNAL (textChanged(QString)), this, SLOT(resize(QString)));
    connect(sHowMuchFields, SIGNAL(valueChanged(int)),this,SLOT(setValueHowMuchField(int)));

    connect(elMakeBid, SIGNAL (textChanged(QString)), this, SLOT(setMakeBid(QString)));
    connect(sMakeBid , SIGNAL(valueChanged(int)),this,SLOT(setMakeBid(int)));

    setLayout(lv1);
    setWindowTitle("Game Machine");
}

void MainWindow::randPic() // move has been done
{
    if (elHowMuchFields->text().toInt() < 2) // || elHowMuchFields->text().toInt() <= lenght)
        elHowMuchFields->setText("2");
    else if (elHowMuchFields->text().toInt() > lenght)
        elHowMuchFields->setText(QString::number(lenght));

    QTime midnight(0, 0, 0);
    qsrand(midnight.secsTo(QTime::currentTime()));

    QString s {""};
    int moves;
    for (size_t i = 0; i < currentLenght; ++i)
    {
        moves = qrand() % lenght;
        labels[i]->setPixmap(pictures[moves]);
        s.append(QString::number(moves));
        Moves->append(QString::number(moves));
        MovesInt[i] = moves;
    }

    emit Play(MovesInt, elHowMuchFields->text().toInt(), elMakeBid->text().toInt());
}

void MainWindow::resize(QString str)
{
    int number = str.toInt();
    if (number > 1 && number <= lenght)
    {
        for (size_t i = 0; i < lenght; ++i)
        {
            if (i < number)
                labels[i]->setEnabled(true);
            else
            {
                labels[i]->setPixmap(pictures[0]);
                labels[i]->setEnabled(false);
            }
        }
        currentLenght = number;
        sHowMuchFields->setValue(currentLenght);
    }
}

void MainWindow::setValueHowMuchField(int value)
{
    for (size_t i = 0; i < lenght; ++i)
    {
        if (i < (size_t)value)
            labels[i]->setEnabled(true);
        else
        {
            labels[i]->setPixmap(pictures[0]);
            labels[i]->setEnabled(false);
        }
    }
    currentLenght = value;
    QString s = QString::number(value);
    elHowMuchFields->setText(s);
}

void MainWindow::setMakeBid(int value)
{
    Bid = value;
    QString s = QString::number(value);
    elMakeBid->setText(s);
    if (value > 0)
        bRun->setEnabled(true);
    else
        bRun->setEnabled(false);
}

void MainWindow::setMakeBid(QString str)
{
    int number = str.toUInt();
    sMakeBid->setValue(number);
    if (number > 0)
        bRun->setEnabled(true);
    else
        bRun->setEnabled(false);
}

void MainWindow::clear()
{
    elYouHave->setText("0");
    elMakeBid->setText("0");
    elHowMuchFields->setText("3");
    for (size_t i = 0; i < lenght; ++i)
    {
        labels[i]->setPixmap(pictures[0]);
        if (currentLenght <= i)
            labels[i]->setEnabled(false);
    }
    emit newGame();
}

void MainWindow::changedYouHave(QString str)
{
    size_t number = (size_t)str.toUInt();
    sMakeBid->setMaximum(number);
}

void MainWindow::Money(const int money)
{
    elYouHave->setText(QString::number(money));
}

void MainWindow::setMoney(const int money)
{
    elYouHave->setText(QString::number(money));
}

//Player
void Player::playGame(const int* const combination, const int lenght, const int makeBid)
{
    QMessageBox Msgbox;
    if (game(combination, lenght))
    {
        yourMoney += makeBid * coef;
        Msgbox.setText("You WIN : \n\t" + QString::number(makeBid * coef));
    }
    else
    {
        yourMoney -= makeBid;
        Msgbox.setText("You LOOSE : " + QString::number(makeBid));
    }
    Msgbox.exec();

    if (!yourMoney)
    {
        QMessageBox Msgbox;
        Msgbox.setText("GAME OVER");
        Msgbox.exec();
    }
    emit changedMoney(yourMoney);
}

void Player::setMoney(const int money)
{
    yourMoney = money;
}

int Player::getCoef() const
{
    return coef;
}

void Player::setCoef(const int coefNew)
{
    coef = coefNew;
}

int Player::getMoney() const
{
    return yourMoney;
}

void Player::newPGame()
{
    yourMoney = 500;
    coef = 0;
    emit changedMoney(yourMoney);
}

//bool Player::game(const int* const, const int)
//{}

bool FirstPlayer::game(const int* const combination, const int lenght)
{
     switch(lenght)
     {
         case 2:
         {
             if (combination[0] == combination[1])
             {
                 setCoef(1);
                 return true;
             }
             else
                 return false;

             break;
         }
         case 3:
         {
             if ((combination[0] == combination[1])&&((combination[1] == combination[2])))
             {
                 setCoef(2);
                 return true;
             }
             if (combination[0] == combination[1])
             {
                 setCoef(1);
                 return true;
             }
             break;
         }
         case 4:
         {
             if ((combination[0] == combination[1])&&((combination[1] == combination[2]))&&((combination[2] == combination[3])))
             {
//                 coef = 3;
                 setCoef(3);
                 return true;
             }
             if ((combination[0] == combination[1])&&((combination[1] == combination[2])))
             {
//                 coef = 2;
                 setCoef(2);
                 return true;
             }
             if (combination[0] == combination[1])
             {
//                 coef = 1;
                 setCoef(1);
                 return true;
             }
             break;
         }

         case 5:
         {
             if ((combination[0] == combination[1])&&((combination[1] == combination[2]))&&((combination[2] == combination[3]))&&((combination[3] == combination[4])))
             {
//                 coef = 4;
                 setCoef(4);
                 return true;
             }
             if ((combination[0] == combination[1])&&((combination[1] == combination[2]))&&((combination[2] == combination[3])))
             {
//                 coef = 3;
                 setCoef(3);
                 return true;
             }
             if ((combination[0] == combination[1])&&((combination[1] == combination[2])))
             {
//                 coef = 2;
                 setCoef(2);
                 return true;
             }
             if (combination[0] == combination[1])
             {
//                 coef = 1;
                 setCoef(1);
                 return true;
             }
             return false;
             break;
         }
     case 6:
     {
         if ((combination[0] == combination[1])&&((combination[1] == combination[2]))&&((combination[2] == combination[3]))&&((combination[3] == combination[4]))&&((combination[4] == combination[5])))
         {
//             coef = 5;
             setCoef(5);
             return true;
         }
         if ((combination[0] == combination[1])&&((combination[1] == combination[2]))&&((combination[2] == combination[3]))&&((combination[3] == combination[4])))
         {
//             coef = 4;
             setCoef(4);
             return true;
         }
         if ((combination[0] == combination[1])&&((combination[1] == combination[2]))&&((combination[2] == combination[3])))
         {
//             coef = 3;
             setCoef(3);
             return true;
         }
         if ((combination[0] == combination[1])&&((combination[1] == combination[2])))
         {
//             coef = 2;
             setCoef(2);
             return true;
         }
         if (combination[0] == combination[1])
         {
//             coef = 1;
             setCoef(1);
             return true;
         }
         return false;
         break;
     }
     }
     return false;
}

