#ifndef GEARBOX
#define GEARBOX
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class Gearbox
{
    static size_t s_gearboxCount;

private:
    char * m_marking;
    const std::vector<std::string> m_currentGear{ "Rear", "Neutral", "First", "Second", "Third", "Fourth", "Fifth", "Six", "Seven", "Eight", "Ninth", "Tenth" };
    unsigned short m_gearCount;
    unsigned short m_gearPos;

    friend std::ostream& operator<<(std::ostream& output, const Gearbox& obj)
    {
        output << std::setw(15) << "Gearbox type [" << obj.getMarking() << "], gearcount [" << obj.getGearCount() - 1 << "]\n";
        return output;
    }

    // ����� ���-�� �� ������������ ���� �� �� ��� �������� ���-�� ������� ����� ��������
    void setGearCount(const int count);

public:

static const size_t getGearboxCount();

    /// ������������
    // ����������� �� ���������
    Gearbox();

    // ����������� � �����������
    Gearbox(const char *marking, const int gearCount);

    // ����������� �����������
    Gearbox(const Gearbox &other);

    //����������� ��������
    Gearbox(Gearbox &&other);

    ~Gearbox();

    /// ���������
    //�������� �����������
    const Gearbox& operator=(const Gearbox &right);
    
    //�������� ��������
    Gearbox &operator=(Gearbox &&right);

    // �������
    void setMarking(const char *marking);

    void setGearPos(const unsigned short position);

    // �������
    unsigned short getGearPos() const;
    unsigned short getGearCount() const;
    const char * getMarking() const;
    std::vector<std::string> getGears() const;

    // ������ � �������� �������
    void shiftUp();

    void shiftDown();

    void shiftNeutral();

    // ����������� ���������
    void printGear();
};

#endif