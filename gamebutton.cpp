#include "gamebutton.h"
#include "Tool.h"
GameButton::GameButton(QString text, QWidget *parent)
{
    this->setParent(parent);
    this->text = text;
    this->setText(text);
    this->resize(400, 40);
    this->setFont(f);
    this->setStyleSheet("QPushButton{border-image: url(:/gui/images/gui/button_normal.png);color:rgb(255, 255, 255);}"
                        "QPushButton::hover{border-image: url(:/gui/images/gui/button_select.png);color:rgb(255, 215, 0);}"
                        "QPushButton::disabled{border-image: url(:/gui/images/gui/button_disabled.png);};");
}
