#include "byte.h"
#include<iostream>

// Default constructor
byte::byte() : value(0) {}

// Parameterized constructor
byte::byte(unsigned char n) : value(n) {}

// Overloaded assignment operator
byte byte::operator=(const byte& rhs) {
    value = rhs.value;
    return *this ;
}

// Overloaded assignment operator with unsigned char
byte& byte::operator=(unsigned char uc) {
    value = uc ; 
    return *this ;
}

bool byte::operator==(const byte &b) { return value == b.value ; }

bool byte::operator > (const byte &b) { return value > b.value ; }

bool byte::operator >= (const byte &b) { return value >= b.value ; }

bool byte::operator < (const byte &b) { return value < b.value ; }

bool byte::operator <= (const byte &b) { return value <= b.value ; }

bool byte::operator != (const byte &b) { return value != b.value ; }

// Overloaded pre-increment operator
byte& byte::operator++() {
    ++value;
    return *this;
}

// Overloaded post-increment operator
byte byte::operator++(int) {
    byte temp = *this;
    ++value;
    return temp;
}

// Overloaded pre-decrement operator
byte& byte::operator--() {
    --value;
    return *this;
}

// Overloaded post-decrement operator
byte byte::operator--(int) {
    byte temp = *this;
    --value;
    return temp;
}

// Overloaded addition operator
byte operator+(const byte& a, const byte& b) {
    return byte(a.value + b.value);
}
byte operator + (const byte& a, const unsigned char uc) 
{
    return byte(a.value + uc ) ; 
}

// Overloaded subtraction operator
byte operator-(const byte& a, const byte& b) {
    return byte(a.value - b.value);
}
byte operator - (const byte& a, const unsigned char uc) 
{
    return a.value - uc ; 
}
// Overloaded addition-assignment operator with unsigned char
byte& byte::operator+=(unsigned char uc) {
    value += uc;
    return *this;
}

// Overloaded addition-assignment operator with byte
byte& byte::operator+=(const byte& b) {
    value += b.value;
    return *this;
}

// Overloaded subtraction-assignment operator with unsigned char
byte& byte::operator-=(unsigned char uc) {
    value -= uc;
    return *this;
}

// Overloaded subtraction-assignment operator with byte
byte& byte::operator-=(const byte& b) {
    value -= b.value;
    return *this;
}

byte operator * (const byte &a, const byte &b)
{
    return byte(a.value * b.value ) ; 
}

byte operator * (const byte &b, const unsigned char uc) 
{
    return byte(b.value * uc) ; 
}

byte operator / (const byte &b, const unsigned char uc) 
{
    return byte(b.value / uc) ; 
}

byte operator % (const byte& a, const byte& b)
{
    return byte(a.value % b.value) ; 
}

byte& byte::operator %= (const byte& b) 
{
    value %= b.value ; 
    return *this ; 
}

byte& byte::operator %= (unsigned char uc)
{
    value %= uc ; 
    return *this ; 
}
// Other overloaded operators...

// Overloaded input stream operator
std::istream& operator>>(std::istream& is, byte& b) {
    std::cout << "Enter uc: ";
    std::string line;
    std::getline(is, line);
    if (!line.empty())
        b.value = static_cast<unsigned char>(std::stoul(line));
    return is;
}

// Overloaded output stream operator
std::ostream& operator<<(std::ostream& os, const byte& b) {
    os << static_cast<unsigned int>(b.value);
    return os;
}
