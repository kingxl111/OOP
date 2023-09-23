#include <iostream>
#include "octal.h"

using std::cin;
using std::cout;
using std::endl;

Octal::Octal() : _size(0), _array{nullptr} {};

Octal::Octal(const size_t & n, unsigned char t = 0) {
    _array = new unsigned char[n];
    for(int i = 0; i < n; ++i) {
        _array[i] = t;
    }
    _size = n;
}

Octal::Octal(const std::initializer_list< unsigned char> &t) {
    _array = new unsigned char[t.size()];
    size_t i{0};
    for (auto c : t)
        _array[i++] = c;
    _size = t.size();
}

Octal::Octal(const std::string &t) {
    _array = new unsigned char[t.size()];
    _size  = t.size();

    for(size_t i{0}; i<_size; ++i) {
        _array[i] = t[i];
    }
}

Octal::Octal(const Octal& other) {
    _size = other._size;
    _array = new unsigned char[_size];

    for(size_t i{0};i<_size;++i) _array[i] = other._array[i];

}

Octal::Octal(Octal&& other) noexcept {
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}      

Octal::Octal add(const Octal& other) {

}

Octal::Octal subtract(const Octal& other) {

}

bool Octal::equals(const Octal& other) const {
    if(this->_size == other._size) {
        for(int i = 0; i < _size; ++i) {
            if (this->_array[i] != other._array[i]) {
                return false;
            }
        }
        return true;
    } 
    return false;
}

bool  Octal::greater(const Octal& other) const {
    if(this->_size > other._size) {
        return true;
    } 
    else if(this->_size < other._size) {
        return false;
    }
    else { // equal size
        for(int i = 0; i < this->_size; ++i) {
            if(this->_array[i] > other._array[i]) {
                return true;
            } 
            else if (this->_array[i] < other._array[i]) {
                return false;
            }
        }
        return false;
    }
}

bool  Octal::less(const Octal& other) const {
    if(this->_size < other._size) {
        return true;
    } 
    else if(this->_size > other._size) {
        return false;
    }
    else { // equal size
        for(int i = 0; i < this->_size; ++i) {
            if(this->_array[i] < other._array[i]) {
                return true;
            } 
            else if (this->_array[i] > other._array[i]) {
                return false;
            }
        }
        return false;
    }
}
   

std::ostream& print(std::ostream& os) {

}

Octal::~Octal() noexcept {
    if (_size > 0) {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}