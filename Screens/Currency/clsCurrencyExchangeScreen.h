#pragma once
#include <iostream>
#include <iomanip>
#include "../clsScreen.h"
#include "../../Lib/clsInputValidate.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeMainScreen : protected clsScreen {
private:
    enum enCurrencyExchangeMenueOptions {
        ListCurrencies = 1, FindCurrency, UpdateRate, CurrencyCalculator, MainMenu
    };

    static short ReadCurrencyExchangeMenueOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate<short>::ReadTNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _GoBackToCurrencyExhangeMenue() {
        cout << "\n\nPress any key to go back to CurrencyExhange Menue...";
        system("pause>0");
        ShowCurrencyExchangeMenue();
    }

    static void _ShowCurreciesListScreen() {
        clsListCurrenciesScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrecyScreen() {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateCurreyScreen() {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurreciesCalculatorScreen() {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformCurrencyExchangeMenueOption(enCurrencyExchangeMenueOptions Option) {
        switch (Option)
        {
        case clsCurrencyExchangeMainScreen::ListCurrencies:
        {
            system("cls");
            _ShowCurreciesListScreen();
            _GoBackToCurrencyExhangeMenue();
            break;
        }
        case clsCurrencyExchangeMainScreen::FindCurrency:
        {
            system("cls");
            _ShowFindCurrecyScreen();
            _GoBackToCurrencyExhangeMenue();
            break;
        }
        case clsCurrencyExchangeMainScreen::UpdateRate:
        {
            system("cls");
            _ShowUpdateCurreyScreen();
            _GoBackToCurrencyExhangeMenue();
            break;
        }
        case clsCurrencyExchangeMainScreen::CurrencyCalculator:
        {
            system("cls");
            _ShowCurreciesCalculatorScreen();
            _GoBackToCurrencyExhangeMenue();
            break;
        }
        case clsCurrencyExchangeMainScreen::MainMenu:
            break;
        default:
            break;
        }
    }

public:
    static void ShowCurrencyExchangeMenue() {
        if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange)) {
            return;
        }

        system("cls");
        _DrawScreenHeader("\tCurrency Exchange Main Screen");
        SetCurrencyExchangeColor();

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] ListCurrencies.\n";
        cout << setw(37) << left << "" << "\t[2] FindCurrency.\n";
        cout << setw(37) << left << "" << "\t[3] UpdateRate.\n";
        cout << setw(37) << left << "" << "\t[4] CurrencyCalculator.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyExchangeMenueOption((enCurrencyExchangeMenueOptions)ReadCurrencyExchangeMenueOption());
    }
};