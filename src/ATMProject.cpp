#include <iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

//enumerations
enum enColors { Green, Red, Gray };
enum enATMMenu { QuickWithDraw = 1, NormalWithDraw, Deposit, CheckBalance, Logout, Exit };

// Data structure
struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false; // Flag
};

//Gobals
const string ClientsFileName = "..\\Files\\Clients.txt";
sClient CurrentClient;
vector <sClient> vClients;

//Functions Prototyp
void PerformClientChoice(enATMMenu enClientChoice);

//Functions
void RefreshConsoleScreen() {
    system("cls");
}
void ShortUnderscoreSeparatorLine() {
    for (short i = 0; i < 15; i++) {
        cout << "---";
    }
    cout << endl;
}
void ShortEqualizationSeparatorLine() {
    for (short i = 0; i < 15; i++) {
        cout << "===";
    }
    cout << endl;
}
void SetScreenColor(enColors Color) {
    switch (Color) {
    case Green:
        system("color 2F"); // Green
        break;
    case Red:
        system("color 4F"); // Red
        break;
    case Gray:
        system("color 7C"); // Gray
        break;
    }
}
void GoBackToMainMenu() {
    cout << "\n\nPress any key to go back to Main Menu...";
    system("pause>0");
}
void EndTheProgram() {
    cout << endl;
    ShortEqualizationSeparatorLine();
    cout << "\t\tGood Bye :)\n";
    ShortEqualizationSeparatorLine();
}
sClient ReadLoginFeilds(sClient& Client) {
    cout << "\nEnter Username: ";
    getline(cin >> ws, Client.AccountNumber);
    cout << "\nEnter PIN Code: ";
    cin >> Client.PinCode;
    return Client;
}

short ReadClientChoice() {
    short Choice = 0;
    cout << "Choose what do you want to do [1-6]: ";
    cin >> Choice;
    return Choice;
}
vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    size_t pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != std::string::npos) {
        sWord = S1.substr(0, pos);
        if (!S1.empty())
            vString.push_back(sWord);
        S1.erase(0, pos + Delim.length());
    }
    if (!S1.empty()) {
        vString.push_back(S1);
    }
    return vString;
}
void SaveFileDataIntoVector(string FileName, vector<string>& vFileContent) {
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open()) {
        string line;
        while (getline(MyFile, line)) {
            vFileContent.push_back(line);
        }
        MyFile.close();
    }
}
void SaveVectorDataIntoFile(string FileName, vector<string>& vFileContent) {
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open()) {
        for (string& line : vFileContent) {
            if (line != "") {
                MyFile << line << endl;
            }
        }
        MyFile.close();
    }
}
string ConvertClientEntityToStringLine(const sClient& Client, const string& Separator = "#//#") {
    return Client.AccountNumber + Separator +
        Client.PinCode + Separator +
        Client.Name + Separator +
        Client.Phone + Separator +
        to_string(Client.AccountBalance);
}
void RefreshClientsFileData() {
    vector<string> StringVectorData;

    for (const sClient& Client : vClients) {
        StringVectorData.push_back(ConvertClientEntityToStringLine(Client));
    }
    SaveVectorDataIntoFile(ClientsFileName, StringVectorData);
}
sClient ConvertStringLineToClientEntity(const string& Line, string Separator = "#//#") {
    sClient Client;
    vector<string> vClientData = SplitString(Line, Separator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);
    return Client;
}
vector<sClient> LoadClientsFromFile() {
    vector<string> vLineClients;
    vector<sClient> vClients;
    SaveFileDataIntoVector(ClientsFileName, vLineClients);
    for (const string& s : vLineClients) {
        vClients.push_back(ConvertStringLineToClientEntity(s));
    }
    return vClients;
}
bool CheckLoginOperation(sClient& Client) {
    for (sClient& client : vClients) {
        if (client.AccountNumber == Client.AccountNumber && client.PinCode == Client.PinCode) {
            Client = client;
            return true;
        }
    }
    return false;
}
void ShowATMMenu() {
    RefreshConsoleScreen();
    ShortEqualizationSeparatorLine();
    cout << "\t\tATM Menu Screen\n";
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposite.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "\t[6] Exit.\n";
    ShortEqualizationSeparatorLine();
}
void ATMMenu() {
    short ClientChoice = 0;
    do {
        SetScreenColor(Gray);
        ShowATMMenu();
        ClientChoice = ReadClientChoice();
        PerformClientChoice(enATMMenu(ClientChoice));
    } while (ClientChoice >= 1 && ClientChoice < 6);
}
void LoginScreen() {
    SetScreenColor(Green);
    if (!vClients.size() > 0) {
        vClients = LoadClientsFromFile();
    }

    ShortEqualizationSeparatorLine();
    cout << "\t\tATM Login Screen\n";
    ShortEqualizationSeparatorLine();

    ReadLoginFeilds(CurrentClient);

    while (!CheckLoginOperation(CurrentClient)) {
        RefreshConsoleScreen();
        ShortEqualizationSeparatorLine();
        cout << "\t\tATM Login Screen\n";
        ShortEqualizationSeparatorLine();
        cout << "Invalid Username/PIN!\n";
        ReadLoginFeilds(CurrentClient);
    }
    ATMMenu();
}
void AccountBalanceScreen() {
    ShortEqualizationSeparatorLine();
    cout << "\t\tATM Login Screen\n";
    ShortEqualizationSeparatorLine();
    cout << "your Balance is " << CurrentClient.AccountBalance << endl;
}
void ShowWithdrawsMenu() {
    printf("\t[1] %d\t\t[2] %d\n", 20, 50);
    printf("\t[3] %d\t\t[4] %d\n", 100, 200);
    printf("\t[5] %d\t\t[6] %d\n", 400, 600);
    printf("\t[7] %d\t\t[8] %d\n", 800, 1000);
    printf("\t[9] Exit\n");
}
bool IsAllowedWithdraw(double WithDrawBalance) {
    if (WithDrawBalance > CurrentClient.AccountBalance) {
        return false;
    }
    return true;
}
void DepositWithdrawOperation(double Amount) {
    CurrentClient.AccountBalance += Amount;

    //to reflect the update on Generic Vector.
    for (sClient& C : vClients) {
        if (C.AccountNumber == CurrentClient.AccountNumber) {
            C.AccountBalance = CurrentClient.AccountBalance;
        }
    }
    RefreshClientsFileData();
}
short ReadQuickWithdrawOption() {
    short choice = 0;
    do {
        cout << "Choose what to withdraw from [1] to [9]: ";
        cin >> choice;
    } while (choice < 1 && choice >9);
    return choice;
}
short GetQuickWithdrawAmmount(short QuickWithdrawOption) {
    switch (QuickWithdrawOption)
    {
    case 1:
        return 20;
        break;
    case 2:
        return 50;
        break;
    case 3:
        return 100;
        break;
    case 4:
        return 200;
        break;
    case 5:
        return 400;
        break;
    case 6:
        return 600;
        break;
    case 7:
        return 800;
        break;
    case 8:
        return 1000;
        break;
    default:
        return 0;
        break;
    }
}
void PerformQuickWithdrawOption(short QuickWithdrawOption) {
    if (QuickWithdrawOption == 9) {
        return;
    }
    string Answer = "Yes";
    short QuickWithdrawBalance = GetQuickWithdrawAmmount(QuickWithdrawOption);

    if (IsAllowedWithdraw(QuickWithdrawBalance)) {
        cout << "Are you sure you want to perform this transaction? ";
        cin >> Answer;
        if (toupper(Answer[0]) == 'Y') {
            DepositWithdrawOperation(QuickWithdrawBalance * -1);
            cout << "\nDone Successfully. Your New Balance is: " << CurrentClient.AccountBalance;
        }
    }
    else {
        cout << "\nThis Ammount Exceeds Your Balance.\n";
    }
}
void QuickWithdrawScreen() {
    char choice = 'A';
    string Answer = "Yes";
    ShortEqualizationSeparatorLine();
    cout << "\t\tATM Quick Withdraw\n";
    ShortEqualizationSeparatorLine();
    ShowWithdrawsMenu();
    cout << "Your Balance is: " << CurrentClient.AccountBalance << endl;
    PerformQuickWithdrawOption(ReadQuickWithdrawOption());
}
double ReadDepositeOrWithdrawAmmount() {
    double Ammount = 0;
    do {
        cout << "Enter a positive ammount multiple of 5's: ";
        cin >> Ammount;
    } while (int(Ammount) % 5 != 0 || Ammount < 0);
    return Ammount;
}
void NormalWithdrawScreen() {
    string Answer = "Yes";
    double Ammount = 0;
    ShortEqualizationSeparatorLine();
    cout << "\t\tATM Normal Withdraw\n";
    ShortEqualizationSeparatorLine();

    Ammount = ReadDepositeOrWithdrawAmmount();

    if (IsAllowedWithdraw(Ammount)) {
        cout << "Are you sure you want to perform this transaction? ";
        cin >> Answer;
        if (toupper(Answer[0]) == 'Y') {
            DepositWithdrawOperation(Ammount * -1);
            cout << "\nDone Successfully. Your New Balance is: " << CurrentClient.AccountBalance;
        }
    }
    else {
        cout << "\nThis Ammount Exceeds Your Balance.\n";
    }
}
void DepositeScreen() {
    string Answer = "Yes";
    double Ammount = 0;
    ShortEqualizationSeparatorLine();
    cout << "\t\tATM Deposite\n";
    ShortEqualizationSeparatorLine();

    Ammount = ReadDepositeOrWithdrawAmmount();

    cout << "Are you sure you want to perform this transaction ?";
    cin >> Answer;
    if (toupper(Answer[0]) == 'Y') {
        DepositWithdrawOperation(Ammount);
        cout << "\nDone Successfully. Your New Balance is: " << CurrentClient.AccountBalance;
    }    
}
int main()
{
    LoginScreen();
}

void PerformClientChoice(enATMMenu enClientChoice) {
    switch (enClientChoice)
    {
    case QuickWithDraw:
        SetScreenColor(Green);
        RefreshConsoleScreen();
        QuickWithdrawScreen();
        GoBackToMainMenu();
        break;
    case NormalWithDraw:
        SetScreenColor(Green);
        RefreshConsoleScreen();
        NormalWithdrawScreen();
        GoBackToMainMenu();
        break;
    case Deposit:
        SetScreenColor(Green);
        RefreshConsoleScreen();
        DepositeScreen();
        GoBackToMainMenu();
        break;
    case CheckBalance:
        SetScreenColor(Green);
        RefreshConsoleScreen();
        AccountBalanceScreen();
        GoBackToMainMenu();
        break;
    case Logout:
        SetScreenColor(Green);
        RefreshConsoleScreen();
        LoginScreen();
        GoBackToMainMenu();
        break;
    case Exit:
        SetScreenColor(Red);
        RefreshConsoleScreen();
        EndTheProgram();
        GoBackToMainMenu();
        break;
    default:
        //Nothing
        break;
    }
}
