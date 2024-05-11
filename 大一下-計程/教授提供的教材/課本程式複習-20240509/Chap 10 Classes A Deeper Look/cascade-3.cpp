class Car {
public:
    std::string color;
    int speed;

    // Default constructor
    Car() : color("Unknown"), speed(0) {
        cout << "Default constructor called. Address: " << this << endl;
    }

    // Copy constructor with address output
    Car(const Car& other) : color(other.color), speed(other.speed) {
        cout << "Copy constructor called. Original object address: " << &other << ", New object address: " << this << endl;
    }

    // Set color function returns by value for demonstration
    Car setColor(const std::string& col) {
        color = col;
        return *this;
    }

    // Set speed function returns by value for demonstration
    Car setSpeed(int spd) {
        speed = spd;
        return *this;
    }

    // Display function to output the state of the car
    void display() const {
        cout << "Car: " << this << " Color: " << color << ", Speed: " << speed << " km/h" << endl;
    }
};

int main() {
    Car myCar;
    myCar.display();  // Display the address of the original car

    // Note: These calls will make copies and display memory addresses due to return-by-value
    Car newCar = myCar.setColor("Red").setSpeed(100);
       // Return Value Optimization (RVO) and Named Return Value Optimization (NRVO):
       // Modern C++ compilers are quite intelligent in optimizing out unnecessary copies, 
       // especially in scenarios like return-by-value in functions. 
    newCar.display();  // Display the address of the new car after cascaded calls

    return 0;
}
