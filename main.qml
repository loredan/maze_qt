import QtQuick 2.9
import QtQuick.Window 2.2
import ru.loredan13.maze 1.0
import QtQuick.Controls 1.5
import QtQuick.Extras 1.4
import QtQuick.Layouts 1.3
import QtQuick.Dialogs.qml 1.0
import QtQuick.Controls.Styles.Desktop 1.0

Window {
    id: window
    visible: true
    width: 1216
    height: 1000
    title: qsTr("Maze")

    RowLayout {
        id: rowLayout
        spacing: 0
        anchors.fill: parent

        ColumnLayout {
            id: columnLayout1
            width: 216
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            Layout.fillWidth: true
            Layout.fillHeight: false

            GroupBox {
                id: groupBox
                height: 300
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                title: qsTr("Generation")

                ColumnLayout {
                    id: columnLayout
                    anchors.fill: parent

                    ProgressBar {
                        id: progressBar
                        Layout.fillWidth: true
                        value: 0
                        orientation: 1
                    }

                    Button {
                        id: randomTraversal
                        text: qsTr("Random traversal")

                        onClicked: {
                            canvas.resetMaze()
                        }
                    }

                }
            }
        }

        Maze {
            id: canvas
            width: 1000
            height: 1000
            fillColor: "#000000"
            size: 100
        }
    }



}
