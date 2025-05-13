#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Lib/clsInputValidate.h"
#include "../../Core/clsClient.h"

using namespace std;

class clsUpdateClientScreen : clsScreen {
private:
	static void _PrintClient(clsClient Client) {
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}
	static void _ReadClientInfo(clsClient& Client) {
		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate<string>::ReadLineInput();

		cout << "\nEnter LastName: ";
		Client.LastName = clsInputValidate<string>::ReadLineInput();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate<string>::ReadLineInput();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate<string>::ReadLineInput();

		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputValidate<string>::ReadLineInput();

		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputValidate<float>::ReadTNumber();
	}

public:
	static void ShowUpdateClientScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients)) {
			return;
		}

		_DrawScreenHeader("\tUpdate Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate<string>::ReadLineInput();

		while (!clsClient::IsClientExist(AccountNumber)){
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate<string>::ReadLineInput();
		}

		clsClient Client1 = clsClient::Find(AccountNumber);
		_PrintClient(Client1);

		cout << "\n\nUpdate Client Info:";
		cout << "\n____________________\n";

		_ReadClientInfo(Client1);

		clsClient::enSaveResults SaveResult;
		SaveResult = Client1.Save();
		switch (SaveResult) {
			case  clsClient::enSaveResults::svSucceeded:{
				cout << "\nAccount Updated Successfully :-)\n";
				_PrintClient(Client1);
				break;
			}
			case clsClient::enSaveResults::svFaildEmptyObject:{
				cout << "\nError account was not saved because it's Empty";
				break;
			}
		}
	}
};