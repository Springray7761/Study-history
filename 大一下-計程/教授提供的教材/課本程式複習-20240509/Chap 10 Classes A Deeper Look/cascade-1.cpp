#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    int speed;
    string color;

public:
    Car() : speed(0), color("Unknown") {}  // Default constructor
    
    // Function to set the color of the car
    Car& setColor(const std::string& col) {
        color = col;
        return *this;
    }

    // Function to set the speed of the car
    Car& setSpeed(int spd) {
        speed = spd;
        return *this;
    }

    // Function to display the state of the car
    void display() const {
        cout << "Car: "<<this<<endl;
        cout << "Car color: " << color << ", Car speed: " << speed << " km/h" << endl;
    }
};

int main() {
    Car myCar;
    cout << "myCar: "<< &myCar << endl;
    myCar.display();
    myCar.setColor("Red").setSpeed(100).display();  // Cascaded member function calls

    return 0;
}
