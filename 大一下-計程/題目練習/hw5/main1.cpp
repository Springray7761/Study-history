#include <iostream>
using namespace std;
class Account{
private:
    int account_balance;
public:
    Account(int balance);
    void credit(int credit_ammount);
    void debit(int debit_ammount);
    void getbalance();
};
Account::Account(int balance){
    account_balance=(balance>=0)?(balance):0;
    if(balance<0) cout<<"The initial balance was valid"<<endl;
}
void Account::credit(int credit_amount){
    account_balance+=credit_amount;
}
void Account::debit(int debit_amount){
    if(debit_amount>account_balance) cout<<"Debit ammount exceeded account balance"<<endl;
    else account_balance-=debit_amount;
}
void Account::getbalance(){
    cout<<"The current balance is:"<<account_balance<<endl;
}
int main(){
    Account guest1(-10);
    guest1.getbalance();
    Account guest2(100);
    guest2.getbalance();
    guest1.credit(200);
    guest1.getbalance();
    guest2.credit(300);
    guest2.getbalance();
    guest1.debit(300);
    guest1.getbalance();
    guest2.debit(200);
    guest2.getbalance();
    return 0;
}
