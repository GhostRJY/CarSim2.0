#include <iostream>
#include "Auto.h"
#include "Driver.h"

int main()
{

 

    Motor audiMotor{"TDI", 3.0};
    Gearbox audiGearbox{"ZF", 6};
    Rims audiRims{"BBS", 245, 50, 18};
    Tyres audiTyres{"Pirelli", 245, 50, 18};
    
    Auto automobile{ "Audi", "A6", 1503.0, audiMotor, audiGearbox, audiRims, audiTyres};
    
    Driver driver("Yevhenii", "Rode", automobile, 300, 100.00);
    //Driver driver1(Driver("David", "Rode", automobile, 300, 100.00));
    //driver1 = driver;
    
    std::cout << driver;
    //std::cout << driver1;
    
    //симуляция поездки
 
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
     
    return 0;
}
