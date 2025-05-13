#pragma once
#include <iostream>
#include <iomanip>
#include "../clsScreen.h"
#include "../Client/clsClientListScreen.h"
#include "../Client/clsAddNewClientScreen.h"
#include "../Client/clsDeleteClientScreen.h"
#include "../Client/clsUpdateClientScreen.h"
#include "../Client/clsFindClientScreen.h"
#include "../Client/Transactions/clsTransactionsScreen.h"
#include "../../Lib/clsInputValidate.h"

using namespace std;

class clsManageClientsScreen :protected clsScreen {

private:
    enum enManageClientsMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6, eMainMenue = 7
    };

    static short ReadManageClientsMenueOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 7]? ";
        short Choice = clsInputValidate<short>::ReadTNumberBetween(1, 7, "Enter Number between 1 to 7? ");
        return Choice;
    }

    static void _GoBackToManageClientsMenue() {
        cout << "\n\nPress any key to go back to Manage Clients Menue...";
        system("pause>0");
        ShowManageClientsMenue();
    }

    static void _ShowAllClientsScreen() {
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen() {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen() {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen() {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen() {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue() {
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _PerformManageClientsMenueOption(enManageClientsMenueOptions ClientsMenueOption) {
        switch (ClientsMenueOption) {
            case eListClients: {
                system("cls");
                _ShowAllClientsScreen();
                _GoBackToManageClientsMenue();
                break;
            }
            case eAddNewClient: {
                system("cls");
                _ShowAddNewClientsScreen();
                _GoBackToManageClientsMenue();
                break;
            }
            case eDeleteClient: {
                system("cls");
                _ShowDeleteClientScreen();
                _GoBackToManageClientsMenue();
            }   break;
            case eUpdateClient: {
                system("cls");
                _ShowUpdateClientScreen();
                _GoBackToManageClientsMenue();
                break;
            }
            case eFindClient: {
                system("cls");
                _ShowFindClientScreen();
                _GoBackToManageClientsMenue();
                break;
            }
            case eShowTransactionsMenue: {
                system("cls");
                _ShowTransactionsMenue();
                _GoBackToManageClientsMenue();
                break;
            }
            case eMainMenue: {
                //do nothing here the main screen will handle it :-) ;
            }
        }
    }

public:
    static void ShowManageClientsMenue() {
        system("cls");
        SetManageClientsColor();
        _DrawScreenHeader("\t Manage Clients Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Clients Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageClientsMenueOption((enManageClientsMenueOptions)ReadManageClientsMenueOption());
    }
};
