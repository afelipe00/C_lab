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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New;
    QAction *action_Open;
    QAction *action_Open_file;
    QAction *action_Save;
    QWidget *centralwidget;
    QComboBox *port_box;
    QPushButton *port_button;
    QPlainTextEdit *plainTextEdit;
    QLabel *picture_label;
    QProgressBar *progressBar;
    QPushButton *send_button;
    QPushButton *receive_button;
    QLabel *sound_label;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMouseTracking(true);
        MainWindow->setTabletTracking(true);
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QString::fromUtf8("action_New"));
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QString::fromUtf8("action_Open"));
        action_Open_file = new QAction(MainWindow);
        action_Open_file->setObjectName(QString::fromUtf8("action_Open_file"));
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QString::fromUtf8("action_Save"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        port_box = new QComboBox(centralwidget);
        port_box->setObjectName(QString::fromUtf8("port_box"));
        port_box->setGeometry(QRect(20, 10, 211, 31));
        port_button = new QPushButton(centralwidget);
        port_button->setObjectName(QString::fromUtf8("port_button"));
        port_button->setGeometry(QRect(250, 10, 101, 31));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(20, 90, 331, 271));
        picture_label = new QLabel(centralwidget);
        picture_label->setObjectName(QString::fromUtf8("picture_label"));
        picture_label->setGeometry(QRect(20, 370, 331, 171));
        picture_label->setTextFormat(Qt::RichText);
        picture_label->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(370, 100, 411, 121));
        progressBar->setTabletTracking(false);
        progressBar->setValue(0);
        progressBar->setInvertedAppearance(false);
        send_button = new QPushButton(centralwidget);
        send_button->setObjectName(QString::fromUtf8("send_button"));
        send_button->setGeometry(QRect(370, 50, 181, 31));
        receive_button = new QPushButton(centralwidget);
        receive_button->setObjectName(QString::fromUtf8("receive_button"));
        receive_button->setGeometry(QRect(600, 50, 181, 31));
        sound_label = new QLabel(centralwidget);
        sound_label->setObjectName(QString::fromUtf8("sound_label"));
        sound_label->setGeometry(QRect(20, 50, 331, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(action_New);
        menu_File->addAction(action_Open_file);
        menu_File->addAction(action_Save);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_New->setText(QCoreApplication::translate("MainWindow", "&New", nullptr));
        action_Open->setText(QCoreApplication::translate("MainWindow", "$Open", nullptr));
        action_Open_file->setText(QCoreApplication::translate("MainWindow", "&Open file", nullptr));
        action_Save->setText(QCoreApplication::translate("MainWindow", " &Save", nullptr));
        port_button->setText(QCoreApplication::translate("MainWindow", "Open port", nullptr));
        picture_label->setText(QCoreApplication::translate("MainWindow", "No Image", nullptr));
        send_button->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        receive_button->setText(QCoreApplication::translate("MainWindow", "Receive", nullptr));
        sound_label->setText(QCoreApplication::translate("MainWindow", "Sound no found", nullptr));
        menu_File->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
