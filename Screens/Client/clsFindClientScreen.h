#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Lib/clsInputValidate.h"
#include "../../Core/clsClient.h"

using namespace std;

class clsFindClientScreen : clsScreen {
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
	static void ShowFindClientScreen() {
		
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient)) {
			return;
		}

		_DrawScreenHeader("\tFind Client Screen");

		string AccountNumber;
		cout << "Please Enter Account Number: ";
		AccountNumber = clsInputValidate<int>::ReadLineInput();
		
		while (!clsClient::IsClientExist(AccountNumber)) {
			cout << "Account Number is not found, Enter again: ";
			AccountNumber = clsInputValidate<string>::ReadLineInput();
		}

		clsClient Client1 = clsClient::Find(AccountNumber);

		if (!Client1.IsEmpty()) {
			cout << "\nClient Found :-)\n";
		}
		else {
			cout << "\nClient Not Found :-(\n";
		}
		_PrintClient(Client1);
	}
};