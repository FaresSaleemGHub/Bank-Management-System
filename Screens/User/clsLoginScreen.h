#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "clsMainScreen.h"
#include "../clsScreen.h"
//#include "Global.h"

class clsLoginScreen :protected clsScreen{
private:
    static  bool _Login(){
        bool LoginFaild = false;
        short LoginFaildCounter = 3;

        string Username, Password;
        do
        {
            if (LoginFaild)
            {
                LoginFaildCounter--;
                cout << "\nInvlaid Username/Password!\n\n";
                cout << "You have " << LoginFaildCounter << " Trial(s) to login.\n\n";
            }

            if (LoginFaildCounter == 0) {
                cout << "You are Locked after 3 failed trials \n\n";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild && LoginFaildCounter >= 0);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:
    static bool ShowLoginScreen() {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        SetLoginScreenColor();

        return _Login();
    }
};

