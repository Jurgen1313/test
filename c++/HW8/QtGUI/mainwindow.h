#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>

class MainWidget: public QDialog
{
    Q_OBJECT
public:
    MainWidget();

private:
    QLabel *label;
    QLineEdit *editField;
    QPushButton *buttonA;
    QPushButton *buttonB;
    QPushButton *buttonC;
    QPushButton *buttonQuit;
    QPushButton *buttonClear;

public slots:
    void pushA ();
    void pushB ();
    void pushC ();
    void pushClear ();
    void TextChanged(QString str);

};

#endif // MAINWINDOW_H
