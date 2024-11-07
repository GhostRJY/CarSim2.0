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

    ///вывод из потока
    friend std::istream &operator>>(std::istream &input, Driver &obj) {



        std::cout << "Enter info for Driver\n";

        //создаю буфер для Имени и Фамилии
        char *nameBuf = new char[50];

        do {

            std::cout << "First name -> ";
            input >> std::setw(50) >> nameBuf;

            if(input.fail()) {
                input.clear();
                input.ignore(32767, '\n');
                std::cout << "Please try again.\n";

            } else
                break;


        } while(true);

        obj.setFirstName(nameBuf);

        //очищаю поток если что-то еще останется после ввода
        input.clear();
        input.ignore(32767, '\n');
        
        do {

            std::cout << "Last name -> ";
            input >> std::setw(50) >> nameBuf;

            if(input.fail()) {
                input.clear();
                input.ignore(32767, '\n');
                std::cout << "Please try again.\n";

            } else
                break;


        } while(true);

        //удаляю буфер Имен
        delete[] nameBuf;

        input.clear();
        input.ignore(32767, '\n');

        int exp{0};

        do {

            std::cout << "Experience of driving -> ";
            input >> exp;

            if(input.fail() || exp<0) {
                input.clear();
                input.ignore(32767, '\n');
                std::cout << "Please try again.\n";

            } else
                break;


        } while(true);

        obj.setExperience(exp);

        input.clear();
        input.ignore(32767, '\n');

        double enrg{0};

        do {

            std::cout << "Energy of driver -> ";
            input >> enrg;

            if(input.fail() || enrg<0 || enrg>100.00) {
                input.clear();
                input.ignore(32767, '\n');
                std::cout << "Please try again.\n";

            } else
                break;

        } while(true);
        
        input.clear();
        input.ignore(32767, '\n');

        input >> *obj.m_ptrAuto;

        return input;
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
    
    //операторы сравнения
    bool operator==(const Driver &right)const;
    bool operator!=(const Driver &right)const;
    bool operator>(const Driver &right)const;
    bool operator<(const Driver &right)const;

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