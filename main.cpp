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
        void menu();
        void getAccount();
        void printAccount();
};

string getString(string prompt);

void Bank::menu(){
    cout << "-------------------------------\n" <<  "| " 
        <<  "    Welcome to the Bank!   " << " |\n" 
        << "|     How May We Help You?    |\n" 
        << "-------------------------------\n"
        << "| " << "       0) Exit Bank        " << " |\n"
        << "| " << "     1) Create Account     " << " |\n"
        << "-------------------------------\n"
        << "| " << "     Type in the Digit     " << " |\n" 
        << "| " << " Associated With the Action" << " |\n"
        << "-------------------------------\n";
    int selection = -1;
    cout << "Enter Digit: ";
    cin >> selection;
    while(!cin || selection < 0 || selection > 1){
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Error: Invalid Input\nTry Again!\n";
        cout << "Enter Digit: ";
        cin >> selection;
    }
    switch(selection){
        case 0:
            break;
        case 1:
            cin.ignore(256, '\n');
            getAccount();
        default:
            break;

    }
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

int main(){
    Bank user;
    user.menu();
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