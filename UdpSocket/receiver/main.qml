import QtQuick 2.9
import QtQuick.Window 2.2
import UDP 1.0

Window {
    visible: true
    width: 360
    height: 240
    title: qsTr("UDP receiver")
    Rectangle{
        anchors.fill: parent
        Text{
            text: "I received: \n\n" + UDPReceiver.data
            anchors.top: parent.top
            anchors.topMargin: 30
            anchors.left: parent.left
            anchors.leftMargin: 10
            font.family: "Helvetica"
            font.pointSize: 12
            color: "black"
        }
    }
}
