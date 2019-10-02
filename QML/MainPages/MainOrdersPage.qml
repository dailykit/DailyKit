import QtQuick 2.0
import "../Components/OrderPages"
import "../"

import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../Screens"


Item {
    id: root
    height: parent.height
    width: parent.width

    property alias loader: orderLoader
    property alias weighScale: idWeightDetails

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
        }
    }

    Row{
        id: middleScreen

        width: parent.width * 0.9
        height: parent.height * 0.8
        spacing: parent.width * 0.03

        anchors{
            top: parent.top
            topMargin: parent.height * 0.08
            left: idleftMargin.right
            leftMargin: parent.width * 0.03
        }


        WeighingScale{
            id: idWeightDetails
            width: parent.width * 0.4
            height: parent.height * 0.4

        }

        Loader {
            id: orderLoader
            width: parent.width * 0.45
            height: parent.height
        }

        Component.onCompleted:
            loader.source =  Qt.resolvedUrl( "../Screens/OrderList.qml")

    }


    RightBar {
        id: idRightMargin
        height: parent.height
        width:  parent.width * 0.04
        anchors{
            right: parent.right
            rightMargin: parent.width * 0.055
            top: idTopMargin.bottom
        }
        options.settings.mouseArea.onClicked :{
            stackView.push(Qt.createComponent(Qt.resolvedUrl("../Screens/Settings.qml")).createObject(parent, {width: stackView.width, height: stackView.height}))
        }
    }

}
