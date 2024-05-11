void f1(int *xPtr) {
  *xPtr = 100;
}

void f2(const int *xPtr) {
  //*xPtr = 200;
}

void f3(int const *xPtr) {
  //*xPtr = 300;
}

void f4(int * const xPtr) {
  int k = 10;
  xPtr = &k;
  *xPtr = 400;
}

void f5(const int * const xPtr) {
  //*xPtr = 500;
  cout<< xPtr<<' '<<xPtr + 2<<" ok but dangerous"<<endl;
}

int main() {
  int y;
  f1(&y);   cout<<y<<endl;
  f2(&y);   cout<<y<<endl;
  f3(&y);   cout<<y<<endl;
  f4(&y);   cout<<y<<endl;
  f5(&y);   cout<<y<<endl;
}