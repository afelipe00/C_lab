/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QPlainTextEdit *plainTextEdit;
    QComboBox *comboBox;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 441);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 101, 51));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 20, 81, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 90, 113, 20));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 47, 13));
        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 140, 113, 20));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 120, 47, 13));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 170, 111, 23));
        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(150, 90, 181, 101));
        plainTextEdit->setReadOnly(true);
        comboBox = new QComboBox(Widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 210, 131, 22));
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(150, 210, 75, 23));
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(150, 240, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Comunicacion USB QT", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Abrir", nullptr));
        label->setText(QCoreApplication::translate("Widget", "--------", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Numero 1", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Numero 2", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "Sumar", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "Open Port", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "Enviar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
