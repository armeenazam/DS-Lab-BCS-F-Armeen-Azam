#include<iostream>
#include<string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    string accountNumber;
    double balance;
public:
    BankAccount(){
        accountHolderName = "abc";
        accountNumber = "689768098546";
        balance = 10000;
    } 

    BankAccount(string name, string num, double bal) : 
        accountHolderName(name), accountNumber(num), balance(bal) {}

    BankAccount(const BankAccount &other) : 
        accountHolderName(other.accountHolderName), 
        accountNumber(other.accountNumber), 
        balance(other.balance) {}

    void showBalance(){
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $ " << balance << endl;
    }    
    
    void deduct(double amount){
        if(amount <= balance){
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }
};

int main(){
    BankAccount account1; 
    cout << "Account 1 details:" << endl;
    account1.showBalance();
    cout << endl;
    
    BankAccount account2 ("Armeen Azam", "1234567890", 1000);
    cout << "Account 2 details:" << endl;
    account2.showBalance();
    cout << endl;

    BankAccount account3 (account2);
    account3.deduct(200);
    cout << "Account 3 details after deducting $200:" << endl;
    account3.showBalance();
    cout << endl;
    cout << "Account 2 details (unchanged):" << endl;
    account2.showBalance();

}