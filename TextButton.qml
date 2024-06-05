import QtQuick 2.15
import QtQuick.Controls 2.15

RoundButton {
    radius: parent.height
    Text {
        font.pointSize: parent.radius
    }
}
