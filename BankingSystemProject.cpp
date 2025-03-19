#include <iostream>
using namespace std;

class Bankaccount
{
protected:
    string name;
    int AccountNum;
    double balance;
    bool isSaving;
    double interestRate;

public:

    // Setter methods
    void setName(string n) { name = n; }
    void setAccountNumber(int accountNum) { AccountNum = accountNum; }
    void setBalance(double balance) { this->balance = balance; }

    // Getter methods
    string getName() { return name; }
    int getAccountNumber() { return AccountNum; }
    double getBalance() { return balance; }

    void createAccount()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter 12-digit Account Number: "<< endl;
        cin >> AccountNum;
        cout << "Enter Initial deposit: ";
        cin >> balance;
        
        
        int choice;
        cout << "Select Account Type (1. Normal  2. Savings): ";
        cin >> choice;
        if (choice == 2)
        {
            isSaving = true;
            cout << "Enter Interest Rate (%): ";
            cin >> interestRate;
        }
        
        cout << "Account Created Successfully!\n";
    }

    void deposit()
    {
        double amount;
        cout << "Enter amount you want to deposit: ";
        cin >> amount;
        if (amount > 0)
        {
            balance += amount;
            cout << amount << " amount deposited\n";
        }
        else
        {
            cout << "Invalid amount!\n";
        }
    }

    void withdraw()
    {
        double amount;
        cout << "Enter amount you want to withdraw: ";
        cin >> amount;
        if (balance >= amount)
        {
            balance -= amount;
            cout << amount << " amount withdrawn\n";
        }
        else
        {
            cout << "Insufficient funds or Invalid amount!\n";
        }
    }

    virtual void checkbalance()
    {
        cout << "Account Holder's name: " << name << "\n";
        
        cout << "Account number: " << AccountNum << "\n";

        cout << "Balance: " << balance << "\n";

        if (isSaving)
        {
            cout << "Interest Rate: " << interestRate << "%\n";
        }
    }

    void addInterest()
    {
        if (isSaving)
        {
            double interest = (balance * interestRate) / 100;
            balance += interest;
            cout << "Interest of " << interest << " Rs. is Added!\n";
        }
        else
        {
            cout << "This is not a Savings Account!\n";
        }
    }

    
};

class SavingAccount : public Bankaccount
{
private:
    double interestRate;

public:
    SavingAccount(string name, int AccountNum, double balance, double interestRate)
    {
        this->name = name;
        this->AccountNum = AccountNum;
        this->balance = balance;
        this->interestRate = interestRate;
    }

    void addinterest()
    {
        double interest = (balance * interestRate) / 100;
        balance = balance + interest;
        cout << interest << " is added";
    }

    void checkbalance()
    {
        cout << "Account Holder's name : " << name;
        cout << "Account number : " << AccountNum;
        cout << "Balance :" << balance;
    }

   
};

class Bank
{
private:
Bankaccount account;



public:
   
    void addInterest(){
        account.addInterest();
    }

    void createAccount()
    {
        account.createAccount();
    }

    void deposit(int AccNum)
    {
        if (account.getAccountNumber() == AccNum)
        {
            account.deposit();
        }
        else
        {
            cout << "Account not found!\n";
        }
    }

    void withdraw(int accNum)
    {
        if (account.getAccountNumber() == accNum)
        {
            account.withdraw();
        }
        else
        {
            cout << "Account not found!\n";
        }
    }

    void checkBalance(int accNum)
    {
        if (account.getAccountNumber() == accNum)
        {
            account.checkbalance();
            
        }
        else
        {
            cout << "Account not found!\n";
        }
    }
};

int main()
{
    Bank bank;
    int choice, accNum;

    while (true)
    {
        cout << "\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. add interest\n6. exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bank.createAccount();
            break;
        case 2:
            cout << "Enter Account Number: ";
            cin >> accNum;
            bank.deposit(accNum);
            break;
        case 3:
            cout << "Enter Account Number: ";
            cin >> accNum;
            bank.withdraw(accNum);
            break;
        case 4:
            cout << "Enter Account Number: ";
            cin >> accNum;
            bank.checkBalance(accNum);
            break;
         case 5:
            bank.addInterest();
            break;
        case 6:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid Choice! Please try again.\n";
        }
    }

    return 0;
}
