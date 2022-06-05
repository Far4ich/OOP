#include <iostream>
#include <string>
#include "Car.h"
#include "CarApp.h"

/*�	Info.������� ��������� ��������� ����������, ����������� ��������, �������� � ��������
�	EngineOn.�������� ���������
�	EngineOff.��������� ���������
�	SetGear ��������.�������� �������� ��������, �������� ������ �� - 1 �� 5. � ������ ������ �������� � ������� ������������� ������������ ��������
�	SetSpeed ��������.������������� ��������� �������� ��������, �������� ��������������� ������.� ������ ������������� ��������� �������� �������� � ������� ������������� �������� �������� �� ���������.
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
    switch (car.GetGear())
    {
    case -1:
        if (car.SetSpeed(speed))
        {
            cout << "Speed is changed\n";
        }
        else
        {
            cout << "Speed isn't changed, at -1 gear speed can be 0-20\n";
        }
        break;
    case 0:
        if (car.SetSpeed(speed))
        {
            cout << "Speed is changed\n";
        }
        else
        {
            cout << "Speed isn't changed, car can't accelerating at 0 gear\n";
        }
        break;
    case 1:
        if (car.SetSpeed(speed))
        {
            cout << "Speed is changed\n";
        }
        else
        {
            cout << "Speed isn't changed, at 1 gear speed can be 0-30\n";
        }
        break;
    case 2:
        if (car.SetSpeed(speed))
        {
            cout << "Speed is changed\n";
        }
        else
        {
            cout << "Speed isn't changed, at 2 gear speed can be 20-50\n";
        }
        break;
    case 3:
        if (car.SetSpeed(speed))
        {
            cout << "Speed is changed\n";
        }
        else
        {
            cout << "Speed isn't changed, at 3 gear speed can be 30-60\n";
        }
        break;
    case 4:
        if (car.SetSpeed(speed))
        {
            cout << "Speed is changed\n";
        }
        else
        {
            cout << "Speed isn't changed, at 4 gear speed can be 40-90\n";
        }
        break;
    case 5:
        if (car.SetSpeed(speed))
        {
            cout << "Speed is changed\n";
        }
        else
        {
            cout << "Speed isn't changed, at 5 gear speed can be 50-150\n";
        }
        break;
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