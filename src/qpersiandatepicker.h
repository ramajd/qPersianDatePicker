#ifndef QPERSIANDATEPICKER_H
#define QPERSIANDATEPICKER_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QDate>
#include <QVector>



class qPersianDatePicker : public QWidget
{
    Q_OBJECT
public:
    explicit qPersianDatePicker(QWidget *parent = 0);

    bool SetCalendarWeekNameList(QStringList *names = NULL);
    bool SetCalendarWeekNameStyle(QString style = "");
    bool SetCalendarDayStyle(QString style = "");
    bool SetCalendarHolidayStyle(QString style = "");


signals:

public slots:

private:

    QStringList *_calendarWeekNameList;
    QString _calendarWeekNameStyle;
    QString _calendarDayStyle;
    QString _calendarHolidayStyle;
    QString _calendarSelectedDayStyle;
    QString _calendarTodyStyle;

    void InitWidget();
    QVector<QStringList> LoadCalendar(QDate selectedDate);
};

#endif // QPERSIANDATEPICKER_H
