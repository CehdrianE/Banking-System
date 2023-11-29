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
        string password;
        double initialBal;
    public:
        void getAccount();
};

string getString(string prompt);

void Bank::getAccount(){
    string firstName = getString("What is your first name: ");
    string lastName = getString("What is your last name: ");
    string accountName = getString("What is the account name: ");
    string password = getString("What is your password: ");
    double initialBal = 0.0;
}

int main(){
    Bank obj;
    obj.getAccount();
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
        cout << "What is the account name: ";
        getline(cin, input);
        continue;
    }
    return input;
}