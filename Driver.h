#ifndef DRIVER_H
#define DRIVER_H
#include "Auto.h"
#include <iostream>

class Driver
{
    static size_t s_driverCount;

private:
    char* m_fname;
    char* m_lname;
    Auto* m_ptrAuto;
    int m_experience;
    double m_energy;
    bool m_inAuto{ false };

    //оператор ввода в поток
    friend std::ostream &operator<<(std::ostream &out, const Driver &driver) {
        out << "Driver first name [" << driver.m_fname << "] last name [" << driver.m_lname << "] with experience [" << driver.m_experience << "] energy [" << driver.m_energy << "]\n";
        out << "drive car\n"
            << *driver.m_ptrAuto;

        return out;
    }

public:
    
static const size_t getDriverCount();

    /// конструкторы
    Driver();

    Driver(const char *firstName,
           const char *lastName,
           const Auto &automobile,
           const int experience,
           const double energy);

    ///копирование
    //конструктор копирования
    Driver(const Driver &other);

    //оператор копирования
    const Driver &operator=(const Driver &right);

    ///перемещение
    //конструктор перемещения
    Driver(Driver &&other);

    //оператор перемещения
    Driver &operator=(Driver &&right);

    ~Driver();
    
    /// сеттеры
    void setFirstName(const char *fName);
    void setLastName(const char *lName);
    void setAuto(const Auto &automobile);
    void setExperience(const int experience);
    void setEnergy(const double energy);
    
    /// геттеры
    const char* getFirstName() const;
    const char* getLastName() const;
    Auto getAuto() const;
    int getExperience() const;
    double getEnergy() const;

    /// методы для водителя
    // отдохнуть, чтоб обновить энергию
    void goSleep();
    // сесть в машину
    void sitInCar();
    // выйти из машины
    void goOut();
    // завести авто
    void startEngine();
    // начать поездку(сколько проехать)
    bool startTrip(const int kms);
    // окончить поездку
    void finishTrip();
};



#endif