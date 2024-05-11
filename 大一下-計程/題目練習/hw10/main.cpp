#include<iostream>
using namespace std;
class Package{
    private:
        string Sname,Saddress,Scity,Sstate,SZIP,Rname,Raddress,Rcity,Rstate,RZIP;
        double weight,cost_per_ounce;
    public:
        Package(const string &a,const string &b,const string &c,const string &d,const string &e,const string &f,const string &g,const string &h,const string &i,const string &j,const double &k,const double &l){
            Sname = a;
            Saddress = b;
            Scity = c;
            Sstate = d;
            SZIP = e;
            Rname = f;
            Raddress = g;
            Rcity = h;
            Rstate = i;
            RZIP = j;
            weight = k>=0?k:0;/*只有說 要注意 沒說她真的輸入負值要幹啥呀;w;*/
            cost_per_ounce = l>=0?l:0;
        }
        double calculateCost()const{
            return weight*cost_per_ounce;
        }
};
class TwoDayPackage:public Package{
    private:
        double flat_fee;
    public:
        TwoDayPackage(const string &a,const string &b,const string &c,const string &d,const string &e,const string &f,const string &g,const string &h,const string &i,const string &j,const double &k,const double &l,const double &m):Package(a,b,c,d,e,f,g,h,i,j,k,l){
            flat_fee=m;             
        }
        double calculateCost()const{
            return Package::calculateCost()+flat_fee;
        }
};
class OvernightPackage:public Package{
    private:
        double additional_fee_per_ounce;
    public:
        OvernightPackage(const string &a,const string &b,const string &c,const string &d,const string &e,const string &f,const string &g,const string &h,const string &i,const string &j,const double &k,const double &l,const double &m):Package(a,b,c,d,e,f,g,h,i,j,k,l+m){
        };
        double calculateCost()const{
            return Package::calculateCost();
        }
};
int main() {
    // Test program
    // Create a Package object
    Package package("John Doe", "123 Main St", "Anytown", "CA", "12345","Jane Smith", "456 Elm St", "Othertown", "NY", "54321", 10, 0.5);
    cout << "Package shipping cost: $" << package.calculateCost() << endl;
    // Create a TwoDayPackage object
    TwoDayPackage twoDayPackage("John Doe", "123 Main St", "Anytown", "CA", "12345", "Jane Smith", "456 Elm St", "Othertown", "NY", "54321", 10, 0.5, 5);
    cout << "Two-day package shipping cost: $" << twoDayPackage.calculateCost() << endl;
    // Create an OvernightPackage object
    OvernightPackage overnightPackage("John Doe", "123 Main St", "Anytown", "CA", "12345", "Jane Smith", "456 Elm St", "Othertown", "NY", "54321", 10, 0.5, 2);
    cout << "Overnight package shipping cost: $" << overnightPackage.calculateCost() << endl;
    return 0;
}
