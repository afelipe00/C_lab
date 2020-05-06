#include "tonegenerator_dialog.h"
#include "ui_tonegenerator_dialog.h"

const int ToneGeneratorFreqMin = 1;
const int ToneGeneratorFreqMax = 1000;
const int ToneGeneratorFreqDefault = 440;
const int ToneGeneratorAmplitudeDefault = 75;

Tonegenerator_dialog::Tonegenerator_dialog(QWidget *parent) :
    QDialog(parent)
  ,ui(new Ui::Tonegenerator_dialog)
  ,m_frecuencySweepEnabled(true)
  ,m_frecuency(ToneGeneratorFreqDefault)

{
    ui->setupUi(this);
    settingsUi();
}

Tonegenerator_dialog::~Tonegenerator_dialog()
{
    delete ui;
}

bool Tonegenerator_dialog::FrecuencySweepEnabled() const{
    return  ui->sweep_checkBox->isChecked();
}

qreal Tonegenerator_dialog::frecuency() const{
    return  qreal(ui->frecuency_slider->value());
}

qreal Tonegenerator_dialog::amplitud() const{
    return qreal(ui->amplitud_slider->value()) / 100.0;
}

void Tonegenerator_dialog::frecuencySweepEnabled(bool enabled){
    m_frecuencySweepEnabled = enabled;
    ui->frecuency_slider->setEnabled(!enabled);
    ui->frecuency_spin->setEnabled(!enabled);
}

void Tonegenerator_dialog::settingsUi(){
    setWindowTitle(tr("Generador de Tonos"));
    ui->sweep_checkBox->setChecked(true);
    ui->frecuency_slider->setEnabled(false);
    ui->frecuency_spin->setEnabled(false);
    ui->amplitud_spin->setRange(ToneGeneratorFreqMin,ToneGeneratorFreqMax);
    ui->amplitud_spin->setValue(ToneGeneratorFreqDefault);
    ui->frecuency_spin->setRange(ToneGeneratorFreqMin,ToneGeneratorFreqMax);
    ui->frecuency_spin->setValue(ToneGeneratorAmplitudeDefault);
    ui->frecuency_slider->setRange(0,100);
    ui->amplitud_slider->setRange(100,500);
    ui->frecuency_slider->setValue(ToneGeneratorFreqDefault);
    ui->amplitud_slider->setValue(ToneGeneratorAmplitudeDefault);
}

void Tonegenerator_dialog::on_sweep_checkBox_toggled(bool checked)
{
    frecuencySweepEnabled(checked);
}

void Tonegenerator_dialog::on_frecuency_slider_valueChanged(int value)
{
    ui->frecuency_spin->setValue(value);
}


void Tonegenerator_dialog::on_amplitud_slider_valueChanged(int value)
{
    ui->amplitud_spin->setValue(value);
}
