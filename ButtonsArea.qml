import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

GridLayout {
    id:                  buttonsArea
    anchors.centerIn:    parent
    rows: 5
    columns: 4

    TextButton {
        id: bracketsButton
        text: "()"
    }

    TextButton {
        id: plusMinusButton
        text: "+/-"
    }

    TextButton {
        id: percentButton
        text: "%"
    }

    TextButton {
        id: divideButton
        text: "/"
    }

    TextButton {
        id: button7
        text: "7"
    }

    TextButton {
        id: button8
        text: "8"
    }

    TextButton {
        id: button9
        text: "9"
    }

    TextButton {
        id: multiplyButton
        text: "*"
    }

    TextButton {
        id: button4
        text: "4"
    }

    TextButton {
        id: button5
        text: "5"
    }

    TextButton {
        id: button6
        text: "6"
    }

    TextButton {
        id: minusButton
        text: "-"
    }

    TextButton {
        id: button1
        text: "1"
    }

    TextButton {
        id: button2
        text: "2"
    }

    TextButton {
        id: button3
        text: "3"
    }

    TextButton {
        id: plusButton
        text: "+"
    }

    TextButton {
        id: cButton
        text: "C"
    }

    TextButton {
        id: zeroButton
        text: "0"
    }

    TextButton {
        id: pointButton
        text: "."
    }

    TextButton {
        id: equalsButton
        text: "="
    }

}
