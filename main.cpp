#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct transaction{
    int number;
    string type;
    string when;
    float Amt;
};

class Bank{
    private:
        string firstName;
        string lastName;
        string accountName;
        string password;
        double initialBal;
        bool accMade; 
        vector<transaction> transHist;
        int transNumber;
    public:
        bool menu();
        void getAccount();
        bool verifyUser(bool);
        void printAccount();
        void deposit();
        void depoToTrans(int);
        void withdraw();
        void withToTrans(int);
        void checkBalance();
        void getHistory();
};

string getString(string prompt);

bool Bank::menu(){
    bool enable = true;
    cout << "\n-------------------------------\n" 
        <<  "|     Welcome to the Bank!    |\n" 
        << "|     How May We Help You?    |\n" 
        << "-------------------------------\n"
        << "| 0) Exit Bank                |\n"
        << "| 1) Create Account           |\n"
        << "| 2) Deposit Money            |\n"
        << "| 3) Withdraw Money           |\n"
        << "| 4) Check Balance            |\n"
        << "| 5) View Account Details     |\n"
        << "| 6) See Transaction History  |\n"
        << "-------------------------------\n"
        << "|      Type in the Digit      |\n" 
        << "|  Associated With the Action |\n"
        << "-------------------------------\n";
    int selection = -1;
    cout << "Enter Digit: ";
    cin >> selection;
    while(!cin || selection < 0 || selection > 6){
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
            accMade = true;
            break;
        case 2:
            cin.ignore(256, '\n');
            if(verifyUser(accMade)){
                deposit();
            }
            break;
        case 3:
            cin.ignore(256, '\n');
            if(verifyUser(accMade)){
                withdraw();
            }
            break;
        case 4:
            cin.ignore(256, '\n');
            if(verifyUser(accMade)){
                checkBalance();
            }
            break;
        case 5:
            cin.ignore(256, '\n');
            if(verifyUser(accMade)){
                printAccount();
            }
            break;
        case 6:
            cin.ignore(256, '\n');
            if(verifyUser(accMade)){
                getHistory();
            }
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
    transNumber = 0;
    accMade = false;
}

bool Bank::verifyUser(bool acc){
    string checkUser = "0";
    string checkPass = "0";
    cout << '\n';
    if(!acc){
        cout << "Error: No account made\n";
        return false;
    }
    cout << "Enter account name: ";
    getline(cin, checkUser);
    cout << "Enter password: ";
    getline(cin, checkPass);
    if(checkUser != accountName || checkPass != password){
        cout << "Error: account name or password is incorrect\n";
        return false;
    }
    cout << '\n';
    return true;
}

void Bank::printAccount(){
    cout << "\nFirst Name: "<< firstName << '\n' << "Last Name: "<< lastName << '\n' << "Account Name: " << accountName << '\n';
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
    depoToTrans(depositAmt);
    initialBal += depositAmt;
}

void Bank::depoToTrans(int d){
    transaction depo;
    time_t now = time(0);
    string transform = ctime(&now);
    depo.number = ++transNumber;
    depo.type = "Deposit";
    depo.when = transform;
    depo.Amt = d;
    transHist.push_back(depo);
}

void Bank::withdraw(){
    float withdrawAmt = 0.0;
    cout << "Enter amount to withdraw: ";
    cin >> withdrawAmt;
    while(!cin){
        cin.clear();
        cout << "Error: Invalid Entry\nTry Again!\n";
        cout << "Enter amount to withdraw: ";
        cin >> withdrawAmt;
    }
    while(withdrawAmt > initialBal){
        cin.clear();
        cout << "Error: Withdrawal Amount Exceeds Balance\nTry Again!\n";
        cout << "Enter amount to withdraw: ";
        cin >> withdrawAmt;
    }
    withToTrans(withdrawAmt);
    initialBal -= withdrawAmt;
}

void Bank::withToTrans(int w){
    transaction with;
    time_t now = time(0);
    string transform = ctime(&now);
    with.number = ++transNumber;
    with.type = "Withdrawal";
    with.when = transform;
    with.Amt = w;
    transHist.push_back(with);
}

void Bank::checkBalance(){
    cout << "Your balance is: " << initialBal << '\n';
}

void Bank::getHistory(){
    if(transNumber == 0){
        cout << "No transactions have been made.\n";
    }
    for(int i = 0; i < transHist.size(); i++){
        cout << "Transaction Number: " << transHist[i].number << '\n' 
            << "Transaction Type: " << transHist[i].type << '\n' 
            << "Tiem of Transaction: " << transHist[i].when 
            << "Amount Deposited/Withdrawn: " << transHist[i].Amt << '\n' << '\n';
    }
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