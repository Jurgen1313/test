/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *ttt_0_0;
    QPushButton *ttt_1_0;
    QPushButton *ttt_2_0;
    QPushButton *ttt_1_1;
    QPushButton *ttt_2_1;
    QPushButton *ttt_0_1;
    QPushButton *ttt_1_2;
    QPushButton *ttt_2_2;
    QPushButton *ttt_0_2;
    QGroupBox *groupBox;
    QRadioButton *radioButton_P1_H;
    QRadioButton *radioButton_P1_Bot;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_P2_H;
    QRadioButton *radioButton_P2_Bot;
    QPushButton *pushStartButton;
    QLabel *label1;
    QLabel *label2;
    QLabel *whosMove;
    QLabel *label_0_0;
    QLabel *label_0_1;
    QLabel *label_0_2;
    QLabel *label_1_0;
    QLabel *label_1_2;
    QLabel *label_1_1;
    QLabel *label_2_0;
    QLabel *label_2_2;
    QLabel *label_2_1;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(739, 504);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ttt_0_0 = new QPushButton(centralWidget);
        ttt_0_0->setObjectName(QStringLiteral("ttt_0_0"));
        ttt_0_0->setGeometry(QRect(370, 90, 100, 100));
        QFont font;
        font.setPointSize(60);
        ttt_0_0->setFont(font);
        ttt_1_0 = new QPushButton(centralWidget);
        ttt_1_0->setObjectName(QStringLiteral("ttt_1_0"));
        ttt_1_0->setGeometry(QRect(490, 90, 100, 100));
        ttt_1_0->setFont(font);
        ttt_2_0 = new QPushButton(centralWidget);
        ttt_2_0->setObjectName(QStringLiteral("ttt_2_0"));
        ttt_2_0->setGeometry(QRect(610, 90, 100, 100));
        ttt_2_0->setFont(font);
        ttt_1_1 = new QPushButton(centralWidget);
        ttt_1_1->setObjectName(QStringLiteral("ttt_1_1"));
        ttt_1_1->setGeometry(QRect(490, 210, 100, 100));
        ttt_1_1->setFont(font);
        ttt_2_1 = new QPushButton(centralWidget);
        ttt_2_1->setObjectName(QStringLiteral("ttt_2_1"));
        ttt_2_1->setGeometry(QRect(610, 210, 100, 100));
        ttt_2_1->setFont(font);
        ttt_0_1 = new QPushButton(centralWidget);
        ttt_0_1->setObjectName(QStringLiteral("ttt_0_1"));
        ttt_0_1->setGeometry(QRect(370, 210, 100, 100));
        ttt_0_1->setFont(font);
        ttt_1_2 = new QPushButton(centralWidget);
        ttt_1_2->setObjectName(QStringLiteral("ttt_1_2"));
        ttt_1_2->setGeometry(QRect(490, 330, 100, 100));
        ttt_1_2->setFont(font);
        ttt_2_2 = new QPushButton(centralWidget);
        ttt_2_2->setObjectName(QStringLiteral("ttt_2_2"));
        ttt_2_2->setGeometry(QRect(610, 330, 100, 100));
        ttt_2_2->setFont(font);
        ttt_0_2 = new QPushButton(centralWidget);
        ttt_0_2->setObjectName(QStringLiteral("ttt_0_2"));
        ttt_0_2->setGeometry(QRect(370, 330, 100, 100));
        ttt_0_2->setFont(font);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 40, 121, 111));
        QFont font1;
        font1.setPointSize(18);
        groupBox->setFont(font1);
        radioButton_P1_H = new QRadioButton(groupBox);
        radioButton_P1_H->setObjectName(QStringLiteral("radioButton_P1_H"));
        radioButton_P1_H->setGeometry(QRect(10, 50, 101, 17));
        radioButton_P1_H->setChecked(true);
        radioButton_P1_Bot = new QRadioButton(groupBox);
        radioButton_P1_Bot->setObjectName(QStringLiteral("radioButton_P1_Bot"));
        radioButton_P1_Bot->setGeometry(QRect(10, 80, 82, 21));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(150, 40, 121, 111));
        groupBox_2->setFont(font1);
        radioButton_P2_H = new QRadioButton(groupBox_2);
        radioButton_P2_H->setObjectName(QStringLiteral("radioButton_P2_H"));
        radioButton_P2_H->setGeometry(QRect(10, 50, 101, 17));
        radioButton_P2_H->setChecked(true);
        radioButton_P2_Bot = new QRadioButton(groupBox_2);
        radioButton_P2_Bot->setObjectName(QStringLiteral("radioButton_P2_Bot"));
        radioButton_P2_Bot->setGeometry(QRect(10, 80, 82, 21));
        pushStartButton = new QPushButton(centralWidget);
        pushStartButton->setObjectName(QStringLiteral("pushStartButton"));
        pushStartButton->setGeometry(QRect(90, 160, 121, 41));
        QFont font2;
        font2.setPointSize(20);
        pushStartButton->setFont(font2);
        label1 = new QLabel(centralWidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(30, 220, 71, 16));
        label2 = new QLabel(centralWidget);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(190, 220, 71, 16));
        whosMove = new QLabel(centralWidget);
        whosMove->setObjectName(QStringLiteral("whosMove"));
        whosMove->setGeometry(QRect(370, 30, 331, 41));
        whosMove->setFont(font2);
        whosMove->setAlignment(Qt::AlignCenter);
        label_0_0 = new QLabel(centralWidget);
        label_0_0->setObjectName(QStringLiteral("label_0_0"));
        label_0_0->setGeometry(QRect(60, 300, 31, 31));
        label_0_1 = new QLabel(centralWidget);
        label_0_1->setObjectName(QStringLiteral("label_0_1"));
        label_0_1->setGeometry(QRect(60, 330, 31, 31));
        label_0_2 = new QLabel(centralWidget);
        label_0_2->setObjectName(QStringLiteral("label_0_2"));
        label_0_2->setGeometry(QRect(60, 360, 31, 31));
        label_1_0 = new QLabel(centralWidget);
        label_1_0->setObjectName(QStringLiteral("label_1_0"));
        label_1_0->setGeometry(QRect(110, 300, 31, 31));
        label_1_2 = new QLabel(centralWidget);
        label_1_2->setObjectName(QStringLiteral("label_1_2"));
        label_1_2->setGeometry(QRect(110, 360, 31, 31));
        label_1_1 = new QLabel(centralWidget);
        label_1_1->setObjectName(QStringLiteral("label_1_1"));
        label_1_1->setGeometry(QRect(110, 330, 31, 31));
        label_2_0 = new QLabel(centralWidget);
        label_2_0->setObjectName(QStringLiteral("label_2_0"));
        label_2_0->setGeometry(QRect(160, 300, 31, 31));
        label_2_2 = new QLabel(centralWidget);
        label_2_2->setObjectName(QStringLiteral("label_2_2"));
        label_2_2->setGeometry(QRect(160, 360, 31, 31));
        label_2_1 = new QLabel(centralWidget);
        label_2_1->setObjectName(QStringLiteral("label_2_1"));
        label_2_1->setGeometry(QRect(160, 330, 31, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 739, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Tic Tac Toe", Q_NULLPTR));
        ttt_0_0->setText(QString());
        ttt_1_0->setText(QString());
        ttt_2_0->setText(QString());
        ttt_1_1->setText(QString());
        ttt_2_1->setText(QString());
        ttt_0_1->setText(QString());
        ttt_1_2->setText(QString());
        ttt_2_2->setText(QString());
        ttt_0_2->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Player 1", Q_NULLPTR));
        radioButton_P1_H->setText(QApplication::translate("MainWindow", "Human", Q_NULLPTR));
        radioButton_P1_Bot->setText(QApplication::translate("MainWindow", "Bot", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Player 2", Q_NULLPTR));
        radioButton_P2_H->setText(QApplication::translate("MainWindow", "Human", Q_NULLPTR));
        radioButton_P2_Bot->setText(QApplication::translate("MainWindow", "Bot", Q_NULLPTR));
        pushStartButton->setText(QApplication::translate("MainWindow", "START", Q_NULLPTR));
        label1->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label2->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        whosMove->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_0_0->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_0_1->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_0_2->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_1_0->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_1_2->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_1_1->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_2_0->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_2_2->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_2_1->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
