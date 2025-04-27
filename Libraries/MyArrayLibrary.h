#pragma once
#include<iostream>
#include<iomanip>

namespace MyArrayLibrary{
	/*some of Helper Functions*/
	void Swap(int& A, int& B) {
		int temp = A;
		A = B;
		B = temp;
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
	enPrimeOrNot CheckPrime(int num) {
		if (num <= 1) return enPrimeOrNot::NotPrime;
		if (num == 2) return enPrimeOrNot::Prime;

		for (int i = 3; i <= round(num / 2); i++) {
			if (num % i == 0)
				return enPrimeOrNot::NotPrime;
		}
		return enPrimeOrNot::Prime;
	}
	int RandomNumber(int From, int To) {
		return rand() % (To - From + 1) + From;
	}

	/*Main LibFunctions*/
	void PrintArrayOfSize100(int Array[100], int ArrLength) {
		for (int i = 0; i < ArrLength; i++) {
			cout << Array[i] << " ";
		}
		cout << endl;
	}
	int ArrayRowSum(int Array[100][100], int RowNumber, int Collumns) {
		int sum = 0;
		for (int i = 0; i < Collumns; i++) {
			sum += Array[RowNumber][i];
		}
		return sum;
	}
	int ArrayCollSum(int Array[100][100], int Rows, int CollumnNumber) {
		int sum = 0;
		for (int i = 0; i < Rows; i++) {
			sum += Array[i][CollumnNumber];
		}
		return sum;
	}
	void PrintMatrix(int Array[100][100], int Rows = 3, int Collumns = 3) {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Collumns; j++) {
				cout << setw(4) << Array[i][j] << "\t";
			}
			cout << endl;
		}
	}
	bool IsNumberInMatrix(int Array[100][100], int Number, int Rows = 3, int Collumns = 3) {
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Collumns; j++) {
				if (Array[i][j] == Number)
					return true;
			}
			cout << endl;
		}
		return false;
	}
	void PrintIntersectedNumbersOfTowMatrices(int Array1[100][100], int Array2[100][100], int Rows = 3, int Collumns = 3) {
		short Number = 0;
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Collumns; j++) {
				Number = Array1[i][j];
				if (IsNumberInMatrix(Array2, Number, Rows, Collumns))
					cout << setw(3) << Number <<" ";
			}
		}
	}
	int MaxValueOfMatrix(int Array[100][100], int Rows = 3, int Collumns = 3) {
		int Max = Array[0][0];
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Collumns; j++) {
				if (Array[i][j] > Max) {
					Max = Array[i][j];
				}
			}
		}
		return Max;
	}
	int MinValueOfMatrix(int Array[100][100], int Rows = 3, int Collumns = 3) {
		int Min = Array[0][0];
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Collumns; j++) {
				if (Array[i][j] < Min) {
					Min = Array[i][j];
				}
			}
		}
		return Min;
	}
	bool IsPalindromMatrix(int Array[100][100], int Rows = 3, int Collumns = 3) {
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Collumns / 2; j++) {
				if (Array[i][j] != Array[i][Collumns - 1 - j]) {
					return false;
				}
			}
		}
		return true;
	}
	void SumRowsOfMatrix(int Array[100][100], int Rows = 3, int Collumns = 3) {
		for (int i = 0; i < Rows; i++) {
			cout << "Sum of Row " << i << " is: " << ArrayRowSum(Array, i, Collumns) << endl;
		}
	}
	void Orderd3X3Matrix(int Array[100][100], int Rows = 3, int Colls = 3) {
		short counter = 0;
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Colls; j++) {
				Array[i][j] = counter++;
			}
		}
	}
	void MultiplyTowMatrix(int Array1[100][100], int Array2[100][100], int Array3[100][100], int Rows = 3, int Colls = 3) {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Colls; j++) {
				Array3[i][j] = Array1[i][j] * Array2[i][j];
			}
		}
	}
	void PrintMidleRowOfMatrix(int Array[100][100], int Rows = 3, int Colls = 3) {
		for (int i = 0; i < Colls; i++) {
			cout << Array[short(Rows / 2)][i];
		}
	}
	void PrintMidleCollOfMatrix(int Array[100][100], int Rows = 3, int Colls = 3) {
		for (int i = 0; i < Rows; i++) {
			cout << Array[i][short(Colls / 2)];
		}
	}
	bool CheckIfTowMatricesAreTypcal(int Array1[100][100], int Array2[100][100], int Rows = 3, int Colls = 3) {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Colls; j++) {
				if (Array1[i][j] != Array2[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	bool IsIdentityMarix(int Array[100][100], int Rows = 3, int Colls = 3) {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Colls; j++) {
				if (i == j && Array[i][j] != 1) {
					return false;
				}
				else if (i != j && Array[i][j] != 0) {
					return false;
				}
			}
		}
		return true;
	}
	bool IsScalarMatrix(int Array[100][100], int Rows = 3, int Colls = 3) {
		short FirstDiagonalElemement = Array[0][0];
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Colls; j++) {
				if (i == j && Array[i][j] != FirstDiagonalElemement) {
					return false;
				}
				else if (i != j && Array[i][j] != 0) {
					return false;
				}
			}
		}
		return true;
	}
	short CountNumberInMatrix(int Array[100][100], int Number, int Rows=3, int Colls=3) { 
		short NumberCount = 0; 
		for (short i = 0; i < Rows; i++) { 
			for (short j = 0; j < Colls; j++) { 
				if (Array[i][j] == Number) { 
					NumberCount++; 
				}
			}
		} 
		return NumberCount;
	}
	bool CheckSparceMatrix(int Array[100][100], int Rows = 3, int Colls = 3) {
		int NumZeros = CountNumberInMatrix(Array, 0);
		int MatrixSize = Rows * Colls;
		return (NumZeros > ceil((float)MatrixSize / 2));
	}
	int TimesRepeatedInArray(int Array[100], int ArrLength, int NumberToCheck) {
		int Count = 0;
		for (int i = 0; i < ArrLength; i++) {
			if (Array[i] == NumberToCheck) {
				Count++;
			}
		}
		return Count;
	}
	int MaxArrayElement(int Array[100], int ArrLength) {
		int Max = Array[0];
		for (int i = 1; i < ArrLength; i++) {
			if (Array[i] > Max)
				Max = Array[i];
		}
		return Max;
	}
	int MinArrayElement(int Array[100], int ArrLength) {
		int Min = Array[0];
		for (int i = 1; i < ArrLength; i++) {
			if (Array[i] < Min)
				Min = Array[i];
		}
		return Min;
	}
	int SumArray(int Array[100], int ArrLength) {
		int Sum = 0;
		for (int i = 0; i < ArrLength; i++) {
			Sum += Array[i];
		}
		return Sum;
	}
	int SumArrayOfMatrix(int Array[100][100], int Rows = 3, int Colls = 3) {
		int Sum = 0;
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Colls; j++) {
				Sum += Array[i][j];
			}
		}
		return Sum;
	}
	bool CheckIfTowMatricesAreEquals(int Array1[100][100], int Array2[100][100], int Rows = 3, int Colls = 3) {
		return (SumArrayOfMatrix(Array1) == SumArrayOfMatrix(Array2));
	}
	float AvgArray(int Array[100], int ArrLength) {
		return (float)SumArray(Array, ArrLength) / ArrLength;;
	}
	void CopyTowArays(int SourceArray[100], int DestinationArray[100], int ArrLength) {
		for (int i = 0; i < ArrLength; i++) {
			DestinationArray[i] = SourceArray[i];
		}
	}
	void CopyOnlyPrimeNumbersFromArray(int SourceArray[100], int DestinationArray[100], int SArrLength, int& DArrLength) {
		DArrLength = 0;
		for (int i = 0; i < SArrLength; i++) {
			if (CheckPrime(SourceArray[i]) == enPrimeOrNot::Prime) {
				DestinationArray[DArrLength] = SourceArray[i];
				DArrLength++;
			}
		}
		DArrLength--;
	}
	void FillArrayWithRandomNumbers(int Array[100], int& Length) {
		Length = ReadPositiveNumber("How many Item you want to Add? ");

		for (int i = 0; i < Length; i++) {
			Array[i] = RandomNumber(1, 100);
		}
	}
	void FillArrayWithOrderedNumbers(int Array[100], int& Length) {
		ReadPositiveNumber("How many Item you want to Add? ");
		cin >> Length;

		for (int i = 0; i < Length; i++) {
			Array[i] = (i + 1);
		}
	}
	void SumTowArrays(int Array1[100], int Array2[100], int SumArray[100], int& Length) {
		for (int i = 0; i < Length; i++) {
			SumArray[i] = Array1[i] + Array2[i];
		}
	}
	void ShuffleArray(int Array[100], int Length) {
		for (int i = 0; i < Length; i++) {
			Swap(Array[RandomNumber(1, Length) - 1],
				Array[RandomNumber(1, Length) - 1]);
		}
	}
	void ConvertArray(int Array[100], int Length) {
		for (int i = 0; i <= round(Length / 2); i++) {
			Swap(Array[i], Array[Length - 1 - i]);
		}
	}
	int IndexElemntInArray(int Array[100], int Length, int Item) {
		for (int i = 0; i < Length; i++) {
			if (Array[i] == Item) {
				return i;
			}
		}
		return -1;
	}
	bool IsNumberInArray(int Array[100], int Length, int Item) {
		return IndexElemntInArray(Array, Length, Item) != -1;
	}
	void AddArrayElemet(int Array[100], int& Length, int Number) {
		Array[Length] = Number;
		Length++;
	}
	void AddNumbersInArraySimiDynamicaly(int Array[100], int& Length) {
		bool AddMore = true;
		do {
			AddArrayElemet(Array, Length, ReadPositiveNumber());
			cout << "Do you want to Add Element? [0]:No. [1]:Yes. ";
			cin >> AddMore;
		} while (AddMore);
	}
	void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int ASLength, int& ADLength) {
		for (int i = 0; i < ASLength; i++) {
			AddArrayElemet(arrDestination, ADLength, arrSource[i]);
		}
	}
	void CopyOddElemntsFromArray(int arrSource[100], int arrDestination[100], int ASLength, int& ADLength) {
		for (int i = 0; i < ASLength; i++) {
			if (arrSource[i] % 2 != 0) {
				cout << arrSource[i] << endl;
				AddArrayElemet(arrDestination, ADLength, arrSource[i]);
			}
		}
	}
	void CopyPrimeElemntsFromArray(int Array1[100], int Array2[100], int Length1, int& Length2) {
		for (int i = 0; i < Length1; i++) {
			if (CheckPrime(Array1[i]) == enPrimeOrNot::Prime) {
				cout << Array1[i] << endl;
				AddArrayElemet(Array2, Length2, Array1[i]);
			}
		}
	}
	void CopyDistinctNumbersToArray(int Array1[100], int Array2[100], int Length1, int& Length2) {
		for (int i = 0; i < Length1; i++) {
			if (!IsNumberInArray(Array2, Length2, Array1[i])) {
				AddArrayElemet(Array2, Length2, Array1[i]);
			}
		}
	}
	bool IsPalindromeArray(int Array[100], int Length) {
		for (int i = 0; i < round(Length / 2); i++) {
			if (Array[i] != Array[Length - i - 1])
				return false;
		}
		return true;
	}
	int OddCountInArray(int Array[100], int Length) {
		int count = 0;
		for (int i = 0; i < Length; i++) {
			if (Array[i] % 2 != 0)
				count++;
		}
		return count;
	}
	int EvenCountInArray(int Array[100], int Length) {
		int count = 0;
		for (int i = 0; i < Length; i++) {
			if (Array[i] % 2 == 0)
				count++;
		}
		return count;
	}
	int PositiveCountInArray(int Array[100], int Length) {
		int count = 0;
		for (int i = 0; i < Length; i++) {
			if (Array[i] >= 0)
				count++;
		}
		return count;
	}
	int NegativeCountInArray(int Array[100], int Length) {
		int count = 0;
		for (int i = 0; i < Length; i++) {
			if (Array[i] < 0)
				count++;
		}
		return count;
	}
}