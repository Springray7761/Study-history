#include<iostream>
using namespace std;
class Vehicle{
    protected:
       int speed,fuel; 
    public:
        Vehicle(const int &a,const int &b){
            speed=a;
            fuel=b;
        }
        virtual void displayInfo() = 0;
        void speed_setter(const int &a){
            speed = a;
        }
        int speed_getter()const {
            return speed;
        }
        void fuel_setter(const int &a){
            fuel = a;
        }
        int fuel_getter()const {
            return fuel;
        }
};
class LandVehicle:public Vehicle{
    protected:
        int numWheels;
    public:
        virtual void displayInfo() {
            cout<<"Land Vehicle - Speed: "<<speed_getter()<<", Fuel: "<<fuel_getter()<<", Wheels: "<<numWheels<<endl;
        }
        LandVehicle(const int &a,const int &b,const int &c):Vehicle(a,b){
            numWheels=c;
        }
};
class WaterVehicle:public Vehicle{
    protected:
        int numEngines;
    public:
        virtual void displayInfo(){
            cout<<"Water Vehicle - Speed: "<<speed_getter()<<", Fuel: "<<fuel_getter()<<", Engines: "<<numEngines<<endl;
        }
        WaterVehicle(const int &a,const int &b,const int &c):Vehicle(a,b){
            numEngines=c;
        }
};
class AirVehicle:public Vehicle{
    protected:
        int numWings;
    public:
        virtual void displayInfo(){
            cout<<"Air Vehicle - Speed: "<<speed_getter()<<", Fuel: "<<fuel_getter()<<", Wings: "<<numWings<<endl;
        }
        AirVehicle(const int &a,const int &b,const int &c):Vehicle(a,b){
            numWings=c;
        }
};
class Car:public LandVehicle{
    private:
        int numDoors;
    public:
        virtual void displayInfo(){
            cout<<"Car - Speed: "<<speed_getter()<<", Fuel: "<<fuel_getter()<<", Wheels: "<<numWheels<<", Doors: "<<numDoors<<endl;
        }
        Car(const int &a,const int &b,const int &c,const int &d):LandVehicle(a,b,c),numDoors(d){}
};
class Boat:public WaterVehicle{
    private:
        int numSails;
    public:
        virtual void displayInfo(){
            cout<<"Boat  - Speed: "<<speed_getter()<<", Fuel: "<<fuel_getter()<<", Engines: "<<numEngines<<", Sails: "<<numSails<<endl;
        }
        Boat(const int &a,const int &b,const int &c,const int &d):WaterVehicle(a,b,c),numSails(d){}
};
class Plane :public AirVehicle{
    private:
        int numEngines;
    public:
        virtual void displayInfo(){
            cout<<"Plane  - Speed: "<<speed_getter()<<", Fuel: "<<fuel_getter()<<", Wings: "<<numWings<<", Engines: "<<numEngines<<endl;
        }
        Plane (const int &a,const int &b,const int &c,const int &d):AirVehicle(a,b,c),numEngines(d){}
};
int main() {
    LandVehicle landVehicle(80, 50, 4);
    WaterVehicle waterVehicle(60, 40, 2);
    AirVehicle airVehicle(300, 200, 2);
    Car car(120, 60, 4, 4);
    Boat boat(40, 30, 1, 2);
    Plane plane(600, 300, 2, 4);
    Vehicle* a=&landVehicle;
    Vehicle* b=&waterVehicle;
    Vehicle* c=&airVehicle;
    Vehicle* d=&car;
    Vehicle* e=&boat;
    Vehicle* f=&plane;
    a->displayInfo();
    b->displayInfo();
    c->displayInfo();
    d->displayInfo();
    e->displayInfo();
    f->displayInfo();
    return 0;
}
