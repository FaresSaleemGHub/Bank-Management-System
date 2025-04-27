#pragma once

#include <fstream>
#include <iostream>
#include<string>

namespace MyFilesLib {
	void PrintFileContent(string FileName) {
		fstream MyFile;
		MyFile.open(FileName, ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {
				cout << line << endl;
			}
			MyFile.close();
		}
	}
	void AppendingFile(string FileName, string sAppend) {
		fstream MyFile;
		MyFile.open(FileName, ios::out | ios::app);
		if (MyFile.is_open()) {
			MyFile << sAppend;
			MyFile.close();
		}
	}
	void SaveFileDataIntoVector(string FileName, vector<string>& vFileContent) {
		fstream MyFile;
		MyFile.open(FileName, ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {
				vFileContent.push_back(line);
			}
			MyFile.close();
		}
	}
	void SaveVectorDataIntoFile(string FileName, vector<string>& vFileContent) {
		fstream MyFile;
		MyFile.open(FileName, ios::out);
		if (MyFile.is_open()) {
			for (string& line : vFileContent) {
				if (line != "") {
					MyFile << line << endl;
				}
			}
			MyFile.close();
		}
	}
	void DeleteRecordFromFile(string FileName, string Record) {
		vector <string> vFileContent;
		SaveFileDataIntoVector(FileName, vFileContent);
		for (string& Line : vFileContent) {
			if (Line == Record) {
				Line = "";
			}
		}
		SaveVectorDataIntoFile(FileName, vFileContent);
	}
	void UpdateRecordFromFile(string FileName, string Record, string UpdateTo) {
		vector <string> vFileContent;
		SaveFileDataIntoVector(FileName, vFileContent);
		for (string& Line : vFileContent) {
			if (Line == Record) {
				Line = UpdateTo;
			}
		}
		SaveVectorDataIntoFile(FileName, vFileContent);
	}
}