#ifndef MOTOR
#define MOTOR

#include <string>
#include <iostream>
#include <iomanip>

class Motor
{
    static size_t s_motorCount;

private:
    // поля
    char * m_marking;
    bool m_work;
    double m_volume;

    ///ввод в поток
    friend std::ostream& operator<<(std::ostream& output, const Motor& obj)
    {
        output << std::setw(15) << "Motor mark [" << obj.m_marking << "] volume [" << obj.m_volume << "]\n";

        return output;
    }

    ///вывод из потока
    friend std::istream &operator>>(std::istream &input, Motor &obj) {



        std::cout << "Enter values for Motor\n";

        char *marking = new char[21];

        do {

            std::cout << "Marking -> ";
            input >> std::setw(20) >> marking;

            if(input.fail()) {
                input.clear();
                input.ignore(32767, '\n');
                std::cout << "Please try again.\n";

            } else
                break;


        } while(true);

        obj.setMarking(marking);
        delete[] marking;

        double values;

        input.clear();
        input.ignore(32767, '\n');

        do {

            std::cout << "Volume of motor -> ";
            input >> std::setw(10) >> values;

            if(input.fail() || values<0.5) {
                input.clear();
                input.ignore(32767, '\n');
                std::cout << "Please try again.\n";

            } else
                break;


        } while(true);

        obj.setVolume(values);


        return input;
    }

    std::string toString() const;
public:

static const size_t getMotorCount();
    /// конструкторы
    // конструктор по умолчанию
    Motor();

    // конструктор с параметрами
    Motor(const char *marking,
          double volume);

    // конструктор копирования
    Motor(const Motor &other);
    
    //конструктор переноса
    Motor(Motor &&other);

    //деструктор
    ~Motor();
    
    ///операторы
    // оператор присваивания копирования
    const Motor& operator=(const Motor &right);
    Motor &operator=(Motor &&right);

    //операторы сравнения
    bool operator==(const Motor &right) const;
    bool operator!=(const Motor &right) const;
    bool operator>(const Motor &right) const;
    bool operator<(const Motor &right) const;

    //оператор привидения к типу
    explicit operator std::string() const;

    // работа с двигателем
    void startEngine();

    void offEngine();

    // геттеры
    bool getWork() const;
    const char * getMarking() const;
    const double getVolume() const;

    // сеттеры
    void setMarking(const char *mark);
    void setWork(const bool state);
    void setVolume(const double volume);

};

#endif