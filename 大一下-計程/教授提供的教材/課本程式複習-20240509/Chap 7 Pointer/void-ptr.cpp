int main()
{
int b = 3;
int *bPtr = &b;

void *cPtr;

cout << cPtr << ' '<< &cPtr << ' ' << sizeof (cPtr)<<endl;
//cout << sizeof (*cPtr)<<endl;

cPtr = bPtr;

cout << cPtr << ' '<< &cPtr << ' ' << sizeof (cPtr)<<endl;
}