#include <iostream>

using namespace std;

int main()
{
int b[] = {10, 20, 30, 40};
int *bPtr = b;

cout<< b << ' '<< &b << ' ' << sizeof (b) << ' ' << sizeof (&b) << endl;
cout<< bPtr << ' '<< &bPtr << ' ' << sizeof (bPtr) << ' ' << sizeof (&bPtr) << endl;

//cout<< ++b << endl;
//cout<< ++bPtr << endl;

for (int i = 0; i < 4; i++)
  cout << b[i] << ' ';
cout << endl;

for (int i = 0; i < 4; i++)
  cout << *(b + i) << ' ';
cout << endl;

for (int i = 0; i < 4; i++)
  cout << (b + i) << ' ';
cout << endl;

for (int i = 0; i < 4; i++)
  cout << bPtr[i] << ' ';
cout << endl;

for (int i = 0; i < 4; i++)
  cout << *(bPtr + i) << ' ';
cout << endl;

for (int i = 0; i < 4; i++)
  cout << (bPtr + i) << ' ';
cout << endl;
}