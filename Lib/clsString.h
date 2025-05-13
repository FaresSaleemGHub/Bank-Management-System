#pragma once
#include <iostream>
#include<vector>

using namespace std;
class clsString {
private:
	string _Value;

public:
	//Constructors
	clsString() {
		_Value = "";
	}
	clsString(string Value) {
		_Value = Value;
	}

	//Properties
	void SetValue(string Value) {
		_Value = Value;
	}
	string GetValue() {
		return _Value;
	}
	static size_t GetLength(string _Value) {
		return _Value.length();
	}
	size_t GetLength() {
		return GetLength(_Value);
	}

	//Dclaration Specefication
	_declspec(property (get = GetValue, put = SetValue))string Value;
	__declspec(property(get = GetLength)) size_t Length;


	static string EncryptText(string Word, int EncryptionKey) {
		for (int i = 0; i < Word.length(); i++) {
			Word[i] = char((int)Word[i] + EncryptionKey);
		}
		return Word;
	}
	string EncryptText(int EncryptionKey) {
		return EncryptText(_Value, EncryptionKey);
	};


	static string DecryptText(string Word, int EncryptionKey) {
		for (int i = 0; i < Word.length(); i++) {
			Word[i] = char((int)Word[i] - EncryptionKey);
		}
		return Word;
	}
	string DecryptText(int EncryptionKey) {
		return DecryptText(_Value, EncryptionKey);
	}


	static void PrintFirstLetterOfEachWord(string& S) {
		bool isFirstLetter = true;
		for (short i = 0; i < S.length(); i++) {
			if (S[i] != ' ' && isFirstLetter) {
				cout << S[i] << endl;
			}
			isFirstLetter = (S[i] == ' ' ? true : false);//will check at each iteration
		}
	}
	void PrintFirstLetterOfEachWord() {
		PrintFirstLetterOfEachWord(_Value);
	}


	static void UpercaseFirstLetterOfEachWord(string& S) {
		bool isFirstLetter = true;
		for (short i = 0; i < S.length(); i++) {
			if (S[i] != ' ' && isFirstLetter) {
				S[i] = toupper(S[i]);
			}
			isFirstLetter = (S[i] == ' ' ? true : false);//will check at each iteration
		}
	}
	void UpercaseFirstLetterOfEachWord() {
		UpercaseFirstLetterOfEachWord(_Value);
	}


	static void LowerFirstLetterOfEachWord(string& S) {
		bool isFirstLetter = true;
		for (short i = 0; i < S.length(); i++) {
			if (S[i] != ' ' && isFirstLetter) {
				S[i] = tolower(S[i]);
			}
			isFirstLetter = (S[i] == ' ' ? true : false);//will check at each iteration
		}
	}
	void LowerFirstLetterOfEachWord() {
		LowerFirstLetterOfEachWord(_Value);
	}


	static string UpperAllString(string S) {
		for (short i = 0; i < S.length(); i++) {
			S[i] = toupper(S[i]);
		}
		return S;
	}
	string UpperAllString() {
		return UpperAllString(_Value);
	}


	static string LowercaseAllLettersOfWord(string S) {
		for (short i = 0; i < S.length(); i++) {
			S[i] = tolower(S[i]);
		}
		return S;
	}
	string LowercaseAllLettersOfWord() {
		return LowercaseAllLettersOfWord(_Value);
	}


	static void InvertLetterCase(char& C) {
		C = isupper(C) ? tolower(C) : toupper(C);
	}
	static void InvertWordCase(string& S) {
		for (short i = 0; i < S.length(); i++) {
			InvertLetterCase(S[i]);
		}
	}
	void InvertWordCase() {
		InvertWordCase(_Value);
	}


	static short CountCapitalLettersIfWord(string& S) {
		short CapitalCounter = 0;
		for (int i = 0; i < S.length(); i++) {
			if (isupper(S[i])) {
				CapitalCounter++;
			}
		}
		return CapitalCounter;
	}
	short CountCapitalLettersIfWord() {
		return CountCapitalLettersIfWord(_Value);
	}


	static short CountSmallLettersIfWord(string& S) {
		short SmallCounter = 0;
		for (int i = 0; i < S.length(); i++) {
			if (islower(S[i])) {
				SmallCounter++;
			}
		}
		return SmallCounter;
	}
	short CountSmallLettersIfWord() {
		return CountSmallLettersIfWord(_Value);
	}


	static short CountLetterOfWord(char C, string Word, bool MatchCase = true) {
		short Counter = 0;
		for (short i = 0; i < Word.length(); i++) {
			;
			if (MatchCase) {
				if (tolower(C) == tolower(Word[i])) {
					Counter++;
				}
			}
			else {
				if (C == Word[i]) {
					Counter++;
				}
			}
		}
		return Counter;
	}
	short CountLetterOfWord(char C, bool MatchCase = true) {
		return CountLetterOfWord(C, _Value, MatchCase);
	}


	static void CountWordsInString(string S) {
		string delimiter = " ";
		size_t Pos = 0;
		short Counter = 0;
		string sWord;
		// Use find() function to get the position of the delimiters  
		while ((Pos = S.find(delimiter)) != string::npos) {
			sWord = S.substr(0, Pos); // Extract the word
			if (!sWord.empty()) {
				Counter++;
			}
			S.erase(0, Pos + delimiter.length()); // Remove the word and delimiter from S
		}
		// Print the last word if there's any left, æããßä Êßæä ÂÎÑ ßáãÉ ãÇ ÈÚÏåÇ ÝÑÇÛ
		if (!S.empty()) {
			Counter++;
		}
	}
	void CountWordsInString() {
		CountWordsInString(_Value);
	}


	static void PrintEachWordInString(string S) {
		string delimiter = " ";
		size_t Pos = 0;
		string sWord;
		// Use find() function to get the position of the delimiters  
		while ((Pos = S.find(delimiter)) != string::npos) {
			sWord = S.substr(0, Pos); // Extract the word
			if (!sWord.empty()) {
				cout << sWord << endl; // Print the word if it's not empty
			}
			S.erase(0, Pos + delimiter.length()); // Remove the word and delimiter from S
		}
		// Print the last word if there's any left, æããßä Êßæä ÂÎÑ ßáãÉ ãÇ ÈÚÏåÇ ÝÑÇÛ
		if (!S.empty()) {
			cout << S << endl;
		}
	}
	void PrintEachWordInString() {
		PrintEachWordInString(_Value);
	}


	static vector<string> Split(string S1, string Delim) {
		vector<string> vString;
		size_t pos = 0;
		string sWord;

		while ((pos = S1.find(Delim)) != std::string::npos) {
			sWord = S1.substr(0, pos);
			if (!S1.empty())
			vString.push_back(sWord);
			S1.erase(0, pos + Delim.length());
		}
		if (!S1.empty()) {
			vString.push_back(S1);
		}
		return vString;
	}
	vector<string> Split(string Delim) {
		return Split(_Value, Delim);
	}


	static string TrimLeft(string S) {
		for (short i = 0; i < S.length(); i++) {
			if (S[i] != ' ') {
				return S.substr(i, S.length() - 1);
			}
		}
		return "";
	}
	string TrimLeft() {
		TrimLeft(_Value);
	}


	static string TrimRight(string S) {
		for (size_t i = S.length() - 1; i >= 0; i--) {
			if (S[i] != ' ') {
				return S.substr(0, i + 1);
			}
		}
		return "";
	}
	string TrimRight() {
		TrimRight(_Value);
	}


	static string Trim(string S1) {
		return (TrimLeft(TrimRight(S1)));
	}
	string Trim() {
		return Trim(_Value);
	}


	static string JoinString(vector<string> vString, string Delim) {
		string S = "";
		for (string& s : vString) {
			S += s + Delim;
		}
		return S.substr(0, S.length() - Delim.length());;
	}
	static string JoinString(string Array[], short ArrayLength, string Delim) {
		string S = "";
		for (short i = 0; i < ArrayLength; i++) {
			S += Array[i] + Delim;
		}
		return S.substr(0, S.length() - Delim.length());;
	}


	static void ReplaceWordOfString(string& S, string ToReplace, string ReplaceTo) {
		size_t pos = S.find(ToReplace);
		while (pos != string::npos) {
			S = S.replace(pos, ToReplace.length(), ReplaceTo);//(int,int,string)
			pos = S.find(ToReplace);
		}
	}
	void ReplaceWordOfString(string ToReplace, string ReplaceTo) {
		ReplaceWordOfString(_Value, ToReplace, ReplaceTo);
	}


	static void ReplaceWordOfString(string& S, string ToReplace, string ReplaceTo, bool MatchCase) {
		if (MatchCase) {
			ReplaceWordOfString(S, ToReplace, ReplaceTo);
		}
		else {
			vector<string> vString = Split(S, " ");
			for (string& s : vString) {
				if (LowercaseAllLettersOfWord(s) == LowercaseAllLettersOfWord(ToReplace)) {
					s = ReplaceTo;
				}
			}
			S = JoinString(vString, " ");
		}
	}
	void ReplaceWordOfString(string ToReplace, string ReplaceTo, bool MatchCase) {
		ReplaceWordOfString(_Value, ToReplace, ReplaceTo, MatchCase);
	}
};
