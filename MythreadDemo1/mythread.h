/* PURPOSE: Start, Stop and Restart a counter
 * PROJECT_NAME: MYthreadDemo1
 * IMPLEMENTATION: Using threads concept, mutex is used to make sure one thread is locked at a moment and executed.
*/

#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

#include <QThread>

class mythread : public QThread
{
    Q_OBJECT
public:
    explicit mythread(QObject *parent = 0, bool b = false, int count=0);
    //
    void run();

    // if Stop = true, the thread will break
        // out of the loop, and will be disposed
        bool Stop;
       int stopped;

    signals:
        // To communicate with Gui Thread
        // we need to emit a signal
        void valueChanged(int);

    public slots:

};

#endif // MYTHREAD_H
