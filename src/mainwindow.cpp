#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pdpr = new qPersianDatePicker(this->ui->widget);
    pdpr->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
