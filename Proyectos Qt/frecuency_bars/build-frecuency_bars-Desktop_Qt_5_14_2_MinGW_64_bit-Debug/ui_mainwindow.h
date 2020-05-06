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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "spectrograph.h"
#include "waveform.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSplitter *splitter;
    Spectrograph *spect_graph;
    QPushButton *pushButton;
    Waveform *wave_widget;
    QSplitter *splitter_2;
    QLabel *label;
    QLabel *label_2;
    QSplitter *splitter_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QSplitter *splitter_4;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
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
        splitter->setGeometry(QRect(10, 290, 781, 221));
        splitter->setOrientation(Qt::Horizontal);
        spect_graph = new Spectrograph(splitter);
        spect_graph->setObjectName(QString::fromUtf8("spect_graph"));
        splitter->addWidget(spect_graph);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 60, 181, 41));
        wave_widget = new Waveform(centralwidget);
        wave_widget->setObjectName(QString::fromUtf8("wave_widget"));
        wave_widget->setGeometry(QRect(310, 10, 481, 261));
        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(20, 30, 281, 21));
        splitter_2->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter_2);
        label->setObjectName(QString::fromUtf8("label"));
        splitter_2->addWidget(label);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        splitter_2->addWidget(label_2);
        splitter_3 = new QSplitter(centralwidget);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setGeometry(QRect(60, 130, 161, 61));
        splitter_3->setOrientation(Qt::Vertical);
        checkBox = new QCheckBox(splitter_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        splitter_3->addWidget(checkBox);
        checkBox_2 = new QCheckBox(splitter_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        splitter_3->addWidget(checkBox_2);
        splitter_4 = new QSplitter(centralwidget);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setGeometry(QRect(20, 520, 751, 16));
        splitter_4->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        splitter_4->addWidget(label_3);
        label_4 = new QLabel(splitter_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        splitter_4->addWidget(label_4);
        label_5 = new QLabel(splitter_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        splitter_4->addWidget(label_5);
        label_6 = new QLabel(splitter_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        splitter_4->addWidget(label_6);
        label_7 = new QLabel(splitter_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        splitter_4->addWidget(label_7);
        label_8 = new QLabel(splitter_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        splitter_4->addWidget(label_8);
        label_9 = new QLabel(splitter_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        splitter_4->addWidget(label_9);
        label_10 = new QLabel(splitter_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        splitter_4->addWidget(label_10);
        label_11 = new QLabel(splitter_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        splitter_4->addWidget(label_11);
        label_12 = new QLabel(splitter_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        splitter_4->addWidget(label_12);
        label_13 = new QLabel(splitter_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        splitter_4->addWidget(label_13);
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
        label->setText(QCoreApplication::translate("MainWindow", "Frecuencia de muestreo:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "100 Hz", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Filtro Pasa-Altas", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Filtro Pasa-Bajas", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "1hz", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "10hz", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "100hz", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "1khz", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "10khz", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "100khz", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "1mhz", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "10mhz", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "100mhz", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "100hz", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "100hz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
