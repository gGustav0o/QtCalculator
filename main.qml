import QtQuick 2.15
import QtQuick.Window 2.15


Window {
    id:         root
    width:      360
    height:     616
    visible:    true
    title:      qsTr("Calculator")
    color:      "#024873"


    Rectangle {
        id:        outputArea
        width:     parent.width
        height:    parent.height / 4
        color:     "#04BFAD"
    }

    Rectangle {
        id: inputArea
        anchors.top:       outputArea.bottom
        anchors.bottom:    parent.bottom
        anchors.left:      parent.left
        anchors.right:     parent.right

        ButtonsArea{
            width:               parent.width   * 0.87
            height:              parent.height  * 0.86

        }
    }


}
