#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pdpicker = new qPersianDatePicker(ui->wgtDatePicker);
    pdpicker->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
