/* PURPOSE: Start, Stop and Restart a counter
 * PROJECT_NAME: MYthreadDemo1
 * IMPLEMENTATION: Using threads concept, mutex is used to make sure one thread is locked at a moment and executed.
*/

#include "dialog.h"
#include "ui_dialog.h"
#include "mythread.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // create an instance of MyThread mThread is Private Member of mythread
       mThread = new mythread(this,false);// Thread creation

        // connect signal/slot
        connect(mThread, SIGNAL(valueChanged(int)),
                this, SLOT(onValueChanged(int)));

}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::onValueChanged(int count)
{
    ui->label->setText(QString::number(count));
}

// Start button
void Dialog::on_pushButton_clicked()
{
    mThread->Stop=false;
    mThread->start();
}

// Stop button
void Dialog::on_pushButton_2_clicked()
{
    mThread->stopped=true;
    mThread->Stop = true;

}

//Restart button
void Dialog::on_pushButton_3_clicked()
{
    mThread->Stop=false;
    mThread->stopped=0;
    mThread->start();

}

