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

                Shape {
                    width: 200
                    height: 200
                    ShapePath {
                        strokeWidth: 10
                        strokeColor: "white"
                        fillColor: "white"
                        Path {
                            startX: 150
                            startY: 150
                            PathAngleArc {
                                centerX: 100
                                centerY: 100
                                radiusX: 80
                                radiusY: 80
                                startAngle: -135
                                sweepAngle: 270
                            }

                            PathLine { x: 150; y: 150 }

                        }
                    }
                }


            }

            Item {
                id: settings
                anchors.centerIn: parent
                anchors.fill: parent
            }
        }
    }

    Rectangle {
        id: speedclusterbackdrop
        width: 380
        height: 405
        opacity: 0.303
        color: "#252526"
        border.width: 0
        anchors.centerIn: parent
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
