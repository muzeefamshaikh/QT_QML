/* PURPOSE: Start, Stop and Restart a counter
 * PROJECT_NAME: MYthreadDemo1
 * IMPLEMENTATION: Using threads concept, mutex is used to make sure one thread is locked at a moment and executed.
*/

#include "mythread.h"
#include <QDebug>
#include<QMutex>

mythread::mythread(QObject *parent, bool status,int count) :
    QThread(parent), Stop(status),stopped(count)
{
}

// run() will be called when a thread starts
void mythread::run()
{
    if(int i=0)
    {
               QMutex mutex;
               mutex.lock();
               if(this->stopped)
               {
                   //displays the counter in console
                   qDebug()<<i;
               while(i<100){
                  mutex.lock();
                   if(this->Stop) //break;
                    emit valueChanged(i);
                   break;
                   mutex.unlock();
                 //  emit valueChanged(stopped);
                      this->msleep(500);
                      i++;
               }
       }
    }

    else {
            for(int i=0; i <= 100; i++)
            {
                      QMutex mutex;
             // prevent other threads from changing the "Stop" value
                 mutex.lock();
              if(this->Stop) break;
              mutex.unlock();

        // emit the signal for the count label
        emit valueChanged(i);
        // slowdown the count change, msec
        this->msleep(500);

    }
}
}


