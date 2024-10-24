#include <iostream>
using namespace std;

class Customers
{
private:
    int customerNIC;
    string customerName;
    string customerAddress;
    int customerPhone;

public:
    Customers(int ID, string name, string address, int phone)
    {
        customerNIC = ID;
        customerName = name;
        customerAddress = address;
        customerPhone = phone;
    }
    void displayCustomerInfo()
    {
        cout << "Customer ID: " << customerNIC << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Customer Address: " << customerAddress << endl;
        cout << "Customer Phone Number: " << customerPhone << endl;
    }
    int getCustomerID()
    {
        return customerNIC;
    }
};

class Accounts : public Customers
{
private:
    int accountNumber;
    string accountType;
    double balance;

public:
    Accounts(int ID, string name, string address, int phone, int accNum, string accType, double bal)
        : Customers(ID, name, address, phone), accountNumber(accNum), accountType(accType), balance(bal) {}

    void getAccount()
    {
        cout << "Account number: " << accountNumber << endl;
        cout << "Account type: " << accountType << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    void getBalance()
    {
        if (balance > 0)
        {
            cout << "Account is active. Balance: Rs. " << balance << endl;
        }
        else
        {
            cout << "Account is inactive. Balance: Rs. " << balance << endl;
        }
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Amount Deposited: Rs. " << amount << endl;
        cout << "Your new balance is: Rs. " << balance << endl;
    }

    bool withdrawal(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance" << endl;
            return false;
        }
        balance -= amount;
        cout << "Withdrew: Rs. " << amount << endl;
        cout << "Your new balance is: Rs. " << balance << endl;
        return true;
    }

    bool transfer(Accounts &toAccount, double amount)
    {
        if (withdrawal(amount))
        {
            toAccount.deposit(amount);
            return true;
        }
        return false;
    }
};

class Transactions
{
private:
    int transactionID;
    string transactionType;
    double transactionAmount;

public:
    void setTransaction(int id, string type, double amount)
    {
        transactionID = id;
        transactionType = type;
        transactionAmount = amount;
    }

    void displayTransaction()
    {
        cout << "Transaction ID: " << transactionID << endl;
        cout << "Transaction Type: " << transactionType << endl;
        cout << "Transaction Amount: Rs. " << transactionAmount << endl;
    }
};

class BankingServices : public Accounts
{
public:
    BankingServices(int ID, string name, string address, int phone, int accNum, string accType, double bal)
        : Accounts(ID, name, address, phone, accNum, accType, bal) {}

    void performTransaction(Transactions &transaction)
    {
        transaction.displayTransaction();
    }
};

int main()
{
    BankingServices Customers1(3320354371089, "Muddasir", "Nishat", 3124511373, 101, "Savings", 5000.0);
    Transactions trans;

    int choice;
    double amount;

    cout << "\t\t\tWelcome to Banking System" << endl;
    cout << "Press 1 to view account details" << endl;
    cout << "Press 2 to withdraw money" << endl;
    cout << "Press 3 to deposit money" << endl;
    cout << "Press 4 to transfer money" << endl;
    cout << "Press 5 to check balance" << endl;
    cout << "Press 6 to check recent transactions" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        Customers1.displayCustomerInfo();
        Customers1.getAccount();
        break;
    case 2:
        cout << "Enter the amount you want to withdraw: ";
        cin >> amount;
        Customers1.withdrawal(amount);
        break;
    case 3:
        cout << "Enter the amount you want to deposit: ";
        cin >> amount;
        Customers1.deposit(amount);
        break;
    case 4:
    {
        BankingServices customer2(3320354371089, "Ali", "Main Street", 3124500000, 102, "Current", 3000.0);
        cout << "Enter the amount you want to transfer: ";
        cin >> amount;
        Customers1.transfer(customer2, amount);
        break;
    }
    case 5:
        Customers1.getBalance();
        break;
    case 6:
        trans.setTransaction(1, "Deposit", 1000);
        trans.displayTransaction();
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }

    return 0;
}
