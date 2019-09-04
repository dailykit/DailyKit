import QtQuick 2.9
import QtQuick.Window 2.2
import "QML/Components/OrderPages"
import "QML/ComponentsCore/Views"

Window {
    visible: true
    width: 1240
    height: 550
    color: "black"

    Rectangle {
        id: idTopMargin
        height: 2
        width: parent.width
        color: "grey"
        anchors{

            top: parent.top
            topMargin: 40
        }
    }

    Rectangle {
        id: idleftMargin
        height: parent.height
        width: 2
        color: "grey"
        anchors{
            left: parent.left
            leftMargin: parent.width * 0.055
            top: idTopMargin.bottom
            //topMargin: parent.height * 0.05
        }
    }

    WeighingScale{
        id: idWeightDetails
        height: parent.height * 0.4
        width: parent.width * 0.4

        anchors{
            top: parent.top
            topMargin: parent.height * 0.09
            left: idleftMargin.right
            leftMargin: parent.width * 0.03
        }

    }
    AppListView {
        id: trialRect
        width: parent.width * 0.4
        height: parent.height * 0.9

        anchors {
            top: parent.top
            topMargin: parent.height * 0.09
            left: idWeightDetails.right
            leftMargin: parent.width * 0.03
        }

        model: orderView
        delegate:
            Text {
            id: trialll
            text: itemName
            color: "Grey"
        }


        sectionProperty: "orderId"
        sectionDelegate: sectionDelegate1

        Component {
            id: sectionDelegate1
            Rectangle{
                width: parent.width * 0.6
                height: 20
                color: "white"
                Text {
                    width: 30
                    height: 20
                    text: section
                    color: "black"
                }
            }
        }


    }

    Rectangle {
        id: idRightMargin
        height: parent.height
        width: 2
        color: "grey"
        anchors{
            right: parent.right
            rightMargin: parent.width * 0.055
            top: idTopMargin.bottom
        }
    }
}
