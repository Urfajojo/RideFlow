import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
import QtQuick.Shapes

Window {
    width: 400
    height: 500
    visible: true
    title: qsTR("RideFlow")

    Rectangle {
        id: rectangle
        visible: true
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#2c789a" } //top
            GradientStop { position: 1.0; color: "#1e3847" } //bottom

        }
    }

    Column {
        id: column
        anchors.fill: parent



        Rectangle {
            id: topbar
            width: 400
            height: 35
            opacity: 0.3
            color: "#252526"
            border.width: 0

            Row {
                id: row
                anchors.fill: parent
                anchors.leftMargin: 0
                anchors.rightMargin: 0
                anchors.topMargin: 1
                anchors.bottomMargin: -1
            }

            Text {
                id: clock
                x: 5
                width: 80
                height: 25
                text: qsTr("Text")
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 12
            }
        }
        Item {
            id: speedcluster
            x: 100
            y: 0
            width: 200
            height: 200
        }
    }
}
