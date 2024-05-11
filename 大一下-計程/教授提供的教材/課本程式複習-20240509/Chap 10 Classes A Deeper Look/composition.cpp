#include <iostream>
using namespace std;
//https://www.geeksforgeeks.org/object-composition-delegation-in-c-with-examples/
  
// Simple class 
class A { 
    int x; 

public:
    // COnstructor initializing 
    // the data members 
    A() { x = 0; } 
  
    A(int a) 
    { 
        cout << "Constructor A(int a) is invoked" << endl; 
        x = a; 
    } 
    ~A()
    {   cout << "destructor A is invoked" << endl;}
    int getx() {return x;}
}; 
  
// Complex class 
class B { 
    int y; 
    A objA; 
  
public: 
    // COnstructor initializing the 
    // data members 
    B(int a) : objA(a) 
    { 
        cout << "Constructor B(int a) is invoked" << endl;
        y = a; 
    } 
  
    ~B()
    {   cout << "destructor B is invoked" << endl;}
    
    // Function to print values 
    // of data members in class 
    // A and B 
    void display() 
    { 
        cout << "Data in object of class B = " << y 
             << endl; 
        cout << "Data in member object of "
             << "class A in class B = " << objA.getx() <<endl; 
    } 
}; 
  
// Driver code 
int main() 
{ 
    // Creating object of class B 
    B objB(25); 
  
    // Invoking display function 
    objB.display(); 
    return 0; 
}