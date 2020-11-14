#ifndef MAPFACTORY_H
#define MAPFACTORY_H

#include <cstdio>
#include <QString>
#include <direct.h>
#include <QDir>
#include <QFile>

void writeMap(int *a[], int width, int height, QString mapName = "new_world") {
    QDir dir = QDir("assets/saves/" + mapName);
    if(!dir.exists()) dir.mkdir("assets/saves/" + mapName);
}

#endif // MAPFACTORY_H
