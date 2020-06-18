#include "on_building.h"
#include "ui_on_building.h"
#include <QDebug>

#include"on_ascensor.h"

on_building::on_building(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::on_building)
{
    ui->setupUi(this);
    CreateUi();
}

on_building::~on_building()
{
    delete ui;
}

void on_building::CreateUi(){
    setWindowTitle("asdfasdf");
    data_buttons.clear();
    if (ui->ups2->isChecked()){
        data_buttons.append('t');
    }else{
        data_buttons.append('f');
    }
    if(ui->ups1->isChecked()){
        data_buttons.append('t');
    }else{
        data_buttons.append('f');
    }
    if(ui->downs1->isChecked()){
        data_buttons.append('t');
    }else{
        data_buttons.append('f');
    }
    if(ui->up1->isChecked()){
        data_buttons.append('t');
    }else{
        data_buttons.append('f');
    }
    if(ui->down1->isChecked()){
        data_buttons.append('t');
    }else{
        data_buttons.append('f');
    }
    if(ui->up2->isChecked()){
        data_buttons.append('t');
    }else{
        data_buttons.append('f');
    }
    if(ui->down2->isChecked()){
        data_buttons.append('t');
    }else{
        data_buttons.append('f');
    }
    if(ui->up3->isChecked()){
        data_buttons.append('t');
    }else{
        data_buttons.append('f');
    }
    if(ui->down3->isChecked()){
        data_buttons.append('t');
    }else{
        data_buttons.append('f');
    }
    if(ui->up4->isChecked()){
        data_buttons.append('t');
    }else{
        data_buttons.append('f');
    }
    if(ui->down4->isChecked()){
        data_buttons.append('t');
    }else{
        data_buttons.append('f');
    }
    if(ui->up5->isChecked()){
        data_buttons.append('t');
    }else{
        data_buttons.append('f');
    }
    if(ui->down5->isChecked()){
        data_buttons.append('t');
    }else{
        data_buttons.append('f');
    }
    if(ui->up6->isChecked()){
        data_buttons.append('t');
    }else{
        data_buttons.append('f');
    }
    if(ui->down6->isChecked()){
        data_buttons.append('t');
    }else{
        data_buttons.append('f');
    }
    if(ui->up7->isChecked()){
        data_buttons.append('t');
    }else{
        data_buttons.append('f');
    }
    if(ui->down7->isChecked()){
        data_buttons.append('t');
    }else{
        data_buttons.append('f');
    }
    if(ui->down8->isChecked()){
        data_buttons.append('t');
    }else{
        data_buttons.append('f');
    }
    qDebug()<< data_buttons;
    ui->historial_text->setPlainText(data_buttons);
}

void on_building::on_ascensor_1_button_clicked()
{
    ascensor_1->show();
}

void on_building::on_ascensor_2_button_clicked()
{
    ascensor_2->show();
}


void on_building::on_downs1_clicked()
{
    CreateUi();
}

void on_building::on_ups2_clicked()
{
    CreateUi();
}


void on_building::on_ups1_clicked()
{
    CreateUi();
}

void on_building::on_up1_clicked()
{
    CreateUi();
}

void on_building::on_down1_clicked()
{
    CreateUi();
}

void on_building::on_up2_clicked()
{
    CreateUi();
}

void on_building::on_down2_clicked()
{
    CreateUi();
}

void on_building::on_up3_clicked()
{
    CreateUi();
}

void on_building::on_down3_clicked()
{
    CreateUi();
}

void on_building::on_up4_clicked()
{
    CreateUi();
}

void on_building::on_down4_clicked()
{
    CreateUi();
}

void on_building::on_up5_clicked()
{
    CreateUi();
}
void on_building::on_down5_clicked()
{
    CreateUi();
}

void on_building::on_up6_clicked()
{
    CreateUi();
}

void on_building::on_down6_clicked()
{
    CreateUi();
}

void on_building::on_up7_clicked()
{
    CreateUi();
}

void on_building::on_down7_clicked()
{
    CreateUi();
}

void on_building::on_down8_clicked()
{
    CreateUi();
}
