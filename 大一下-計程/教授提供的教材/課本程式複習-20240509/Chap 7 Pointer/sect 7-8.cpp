int main(){
int b[] = {10, 20, 30, 40};
int *bPtr = b;
int *cPtr = &b[3];
cout << cPtr - bPtr<< endl;
cout << bPtr - cPtr<< endl;
//cout << bPtr / cPtr<< endl;
}