/* PURPOSE: To generate QML C++ interaction using Signal and Slots
 * PROJECT_NAME: Calculator
 * IMPLEMENTATION: A Qt widget application, using basic operations and using stylesheet to provide alignment for output(label) part.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digit_pressed();
    void on_pushButton_Decimal_released();
    void unary_operation_pressed();
    void on_pushButton_Clear_released();
    void binary_operation_pressed();
    void on_pushButton_Equal_released();
};
#endif // MAINWINDOW_H
