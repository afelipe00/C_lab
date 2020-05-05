/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSplitter *splitter;
    QProgressBar *progressBar_2;
    QProgressBar *progressBar;
    QProgressBar *progressBar_3;
    QProgressBar *progressBar_4;
    QProgressBar *progressBar_5;
    QProgressBar *progressBar_6;
    QProgressBar *progressBar_7;
    QProgressBar *progressBar_8;
    QProgressBar *progressBar_9;
    QProgressBar *progressBar_10;
    QProgressBar *progressBar_11;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(802, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(60, 340, 681, 201));
        splitter->setOrientation(Qt::Horizontal);
        progressBar_2 = new QProgressBar(splitter);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setValue(24);
        progressBar_2->setOrientation(Qt::Vertical);
        splitter->addWidget(progressBar_2);
        progressBar = new QProgressBar(splitter);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);
        progressBar->setOrientation(Qt::Vertical);
        splitter->addWidget(progressBar);
        progressBar_3 = new QProgressBar(splitter);
        progressBar_3->setObjectName(QString::fromUtf8("progressBar_3"));
        progressBar_3->setValue(24);
        progressBar_3->setOrientation(Qt::Vertical);
        splitter->addWidget(progressBar_3);
        progressBar_4 = new QProgressBar(splitter);
        progressBar_4->setObjectName(QString::fromUtf8("progressBar_4"));
        progressBar_4->setValue(24);
        progressBar_4->setOrientation(Qt::Vertical);
        splitter->addWidget(progressBar_4);
        progressBar_5 = new QProgressBar(splitter);
        progressBar_5->setObjectName(QString::fromUtf8("progressBar_5"));
        progressBar_5->setValue(24);
        progressBar_5->setOrientation(Qt::Vertical);
        splitter->addWidget(progressBar_5);
        progressBar_6 = new QProgressBar(splitter);
        progressBar_6->setObjectName(QString::fromUtf8("progressBar_6"));
        progressBar_6->setValue(24);
        progressBar_6->setOrientation(Qt::Vertical);
        splitter->addWidget(progressBar_6);
        progressBar_7 = new QProgressBar(splitter);
        progressBar_7->setObjectName(QString::fromUtf8("progressBar_7"));
        progressBar_7->setValue(24);
        progressBar_7->setOrientation(Qt::Vertical);
        splitter->addWidget(progressBar_7);
        progressBar_8 = new QProgressBar(splitter);
        progressBar_8->setObjectName(QString::fromUtf8("progressBar_8"));
        progressBar_8->setValue(24);
        progressBar_8->setOrientation(Qt::Vertical);
        splitter->addWidget(progressBar_8);
        progressBar_9 = new QProgressBar(splitter);
        progressBar_9->setObjectName(QString::fromUtf8("progressBar_9"));
        progressBar_9->setValue(24);
        progressBar_9->setOrientation(Qt::Vertical);
        splitter->addWidget(progressBar_9);
        progressBar_10 = new QProgressBar(splitter);
        progressBar_10->setObjectName(QString::fromUtf8("progressBar_10"));
        progressBar_10->setValue(24);
        progressBar_10->setOrientation(Qt::Vertical);
        splitter->addWidget(progressBar_10);
        progressBar_11 = new QProgressBar(splitter);
        progressBar_11->setObjectName(QString::fromUtf8("progressBar_11"));
        progressBar_11->setValue(24);
        progressBar_11->setOrientation(Qt::Vertical);
        splitter->addWidget(progressBar_11);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 180, 171, 101));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 802, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
