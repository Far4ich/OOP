#pragma once

// ������������ scoped enum
enum direction { forward, back, stay };
//��������� ������ �������� ��� 20 �������� 2 ��������
//const ���������
class Car
{
public:
    Car();

    ~Car();

    bool isTurnedOn();

    direction GetDirection();

    int GetSpeed();

    int GetGear();

    bool TurnOnEngine();

    bool TurnOffEngine();

    bool SetGear(int gear);

    bool SetSpeed(int speed);
private:
    direction m_direction;
    bool m_isTurnedOn;
    int m_speed;
    int m_gear;
};

