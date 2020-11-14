#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QWidget>
#include <QDebug>
#include <QIcon>
#include <QPainter>
#include "Tool.h"
#include <QPushButton>
#include "gamebutton.h"

class MainInterface : public QWidget
{
    Q_OBJECT
public:
    MainInterface(QWidget *parent = nullptr, QString title = nullptr, int width = 1280, int height = 720);
    void Show(int x = 0, int y = 0, int mode = 0);
    void Hide();
    void closeEvent(QCloseEvent *event) override;
    void setIcon(QString path);
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

    int width, height;
    QString title;
    QImage titleImg;
    QImage bg;
    int titleWidth, titleHeight;

    GameButton *SinglePlayer;
    GameButton *MultiPlayer;
    GameButton *Exit;
    GameButton *Option;

signals:
    void select_world();
};

#endif // MAININTERFACE_H
