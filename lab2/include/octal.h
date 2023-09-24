#pragma once

#include <iostream>

class Octal {

public:
   Octal();
   Octal(const size_t & n, unsigned char t = 0);
   Octal(const std::initializer_list< unsigned char> &t);
   Octal(const std::string &t);
   Octal(const Octal& other);
   Octal(Octal&& other) noexcept;      

   Octal add(const Octal& other);
   Octal subtract(const Octal& other);
   bool  equals(const Octal& other) const;
   bool  greater(const Octal& other) const;
   bool  less(const Octal& other) const;
   
   void print();
   std::ostream& print(std::ostream& os);

   virtual ~Octal() noexcept;

private:
    unsigned char *_array;
    size_t _size;
};