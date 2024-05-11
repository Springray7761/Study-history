int main()
{
    // Allocate Heap memory
    int* array = new int[10];
     
     
    cout<<sizeof (array)<<" "<<array<<" "<<sizeof (*array)<<" " << *array<<"\n";
    cout<<sizeof (array+1)<<" "<<array+1<<" "<<sizeof (*(array+1))<<" " << *(array+1)<<"\n";
    
    // Deallocate Heap memory
    delete[] array;
        
    cout<<sizeof (array)<<" "<<array<<" "<<sizeof (*array)<<" " << *array<<"\n";
 
    array=NULL;
    cout<<"hi "<<endl<<sizeof (array)<<" "<<array<<" "<<sizeof (*array)<<" " << *array<<"\n";
    return 0;
}
