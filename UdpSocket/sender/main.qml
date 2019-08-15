import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import UDP 1.0

Window{
    id: root
    visible: true
    width: 360
    height: 240
    title: qsTr("UDP sender")
    TextField{
        id: textField
        anchors.top: parent.top
        anchors.topMargin: 60
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        placeholderText: qsTr("Enter something to send")
    }
    Button{
        width: 50
        height: 25
        text: "SEND"
        anchors.top: textField.bottom
        anchors.margins: 15
        anchors.right: parent.right
        anchors.rightMargin: 10
        onClicked:{
            UDPSender.send(textField.text)
        }
    }
}
