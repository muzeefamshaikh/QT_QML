#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     //Connecting the signal and slots using the keyword "connect"
    connect(ui->horizontalSlider,SIGNAL(sliderMoved(int)),this,SLOT(Horizontal_Slider_Moved(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Function defination for slot
void MainWindow::Horizontal_Slider_Moved(int position)
{
    ui->label->setNum(position);
     qDebug() << "Slider moved: " << position;
}
