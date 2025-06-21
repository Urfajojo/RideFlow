import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
import QtQuick.Shapes

Window {
    id: window
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

        Rectangle {
            id: topbar
            height: 35
            opacity: 0.298
            color: "#252526"
            border.width: 0
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.topMargin: 0
        }
    }

    Column {
        id: column
        anchors.fill: parent
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.topMargin: 2
        anchors.bottomMargin: -2










        Row {
            id: row
            width: 400
            height: 35















            Image {
                id: image
                width: 100
                height: 35
                source: "resources/CAN_Logo.svg"
                sourceSize.height: 80
                sourceSize.width: 80
                fillMode: Image.PreserveAspectFit
            }

            Text {
                id: clock
                width: 80
                height: 25
                color: "#ffffff"
                text: Qt.formatTime(new Date()("hh:mm"))
                Timer {
                    interval: 1000
                    running: true
                    repeat: true
                    onTriggered: clock.text = Qt.formatTime(new Date(), ("hh:mm"))
                }
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 5
                font.pixelSize: 20
                verticalAlignment: Text.AlignVCenter
                anchors.verticalCenterOffset: 1
                font.styleName: "Bold"
            }

        }

        Item {
            id: speedcluster
            width: 200
            height: 200
        }


    }

}
