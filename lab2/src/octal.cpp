#include "octal.h"

using std::cin;
using std::cout;
using std::endl;

Octal::Octal() {
    this->_size = 0;
    this->_array = nullptr;
} 

Octal::Octal(const size_t & n, unsigned char t) {
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

Octal Octal::add(const Octal& other) {
    Octal result(1, '1'); // чзх
    if(this->_size > other._size) {
        result._array = new unsigned char[this->_size + 1];
        result._size = this->_size + 1;
        int iter1 = this->_size - 1;
        int iter2 = other._size - 1;
        int rem = 0; 

        while(iter2 >= 0) {
            
            int d1 = this->_array[iter1] - '0';
            int d2 = other._array[iter2] - '0';
            int d3 = (d1 + d2 + rem) % 8;
            rem = (d1 + d2 + rem) / 8;

            result._array[iter1 + 1] = (unsigned char)(d3 + '0');

            --iter1;
            --iter2;
        }
        while(iter1 >= 0) {
            int d1 = this->_array[iter1] - '0';
            int d3 = (d1 + rem) % 8;
            rem = (d1 + rem) / 8;

            result._array[iter1 + 1] = (unsigned char)(d3 + '0');

            --iter1;
        }
        result._array[0] = (unsigned char)(rem + '0'); 
    }
    else if(this->_size < other._size) {
        result._array = new unsigned char[other._size + 1];
        result._size = other._size + 1;
        int iter1 = this->_size - 1;
        int iter2 = other._size - 1;
        int rem = 0; 
        while(iter1 >= 0) {
            
            int d1 = this->_array[iter1] - '0';
            int d2 = other._array[iter2] - '0';
            int d3 = (d1 + d2 + rem) % 8;
            rem = (d1 + d2 + rem) / 8;

            result._array[iter2 + 1] = (unsigned char)(d3 + '0');
            
            --iter1;
            --iter2;
        }
        while(iter2 >= 0) {
            int d2 = other._array[iter2] - '0';
            int d3 = (d2 + rem) % 8;
            rem = (d2 + rem) / 8;

            result._array[iter2 + 1] = (unsigned char)(d3 + '0');

            --iter2;
        }
        result._array[0] = (unsigned char)(rem + '0'); 
    }
    else {
        result._array = new unsigned char[this->_size + 1];
        result._size = this->_size + 1;
        int iter1 = this->_size - 1;
        int iter2 = other._size - 1;
        int rem = 0; 
        while(iter2 >= 0) {
            
            int d1 = this->_array[iter1] - '0';
            int d2 = other._array[iter2] - '0';
            int d3 = (d1 + d2 + rem) % 8;
            rem = (d1 + d2 + rem) / 8;

            result._array[iter1 + 1] = (unsigned char)(d3 + '0');
            
            --iter1;
            --iter2;
        }
        result._array[0] = (unsigned char)(rem + '0'); 
    }
    return result;
}

// Octal Octal::subtract(const Octal& other) {

// }

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
   
void Octal::print() {
    if (this->_size <= 0) {
        return;
    }
    int i = 0;
    if(this->_array[0] == '0') {
        i = 1;
    }
    for(; i < this->_size; ++i) {
        cout << this->_array[i];
    } cout << endl;
}

// std::ostream& print(std::ostream& os) {

// }

Octal::~Octal() noexcept {
    if (_size > 0) {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}