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
    /// конструкторы
    // Конструктор по умолчанию
    Tyres();

    // Конструктор с параметрами
    Tyres(const char *brand,
          unsigned short width,
          unsigned short height,
          unsigned short radius);
    
    // Конструктор копирования
    Tyres(const Tyres &other);

    //Деструктор
    ~Tyres();

    // операторы
    Tyres& operator=(const Tyres &right);

    // Геттеры
    const char* getBrand() const;
    unsigned short getWidth() const;
    unsigned short getHeight() const;
    unsigned short getRadius() const;

    // Сеттеры
    void setBrand(const char *brand);
    void setWidth(const unsigned short width);
    void setHeight(const unsigned short height);
    void setRadius(const unsigned short radius);
};

#endif