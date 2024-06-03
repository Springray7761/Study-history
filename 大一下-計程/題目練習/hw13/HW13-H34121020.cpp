#include <iostream>
#include <vector>
#include<typeinfo>
using namespace std;
class Account{
    private:
        double balance;
    public:
        Account(const double &a){
            if(a<0){
                cout<<"Error:invalid input."<<endl;
                balance=0;
            }
            else
                balance=a;
        }
        virtual void credit(const double &a){
            balance+=a;
        }
        virtual void debit(const double &a){
            if(balance<a)
                cout<<"Debit amount exceeded account balance."<<endl;
            else
                balance-=a;
        }
        double getBalance ()const{
            return balance;
        }
};
class SavingsAccount:public Account{
    private:
        double interest_rate;
    public:
        SavingsAccount(const double &a,const double &b):Account(a){
            interest_rate=b;
        }
        double calculateInterest() const{
            return getBalance()*interest_rate;
        }
};
class CheckingAccount:public Account{
    private:
        double fee;
    public:
        CheckingAccount(const double &a,const double &b):Account(a){
            fee=b;
        }
        virtual void credit(const double &a){
            Account::credit(a - fee);
        }
        virtual void debit(const double &a){
            if(getBalance()<a+fee)
                cout<<"Debit amount exceeded account balance."<<endl;
            else
                Account::debit(a + fee);
        }
        
};
int main() {
    std::vector<Account*> accounts;
    int number;
    // Create SavingsAccount and CheckingAccount objects
    accounts.push_back(new SavingsAccount(500.0, 0.05)); // Savings account with $500 initial balance and 5% interest rate
    accounts.push_back(new CheckingAccount(200.0, 1.0)); // Checking account with $200 initial balance and $1 fee per transaction

    // Process each account
    for(auto a:accounts){
        cout<<"Processing "<<typeid(*a).name()<<" account."<<endl;
        cout<<"Enter amount to deposit: ";
        cin>>number;
        a->credit(number);
        cout<<"Enter amount to withdraw: ";
        cin>>number;
        a->debit(number);
        if(SavingsAccount *b = dynamic_cast<SavingsAccount *>(a)){
            cout<<"Interest added: "<<b->calculateInterest()<<endl;
            b->credit(b->calculateInterest());
        } 
        cout<<"Updated balance: "<<a->getBalance()<<endl;;
    }
    // Clean up dynamically allocated memory
    for(auto a:accounts) delete(a);
    return 0;
}

