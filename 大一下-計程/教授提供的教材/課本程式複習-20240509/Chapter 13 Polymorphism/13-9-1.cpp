class Shape {
   public:
      // pure virtual function providing interface framework.
      virtual int getArea() = 0;
      
      void setWidth(int w) {
         width = w;
      }
   
      void setHeight(int h) {
         height = h;
      }
      
     virtual ~Shape(){
         cout<<"destructing shape"<<endl;
     }
   
   protected:
      int width;
      int height;
};
 
// Derived classes
class Rectangle: public Shape {
   public:
      int getArea() { 
         return (width * height); 
      }
      
     virtual ~Rectangle(){
         cout<<"destructing Rectangle"<<endl;
     }
};

class Triangle: public Shape {
   public:
      int getArea() { 
         return (width * height)/2; 
      }
      
      virtual ~Triangle(){
         cout<<"destructing Triangle"<<endl;
      }
};
 
int main(void) {
/*
   Rectangle Rect;
   Triangle  Tri;
*/
   Shape *ShapePtr[2];
   ShapePtr [0] = new Rectangle();
   ShapePtr [1] = new Triangle();
   
   ShapePtr[0]->setWidth(5);
   ShapePtr[0]->setHeight(7);
   
   ShapePtr[1]->setWidth(5);
   ShapePtr[1]->setHeight(7);
   
   for (int i=0; i<2; i++) {
     cout<<ShapePtr[i]->getArea()<<endl;
     delete ShapePtr[i];
   }
   
   return 0;
}