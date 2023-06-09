#include "byte.h"
#include<iostream>

// Default constructor
byte::byte() : value(0) {}

// Parameterized constructor
byte::byte(unsigned char n) : value(n) {}

// Overloaded assignment operator
byte byte::operator=(const byte& rhs) {
    value = rhs.value;
    return *this;
}

// Overloaded assignment operator with unsigned char
byte* byte::operator=(unsigned char uc) {
    byte* newByte = new byte(uc);
    return newByte;
}

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

// Overloaded subtraction operator
byte operator-(const byte& a, const byte& b) {
    return byte(a.value - b.value);
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