#ifndef QPERSIANDATEPICKER_H
#define QPERSIANDATEPICKER_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QDateTime>

#include "persiandate.h"

//===========================================================

class qPersianDatePicker : public QWidget
{
    Q_OBJECT
public:
    explicit qPersianDatePicker(QWidget *parent = 0);
    ~qPersianDatePicker();

    void SetSelectedDate(PersianDate pDate);
    void SetSelectedDate(QDate gDate);
    void SetSelectedDate(int pYear, int pMonth, int pDay);
signals:

public slots:

private:
    QGridLayout *calendarLayout;
    PersianDate _selectedDate;

    void InitCalendarLayout();



};

#endif // QPERSIANDATEPICKER_H
