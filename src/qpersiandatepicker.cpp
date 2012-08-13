#include "qpersiandatepicker.h"

qPersianDatePicker::qPersianDatePicker(QWidget *parent, QDate *date) :
    QWidget(parent)
{
    SetCalendarWeekNameList(QStringList());
    SetCalendarMonthNameList(QStringList());

    SetCalendarWeekNameStyle();
    SetCalendarDayStyle();
    SetCalendarHolidayStyle();
    SetCalendarTodayStyle();

    if (date != 0) this->SetSelectedDate(*date);
    else this->SetSelectedDate(QDate::currentDate());

    InitWidget();
}

void qPersianDatePicker::InitWidget()
{
    QVBoxLayout *widgetLayout = new QVBoxLayout();

    QGridLayout *monthLayout = new QGridLayout();
    monthLayout->setSpacing(2);

    QLabel *lbl;

    //=== Loading Calendar Header.
    for (int i = 0; i < _calendarWeekNameList.length(); ++i) {

        lbl = new QLabel(_calendarWeekNameList[6-i]);
        lbl->setAlignment(Qt::AlignCenter);
        lbl->setStyleSheet(_calendarWeekNameStyle);
        lbl->setFixedSize(25, 25);
        monthLayout->addWidget(lbl, 0, i);
    }

    //=== Loading Calendar Days.

    PersianDate pSelectedDay = PersianDateUtil::GerigorianToPersian(SelectedDate());
    PersianDate pToday = PersianDateUtil::GerigorianToPersian(QDate::currentDate());

    QVector<QStringList> calendar = LoadCalendar(pSelectedDay);

    for (int i = 0; i < calendar.count(); ++i) {
        for (int j = 0; j < calendar.at(i).length(); ++j) {

            lbl = new QLabel(calendar.at(i).at(j));
            lbl->setAlignment(Qt::AlignCenter);
            if ( pSelectedDay.Month == pToday.Month && calendar[i][j] == QString::number(pSelectedDay.Day))
                lbl->setStyleSheet(_calendarTodayStyle);
            else
                lbl->setStyleSheet(_calendarDayStyle);
            lbl->setFixedSize(25, 25);
            lbl->setCursor(Qt::PointingHandCursor);
            monthLayout->addWidget(lbl, i + 1, 6 - j);
        }
    }

    QLabel *lblTitle = new QLabel();
    lblTitle->setAlignment(Qt::AlignCenter);
    lblTitle->setText(this->_calendarMonthNameList[pSelectedDay.Month - 1]);


    widgetLayout->addWidget(lblTitle);
    widgetLayout->addLayout(monthLayout);
    this->setLayout(widgetLayout);
}

void qPersianDatePicker::SetCalendarWeekNameList(QStringList names)
{
    if (names.count() == 0) {
        this->_calendarWeekNameList << QString::fromUtf8("ش") << QString::fromUtf8("۱ش") << QString::fromUtf8("۲ش")
                                    << QString::fromUtf8("۳ش") << QString::fromUtf8("۴ش") << QString::fromUtf8("۵ش")
                                    << QString::fromUtf8("ج");
    } else {
        _calendarWeekNameList.clear();
        for (int i = 0; i < names.length(); ++i) {
            _calendarWeekNameList.append(names[i]);

        }
    }
}
void qPersianDatePicker::SetCalendarMonthNameList(QStringList monthNames)
{
    if (monthNames.count() == 0)
        this->_calendarMonthNameList << QString::fromUtf8("فروردین") << QString::fromUtf8("اردیبهشت")  << QString::fromUtf8("خرداد")
                                     << QString::fromUtf8("تیر") << QString::fromUtf8("مرداد") << QString::fromUtf8("شهریور")
                                     << QString::fromUtf8("مهر") << QString::fromUtf8("آبان") << QString::fromUtf8("آذر")
                                     << QString::fromUtf8("دی") << QString::fromUtf8("بهمن") << QString::fromUtf8("اسفند");
    else {
        _calendarMonthNameList.clear();
        _calendarWeekNameList = monthNames;
    }

}

void qPersianDatePicker::SetCalendarWeekNameStyle(QString style)
{
    _calendarWeekNameStyle =
            "border: 1px solid #000000; "
            "border-radius: 10px; "
            "font: 9pt 'B Homa'; "
            "background-color: #0088FF; "
            "color: #FFFFFF;";

    if (style.trimmed() != "")
        _calendarWeekNameStyle = style;
}
void qPersianDatePicker::SetCalendarDayStyle(QString style)
{
    _calendarDayStyle = "border: 1px solid #000000; border-radius: 9px; font: 9pt 'B Homa';";

    if ( style.trimmed() != "" )
        _calendarDayStyle = style;    
}
void qPersianDatePicker::SetCalendarHolidayStyle(QString style)
{
    _calendarHolidayStyle = "border: 1px solid #000000; border-radius: 9px; font: 9pt 'B Homa'; color: #FF0000";

    if ( style.trimmed() != "" )
        _calendarHolidayStyle = style;
}
void qPersianDatePicker::SetCalendarTodayStyle(QString style)
{
    _calendarTodayStyle = "border: 1px solid #000000; border-radius: 9px; font: 9pt 'B Homa'; color: #000000; background-color: #FEFF80;";
    if ( style.trimmed() != "" )
        _calendarTodayStyle = style;
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

