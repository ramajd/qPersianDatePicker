#ifndef PERSIANDATE_H
#define PERSIANDATE_H

#include <QDateTime>
#include <QString>

class PersianDate
{
public:

    int Year;
    int Month;
    int Day;

    PersianDate();
    PersianDate(QDate gDate);
    PersianDate(int pYear, int pMonth, int pDay);

    void SetDate(QDate gDate);
    void SetDate(PersianDate pDate);
    void SetDate(int pYear, int pMonth, int pDay);

    //QString ToString();

    static PersianDate GerigorianToPersian(QDate gDate);
    //static QDate PersianToGerigorian(PersianDate pDate);

private:
    static bool GerigorianIsLeep(int gYear);


};

#endif // PERSIANDATE_H
