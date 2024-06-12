import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15


Rectangle {
    id:                  buttonsArea
    anchors.centerIn:    parent
    color:              "#024873"

    Rectangle{
        id:                leftArea
        width:             parent.width * 0.75
        color:             "#024873"
        anchors {
            top:       parent.top
            bottom:    parent.bottom
            left:      parent.left
        }

        RowLayout {
            id:               complexOperations
            height:           parent.height * 0.2
            anchors {
                top:      parent.top
                left:     parent.left
                right:    parent.right
            }

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
                onPressed: calculator.bracketPressed()

                background: Rectangle {
                    radius: parent.height / 2
                    color: parent.down ? "#F7E425" : "#0889A6"
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
                background: Rectangle {
                    radius: parent.height / 2
                    color: parent.down ? "#F7E425" : "#0889A6"
                }
                onPressed: calculator.changeSignPressed()
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
                background: Rectangle {
                    radius: parent.height / 2
                    color: parent.down ? "#F7E425" : "#0889A6"
                }
                onPressed: calculator.percentPressed()
            }
        }

        GridLayout{
            id:               numbers
            rows:             3
            columns:          3
            height:           parent.height * 0.6
            anchors {
                top:      complexOperations.bottom
                left:     parent.left
                right:    parent.right
            }

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
                        text:                index + 1
                    }

                    background: Rectangle {
                        radius: parent.height / 2
                        color: parent.down ? "#04BFAD" : "#B0D1D8"
                    }
                    onPressed: calculator.numberPressed(index + 1)
                }
            }
        }

        RowLayout{
            anchors {
                top:       numbers.bottom
                bottom:    parent.bottom
                left:      parent.left
                right:     parent.right
            }

            RoundButton {
                Layout.leftMargin:         buttonsArea.height * 0.029
                Layout.preferredHeight:    buttonsArea.height * 0.14
                Layout.preferredWidth:     buttonsArea.height * 0.14

                Text {
                    color:               "#024873"
                    font.pointSize:      buttonsArea.height * 0.05
                    anchors.centerIn:    parent
                    text:                "C"
                }

                background: Rectangle {
                    radius: parent.height / 2
                    color: parent.down ? "#F25E5E" : "#F08080"
                }
                onPressed: calculator.clearPressed()
            }

            RoundButton {
                Layout.preferredHeight:    buttonsArea.height * 0.14
                Layout.leftMargin:         buttonsArea.height * 0.029
                Layout.preferredWidth:     buttonsArea.height * 0.14

                Text {
                    color:               "#024873"
                    font.pointSize:      buttonsArea.height * 0.05
                    anchors.centerIn:    parent
                    text:                "0"
                }

                onPressed: calculator.numberPressed(0)
            }

            RoundButton {
                Layout.preferredHeight:    buttonsArea.height * 0.14
                Layout.leftMargin:         buttonsArea.height * 0.029
                Layout.preferredWidth:     buttonsArea.height * 0.14

                Text {
                    color:               "#024873"
                    font.pointSize:      buttonsArea.height * 0.05
                    anchors.centerIn:    parent
                    text:                "."
                }
                background: Rectangle {
                    radius: parent.height / 2
                    color: parent.down ? "#04BFAD" : "#B0D1D8"
                }
                onPressed: calculator.dotPressed()
            }

        }
    }

    ColumnLayout{

        anchors {
            top:       parent.top
            bottom:    parent.bottom
            right:     parent.right
            left:      leftArea.right
        }

        RoundButton {
            Layout.leftMargin:         buttonsArea.height * 0.029
            Layout.preferredHeight:    buttonsArea.height * 0.14
            Layout.preferredWidth:     buttonsArea.height * 0.14
            Text {
                color:               "#024873"
                font.pointSize:      buttonsArea.height * 0.05
                anchors.centerIn:    parent
                text:                "/"
            }
            background: Rectangle {
                radius: parent.height / 2
                color: parent.down ? "#F7E425" : "#0889A6"
            }
            onPressed: calculator.operationPressed('/')
        }

        RoundButton {
            Layout.leftMargin:         buttonsArea.height * 0.029
            Layout.preferredHeight:    buttonsArea.height * 0.14
            Layout.preferredWidth:     buttonsArea.height * 0.14
            Text {
                color:               "#024873"
                font.pointSize:      buttonsArea.height * 0.05
                anchors.centerIn:    parent
                text:                "*"
            }
            background: Rectangle {
                radius: parent.height / 2
                color: parent.down ? "#F7E425" : "#0889A6"
            }
            onPressed: calculator.operationPressed('*')
        }

        RoundButton {
            Layout.leftMargin:         buttonsArea.height * 0.029
            Layout.preferredHeight:    buttonsArea.height * 0.14
            Layout.preferredWidth:     buttonsArea.height * 0.14
            Text {
                color:               "#024873"
                font.pointSize:      buttonsArea.height * 0.05
                anchors.centerIn:    parent
                text:                "-"
            }
            background: Rectangle {
                radius: parent.height / 2
                color: parent.down ? "#F7E425" : "#0889A6"
            }
            onPressed: calculator.operationPressed('-')
        }

        RoundButton {
            Layout.leftMargin:         buttonsArea.height * 0.029
            Layout.preferredHeight:    buttonsArea.height * 0.14
            Layout.preferredWidth:     buttonsArea.height * 0.14
            Text {
                color:               "#024873"
                font.pointSize:      buttonsArea.height * 0.05
                anchors.centerIn:    parent
                text:                "+"
            }
            background: Rectangle {
                radius: parent.height / 2
                color: parent.down ? "#F7E425" : "#0889A6"
            }
            onPressed: calculator.operationPressed('+')
        }

        DelayButton {
            Layout.leftMargin:         buttonsArea.height * 0.029
            Layout.preferredHeight:    buttonsArea.height * 0.14
            Layout.preferredWidth:     buttonsArea.height * 0.14
            Text {
                color:               "#024873"
                font.pointSize:      buttonsArea.height * 0.05
                anchors.centerIn:    parent
                text:                "="
            }
            delay: 4000
            onActivated:
                {
                    calculator.equalsActivated()
                    progress = 0.0
                }

            onPressed: calculator.equalsPressed()

            background: Rectangle {
                color:     parent.down ? "#F7E425" : "#0889A6"
                radius:    height / 2
            }
        }
    }

    Connections {
        target: calculator
        onIsSecretMenuVisibleChanged : {
            root.hide()
            secretMenu.show()
        }
    }

    SecretMenu {
        id: secretMenu
    }

}
