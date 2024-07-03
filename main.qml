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
    minimumHeight: 200
    minimumWidth:  360


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
                id:                     result
                text:                   calculator.result
                color:                  "white"
                width:                  parent.width
                font.pointSize:         parent.height / 4 * (1 - (calculator.calcValue.length * 7 / parent.width))
                elide:                  Text.ElideMiddle
                horizontalAlignment:    Text.AlignRight
                anchors {
                    right:     parent.right
                    bottom:    parent.bottom
                }

            }

            Text {
                id:                     terms
                text:                   calculator.calcValue
                color:                  "white"
                width:                  parent.width
                font.pointSize:         parent.height / 4 * (1 - (calculator.calcValue.length * 7 / parent.width))
                elide:                  Text.ElideMiddle
                horizontalAlignment:    Text.AlignRight
                anchors {
                    bottom:    result.top
                    right:     parent.right
                }
            }

        }

    }

    Rectangle {
        id:       inputArea
        color:    "#024873"
        anchors {
            top:       outputArea.bottom
            bottom:    parent.bottom
            left:      parent.left
            right:     parent.right
        }

        ButtonsArea{
            width:     parent.width   * 0.93
            height:    parent.height  * 0.91
        }
    }


}
