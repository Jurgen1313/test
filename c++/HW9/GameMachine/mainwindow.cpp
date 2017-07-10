#include <mainwindow.h>


MainWindow::MainWindow()
{
    bRun = new QPushButton ("GO!!!");
    bQuit = new QPushButton ("QUIT");

    labelPix1 = new QLabel;
    labelPix2 = new QLabel;
    labelPix3 = new QLabel;
    labelPix4 = new QLabel;
    labelPix5 = new QLabel;
    labelPix6 = new QLabel;

    pix1 = {"../GameMachine/2.jpg"};
    pix2 = {"../GameMachine/4.jpg"};
    pix3 = {"../GameMachine/1.gif"};
    pix4 = {"../GameMachine/3.gif"};
    pix5 = {"../GameMachine/5.jpg"};
    pix6 = {"../GameMachine/6.jpg"};

    labels = {labelPix1, labelPix2, labelPix3, labelPix4, labelPix5, labelPix6};
//    lenght = labels.size();
    lenght = 3;
    pictures = {pix1, pix2, pix3, pix4, pix5, pix6};

    l1 = new QHBoxLayout;
    l2 = new QHBoxLayout;
    v1 = new QVBoxLayout;

    l2->addWidget(bRun);
    l2->addWidget(bQuit);

    for (size_t i = 0; i < lenght; ++i)
    {
        labels[i]->setPixmap(pictures[0]);
        l1->addWidget(labels[i]);
    }

    v1->addLayout(l1);
    v1->addLayout(l2);

    connect(bQuit, SIGNAL (clicked()), this, SLOT(close() ));
    connect(bRun,  SIGNAL (clicked()), this, SLOT(randPic()));

    setLayout(v1);
    setWindowTitle("Game Machine");
}

void MainWindow::randPic()
{
    qsrand(qrand());

    for (size_t i = 0; i < lenght; ++i)
        labels[i]->setPixmap(pictures[qrand() % lenght]);
}
