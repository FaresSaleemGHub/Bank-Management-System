#pragma once
#include <iostream>
#include "../Core/clsUser.h"
#include "../Lib/clsUtil.h"
#include "../Global.h"

using namespace std;

class clsScreen {

protected:
    static void _DrawScreenHeader(string Title, string SubTitle = ""){
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n";
        cout << "\n\t\t\t\t\tUser: " << 
            (!CurrentUser.IsEmpty() ? CurrentUser.UserName : "No Users Yet") << "\n";
        cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n\n";
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission){
        if (!CurrentUser.CheckAccessPermission(Permission)){
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }

    static void SetLoginScreenColor() {
        clsUtil::SetScreenColor(clsUtil::Blue, clsUtil::BrightWhite);
    }
    
    static void SetMainMenuColor() {
        clsUtil::SetScreenColor(clsUtil::Green, clsUtil::Black);
    }

    static void SetManageClientsColor() {
        clsUtil::SetScreenColor(clsUtil::LightGray, clsUtil::Blue);
    }

    static void SetManageUsersColor() {
        clsUtil::SetScreenColor(clsUtil::Purple, clsUtil::BrightWhite);
    }

    static void SetTransactionsColor() {
        clsUtil::SetScreenColor(clsUtil::Aqua, clsUtil::Black);
    }

    static void SetLoginRegisterColor() {
        clsUtil::SetScreenColor(clsUtil::LightGray, clsUtil::Black);
    }

    static void SetCurrencyExchangeColor() {
        clsUtil::SetScreenColor(clsUtil::LightGray, clsUtil::Black);
    }

};
