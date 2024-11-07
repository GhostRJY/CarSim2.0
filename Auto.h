#ifndef AUTO
#define AUTO

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <windows.h>
#include "Gearbox.h"
#include "Tyres.h"
#include "Rims.h"
#include "Motor.h"

class Auto
{
    //кол-во объектов класса
    static size_t s_autoCount;

    private:    
    // поля класса
    std::string m_brand;
    std::string m_model;
    double m_odometer;

    //поля указатели на объекты других классов
    Motor *m_motor;
    Gearbox *m_gearbox;
    Rims *m_rims;
    Tyres *m_tyres;
    
    // оператор помещения в поток
    friend std::ostream &operator<<(std::ostream& output, const Auto& obj)
    {
        output << std::setw(15) << "\nAuto brand [" << obj.m_brand << "] model [" << obj.m_model << "] odometer: "
            << std::setprecision(2) << std::fixed << std::showpoint << obj.m_odometer << " km\n"
            << "\t\tSpecifications\n"
            << *obj.m_motor
            << *obj.m_gearbox
            << *obj.m_rims
            << *obj.m_tyres
            << '\n';

        return output;
    }

    ///вывод из потока
    friend std::istream &operator>>(std::istream &input, Auto &obj) {



        std::cout << "Enter values for Automobile\n";
               

        do {

            std::cout << "Producer -> ";
            input >> std::setw(20) >> obj.m_brand;

            if(input.fail()) {
                input.clear();
                input.ignore(32767, '\n');
                std::cout << "Please try again.\n";

            } else
                break;


        } while(true);
        
        input.clear();
        input.ignore(32767, '\n');

        do {

            std::cout << "Model -> ";
            input >> std::setw(20) >> obj.m_model;

            if(input.fail()) {
                input.clear();
                input.ignore(32767, '\n');
                std::cout << "Please try again.\n";

            } else
                break;


        } while(true);

        input.clear();
        input.ignore(32767, '\n');

        double odometer{0.0};

        do {

            std::cout << "odometer display -> ";
            input >> std::setw(10) >> odometer;

            if(input.fail() || odometer < 0) {
                input.clear();
                input.ignore(32767, '\n');
                std::cout << "Please try again.\n";

            } else
                break;


        } while(true);

        obj.setOdometer(odometer);

        input.clear();
        input.ignore(32767, '\n');

        input >> *obj.m_motor;
        input >> *obj.m_gearbox;
        input >> *obj.m_rims;
        input >> *obj.m_tyres;


        return input;
    }

    std::string toString() const;

public:
    /// конструкторы

    Auto();
    Auto(const std::string &brand,
         const std::string &model,
         const double odometer,
         const char *motorMarking,
         const double motorVolume,
         const char *gearBoxMarking,
         const unsigned short gearCount,
         const char *rimsMark,
         const char *tyreMark,
         const unsigned short width,
         const unsigned short height,
         const unsigned short radius);

    Auto(const std::string &brand,
         const std::string &model,
         const double odometer,
         const Motor &motor,
         const Gearbox &gearbox,
         const Rims &rims,
         const Tyres &tyres);

    // конструктор копирования
    Auto(const Auto &other);
    
    //конструктор перемещения
    Auto(Auto &&other);

    // деструктор
    ~Auto();

    ///операторы
    // оператор копирования
    const Auto& operator=(const Auto &right);
    
    // оператор перемещения
    Auto &operator=(Auto &&right);

    //операторы сравнения
    bool operator==(const Auto &right)const;
    bool operator!=(const Auto &right)const;
    bool operator>(const Auto &right)const;
    bool operator<(const Auto &right)const;

    //оператор привидения к типу
    explicit operator std::string() const;

    /// геттеры
    std::string getBrand() const;
    std::string getModel() const;
    
    Motor getMotor() const;
    Gearbox getGearbox() const;
    Tyres getTyres() const;
    Rims getRims() const;
    double getOdometer() const;
    
    static const size_t getObjectCount();

    /// сеттеры
    void setBrand(const std::string &brand);
    void setModel(const std::string &model);
    void setOdometer(const double odometer);

    void setMotor(const Motor &motor);
    void setMotor(const char *mark,
                  const double volume);

    void setGearbox(const Gearbox &gearbox);
    void setGearbox(const char *mark,
                    unsigned short gearCount);

    void setRims(const Rims &rims);
    void setRims(const char *mark,
                 const unsigned short width,
                 const unsigned short height,
                 const unsigned short radius);

    void setTyres(const Tyres &tyres);
    void setTyres(const char *mark,
                  const unsigned short width,
                  const unsigned short height,
                  const unsigned short radius);

    // завожу машину
    void turnOn();

    // глушу машину
    void turnOff();

    // передача вверх
    void gearUp();

    // передача вниз
    void gearDown();

    // начать движение авто
    int startMoving(const double);

    // замедлятся
    void stopMoving();
};

#endif