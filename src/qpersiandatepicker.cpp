#include "qpersiandatepicker.h"

qPersianDatePicker::qPersianDatePicker(QWidget *parent) :
    QWidget(parent)
{

    InitCalendarLayout();
}

qPersianDatePicker::~qPersianDatePicker()
{
    delete calendarLayout;
}

void qPersianDatePicker::InitCalendarLayout()
{

    calendarLayout = new QGridLayout();

    QLabel *lbl;

    int x(0), y(0);





    for (int i = 0; i < 49; ++i) {

        lbl = new QLabel();
        lbl->setFixedSize(20, 20);
        lbl->setText(QString::number(i));
        lbl->setStyleSheet("background-color: #FFFFFF;");
        lbl->setAlignment(Qt::AlignCenter);
        calendarLayout->addWidget(lbl, y, x);

        if (x == 6) {
            x = 0;
            y++;
        } else {
            x++;
        }

    }

    calendarLayout->addWidget(new QLabel("ش"),2, 2);


    this->setLayout(calendarLayout);
    this->setStyleSheet("border: none; background-color: #FFFFFF;");
}
