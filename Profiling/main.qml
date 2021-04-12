/* PURSPOSE: Obtain the current date and time of system
 * PROJECT_NAME: Profiling
 * IMPLEMENTATION: QML application, using Qt formatTime,formatDateTime
*/

import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.12

//Creation of window titled System_Date_Time
Window {
    visible: true
    width: 200
    height: 200
    title: qsTr("System_Date_Time")


    Rectangle{
        id: rect1
        x: 0
        y: 0
        width: 200
        height: 200
         color: "lavender"//rectangle color
           Text
           {
               anchors.centerIn: parent
               text: Qt.formatDateTime(new Date(), "yy/MM/dd")//specified format for date
               anchors.verticalCenterOffset: -50
               anchors.horizontalCenterOffset: 42
           }

            Text
            {
                 id:txt
                 x: 115
                 y: 119
                 width: 49
                 height: 14
                 text: Qt.formatTime(new Date(), "hh:mm:ss")//specified format for time
             }


           Text
           {
               id: text1
               x: 14
               y: 44
               width: 49
               height: 14
               text: qsTr("DATE")
               font.pixelSize: 12
           }

           Text
           {
               id: text2
               x: 14
               y: 119
               width: 49
               height: 14
               text: qsTr("TIME")
               font.pixelSize: 12
           }
    }
}


