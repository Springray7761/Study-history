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
};

class Triangle: public Shape {
   public:
      int getArea() { 
         return (width * height)/2; 
      }
};
 
int main(void) {
   Rectangle Rect;
   Triangle  Tri;
 
   Rect.setWidth(5);
   Rect.setHeight(7);
   
   // Print the area of the object.
   cout << "Total Rectangle area: " << Rect.getArea() << endl;

   Tri.setWidth(5);
   Tri.setHeight(7);
   
   // Print the area of the object.
   cout << "Total Triangle area: " << Tri.getArea() << endl; 

   Shape *ShapePtr[2];
   ShapePtr [0] = &Rect;
   ShapePtr [1] = &Tri;
   
   cout<<typeid(int).name()<<endl;
   cout<<typeid(double).name()<<endl;
   cout<<typeid(char).name()<<endl;
   cout<<typeid(string).name()<<endl<<endl;
   
   cout<<typeid(Shape).name()<<endl;
   cout<<typeid(Rect).name()<<endl;
   cout<<typeid(Tri).name()<<endl<<endl;
   
   for (int i=0; i<2; i++)
     cout<<typeid(*ShapePtr[i]).name()<<" "<<ShapePtr[i]->getArea()<<endl;
   return 0;
}
