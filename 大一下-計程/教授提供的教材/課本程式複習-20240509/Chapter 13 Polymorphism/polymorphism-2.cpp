// base class declaration.
class Animal {
public:
	string color = "Black";
};

// inheriting Animal class.
class Dog : public Animal {
public:
	string color = "Grey";
};

// Driver code
int main(void)
{
	Animal d = Dog(); // accessing the field by reference
					// variable which refers to derived
	cout << d.color<<endl;
	
	Dog dog = Dog(); // accessing the field by reference
					// variable which refers to derived
	cout << dog.color;

    
    
}