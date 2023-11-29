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

}

void Bank::getAccount(){
    firstName = getString("What is your first name: ");
    lastName = getString("What is your last name: ");
    accountName = getString("What is the account name: ");
    password = getString("What is your password: ");
    initialBal = 0.0;
}

void Bank::printAccount(){
    cout << firstName << '\n' << lastName << '\n' << lastName << '\n' << accountName << '\n' << initialBal;
}

int main(){
    Bank obj;
    obj.getAccount();
    obj.printAccount();
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