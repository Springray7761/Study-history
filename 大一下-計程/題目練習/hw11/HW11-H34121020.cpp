#include <stdio.h>
#include<iostream>
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
    // Testing Account class
    Account acc(100.0);
    std::cout << "Account balance: " << acc.getBalance() << std::endl;
    acc.credit(50.0);
    std::cout << "Account balance after credit: " << acc.getBalance() << std::endl;
    acc.debit(30.0);
    std::cout << "Account balance after debit: " << acc.getBalance() << std::endl;

    // Testing SavingsAccount class
    SavingsAccount savings(500.0, 0.05); // Initial balance $500, interest rate 5%
    std::cout << "Savings account balance: " << savings.getBalance() << std::endl;
    double interest = savings.calculateInterest();
    savings.credit(interest);
    std::cout << "Savings account balance after interest: " << savings.getBalance() << std::endl;

    // Testing CheckingAccount class
    CheckingAccount checking(200.0, 1.0); // Initial balance $200, transaction fee $1
    std::cout << "Checking account balance: " << checking.getBalance() << std::endl;
    checking.credit(100.0);
    std::cout << "Checking account balance after credit: " << checking.getBalance() << std::endl;
    checking.debit(50.0);
    std::cout << "Checking account balance after debit: " << checking.getBalance() << std::endl;

    return 0;
}
