#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTranslator>
#include <QIcon>
#include <Qt>
#include <QObject>

#include "selectworld.h"
#include "maininterface.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    //游戏主界面
    MainInterface *main_interface = new MainInterface(nullptr, TITLE);
    //选择世界
    SelectWorld *select_world = new SelectWorld(nullptr);

    main_interface->Show();
    QObject::connect(main_interface, &MainInterface::select_world, [=]() {
        main_interface->Hide();
        if(main_interface->isMaximized()) select_world->Show(0, 0, 1);
        else if(main_interface->isFullScreen()) select_world->Show(0, 0, 2);
        else {
            select_world->resize(main_interface->width, main_interface->height);
            select_world->Show(main_interface->x(), main_interface->y(), 0);
        }
    });
    QObject::connect(select_world, &SelectWorld::exited, [=]() {
        select_world->Hide();
        if(select_world->isMaximized()) main_interface->Show(0, 0, 1);
        else if(select_world->isFullScreen()) main_interface->Show(0, 0, 2);
        else {
            main_interface->resize(select_world->width, select_world->height);
            main_interface->Show(select_world->x(), select_world->y(), 0);
        }
    });
    return a.exec();
}
