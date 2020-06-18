#ifndef ON_ASCENSOR_H
#define ON_ASCENSOR_H

#include <QWidget>

namespace Ui {
class On_ascensor;
}

class On_ascensor : public QWidget
{
    Q_OBJECT

public:
    explicit On_ascensor(QWidget *parent = nullptr);
    ~On_ascensor();

private:
    Ui::On_ascensor *ui;
    void setupUi();
};

#endif // ON_ASCENSOR_H
