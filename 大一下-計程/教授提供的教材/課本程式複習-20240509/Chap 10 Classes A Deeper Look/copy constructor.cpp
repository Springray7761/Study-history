/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class People{
private:
    int m_age;
public:
    People(int age):m_age(age){
        cout << "constructor" << endl;
    }
    People(){
        m_age = 0;
        cout << "default constructor" << endl;
    }

    //copy constructor
    People(const People& p){
        cout << "copy constructor" << endl;
    
        m_age = p.m_age;
    }

    ~People(){
        cout << "destructor" << endl;
    }
    int getAge() const{
        return m_age;
    }
};

int main(){
People p1(18), p2;
cout << "p1's age " << p1.getAge() << endl;
p2 = p1;
cout << "p2's age " << p2.getAge() << endl;
People p3 = p1;
cout << "p3's age " << p3.getAge() << endl;
People p4(p1);
cout << "p4's age " << p3.getAge() << endl;
}