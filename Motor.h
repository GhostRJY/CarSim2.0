#ifndef MOTOR
#define MOTOR

#include <string>
#include <iostream>
#include <iomanip>

class Motor
{
    static size_t s_motorCount;

private:
    // ����
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
    /// ������������
    // ����������� �� ���������
    Motor();

    // ����������� � �����������
    Motor(const char *marking,
          double volume);

    // ����������� �����������
    Motor(const Motor &other);
    
    //����������� ��������
    Motor(Motor &&other);

    //����������
    ~Motor();
    
    ///���������
    // �������� ������������ �����������
    const Motor& operator=(const Motor &right);
    Motor &operator=(Motor &&right);

    // ������ � ����������
    void startEngine();

    void offEngine();

    // �������
    bool getWork() const;
    const char * getMarking() const;
    const double getVolume() const;

    // �������
    void setMarking(const char *mark);
    void setWork(const bool state);
    void setVolume(const double volume);
};

#endif