#ifndef SELECTWORLD_H
#define SELECTWORLD_H

#include <QWidget>
#include <QImage>
#include <QPushButton>
#include "gamebutton.h"

class SelectWorld : public QWidget
{
    Q_OBJECT
public:
    explicit SelectWorld(QWidget *parent = nullptr);
    void Show(int x = 0, int y = 0, int mode = 0);
    void Hide();
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

    QImage bg = QImage(":/gui/images/gui/SelectWorld.png");
    int width, height;
    GameButton *PlaySelectedWorld = new GameButton("Play Selected World", this);
    GameButton *CreateNewWorld = new GameButton("Create New World", this);
    GameButton *Rename = new GameButton("Rename", this);
    GameButton *Delete = new GameButton("Delete", this);
    GameButton *ReCreate = new GameButton("Re-Create", this);
    GameButton *Cancel = new GameButton("Cancle", this);
signals:
    void exited();
};

#endif // SELECTWORLD_H
