#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string name;
    double balance;

public:
    // Constructor
    BankAccount(string accountName, double initialBalance) : name(accountName), balance(initialBalance) {}

    // Deposit function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Withdrawal successful! New balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount." << endl;
        }
    }

    // Display account information
    void display() {
        cout << "Account: " << name << "\nBalance: $" << balance << endl;
    }
};

int main() {
    string name;
    double initialDeposit;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter initial deposit: ";
    cin >> initialDeposit;

    // Creating account object
    BankAccount account(name, initialDeposit);

    int choice;
    double amount;

    do {
        // Displaying menu
        cout << "\n1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Display Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 3:
                account.display();
                break;

            case 4:
                cout << "Thank you for using our bank system!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
