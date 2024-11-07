#include "Rims.h"

Rims::Rims() {
    this->setBrand("Rims");
    this->setRadius(14);
    this->setWidth(160);
    this->setHeight(50);

    std::cout << "Rims constructed\n";
}

Rims::Rims(const char *brand,
           unsigned short width,
           unsigned short height,
           unsigned short radius)
    :m_brand{nullptr}
{
    this->setBrand(brand);
    this->setRadius(radius);
    this->setWidth(width);
    this->setHeight(height);

    std::cout << "Rims constructed\n";
}

// пример инициализирующего конструктора
Rims::Rims(const Rims &other)
    :m_width{other.m_width},
    m_height{other.m_height},
    m_radius{other.m_radius}
{
    setBrand(other.m_brand);

}

 Rims::Rims(Rims &&other) noexcept {
    
     
     this->m_brand = other.m_brand;
    this->m_width = other.m_width;
    this->m_height = other.m_height;
    this->m_radius = other.m_radius;

    other.m_brand = nullptr;
    other.m_width = 0;
    other.m_height = 0;
    other.m_radius = 0;

    std::cout << "move Rims\n";
}

Rims::~Rims() {
    if(this->m_brand != nullptr) {
        delete[]this->m_brand;
        this->m_brand = nullptr;
    }

    std::cout << "Rims destroyed\n";
}

const Rims &Rims::operator=(const Rims &right) {
    if(this != &right) {
        setBrand(right.m_brand);

        this->m_width = right.m_width;
        this->m_height = right.m_height;
        this->m_radius = right.m_radius;
    }

    return *this;
}

Rims &Rims::operator=(Rims &&right) {
    if(this == &right)
        return *this;

    if(this->m_brand!=nullptr)
    delete[] this->m_brand;
     
    this->m_brand = right.m_brand;
    this->m_width = right.m_width;
    this->m_height = right.m_height;
    this->m_radius = right.m_radius;

    right.m_brand = nullptr;
    right.m_width = 0;
    right.m_height = 0;
    right.m_radius = 0;
    
    std::cout << "move = Rims\n";

    return *this;
}

// Геттеры
const char * Rims::getBrand() const {
    return this->m_brand;
}

unsigned short Rims::getWidth() const {
    return this->m_width;
}

unsigned short Rims::getHeight() const {
    return this->m_height;
}

unsigned short Rims::getRadius() const {
    return this->m_radius;
}

// сеттеры
void Rims::setBrand(const char *brand) {
    
    if(this->m_brand != nullptr) {
        delete[] this->m_brand;
        this->m_brand = nullptr;
    }

    int length = std::strlen(brand) + 1;
    this->m_brand = new char[length];
    strcpy_s(this->m_brand, length, brand);
}

void Rims::setWidth(const unsigned short width) {
    if(width >= 160 && width < 450)
        this->m_width = width;
    else {
        std::cout << "unacceptable value! using standard width = 160\n";
        this->m_width = 160;
    }
}

void Rims::setHeight(const unsigned short height) {
    if(height >= 20 && height <= 200)
        this->m_height = height;
    else {
        std::cout << "unacceptable value! using standard height = 60\n";
        this->m_height = 60;
    }
}

void Rims::setRadius(const unsigned short radius) {
    if(radius > 13 && radius < 30)
        this->m_radius = radius;
    else {
        std::cout << "unacceptable value! using standard width = 13\n";
        this->m_radius = 13;
    }
}

void Rims::spinWheels(bool maxSpeed) {
    std::cout << "Wheels spinning.\n";
    if(maxSpeed)
        for(int i{0}; i < 3; ++i) {
            std::cout << "faster\n";
            // Sleep(10);
        }
}


//операторы спавнения
bool Rims::operator==(const Rims &right) const {
    if(this->m_width == right.m_width &&
       this->m_height == right.m_height &&
       this->m_radius == right.m_radius)
        return true;

    return false;
}
bool Rims::operator!=(const Rims &right) const {
    return !(*this == right);
}

bool Rims::operator>(const Rims &right) const {
    if(this->m_width > right.m_width ||
       this->m_height > right.m_height ||
       this->m_radius > right.m_radius)
        return true;

    return false;
}
bool Rims::operator<(const Rims &right) const {
    return !(*this > right);
}

std::string Rims::toString()const {
    std::string str{"Brand ["};
    str += this->m_brand;
    str += "] size [";
    str += std::to_string(this->m_width);
    str += 'x';
    str += std::to_string(this->m_height);
    str += " radius ";
    str += std::to_string(this->m_radius);
    str += ']';
    return str;
}

Rims::operator std::string()const {

    return toString();
}