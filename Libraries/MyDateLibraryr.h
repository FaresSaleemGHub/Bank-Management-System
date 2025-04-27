#pragma once
#include <iostream>
#include <vector>
#include <string>

struct stDate {
    short Year;
    short Month;
    short Day;
};

struct stPeriod {
    stDate StartDate;
    stDate EndDate;
};

enum enCompareDates { Before, Equals, After };

using namespace std;

namespace MyDateLibrary {
    // Utilities
    vector<string> SplitString(string S1, string Delim);
    string ReplaceWordInString(string S1, string StringToReplace, string sReplaceTo);
    string ReadStringDate(string Message);
    bool IsValidDate(stDate Date);  // This function is included
    stDate GetSystemDate();
    void SwapTowDates(stDate& Date1, stDate& Date2);

    // Date Operations
    stDate ConvertStringToStructDate(string Date, string Delimeter = "/");
    string ConvertStructDateToString(stDate Date);
    string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy");
    stDate IncreaseDateByOneDay(stDate& Date);
    stDate DecreaseDateByOneDay(stDate& Date);
    stDate IncreaseDateByXDays(short DaysToAdd, stDate& Date);
    stDate DecreaseDateByXDays(short DaysToSubtract, stDate& Date);
    stDate IncreaseDateByOneMonth(stDate& Date);
    stDate DecreaseDateByOneMonth(stDate& Date);
    stDate IncreaseDateByXMonths(short XMonths, stDate& Date);
    stDate DecreaseDateByXMonths(short XMonths, stDate& Date);
    stDate IncreaseDateByOneYear(stDate& Date);
    stDate DecreaseDateByOneYear(stDate& Date);

    // Date Comparisons
    bool IsDate1BeforeDate2(stDate Date1, stDate Date2);
    bool IsDateEquals(stDate Date1, stDate Date2);
    bool IsDate1AfterDate2(stDate Date1, stDate Date2);
    enCompareDates CompareDates(stDate Date1, stDate Date2);

    // Leap Year & Calendar Functions
    bool IsLeapYear(short year);
    int NumberOfDaysInAMonth(short Year, short Month);
    int NumberOfDaysOfYear(short Year);
    int NumberOfHoursOfYear(short Year);
    int NumberOfMinutesOfYear(short Year);
    int NumberOfSecondsOfYear(short Year);
    void PrintMonthCalender(short Year, short Month);
    void PrintYearCalender();

    // Date Period & Overlap
    bool isOverlapPeriods(stPeriod Period1, stPeriod Period2);
    int CountOverlapDays(stPeriod P1, stPeriod P2);
    bool isDateInPeriod(stDate Date, stPeriod Period);
    short CalcultePeriodLengthInDays(stPeriod Period, bool EncludeEndDate = false);

    // Miscellaneous Functions
    string DayName(short DayOrder_Index);
    string MonthName(short MonthOrder_Index);
    string DayBar();
    string StartSpace();

    // Date Input and Output
    short ReadYear();
    short ReadMonth();
    short ReadDay();
    stDate ReadFullDate();
    stPeriod ReadPeriod();
    void PrintDate(stDate Date);

    // Math Functions for Dates
    stDate IncreaseDateByOneCentury(stDate& Date);
    stDate DecreaseDateByOneCentury(stDate& Date);
    stDate IncreaseDateByOneMillennium(stDate& Date);
    stDate DecreaseDateByOneMillennium(stDate& Date);

    // Conversions
    string ConvertNumberToText(int num);


    string ConvertNumberToText(int num) {
        if (num == 0) {
            return " ";
        }
        if (num >= 1 && num <= 19) {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven", "Eight","Nine","Ten",
                "Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
            return arr[num];
        }
        else if (num >= 20 && num <= 99) {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return arr[num / 10] + " " + ConvertNumberToText(num % 10);
        }
        else if (num >= 100 && num <= 199) {
            return "One Hundred " + ConvertNumberToText(num % 100);
        }
        else if (num >= 200 && num <= 999) {
            return ConvertNumberToText(num / 100) + " Hundreds " + ConvertNumberToText(num % 100);
        }
        else if (num >= 1000 && num <= 1999) {
            return "One Thousand " + ConvertNumberToText(num % 1000);
        }
        else if (num >= 2000 && num <= 999999) {
            return ConvertNumberToText(num / 1000) + " Thousands " + ConvertNumberToText(num % 1000);
        }
        else if (num >= 1000000 && num <= 1999999) {
            return "One Million " + ConvertNumberToText(num % 1000000);
        }
        else if (num >= 2000000 && num <= 999999999) {
            return ConvertNumberToText(num / 1000000) + " Millions " + ConvertNumberToText(num % 1000000);
        }
        else if (num >= 1000000000 && num <= 1999999999) {
            return "One Billion " + ConvertNumberToText(num % 1000000000);
        }
        else {
            return ConvertNumberToText(num / 1000000000) + " Billions " + ConvertNumberToText(num % 1000000000);
        }
    }

    bool IsLeapYear(short year) {
        //إما أنه بيقسم على 400 بدون باقي أو أنه بيقسم على 4 ولا يقبل القسمة على 100 
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }

    int NumberOfDaysOfYear(short Year) {
        return (IsLeapYear(Year)) ? 366 : 365;
    }
    int NumberOfHoursOfYear(short Year) {
        return (NumberOfDaysOfYear(Year) * 24);
    }
    int NumberOfMinutesOfYear(short Year) {
        return (NumberOfHoursOfYear(Year) * 60);
    }
    int NumberOfSecondsOfYear(short Year) {
        return (NumberOfMinutesOfYear(Year) * 60);
    }

    int NumberOfDaysInAMonth(short Year, short Month) {
        if (Month < 0 || Month>12) {
            return 0;
        }

        short arrOfDays[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
        return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arrOfDays[Month];
    }
    int NumberOfHoursOfMonth(short Year, short Month) {
        return (NumberOfDaysInAMonth(Year, Month) * 24);
    }
    int NumberOfMinutesOfMonth(short Year, short Month) {
        return (NumberOfHoursOfMonth(Year, Month) * 60);
    }
    int NumberOfSecondsOfMonth(short Year, short Month) {
        return (NumberOfMinutesOfMonth(Year, Month) * 60);
    }
    short CalculateDayOrderOfDate(short Year, short Month, short Day) {
        short a, y, m;
        a = (14 - Month) / 12;
        y = Year - a;
        m = Month + 12 * a - 2;
        return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }
    short CalculateDayOrderOfDate(stDate Date) {
        //Version 2
        return CalculateDayOrderOfDate(Date.Year, Date.Month, Date.Day);
    }

    string DayName(short DayOrder_Index) {
        string arrDays[] = { "Sunday", "Monday", "Tusday", "Wednesday","Thursday", "Friday","Satarday" };
        return arrDays[DayOrder_Index];
    }

    string MonthName(short MonthOrder_Index) {
        string arrMonths[] = { "", "Gan", "Feb", "Mar", "Apr", "May", "Jou", "Jul", "Oug", "Sep", "Oct", "Nov", "Dec" };
        return arrMonths[MonthOrder_Index];
    }

    string DayBar() {
        return "Sun  Mon  Tue  Wed  Thu  Fri  Sat   ";
    }
    string StartSpace() {
        return "  ";
    }
    short ReadYear() {
        short year = 0;
        cout << "Enter a year? ";
        cin >> year;
        return year;
    }
    short ReadMonth() {
        short month = 0;
        cout << "Enter a month? ";
        cin >> month;
        return month;
    }
    short ReadDay() {
        short day = 0;
        cout << "Enter a day number? ";
        cin >> day;
        return day;
    }
    stDate ReadFullDate() {
        stDate Date;
        Date.Day = ReadDay();
        Date.Month = ReadMonth();
        Date.Year = ReadYear();
        return Date;
    }
    void PrintDate(stDate Date) {
        printf("%d/%2d/%2d", Date.Day, Date.Month, Date.Year);
    }
    void PrintMonthCalender(short Year, short Month) {
        short IndexOfDay = CalculateDayOrderOfDate(Year, Month, 1);
        short LastDayOfMonth = NumberOfDaysInAMonth(Year, Month);
        string NameOfMonth = MonthName(Month);

        cout << "\n" << StartSpace();
        printf("_______________%s_______________\n", NameOfMonth.c_str());
        cout << StartSpace();
        cout << DayBar() << endl;

        short i = 0;
        for (; i < IndexOfDay; i++) {
            printf("     ");
        }

        for (int j = 1; j <= LastDayOfMonth; j++) {
            printf("%5d", j);

            if (++i == 7) {
                printf("\n");
                i = 0;
            }
        }
        cout << endl << StartSpace();
        printf("_________________________________\n");
    }
    void PrintYearCalender() {
        short Year = ReadYear();

        cout << "\n" << StartSpace();
        printf("_________________________________\n");
        cout << "\n" << StartSpace();
        printf("\t\tCalender - %d\n", Year);
        cout << "\n" << StartSpace();
        printf("_________________________________\n");

        for (int i = 1; i <= 12; i++) {
            PrintMonthCalender(Year, i);
            cout << endl;
        }
    }
    short YearDaysUntilDate(short Year, short Month, short Day) {
        short TotalDays = 0;
        for (int i = 1; i < Month; i++) {
            TotalDays += NumberOfDaysInAMonth(Year, i);
        }
        TotalDays += Day;
        return TotalDays;
    }
    stDate GetDateFromYearDays(short NumDays, short Year) {
        stDate Date;
        Date.Year = Year;
        Date.Month = 1;
        short MonthDays = 0;

        while (true) {
            MonthDays = NumberOfDaysInAMonth(Year, Date.Month);
            if (NumDays > MonthDays) {
                NumDays -= MonthDays;
                Date.Month++;
            }
            else {
                Date.Day = NumDays;
                break;
            }
        }
        return Date;
    }
    bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
        return Date1.Year < Date2.Year ? true :
            Date1.Month < Date2.Month ? true :
            Date1.Day < Date2.Day ? true : false;
    }
    bool IsDateEquals(stDate Date1, stDate Date2) {
        return Date1.Year != Date2.Year ? false :
            Date1.Month != Date2.Month ? false :
            Date1.Day != Date2.Day ? false : true;
    }
    bool IsDate1AftereDate2(stDate Date1, stDate Date2) {
        //الفكرة في هاد السؤال عدم إعادة كتابة كود كامل, وتطوير كتابة الكود
        return !IsDate1BeforeDate2(Date1, Date2) && !IsDateEquals(Date1, Date2);
    }
    enCompareDates CompareDates(stDate Date1, stDate Date2) {
        if (IsDate1BeforeDate2(Date1, Date2))
            return enCompareDates::Before;

        if (IsDate1AftereDate2(Date1, Date2)) {
            return enCompareDates::After;
        }
        return enCompareDates::Equals;
    }
    stPeriod ReadPeriod() {
        stPeriod Period;
        cout << "Enter Start Date of this period:\n";
        Period.StartDate = ReadFullDate();
        cout << "\nEnter End Date this period:\n";
        Period.EndDate = ReadFullDate();
        cout << endl;
        return Period;
    }
    bool isOverlapPeriods(stPeriod Period1, stPeriod Period2) {
        if (
            CompareDates(Period2.EndDate, Period1.StartDate) == enCompareDates::Before ||
            CompareDates(Period2.StartDate, Period1.EndDate) == enCompareDates::After)
            return false;
        return true;
    }
    short CalcultePeriodLengthInDays(stPeriod Period, bool EncludeEndDate = false) {
        return DefferenceBetweenTowDatesInDays(Period.StartDate, Period.EndDate, EncludeEndDate);
    }
    bool isDateInPeriod(stDate Date, stPeriod Period) {
        // بالتحقق من أنه واقع خارج الفترة
        return !(IsDate1BeforeDate2(Date, Period.StartDate) || IsDate1AftereDate2(Date, Period.EndDate));
    }

    bool IsLastMonthInAYear(short Month) {
        return Month == 12;
    }
    int CountOverlapDays(stPeriod P1, stPeriod P2) {
        //تم فهمها بعد طلع الروح, بالرسم تُفهم مباشرة.
        int Period1Length = CalcultePeriodLengthInDays(P1, true);
        int Period2Length = CalcultePeriodLengthInDays(P2, true);
        int OverlapDays = 0;

        if (!isOverlapPeriods(P1, P2))
            return 0;

        if (Period1Length < Period2Length) {
            while (IsDate1BeforeDate2(P1.StartDate, P1.EndDate)) {
                if (isDateInPeriod(P1.StartDate, P2)) {
                    OverlapDays++;
                }
                P1.StartDate = IncreaseDateByOneDay(P1.StartDate);
            }
        }
        else {
            while (IsDate1BeforeDate2(P2.StartDate, P2.EndDate)) {
                if (isDateInPeriod(P2.StartDate, P1)) {
                    OverlapDays++;
                }
                P2.StartDate = IncreaseDateByOneDay(P2.StartDate);
            }
        }
        return OverlapDays;
    }
    string ReadStringDate(string Message) {
        string StringDate;
        cout << Message;
        getline(cin >> ws, StringDate);
        return StringDate;
    }
    bool IsValidDate(stDate Date) {
        if (Date.Month > 0 && Date.Month <= 12) {
            short Days = NumberOfDaysInAMonth(Date.Year, Date.Month);
            if (Date.Day >= 1 && Date.Day <= Days) {
                return true;
            }
        }
        return false;
    }
    vector<string> SplitString(string S1, string Delim) {
        vector<string> vString;
        short pos = 0;
        string sWord;
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos);
            if (sWord != "")
            {
                vString.push_back(sWord);
            }
            S1.erase(0, pos + Delim.length());
        }
        if (S1 != "") {
            vString.push_back(S1);
        }
        return vString;
    }
    string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo) {
        short pos = S1.find(StringToReplace);
        while (pos != std::string::npos) {
            S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
            pos = S1.find(StringToReplace);//find next    
        } return S1;
    }
    stDate ConvertStringToStructDate(string Date, string Delimeter = "/") {
        stDate sDate;
        vector <string> vDate;

        vDate = SplitString(Date, Delimeter);
        sDate.Day = stoi(vDate[0]);
        sDate.Month = stoi(vDate[1]);
        sDate.Year = stoi(vDate[2]);

        return sDate;
    }
    string ConvertStructDateToString(stDate Date) {
        return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }
    string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy") {
        string FormattedDateString = "";
        FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
        FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
        FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));
        return FormattedDateString;
    }
    bool IsLastDayInAMonth(stDate Date) {
        return NumberOfDaysInAMonth(Date.Year, Date.Month) == Date.Day;
    }
    bool IsFirstDayInAMonth(stDate Date) {
        return Date.Day == 1;
    }
    void SwapTowDates(stDate& Date1, stDate& Date2) {
        stDate TempDate;
        TempDate.Year = Date1.Year;
        TempDate.Month = Date1.Month;
        TempDate.Day = Date1.Day;

        Date1.Year = Date2.Year;
        Date1.Month = Date2.Month;
        Date1.Day = Date2.Day;

        Date2.Year = TempDate.Year;
        Date2.Month = TempDate.Month;
        Date2.Day = TempDate.Day;
    }
    stDate IncreaseDateByOneDay(stDate& Date) {
        if (IsLastDayInAMonth(Date)) {
            if (IsLastMonthInAYear(Date.Month)) {
                Date.Day = 1;
                Date.Month = 1;
                Date.Year++;
            }
            else {
                Date.Day = 1;
                Date.Month++;
            }
        }
        else {
            Date.Day++;
        }
        return Date;
    }
    stDate DecreaseDateByOneDay(stDate& Date) {
        if (Date.Day == 1) {
            if (Date.Month == 1) {
                Date.Year--;
                Date.Month = 12;
                Date.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);
            }
            else {
                Date.Month--;
                Date.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);
            }
        }
        else {
            Date.Day--;
        }
        return Date;
    }

    short DefferenceBetweenTowDatesInDays(stDate, stDate, bool);
    stDate GetSystemDate();

    stDate IncreaseDateByXDays(short DaysToAdd, stDate& Date) {
        while (DaysToAdd > 0) {
            IncreaseDateByOneDay(Date);
            DaysToAdd--;
        }
        return Date;
    }
    stDate DecreaseDateByXDays(short DaysToSubtract, stDate& Date) {
        while (DaysToSubtract > 0) {
            DecreaseDateByOneDay(Date);
            DaysToSubtract--;
        }
        return Date;
    }
    stDate IncreaseDateByOneWeek(stDate& Date) {
        IncreaseDateByXDays(7, Date);
        return Date;
    }
    stDate DecreaseDateByOneWeek(stDate& Date) {
        DecreaseDateByXDays(7, Date);
        return Date;
    }
    stDate IncreaseDateByXWeeks(short WeeksToAdd, stDate& Date) {
        IncreaseDateByXDays(7 * WeeksToAdd, Date);
        return Date;
    }
    stDate DecreaseDateByXWeeks(short WeeksToSubtract, stDate& Date) {
        DecreaseDateByXDays(7 * WeeksToSubtract, Date);
        return Date;
    }
    stDate IncreaseDateByOneMonth(stDate& Date) {
        if (Date.Month < 12) {
            Date.Month++;
        }
        else {
            Date.Month = 1;
            Date.Year++;
        }

        short NumDaysOfMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
        if (Date.Day > NumDaysOfMonth) {
            Date.Day = NumDaysOfMonth;
            //هذا الشرط لراعاة مسألة آخر يوم في الشهور, كي لا تكون النتائج خاطئة عند التعديل على الشهور ذاتها
        }

        return Date;
    }
    void CheckDayOfDate(stDate& Date) {
        short NumDaysOfMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
        if (Date.Day > NumDaysOfMonth) {
            Date.Day = NumDaysOfMonth;
            //هذا الشرط لراعاة مسألة آخر يوم في الشهور, كي لا تكون النتائج خاطئة عند التعديل على الشهور ذاتها
        }
    }
    stDate DecreaseDateByOneMonth(stDate& Date) {
        if (Date.Month > 1) {
            Date.Month--;
        }
        else {
            Date.Month = 12;
            Date.Year--;
        }
        CheckDayOfDate(Date);
        return Date;
    }
    stDate IncreaseDateByXMonths(short XMonths, stDate& Date) {
        while (XMonths > 0) {
            IncreaseDateByOneMonth(Date);
            XMonths--;
        }
        return Date;
    }
    stDate DecreaseDateByXMonths(short XMonths, stDate& Date) {
        while (XMonths > 0) {
            DecreaseDateByOneMonth(Date);
            XMonths--;
        }
        return Date;
    }
    stDate IncreaseDateByOneYear(stDate& Date) {
        Date.Year++;
        CheckDayOfDate(Date);//for Month 2
        return Date;
    }
    stDate DecreaseDateByOneYear(stDate& Date) {
        Date.Year--;
        CheckDayOfDate(Date);//for Month 2
        return Date;
    }
    stDate IncreaseDateByXYears(short YearsToAdd, stDate& Date) {
        while (YearsToAdd > 0)
        {
            IncreaseDateByOneYear(Date);
            YearsToAdd--;
        }
        CheckDayOfDate(Date);
        return Date;
    }
    stDate DecreaseDateByXYears(short YearsToSubtract, stDate& Date) {
        while (YearsToSubtract > 0)
        {
            DecreaseDateByOneYear(Date);
            YearsToSubtract--;
        }
        CheckDayOfDate(Date);
        return Date;
    }
    stDate IncreaseDateByXYearsFaster(short YearsToAdd, stDate& Date) {
        Date.Year += YearsToAdd;
        CheckDayOfDate(Date);
        return Date;
    }
    stDate DecreaseDateByXYearsFaster(short YearsToSubtract, stDate& Date) {
        Date.Year -= YearsToSubtract;
        CheckDayOfDate(Date);
        return Date;
    }
    stDate IncreaseDateByOneDecade(stDate& Date) {
        Date.Year += 10;
        CheckDayOfDate(Date);
        return Date;
    }
    stDate DecreaseDateByOneDecade(stDate& Date) {
        Date.Year -= 10;
        CheckDayOfDate(Date);
        return Date;
    }
    stDate IncreaseDateByXDecades(short DecadesToAdd, stDate& Date) {
        while (DecadesToAdd > 0) {
            IncreaseDateByOneDecade(Date);
            DecadesToAdd--;
        }
        return Date;
    }
    stDate DecreaseDateByXDecades(short DecadesToSubtract, stDate& Date) {
        while (DecadesToSubtract > 0) {
            DecreaseDateByOneDecade(Date);
            DecadesToSubtract--;
        }
        return Date;
    }
    stDate IncreaseDateByXDecadesFaster(short DecadesToAdd, stDate& Date) {
        Date.Year += (DecadesToAdd * 10);
        CheckDayOfDate(Date);
        return Date;
    }
    stDate DecreaseDateByXDecadesFaster(short DecadesToSubtract, stDate& Date) {
        Date.Year -= (DecadesToSubtract * 10);
        CheckDayOfDate(Date);
        return Date;
    }
    stDate IncreaseDateByOneCentury(stDate& Date) {
        Date.Year += 100;
        CheckDayOfDate(Date);
        return Date;
    }
    stDate DecreaseDateByOneCentury(stDate& Date) {
        Date.Year -= 100;
        CheckDayOfDate(Date);
        return Date;
    }
    stDate IncreaseDateByOneMillennium(stDate& Date) {
        Date.Year += 1000;
        CheckDayOfDate(Date);
        return Date;
    }
    stDate DecreaseDateByOneMillennium(stDate& Date) {
        Date.Year -= 1000;
        CheckDayOfDate(Date);
        return Date;
    }
    bool IsEndOfWeek(stDate Date) {
        return CalculateDayOrderOfDate(Date) == 6;
    }
    bool IsWeekend(stDate Date) {
        //Weekend: fri, Sat.
        short DayIndex = CalculateDayOrderOfDate(Date);
        return (DayIndex == 5 || DayIndex == 6);
    }
    bool IsBusinessDay(stDate Date) {
        return !IsWeekend(Date);
    }
    short DaysUntillEndOfWeek(stDate Date) {
        return 6 - CalculateDayOrderOfDate(Date);
    }
    short DaysUntillEndOfMonth(stDate Date) {
        return NumberOfDaysInAMonth(Date.Year, Date.Month) - Date.Day;
    }
    short DaysUntillEndOfYear(stDate Date) {
        stDate EndDate;
        EndDate.Day = 31;
        EndDate.Month = 12;
        EndDate.Year = Date.Year;

        return DefferenceBetweenTowDatesInDays(Date, EndDate, true);
    }
    short VacationPeriodInDays(stDate FromDate, stDate ToDate) {
        short ActualVacationDays = 0;
        while (IsDate1BeforeDate2(FromDate, ToDate)) {
            if (IsBusinessDay(FromDate)) {
                ActualVacationDays++;
            }
            IncreaseDateByOneDay(FromDate);
        }
        return ActualVacationDays;
    }
    stDate VacationReturnDate(stDate StartDate, short VacationDays) {
        while (VacationDays > 0) {
            if (IsBusinessDay(StartDate)) {
                VacationDays--;
            }
            IncreaseDateByOneDay(StartDate);
        }
        return StartDate;
    }
    stDate GetSystemDate() {
        stDate Date;
        time_t t = time(0);
        tm now;
        localtime_s(&now, &t);
        Date.Year = now.tm_year + 1900;
        Date.Month = now.tm_mon + 1;
        Date.Day = now.tm_mday;

        return Date;
    }
    short DefferenceBetweenTowDatesInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) {
        short Days = 0;
        short FlagValue = 1;
        if (!IsDate1BeforeDate2(Date1, Date2)) {
            SwapTowDates(Date1, Date2);
            FlagValue = -1;
        }
        while (IsDate1BeforeDate2(Date1, Date2)) {
            Days++;
            Date1 = IncreaseDateByOneDay(Date1);
        }
        return IncludeEndDay ? ++Days * FlagValue : Days * FlagValue;
    }
}