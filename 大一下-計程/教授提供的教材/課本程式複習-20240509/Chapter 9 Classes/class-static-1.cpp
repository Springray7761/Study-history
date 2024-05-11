#include <iostream>
#include <iomanip>
using namespace std;  /* Why is a static data member needed? */

class SalesPerson
{
public:  
static const int monthsPerYear = 12; //has to be constant    
void getstatic(){
  cout<< monthsPerYear;
}
private:
};

Int main(){
SalesPerson s1,s2;
s1.getstatic();s2.getstatic();
cout << SalesPerson::monthsPerYear<<endl;
cout <<' '<<s1.monthsPerYear<<' '<<s2.monthsPerYear; 
return 0;
}
