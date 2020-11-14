#include "maininterface.h"
#include <QKeyEvent>
#include <QMessageBox>
#include <QSound>
#include "Tool.h"

MainInterface::MainInterface(QWidget *parent, QString title, int width, int height)
{
    this->width = width;
    this->height = height;
    this->title = title;
    this->setIcon(":/gui/images/gui/icon.png");

    titleImg = QImage(":/gui/images/gui/title.png");
    bg = QImage(":/gui/images/gui/bg.png").scaled(width, height);
    titleWidth = titleImg.width(), titleHeight = titleImg.height();

    SinglePlayer = new GameButton("SinglePlayer", this);
    MultiPlayer = new GameButton("MultiPlayer", this);
    Option = new GameButton("Option", this);
    Exit = new GameButton("Exit", this);

    MultiPlayer->setEnabled(false);
    Option->setEnabled(false);

    connect(SinglePlayer, &QPushButton::clicked, [=]() {
//        if(!this->isVisible()) return;
        sendInfo("Player Clicked SinglePlayer Button");
        buttonSound->play();
        select_world();
//        QMessageBox::critical(this, "Wrong", "Invalid!");
    });
    connect(MultiPlayer, &QPushButton::clicked, [=]() {
        sendInfo("Player Clicked MultiPlayer Button");
        sendError("MultiPlayer Button is Invalid");
        buttonSound->play();
        QMessageBox::critical(this, "Wrong", "Invalid!");
    });
    connect(Option, &QPushButton::clicked, [=]() {
        sendInfo("Player Clicked Option Button");
        sendError("Option Button is Invalid!");
        buttonSound->play();
        QMessageBox::critical(this, "Wrong", "Invalid!");
    });
    connect(Exit, &QPushButton::clicked, [=]() {
        sendInfo("Player Clicked Exit Button");
        sendInfo("Game Has Been Over");
        buttonSound->play();
        exit(0);
    });

    this->setWindowTitle(title);
    this->resize(width, height);
    this->setParent(parent);
}

void MainInterface::Show(int x, int y, int mode)
{
    if(mode == 0) this->move(x, y);
    switch (mode) {
    case 0:this->showNormal();break;
    case 1:this->showMaximized();break;
    case 2:this->showFullScreen();break;
    }
    sendInfo("MainInterface Has Been Shown");
}

void MainInterface::Hide()
{
    this->hide();
    sendInfo("MainInterface Has Been Hidden");

}

void MainInterface::closeEvent(QCloseEvent *event)
{
    sendInfo("MainInterface Has Been Closed");
}

void MainInterface::setIcon(QString path)
{
    this->setWindowIcon(QIcon(path));
}

void MainInterface::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(QRect(0, 0, width, height), bg);
    /*
      976 * 185 -> 1280 * 720

      (1280 - 976) / 2 = 152
      (720 / 2 - 185) / 2 = 87.5

      152 * width / 1280 = 19 * w / 160
      87.5 * height / 720 = 35 * h / 288

    */
    painter.drawImage(19 * width / 160, 35 * height / 288, titleImg.scaled(titleWidth * width / 1280, titleHeight * height / 720));
    painter.setFont(f);
    painter.setPen(QColor(255, 255, 255));
    painter.drawText(0 + 10, height - 10, "Minecraft  2D  1.0   Author: Bili_TianX");
}

void MainInterface::resizeEvent(QResizeEvent *event)
{
//    设置窗口比例固定
//    int newWidth = geometry().width(), newHeight = geometry().height();
//    if(newHeight * 1.0 / newWidth > height * 1.0 / width) {
//        this->resize(newWidth, height * newWidth / width);
//    } else if(newHeight * 1.0 / newWidth < height * 1.0 / width) {
//        this->resize(width * newHeight / height, newHeight);
//    }
    this->width = geometry().width();
    this->height = geometry().height();
    SinglePlayer->resize(400 * width / 1280, 40 * height / 720);
    MultiPlayer->resize(400 * width / 1280, 40 * height / 720);
    Option->resize(400 * width / 1280, 40 * height / 720);
    Exit->resize(400 * width / 1280, 40 * height / 720);
    SinglePlayer->setFont(f);
    MultiPlayer->setFont(f);
    Option->setFont(f);
    Exit->setFont(f);
    /*
    (1280 - 400) / 2 = 440
    (720 / 2 - 40 * 4) / 5 = 40
    */
    SinglePlayer->move(440 * width / 1280, 360 * height / 720); // 360 + 40 * 1
    MultiPlayer->move(440 * width / 1280, 440 * height / 720); // 360 + 40 * 3
    Option->move(440 * width / 1280, 520 * height / 720); // 360 + 40 * 5
    Exit->move(440 * width / 1280, 600 * height / 720); // 360 + 40 * 7

}

void MainInterface::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
    case Qt::Key_F11:
        if(!isFullScreen()) this->showFullScreen();
        else this->showNormal();
        break;
    case Qt::Key_Escape:
        sendInfo("Game Has Been Over");
        exit(0);
        break;
    }
}
