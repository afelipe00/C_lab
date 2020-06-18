#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAudio>
#include <QIcon>

QT_BEGIN_NAMESPACE
class Qlabel;
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    void createUi();
    void connectUi();
    void createMenus();
    void reset();

    enum Mode {
        Nomode,
        RecordMode,
        GenerateToneMode
    };

    void setMode(Mode mode);
private:
    Mode m_mode;
    Qlabel* m_infoMessage;
};
#endif // WIDGET_H
