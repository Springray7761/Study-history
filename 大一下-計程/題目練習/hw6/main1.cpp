#include <iostream>
using namespace std;
class Date{
private:
    int month;
    int day;
    int year;
public:
    Date(int number1=1,int number2=1,int number3=1);
    void month_set(int);
    int month_get();
    void day_set(int);
    int day_get();
    void year_set(int);
    int year_get();
    void displayDate(string);
};
Date::Date(int number1,int number2,int number3){
    month_set(number1);
    day_set(number2);
    year_set(number3);
}
void Date::month_set(int number){
    if(number>=1&&number<=12) month=number;
    else month=1;
}
int Date::month_get(){
    return month;
}
void Date::day_set(int number){
    day=number;
}
int Date::day_get(){
    return day;
}
void Date::year_set(int number){
    year=number;
}
int Date::year_get(){
    return year;
}
void Date::displayDate(string date_number){
    for(int counter=0,j=0;counter<3;j++){
        if(date_number[j]=='/') continue;
        if(counter==0){
            if(j==0) month=date_number[j]-'0';
            else month=10*month+date_number[j]-'0';
        }
        if(counter==1){
            if(date_number[j-1]=='/') day=date_number[j]-'0';
            else day=10*day+date_number[j]-'0';
        }
        if(counter==2){
            if(date_number[j-1]=='/') year=date_number[j]-'0';
            else year=10*year+date_number[j]-'0';
        }
        if(date_number[j+1]=='\0'||date_number[j+1]=='/') counter++;
    }
    
}
int main(){
    Date today;
    today.displayDate("11/4/2024");
    cout<<"The month of today:"<<today.month_get()<<endl;
    cout<<"The day of today:"<<today.day_get()<<endl;
    cout<<"The year of today:"<<today.year_get()<<endl;
    return 0;
}

