#pragma once
#include <iostream>
#include <iomanip>
#include "../../../Lib/clsInputValidate.h"
#include "../../clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen {

private:
    enum enTransactionsMenuOptions {
        eDiposit = 1, eWithdraw, eShoTotalBalance, eTransfer, eTransferLog, eShowMainMen
    };

    static short _ReadTransactionsMenueOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate<short>::ReadTNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static  void _GoBackToTransactionMenue() {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowTransactionsMenue();
    }

    static void _ShowDipositScreen() {
        clsDepositScreen::ShowDepositScreen();
    }
    static void _ShowWithdrawScreen() {
        clsWithdrawScreen::ShowWithdrawScreen();
    }
    static void _ShowTotalBalanceScreen() {
        clsTotalBalancesScreen::ShowTotalBalancesScreen();
    }
    static void _ShowTransferScreen() {
        clsTransferScreen::ShowTransferScreen();
    }
    static void _ShowTransferLogScreen() {
        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void _PerfromMainMenueOption(enTransactionsMenuOptions TransactionMenueOption) {
        switch (TransactionMenueOption)
        {
        case clsTransactionsScreen::eDiposit:
            system("cls");
            _ShowDipositScreen();
            _GoBackToTransactionMenue();
            break;
        case clsTransactionsScreen::eWithdraw:
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionMenue();
            break;
        case clsTransactionsScreen::eShoTotalBalance:
            system("cls");
            _ShowTotalBalanceScreen();
            _GoBackToTransactionMenue();
            break;
        case clsTransactionsScreen::eTransfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionMenue();
            break;
        case clsTransactionsScreen::eTransferLog:
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionMenue();
            break;
        case clsTransactionsScreen::eShowMainMen:
            //Do nothing
            break;
        }
    }

public:
    static void ShowTransactionsMenue() {
        
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions)) {
            return;
        }

        system("cls");
        SetTransactionsColor();
        _DrawScreenHeader("\tTransactions Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Diposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enTransactionsMenuOptions)_ReadTransactionsMenueOption());
    }
};