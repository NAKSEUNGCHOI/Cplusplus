#include <iostream>
#include <cstring>
#include "Mystring.h"

// no-args constructor; being called like Mystring a;
Mystring::Mystring()
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor; being called like Mystring a {"Hello"};
Mystring::Mystring(const char *s)
    : str {nullptr} {
    if(s == nullptr){
        str = new char[1];
        *str = '\0';
    }else{
        str = new char[std::strlen(s)+1]; // +1 for null terminator '/0'
        std::strcpy(str, s);
    }
}
// Copy constructor; being called Mystring a {"Hello"}; Mystring b {a};
Mystring::Mystring(const Mystring &source)
    : str{nullptr}{
    str = new char[std::strlen(source.str)+1];
    std::strcpy(str, source.str);
}
// move constructor
Mystring::Mystring(Mystring &&source)
    : str{source.str} {
    source.str = nullptr;
    std::cout << "Move constructor used" << std::endl;

}
// destructor
Mystring::~Mystring(){
    if(str == nullptr){
        std::cout << "Calling destructor for Mystring : nullptr " << std::endl;
    }else{
        std::cout << "Calling descutor for Mystring : " << str << std::endl;
    }
    delete [] str;
}

// copy assignment (different from copy constructor)
Mystring &Mystring::operator=(const Mystring &rhs){
    std::cout << "Copy assignment" << std::endl;
    if(this == &rhs){ // this is pointer to the current object
        return *this;
    }
    delete [] this->str;
    str = new char[strlen(rhs.str)+1];
    std::strcpy(this->str, rhs.str);
    return *this;
}

// move assignment
Mystring &Mystring::operator=(Mystring &&rhs){
    std::cout << "Move assignment" << std::endl;
    if(this == &rhs){
        return *this;
    }
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Equality
bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcpy(str, rhs.str) == 0);
}

Mystring Mystring::operator-() const{
    char *buff = new char[std::strlen(str)+1];
    std::strcpy(buff, str);
    for(size_t i = 0; i < std::strlen(buff); i++){
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// Concatenate
Mystring Mystring::operator+(const Mystring &rhs) const{
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// Display method
void Mystring::display() const{
    std::cout << str << ": " << get_length() << std::endl;
}
// Length getter
int Mystring::get_length() const{
    return std::strlen(str);
}

//string getter
const char *Mystring::get_str() const {
    return str;
}