#pragma once
#include <iostream>
#include <iomanip>
#include "../../clsScreen.h"
#include "../../../Lib/clsInputValidate.h"
#include "../../../Core/clsClient.h"
//#include "Global.h"

using namespace std;

class clsTransferScreen : protected clsScreen {

private:
    static void _PrintClient(clsClient Client){
        cout << "\nClient Card:";
        cout << "\n___________________\n";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }

    static string _ReadAccountNumber(){
        string AccountNumber;
        cout << "\nPlease Enter Account Number to Transfer From: ";
        AccountNumber = clsInputValidate<string>::ReadLineInput();
        while (!clsClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate<string>::ReadLineInput();
        }
        return AccountNumber;
    }

    static float ReadAmount(clsClient SourceClient){
        float Amount;

        cout << "\nEnter Transfer Amount? ";
        Amount = clsInputValidate<float>::ReadTNumber();
        while (Amount > SourceClient.AccountBalance){
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate<float>::ReadTNumber();
        }
        return Amount;
    }

public:
    static void ShowTransferScreen() {
        _DrawScreenHeader("\tTransfer Screen");

        clsClient SourceClient = clsClient::Find(_ReadAccountNumber());
        _PrintClient(SourceClient);

        clsClient DestinationClient = clsClient::Find(_ReadAccountNumber());
        _PrintClient(DestinationClient);

        float Amount = ReadAmount(SourceClient);

        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y'){
            if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName)){
                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }
        }

        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);
    }

};