// Include built-in libraries
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

// Include custom libraries
#include "F:\IT\Knowledg\AbuHadhoud\MyLibraries\MyMathLibrary.h"
#include "F:\IT\Knowledg\AbuHadhoud\MyLibraries\MyArrayLibrary.h"
#include "F:\IT\Knowledg\AbuHadhoud\MyLibraries\MyReadInputsLibrary.h"
#include "F:\IT\Knowledg\AbuHadhoud\MyLibraries\MyFilesLibrary.h"
#include "F:\IT\Knowledg\AbuHadhoud\MyLibraries\MySecurityLibrary.h"

using namespace std;

// Enumerations
enum enColors { Green, Red, Gray };
enum enMainMenu { Add = 1, Print, Find, Update, Delete, Transactions, ManageUsers, Logout, Exit};
enum enTransactionsMainMenu { Deposit = 1, Withdraw, TotalBalance };
enum enManageUsersMainMenu { ListUsers = 1, AddUser, DeleteUser, UpdateUser, FindUser, MainMenue};
enum enMainMenuePermissions {
    FullAccessP = -1, ShowClientListP = 1, AddNewClientP = 2, DeleteClientP = 4,
    UpdateclientP = 8, FindClientP = 16, TransactionsP = 32, ManageUsersP = 64
};

// Data structure
struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false; // Flag
};

struct sUser {
    string Name;
    string Password;
    short Permissions = 0;
    bool MarkForDelete = false; // Flag
};

// Global constants
const string ClientsFileName = "..\\Files\\Clients.txt";
const string UsersFileName = "..\\Files\\Users.txt";
vector<sClient> vClients;
vector<sUser> vUsers;
sUser CurrentUser;//to access it via All screens

// Function declaration (prototype)
void BankMenu();
void DepositScreen();
void PerformUserChoiceOfManageUsers(enManageUsersMainMenu enUserChoice);
void PerformUserChoiceOfTransactions(enTransactionsMainMenu);
void PerformUserChoiceOfManageUsers(enManageUsersMainMenu(Choice));
sUser GiveUserPermissions(sUser& User);
bool FindClientScreen(sClient&, string&, bool = true);

void PerformUserChoice(enMainMenu enUserChoice);

// Function definitions
void RefreshConsoleScreen() {
    system("cls");
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

void LongSeparatorLine() {
    for (short i = 0; i < 15; i++) {
        cout << "______";
    }
    cout << endl;
}

void ShortEqualizationSeparatorLine() {
    for (short i = 0; i < 15; i++) {
        cout << "===";
    }
    cout << endl;
}

void ShortUnderscoreSeparatorLine() {
    cout << endl;
    for (short i = 0; i < 15; i++) {
        cout << "---";
    }
    cout << endl;
}

bool CheckIfAccountNumberExists(const string& AccountNumber) {
    for (const sClient& s : vClients) {
        if (s.AccountNumber == AccountNumber) {
            return true;
        }
    }
    return false;
}
bool CheckIfUsernameExists(string Username) {
    for (const sUser& s : vUsers) {
        if (s.Name == Username) {
            return true;
        }
    }
    return false;
}

sClient ReadNewClient() {
    sClient Client;
    cout << "Enter Account Number: ";
    getline(cin >> ws, Client.AccountNumber);

    while (CheckIfAccountNumberExists(Client.AccountNumber)) {
        cout << "Client with [" << Client.AccountNumber << "] already exists, Enter another Account number: ";
        getline(cin >> ws, Client.AccountNumber);
    }
    cout << "Enter PinCode: ";
    getline(cin, Client.PinCode);
    cout << "Enter Name: ";
    getline(cin, Client.Name);
    cout << "Enter Phone: ";
    getline(cin, Client.Phone);
    cout << "Enter Account Balance: ";
    cin >> Client.AccountBalance;

    return Client;
}

string ReadAccountNumber(string& AccountNumber) {
    cout << "Please Enter Account Number: ";
    cin >> AccountNumber;
    return AccountNumber;
}

sUser ReadNewUser() {
    sUser User;
    cout << "Enter Username: ";
    getline(cin >> ws, User.Name);

    while (CheckIfUsernameExists(User.Name)) {
        cout << "User with [" << User.Name << "] already exists, Enter another User name: ";
        getline(cin >> ws, User.Name);
    }
    cout << "Enter Password: ";
    getline(cin >> ws, User.Password);

    GiveUserPermissions(User);

    return User;
}

sUser ReadLoginFeilds(sUser& User) {
    cout << "\nEnter Username: ";
    getline(cin >>ws, User.Name);
    cout << "\nEnter Passwors: ";
    cin >> User.Password;
    return User;
}

string ConvertClientEntityToStringLine(const sClient& Client, const string& Separator = "#//#") {
    return Client.AccountNumber + Separator +
        Client.PinCode + Separator +
        Client.Name + Separator +
        Client.Phone + Separator +
        to_string(Client.AccountBalance);
}

sClient ConvertStringLineToClientEntity(const string& Line, string Separator = "#//#") {
    sClient Client;
    vector<string> vClientData = MySecurityLibrary::SplitString(Line, Separator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);
    return Client;
}
string ConvertUserEntityToStringLine(const sUser& User, const string& Separator = "#//#") {
    return User.Name+ Separator +
        User.Password+ Separator +
        to_string(User.Permissions);
}
sUser ConvertStringLineToUserEntity(const string& Line, string Separator = "#//#") {
    sUser User;
    vector<string> vUserData = MySecurityLibrary::SplitString(Line, Separator);
    User.Name = vUserData[0];
    User.Password = vUserData[1];
    User.Permissions = stoi(vUserData[2]);
    return User;
}

void ShowTransactionsMainMenu() {
    RefreshConsoleScreen();
    ShortEqualizationSeparatorLine();
    cout << "\t\tTransactions Menu Screen\n";
    cout << "\t[1] Deposit Screen.\n";
    cout << "\t[2] Withdraw Screen.\n";
    cout << "\t[3] Total Balances Screen.\n";
    cout << "\t[4] Main Menu Screen.\n";
    ShortEqualizationSeparatorLine();
}
void ShowManageUsersMainMenu() {
    RefreshConsoleScreen();
    ShortEqualizationSeparatorLine();
    cout << "\t\tManage Users Menu Screen\n";
    cout << "\t[1] List Users.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delete User.\n";
    cout << "\t[4] Update User.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] MainMenu.\n";
    ShortEqualizationSeparatorLine();
}

void ShowMainMenu() {
    RefreshConsoleScreen();
    ShortEqualizationSeparatorLine();
    cout << "\t\tMain Menu Screen\n";
    cout << "\t[1] Add Client.\n";
    cout << "\t[2] Print Clients.\n";
    cout << "\t[3] Find Client.\n";
    cout << "\t[4] Update Client.\n";
    cout << "\t[5] Delete Client.\n";
    cout << "\t[6] Transactions Screen.\n";
    cout << "\t[7] Manage Users.\n";
    cout << "\t[8] Logout.\n";
    cout << "\t[9] Exit.\n";
    ShortEqualizationSeparatorLine();
}

void PrintClientCard(const sClient& Client) {
    cout << "\nThe following are the client details:";
    ShortUnderscoreSeparatorLine();
    cout << "Account Number: " << Client.AccountNumber;
    cout << "\nPin Code: " << Client.PinCode;
    cout << "\nName: " << Client.Name;
    cout << "\nPhone: " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    ShortUnderscoreSeparatorLine();
}
void PrintUserCard(const sUser& User) {
    cout << "\nThe following are the client details:";
    ShortUnderscoreSeparatorLine();
    cout << "Username: " << User.Name;
    cout << "\nPassword: " << User.Password;
    cout << "\nPermissions: " << User.Permissions;
    ShortUnderscoreSeparatorLine();
}

short UserChoice() {
    short Choice = 0;
    cout << "Choose what do you want to do [1-9]: ";
    cin >> Choice;
    return Choice;
}

short UserChoiceOfTransactions() {
    short Choice = 0;
    cout << "Choose what do you want to do [1-4]: ";
    cin >> Choice;
    return Choice;
}
short UserChoiceOfManageUsers() {
    short Choice = 0;
    cout << "Choose what do you want to do [1-6]: ";
    cin >> Choice;
    return Choice;
}

void AddDataLineToFile(const string& FileName, const string& stDataLine) {
    fstream MyFile(FileName, ios::out | ios::app);
    if (MyFile.is_open()) {
        MyFile << stDataLine << endl;
        MyFile.close();

    }
}

bool CheckaccessPermission(enMainMenuePermissions Permission) {
    if (CurrentUser.Permissions == enMainMenuePermissions::FullAccessP) {
        return true;
    }
    if ((Permission & CurrentUser.Permissions) == Permission) {
        return true;
    }
    return false;
}
    
void ShowAccessDeniedMessage() {
    ShortUnderscoreSeparatorLine();
    cout << "Access Denied,\nYou Don't Have Permission To Do This,\nPlease Contact Your Admin.";
    ShortUnderscoreSeparatorLine();
}

sClient AddNewClient() {
    sClient Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertClientEntityToStringLine(Client));
    return Client;
}

void AddNewClientsOperation() {
    string AddMore = "Yes";
    do {
        cout << "\nAdd New Client:\n\n";
        vClients.push_back(AddNewClient());
        cout << "\nClient Added Successfully, do you want to add more? (Y/N): ";
        cin >> AddMore;
    } while (toupper(AddMore[0]) == 'Y');
}

void AddNewClientsScreen() {
    if (!CheckaccessPermission(enMainMenuePermissions::AddNewClientP)) {
        ShowAccessDeniedMessage();
        return;
    }
    ShortUnderscoreSeparatorLine();
    cout << "\t\tAdd New Client Screen";
    ShortUnderscoreSeparatorLine();
    AddNewClientsOperation();
}

vector<sClient> LoadClientsFromFile() {
    vector<string> vLineClients;
    vector<sClient> vClients;
    MyFilesLib::SaveFileDataIntoVector(ClientsFileName, vLineClients);
    for (const string& s : vLineClients) {
        vClients.push_back(ConvertStringLineToClientEntity(s));
    }
    return vClients;
}
vector<sUser> LoadusersFromFile() {
    vector<string> vLineUsers;
    vector<sUser> vUsers;
    MyFilesLib::SaveFileDataIntoVector(UsersFileName, vLineUsers);
    for (const string& s : vLineUsers) {
        vUsers.push_back(ConvertStringLineToUserEntity(s));
    }
    return vUsers;
}

void PrintClientCardAsMenu(const sClient& Client) {
    cout << left << setw(15) << Client.AccountNumber;
    cout << " | " << left << setw(10) << Client.PinCode;
    cout << " | " << left << setw(30) << Client.Name;
    cout << " | " << left << setw(12) << Client.Phone;
    cout << " | " << left << setw(12) << Client.AccountBalance;
}

void PrintClientCardAsMenuForTransactions(const sClient& Client) {
    cout << left << setw(15) << Client.AccountNumber;
    cout << " | " << left << setw(30) << Client.Name;
    cout << " | " << left << setw(12) << Client.AccountBalance;
}

void ShowAllClientsScreen() {

   if (!CheckaccessPermission(enMainMenuePermissions::ShowClientListP)) {
        ShowAccessDeniedMessage();
        return;
    }

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s)\n";
    LongSeparatorLine();
    cout << left << setw(15) << "Account Number";
    cout << " | " << left << setw(10) << "Pin Code";
    cout << " | " << left << setw(30) << "Client Name";
    cout << " | " << left << setw(12) << "Phone";
    cout << " | " << left << setw(12) << "Balance" << endl;
    LongSeparatorLine();
    for (const sClient& s : vClients) {
        PrintClientCardAsMenu(s);
        cout << endl;
    }
    LongSeparatorLine();
}

void PrintClientCardBalanceAsMenu(const sClient& Client) {
    cout << left << setw(15) << Client.AccountNumber;
    cout << " | " << left << setw(30) << Client.Name;
    cout << " | " << left << setw(12) << Client.AccountBalance;
}

void ShowTotalBalancesScreen() {
    double TotalBalance = 0;
    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s)\n";
    LongSeparatorLine();
    cout << left << setw(15) << "Account Number";
    cout << " | " << left << setw(30) << "Client Name";
    cout << " | " << left << setw(12) << "Balance" << endl;
    LongSeparatorLine();
    for (const sClient& s : vClients) {
        PrintClientCardBalanceAsMenu(s);
        TotalBalance += s.AccountBalance;
        cout << endl;
    }
    LongSeparatorLine();
    cout << "\n\t\t\t\t\tTotal Balances = " << TotalBalance << endl;
}

bool FindClientByAccountNumber(sClient& Client, const string& AccountNumber) {
    for (const sClient& s : vClients) {
        if (s.AccountNumber == AccountNumber) {
            Client = s;
            return true;
        }
    }
    return false;
}

bool FindClientScreen(sClient& Client, string& AccountNumber, bool isFindScreen) {

    if (isFindScreen) {
        
        if (!CheckaccessPermission(enMainMenuePermissions::FindClientP)) {
            ShowAccessDeniedMessage();
            return false;
        }
        else {
            ShortUnderscoreSeparatorLine();
            cout << "\t\tFind Client Screen";
            ShortUnderscoreSeparatorLine();
        }
    }

    cout << "Please Enter the Account Number: ";
    cin >> AccountNumber;

    if (FindClientByAccountNumber(Client, AccountNumber)) {
        PrintClientCard(Client);
        return true;
    }
    else {
        cout << "\nThe Client with Account Number " << AccountNumber << " Not Found !!\n";
        return false;
    }
}

void RefreshClientsFileData() {
    vector<sClient> UpdatedFileData;
    vector<string> UpdatedStringFileData;

    for (const sClient& Client : vClients) {
        if (!Client.MarkForDelete) {
            UpdatedFileData.push_back(Client);
            UpdatedStringFileData.push_back(ConvertClientEntityToStringLine(Client));
        }
    }
    MyFilesLib::SaveVectorDataIntoFile(ClientsFileName, UpdatedStringFileData);
    vClients = UpdatedFileData;
}

bool MarkClientForDelete(const string& AccountNumber) {
    for (sClient& Client : vClients) {
        if (Client.AccountNumber == AccountNumber) {
            Client.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

bool MarkUserForDelete(const string& Username) {
    for (sUser& User : vUsers) {
        if (User.Name == Username) {
            User.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

void DeleteClientScreen(string& AccountNumber) {    
    if (!CheckaccessPermission(enMainMenuePermissions::DeleteClientP)) {
        ShowAccessDeniedMessage();
        return;
    }

    sClient Client;
    string Answer = "Yes";

    ShortUnderscoreSeparatorLine();
    cout << "\t\tDelete Client Screen";
    ShortUnderscoreSeparatorLine();

    if (FindClientScreen(Client, AccountNumber, false)) {
        cout << "\nAre you sure you want to delete this client account? (Y/N): ";
        cin >> Answer;
        if (toupper(Answer[0]) == 'Y') {
            MarkClientForDelete(AccountNumber);
            RefreshClientsFileData();
            cout << "\nClient Deleted Successfully.";
        }
    }
}

bool UpdateClient(sClient& ClientForUpdate) {
    cout << "\nEnter PinCode: ";
    getline(cin >> ws, ClientForUpdate.PinCode);
    cout << "Enter Name: ";
    getline(cin, ClientForUpdate.Name);
    cout << "Enter Phone: ";
    getline(cin, ClientForUpdate.Phone);
    cout << "Enter Account Balance: ";
    cin >> ClientForUpdate.AccountBalance;

    for (sClient& C : vClients) {
        if (C.AccountNumber == ClientForUpdate.AccountNumber) {
            C = ClientForUpdate;
            RefreshClientsFileData();
            return true;
        }
    }
    return false;
}

void UpdateClientScreen() {
    if (!CheckaccessPermission(enMainMenuePermissions::UpdateclientP)) {
        ShowAccessDeniedMessage();
        return;
    }

    string AccountNumber;
    sClient Client;
    string Answer = "Yes";

    ShortUnderscoreSeparatorLine();
    cout << "\t\tUpdate Client Info Screen";
    ShortUnderscoreSeparatorLine();

    if (FindClientScreen(Client, AccountNumber, false)) {
        cout << "\nAre you sure you want to update this account? (Y/N): ";
        cin >> Answer;
        if (toupper(Answer[0]) == 'Y') {
            if (UpdateClient(Client)) {
                cout << "\nClient Updated Successfully!\n";
            }
            else {
                cout << "\n\nClient Updating Failed!\n";
            }
        }
    }
}
void TransactionsScreen() {
    short Choice;
    if (!CheckaccessPermission(enMainMenuePermissions::TransactionsP)) {
        ShowAccessDeniedMessage();
        return;
    }
    do {
        SetScreenColor(Gray);
        ShowTransactionsMainMenu();
        Choice = UserChoiceOfTransactions();
        PerformUserChoiceOfTransactions(enTransactionsMainMenu(Choice));
    } while (Choice >= 1 && Choice <= 3);
}
void ManageUsersScreen() {
    short Choice;
    if (!CheckaccessPermission(enMainMenuePermissions::ManageUsersP)) {
        ShowAccessDeniedMessage();
        return;
    }
    do {
        SetScreenColor(Gray);
        ShowManageUsersMainMenu();
        Choice = UserChoiceOfManageUsers();
        PerformUserChoiceOfManageUsers(enManageUsersMainMenu(Choice));
    } while (Choice >= 1 && Choice <= 6);
}
void EndTheProgram() {
    cout << endl;
    ShortEqualizationSeparatorLine();
    cout << "\t\tGood Bye :)\n";
    ShortEqualizationSeparatorLine();
}

void DepositWithdrawOperation(sClient& Client, double Amount) {
    for (sClient& C : vClients) {
        if (C.AccountNumber == Client.AccountNumber) {
            C.AccountBalance += Amount;
        }
    }
}

void WithdrawScreen() {
    sClient Client;
    string AccountNumber = "";
    string Answer = "Yes";
    double WithdrawAmount = 0;

    ShortUnderscoreSeparatorLine();
    cout << "\t\tWithdraw Screen";
    ShortUnderscoreSeparatorLine();

    if (FindClientScreen(Client, AccountNumber, false)) {
        cout << "\nPlease Enter withdraw amount: ";
        cin >> WithdrawAmount;
        while (WithdrawAmount > Client.AccountBalance) {
            cout << "Amount Exceeds the balance, you can withdraw up to: " << Client.AccountBalance << endl;
            cout << "\nPlease Enter withdraw amount: ";
            cin >> WithdrawAmount;
        }

        cout << "\nAre you sure you want to perform this transaction? (Y/N): ";
        cin >> Answer;

        if (toupper(Answer[0]) == 'Y') {
            DepositWithdrawOperation(Client, -WithdrawAmount);
            RefreshClientsFileData();
            cout << "\nWithdraw Operation Done Successfully.\n";
        }
    }
}

bool CheckLoginOperation(sUser & User) {
    for (sUser &user : vUsers) {
        if (user.Name == User.Name && user.Password == User.Password) {
            User = user;
            return true;
        }
    }
    return false;
}
void LoginScreen() {
    SetScreenColor(Green);
    vUsers = LoadusersFromFile();
    
    ShortUnderscoreSeparatorLine();
    cout << "\t\tLogin Screen";
    ShortUnderscoreSeparatorLine();

    ReadLoginFeilds(CurrentUser);

    while (!CheckLoginOperation(CurrentUser)) {
        RefreshConsoleScreen();
        ShortUnderscoreSeparatorLine();
        cout << "\t\tLogin Screen";
        ShortUnderscoreSeparatorLine();
        cout << "Invalid Username/Password!\n";
        ReadLoginFeilds(CurrentUser);
    }
    BankMenu();
}

void PrintUserCardAsMenu(const sUser& User) {
    cout << left << setw(20) << User.Name;
    cout << " | " << left << setw(15) << User.Password;
    cout << " | " << left << setw(10) << User.Permissions;
}

void ListUsersScreen() {
    cout << "\n\t\t\t\tUsers List (" << vUsers.size() << ") User(s)\n";
    LongSeparatorLine();
    cout << left << setw(20) << "User Name";
    cout << " | " << left << setw(15) << "Password";
    cout << " | " << left << setw(10) << "Permission";
    cout << endl;
    LongSeparatorLine();
    for (const sUser& s : vUsers) {
        PrintUserCardAsMenu(s);
        cout << endl;
    }
    LongSeparatorLine();
}

sUser AddNewUser() {
    sUser User = ReadNewUser();
    AddDataLineToFile(UsersFileName, ConvertUserEntityToStringLine(User));
    return User;
}

void AddNewUsersOperation() {
    string AddMore = "Yes";
    do {
        cout << "\nAdd New User:\n\n";
        vUsers.push_back(AddNewUser());
        cout << "\nUser Added Successfully, do you want to add more? (Y/N): ";
        cin >> AddMore;
    } while (toupper(AddMore[0]) == 'Y');
}

void AddNewUsersScreen() {
    ShortUnderscoreSeparatorLine();
    cout << "\t\tAdd New User Screen";
    ShortUnderscoreSeparatorLine();
    AddNewUsersOperation();
}

void RefreshUsersFileData() {
    vector<sUser> UpdatedFileData;
    vector<string> UpdatedStringFileData;

    for (const sUser& User : vUsers) {
        if (!User.MarkForDelete) {
            UpdatedFileData.push_back(User);
            UpdatedStringFileData.push_back(ConvertUserEntityToStringLine(User));
        }
    }
    MyFilesLib::SaveVectorDataIntoFile(UsersFileName, UpdatedStringFileData);
    vUsers = UpdatedFileData;
}

bool FindUserByUsername(sUser& User, const string& Username) {
    for (const sUser& u : vUsers) {
        if (u.Name == Username) {
            User = u;
            return true;
        }
    }
    return false;
}

bool FindUserScreen(sUser& User, string& Username, bool isFindScreen = true) {
    if (isFindScreen) {
        ShortUnderscoreSeparatorLine();
        cout << "\t\tFind User Screen";
        ShortUnderscoreSeparatorLine();
    }
    cout << "Please Enter the Username: ";
    cin >> Username;

    if (FindUserByUsername(User, Username)) {
        PrintUserCard(User);
        return true;
    }
    else {
        cout << "\nThe User with userame " << Username << " Not Found !!\n";
        return false;
    }
}

void DeleteUserScreen(string& Username) {
    sUser User;
    string Answer = "Yes";

    ShortUnderscoreSeparatorLine();
    cout << "\t\tDelete User Screen";
    ShortUnderscoreSeparatorLine();

    if (FindUserScreen(User, Username, false)) {
        cout << "\nAre you sure you want to delete this user account? (Y/N): ";
        cin >> Answer;
        if (toupper(Answer[0]) == 'Y') {
            MarkUserForDelete(Username);
            RefreshUsersFileData();
            cout << "\nUser Deleted Successfully.";
        }
    }
}

bool UpdateUserOperation(sUser& UserForUpdate) {
    cout << "\nEnter password: ";
    getline(cin >> ws, UserForUpdate.Password);
    GiveUserPermissions(UserForUpdate);

    for (sUser& u : vUsers) {
        if (u.Name == UserForUpdate.Name) {
            u = UserForUpdate;
            RefreshUsersFileData();
            return true;
        }
    }
    return false;
}

void UpdateUserScreen() {
    string Username;
    sUser User;
    string Answer = "Yes";

    ShortUnderscoreSeparatorLine();
    cout << "\t\tUpdate User Info Screen";
    ShortUnderscoreSeparatorLine();

    if (FindUserScreen(User, Username, false)) {
        cout << "\nAre you sure you want to update this account? (Y/N): ";
        cin >> Answer;
        if (toupper(Answer[0]) == 'Y') {
            if (UpdateUserOperation(User)) {
                cout << "\nUser Updated Successfully!\n";
            }
            else {
                cout << "\n\nUser Updating Failed!\n";
            }
        }
    }
}

int main() {
    LoginScreen();
}

void BankMenu() {
    vClients = LoadClientsFromFile();
    short MainChoice = 0;
    do {
        SetScreenColor(Gray);
        ShowMainMenu();
        MainChoice = UserChoice();
        PerformUserChoice(enMainMenu(MainChoice));
    } while (MainChoice >= 1 && MainChoice <= 9);
}

void DepositScreen() {
    sClient Client;
    string AccountNumber = "";
    string Answer = "Yes";
    double DepositAmount = 0;

    ShortUnderscoreSeparatorLine();
    cout << "\t\tDeposit Screen";
    ShortUnderscoreSeparatorLine();

    if (FindClientScreen(Client, AccountNumber, false)) {
        cout << "\nPlease Enter deposit amount: ";
        cin >> DepositAmount;

        cout << "\nAre you sure you want to perform this transaction? (Y/N): ";
        cin >> Answer;

        if (toupper(Answer[0]) == 'Y') {
            DepositWithdrawOperation(Client, DepositAmount);
            RefreshClientsFileData();
            cout << "\nDeposit Operation Done Successfully.\n";
        }
    }
}

void PerformUserChoice(enMainMenu enUserChoice) {
    string AccountNumber;
    sClient Client;
    short Choice = 0;
    switch (enUserChoice) {
    case Add:
        SetScreenColor(Green);
        RefreshConsoleScreen();
        AddNewClientsScreen();
        GoBackToMainMenu();
        break;
    case Print:
        SetScreenColor(Green);
        RefreshConsoleScreen();
        ShowAllClientsScreen();
        GoBackToMainMenu();
        break;
    case Find:
        SetScreenColor(Green);
        RefreshConsoleScreen();
        FindClientScreen(Client, AccountNumber);
        GoBackToMainMenu();
        break;
    case Update:
        SetScreenColor(Green);
        RefreshConsoleScreen();
        UpdateClientScreen();
        GoBackToMainMenu();
        break;
    case Delete:
        SetScreenColor(Green);
        RefreshConsoleScreen();
        DeleteClientScreen(AccountNumber);
        GoBackToMainMenu();
        break;
    case Transactions:
        RefreshConsoleScreen();
        TransactionsScreen();
        GoBackToMainMenu();
        break;
    case ManageUsers:
        RefreshConsoleScreen();
        ManageUsersScreen();
        GoBackToMainMenu();
        break;
    case Logout:
        RefreshConsoleScreen();
        LoginScreen();
        break;
    case Exit:
        SetScreenColor(Red);
        RefreshConsoleScreen();
        EndTheProgram();
        break;

    default:
        SetScreenColor(Red);
        RefreshConsoleScreen();
        EndTheProgram();
        break;
    }
}

void PerformUserChoiceOfTransactions(enTransactionsMainMenu enUserChoice) {
    string AccountNumber;
    sClient Client;
    switch (enUserChoice) {
    case Deposit:
        SetScreenColor(Green);
        RefreshConsoleScreen();
        DepositScreen();
        GoBackToMainMenu();
        break;
    case Withdraw:
        SetScreenColor(Green);
        RefreshConsoleScreen();
        WithdrawScreen();
        GoBackToMainMenu();
        break;
    case TotalBalance:
        SetScreenColor(Green);
        RefreshConsoleScreen();
        ShowTotalBalancesScreen();
        GoBackToMainMenu();
        break;
    default:
        SetScreenColor(Gray);
        RefreshConsoleScreen();
        BankMenu();
        break;
    }
}

void PerformUserChoiceOfManageUsers(enManageUsersMainMenu enUserChoice) {
    sUser User;
    string username = "";

    switch (enUserChoice)
    {
    case ListUsers:
        SetScreenColor(Green);
        RefreshConsoleScreen();
        ListUsersScreen();
        GoBackToMainMenu();
        break;
    case AddUser:
        SetScreenColor(Green);
        RefreshConsoleScreen();
        AddNewUsersScreen();
        GoBackToMainMenu();
        break;
    case DeleteUser:
        SetScreenColor(Green);
        RefreshConsoleScreen();
        DeleteUserScreen(username);
        GoBackToMainMenu();
        break;
    case UpdateUser:
        SetScreenColor(Green);
        RefreshConsoleScreen();
        UpdateUserScreen();
        GoBackToMainMenu();
        break;
    case FindUser:
        SetScreenColor(Green);
        RefreshConsoleScreen();
        FindUserScreen(User, username);
        GoBackToMainMenu();
        break;
    case MainMenue:
        SetScreenColor(Gray);
        RefreshConsoleScreen();
        BankMenu();
        break;
    default:
        SetScreenColor(Gray);
        RefreshConsoleScreen();
        BankMenu();
        break;
    }
}
sUser GiveUserPermissions(sUser& User) {
    string Answer = "No";
    short PermittionsCount = 0;

    cout << "\nDo you want to give full Access? y/n? ";
    cin >> Answer;
    
    if (toupper(Answer[0]) == 'Y') {
        User.Permissions = enMainMenuePermissions::FullAccessP;
    }
    else {
        cout << "\nDo you want to give access to:\n";
        cout << "Show Client List? y/n? ";
        cin >> Answer;
        if (toupper(Answer[0]) == 'Y') {
            User.Permissions += enMainMenuePermissions::ShowClientListP;
        }

        cout << "Add Client? y/n?";
        cin >> Answer;
        if (toupper(Answer[0]) == 'Y') {
            User.Permissions += enMainMenuePermissions::AddNewClientP;
        }

        cout << "Delete Client? y/n?";
        cin >> Answer;
        if (toupper(Answer[0]) == 'Y') {
            User.Permissions += enMainMenuePermissions::DeleteClientP;
        }

        cout << "Update Client? y/n?";
        cin >> Answer;
        if (toupper(Answer[0]) == 'Y') {
            User.Permissions += enMainMenuePermissions::UpdateclientP;
        }

        cout << "Find Client? y/n?";
        cin >> Answer;
        if (toupper(Answer[0]) == 'Y') {
            User.Permissions += enMainMenuePermissions::FindClientP;
        }

        cout << "Transactions? y/n?";
        cin >> Answer;
        if (toupper(Answer[0]) == 'Y') {
            User.Permissions += enMainMenuePermissions::TransactionsP;
        }

        cout << "Manage Users? y/n?";
        cin >> Answer;
        if (toupper(Answer[0]) == 'Y') {
            User.Permissions += enMainMenuePermissions::ManageUsersP;
        }
    }
    return User;
}
