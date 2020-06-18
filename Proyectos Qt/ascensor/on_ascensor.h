#ifndef ON_ASCENSOR_H
#define ON_ASCENSOR_H

#include <QWidget>

namespace Ui {
class on_ascensor;
}

class on_ascensor : public QWidget
{
    Q_OBJECT

public:
    explicit on_ascensor(QWidget *parent = nullptr);
    ~on_ascensor();

private slots:
    void on_seven_button_clicked();

private:
    Ui::on_ascensor *ui;
};

#endif // ON_ASCENSOR_H
