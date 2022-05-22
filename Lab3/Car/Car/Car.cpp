#include "Car.h"

Car::Car()
{
    m_direction = stay;
    m_isTurnedOn = false;
    m_gear = 0;
    m_speed = 0;
}

Car::~Car()
{

}

bool Car::isTurnedOn()
{
    return m_isTurnedOn;
}
direction Car::GetDirection()
{
    return m_direction;
}
int Car::GetSpeed()
{
    return m_speed;
}
int Car::GetGear()
{
    return m_gear;
}
//�������� ���������(���� �� ��������).���������� true, ���� ��������� ���������(��� ��� ��� �������).
bool Car::TurnOnEngine()
{
    m_isTurnedOn = true;
    return true;
}
/*��������� ���������(���� �� ������� � ������� �������� � �����������, � ���������� �����).���������� true,
���� ��������� ��� ������� ��������(��� ��� ��� ��������), � false, ���� ��������� �� ����� ���� � ������ ������ ��������.*/
bool Car::TurnOffEngine()
{
    if (m_isTurnedOn)
    {
        if (m_gear == 0 && m_direction == stay)
        {
            m_isTurnedOn = false;
            return true;
        }
        else
        {
            return false;
        }
    }

    return true;
}
//������� ��������� ��������[-1..5].� ������ ��������� ������������ ��������(� ��� ����� � �� ���� ����) ���������� true.
bool Car::SetGear(int gear)
{
    if (m_isTurnedOn)
    {
        switch (gear)
        {
        case -1:
            if (m_speed == 0)
            {
                m_gear = -1;
                return true;
            }
            return false;
        case 0:
            m_gear = 0;
            return true;
        case 1:
            if (m_direction != back && m_speed == 0)
            {
                m_gear = 1;
                return true;
            }
            return false;
        case 2:
            if (m_direction == forward && (m_speed >= 20 && m_speed <= 50))
            {
                m_gear = 2;
                return true;
            }
            return false;
        case 3:
            if (m_direction == forward && (m_speed >= 30 && m_speed <= 60))
            {
                m_gear = 3;
                return true;
            }
            return false;
        case 4:
            if (m_direction == forward && (m_speed >= 40 && m_speed <= 90))
            {
                m_gear = 4;
                return true;
            }
            return false;
        case 5:
            if (m_direction == forward && (m_speed >= 50 && m_speed <= 150))
            {
                m_gear = 5;
                return true;
            }
            return false;
        default:
            return false;
        }
    }
    return false;
}
/*������ ��������� ��������.���������� true, ���� �������� ������� �������� � false, ���� �������� �������� �������� ��
��������� ����������(��������, �� ����������� �������� ������ �����������).*/
bool Car::SetSpeed(int speed)
{
    if (m_isTurnedOn)
    {
        switch (m_gear)
        {
        case -1:
            if (speed >= 0 && speed <= 20)
            {
                m_speed = speed;
                if (speed == 0)
                {
                    m_direction = stay;
                }
                else
                {
                    m_direction = back;
                }
                return true;
            }
            return false;
        case 0:
            if (m_speed >= speed && speed >= 0)
            {
                m_speed = speed;
                if (m_speed == 0)
                {
                    m_direction = stay;
                }
                return true;
            }
            return false;
        case 1:
            if (speed >= 0 && speed <= 20)
            {
                m_speed = speed;
                if (speed == 0)
                {
                    m_direction = stay;
                }
                else
                {
                    m_direction = forward;
                }
                return true;
            }
            return false;
        case 2:
            if (speed >= 20 && speed <= 50)
            {
                m_speed = speed;
                return true;
            }
            return false;
        case 3:
            if (speed >= 30 && speed <= 60)
            {
                m_speed = speed;
                return true;
            }
            return false;
        case 4:
            if (speed >= 40 && speed <= 90)
            {
                m_speed = speed;
                return true;
            }
            return false;
        case 5:
            if (speed >= 50 && speed <= 150)
            {
                m_speed = speed;
                return true;
            }
            return false;
        }
    }
    return false;
}