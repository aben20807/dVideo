import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("dVideo")

    Column {
        id: col
        anchors.fill: parent
        anchors.margins: 7
        Row {
            id: toolOfUrl
            width: parent.width
            height: 40
            anchors.margins: 7
            Text {
                id: urlText
                text: qsTr("網址：")
                font.family: "微軟正黑體"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 12
                height: parent.height
                anchors.left: parent.verticalCenter
            }
            TextField {
                id: urlInput
                font.family: "微軟正黑體"
                font.pointSize: 10
                height: parent.height
                width: parent.width - (urlText.width)
            }
        }
        Row {
            id: toolOfType
            width: parent.width
            height: 40
            anchors.top: toolOfUrl.bottom
            anchors.margins: 7
            RadioButton {
                id: selectAll
                height: parent.height
                Text {
                    id: selectAllText
                    height: parent.height
                    anchors.left: parent.right
                    text: qsTr("全選")
                    font.family: "微軟正黑體"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: 12
                }
            }
        }
    }


}
