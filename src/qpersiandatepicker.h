#ifndef QPERSIANDATEPICKER_H
#define QPERSIANDATEPICKER_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QDate>
#include <QVector>
#include "persiandateutil.h"


class qPersianDatePicker : public QWidget
{
    Q_OBJECT
public:
    explicit qPersianDatePicker(QWidget *parent = 0, QDate *date = 0);

    bool SetCalendarWeekNameList(QStringList *names = NULL);
    bool SetCalendarWeekNameStyle(QString style = "");
    bool SetCalendarDayStyle(QString style = "");
    bool SetCalendarHolidayStyle(QString style = "");

    QDate SelectedDate(){ return _selectedDate; }
    void SetSelectedDate(QDate date);

signals:
    void SelectedDateChanged(QDateTime *selectedDate);

private:

    QStringList *_calendarWeekNameList;
    QString _calendarWeekNameStyle;
    QString _calendarDayStyle;
    QString _calendarHolidayStyle;
    QString _calendarSelectedDayStyle;
    QString _calendarTodyStyle;

    void InitWidget();
    QVector<QStringList> LoadCalendar(QDate selectedDate);
    QVector<QStringList> LoadCalendar(PersianDate selectedPersianDate);
    QDate _selectedDate;
};

#endif // QPERSIANDATEPICKER_H
