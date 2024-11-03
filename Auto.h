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
    //���-�� �������� ������
    static size_t s_autoCount;

    private:    
    // ���� ������
    std::string m_brand;
    std::string m_model;
    double m_odometer;

    //���� ��������� �� ������� ������ �������
    Motor *m_motor;
    Gearbox *m_gearbox;
    Rims *m_rims;
    Tyres *m_tyres;
    
    // �������� ��������� � �����
    friend std::ostream&
        operator<<(std::ostream& output, const Auto& obj)
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

public:
    /// ������������

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

    // ����������� �����������
    Auto(const Auto &other);
    
    //����������� �����������
    Auto(Auto &&other);

    // ����������
    ~Auto();

    ///���������
    // �������� �����������
    const Auto& operator=(const Auto &right);
    
    // �������� �����������
    Auto &operator=(Auto &&right);

    /// �������
    std::string getBrand() const;
    std::string getModel() const;
    
    Motor getMotor() const;
    Gearbox getGearbox() const;
    Tyres getTyres() const;
    Rims getRims() const;
    double getOdometer() const;
    
    static const size_t getObjectCount();

    /// �������
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

    // ������ ������
    void turnOn();

    // ����� ������
    void turnOff();

    // �������� �����
    void gearUp();

    // �������� ����
    void gearDown();

    // ������ �������� ����
    int startMoving(const double);

    // ����������
    void stopMoving();
};

#endif