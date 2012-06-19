#include "persiandate.h"

PersianDate::PersianDate()
{
    this->SetDate(QDate::currentDate());
}
PersianDate::PersianDate(QDate gDate)
{
    this->SetDate(gDate);
}
PersianDate::PersianDate(int pYear, int pMonth, int pDay)
{
    this->SetDate(pYear, pMonth, pDay);
}

void PersianDate::SetDate(QDate gDate)
{
    PersianDate pd = PersianDate::GerigorianToPersian(gDate);
    this->SetDate(pd);
}
void PersianDate::SetDate(PersianDate pDate)
{
    this->Year = pDate.Year;
    this->Month = pDate.Month;
    this->Day = pDate.Day;
}
void PersianDate::SetDate(int pYear, int pMonth, int pDay)
{
    this->Year = pYear;
    this->Month = pMonth;
    this->Day = pDay;
}


bool PersianDate::GerigorianIsLeep(int gYear)
{
    if(((gYear % 100)!= 0 && (gYear % 4) == 0) || ((gYear % 100)== 0 && (gYear % 400) == 0))
        return true;
    else
        return false;
}

PersianDate PersianDate::GerigorianToPersian(QDate gDate)
{
    int pDay, pMonth, pYear;
    int dayCount,farvardinDayDiff,deyDayDiff ;
    int gMonthLenArray[] = {0,31,59,90,120,151,181,212,243,273,304,334};
    int gLeepMonthLenArray[]= {0,31,60,91,121,152,182,213,244,274,305,335};

    farvardinDayDiff=79;

    if (GerigorianIsLeep(gDate.year())) dayCount = gLeepMonthLenArray[gDate.month() - 1] + gDate.day();
    else dayCount = gMonthLenArray[gDate.month()-1] + gDate.day();


    if((GerigorianIsLeep(gDate.year() - 1))) { deyDayDiff = 11; }
    else { deyDayDiff = 10; }

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
            pYear = gDate.year() - 621;
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
            pYear = gDate.year() - 621;
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
        pYear = gDate.year() - 622;
    }

    return PersianDate(pYear, pMonth, pDay);
}

