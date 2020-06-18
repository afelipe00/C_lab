#include "on_ascensor.h"
#include "ui_on_ascensor.h"

on_ascensor::on_ascensor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::on_ascensor)
{
    ui->setupUi(this);
}

on_ascensor::~on_ascensor()
{
    delete ui;
}

void on_ascensor::on_seven_button_clicked()
{

}
