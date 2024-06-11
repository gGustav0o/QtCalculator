import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

Window  {
    width:      360
    height:     616

    Text {
        text: "Секретное меню"
        font.pointSize: parent.width / 20
        anchors {
            top: parent.top
            horizontalCenter: parent.horizontalCenter
        }
    }

    Button {
        text: qsTr("Главное окно")
        width: parent.width / 2
        height: width / 3
        anchors.centerIn: parent
        onClicked: {
            secretMenu.hide()
            root.show()
        }
    }

}
