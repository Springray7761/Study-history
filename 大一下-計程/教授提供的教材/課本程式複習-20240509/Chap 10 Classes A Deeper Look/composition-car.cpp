#include <iostream> 
using namespace std; 


// Define a simple 'Engine' class with a constructor and destructor.
class Engine {
public:
    Engine() {
        std::cout << "Engine is constructed." << std::endl;
    }

    ~Engine() {
        std::cout << "Engine is destructed." << std::endl;
    }

    void start() {
        std::cout << "Engine starts!" << std::endl;
    }
};

// Define a 'Car' class that contains an 'Engine' with a constructor and destructor.
class Car {
private:
    Engine engine; // Car has an Engine.

public:
    Car() {
        std::cout << "Car is constructed." << std::endl;
    }

    ~Car() {
        std::cout << "Car is destructed." << std::endl;
    }

    void startCar() {
        engine.start(); // Starting the car means starting its engine.
        std::cout << "Car starts!" << std::endl;
    }
};

int main() {
    Car myCar;
    myCar.startCar(); // This will start the engine, then the car.
    return 0;
}