#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDate d(2013, 1, 12);
    pdpr = new qPersianDatePicker(this->ui->widget, &d);
    pdpr->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
