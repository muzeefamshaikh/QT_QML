/* PURPOSE: Start, Stop and Restart a counter
 * PROJECT_NAME: MYthreadDemo1
 * IMPLEMENTATION: Using threads concept, mutex is used to make sure one thread is locked at a moment and executed.
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
double firstNum; //global variable declaration
bool userSecondNumber=false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

        //Connecting the signal and slots using the keyword "connect"
        connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
        connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
        connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
        connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
        connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
        connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
        connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
        connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
        connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
        connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));
        connect(ui->pushButton_Plus_Minus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
        connect(ui->pushButton_Percent,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
        connect(ui->pushButton_Add,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
        connect(ui->pushButton_Subtract,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
        connect(ui->pushButton_Multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
        connect(ui->pushButton_Divide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    //to make the basic operations buttons toggle from checked/pressed to unchecked /unpressed
    ui->pushButton_Add->setCheckable(true);
    ui->pushButton_Subtract->setCheckable(true);
    ui->pushButton_Multiply->setCheckable(true);
    ui->pushButton_Divide->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Function defination for digits pressed on calculator
void MainWindow::digit_pressed()
{
    //qDebug()<<"Test"; //Similar to Cout in C++
    QPushButton *button=(QPushButton*)sender();//button that sends signal
    double labelNumber;
    QString newLabel;
    //to clear the label
    if((ui->pushButton_Add->isChecked()||
            ui->pushButton_Subtract->isChecked()||
            ui->pushButton_Multiply->isChecked()||
            ui->pushButton_Divide->isChecked())&&(!userSecondNumber))
    {
        labelNumber= button->text().toDouble();
        userSecondNumber=true;//to allow multiple digit input
    }
    else
    {
      labelNumber=(ui->label->text()+button->text()).toDouble();//to concatenate the label and button number

    }
    newLabel=QString::number(labelNumber);//convert double back to string value
    ui->label->setText(newLabel);
}

//Function defination for decimal button pressed on calculator
void MainWindow::on_pushButton_Decimal_released()
{
    ui->label->setText(ui->label->text()+".");//concatenate the digit with decimal point
}

//Function defination for unary buttons pressed on calculator
void MainWindow::unary_operation_pressed()
{
    QPushButton *button=(QPushButton*)sender();
            double labelNumber;
            QString newLabel;
            if(button->text() == "+/-")
            {
                 labelNumber=ui->label->text().toDouble();
                 labelNumber=labelNumber * -1;
                  newLabel=QString::number(labelNumber);
                  ui->label->setText(newLabel);
            }
            if(button->text() == "%")
            {
                 labelNumber=ui->label->text().toDouble();
                 labelNumber=labelNumber * 0.01;
                  newLabel=QString::number(labelNumber);
                  ui->label->setText(newLabel);
            }
}

//Function defination for clear button pressed on calculator
void MainWindow::on_pushButton_Clear_released()
{
    ui->pushButton_Add->setChecked(false);
    ui->pushButton_Subtract->setChecked(false);
    ui->pushButton_Multiply->setChecked(false);
    ui->pushButton_Divide->setChecked(false);
    userSecondNumber=false;
    ui->label->setText("0");
}

//Function defination for binary buttons pressed on calculator
void MainWindow::binary_operation_pressed()
{
    QPushButton *button=(QPushButton*)sender();
    button->setChecked(true);//to check if button pressed
    firstNum=ui->label->text().toDouble();
}

//Function defination for equal button pressed on calculator
void MainWindow::on_pushButton_Equal_released()
{
    double labelNumber,secondNum;
     QString newLabel;
    secondNum= ui->label->text().toDouble();
    if(ui->pushButton_Add->isChecked())
    {
       labelNumber=firstNum+secondNum;
       newLabel=QString::number(labelNumber);
       ui->label->setText(newLabel);
       ui->pushButton_Add->setChecked(false);
    }
    else if(ui->pushButton_Subtract->isChecked())
    {
        labelNumber=firstNum-secondNum;
        newLabel=QString::number(labelNumber);
        ui->label->setText(newLabel);
        ui->pushButton_Subtract->setChecked(false);
    }
    else if(ui->pushButton_Multiply->isChecked())
    {
        labelNumber=firstNum*secondNum;
        newLabel=QString::number(labelNumber);
        ui->label->setText(newLabel);
        ui->pushButton_Multiply->setChecked(false);
    }
    else if(ui->pushButton_Divide->isChecked())
    {
        labelNumber=firstNum/secondNum;
        newLabel=QString::number(labelNumber);
        ui->label->setText(newLabel);
        ui->pushButton_Divide->setChecked(false);
    }
    userSecondNumber=false;
}
