#include <iostream>
using namespace std;
class Invoice{
private:
    string part_number;
    string part_description;
    int item_sold;
    int price;
public:
    Invoice(string,string,int,int);
    void part_num_set(string);
    string part_num_get();
    void part_des_set(string);
    string part_des_get();
    void sold_set(int);
    int sold_get();
    void price_set(int);
    int price_get();
    int getInvoiceAmount();
};
Invoice::Invoice(string part_num,string part_des,int sold_num,int price_num){
    part_number=part_num,part_description=part_des,item_sold=sold_num,price=price_num;
}
void Invoice::part_num_set(string part_num){
    part_number=part_num;
}
string Invoice::part_num_get(){
    return part_number;
}
void Invoice::part_des_set(string part_des){
    part_description=part_des;
}
string Invoice::part_des_get(){
   return part_description;
}
void Invoice::sold_set(int sold_num){
    if(sold_num<0) item_sold=0;
    else item_sold=sold_num;
}
int Invoice::sold_get(){
    return item_sold;
}
void Invoice::price_set(int price_num){
    if(price_num<0) price=0;
    else price=price_num;
}
int Invoice::price_get(){
    return price;
}
int Invoice::getInvoiceAmount(){
    return item_sold*price;
}
int main(){
    Invoice thing("001","owo",0,20);
    thing.part_num_set("002");
    cout<<thing.part_num_get()<<endl;
    thing.part_des_set(".w.");
    cout<<thing.part_des_get()<<endl;
    thing.sold_set(10);
    cout<<thing.sold_get()<<endl;
    thing.price_set(100);
    cout<<thing.price_get()<<endl;
    cout<<thing.getInvoiceAmount()<<endl;
    return 0;
}
