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

    //�������� ����� � �����
    friend std::ostream &operator<<(std::ostream &out, const Driver &driver) {
        out << "Driver first name [" << driver.m_fname << "] last name [" << driver.m_lname << "] with experience [" << driver.m_experience << "] energy [" << driver.m_energy << "]\n";
        out << "drive car\n"
            << *driver.m_ptrAuto;

        return out;
    }

public:
    
static const size_t getDriverCount();

    /// ������������
    Driver();

    Driver(const char *firstName,
           const char *lastName,
           const Auto &automobile,
           const int experience,
           const double energy);

    ///�����������
    //����������� �����������
    Driver(const Driver &other);

    //�������� �����������
    const Driver &operator=(const Driver &right);

    ///�����������
    //����������� �����������
    Driver(Driver &&other);

    //�������� �����������
    Driver &operator=(Driver &&right);

    ~Driver();
    
    /// �������
    void setFirstName(const char *fName);
    void setLastName(const char *lName);
    void setAuto(const Auto &automobile);
    void setExperience(const int experience);
    void setEnergy(const double energy);
    
    /// �������
    const char* getFirstName() const;
    const char* getLastName() const;
    Auto getAuto() const;
    int getExperience() const;
    double getEnergy() const;

    /// ������ ��� ��������
    // ���������, ���� �������� �������
    void goSleep();
    // ����� � ������
    void sitInCar();
    // ����� �� ������
    void goOut();
    // ������� ����
    void startEngine();
    // ������ �������(������� ��������)
    bool startTrip(const int kms);
    // �������� �������
    void finishTrip();
};



#endif