#ifndef PERSIANDATEUTIL_H
#define PERSIANDATEUTIL_H

#include <QDateTime>

class PersianDate
{
public:
    int Year;
    int Month;
    int Day;
    int DayOfWeek;
    bool IsLeap;
    int MonthTotalDays;

    PersianDate() { Year = Month = Day = DayOfWeek = -1; }
    PersianDate(QDate gDate);

    bool IsValidDate();

};

class PersianDateUtil
{
public:
    static PersianDate GerigorianToPersian(int gYear, int gMonth, int gDay);
    static PersianDate GerigorianToPersian(QDate gDate);
    static bool IsGerigorianYearLeap(int gYear);

};

#endif // PERSIANDATEUTIL_H
