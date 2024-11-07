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

    ///ввод в поток
    friend std::ostream& operator<<(std::ostream& output, const Gearbox& obj)
    {
        output << std::setw(15) << "Gearbox type [" << obj.getMarking() << "], gearcount [" << obj.getGearCount() - 1 << "]\n";
        return output;
    }

    ///вывод из потока
    friend std::istream &operator>>(std::istream &input, Gearbox &obj) {



        std::cout << "Enter values for Gearbox\n";

        char *brand = new char[21];

        do {

            std::cout << "Marking -> ";
            input >> std::setw(20) >> brand;

            if(input.fail()) {
                input.clear();
                input.ignore(32767, '\n');
                std::cout << "Please try again.\n";

            } else
                break;


        } while(true);

        obj.setMarking(brand);
        delete[] brand;

        unsigned short values;

        input.clear();
        input.ignore(32767, '\n');

        do {

            std::cout << "Gear count -> ";
            input >> std::setw(2) >> values;

            if(input.fail()) {
                input.clear();
                input.ignore(32767, '\n');
                std::cout << "Please try again.\n";

            } else
                break;


        } while(true);

        obj.setGearCount(values);

        input.clear();
        input.ignore(32767, '\n');

        do {

            std::cout << "Gear position -> ";
            input >> std::setw(3) >> values;

            if(input.fail() && values > 3 && values < 11) {
                input.clear();
                input.ignore(32767, '\n');
                std::cout << "Please try again.\n";

            } else
                break;


        } while(true);

        obj.setGearPos(values);
        
        return input;
    }

    // прячу фун-ию от пользователя чтоб он не мог изменить кол-во передач после создания
    void setGearCount(const int count);
    
    std::string toString()const;

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

    //операторы сравнения
    bool operator==(const Gearbox &right) const;
    bool operator!=(const Gearbox &right) const;
    bool operator>(const Gearbox &right) const;
    bool operator<(const Gearbox &right) const;

    //оператор привидения к типу
    explicit operator std::string() const;

    // работа с коробкой передач
    void shiftUp();

    void shiftDown();

    void shiftNeutral();

    // отображение состояний
    void printGear();
};

#endif