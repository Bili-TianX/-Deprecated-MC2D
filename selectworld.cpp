#include "selectworld.h"
#include "Tool.h"
#include <QPainter>
#include <QKeyEvent>
#include <QIcon>

SelectWorld::SelectWorld(QWidget *parent) : QWidget(parent)
{
    this->resize(1280, 720);
    this->width = 1280;
    this->height = 720;
    this->setWindowIcon(QIcon(":/gui/images/gui/icon.png"));
    this->setWindowTitle("Minecraft v0.0.2");

    PlaySelectedWorld->setEnabled(false);
    Rename->setEnabled(false);
    Delete->setEnabled(false);
    ReCreate->setEnabled(false);

    connect(PlaySelectedWorld, &QPushButton::clicked, [=]() {
        sendInfo("Player Clicked PlaySelectedWorld Button");
        buttonSound->play();
    });
    connect(CreateNewWorld, &QPushButton::clicked, [=]() {
        sendInfo("Player Clicked CreateNewWorld Button");
        buttonSound->play();
    });
    connect(Rename, &QPushButton::clicked, [=]() {
        sendInfo("Player Clicked Rename Button");
        buttonSound->play();
    });
    connect(Delete, &QPushButton::clicked, [=]() {
        sendInfo("Player Clicked Delete Button");
        buttonSound->play();
    });
    connect(ReCreate, &QPushButton::clicked, [=]() {
        sendInfo("Player Clicked ReCreate Button");
        buttonSound->play();
    });
    connect(Cancel, &QPushButton::clicked, [=]() {
        sendInfo("Player Clicked Cancel Button");
        buttonSound->play();
        exited();
    });
}

void SelectWorld::Show(int x, int y, int mode)
{
    if(mode == 0) this->move(x, y);
    switch (mode) {
    case 0:this->showNormal();break;
    case 1:this->showMaximized();break;
    case 2:this->showFullScreen();break;
    }
    sendInfo("SelectWorld Has Been Shown");
}

void SelectWorld::Hide()
{
    this->hide();
    sendInfo("SelectWorld Has Been Hidden");
}

void SelectWorld::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawImage(QRect(0, 0, width, height), bg);
    p.setFont(f);
    p.setPen(QColor(255, 255, 255));
    p.drawText(555 * width / 1280, 125 * height / 720, "Select World");
}

void SelectWorld::resizeEvent(QResizeEvent *event)
{
    this->width = geometry().width();
    this->height = geometry().height();

    int tmpWidth = 190 * width / 1280, tmpHeight = 40 * height / 720;
    PlaySelectedWorld->resize(400 * width / 1280, 40 * height / 720);
    CreateNewWorld->resize(400 * width / 1280, 40 * height / 720);
    Rename->resize(tmpWidth, tmpHeight);
    Delete->resize(tmpWidth, tmpHeight);
    ReCreate->resize(tmpWidth, tmpHeight);
    Cancel->resize(tmpWidth, tmpHeight);

    PlaySelectedWorld->move(230 * width / 1280, 600 * height / 720);
    CreateNewWorld->move(650 * width / 1280, 600 * height / 720);
    Rename->move(230 * width / 1280, 660 * height / 720);
    Delete->move(440 * width / 1280, 660 * height / 720);
    ReCreate->move(650 * width / 1280, 660 * height / 720);
    Cancel->move(860 * width / 1280, 660 * height / 720);
}

void SelectWorld::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_F11:
        if(!isFullScreen()) this->showFullScreen();
        else this->showNormal();
        break;
    case Qt::Key_Escape:
        exited();
        break;
    }
}
