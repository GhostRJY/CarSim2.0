#ifndef RIMS
#define RIMS

#include <string>
#include <iostream>
#include <iomanip>
#include <windows.h>

class Rims
{
    private:
    char* m_brand;
    unsigned short m_width;
    unsigned short m_height;
    unsigned short m_radius;

    friend std::ostream &operator<<(std::ostream &output, const Rims &obj) {
        output << std::setw(15) << "Wheels brand [" << obj.m_brand << "] size [" << obj.m_width << 'x' << obj.m_height << " radius " << obj.m_radius << "]\n";

        return output;
    }

    public:
    // конструкторы

    // конструктор по умолчанию
    Rims();

    // конструктор с параметрами
    Rims(const char *brand,
         unsigned short width,
         unsigned short height,
         unsigned short radius);

    // конструктор копирования
    Rims(const Rims &other);

    Rims(Rims &&other)noexcept;

    ~Rims();

    // операторы
    const Rims &operator=(const Rims &right);
    Rims &operator=(Rims &&right);

    // геттеры
    const char * getBrand() const;
    unsigned short getWidth() const;
    unsigned short getHeight() const;
    unsigned short getRadius() const;

    // сеттеры
    void setBrand(const char *brand);
    void setWidth(const unsigned short width);
    void setHeight(const unsigned short height);
    void setRadius(const unsigned short radius);

    // состояния
    void spinWheels(bool);
};

#endif