#ifndef QPERSIANDATEPICKER_H
#define QPERSIANDATEPICKER_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDate>
#include <QVector>
#include <QDebug>
#include "persiandateutil.h"


class qPersianDatePicker : public QWidget
{
    Q_OBJECT
public:
    explicit qPersianDatePicker(QWidget *parent = 0, QDate *date = 0);

    void SetCalendarWeekNameList(QStringList names);
    void SetCalendarMonthNameList(QStringList monthNames);

    void SetCalendarWeekNameStyle(QString style = "");
    void SetCalendarDayStyle(QString style = "");
    void SetCalendarHolidayStyle(QString style = "");
    void SetCalendarTodayStyle(QString style = "");

    QDate SelectedDate();
    void SetSelectedDate(QDate date);

signals:
    void SelectedDateChanged(QDateTime *selectedDate);

private:

    QStringList _calendarWeekNameList;
    QStringList _calendarMonthNameList;
    QString _calendarWeekNameStyle;
    QString _calendarDayStyle;
    QString _calendarHolidayStyle;
    QString _calendarSelectedDayStyle;
    QString _calendarTodayStyle;

    void InitWidget();
    QVector<QStringList> LoadCalendar(QDate selectedDate);
    QVector<QStringList> LoadCalendar(PersianDate selectedPersianDate);
    QDate _selectedDate;
};

#endif // QPERSIANDATEPICKER_H
