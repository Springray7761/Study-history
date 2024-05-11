// Fig. 9.2: fig09_02.cpp
// Demonstrating the class member access operators . and ->
class Count {
public: // public data is dangerous
  void setX( int value ){
    x = value;
  }
  void print(){
    cout << x << endl;
  }

private:
  int x;
};

int main(){
   Count counter; // create counter object
   Count *counterPtr = &counter; // create pointer to counter
   Count &counterRef = counter;
   cout << "Set x to 1 and print using the object's name: ";
   counter.setX( 1 ); // set data member x to 1
   counter.print(); // ca1l member function print
   cout << "Set x to 2 and print using a reference to an object: ";
   counterRef.setX( 2 ); // set data member x to 2
   counterRef.print(); // ca11 member function print
   cout << "Set x to 3 and print using a pointer to an object: ";
   counterPtr->setX( 3 ); // set data member x to 3
   counterPtr->print(); // ca11 member function print
   cout<<sizeof (counter)<<' '<<sizeof(counterRef)<<' '<<sizeof(*counterPtr)<<endl;
}