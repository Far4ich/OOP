#include <iostream>
#include <string>
#include "Car.h"
#include "CarApp.h"

/*Х	Info.¬ыводит состо€ние двигател€ автомобил€, направление движени€, скорость и передачу
Х	EngineOn.¬ключает двигатель
Х	EngineOff.¬ыключает двигатель
Х	SetGear передача.¬ключает заданную передачу, заданную числом от - 1 до 5. ¬ случае ошибки сообщает о причине невозможности переключени€ передачи
Х	SetSpeed скорость.”станавливает указанную скорость движени€, заданную неотрицательным числом.¬ случае невозможности изменени€ скорости сообщает о причине невозможности изменить скорость на указанную.
*/
using namespace std;

void Info(Car car)
{
    if (car.isTurnedOn())
    {
        cout << "Engine turn on\n";
    }
    else
    {
        cout << "Engine turn off\n";
    }
    switch (car.GetDirection())
    {
    case 2:
        cout << "Car is staying\n";
        break;
    case 1:
        cout << "Car move back\n";
        break;
    case 0:
        cout << "Car move forward\n";
        break;
    }
    cout << "Speed is " << car.GetSpeed() << "\n";
    cout << "Gear is " << car.GetGear() << "\n";
}

void EngineOn(Car& car)
{
    if (car.TurnOnEngine())
    {
        cout << "Engine turned on\n";
    }
    else
    {
        cout << "Engine did not turned on\n";
    }
}

void EngineOff(Car& car)
{
    if (car.TurnOffEngine())
    {
        cout << "Engine turned off\n";
    }
    else
    {
        cout << "Engine did not turned off\n";
    }
}

void SetGear(Car& car, string action)
{
    string value;
    value.append(action, action.find(" "));
    int gear = stoi(value);
    
    if (car.SetGear(gear))
    {
        cout << "Gear is changed\n";
    }
    else
    {
        cout << "Gear isn't changed\n";
    }
}

void SetSpeed(Car& car, string action)
{
    string value;
    value.append(action, action.find(" "));
    int speed = stoi(value);
    
    if (car.SetSpeed(speed))
    {
        cout << "Speed is changed\n";
    }
    else
    {
        cout << "Speed isn't changed\n";
    }
}
int GetAction(const string in)
{
    string action;
    size_t pos = in.find(" ");
    if (pos != string::npos)
    {
        action.append(in, 0, pos);
    }
    else
    {
        action = in;
    }
    if (action == "Info")
    {
        return 0;
    }
    if (action == "EngineOn")
    {
        return 1;
    }
    if (action == "EngineOff")
    {
        return 2;
    }
    if (action == "SetGear")
    {
        return 3;
    }
    if (action == "SetSpeed")
    {
        return 4;
    }
    return -1;
}
int main()
{
    string action;
    Car car;
    while (getline(cin, action))
    {
        switch (GetAction(action))
        {
            case 0: 
                Info(car);
                break;
            case 1:
                EngineOn(car);
                break;
            case 2:
                EngineOff(car);
                break;
            case 3:
                SetGear(car, action);
                break; 
            case 4:
                SetSpeed(car, action);
                break;
            default:
                cout << "Operation not found, try Info EngineOn EngineOff SetGear SetSpeed\n";
                break;
        }
    }

    return 0;
}