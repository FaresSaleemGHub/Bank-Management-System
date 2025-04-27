#pragma once
#include<iostream>
#include <cstdlib> // for rand()
#include <cmath>   // for round()
#include <string>
using namespace std;

enum enPrimeOrNot { Prime, NotPrime };

namespace MyMathLibrary{
	int RandomNumber(int From, int To) {
		//Function To Generate A Random Number
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}
	enPrimeOrNot CheckPrime(int num) {
		if (num <= 1) return enPrimeOrNot::NotPrime;
		if (num == 2) return enPrimeOrNot::Prime;

		for (int i = 3; i <= round(num / 2); i++) {
			if (num % i == 0)
				return enPrimeOrNot::NotPrime;
		}
		return enPrimeOrNot::Prime;
	}
	void PrintAllPrimeNumbersFrom1ToN(int num) {
		cout << "All Prime Numbers From 1  To " << num << ":\n";
		for (int i = 1; i <= num; i++) {
			if (CheckPrime(i) == enPrimeOrNot::Prime)
				cout << i << endl;
		}
	}
	bool IsPerfectNumber(int num) {
		//أن تكون مجموع الأعداد التي تقبل القسمة على الرقم حتى 0 == الرقم نفسه
		int SumDevisors = 0;
		for (int i = 1; i < num; i++) {
			if (num % i == 0) {
				SumDevisors += i;
			}
		}
		return SumDevisors == num;
	}
	void PrintAllPerfectNumbersFrom1ToN(int n) {
		for (int i = 1; i <= n; i++) {
			if (IsPerfectNumber(i)) {
				cout << i << endl;
			}
		}
	}
	void PrintDigitsOfNumber(int num) {
		while (num > 0) {
			cout << num % 10 << endl;
			num /= 10;
		}
	}
	int SumDigitsOfNumber(int num) {
		int sum = 0;
		while (num > 0) {
			cout << num % 10 << endl;
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}
	int ReverseNumber(int num) {
		int ReversedNumber = 0;
		while (num > 0) {
			ReversedNumber = ReversedNumber * 10 + (num % 10);
			num /= 10;
		}
		return ReversedNumber;
	}
	int CountOfRepeatingDigit(int Number, int Digit) {
		int Repeating = 0;
		while (Number > 0) {
			if (Number % 10 == Digit) {
				Repeating++;
			}
			Number /= 10;
		}
		return Repeating;
	}
	void CountOfRepeatingAllDigits(int Number) {
		int RepeatingNumber = 0;
		for (int i = 0; i < 10; i++) {
			RepeatingNumber = CountOfRepeatingDigit(Number, i);
			if (RepeatingNumber > 0) {
				cout << "Repeating Number Of " << i << " is: " << RepeatingNumber;
				cout << endl;
			}
		}
	}
	bool IsPalindromNumber(int Number) {
		//الرقم الذي تسطيع قراءته من الجهتين بنفس الطريقة.
		return (Number == ReverseNumber(Number));
	}
	float MyABS(float Number) {
		if (Number > 0)
			return Number;
		return Number * -1;
	}
	float GetFractionPart(float Number) {
		return Number - int(Number);
	}
	int MyRound(float Number) {
		int IntPart = (int)Number;
		float FractionPart = GetFractionPart(Number);

		if (MyABS(FractionPart) >= 0.5) {
			if (Number > 0)
				return ++IntPart;
			else
				return --IntPart;
		}
		return IntPart;
	}
	int MyFloar(float Number) {
		if (Number > 0)
			return (int)Number;
		return (int)Number - 1;
	}
	int MyCeil(float Number) {
		if (abs(GetFractionPart(Number) > 0))
		{
			if (Number > 0)
				return int(Number) + 1; //10.5 =>11
			else
				return int(Number);//-10.5 => 10
		}
		else
			return int(Number); //10 => 10, if the Number doesn't has fraction.
	}
	int MySQRT(float Number) {
		return int(pow(Number, 0.5));
	}
}