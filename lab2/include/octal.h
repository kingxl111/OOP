#pragma once

#include <iostream>

class Octal {

public:
    Octal() noexcept;
    Octal(const size_t & n, unsigned char t = 0);
    Octal(const std::initializer_list< unsigned char> &t);
    Octal(const std::string &t);
    Octal(const Octal& other);
    Octal(Octal&& other) noexcept; 

    Octal add( Octal& other);
    Octal subtract( Octal& other);

    bool  equals(const Octal& other) const;
    bool  greater(const Octal& other) const;
    bool  less(const Octal& other) const;
   
    int get_size();
    unsigned char* get_array(); 

    void print();
    std::ostream& print(std::ostream& os);  
    virtual ~Octal() noexcept;

private:
    unsigned char *_array;
    size_t _size;

    bool _is_positive;
    bool _is_negative;
    
    void add_intern(Octal& other, Octal& result);
    void subtract_intern(Octal& other, Octal& result);

};


Octal operator+(Octal& l, Octal& r);
Octal operator-(Octal& l, Octal& r);
bool operator==(Octal& l, const Octal& r); 
bool operator<(Octal& l, const Octal& r);
bool operator>(Octal& l, const Octal& r);