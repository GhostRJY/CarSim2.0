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

    ///ввод в поток
    friend std::ostream &operator<<(std::ostream &output, const Rims &obj) {
        output << std::setw(15) << "Wheels brand [" << obj.m_brand << "] size [" << obj.m_width << 'x' << obj.m_height << " radius " << obj.m_radius << "]\n";

        return output;
    }

    ///вывод из потока
    friend std::istream &operator>>(std::istream &input, Rims &obj) {



        std::cout << "Enter values for Rims\n";

        char *brand = new char[21];

        do {

            std::cout << "Brand -> ";
            input >> std::setw(20) >> brand;

            if(input.fail()) {
                input.clear();
                input.ignore(32767, '\n');
                std::cout << "Please try again.\n";

            } else
                break;


        } while(true);

        obj.setBrand(brand);
        delete[] brand;

        unsigned short values;

        input.clear();
        input.ignore(32767, '\n');

        do {

            std::cout << "Width -> ";
            input >> std::setw(3) >> values;

            if(input.fail()) {
                input.clear();
                input.ignore(32767, '\n');
                std::cout << "Please try again.\n";

            } else
                break;


        } while(true);

        obj.setWidth(values);

        input.clear();
        input.ignore(32767, '\n');

        do {

            std::cout << "Height -> ";
            input >> std::setw(3) >> values;

            if(input.fail()) {
                input.clear();
                input.ignore(32767, '\n');
                std::cout << "Please try again.\n";

            } else
                break;


        } while(true);

        obj.setHeight(values);

        input.clear();
        input.ignore(32767, '\n');

        do {

            std::cout << "Radius -> ";
            input >> std::setw(3) >> values;

            if(input.fail()) {
                input.clear();
                input.ignore(32767, '\n');
                std::cout << "Please try again.\n";

            } else
                break;


        } while(true);

        obj.setRadius(values);

        return input;
    }

    std::string toString()const;

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

    //операторы спавнения
    bool operator==(const Rims &right) const;
    bool operator!=(const Rims &right) const;
    bool operator>(const Rims &right) const;
    bool operator<(const Rims &right) const;

    //оператор привидения к типу
    explicit operator std::string() const;

    // состояния
    void spinWheels(bool);
};

#endif