#include <iostream>
#include<windows.h>
#include "Auto.h"
#include "Driver.h"

//#define DEBUG

int main()
{
    Motor audiMotor{"TDI", 3.0};

#ifdef DEBUG
    Motor motor{"TDI", 2.0};
#endif
    Gearbox audiGearbox{"ZF", 6};

#ifdef DEBUG
    Gearbox gearbox{"IL", 5};
#endif
    Rims audiRims{"BBS", 250, 50, 18};

#ifdef DEBUG
    Rims rims{"BORBET", 245, 50, 18};
#endif    
    Tyres audiTyres{"Pirelli", 250, 50, 18};

#ifdef DEBUG
    Tyres tyres{"Dunlop", 255, 50, 18};
#endif    
    Auto automobile{ "Audi", "A6", 1503.0, audiMotor, audiGearbox, audiRims, audiTyres};

#ifdef DEBUG
    Auto automobile2{"Audi", "A4", 21503.0, motor, gearbox, rims, tyres};
#endif

    Driver driver("Yevhenii", "Rode", automobile, 300, 100.00);

    //Driver driver1("David", "Rode", automobile, 1300, 100.00);


    ///проверка ввода вывода информации Автомобиля
    /*std::cin >> automobile;
    std::cout << automobile;*/
        
    //driver1 = driver;
    
    ///проверка ввода вывода информации о Водителе
    /*std::cin >> driver;
    std::cout << driver;*/


    //std::cout << driver1;
    //
    
    ////симуляция поездки
 
     driver.sitInCar();
     driver.startEngine();
     if (driver.startTrip(100))
     {
         std::cout << driver.getEnergy() << " " << driver.getExperience() << "\n\n";
     }
     else
     {
         driver.goOut();
         driver.goSleep();
     }

    ///проверка операторов сравнения
#ifdef DEBUG
    //проверка шин
    if(audiTyres == tyres) {
        std::cout << audiTyres << " == " << tyres;
    }

    if(audiTyres != tyres) {
        std::cout << audiTyres << " != " << tyres;
    }

    if(audiTyres > tyres) {
        std::cout << audiTyres << " > " << tyres;
    }

    if(audiTyres < tyres) {
        std::cout << audiTyres << " < " << tyres;
    }

    //проверка дисков
    if(audiRims == rims) {
        std::cout << audiRims << " == " << rims;
    }

    if(audiRims != rims) {
        std::cout << audiRims << " != " << rims;
    }

    if(audiRims > rims) {
        std::cout << audiRims << " > " << rims;
    }

    if(audiRims < rims) {
        std::cout << audiRims << " < " << rims;
    }

    //проверка коробки
    if(audiGearbox == gearbox) {
        std::cout << audiGearbox << " == " << gearbox;
    }

    if(audiGearbox != gearbox) {
        std::cout << audiGearbox << " != " << gearbox;
    }

    if(audiGearbox > gearbox) {
        std::cout << audiGearbox << " > " << gearbox;
    }

    if(audiGearbox < gearbox) {
        std::cout << audiGearbox << " < " << gearbox;
    }

    //проверка мотора
    if(audiMotor == motor) {
        std::cout << audiMotor << " == " << motor;
    }

    if(audiMotor != motor) {
        std::cout << audiMotor << " != " << motor;
    }

    if(audiMotor > motor) {
        std::cout << audiMotor << " > " << motor;
    }

    if(audiMotor < motor) {
        std::cout << audiMotor << " < " << motor;
    }

    //проверка автомобилей
    if(automobile == automobile2) {
        std::cout << automobile << " == " << automobile2;
}

    if(automobile != automobile2) {
        std::cout << automobile << " != " << automobile2;
    }

    if(automobile > automobile2) {
        std::cout << automobile << " > " << automobile2;
    }

    if(automobile < automobile2) {
        std::cout << automobile << " < " << automobile2;
    }

    //проверка водителей
    if(driver == driver1) {
        std::cout << driver << " == " << driver1;
    }

    if(driver != driver1) {
        std::cout << driver << " != " << driver1;
    }

    if(driver > driver1) {
        std::cout << driver << " > " << driver1;
    }

    if(driver < driver1) {
        std::cout << driver << " < " << driver1;
    }
#endif


    ///проверка привидения к стрингу
#ifdef DEBUG
    std::string test{};
    test = (std::string)audiTyres;
    std::cout << test << '\n';
    test = (std::string)audiRims;
    std::cout << test << '\n';
    test = (std::string)audiGearbox;
    std::cout << test << '\n';
    test = (std::string)audiMotor;
    std::cout << test << '\n';
    test = (std::string)automobile;
    std::cout << test << '\n';
#endif

    getchar();
    return 0;
}
