size_t getSize(float *ptr) {

cout<<ptr<<' '<<*ptr<<endl;
cout<<sizeof(ptr)<<endl;
cout<<sizeof(*ptr)<<endl;
return sizeof (ptr);
}

int main() {
float array [20]={0};

cout<<sizeof(array)<<' '<<array<<endl;
cout<<getSize(array)<<endl;
cout<<sizeof(array[0]);
}
