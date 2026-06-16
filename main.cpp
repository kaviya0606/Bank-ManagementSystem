#include <iostream>
#include <fstream>
using namespace std;

class Account
{
public:
    int accountNumber;
    string customerName;
    float balance;

    void createAccount()
{
    cout << "Enter Account Number: ";
    cin >> accountNumber;

    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, customerName);

    cout << "Enter Initial Balance: ";
    cin >> balance;

    if(balance < 0)
    {
        balance = 0;
        cout << "\nNegative balance not allowed!";
        cout << "\nBalance has been set to 0." << endl;
    }
}

    void displayAccount()
{
    cout << "\n----- Account Details -----";
    cout << "\nAccount Number : " << accountNumber;
    cout << "\nCustomer Name  : " << customerName;
    cout << "\nBalance        : " << balance;
    cout << endl;
}

void deposit()
{
    float amount;

    cout << "\nEnter Deposit Amount: ";
    cin >> amount;

    if(amount <= 0)
    {
        cout << "\nInvalid Amount!";
        return;
    }

    balance = balance + amount;

    cout << "\nDeposit Successful!";
    cout << "\nUpdated Balance: " << balance << endl;
}

void withdraw()
{
    float amount;

    cout << "\nEnter Withdrawal Amount: ";
    cin >> amount;

    if(amount <= 0)
    {
        cout << "\nInvalid Amount!";
        return;
    }

    if(amount > balance)
    {
        cout << "\nInsufficient Balance!";
    }
    else
    {
        balance = balance - amount;

        cout << "\nWithdrawal Successful!";
        cout << "\nUpdated Balance: " << balance << endl;
    }
}

void checkBalance()
{
    cout << "\n===== BALANCE INQUIRY =====";
    cout << "\nAccount Number : " << accountNumber;
    cout << "\nCustomer Name  : " << customerName;
    cout << "\nCurrent Balance: " << balance << endl;
}

void saveToFile()
{
    ofstream file("accounts.txt", ios::app);

    file << accountNumber << " "
         << customerName << " "
         << balance << endl;

    file.close();

    cout << "\nAccount Saved Successfully!";
}

};

int main()
{
    Account acc;
    int choice;

    do
    {
       cout << "\n\n===== BANK MANAGEMENT SYSTEM =====";
       cout << "\n1. Create Account";
       cout << "\n2. Display Account";
       cout << "\n3. Deposit Money";
       cout << "\n4. Withdraw Money";
       cout << "\n5. Balance Inquiry";
       cout << "\n6. Save Account";
       cout << "\n7. Exit";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                acc.createAccount();
                break;

            case 2:
                acc.displayAccount();
                break;

            case 3:
                acc.deposit();
                break;

            case 4:
                acc.withdraw();
                break;

            case 5:
                acc.checkBalance();
                break;
            case 6:
                 acc.saveToFile();
                 break;

            case 7:
                 cout << "\nThank You For Using Bank Management System!";
                 break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 7);

    return 0;
}
