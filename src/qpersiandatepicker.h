#ifndef QPERSIANDATEPICKER_H
#define QPERSIANDATEPICKER_H

#include <QWidget>

class PersianDate {

public:
    int Year;
    int Month;
    int Day;

    PersianDate(int y, int m, int d) {
        this->Year = y;
        this->Month = m;
        this->Day = d;
    }
};

class qPersianDatePicker : public QWidget
{
    Q_OBJECT
public:
    explicit qPersianDatePicker(QWidget *parent = 0);

signals:

public slots:

};

#endif // QPERSIANDATEPICKER_H
