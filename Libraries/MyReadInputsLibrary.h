#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace ReadInputsLibrary {
	string ReadTextLine(string Message) {
		string Text = "";
		cout << Message;
		getline(cin, Text);
		return Text;
	}
	int ReadIntNumber(string Message) {
		int Number = 0;
		cout << Message;
		cin >> Number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter again: ";
			cin >> Number;
			}
			return Number;
	}
	int ReadPositiveNumber(string Message) {
		int num = 0;
		do {
			cout << Message;
			cin >> num;
		} while (num <= 0);
		return num;
	}
	int ReadPositiveNumber() {
		int num = 0;
		do {
			cout << "Enter a positive number: ";
			cin >> num;
		} while (num <= 0);
		return num;
	}
	void ReadArrayOf100Size(int Array[100], int& ArrLength) {
		cout << "Enter How Many Number You Want to Enter? ";
		cin >> ArrLength;

		cout << "Enter Array Elements:\n";
		for (int i = 0; i < ArrLength; i++) {
			cout << "Element [" << (i + 1) << "]:";
			cin >> Array[i];
		}
	}
}