#include "Auto.h"

size_t Auto::s_autoCount = 0;

Auto::Auto()
    : m_motor{nullptr},
      m_gearbox{nullptr},
      m_rims{nullptr},
      m_tyres{nullptr}
{
    this->setBrand("Auto");

    this->setModel("Model");

    this->setOdometer(1000.00);
    
    this->setMotor(Motor());

    this->setGearbox(Gearbox());

    this->setTyres(Tyres());

    this->setRims(Rims());
        
    ++s_autoCount;

    std::cout << "Auto constructed\n";
}

Auto::Auto(const std::string& brand,
    const std::string& model,
    const double odometer,
    const char * motorMarking,
    const double motorVolume,
    const char * gearBoxMarking,
    const unsigned short gearCount,
    const char * rimsMark,
    const char* tyreMark,
    const unsigned short width,
    const unsigned short height,
    const unsigned short radius)
    :m_motor{nullptr},
     m_gearbox{nullptr},
     m_rims{nullptr},
     m_tyres{nullptr}
    
{
    // делегирую инициализацию полей класса
    this->setBrand(brand);

    this->setModel(model);

    this->setMotor(motorMarking, motorVolume);

    this->setGearbox(gearBoxMarking, gearCount);

    this->setTyres(tyreMark, width, height, radius);

    this->setRims(rimsMark, width, height, radius);

    this->setOdometer(odometer);

    ++s_autoCount;

    std::cout << "Auto constructed\n";
}

Auto::Auto(const std::string &brand,
           const std::string &model,
           const double odometer,
           const Motor &motor,
           const Gearbox &gearbox,
           const Rims &rims,
           const Tyres &tyres)
    :m_motor{nullptr},
     m_gearbox{nullptr},
     m_rims{nullptr},
     m_tyres{nullptr}
{
    
    this->setBrand(brand);

    this->setModel(model);

    this->setOdometer(odometer);

    this->setMotor(motor);

    this->setGearbox(gearbox);
        
    this->setRims(rims);

    this->setTyres(tyres);    

    ++s_autoCount;
}

Auto::Auto(const Auto& other)
    :m_brand{other.m_brand},
    m_model{other.m_model},    
    m_odometer{other.m_odometer}

{
    this->setMotor(*other.m_motor);
    this->setGearbox(*other.m_gearbox);
    this->setRims(*other.m_rims);
    this->setTyres(*other.m_tyres);
    
    ++s_autoCount;
}

Auto::Auto(Auto &&other)
    :   m_motor{other.m_motor},
        m_gearbox{other.m_gearbox},
        m_rims{other.m_rims},
        m_tyres{other.m_tyres},
        m_brand{other.m_brand},
        m_model{other.m_model},
        m_odometer{other.m_odometer}
{
    other.m_motor = nullptr;
    other.m_gearbox = nullptr;
    other.m_rims = nullptr;
    other.m_tyres = nullptr;
    other.m_brand = "";
    other.m_model = "";
    other.m_odometer = 0;

#ifdef DEBUG
    std::cout << "move Auto\n";
#endif
}

Auto::~Auto()
{
    if(this->m_motor != nullptr) {
        delete this->m_motor;
        this->m_motor = nullptr;

#ifdef DEBUG
        std::cout << "\nMotor from{" << m_brand << ' ' << m_model << "} is deleted correctly\n";
#endif
    }

    if(this->m_gearbox != nullptr) {
        delete this->m_gearbox;
        this->m_gearbox = nullptr;

#ifdef DEBUG
        std::cout << "\nGearbox from{" << m_brand << ' ' << m_model << "} is deleted correctly\n";
#endif
    }

    if(this->m_rims != nullptr) {
        delete this->m_rims;
        this->m_rims = nullptr;

#ifdef DEBUG
        std::cout << "\nGearbox from{" << m_brand << ' ' << m_model << "} is deleted correctly\n";
#endif
    }

    if(this->m_tyres != nullptr) {
        delete this->m_tyres;
        this->m_tyres = nullptr;

#ifdef DEBUG
        std::cout << "\nGearbox from{" << m_brand << ' ' << m_model << "} is deleted correctly\n";
#endif
    }
    --s_autoCount;

    std::cout << "Auto{" << m_brand << ' ' << m_model << "} destroyed\n";
}

const Auto& Auto::operator=(const Auto& right)
{
    if (this != &right)
    {
        this->setBrand(right.m_brand);

        this->setModel(right.m_model);

        this->setOdometer(right.m_odometer);
        
        this->setMotor(*right.m_motor);

        this->setGearbox(*right.m_gearbox);

        this->setRims(*right.m_rims);
        
        this->setTyres(*right.m_tyres);

        ++s_autoCount;
        
    }

    return *this; // позволяет последовательное присваивание a=b=c
}

Auto &Auto::operator=(Auto &&right) {
    if(&right == this)
        return *this;
    
    m_motor = right.m_motor;
    right.m_motor = nullptr;

    m_gearbox = right.m_gearbox;
    right.m_gearbox = nullptr;

    m_rims = right.m_rims;
    right.m_rims = nullptr;

    m_tyres = right.m_tyres;
    right.m_tyres = nullptr;

    m_brand = right.m_brand;
    right.m_brand = "";

    m_model = right.m_model;
    right.m_model = "";

    m_odometer = right.m_odometer;
    right.m_odometer = 0;

    return *this;
}

/// <геттеры>

std::string Auto::getBrand() const
{
    return this->m_brand;
}

std::string Auto::getModel() const
{
    return this->m_model;
}

Motor Auto::getMotor() const
{    
    return Motor{*this->m_motor};
}

Gearbox Auto::getGearbox() const
{
    return Gearbox{*this->m_gearbox};
}

Tyres Auto::getTyres() const
{
    return Tyres{*this->m_tyres};
}

Rims Auto::getRims() const
{
    return Rims{*m_rims};
}

double Auto::getOdometer() const
{
    return this->m_odometer;
}

const size_t Auto::getObjectCount() {
    return s_autoCount;
}

/// <сеттеры>

void Auto::setBrand(const std::string& brand)
{
    this->m_brand = brand;
}

void Auto::setModel(const std::string& model)
{
    this->m_model = model;
}

void Auto::setOdometer(const double odometer) {
    if(odometer >= 0) {
        this->m_odometer = odometer;
    } else {
        std::cout << "Invalid value odometer = 100 km\n";
        this->m_odometer = 100.00;
    }
}

void Auto::setMotor(const Motor & motor)
{    
    if(this->m_motor != nullptr) {
        delete this->m_motor;
        this->m_motor = nullptr;
    }

    this->m_motor = new Motor{motor};
        
}

void Auto::setMotor(const char * mark,
    const double volume)
{    
    if(this->m_motor != nullptr) {
        delete this->m_motor;
        this->m_motor = nullptr;
    }

    this->m_motor = new Motor{mark, volume};
}

void Auto::setGearbox(const Gearbox& gearbox)
{
    if(this->m_gearbox != nullptr) {
        delete this->m_gearbox;
        this->m_gearbox = nullptr;
    }
    this->m_gearbox = new Gearbox{gearbox};
}

void Auto::setGearbox(const char * mark,
    unsigned short gearCount)
{
    if(this->m_gearbox != nullptr) {
        delete this->m_gearbox;
        this->m_gearbox = nullptr;
    }
    this->m_gearbox = new Gearbox{mark, gearCount};
}

void Auto::setTyres(const Tyres& tyres)
{
    if(m_tyres != nullptr) {
        delete m_tyres;
        m_tyres = nullptr;
    }
    m_tyres = new Tyres{tyres};
}

void Auto::setTyres(const char* mark,
    const unsigned short width,
    const unsigned short height,
    const unsigned short radius)
{
    if(m_tyres != nullptr) {
        delete m_tyres;
        m_tyres = nullptr;
    }
    m_tyres = new Tyres{mark, width, height, radius};
}

void Auto::setRims(const Rims& rims)
{
    if(this->m_rims != nullptr) {
        delete this->m_rims;
        this->m_rims = nullptr;
    }

    this->m_rims = new Rims{rims};
}

void Auto::setRims(const char * mark,
    const unsigned short width,
    const unsigned short height,
    const unsigned short radius)
{
    if(m_rims != nullptr) {
        delete m_rims;
        m_rims = nullptr;
    }

    m_rims = new Rims{mark, width, height, radius};
}

void Auto::turnOn()
{
    m_motor->startEngine();
}

void Auto::turnOff()
{
    m_motor->offEngine();
}

void Auto::gearUp()
{
    m_gearbox->shiftUp();
}

void Auto::gearDown()
{
    m_gearbox->shiftDown();
}

int Auto::startMoving(const double driveKM)
{
    // пробег одной поездки нужен для водительского опыта
    int kms{ 0 };
    if (m_motor->getWork())
    {

        while (kms <= driveKM)
        {

            gearUp();
            if (m_gearbox->getGearPos() == 2)
                std::cout << "Auto start moving\n";

            if (m_gearbox->getGearPos() == m_gearbox->getGearCount())
                m_rims->spinWheels(false);
            else
                m_rims->spinWheels(true);

            // увеличиваю пробег авто
            m_odometer += 1.0;
            ++kms;
        }
    }
    else
    {
        std::cout << "Your motor is off!!!\n";
    }

    return kms;
}

void Auto::stopMoving()
{
    m_gearbox->printGear();

    while (m_gearbox->getGearPos() > 1)
    {
        std::cout << "Auto slowing\n";
        gearDown();
        Sleep(10);
    }

    std::cout << "Auto is stopped\n";
}