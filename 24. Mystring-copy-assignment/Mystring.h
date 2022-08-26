#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>

class Mystring{
    private:
        char *str;
    public:
        Mystring();                                     // No-args constructor
        Mystring(const char *s);                        // overloaded constructor
        Mystring(const Mystring &source);               // copy constructor
        ~Mystring();                                    // destructor

        
        Mystring &operator=(const Mystring &rhs);       // copy assignment

        void display() const;

        int get_length() const;
        const char *get_str() const;


};  

#endif // _MYSTRING_H_