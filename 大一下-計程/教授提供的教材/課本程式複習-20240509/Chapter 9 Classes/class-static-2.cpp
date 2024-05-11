#include <iostream>
#include <iomanip>
using namespace std;

class SalesPerson
{
public:  
static const int monthsPerYear = 12; //has to be constant    
void getstatic(){
  cout<< monthsPerYear<<endl;
}
private:
};

int main(){
SalesPerson s1,s2;
cout<<sizeof(s1)<<' '<<sizeof(s1)<<endl;
s1.getstatic();
s2.getstatic();
cout << SalesPerson::monthsPerYear;
return 0;
}

/*
class SalesPerson
{
public:  
void getstatic(){
  cout<< monthsPerYear<<endl;
}
private:
static const int monthsPerYear = 12; //has to be constant    
};

int main(){
SalesPerson s1,s2;
cout<<sizeof(s1)<<' '<<sizeof(s1)<<endl;
s1.getstatic();
s2.getstatic();
//cout << SalesPerson::monthsPerYear;
//cout <<' '<<s1.monthsPerYear<<' '<<s2.monthsPerYear; 

return 0;
}
*/