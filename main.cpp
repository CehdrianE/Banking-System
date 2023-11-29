#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Bank{
    private:
        string firstName;
        string LastName;
        string accountName;
        double initialBal;
    public:
        void getAccount();
};

void Bank::getAccount(){
    string firstName = "0";
    string lastName = "0";
    string accountName = "0";
    double initialBal = 0.0;
    cout << "What is your first name: ";
    getline(cin, firstName);
    while(!cin || (firstName.length() == 0 || 20 < firstName.length())){
        cin.clear();
        cout << "Error: Invalid Entry\nTry Again!\n";
        cout << "What is your first name: ";
        getline(cin, firstName);
        continue;
    }
    cout << "What is your last name: ";
    getline(cin, lastName);
    while(!cin || (lastName.length() == 0 || 20 < lastName.length())){
        cin.clear();
        cout << "Error: Invalid Entry\nTry Again!\n";
        cout << "What is your last name: ";
        getline(cin, lastName);
        continue;
    }
    cout << "What is the account name: ";
    getline(cin, accountName);
    while(!cin || (accountName.length() == 0 || 20 < accountName.length())){
        cin.clear();
        cout << "Error: Invalid Entry\nTry Again!\n";
        cout << "What is the account name: ";
        getline(cin, accountName);
        continue;
    }

}

int main(){
    Bank obj;
    obj.getAccount();
    cout << "\nCheck\n";
    return 0;
}