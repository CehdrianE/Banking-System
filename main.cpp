#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Bank{
    private:
        string firstName;
        string lastName;
        string accountName;
        string password;
        double initialBal;  
    public:
        bool menu();
        void getAccount();
        void printAccount();
        void deposit();
};

string getString(string prompt);

bool Bank::menu(){
    bool enable = true;
    cout << "-------------------------------\n" 
        <<  "|     Welcome to the Bank!    |\n" 
        << "|     How May We Help You?    |\n" 
        << "-------------------------------\n"
        << "|        0) Exit Bank         |\n"
        << "|      1) Create Account      |\n"
        << "-------------------------------\n"
        << "|      Type in the Digit      |\n" 
        << "|  Associated With the Action |\n"
        << "-------------------------------\n";
    int selection = -1;
    cout << "Enter Digit: ";
    cin >> selection;
    while(!cin || selection < 0 || selection > 2){
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Error: Invalid Input\nTry Again!\n";
        cout << "Enter Digit: ";
        cin >> selection;
    }
    switch(selection){
        case 0:
            enable = false;
            break;
        case 1:
            cin.ignore(256, '\n');
            getAccount();
            break;
        case 2:
            cin.ignore(256, '\n');
            deposit();
            break;
        default:
            break;

    }
    return enable;
} 

void Bank::getAccount(){
    firstName = getString("What is your first name: ");
    lastName = getString("What is your last name: ");
    accountName = getString("What is the account name: ");
    password = getString("What is your password: ");
    initialBal = 0.0;
}

void Bank::printAccount(){
    cout << firstName << '\n' << lastName << '\n' << accountName << '\n' << password << '\n' << initialBal;
}

void Bank::deposit(){
    float depositAmt = 0.0;
    cout << "How much would you like to deposit: ";
    cin >> depositAmt;
    while(!cin || depositAmt <= 0){
        cin.clear();
        cout << "Error: Invalid Entry\nTry Again!\n";
        cout << "How much would you like to deposit: ";
        cin >> depositAmt;
    }
    initialBal += depositAmt;
}

int main(){
    Bank user;
    bool enable = true;
    do{
        enable = user.menu();
    } while(enable);
    user.printAccount();
    cout << "\nCheck\n";
    return 0;
}

string getString(string prompt){
    string input = "0";
    cout << prompt;
    getline(cin, input);
    while(!cin || (input.length() == 0 || 20 < input.length())){
        cin.clear();
        cout << "Error: Invalid Entry\nTry Again!\n";
        cout << prompt;
        getline(cin, input);
        continue;
    }
    return input;
}