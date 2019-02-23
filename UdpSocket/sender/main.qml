import QtQuick 2.9
import QtQuick.Window 2.2
import UDP 1.0

Window{
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("UDP sender")
    Timer{
        interval: 2000
        repeat: true
        running: true
        onTriggered: {
            Sender.send()
        }
    }
}
