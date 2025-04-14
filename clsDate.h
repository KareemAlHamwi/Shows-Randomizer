#pragma once
#include <iostream>
#include <vector>

#include "clsString.h"
using namespace std;

class clsDate {
   private:
    short day = 1, month = 1, year = 1900;

   public:
    enum enDateCompare {
        before = -1,
        equal = 0,
        after = 1
    };

    clsDate() {
        time_t t = time(0);
        tm *now = localtime(&t);

        year = now->tm_year + 1900;
        month = now->tm_mon + 1;
        day = now->tm_mday;
    };

    clsDate(string formate) {
        vector<string> vDate = clsString::split(formate, "/");

        day = stoi(vDate[0]);
        month = stoi(vDate[1]);
        year = stoi(vDate[2]);
    };

    clsDate(short day, short month, short year) {
        this->day = day;
        this->month = month;
        this->year = year;
    };

    clsDate(short totalDays, short year) {
        clsDate date = totalDaysToDate(totalDays, year);
        this->day = date.day;
        this->month = date.month;
        this->year = date.year;
    };

    void print() {
        cout << dateToString() << endl;
    }

    static string dateToString(clsDate date) {
        return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
    }

    string dateToString() {
        return dateToString(*this);
    }

    string replaceWordInString(string line, string StringToReplace, string ReplaceTo) {
        size_t pos = line.find(StringToReplace);

        while (pos != std::string::npos) {
            line = line.replace(pos, StringToReplace.length(), ReplaceTo);
            pos = line.find(StringToReplace);
        }

        return line;
    }

    static string readStrDate() {
        string strDate;

        cout << "Enter date dd/mm/yyyy? ";
        getline(cin >> ws, strDate);

        return strDate;
    }

    clsDate stringToDate(string formate) {
        vector<string> vDate = clsString::split(formate, "/");
        clsDate date;

        date.day = stoi(vDate.at(0));
        date.month = stoi(vDate.at(1));
        date.year = stoi(vDate.at(2));

        return date;
    }

    string formateDate(clsDate date, string formate = "dd-mm-yyyy") {
        string formattedStrDate = "";

        formattedStrDate = replaceWordInString(formate, "dd", to_string(date.day));
        formattedStrDate = replaceWordInString(formattedStrDate, "mm", to_string(date.month));
        formattedStrDate = replaceWordInString(formattedStrDate, "yyyy", to_string(date.year));

        return formattedStrDate;
    }

    static clsDate readDate() {
        clsDate date;

        cout << "Enter day? ";
        cin >> date.day;
        cout << "Enter month? ";
        cin >> date.month;
        cout << "Enter year? ";
        cin >> date.year;

        return date;
    }

    static bool isLeapYear(short year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool isLeapYear() {
        return isLeapYear(year);
    }

    static short numberOfDaysInYear(short year) {
        return isLeapYear(year) ? 365 : 364;
    }

    short numberOfDaysInYear() {
        return numberOfDaysInYear(year);
    }

    static short numberOfHoursInYear(short year) {
        return numberOfDaysInYear(year) * 24;
    }

    short numberOfHoursInYear() {
        return numberOfHoursInYear(year);
    }

    static int numberOfMinutesInYear(short year) {
        return numberOfHoursInYear(year) * 60;
    }

    int numberOfMinutesInYear() {
        return numberOfMinutesInYear(year);
    }

    static int numberOfSecondsInYear(short year) {
        return numberOfMinutesInYear(year) * 60;
    }

    int numberOfSecondsInYear() {
        return numberOfSecondsInYear();
    }

    static short numberOfDaysInMonth(short month, short year) {
        if (month < 1 || month > 12)
            return 0;

        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return (month == 2) ? (isLeapYear(year) ? 29 : 28) : days[month - 1];
    }

    short numberOfDaysInMonth() {
        return numberOfDaysInMonth(month, year);
    }

    static short numberOfHoursInMonth(short month, short year) {
        return numberOfDaysInMonth(month, year) * 24;
    }

    short numberOfHoursInMonth() {
        return numberOfDaysInMonth(month, year) * 24;
    }

    static int numberOfMinutesInMonth(short month, short year) {
        return numberOfHoursInMonth(month, year) * 60;
    }

    int numberOfMinutesInMonth() {
        return numberOfHoursInMonth(month, year) * 60;
    }

    static int numberOfSecondsInMonth(short month, short year) {
        return numberOfMinutesInMonth(month, year) * 60;
    }

    int numberOfSecondsInMonth() {
        return numberOfMinutesInMonth(month, year) * 60;
    }

    static bool isLastDayInMonth(clsDate date) {
        return date.day == numberOfDaysInMonth(date.month, date.year);
    }

    static bool isLastMonthInYear(clsDate date) {
        return date.month == 12;
    }

    static bool isValidDate(clsDate date) {
        if (date.day > 31 || date.day < 1)
            return false;

        if (date.month > 12 || date.month < 1)
            return false;

        if (date.month == 2) {
            if (isLeapYear(date.year)) {
                if (date.day > 29)
                    return false;
            } else if (date.day > 28)
                return false;
        }

        if (date.day > numberOfDaysInMonth(date.month, date.year))
            return false;

        return true;
    }

    bool isValid() {
        return isValidDate(*this);
    }

    static short dayOfWeekOrder(short day, short month, short year) {
        short a, y, m;

        a = (14 - month) / 12;
        y = year - a;
        m = month + (12 * a) - 2;

        return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    static short dayOfWeekOrder(clsDate date) {
        return dayOfWeekOrder(date.day, date.month, date.year);
    }

    static string dayShortName(short dayOfWeekOrder) {
        string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        return arrDayNames[dayOfWeekOrder];
    }

    static string monthShortName(short monthNumber) {
        string months[12] = {"Jan", "Feb", "Mar",
                             "Apr", "May", "Jun",
                             "Jul", "Aug", "Sep",
                             "Oct", "Nov", "Dec"};

        return (months[monthNumber - 1]);
    }

    string monthShortName() {
        return monthShortName(month);
    }

    static void printMonthCalendar(short month, short year) {
        int numberOfDays;

        // Index of the day from 0 to 6
        int current = dayOfWeekOrder(1, month, year);

        numberOfDays = numberOfDaysInMonth(month, year);

        // Print the current month name
        printf("\n  _______________%s_______________\n\n",
               monthShortName(month).c_str());

        // Print the columns
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print appropriate spaces
        int i;
        for (i = 0; i < current; i++)
            printf("     ");

        for (int j = 1; j <= numberOfDays; j++) {
            printf("%5d", j);

            if (++i == 7) {
                i = 0;
                printf("\n");
            }
        }

        printf("\n  _________________________________\n");
    }

    void printMonthCalendar() {
        printMonthCalendar(month, year);
    }

    static void printYearCalendar(int Year) {
        printf("\n  _________________________________\n\n");
        printf("           Calendar - %d\n", Year);
        printf("  _________________________________\n");

        for (int i = 1; i <= 12; i++) {
            printMonthCalendar(i, Year);
        }
    }

    void printYearCalendar() {
        printf("\n  _________________________________\n\n");
        printf("           Calendar - %d\n", year);
        printf("  _________________________________\n");

        for (int i = 1; i <= 12; i++) {
            printMonthCalendar(i, year);
        }
    }

    static bool isDatesEqual(clsDate date1, clsDate date2) {
        return (date1.year == date2.year) && (date1.month == date2.month) && (date1.day == date2.day);
    }

    bool isDateEqualTo(clsDate date) {
        return isDatesEqual(*this,date);
    }

    static bool isDate1BeforeDate2(clsDate date1, clsDate date2) {
        return (date1.year < date2.year) ? true
                                         : ((date1.year == date2.year) ? (date1.month < date2.month ? true
                                                                                                    : (date1.month == date2.month ? date1.day < date2.day : false))
                                                                       : false);
    }

    bool isDateBefore(clsDate date) {
        return isDate1BeforeDate2(*this,date);
    }

    static bool isDate1AfterDate2(clsDate date1, clsDate date2) {
        return (!isDate1BeforeDate2(date1, date2) && !isDatesEqual(date1, date2));
    }

    bool isDateAfter(clsDate date) {
        return isDate1AfterDate2(*this, date);
    }

    //? make non static funcs for the object itself
    //? *********************************************************

    static clsDate addOneDay(clsDate date) {
        if (isLastDayInMonth(date)) {
            if (isLastMonthInYear(date)) {
                date.day = 1;
                date.month = 1;
                date.year++;
            } else {
                date.day = 1;
                date.month++;
            }
        } else {
            date.day++;
        }

        return date;
    }

    void addOneDay() {
        *this = addOneDay(*this);
    }

    static clsDate increaseDateByXDays(short days, clsDate date) {
        for (short i = 1; i <= days; i++) {
            date = addOneDay(date);
        }

        return date;
    }

    static clsDate increaseDateByOneWeek(clsDate date) {
        for (short i = 0; i < 7; i++) {
            date = addOneDay(date);
        }

        return date;
    }

    static clsDate increaseDateByXWeeks(short weeks, clsDate date) {
        for (short i = 1; i <= weeks; i++) {
            date = increaseDateByOneWeek(date);
        }

        return date;
    }

    static clsDate increaseDateByOneMonth(clsDate date) {
        if (date.month == 12) {
            date.month = 1;
            date.year++;
        } else {
            date.month++;
        }

        if (date.day > numberOfDaysInMonth(date.month, date.year)) {
            date.day = numberOfDaysInMonth(date.month, date.year);
        }

        return date;
    }

    static clsDate increaseDateByXMonths(short months, clsDate date) {
        for (short i = 1; i <= months; i++) {
            date = increaseDateByOneMonth(date);
        }

        return date;
    }

    static clsDate increaseDateByOneYear(clsDate date) {
        date.year++;

        return date;
    }

    static clsDate increaseDateByXYears(short years, clsDate date) {
        date.year += years;
        return date;
    }

    static clsDate increaseDateByOneDecade(clsDate &date) {
        date.year += 10;
        return date;
    }

    static clsDate increaseDateByXDecades(short decades, clsDate date) {
        date.year += (decades * 10);
        return date;
    }

    static clsDate increaseDateByOneCentury(clsDate date) {
        date.year += 100;
        return date;
    }

    static clsDate increaseDateByOneMillennium(clsDate date) {
        date.year += 1000;
        return date;
    }

    static clsDate decreaseDateByOneDay(clsDate date) {
        if (date.day == 1) {
            if (date.month == 1) {
                date.day = 31;
                date.month = 12;
                date.year--;
            } else {
                date.month--;
                date.day = numberOfDaysInMonth(date.month, date.year);
            }
        } else {
            date.day--;
        }

        return date;
    }

    static clsDate decreaseDateByXDays(short days, clsDate date) {
        for (short i = 1; i <= days; i++) {
            date = decreaseDateByOneDay(date);
        }

        return date;
    }

    static clsDate decreaseDateByOneWeek(clsDate date) {
        for (short i = 0; i < 7; i++) {
            date = decreaseDateByOneDay(date);
        }

        return date;
    }

    static clsDate decreaseDateByXWeeks(short weeks, clsDate date) {
        for (short i = 1; i <= weeks; i++) {
            date = decreaseDateByOneWeek(date);
        }

        return date;
    }

    static clsDate decreaseDateByOneMonth(clsDate date) {
        if (date.month == 1) {
            date.month = 12;
            date.year--;
        } else {
            date.month--;
        }

        if (date.day > numberOfDaysInMonth(date.month, date.year)) {
            date.day = numberOfDaysInMonth(date.month, date.year);
        }

        return date;
    }

    static clsDate decreaseDateByXMonths(short months, clsDate date) {
        for (short i = 1; i <= months; i++) {
            date = decreaseDateByOneMonth(date);
        }

        return date;
    }

    static clsDate decreaseDateByOneYear(clsDate date) {
        date.year--;

        return date;
    }

    static clsDate decreaseDateByXYears(short years, clsDate date) {
        date.year -= years;
        return date;
    }

    static clsDate decreaseDateByOneDecade(clsDate date) {
        date.year -= 10;
        return date;
    }

    static clsDate decreaseDateByXDecades(short decades, clsDate date) {
        date.year -= (decades * 10);
        return date;
    }

    static clsDate decreaseDateByOneCentury(clsDate date) {
        date.year -= 100;
        return date;
    }

    static clsDate decreaseDateByOneMillennium(clsDate date) {
        date.year -= 1000;
        return date;
    }

    //? *********************************************************

    static void swapDates(clsDate &date1, clsDate &date2) {
        clsDate tempDate;

        tempDate = date1;
        date1 = date2;
        date2 = tempDate;
    }

    static int differenceBetweenDate1AndDate2(clsDate date1, clsDate date2, bool includeLastDay = false) {
        int difference = 0;
        short swapFlagValue = 1;

        if (!isDate1BeforeDate2(date1, date2)) {
            swapDates(date1, date2);
            swapFlagValue = -1;
        }

        while (isDate1BeforeDate2(date1, date2)) {
            date1 = addOneDay(date1);
            difference++;
        }

        return includeLastDay ? ++difference * swapFlagValue : difference * swapFlagValue;
    }

    static short calculateAgeInDays(clsDate birthDate) {
        return differenceBetweenDate1AndDate2(birthDate,getSystemDate(),true);
    }

    static int dateTotalDays(clsDate date) {
        int totalDays;

        for (int i = 0; i < date.month; i++) {
            totalDays += numberOfDaysInMonth(i, date.year);
        }

        return totalDays += date.day;
    }

    int dateToTotalDays() {
        return dateTotalDays(*this);
    }

    static clsDate totalDaysToDate(short totalDays, short year) {
        clsDate date;
        short remainingDays = totalDays;
        short monthDays = 0;

        date.year = year;
        date.month = 1;

        while (true) {
            monthDays = numberOfDaysInMonth(date.month, year);

            if (remainingDays > monthDays) {
                remainingDays -= monthDays;
                date.month++;
            } else {
                date.day = remainingDays;
                break;
            }
        }

        return date;
    }

    static clsDate getSystemDate() {
        clsDate date;

        time_t t = time(0);
        tm *now = localtime(&t);

        date.year = now->tm_year + 1900;
        date.month = now->tm_mon + 1;
        date.day = now->tm_mday;

        return date;
    }

    static string getSystemTime() {
		time_t t = time(0);
		tm* now = localtime(&t);

		short Hours, Minutes, Seconds;

		Hours = now->tm_hour;
		Minutes = now->tm_min;
		Seconds = now->tm_sec;

		return to_string(Hours) + ":" + to_string(Minutes) + ":" + to_string(Seconds);
	}

    static string getSystemDateTimeString() {
        return dateToString(getSystemDate()) + " - " + getSystemTime();
    }

    static bool isEndOfWeek(clsDate date) {
        return dayOfWeekOrder(date) == 6;
    }

    bool isEndOfWeek() {
        return isEndOfWeek(*this);
    }

    static bool isWeekend(clsDate date) {
        short dayIndex = dayOfWeekOrder(date);
        return (dayIndex == 5) || (dayIndex == 6);
    }

    bool isWeekend() {
        return isWeekend(*this);
    }

    static bool isBusinessDay(clsDate date) {
        return !isWeekend(date);
    }

    bool isBusinessDay() {
        return isBusinessDay(*this);
    }

    static short daysUntilEndOfWeek(clsDate date) {
        return 6 - dayOfWeekOrder(date);
    }

    short daysUntilEndOfWeek() {
        return daysUntilEndOfWeek(*this);
    }

    static short daysUntilEndOfMonth(clsDate date) {
        return (numberOfDaysInMonth(date.month, date.year) + 1) - date.day;
    }

    short daysUntilEndOfMonth() {
        return daysUntilEndOfMonth(*this);
    }

    static short daysUntilEndOfYear(clsDate date) {
        clsDate endOfYearDate;
        endOfYearDate.day = 31;
        endOfYearDate.month = 12;
        endOfYearDate.year = date.year;

        return differenceBetweenDate1AndDate2(date, endOfYearDate, true);
    }

    short daysUntilEndOfYear() {
        return daysUntilEndOfYear(*this);
    }

    int getVacationDays(clsDate dateFrom, clsDate dateTo) {
        short actualVacationDays = 0;

        while (isDate1BeforeDate2(dateFrom, dateTo)) {
            if (isBusinessDay(dateFrom))
                actualVacationDays++;

            dateFrom = addOneDay(dateFrom);
        }

        return actualVacationDays;
    }

    clsDate getVacationDate(clsDate dateFrom, int actualVacationDays) {
        short weekendCounter = 0;

        while (isWeekend(dateFrom))
            dateFrom = addOneDay(dateFrom);

        for (short i = 1; i <= actualVacationDays + weekendCounter; i++) {
            if (isWeekend(dateFrom)) {
                weekendCounter++;
            }

            dateFrom = addOneDay(dateFrom);
        }

        while (isWeekend(dateFrom))
            dateFrom = addOneDay(dateFrom);

        return dateFrom;
    }

    static enDateCompare compareDates(clsDate date1, clsDate date2) {
        if (isDate1BeforeDate2(date1, date2))
            return enDateCompare::before;
        else if (isDatesEqual(date1, date2))
            return enDateCompare::equal;

        return enDateCompare::after;
    }

    enDateCompare compareDates(clsDate date) {
        return compareDates(*this,date);
    }
};