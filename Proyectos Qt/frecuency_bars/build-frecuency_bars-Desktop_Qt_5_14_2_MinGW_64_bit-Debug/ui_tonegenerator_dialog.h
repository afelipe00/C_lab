/********************************************************************************
** Form generated from reading UI file 'tonegenerator_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TONEGENERATOR_DIALOG_H
#define UI_TONEGENERATOR_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_Tonegenerator_dialog
{
public:
    QDialogButtonBox *buttonBox;
    QCheckBox *sweep_checkBox;
    QSplitter *splitter;
    QLabel *label;
    QSpinBox *frecuency_spin;
    QSplitter *splitter_2;
    QLabel *label_2;
    QSpinBox *amplitud_spin;
    QSplitter *splitter_3;
    QLabel *label_3;
    QSlider *frecuency_slider;
    QSplitter *splitter_4;
    QLabel *label_4;
    QSlider *amplitud_slider;

    void setupUi(QDialog *Tonegenerator_dialog)
    {
        if (Tonegenerator_dialog->objectName().isEmpty())
            Tonegenerator_dialog->setObjectName(QString::fromUtf8("Tonegenerator_dialog"));
        Tonegenerator_dialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(Tonegenerator_dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(300, 30, 81, 61));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        sweep_checkBox = new QCheckBox(Tonegenerator_dialog);
        sweep_checkBox->setObjectName(QString::fromUtf8("sweep_checkBox"));
        sweep_checkBox->setGeometry(QRect(30, 40, 141, 22));
        splitter = new QSplitter(Tonegenerator_dialog);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(30, 100, 141, 51));
        splitter->setOrientation(Qt::Vertical);
        label = new QLabel(splitter);
        label->setObjectName(QString::fromUtf8("label"));
        splitter->addWidget(label);
        frecuency_spin = new QSpinBox(splitter);
        frecuency_spin->setObjectName(QString::fromUtf8("frecuency_spin"));
        splitter->addWidget(frecuency_spin);
        splitter_2 = new QSplitter(Tonegenerator_dialog);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(30, 180, 141, 71));
        splitter_2->setOrientation(Qt::Vertical);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        splitter_2->addWidget(label_2);
        amplitud_spin = new QSpinBox(splitter_2);
        amplitud_spin->setObjectName(QString::fromUtf8("amplitud_spin"));
        splitter_2->addWidget(amplitud_spin);
        splitter_3 = new QSplitter(Tonegenerator_dialog);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setGeometry(QRect(220, 120, 61, 141));
        splitter_3->setOrientation(Qt::Vertical);
        label_3 = new QLabel(splitter_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        splitter_3->addWidget(label_3);
        frecuency_slider = new QSlider(splitter_3);
        frecuency_slider->setObjectName(QString::fromUtf8("frecuency_slider"));
        frecuency_slider->setOrientation(Qt::Vertical);
        splitter_3->addWidget(frecuency_slider);
        splitter_4 = new QSplitter(Tonegenerator_dialog);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setGeometry(QRect(310, 120, 61, 141));
        splitter_4->setOrientation(Qt::Vertical);
        label_4 = new QLabel(splitter_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        splitter_4->addWidget(label_4);
        amplitud_slider = new QSlider(splitter_4);
        amplitud_slider->setObjectName(QString::fromUtf8("amplitud_slider"));
        amplitud_slider->setOrientation(Qt::Vertical);
        splitter_4->addWidget(amplitud_slider);

        retranslateUi(Tonegenerator_dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Tonegenerator_dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Tonegenerator_dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Tonegenerator_dialog);
    } // setupUi

    void retranslateUi(QDialog *Tonegenerator_dialog)
    {
        Tonegenerator_dialog->setWindowTitle(QCoreApplication::translate("Tonegenerator_dialog", "Dialog", nullptr));
        sweep_checkBox->setText(QCoreApplication::translate("Tonegenerator_dialog", "Frecuency sweep", nullptr));
        label->setText(QCoreApplication::translate("Tonegenerator_dialog", "Frecuency", nullptr));
        label_2->setText(QCoreApplication::translate("Tonegenerator_dialog", "Amplitud", nullptr));
        label_3->setText(QCoreApplication::translate("Tonegenerator_dialog", "Frecuency", nullptr));
        label_4->setText(QCoreApplication::translate("Tonegenerator_dialog", "Amplitud", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tonegenerator_dialog: public Ui_Tonegenerator_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TONEGENERATOR_DIALOG_H
