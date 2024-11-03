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

    // прячу фун-ию от пользователя чтоб он не мог изменить кол-во передач после создания
    void setGearCount(const int count);

public:

static const size_t getGearboxCount();

    /// конструкторы
    // конструктор по умолчанию
    Gearbox();

    // конструктор с параметрами
    Gearbox(const char *marking, const int gearCount);

    // конструктор копирования
    Gearbox(const Gearbox &other);

    //конструктор переноса
    Gearbox(Gearbox &&other);

    ~Gearbox();

    /// операторы
    //оператор копирования
    const Gearbox& operator=(const Gearbox &right);
    
    //оператор переноса
    Gearbox &operator=(Gearbox &&right);

    // сеттеры
    void setMarking(const char *marking);

    void setGearPos(const unsigned short position);

    // геттеры
    unsigned short getGearPos() const;
    unsigned short getGearCount() const;
    const char * getMarking() const;
    std::vector<std::string> getGears() const;

    // работа с коробкой передач
    void shiftUp();

    void shiftDown();

    void shiftNeutral();

    // отображение состояний
    void printGear();
};

#endif