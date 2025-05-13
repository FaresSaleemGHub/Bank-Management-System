#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../Lib/clsString.h"
#include "clsPerson.h"
#include "../Lib/clsDate.h"

using namespace std;

static const string ClientsFile = "data/Clients.txt";
static const string TransferLogFile = "data/TransferLog.txt";

class clsClient : public clsPerson {
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    double _AccountBalance;
    bool _MarkedForDelete = false;

    static clsClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#") {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
    }

    static string _ConverClientObjectToLine(clsClient Client, string Seperator = "#//#") {
        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;
    }

    static  vector <clsClient> _LoadClientsDataFromFile() {
        vector <clsClient> vClients;
        fstream MyFile (ClientsFile, ios::in);//read Mode
        if (MyFile.is_open()) {
            string Line;
            while (getline(MyFile, Line)) {
                clsClient Client = _ConvertLinetoClientObject(Line);
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return vClients;
    }

    static void _SaveCleintsDataToFile(vector <clsClient> vClients) {
        fstream MyFile(ClientsFile, ios::out);//overwrite
        if (MyFile.is_open()) {
            for (clsClient C : vClients) {
                if (C._MarkedForDelete == false) {
                    MyFile << _ConverClientObjectToLine(C) << endl;
                }
            }
            MyFile.close();
        }
    }

    void _Update() {
        vector <clsClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsClient& C : _vClients) {
            if (C.AccountNumber() == AccountNumber()) {
                C = *this; // to reflect the updated data of this object on saved Vector data in memory.
                break;
            }
        }
        _SaveCleintsDataToFile(_vClients); //to reflect the updates on file's data.
    }

    void _AddNew() {
        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine) {
        fstream MyFile;
        MyFile.open(ClientsFile, ios::out | ios::app);

        if (MyFile.is_open()) {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

    static clsClient _GetEmptyClientObject() {
        return clsClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    string _PrepareTransferLogRecord(float Amount, clsClient DestinationClient,
        string UserName, string Seperator = "#//#"){
        string TransferLogRecord = "";
        TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
        TransferLogRecord += AccountNumber() + Seperator;
        TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
        TransferLogRecord += to_string(Amount) + Seperator;
        TransferLogRecord += to_string(AccountBalance) + Seperator;
        TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
        TransferLogRecord += UserName;
        return TransferLogRecord;
    }

    void _RegisterTransferLog(double Amount, clsClient DestinationClient, string UserName){
        string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

        fstream MyFile;
        MyFile.open(TransferLogFile, ios::out | ios::app);

        if (MyFile.is_open()) {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

    struct stTrnsferLogRecord;

    static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#"){
        stTrnsferLogRecord TrnsferLogRecord;
        vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
        TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
        TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
        TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
        TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
        TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
        TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
        TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];
        return TrnsferLogRecord;
    }

public:
    struct stTrnsferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        double Amount;
        double srcBalanceAfter;
        double destBalanceAfter;
        string UserName;
    };

    clsClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone) {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    bool IsEmpty() {
        return (_Mode == enMode::EmptyMode);
    }

    string AccountNumber() {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode) {
        _PinCode = PinCode;
    }
    string GetPinCode() {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance) {
        _AccountBalance = AccountBalance;
    }
    double GetAccountBalance() {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;

    static clsClient Find(string AccountNumber) {
        fstream MyFile;
        MyFile.open(ClientsFile, ios::in);//read Mode

        if (MyFile.is_open()) {
            string Line;
            while (getline(MyFile, Line)) {
                clsClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber) {
                    MyFile.close();
                    return Client;
                }
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    static clsClient Find(string AccountNumber, string PinCode) {
        fstream MyFile;
        MyFile.open(ClientsFile, ios::in);//read Mode

        if (MyFile.is_open()) {
            string Line;
            while (getline(MyFile, Line)) {
                clsClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode) {
                    MyFile.close();
                    return Client;
                }
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2};

    enSaveResults Save() {
        switch (_Mode) {
        case enMode::EmptyMode: {
            return enSaveResults::svFaildEmptyObject;
        }
        case enMode::UpdateMode: {
            _Update();
            return enSaveResults::svSucceeded;
            break;
        }
        case enMode::AddNewMode:
            if (IsClientExist(_AccountNumber)) {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
            break;
        }
        return enSaveResults::svFaildEmptyObject;
    }

    static bool IsClientExist(string AccountNumber) {
        clsClient Client1 = clsClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    bool Delete() {
        vector <clsClient> _vClients;
        _vClients = _LoadClientsDataFromFile();
        for (clsClient& C : _vClients) {
            if (C.AccountNumber() == _AccountNumber) {
                C._MarkedForDelete = true;
                break;
            }
        }
        _SaveCleintsDataToFile(_vClients);
        *this = _GetEmptyClientObject();
        return true;
    }

    static clsClient GetAddNewClientObject(string AccountNumber){
        return clsClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    static vector <clsClient> GetClientsList(){
        return _LoadClientsDataFromFile();
    }

    static double GetTotalBalances(){
        vector <clsClient> vClients = clsClient::GetClientsList();
        double TotalBalances = 0;
        for (clsClient Client : vClients){
            TotalBalances += Client.AccountBalance;
        }
        return TotalBalances;
    }

    void Deposit(double Amount) {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(double Amount) {
        if (Amount > _AccountBalance) {
            return false;
        } else {
            _AccountBalance -= Amount;
            Save();
        }
        return true;
    }

    bool Transfer(double Amount, clsClient& DestinationClient, string UserName){
        if (Amount > AccountBalance)
        {
            return false;
        }

        Withdraw(Amount);
        DestinationClient.Deposit(Amount);

        _RegisterTransferLog(Amount, DestinationClient, UserName);

        return true;
    }

    static  vector <stTrnsferLogRecord> GetTransfersLogList(){
        vector <stTrnsferLogRecord> vTransferLogRecord;

        fstream MyFile;
        MyFile.open("TransfersLog.txt", ios::in);//read Mode

        if (MyFile.is_open()){
            string Line;
            stTrnsferLogRecord TransferRecord;
            while (getline(MyFile, Line)){
                TransferRecord = _ConvertTransferLogLineToRecord(Line);
                vTransferLogRecord.push_back(TransferRecord);
            }
            MyFile.close();
        }
        return vTransferLogRecord;
    }

};