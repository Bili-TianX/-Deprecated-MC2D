#ifndef TOOL_H
#define TOOL_H

#include <QDebug>
#include <QTime>
#include <QFont>
#include <QSound>

static const QFont f("Minecraft", 15);
static QSound *buttonSound = new QSound(":/sound/musics/ButtonClicked.wav");
static const QString TITLE = "Minecraft v0.0.2";

static void sendInfo(QString msg) {
    QDateTime current_time = QDateTime::currentDateTime();
    qDebug() << "[" + current_time.toString("yyyy-MM-dd hh:mm:ss") + "][Info]" + msg;
}

static void sendError(QString msg) {
    QDateTime current_time = QDateTime::currentDateTime();
    qDebug() << "[" + current_time.toString("yyyy-MM-dd hh:mm:ss") + "][Error]" + msg;
}

static void sendWarning(QString msg) {
    QDateTime current_time = QDateTime::currentDateTime();
    qDebug() << "[" + current_time.toString("yyyy-MM-dd hh:mm:ss") + "][Warning]" + msg;
}


#endif // LOGGER_H
