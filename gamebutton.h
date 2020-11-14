#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class GameButton : public QPushButton
{
    Q_OBJECT
public:
    explicit GameButton(QString text = nullptr, QWidget *parent = nullptr);

    QString text;

private:
};

#endif // GAMEBUTTON_H
