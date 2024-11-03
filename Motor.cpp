#include "Motor.h"

size_t Motor::s_motorCount = 0;

const size_t Motor::getMotorCount() {
    return s_motorCount;
}

Motor::Motor()
{
    this->setMarking("Motor");
    this->setVolume(0.5);
    this->setWork(false);

    ++s_motorCount;

    std::cout << "Motor constructed\n";
}

Motor::Motor(const char * marking,
             double volume)
    :m_marking{nullptr}
{
    this->setMarking(marking);
    this->setVolume(volume);
    this->setWork(false);

    ++s_motorCount;

    std::cout << "Motor constructed\n";
}

Motor::Motor(const Motor& other)
{
    //для правильного выделения памяти
    setMarking(other.m_marking);
    this->m_volume = other.m_volume;
    this->m_work = other.m_work;

    ++s_motorCount;
}

Motor::Motor(Motor && other)
    :m_marking{other.m_marking},
    m_volume{other.m_volume},
    m_work{other.m_work}
{
    other.m_marking = nullptr;
    other.m_volume = 0.0;
    other.m_work = false;

    std::cout << "move Motor\n";
}

Motor::~Motor()
{
    if(m_marking != nullptr) {
        delete[] m_marking;
        m_marking = nullptr;
    }

    --s_motorCount;

    std::cout << "Motor destroyed\n";
}

const Motor& Motor::operator=(const Motor& right)
{
    if (this != &right)
    {
        setMarking(right.m_marking);
        m_volume = right.m_volume;
        m_work = right.m_work;

        ++s_motorCount;
    }

    return *this;
}

Motor &Motor::operator=(Motor &&right) {
    if(this == &right)
        return *this;
    
    if(this->m_marking != nullptr)
        delete[] this->m_marking;

    this->m_marking = right.m_marking;
    this->m_volume = right.m_volume;
    this->m_work = right.m_work;

    right.m_marking = nullptr;
    right.m_volume = 0.0;
    right.m_work = false;

    std::cout << "move = Motor\n";
    return *this;
}

void Motor::startEngine()
{
    this->m_work = true;
    std::cout << "(Motor is started)\n";
}

void Motor::offEngine()
{
    this->m_work = false;
    std::cout << "(Motor is off)\n";
}

bool Motor::getWork() const
{
    return this->m_work;
}

const char * Motor::getMarking() const
{
    return this->m_marking;
}

const double Motor::getVolume() const
{
    return this->m_volume;
}

// сеттеры
void Motor::setMarking(const char * mark)
{
    if(this->m_marking != nullptr) {
        delete[] this->m_marking;
        this->m_marking = nullptr;
    }

    int length = std::strlen(mark) + 1;
    this->m_marking = new char[length];
    strcpy_s(this->m_marking, length, mark);
}

void Motor::setWork(const bool state)
{
    this->m_work = state;
}

void Motor::setVolume(const double volume)
{
    if (volume >= 0.0)
        this->m_volume = volume;
    else
    {
        std::cout << "Invalid value for motor volume using standart volume 0.6\n";
        this->m_volume = 0.6;
    }
}
