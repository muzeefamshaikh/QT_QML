/* PURPOSE: Change COLOR, SHAPE of one rectangle on click of another using widgets
 * PROJECT_NAME: Rectangle
 * IMPLEMENTATION: QML application using different widgets and properties
*/

import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

//Creation of a window titled Rectangle
Window {
    width: 640
    height: 480
    visible: true
    color: "#add8e6"
    title: qsTr("Rectangle")

    Rectangle{
        id:rect1
        x: 143
        y:185
        width: 69
        height: 100
        color: "#f0a4a4"

    //MouseAreafor the 1st rectangle
        MouseArea {
            id: mouseArea
            x: 0
            y: 0
            width: 69
            height: 100
            //changing colour of rectangle on click
            onClicked: {
                rect2.color="grey"
                console.log("Color of rect2 changed")// To be visible on the console for confirmation
            }
        }
    }
    Rectangle{
        id: rect2
        x:434
        y:185
        width:69
        height: 100
        color: "#f0efa4"
        border.color: "#f95270"
}
  //MouseAreafor the 2nd rectangle
    MouseArea {
        id: mouseArea1
        x: 434
        y: 185
        width: 69
        height: 100
        //changing shape of rectangle onclick
        onClicked: {
            rect1.width=90
            rect1.height=180
            console.log("Shape of rect1 changed")// To be visible on the console for confirmation
        }
    }
}


