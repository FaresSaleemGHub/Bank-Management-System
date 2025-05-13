#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Lib/clsInputValidate.h"
#include "../../Core/clsClient.h"

using namespace std;

class clsAddNewClientScreen : protected clsScreen {
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
	static void ShowAddNewClientScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient)) {
			return;
		}

		_DrawScreenHeader("\tAdd New Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate<string>::ReadLineInput();;
		while (clsClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount Number Is Already Used, Choose another one: ";
			AccountNumber = clsInputValidate<string>::ReadLineInput();
		}

		clsClient NewClient = clsClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();
		switch (SaveResult) {
		case  clsClient::enSaveResults::svSucceeded: {
			cout << "\nAccount Addeded Successfully :-)\n";
			_PrintClient(NewClient);
			break;
		}
		case clsClient::enSaveResults::svFaildEmptyObject: {
			cout << "\nError account was not saved because it's Empty";
			break;
		}
		case clsClient::enSaveResults::svFaildAccountNumberExists: {
			cout << "\nError account was not saved because account number is used!\n";
			break;
		}
		}
	}
};
