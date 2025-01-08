#include "Vehicle.h"
class Car : public Vehicle
{
public:
    Car(string name) : Vehicle(name) {}

    void drive();
};

class Boat : public Vehicle
{
public:
    Boat(string name) : Vehicle(name) {}

    void drive();
};

class AmphibianCar : public Car, public Boat
{
public:
    AmphibianCar(string name) : Car(name), Boat(name) {}
    void driveAsCar();
    void driveAsBoat();
};

void Boat::drive()
{
    AmphibianCar *ac = dynamic_cast<AmphibianCar *>(this);
    if (ac)
    {
        ac->driveAsBoat();
    }
    else
    {
        cout << name << " drive on river" << endl;
    }
}
void Car::drive()
{
    AmphibianCar *ac = dynamic_cast<AmphibianCar *>(this);
    if (ac)
    {
        ac->driveAsCar();
    }
    else
    {
        cout << name << " drive on road" << endl;
    }
}

void AmphibianCar::driveAsCar()
{
    cout << Car::name << " drive on road as car" << endl;
}

void AmphibianCar::driveAsBoat()
{
    cout << Boat::name << " drive on river as boat" << endl;
}
