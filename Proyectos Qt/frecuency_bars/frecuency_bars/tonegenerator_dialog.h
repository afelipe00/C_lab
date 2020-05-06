#ifndef TONEGENERATOR_DIALOG_H
#define TONEGENERATOR_DIALOG_H

#include <QDialog>

namespace Ui {
class Tonegenerator_dialog;
}

class Tonegenerator_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Tonegenerator_dialog(QWidget *parent = nullptr);
    bool FrecuencySweepEnabled() const;
    qreal frecuency() const;
    qreal amplitud() const;
    ~Tonegenerator_dialog();
private slots:
    void frecuencySweepEnabled(bool enable);

    void on_sweep_checkBox_toggled(bool checked);

    void on_frecuency_slider_valueChanged(int value);

    void on_amplitud_slider_valueChanged(int value);

private:
    Ui::Tonegenerator_dialog *ui;
    bool m_frecuencySweepEnabled;
    qreal m_frecuency;
    void settingsUi();
};

#endif // TONEGENERATOR_DIALOG_H
