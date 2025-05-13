#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Core/clsPerson.h"
#include "../../Lib/clsInputValidate.h"

class clsUpdateUserScreen :protected clsScreen{
private:
    static void _ReadUserInfo(clsUser& User){
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate<string>::ReadLineInput();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate<string>::ReadLineInput();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate<string>::ReadLineInput();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate<string>::ReadLineInput();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate<string>::ReadLineInput();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUser User){
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";
    }

    static int _ReadPermissionsToSet(){
        int Permissions = 0;
        char Answer = 'n';

        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y'){
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";
        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y'){
            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y'){
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y'){
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y'){
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y'){
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y'){
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y'){
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nShow Login Registers? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            Permissions += clsUser::enPermissions::pShowLoginRegister;
        }

        cout << "\npCurrencyExchange? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            Permissions += clsUser::enPermissions::pCurrencyExchange;
        }

        return Permissions;

    }

public:

    static void ShowUpdateUserScreen(){
        _DrawScreenHeader("\tUpdate User Screen");

        string UserName = "";

        cout << "\nPlease Enter User UserName: ";
        UserName = clsInputValidate<string>::ReadLineInput();

        while (!clsUser::IsUserExist(UserName)){
            cout << "\nAccount number is not found, choose another one: ";
            UserName = clsInputValidate<string>::ReadLineInput();
        }

        clsUser User1 = clsUser::Find(UserName);

        _PrintUser(User1);

        cout << "\nAre you sure you want to update this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y'){
            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";

            _ReadUserInfo(User1);

            clsUser::enSaveResults SaveResult;
            SaveResult = User1.Save();
            switch (SaveResult){
                case  clsUser::enSaveResults::svSucceeded:
                {
                    cout << "\nUser Updated Successfully :-)\n";

                    _PrintUser(User1);
                    break;
                }
                case clsUser::enSaveResults::svFaildEmptyObject:
                {
                    cout << "\nError User was not saved because it's Empty";
                    break;

                }
            }
        }
    }
};

