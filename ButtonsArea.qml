import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import CoolPackage 1.0


Rectangle {
    id:                  buttonsArea
    anchors.centerIn:    parent
    color:              "#024873"

    Calculator{
        id: calculator
    }

    Rectangle{
        id:                leftArea
        anchors.top:       parent.top
        anchors.bottom:    parent.bottom
        anchors.left:      parent.left
        width:             parent.width * 0.75
        color:             "#024873"

        RowLayout {
            id:               complexOperations
            anchors.top:      parent.top
            anchors.left:     parent.left
            anchors.right:    parent.right
            height:           parent.height * 0.2

            RoundButton {
                Layout.leftMargin:         buttonsArea.height * 0.029
                Layout.preferredHeight:    buttonsArea.height * 0.14
                Layout.preferredWidth:     buttonsArea.height * 0.14

                Text {
                    color:               "#024873"
                    font.pointSize:      buttonsArea.height * 0.05
                    anchors.centerIn:    parent
                    text:                "()"
                }
            }

            RoundButton {
                Layout.preferredHeight:    buttonsArea.height * 0.14
                Layout.leftMargin:         buttonsArea.height * 0.029
                Layout.preferredWidth:     buttonsArea.height * 0.14
                Text {
                    color:               "#024873"
                    font.pointSize:      buttonsArea.height * 0.05
                    anchors.centerIn:    parent
                    text:                "+/-"
                }
            }

            RoundButton {
                Layout.preferredHeight:    buttonsArea.height * 0.14
                Layout.leftMargin:         buttonsArea.height * 0.029
                Layout.preferredWidth:     buttonsArea.height * 0.14

                Text {
                    color:               "#024873"
                    font.pointSize:      buttonsArea.height * 0.05
                    anchors.centerIn:    parent
                    text:                "%"
                }
            }
        }

        GridLayout{
            id:               numbers
            rows:             3
            columns:          3
            anchors.top:      complexOperations.bottom
            anchors.left:     parent.left
            anchors.right:    parent.right
            height:           parent.height * 0.6

            Repeater {
                model: 9

                RoundButton {
                    Layout.leftMargin:         buttonsArea.height * 0.029
                    Layout.preferredHeight:    buttonsArea.height * 0.14
                    Layout.preferredWidth:     buttonsArea.height * 0.14

                    Text {
                        color:               "#024873"
                        font.pointSize:      buttonsArea.height * 0.05
                        anchors.centerIn:    parent
                        text:                index
                    }
                }
            }
        }

        RowLayout{
            anchors.top:       numbers.bottom
            anchors.bottom:    parent.bottom
            anchors.left:      parent.left
            anchors.right:     parent.right

            RoundButton {
                Layout.leftMargin: buttonsArea.height * 0.029
                Layout.preferredHeight:    buttonsArea.height * 0.14
                Layout.preferredWidth: buttonsArea.height * 0.14
                Text {
                    color: "#024873"
                    font.pointSize: buttonsArea.height * 0.05
                    anchors.centerIn: parent
                    text: "C"
                }
            }

            RoundButton {
                Layout.preferredHeight: buttonsArea.height * 0.14
                Layout.leftMargin: buttonsArea.height * 0.029
                Layout.preferredWidth: buttonsArea.height * 0.14
                Text {
                    color: "#024873"
                    font.pointSize: buttonsArea.height * 0.05
                    anchors.centerIn: parent
                    text: "0"
                }
            }

            RoundButton {
                Layout.preferredHeight: buttonsArea.height * 0.14
                Layout.leftMargin: buttonsArea.height * 0.029
                Layout.preferredWidth: buttonsArea.height * 0.14
                Text {
                    color: "#024873"
                    font.pointSize: buttonsArea.height * 0.05
                    anchors.centerIn: parent
                    text: "."
                }
            }

        }
    }

    ColumnLayout{

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: leftArea.right

        RoundButton {
            Layout.leftMargin: buttonsArea.height * 0.029
            Layout.preferredHeight: buttonsArea.height * 0.14
            Layout.preferredWidth: buttonsArea.height * 0.14
            Text {
                color: "#024873"
                font.pointSize: buttonsArea.height * 0.05
                anchors.centerIn: parent
                text: "/"
            }
        }

        RoundButton {
            Layout.leftMargin: buttonsArea.height * 0.029
            Layout.preferredHeight: buttonsArea.height * 0.14
            Layout.preferredWidth: buttonsArea.height * 0.14
            Text {
                color: "#024873"
                font.pointSize: buttonsArea.height * 0.05
                anchors.centerIn: parent
                text: "*"
            }
        }

        RoundButton {
            Layout.leftMargin: buttonsArea.height * 0.029
            Layout.preferredHeight: buttonsArea.height * 0.14
            Layout.preferredWidth: buttonsArea.height * 0.14
            Text {
                color: "#024873"
                font.pointSize: buttonsArea.height * 0.05
                anchors.centerIn: parent
                text: "-"
            }
        }

        RoundButton {
            Layout.leftMargin: buttonsArea.height * 0.029
            Layout.preferredHeight: buttonsArea.height * 0.14
            Layout.preferredWidth: buttonsArea.height * 0.14
            Text {
                color: "#024873"
                font.pointSize: buttonsArea.height * 0.05
                anchors.centerIn: parent
                text: "+"
            }
        }

        RoundButton {
            Layout.leftMargin: buttonsArea.height * 0.029
            Layout.preferredHeight: buttonsArea.height * 0.14
            Layout.preferredWidth: buttonsArea.height * 0.14
            Text {
                color: "#024873"
                font.pointSize: buttonsArea.height * 0.05
                anchors.centerIn: parent
                text: "="
            }
        }
    }

}
