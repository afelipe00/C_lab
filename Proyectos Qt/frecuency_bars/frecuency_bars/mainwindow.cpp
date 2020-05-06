#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tonegenerator_dialog.h"
#include "spectrograph.h"
#include <QHBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::createUi(){
    setWindowTitle(tr("prueba papus"));
    ui->spect_graph->setParams(11,1,1000);

}


void MainWindow::on_pushButton_clicked()
{
    Tonegenerator_dialog* tone = new Tonegenerator_dialog();
    tone->show();

}
