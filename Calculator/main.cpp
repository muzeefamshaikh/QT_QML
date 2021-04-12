/* PURPOSE: Start, Stop and Restart a counter
 * PROJECT_NAME: MYthreadDemo1
 * IMPLEMENTATION: Using threads concept, mutex is used to make sure one thread is locked at a moment and executed.
*/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
