import QtQuick 2.15
import QtQuick.Window 2.15
import CoolPackage 1.0


Window {
    id:         root
    width:      360
    height:     616
    visible:    true
    title:      qsTr("Calculator")
    color:      "#024873"


    Calculator{
        id: calculator
    }

    Rectangle {
        id:        outputArea
        width:     parent.width
        height:    parent.height / 4 + parent.width / 20
        y:         - parent.width / 20
        color:     "#04BFAD"
        radius:    parent.width / 20

        Rectangle {
            id:                  textArea
            anchors.centerIn:    parent
            width:               parent.width * 0.9
            height:              parent.height * 0.9
            color:               "#04BFAD"

            Text {
                id:               result
                text:             calculator.calcValue
                color:            "white"
                font.pointSize:   parent.height / 4
                anchors.right:    parent.right
                anchors.bottom:   parent.bottom
            }

            Text {
                id: terms
                text:              "terms"
                color:             "white"
                font.pointSize:    result.height / 4
                anchors.bottom:    result.top
                anchors.right:     parent.right
            }

        }

    }

    Rectangle {
        id: inputArea
        anchors.top:       outputArea.bottom
        anchors.bottom:    parent.bottom
        anchors.left:      parent.left
        anchors.right:     parent.right
        color:             "#024873"

        ButtonsArea{
            width:     parent.width   * 0.93
            height:    parent.height  * 0.91
        }
    }


}
