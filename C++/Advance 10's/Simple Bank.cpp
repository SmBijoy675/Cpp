#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;
public:
    BankAccount() {
        balance = 0.0;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit of $" << amount << " successful" << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds. Cannot withdraw $" << amount << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal of $" << amount << " successful" << endl;
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account;
    char depositChoice;
    double depositAmount;
    char withdrawChoice;
    double withdrawalAmount;

    do {
        cout << "\n ";
        cout << "!!!Welcome to the Simple Bank!!!\n ";
        cout << "Do you want to deposit money? (y/n): ";
        cin >> depositChoice;

        if (depositChoice == 'y' || depositChoice == 'Y') {
            cout << "Enter the deposit amount: ";
            cin >> depositAmount;
            account.deposit(depositAmount);
            cout << "Current account balance: $" << account.getBalance() << endl;

            cout << "Do you want to withdraw money? (y/n): ";
            cin >> withdrawChoice;

            if (withdrawChoice == 'y' || withdrawChoice == 'Y') {
                cout << "Enter the withdrawal amount: ";
                cin >> withdrawalAmount;
                account.withdraw(withdrawalAmount);
                cout << "Current account balance: $" << account.getBalance() << endl;
            }
        }
    } while (depositChoice == 'y' || depositChoice == 'Y');

    return 0;
}
