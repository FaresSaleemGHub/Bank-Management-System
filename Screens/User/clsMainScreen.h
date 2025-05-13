#pragma once
#include <iostream>
#include <iomanip>
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "../clsScreen.h"
#include "../Client/clsManageClientsScreen.h"
#include "../Client/Transactions/clsTransferScreen.h"
#include "../Currency/clsCurrencyExchangeScreen.h"
#include "../../Lib/clsInputValidate.h"
//#include "Global.h"


using namespace std;

class clsMainScreen : protected clsScreen{
private:
    enum enMainMenueOptions {
        eManageClients = 1, eManageUsers = 2, eLoginRegister = 3, eCurrencyExchange = 4, eExit = 5
    };

    static short _ReadMainMenueOption(){
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate<short>::ReadTNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static  void _GoBackToMainMenue(){
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowManageClientsMenue() {
        clsManageClientsScreen::ShowManageClientsMenue();
    }

    static void _ShowManageUsersMenue() {
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowCurrencyExchangeScreen() {
        clsCurrencyExchangeMainScreen::ShowCurrencyExchangeMenue();
    }

    static void _ShowLoginRegisterScreen() {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _Logout() {
        CurrentUser = clsUser::Find("","");
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption){
        switch (MainMenueOption)
        {
        case eManageClients:
            system("cls");
            _ShowManageClientsMenue();
            _GoBackToMainMenue();
            break;
        case eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        case eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;
        case eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenue();
            break;
        case eExit:
            system("cls");
            _Logout();
            break;
        }
    }

public:
    static void ShowMainMenue(){
        system("cls");
        SetMainMenuColor();
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Manage Clients.\n";
        cout << setw(37) << left << "" << "\t[2] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[3] Login Regester.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[5] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }
};