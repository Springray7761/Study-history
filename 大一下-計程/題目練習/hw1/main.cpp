#include <iostream>
using namespace std;
void findAndInvertMinimum(int *arr,int size){/*Teacher said it's better to use ptr in fuction,so I did as he say*/
    int minimum=*arr;
    for(int i=1;i<size;i++)
        if(minimum>*(arr+i)) minimum=arr[i];
    for(int i=0;i<size;i++)
        if(*(arr+i)==minimum) *(arr+i)*=-1;/*Because the problem didn't talk about the situation when there are more than one minumum*/
}                                        /*So I take as the problem want us to change all of the signs of the minimums*/
void negateElements(int* arr, int size){
    for(int i=0;i<size;i++)
        if(*(arr+i)>0) *(arr+i)*=-1; 
}
/*int* arraysizechanger(int* array,int size,int new_size){
    int *new_array=new int[new_size];
    int counter=0;
    for(int i=0;i<size;i++){
        *(new_array+i)=*(array+i);
    }
    return new_array;
}*/
void mergeAndDoubleSecondArrayElements(int* arr1, int arr1Size, const int* arr2, int arr2Size, int combinedCapacity){
    if(combinedCapacity<arr1Size+arr2Size)
        cout<<"Array1 too small,error input try again"<<endl;
    else
        for(int i=arr1Size;i<arr1Size+arr2Size;i++) *(arr1+i)=*(arr2+i-arr1Size)*2;
}
int main(){
    int arr1[7]={1,2,3},arr2[4]={1,2,3,4};
    findAndInvertMinimum(arr1,3);
    for(int i=0;i<3;i++) cout<<arr1[i]<<' ';
    cout<<endl;
    negateElements(arr1,3);
    for(int i=0;i<3;i++) cout<<arr1[i]<<' ';
    cout<<endl;
    mergeAndDoubleSecondArrayElements(arr1,3,arr2,4,7);
    for(int i=0;i<7;i++) cout<<arr1[i]<<' ';
    cout<<endl;
    return 0;
}
