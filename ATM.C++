#include <iostream>
#include <string>
using namespace std;

class ATM {
private:
    int pin;
    double balance;

public:
    ATM(int p, double b) {
        pin = p;
        balance = b;
    }

    bool checkPIN(int enteredPin) {
        return enteredPin == pin;
    }

    void deposit(double amount) {
        if(amount > 0){
            balance += amount;
            cout << "Amount deposited: $" << amount << endl;
        } else {
            cout << "Invalid amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if(amount > 0 && amount <= balance){
            balance -= amount;
            cout << "Amount withdrawn: $" << amount << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    void checkBalance() {
        cout << "Current balance: $" << balance << endl;
    }
};

int main() {
    ATM myATM(1234, 1000.0); // Default PIN: 1234, balance: $1000
    int enteredPin;
    int choice;
    double amount;

    cout << "Welcome to the ATM Simulator!" << endl;

    cout << "Enter your PIN: ";
    cin >> enteredPin;

    if(!myATM.checkPIN(enteredPin)) {
        cout << "Incorrect PIN! Exiting..." << endl;
        return 0;
    }

    do {
        cout << "\nATM Menu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                myATM.checkBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                myATM.deposit(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                myATM.withdraw(amount);
                break;
            case 4:
                cout << "Thank you for using ATM Simulator!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 4);

    return 0;
}
