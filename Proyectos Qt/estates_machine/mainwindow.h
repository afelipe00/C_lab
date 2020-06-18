#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "on_ascensor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Serial_com_form;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_open_button_clicked();

    void on_ascensor_2_button_clicked();

    void on_ascensor_1_button_clicked();

private:
    void CreateUi();
    Ui::MainWindow *ui;
    void data_const();

    //atributos
    Serial_com_form* serial;
    On_ascensor* ascensor_1 = new On_ascensor();
    On_ascensor* ascensor_2 = new On_ascensor();
    QByteArray data_buttons = 0;

};
#endif // MAINWINDOW_H
