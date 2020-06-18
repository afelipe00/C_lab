#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "on_ascensor.h"
#include "serial_com_form.h"
#include<QDebug>

enum{
    s2up =0,
    s1up,
    s1down,
    p1up,
    p1down,
    p2up,
    p2down,
    p3up,
    p3down,
    p4up,
    p4down,
    p5up,
    p5down,
    p6up,
    p6down,
    p7up,
    p7down,
    p8down,
    a1s2up,
    a1s2down,
    a1s1up,
    a1s1down,
    a1p1up,
    a1p1down,
    a1p2up,
    a1p2down,
    a1p3up,
    a1p3down,
    a1p4up,
    a1p4down,
    a1p5up,
    a1p5down,
    a1p6up,
    a1p6down,
    a1p7up,
    a1p7down,
    a1p8down,
    buttons
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CreateUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateUi(){
    setWindowTitle(tr("Ascensor App"));
    serial = new Serial_com_form();
}

void MainWindow::on_open_button_clicked()
{
   serial->show();
}

void MainWindow::on_ascensor_1_button_clicked()
{
    ascensor_1->show();
}


void MainWindow::on_ascensor_2_button_clicked()
{
    ascensor_2->show();
}
void MainWindow::data_const(){
    int data_vect[buttons];
    if (ui->ups2->isChecked()){
       data_vect[s2up]=1;
    }else {
        data_vect[s2up]=0;
    }
    if (ui->ups1->isChecked()){
       data_vect[s1up]=1;
    }else {
        data_vect[s1up]=0;
    }
    if (ui->downs1->isChecked()){
       data_vect[s1down]=1;
    }else {
        data_vect[s1down]=0;
    }
    if (ui->up1->isChecked()){
       data_vect[p1up]=1;
    }else {
        data_vect[p1up]=0;
    }
    if (ui->down1->isChecked()){
       data_vect[p1down]=1;
    }else {
        data_vect[p1down]=0;
    }
    if (ui->up2->isChecked()){
       data_vect[p2up]=1;
    }else {
        data_vect[p2up]=0;
    }
    if (ui->down2->isChecked()){
       data_vect[p2down]=1;
    }else {
        data_vect[p2down]=0;
    }
    if (ui->up3->isChecked()){
       data_vect[p3up]=1;
    }else {
        data_vect[p3up]=0;
    }
    if (ui->down3->isChecked()){
       data_vect[p3down]=1;
    }else {
        data_vect[p3down]=0;
    }
    if (ui->up4->isChecked()){
       data_vect[p4up]=1;
    }else {
        data_vect[p4up]=0;
    }
    if (ui->down4->isChecked()){
       data_vect[p4down]=1;
    }else {
        data_vect[p4down]=0;
    }
    if (ui->up5->isChecked()){
       data_vect[p5up]=1;
    }else {
        data_vect[p5up]=0;
    }
    if (ui->down5->isChecked()){
       data_vect[p5down]=1;
    }else {
        data_vect[p5down]=0;
    }
    if (ui->up6->isChecked()){
       data_vect[p6up]=1;
    }else {
        data_vect[p6up]=0;
    }
    if (ui->down6->isChecked()){
       data_vect[p6down]=1;
    }else {
        data_vect[p6down]=0;
    }
    if (ui->up7->isChecked()){
       data_vect[p7up]=1;
    }else {
        data_vect[p7up]=0;
    }
    if (ui->down7->isChecked()){
       data_vect[p7down]=1;
    }else {
        data_vect[p7down]=0;
    }
    if (ui->down8->isChecked()){
       data_vect[p8down]=1;
    }else {
        data_vect[p8down]=0;
    }
}


