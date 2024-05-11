int main()
{
int a;
int *aPtr;
double b;
double *bPtr;

a = 7;
aPtr = &a;

cout << &a << ' '<< aPtr<<'\n';
cout << a <<' '<< *aPtr<<'\n';
cout << &*aPtr <<' ' << *&aPtr<<'\n'<<endl;

cout << &a << ' '<< &aPtr<<'\n';
cout << &b << ' '<< &bPtr<<'\n';

cout << sizeof (a) <<' ' << sizeof (aPtr) << ' '<< sizeof (*aPtr) <<' '<< sizeof (&a) <<' '<< sizeof (&aPtr)<<endl;
cout << sizeof (b) <<' ' << sizeof (bPtr) << ' '<< sizeof (*bPtr) <<' '<< sizeof (&b) <<' '<< sizeof (&bPtr);
}
