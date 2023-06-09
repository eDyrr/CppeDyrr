#ifndef BYTE_H
#pragma once 
#include<iostream>
class byte
{
    private : 
    unsigned char value ; 

    public : 
    byte() ;
    byte(unsigned char n) ;
    byte operator = (const byte &rhs) ;
    byte* operator = (unsigned char uc) ;
    bool operator == (const byte &b) ;
    bool operator > (const byte &b) ; 
    bool operator >= (const byte &b) ; 
    bool operator < (const byte &b) ; 
    bool operator <= (const byte &b) ; 
    bool operator != (const byte &b) ;  
    friend byte operator + (const byte &a, const byte &b) ;
    byte& operator ++ () ; 
    byte operator ++ (int) ; 
    friend byte operator - (const byte &a, const byte &b) ; 
    byte& operator --() ; 
    byte operator --(int) ; 
    byte& operator += (unsigned char uc) ;
    byte& operator += (const byte &b) ; 
    byte& operator -= (unsigned char uc) ;
    byte& operator -= (const byte &b) ;
    friend byte operator * (const byte &a, const byte &b) ;
    byte& operator *= (unsigned char uc) ;
    byte& operator *= (const byte &b) ;
    friend byte operator / (const byte &a, const byte &b) ;
    byte& operator /= (unsigned char uc) ;
    byte& operator /= (const byte &b) ;
    friend byte operator % (const byte& a, const byte &b) ;
    byte& operator %= (const byte &b) ; 
    byte& operator %= (unsigned char uc) ; 
    friend std::istream& operator >> (std::istream& is, byte &b) ;
    friend std::ostream& operator << (std::ostream& os, const byte& b) ;
};
#endif // !BYTE_H