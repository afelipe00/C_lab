#include "on_ascensor.h"
#include "ui_on_ascensor.h"

On_ascensor::On_ascensor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::On_ascensor)
{
    ui->setupUi(this);
    setupUi();
}

On_ascensor::~On_ascensor()
{
    delete ui;
}

void On_ascensor::setupUi(){
    setWindowTitle(tr("Ascensor"));
}
