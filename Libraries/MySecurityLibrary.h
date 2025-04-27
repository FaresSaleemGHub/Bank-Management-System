#pragma once
#include<iostream>
#include<string>

enum enCharacterType { SmallLetter, CapitalLetter, SpecialCharacter, Digit };

namespace MySecurityLibrary {
	int RandomNumber(int From, int To) {
		//Function To Generate A Random Number
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}
	char RandomCharacter(enCharacterType enRC) {
		switch (enRC) {
		case enCharacterType::SmallLetter:
			return char(RandomNumber('a', 'z'));
			break;
		case enCharacterType::CapitalLetter:
			return char(RandomNumber('A', 'Z'));
			break;
		case enCharacterType::SpecialCharacter:
			return char(RandomNumber(33, 47));
			break;
		default:
			return RandomNumber(48, 57);
			break;
		}
	}
	string RandomWord(enCharacterType enCT, short Length) {
		string Word = "";
		for (int i = 0; i < Length; i++) {
			Word = Word + RandomCharacter(enCT);
		}
		return Word;
	}
	string GenerateRandomKey() {
		string Key = "";
		Key = RandomWord(enCharacterType::CapitalLetter, 4) + "-";
		Key += RandomWord(enCharacterType::CapitalLetter, 4) + "-";
		Key += RandomWord(enCharacterType::CapitalLetter, 4) + "-";
		Key += RandomWord(enCharacterType::CapitalLetter, 4);
		return Key;
	}
	void GenerateKeys(int NumKeys) {
		for (int i = 0; i < NumKeys; i++) {
			cout << "Key [" << i << "] : ";
			cout << GenerateRandomKey() << endl;
		}
	}
	bool GuessPassword3Letters(string Password) {
		string guess = "";
		int NumTries = 0;
		for (int i = 'A'; i <= 'Z'; i++) {
			for (int j = 'A'; j <= 'Z'; j++) {
				for (int k = 'A'; k <= 'Z'; k++) {
					NumTries++;
					guess += char(i);
					guess += char(j);
					guess += char(k);
					cout << "Trial [" << (NumTries) << "]: " << guess << endl;
					if (guess == Password) {
						cout << "Found it, it's: " << guess << endl;
						return true;
					}
					guess = "";
				}
			}
		}
		return false;
	}
	string EncryptText(string Word, int EncryptionKey) {
		for (int i = 0; i < Word.length(); i++) {
			Word[i] = char((int)Word[i] + EncryptionKey);
		}
		return Word;
	}
	string DecryptText(string Word, int EncryptionKey) {
		for (int i = 0; i < Word.length(); i++) {
			Word[i] = char((int)Word[i] - EncryptionKey);
		}
		return Word;
	}

	void PrintFirstLetterOfEachWord(string& S) {
		bool isFirstLetter = true;
		for (short i = 0; i < S.length(); i++) {
			if (S[i] != ' ' && isFirstLetter) {
				cout << S[i] << endl;
			}
			isFirstLetter = (S[i] == ' ' ? true : false);//will check at each iteration
		}
	}
	void UpercaseFirstLetterOfEachWord(string& S) {
		bool isFirstLetter = true;
		for (short i = 0; i < S.length(); i++) {
			if (S[i] != ' ' && isFirstLetter) {
				S[i] = toupper(S[i]);
			}
			isFirstLetter = (S[i] == ' ' ? true : false);//will check at each iteration
		}
	}
	void LowerFirstLetterOfEachWord(string& S) {
		bool isFirstLetter = true;
		for (short i = 0; i < S.length(); i++) {
			if (S[i] != ' ' && isFirstLetter) {
				S[i] = tolower(S[i]);
			}
			isFirstLetter = (S[i] == ' ' ? true : false);//will check at each iteration
		}
	}
	string UpercaseAllLettersOfWord(string S) {
		for (short i = 0; i < S.length(); i++) {
			S[i] = toupper(S[i]);
		}
		return S;
	}
	string LowercaseAllLettersOfWord(string S) {
		for (short i = 0; i < S.length(); i++) {
			S[i] = tolower(S[i]);
		}
		return S;
	}
	void InvertLetterCase(char& C) {
		C = isupper(C) ? tolower(C) : toupper(C);
	}
	void InvertWordCase(string& S) {
		for (short i = 0; i < S.length(); i++) {
			InvertLetterCase(S[i]);
		}
	}
	short CountCapitalLettersIfWord(string& S) {
		short CapitalCounter = 0;
		for (int i = 0; i < S.length(); i++) {
			if (isupper(S[i])) {
				CapitalCounter++;
			}
		}
		return CapitalCounter;
	}
	short CountSmallLettersIfWord(string& S) {
		short SmallCounter = 0;
		for (int i = 0; i < S.length(); i++) {
			if (islower(S[i])) {
				SmallCounter++;
			}
		}
		return SmallCounter;
	}
	short CountLetterOfWord(char C, string Word, bool MatchCase = true) {
		short Counter = 0;
		for (short i = 0; i < Word.length(); i++) {;
			if (MatchCase) {
				if (tolower(C) == tolower(Word[i])) {
					Counter++;
				}
			}else {
				if (C == Word[i]) {
					Counter++;
				}
			}
		}
		return Counter;
	}
	bool isVowelLetter(char C) {
		C = tolower(C);
		return ((C == 'a') || (C == 'e') || (C == 'i') || (C == 'o') || (C == 'u'));
	}
	void PrintEachWordInString(string S) {
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
	void CountWordsInString(string S) {
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
	vector<string> SplitString(string S1, string Delim) {
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
	string TrimLeft(string S) {

		for (short i = 0; i < S.length(); i++) {
			if (S[i] != ' ') {
				return S.substr(i, S.length() - 1);
			}
		}
		return "";
	}
	string TrimRight(string S) {

		for (size_t i = S.length() - 1; i >= 0; i--) {
			if (S[i] != ' ') {
				return S.substr(0, i + 1);
			}
		}
		return "";
	}
	string Trim(string S1) {
		return (TrimLeft(TrimRight(S1)));
	}
	string JoinString(vector<string> vString, string Delim) {
		string S = "";
		for (string& s : vString) {
			S += s + Delim;
		}
		return S.substr(0, S.length() - Delim.length());;
	}
	string JoinString(string Array[], short ArrayLength, string Delim) {
		string S = "";
		for (short i = 0; i < ArrayLength; i++) {
			S += Array[i] + Delim;
		}
		return S.substr(0, S.length() - Delim.length());;
	}
	void ReplaceWordOfString(string& S, string ToReplace, string ReplaceTo) {
		size_t pos = S.find(ToReplace);
		while (pos != string::npos) {
			S = S.replace(pos, ToReplace.length(), ReplaceTo);//(int,int,string)
			pos = S.find(ToReplace);
		}
	}
	void ReplaceWordOfString(string& S, string ToReplace, string ReplaceTo, bool MatchCase) {
		if (MatchCase) {
			ReplaceWordOfString(S, ToReplace, ReplaceTo);
		}
		else {
			vector<string> vString = SplitString(S, " ");
			for (string& s : vString) {
				if (LowercaseAllLettersOfWord(s) == LowercaseAllLettersOfWord(ToReplace)) {
					s = ReplaceTo;
				}
			}
			S = JoinString(vString, " ");
		}
	}
}