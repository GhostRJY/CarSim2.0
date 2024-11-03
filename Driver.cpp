#include "Driver.h"
#define DEBUG

size_t Driver::s_driverCount = 0;

const size_t Driver::getDriverCount() {
    return s_driverCount;
}

Driver::Driver()
// инициализирую все указатели 0 из-за того что там лежат мусорные значения и соответственно сеттеры отрабатывают не правильно
    : m_fname{ nullptr },
    m_lname{ nullptr },
    m_ptrAuto{ nullptr },
    m_inAuto{false}
{
    setLastName("");
    setFirstName("");
    setExperience(0);
    setEnergy(100.00);

    ++s_driverCount;

#ifdef DEBUG
    std::cout << "Empty Driver created\n";
#endif
}

Driver::Driver(const char* firstName,
    const char* lastName,
    const Auto & automobile,
    const int experience, const double energy)
    : m_fname{ nullptr },
    m_lname{ nullptr },
    m_ptrAuto{ nullptr },
    m_inAuto{false} // инициализирую все указатели 0 из-за того что там лежат мусорные значения и соответственно сеттеры отрабатывают не правильно
{
    setLastName(lastName);
    setFirstName(firstName);
    setAuto(automobile);
    setExperience(experience);
    setEnergy(energy);

    ++s_driverCount;

#ifdef DEBUG
    std::cout << "Driver " << this->m_fname << ' ' << this->m_lname << " created\n";
#endif
}

Driver::Driver(const Driver &other)
    :m_fname{nullptr},
    m_lname{nullptr},
    m_ptrAuto{nullptr},
    m_inAuto{false}
{
    setLastName(other.m_lname);
    setFirstName(other.m_fname);
    setAuto(*other.m_ptrAuto);
    setExperience(other.m_experience);
    setEnergy(other.m_energy);

    ++s_driverCount;

#ifdef DEBUG
    std::cout << "Driver " << other.m_fname << ' ' << other.m_lname << " COPY created\n";
#endif
}

const Driver &Driver::operator=(const Driver &right) {
    setLastName(right.m_lname);
    setFirstName(right.m_fname);
    setAuto(*right.m_ptrAuto);
    setExperience(right.m_experience);
    setEnergy(right.m_energy);
    m_inAuto = false;

    ++s_driverCount;

    return *this;
}

//конструктор перемещения
Driver::Driver(Driver &&other)
    :m_ptrAuto{other.m_ptrAuto},
     m_fname{other.m_fname},
     m_lname{other.m_lname},
    m_experience{other.m_experience},
    m_energy{other.m_energy},
    m_inAuto{false}
{
    other.m_ptrAuto = nullptr;
    other.m_fname = nullptr;
    other.m_lname = nullptr;
    other.m_inAuto = false;
    other.m_experience = 0;
    other.m_energy = 0;

#ifdef DEBUG
    std::cout << "move driver\n";
#endif
}

//оператор перемещения
Driver &Driver::operator=(Driver &&right) {
    if(&right == this)
        return *this;

    if(m_ptrAuto != nullptr)
        delete m_ptrAuto;

    m_ptrAuto = right.m_ptrAuto;
    right.m_ptrAuto = nullptr;

    m_fname = right.m_fname;
    right.m_fname = nullptr;

    m_lname = right.m_lname;
    right.m_lname = nullptr;
    
    m_experience = right.m_experience;
    right.m_experience = 0;

    m_energy = right.m_energy;
    right.m_energy = 0;

    m_inAuto = false;
    right.m_inAuto = false;
#ifdef DEBUG
    std::cout << "move = driver\n";
#endif

    return *this;
}

Driver::~Driver()
{
    if (this->m_fname != nullptr)
    {
        delete[] this->m_fname;
        this->m_fname = nullptr;
#ifdef DEBUG
        std::cout << "\nFirst name is deleted correctly\n";
#endif
    }

    if (this->m_lname != nullptr)
    {
        delete[] this->m_lname;
        this->m_lname = nullptr;
#ifdef DEBUG
        std::cout << "\nLast name is deleted correctly\n";
#endif
    }

    if (this->m_ptrAuto != nullptr)
    {
        delete this->m_ptrAuto;
        this->m_ptrAuto = nullptr;

#ifdef DEBUG
        std::cout << "\nAutoPtr is deleted correctly\n";
#endif
    }

    --s_driverCount;

#ifdef DEBUG
    std::cout << "Object is deleted correctly\n";
#endif
}

void Driver::setFirstName(const char* fName)
{
    if (this->m_fname != nullptr)
    {
        delete[] this->m_fname;
        this->m_fname = nullptr;
    }

    int length = std::strlen(fName) + 1;
    this->m_fname = new char[length];
    strcpy_s(this->m_fname, length, fName);
}

void Driver::setLastName(const char* lName)
{
    if (this->m_lname != nullptr)
    {
        delete[] this->m_lname;
        this->m_lname = nullptr;
    }

    int length = std::strlen(lName) + 1;
    this->m_lname = new char[length];
    strcpy_s(this->m_lname, length, lName);
}

void Driver::setAuto(const Auto & automobile)
{
    if (this->m_ptrAuto != nullptr)
    {
        delete this->m_ptrAuto;
        this->m_ptrAuto = nullptr;
    }

    this->m_ptrAuto = new Auto{automobile};
}

void Driver::setExperience(const int experience)
{
    if (experience >= 0)
        this->m_experience = experience;
    else
    {
        std::cout << "invalid value!!!\n";
    }
}

void Driver::setEnergy(const double energy)
{
    if (energy >= 0.0 && energy <= 100.00)
        this->m_energy = energy;
    else
    {
        std::cout << "invalid value!!!\n";
    }
}

const char* Driver::getFirstName() const
{
    return this->m_fname;
}
const char* Driver::getLastName() const
{
    return this->m_lname;
}

Auto Driver::getAuto() const
{
    Auto temp{*this->m_ptrAuto};
    return temp;
}

int Driver::getExperience() const
{
    return this->m_experience;
}

double Driver::getEnergy() const
{
    return this->m_energy;
}

void Driver::goSleep()
{
    std::cout << "Driver " << m_fname << ' ' << m_lname << " Sleep well and have now energy for driving!\n";
    m_energy = 100.00;
}

void Driver::sitInCar()
{
    std::cout << "Driver " << m_fname << ' ' << m_lname << " sit in auto\n";
    m_inAuto = true;
}

void Driver::goOut()
{
    std::cout << "Driver " << m_fname << ' ' << m_lname << " go out\n";
    m_inAuto = false;
}
// завести авто
void Driver::startEngine()
{
    std::cout << "Driver " << m_fname << ' ' << m_lname << " start engine \n";
    m_ptrAuto->turnOn();
}
// начать поездку(сколько проехать)
bool Driver::startTrip(const int kms)
{
    if (m_energy > 0)
    {
        m_experience += m_ptrAuto->startMoving(kms);
        finishTrip();
        // усталость после поездки
        m_energy -= (kms * 12 / 100);
        std::cout << "the driver received " << kms << " experience\n"
            << "driver's energy: " << m_energy << '\n';
        return true;
    }
    else
    {
        std::cout << "Your driver can not drive (he hat no energy)!!!\n";
        return false;
    }
}
// окончить поездку
void Driver::finishTrip()
{
    m_ptrAuto->stopMoving();
    std::cout << "The driver has reached his destination\n";
    m_ptrAuto->turnOff();
}