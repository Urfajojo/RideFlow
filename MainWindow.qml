import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
import QtQuick.Shapes 6.5
import QtQml

Window {
    id: window
    width: 400
    height: 500
    visible: true
    title: qsTR("RideFlow")


    Rectangle {
        id: bg
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

        Rectangle {
            id: speedclusterbackdrop
            x: 10
            y: 47
            width: 380
            height: 405
            opacity: 0.303
            color: "#252526"
            border.width: 0
            anchors.centerIn: parent
        }
    }

    Item {
        id: swipingarea
        x: 10
        y: 47
        width: 380
        height: 405

        SwipeView {
            id: swipeView
            anchors.fill: parent
            currentIndex: 0

            Item {
                id: overview
                anchors.centerIn: parent
                anchors.fill: parent

                Text {
                    anchors.centerIn: parent
                    id: speedindicator
                    color: "#ffffff"
                    text: qsTr(telemetry.speed)
                    font.pixelSize: 72
                    anchors.verticalCenterOffset: -16
                    z: 10
                    font.styleName: "Bold"
                }

                Text {
                    id: text1
                    color: "#ffffff"
                    text: qsTr("km/H")
                    font.pixelSize: 24
                    anchors.verticalCenterOffset: 40
                    anchors.centerIn: parent
                    font.styleName: "Bold"
                }


            }

            Item {
                id: settings
                anchors.centerIn: parent
                anchors.fill: parent
            }
        }

        PageIndicator {
            id: pageIndicator
            x: 173
            anchors.bottom: parent.bottom
            anchors.bottomMargin: -30
            enabled: true
            interactive: false
            count: 2
            currentIndex: swipeView.currentIndex
        }
    }


    Column {
        id: column
        width: 400
        height: 500
        anchors.top: parent.top
        anchors.topMargin: 0
        spacing: 0
        leftPadding: 10
        topPadding: 5










        Row {
            id: row
            leftPadding: 0
            topPadding: 0
            layoutDirection: Qt.LeftToRight
            spacing: 0

            Text {
                id: clock
                x: 0
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
                font.pixelSize: 20
                verticalAlignment: Text.AlignVCenter
                font.styleName: "Bold"
            }

        }


    }



}
