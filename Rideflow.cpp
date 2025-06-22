//This is the Mac Daddy of this program. Uses QT
#include <iostream>
#include "conn_can/can.h"
#include "conn_can/mcu_can_frame.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "conn_can/TelemetryModel.h"

using namespace std;
int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    TelemetryModel telemetry;
    can::currentcan.can_open_socket("vcan0");

    engine.rootContext()->setContextProperty("telemetry", &telemetry);

    qmlRegisterUncreatableType<TelemetryModel>("Telemetry", 1, 0, "TelemetryModel", "Accesed via context property");

    const QUrl url(u"MainWindow.qml"_qs);

    engine.load(url);

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }


    return app.exec();

}


