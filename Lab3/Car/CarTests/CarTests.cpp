#include <iostream>
#include "../Car/Car.h"
#include <assert.h>

using namespace std;

void TestCarCreation()
{
    Car car;

    assert(car.isTurnedOn() == false);
    assert(car.GetDirection() == stay);
    assert(car.GetGear() == 0);
    assert(car.GetSpeed() == 0);

    cout << "Car creation test is ok \n";
}

void TestTurningOnEngine()
{
    Car car;

    assert(car.TurnOnEngine());
}

void TestTurningOffEngine()
{
    Car car;

    car.TurnOnEngine();
    car.TurnOffEngine();
    assert(!car.isTurnedOn());

    car.TurnOffEngine();
    assert(!car.isTurnedOn());

    car.TurnOnEngine();
    car.SetGear(1);
    car.TurnOffEngine();
    assert(car.isTurnedOn());

    cout << "Test TurningOffEngine is ok \n";
}

void TestSetGear()
{
    Car car;

    car.SetGear(1);
    assert(car.GetGear() == 0);

    car.TurnOnEngine();
    car.SetGear(1);
    assert(car.GetGear() == 1);

    car.SetSpeed(10);
    car.SetGear(2);
    assert(car.GetGear() == 1);
    
    car.SetSpeed(20);
    car.SetGear(2);
    assert(car.GetGear() == 2);

    car.SetSpeed(50);
    car.SetGear(0);
    assert(car.GetGear() == 0);

    car.SetGear(1);
    assert(car.GetGear() == 0);

    car.SetGear(-1);
    assert(car.GetGear() == 0);

    car.SetSpeed(0);
    car.SetGear(-1);
    assert(car.GetGear() == -1);

    car.SetSpeed(10);
    car.SetGear(1);
    assert(car.GetGear() == -1);

    car.SetSpeed(0);
    car.SetGear(1);
    assert(car.GetGear() == 1);
    cout << "Test SetGear is ok \n";

}

void TestSetSpeed()
{
    Car car;

    car.SetSpeed(10);
    assert(car.GetSpeed() == 0);

    car.TurnOnEngine();
    car.SetSpeed(10);
    assert(car.GetSpeed() == 0);

    car.SetGear(1);
    car.SetSpeed(10);
    assert(car.GetSpeed() == 10);

    car.SetSpeed(50);
    assert(car.GetSpeed() == 10);
    cout << "Test SetSpeed is ok \n";
}

int main()
{
    TestCarCreation();
    TestTurningOnEngine();
    TestTurningOffEngine();
    TestSetGear();
    TestSetSpeed();
}
