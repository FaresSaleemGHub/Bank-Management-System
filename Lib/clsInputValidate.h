#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

template <typename T>
class clsInputValidate {

public:
	static bool IsTNumberBetween(T Number, T From, T To) {
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}

	static T ReadTNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static T ReadTNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		T Number = ReadTNumber();

		while (!IsTNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadTNumber();
		}
		return Number;
	}

	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}

	static string ReadLineInput()
	{
		string S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}
};

