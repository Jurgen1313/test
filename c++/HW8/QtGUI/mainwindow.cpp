#include<mainwindow.h>


//MainWidget::MainWidget(QWidget *parent): QDialog(parent)
MainWidget::MainWidget()
{
    label = new QLabel("You entered :");

    buttonA = new QPushButton("A");
    buttonB = new QPushButton("B");
    buttonC = new QPushButton("C");
    buttonQuit = new QPushButton("QUIT");
    buttonClear = new QPushButton("Clear");
    buttonClear->setEnabled(false);

    editField = new QLineEdit();
    editField->setEnabled(false);

    QVBoxLayout *lv1 = new QVBoxLayout;

    lv1->addWidget(label);
    lv1->addWidget(editField);
    lv1->addWidget(buttonA);
    lv1->addWidget(buttonB);
    lv1->addWidget(buttonC);

    QHBoxLayout *menu = new QHBoxLayout;
    menu->addWidget(buttonClear);
    menu->addWidget(buttonQuit);

    lv1->addLayout(menu);

    connect(buttonQuit, SIGNAL(clicked()), this, SLOT (close()));
    connect(editField, SIGNAL(textChanged(QString)), this, SLOT(TextChanged(QString)) );
    connect(buttonClear, SIGNAL(clicked()),this, SLOT(pushClear()));

    connect(buttonA, SIGNAL(clicked()), this, SLOT(pushA()));
    connect(buttonB, SIGNAL(clicked()), this, SLOT(pushB()));
    connect(buttonC, SIGNAL(clicked()), this, SLOT(pushC()));
    setLayout(lv1);
    setWindowTitle("Test ABC Buttons");
}

void MainWidget::pushClear()
{
    editField->clear();
}

void MainWidget::TextChanged(QString str)
{
    buttonClear->setEnabled(!str.isEmpty());
}

void MainWidget::pushA()
{
    editField->insert("A");
}

void MainWidget::pushB()
{
    editField->insert("B");
}

void MainWidget::pushC()
{
    editField->insert("C");
}
