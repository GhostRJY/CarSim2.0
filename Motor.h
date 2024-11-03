#ifndef MOTOR
#define MOTOR

#include <string>
#include <iostream>
#include <iomanip>

class Motor
{
    static size_t s_motorCount;

private:
    // поля
    char * m_marking;
    bool m_work;
    double m_volume;

    friend std::ostream& operator<<(std::ostream& output, const Motor& obj)
    {
        output << std::setw(15) << "Motor mark [" << obj.m_marking << "] volume [" << obj.m_volume << "]\n";

        return output;
    }

public:

static const size_t getMotorCount();
    /// конструкторы
    // конструктор по умолчанию
    Motor();

    // конструктор с параметрами
    Motor(const char *marking,
          double volume);

    // конструктор копирования
    Motor(const Motor &other);
    
    //конструктор переноса
    Motor(Motor &&other);

    //деструктор
    ~Motor();
    
    ///операторы
    // оператор присваивания копирования
    const Motor& operator=(const Motor &right);
    Motor &operator=(Motor &&right);

    // работа с двигателем
    void startEngine();

    void offEngine();

    // геттеры
    bool getWork() const;
    const char * getMarking() const;
    const double getVolume() const;

    // сеттеры
    void setMarking(const char *mark);
    void setWork(const bool state);
    void setVolume(const double volume);
};

#endif