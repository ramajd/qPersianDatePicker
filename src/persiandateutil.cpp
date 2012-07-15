#include "persiandateutil.h"

PersianDate PersianDateUtil::GerigorianToPersian(QDate gDate)
{
    return GerigorianToPersian(gDate.year(), gDate.month(), gDate.day());
}
PersianDate PersianDateUtil::GerigorianToPersian(int gYear, int gMonth, int gDay)
{
    int pDay, pMonth, pYear;
    int dayCount,farvardinDayDiff,deyDayDiff ;

    int sumDayMiladiMonth[] = {0,31,59,90,120,151,181,212,243,273,304,334};
    int sumDayMiladiMonthLeap[]= {0,31,60,91,121,152,182,213,244,274,305,335};

    PersianDate pDate;

    farvardinDayDiff=79;

    dayCount = gDay + (IsGerigorianYearLeap(gYear) ? sumDayMiladiMonthLeap[gMonth - 1] : sumDayMiladiMonth[gMonth - 1] );
    deyDayDiff = (IsGerigorianYearLeap(gYear - 1) ? 11 : 10);

    if (dayCount > farvardinDayDiff) {

        dayCount = dayCount - farvardinDayDiff;

        if (dayCount <= 186) {

            switch (dayCount%31) {
            case 0:
                pMonth = dayCount / 31;
                pDay = 31;
                break;
            default:
                pMonth = (dayCount / 31) + 1;
                pDay = (dayCount%31);
                break;
            }
            pYear = gYear - 621;
        }
        else {
            dayCount = dayCount - 186;
            switch (dayCount%30) {
            case 0:
                pMonth = (dayCount / 30) + 6;
                pDay = 30;
                break;
            default:
                pMonth = (dayCount / 30) + 7;
                pDay = (dayCount%30);
                break;
            }
            pYear = gYear - 621;
        }
    } else {
        dayCount = dayCount + deyDayDiff;

        switch (dayCount%30) {
        case 0 :
            pMonth = (dayCount / 30) + 9;
            pDay = 30;
            break;
        default:
            pMonth = (dayCount / 30) + 10;
            pDay = (dayCount%30);
            break;
        }
        pYear = gYear - 622;
    }

    QDate curday = QDate(gYear, gMonth, gDay);

    pDate.Year = pYear;
    pDate.Month = pMonth;
    pDate.Day = pDay;
    pDate.DayOfWeek = (curday.dayOfWeek() + 2) % 7;

    return pDate ;

}

bool PersianDateUtil::IsGerigorianYearLeap(int gYear)
{
    if(((gYear % 100)!= 0 && (gYear % 4) == 0) || ((gYear % 100)== 0 && (gYear % 400) == 0))
        return true;
    else
        return false;
}






//================================

PersianDate::PersianDate(QDate gDate)
{
    PersianDate pd = PersianDateUtil::GerigorianToPersian(gDate);
    this->Year = pd.Year;
    this->Month = pd.Month;
    this->Day = pd.Day;
    this->DayOfWeek = pd.DayOfWeek;
}

int PersianDate::MonthTotalDays()
{
    if (this->IsValidDate()) {

        if(this->Month <= 6)
            return 31;

        if(PersianDateUtil::IsGerigorianYearLeap(this->Year) && this->Month == 12)
            return 29;

        return 30;

    } else {
        return -1;

    }



}

bool PersianDate::IsValidDate()
{
    if (this->Year > 0 && this->Month > 0 && this->Day > 0)
        return true;

    return false;
}
