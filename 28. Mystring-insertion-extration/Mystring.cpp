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

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs){
    os << rhs.str;
    return os;
}
std::istream &operator>>(std::istream &in, Mystring &rhs){
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring {buff};
    delete [] buff;
    return in;
}