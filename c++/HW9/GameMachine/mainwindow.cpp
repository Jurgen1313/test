#include <mainwindow.h>


MainWindow::MainWindow()
{
    Bid = 0;

    bRun = new QPushButton ("GO!!!");
//    bRun->setEnabled(false);
    bQuit = new QPushButton ("QUIT");
    bClear = new QPushButton ("CLEAR");

    labelPix1 = new QLabel;
    labelPix2 = new QLabel;
    labelPix3 = new QLabel;
    labelPix4 = new QLabel;
    labelPix5 = new QLabel;
    labelPix6 = new QLabel;

    lYouHave = new QLabel ("You have : ");
    lMakeBid = new QLabel ("Make your bid : ");
    lHowMuchFields = new QLabel ("How much fields? :");
    lDollar = new QLabel (" $ ");

    elYouHave = new QLineEdit ("500");
    elMakeBid = new QLineEdit ("0");
    elHowMuchFields = new QLineEdit ("3");

    pix1 = {"../GameMachine/2.jpg"};
    pix2 = {"../GameMachine/4.jpg"};
    pix3 = {"../GameMachine/1.gif"};
    pix4 = {"../GameMachine/3.gif"};
    pix5 = {"../GameMachine/5.jpg"};
    pix6 = {"../GameMachine/6.jpg"};

    labels = {labelPix1, labelPix2, labelPix3, labelPix4, labelPix5, labelPix6};
//    lenght = labels.size();
    lenght = elHowMuchFields->text().toUInt();
//    lenght = 3;
    pictures = {pix1, pix2, pix3, pix4, pix5, pix6};

    sMakeBid = new QSlider (Qt::Horizontal);
    sMakeBid->setMinimum(0);
    sMakeBid->setMaximum(elYouHave->text().toUInt());
    sMakeBid->setValue(Bid);

    sHowMuchFields = new QSlider (Qt::Horizontal);
    sHowMuchFields->setMinimum(1);
    sHowMuchFields->setMaximum(labels.size());
    sHowMuchFields->setValue(3);

    lh1 = new QHBoxLayout;
    lh2 = new QHBoxLayout;
    lh3 = new QHBoxLayout;
    lh4 = new QHBoxLayout;
    lh5 = new QHBoxLayout;
    lh6 = new QHBoxLayout;

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

    for (size_t i = 0; i < labels.size(); ++i)
    {
        labels[i]->setPixmap(pictures[0]);
        if (lenght <= i)
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


    connect(bQuit, SIGNAL (clicked()), this, SLOT(close() ));
    connect(bRun,  SIGNAL (clicked()), this, SLOT(randPic()));

    connect(elHowMuchFields, SIGNAL (textChanged(QString)), this, SLOT(resize(QString)));
    connect(sHowMuchFields, SIGNAL(valueChanged(int)),this,SLOT(setValueHowMuchField(int)));

    connect(elMakeBid, SIGNAL (textChanged(QString)), this, SLOT(setMakeBid(QString)));
    connect(sMakeBid , SIGNAL(valueChanged(int)),this,SLOT(setMakeBid(int)));

    setLayout(lv1);
    setWindowTitle("Game Machine");
}

void MainWindow::randPic()
{
    qsrand(qrand());
    for (size_t i = 0; i < lenght; ++i)
        labels[i]->setPixmap(pictures[qrand() % lenght]);
}

void MainWindow::resize(QString str)
{
    int number = str.toUInt();
    if (number > 0 && number <= labels.size())
    {
        for (size_t i = 0; i < labels.size(); ++i)
        {
            if (i < number)
                labels[i]->setEnabled(true);
            else
            {
                labels[i]->setPixmap(pictures[0]);
                labels[i]->setEnabled(false);
            }
        }
        lenght = number;
        sHowMuchFields->setValue(number);
    }
}

void MainWindow::setValueHowMuchField(int value)
{
    for (size_t i = 0; i < labels.size(); ++i)
    {
        if (i < value)
            labels[i]->setEnabled(true);
        else
        {
            labels[i]->setPixmap(pictures[0]);
            labels[i]->setEnabled(false);
        }
    }
    lenght = value;
    QString s = QString::number(value);
    elHowMuchFields->setText(s);
}

void MainWindow::setMakeBid(int value)
{
    Bid = value;
    QString s = QString::number(value);
    elMakeBid->setText(s);

}

void MainWindow::setMakeBid(QString str)
{
    int number = str.toUInt();
//    if (number > 0 && number <= (elYouHave->text().toUInt()))
//    {
        sMakeBid->setValue(number);
//        sHowMuchFields->setValue(number);
//    }

}
