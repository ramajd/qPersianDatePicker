#ifndef PERSIANDATE_H
#define PERSIANDATE_H

#include <QDateTime>
#include <QString>

class PersianDate
{
public:
    enum PersianDateFormat{
        FORMAT_FULL,
        FORMAT_SMALL,
        FORMAT_NUMBER
    };

    int Year;
    int Month;
    int Day;

    PersianDate();
    PersianDate(QDate gDate);
    PersianDate(int y, int m, int d);

    QDate ToGerigorian();
    void SetDate(QDate gerigorianDate);
    void SetDate(int pYear, int pMonth, int pDay);

    QString ToString();

    static PersianDate GerigorianToPersian(QDate gDate);
    static QDate PersianToGerigorian(PersianDate pDate);

private:
    static bool GerigorianIsLeep(int gYear);


};

#endif // PERSIANDATE_H
