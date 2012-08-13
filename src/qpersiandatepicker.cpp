#include "qpersiandatepicker.h"
#include <QDebug>

qPersianDatePicker::qPersianDatePicker(QWidget *parent, QDate *date) :
    QWidget(parent)
{
    _calendarWeekNameList = new QStringList();
    SetCalendarWeekNameList();
    SetCalendarWeekNameStyle();
    SetCalendarDayStyle();
    SetCalendarHolidayStyle();

    if (date != 0) this->SetSelectedDate(*date);
    else this->SetSelectedDate(QDate::currentDate());

    InitWidget();
}

void qPersianDatePicker::InitWidget()
{
    QGridLayout *monthLayout = new QGridLayout();
    monthLayout->setSpacing(2);

    QLabel *lbl;

    //=== Loading Calendar Header.
    for (int i = 0; i < _calendarWeekNameList->length(); ++i) {

        lbl = new QLabel(_calendarWeekNameList->at(6-i));
        lbl->setAlignment(Qt::AlignCenter);
        lbl->setStyleSheet(_calendarWeekNameStyle);
        lbl->setFixedSize(25, 25);
        monthLayout->addWidget(lbl, 0, i);
    }

    //=== Loading Calendar Days.

    QVector<QStringList> calendar = LoadCalendar(SelectedDate());

    for (int i = 0; i < calendar.count(); ++i) {
        for (int j = 0; j < calendar.at(i).length(); ++j) {

            lbl = new QLabel(calendar.at(i).at(j));
            lbl->setAlignment(Qt::AlignCenter);
            lbl->setStyleSheet(_calendarDayStyle);
            lbl->setFixedSize(25, 25);
            lbl->setCursor(Qt::PointingHandCursor);
            monthLayout->addWidget(lbl, i + 1, 6 - j);
        }
    }

    this->setLayout(monthLayout);
}

bool qPersianDatePicker::SetCalendarWeekNameList(QStringList *names)
{
    if (names == NULL) {
        _calendarWeekNameList->append(QString::fromUtf8("ش"));
        _calendarWeekNameList->append(QString::fromUtf8("۱ش"));
        _calendarWeekNameList->append(QString::fromUtf8("۲ش"));
        _calendarWeekNameList->append(QString::fromUtf8("۳ش"));
        _calendarWeekNameList->append(QString::fromUtf8("۴ش"));
        _calendarWeekNameList->append(QString::fromUtf8("۵ش"));
        _calendarWeekNameList->append(QString::fromUtf8("ج"));
        return true;

    } else if (names->length() == 7) {
        _calendarWeekNameList = names;
        return true;
    }
    return false;
}
bool qPersianDatePicker::SetCalendarWeekNameStyle(QString style)
{
    _calendarWeekNameStyle =
            "border: 1px solid #000000; "
            "border-radius: 10px; "
            "font: 9pt 'B Homa'; "
            "background-color: #0088FF; "
            "color: #FFFFFF;";

    if (style.trimmed() != "")
        _calendarWeekNameStyle = style;

    return true;
}
bool qPersianDatePicker::SetCalendarDayStyle(QString style)
{
    _calendarDayStyle = "border: 1px solid #000000; border-radius: 9px; font: 9pt 'B Homa';";

    if ( style.trimmed() != "" )
        _calendarDayStyle = style;

    return true;
}
bool qPersianDatePicker::SetCalendarHolidayStyle(QString style)
{
    _calendarHolidayStyle = "border: 1px solid #000000; border-radius: 9px; font: 9pt 'B Homa'; color: #FF0000";

    if ( style.trimmed() != "" )
        _calendarHolidayStyle = style;

    return true;
}

QVector<QStringList> qPersianDatePicker::LoadCalendar(QDate selectedDate)
{
    PersianDate pDate = PersianDateUtil::GerigorianToPersian(selectedDate);
    return LoadCalendar(pDate);
}
QVector<QStringList> qPersianDatePicker::LoadCalendar(PersianDate selectedPersianDate)
{
    int firstDayInWeek =
            (selectedPersianDate.DayOfWeek + 7 - (selectedPersianDate.Day - 1) % 7) % 7;
    firstDayInWeek = (firstDayInWeek == 0 ? 7 : firstDayInWeek);

    QVector<QStringList> retVal;

    int cntr = 1;

    for (int i = 0; i < 7; ++i) {
        if (cntr > 30) break;
        QStringList lst;
        for (int j = 0; j < 7; ++j) {
            if (cntr > selectedPersianDate.MonthTotalDays)
                lst.append("");
            else if (i == 0 && j < firstDayInWeek - 1) {
                lst.append("");
            } else {
                lst.append(QString::number(cntr++));
            }
        }                    
        retVal.append(lst);
        if (cntr > selectedPersianDate.MonthTotalDays)
            break;
    }

    return retVal;
}


void qPersianDatePicker::SetSelectedDate(QDate date)
{
    this->_selectedDate = date;
}

QDate qPersianDatePicker::SelectedDate()
{
    return this->_selectedDate;
}

