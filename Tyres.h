#ifndef TYRES
#define TYRES
#include <string>
#include <iostream>
#include <iomanip>

class Tyres
{
private:
    char* m_brand;
    unsigned short m_width;
    unsigned short m_height;
    unsigned short m_radius;

    friend std::ostream& operator<<(std::ostream& output, const Tyres& obj)
    {
        output << std::setw(15) << "Tyres brand [" << obj.m_brand << "] size [" << obj.m_width << 'x' << obj.m_height << " radius " << obj.m_radius << "]\n";

        return output;
    }

public:
    /// ������������
    // ����������� �� ���������
    Tyres();

    // ����������� � �����������
    Tyres(const char *brand,
          unsigned short width,
          unsigned short height,
          unsigned short radius);
    
    // ����������� �����������
    Tyres(const Tyres &other);

    //����������
    ~Tyres();

    // ���������
    Tyres& operator=(const Tyres &right);

    // �������
    const char* getBrand() const;
    unsigned short getWidth() const;
    unsigned short getHeight() const;
    unsigned short getRadius() const;

    // �������
    void setBrand(const char *brand);
    void setWidth(const unsigned short width);
    void setHeight(const unsigned short height);
    void setRadius(const unsigned short radius);
};

#endif