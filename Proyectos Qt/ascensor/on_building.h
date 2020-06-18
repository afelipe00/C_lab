#ifndef ON_BUILDING_H
#define ON_BUILDING_H

#include <QWidget>
#include <QMainWindow>

#include "on_ascensor.h"

namespace Ui {
class on_building;
}

class on_building : public QMainWindow
{
    Q_OBJECT

public:
    explicit on_building(QMainWindow *parent = nullptr);
    ~on_building();
     QByteArray data_buttons;

private slots:
    void on_ascensor_1_button_clicked();

    void on_ascensor_2_button_clicked();

    void on_downs1_clicked();

    void on_ups2_clicked();

    void on_ups1_clicked();

    void on_up1_clicked();

    void on_down1_clicked();

    void on_up2_clicked();

    void on_down2_clicked();

    void on_up3_clicked();

    void on_down3_clicked();

    void on_up4_clicked();

    void on_down4_clicked();

    void on_up5_clicked();

    void on_down5_clicked();

    void on_up6_clicked();

    void on_down6_clicked();

    void on_up7_clicked();

    void on_down7_clicked();

    void on_down8_clicked();

private:
    void CreateUi();
    Ui::on_building *ui;
    void data_const();


    on_ascensor* ascensor_1 = new on_ascensor();
    on_ascensor* ascensor_2 = new on_ascensor();
};

#endif // ON_BUILDING_H
