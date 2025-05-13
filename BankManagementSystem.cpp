#include <iostream>
#include <iomanip>
#include "Core/clsClient.h"
#include "Lib/clsInputValidate.h"
#include "Lib/clsUtil.h"
#include "Screens/User/clsMainScreen.h"
#include "Screens/User/clsLoginScreen.h"

int main() {
    while (true) {
        if (clsLoginScreen::ShowLoginScreen() == false) {
            break;
        }
    }
    return 0;
}