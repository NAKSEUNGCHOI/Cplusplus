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
// destructor
Mystring::~Mystring(){
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