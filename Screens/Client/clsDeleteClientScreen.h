#pragma once
#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Core/clsClient.h"
#include "../../Lib/clsInputValidate.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen {
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

public:
	static void ShowDeleteClientScreen() {
		
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient)) {
			return;
		}

		_DrawScreenHeader("\t  Delete Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate<string>::ReadLineInput();
		while (!clsClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate<string>::ReadLineInput();
		}

		clsClient Client1 = clsClient::Find(AccountNumber);
		_PrintClient(Client1);

		cout << "\nAre you sure you want to delete this client y/n?";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {
			if (Client1.Delete()) {
				cout << "\nClient Deleted Successfully :-)\n";
				_PrintClient(Client1);
			}
			else {
				cout << "\nError Client Was not Deleted\n";
			}
		}
	}
};