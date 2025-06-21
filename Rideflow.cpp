//This is the Mac Daddy of this program. Uses QT
#include <iostream>
#include "conn_can/can.h"
#include "conn_can/mcu_can_frame.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>

using namespace std;
int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    const QUrl url(u"MainWindow.qml"_qs);

    engine.load(url);

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }
    can::currentcan.can_open_socket("vcan0");
    return app.exec();

}


