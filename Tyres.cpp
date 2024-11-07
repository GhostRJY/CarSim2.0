#include "Tyres.h"

Tyres::Tyres()
{
    this->setBrand("Tyres");
    this->setRadius(14);
    this->setWidth(160);
    this->setHeight(50);

    std::cout << "Tyres constructed\n";
}

Tyres::Tyres(const char* brand,
    unsigned short width,
    unsigned short height,
    unsigned short radius)
    : m_brand{ nullptr }
{
    this->setBrand(brand);
    this->setRadius(radius);
    this->setWidth(width);
    this->setHeight(height);

    std::cout << "Tyres constructed\n";
}

Tyres::Tyres(const Tyres& other)
{
    this->setBrand(other.m_brand);
    this->m_width = other.m_width;
    this->m_height = other.m_height;
    this->m_radius = other.m_radius;
}

Tyres& Tyres::operator=(const Tyres& right)
{
    if (this != &right)
    {
        this->setBrand(right.m_brand);
        this->setRadius(right.m_radius);
        this->setWidth(right.m_width);
        this->setHeight(right.m_height);
    }
    return *this;
}

Tyres::~Tyres()
{
    if (this->m_brand != nullptr)
    {
        delete[] this->m_brand;
        this->m_brand = nullptr;
    }
    std::cout << "Tyres destroyed\n";
}

const char* Tyres::getBrand() const
{
    return this->m_brand;
}

unsigned short Tyres::getWidth() const
{
    return this->m_width;
}

unsigned short Tyres::getHeight() const
{
    return this->m_height;
}

unsigned short Tyres::getRadius() const
{
    return this->m_radius;
}

void Tyres::setBrand(const char* brand)
{
    if (this->m_brand != nullptr)
    {
        delete[] this->m_brand;
        this->m_brand = nullptr;
    }

    int length = std::strlen(brand) + 1;
    this->m_brand = new char[length];
    strcpy_s(this->m_brand, length, brand);
}

void Tyres::setWidth(const unsigned short width)
{
    if (width >= 160 && width < 450)
        this->m_width = width;
    else
    {
        std::cout << "unacceptable value! using standard width = 160\n";
        this->m_width = 160;
    }
}

void Tyres::setHeight(const unsigned short height)
{
    if (height >= 20 && height <= 200)
        this->m_height = height;
    else
    {
        std::cout << "unacceptable value! using standard height = 60\n";
        this->m_height = 60;
    }
}

void Tyres::setRadius(const unsigned short radius)
{
    if (radius > 13 && radius < 30)
        this->m_radius = radius;
    else
    {
        std::cout << "unacceptable value! using standard width = 13\n";
        this->m_radius = 13;
    }
}

//операторы спавнения
bool Tyres::operator==(const Tyres &right) const {
    if(this->m_width == right.m_width &&
       this->m_height == right.m_height &&
       this->m_radius == right.m_radius)
        return true;

    return false;
}
bool Tyres::operator!=(const Tyres &right) const {
    return !(*this == right);
}

bool Tyres::operator>(const Tyres &right) const {
    if(this->m_width > right.m_width ||
       this->m_height > right.m_height ||
       this->m_radius > right.m_radius)
        return true;

    return false;
}
bool Tyres::operator<(const Tyres &right) const {
    return !(*this>right);
}

std::string Tyres::toString()const {
    std::string str{"Brand ["};
    str += this->m_brand;
    str += "] size [";
    str +=std::to_string(this->m_width);
    str += 'x';
    str += std::to_string(this->m_height);
    str += " radius ";
    str += std::to_string(this->m_radius);
    str += ']';
    return str;
}

Tyres::operator std::string()const {
    
    return toString();
}