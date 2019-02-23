import QtQuick 2.9
import QtQuick.Window 2.2
import UDP 1.0

Window{
    id: root
    visible: true
    width: 300
    height: 200
    title: qsTr("UDP sender")
    Timer{
        interval: 50
        repeat: true
        running: true
        onTriggered: {
            Sender.send();
        }
    }
}
