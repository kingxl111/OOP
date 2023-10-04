#include "octal.h"

using std::cin;
using std::cout;
using std::endl;

Octal::Octal() {
    this->_size = 0;
    this->_array = nullptr;
    this->_is_negative = false;
    this->_is_positive = false;
} 

Octal::Octal(const size_t & n, unsigned char t) {
    _array = new unsigned char[n];
    for(int i = 0; i < n; ++i) {
        _array[i] = t;
    }
    _size = n; 
    _is_positive = true;
    _is_negative = false;
}

Octal::Octal(const std::initializer_list< unsigned char> &t) {
    _array = new unsigned char[t.size()];
    size_t i{0};
    for (auto c : t){
        if((c < '0') || (c > '8')) {
            throw std::logic_error("constructor: invalid format of number!");
        }
        _array[i++] = c;
    }
    _size = t.size();

    if(_array[0] == '-') {
        _is_negative = true;
        _is_positive = false;
        _array = (_array + 1); //moving the pointer to skip minus
        --_size;
    } 
    else {
        _is_negative = false;
        _is_positive = true;
    }
}

Octal::Octal(const std::string &t) {
    if(t.size() > 0) {
        
        if(t[0] == '-') {

            int pre_zero_counter = 0;
            for(size_t i{1}; i < t.size() - 1; ++i) {
                if(t[i] != '0') {
                    break;
                } 
                ++pre_zero_counter;
            }

            _array = new unsigned char[t.size() - 1 - pre_zero_counter];
            _size  = t.size() - 1 - pre_zero_counter;

            for(size_t i{0}; i < t.size() - 1 - pre_zero_counter; ++i) {
                if((t[i + 1 + pre_zero_counter] < '0') || (t[i + 1 + pre_zero_counter] > '8')) {
                    throw std::logic_error("constructor: invalid format of number!");
                }
                _array[i] = t[i + 1 + pre_zero_counter];
            }
            _is_negative = true;
            _is_positive = false;
        } 
        else  {
            int pre_zero_counter = 0;
            for(size_t i{0}; i < t.size() - 1; ++i) {
                if(t[i] != '0') {
                    break;
                } 
                ++pre_zero_counter;
            }
            _array = new unsigned char[t.size() - pre_zero_counter];
            _size  = t.size() - pre_zero_counter;

            for(size_t i{0}; i < t.size() - pre_zero_counter; ++i) {
                if((t[i + pre_zero_counter] < '0') || (t[i + pre_zero_counter] > '8')) {
                    throw std::logic_error("constructor: invalid format of number!");
                }
                _array[i] = t[i + pre_zero_counter];
            }
            _is_negative = false;
            _is_positive = true;
        }
    } 
    else {
        throw std::logic_error("constructor: invalid number!");
    }
}

Octal::Octal(const Octal& other) {
    _size = other._size;
    _array = new unsigned char[_size];
    _is_negative = other._is_negative;
    _is_positive = other._is_positive;
    for(size_t i{0};i<_size;++i) _array[i] = other._array[i];

}

Octal::Octal(Octal&& other) noexcept {
    _size = other._size;
    _array = other._array;
    _is_negative = other._is_negative;
    _is_positive = other._is_positive;
    other._size = 0;
    other._array = nullptr;
}      

Octal Octal::add(Octal& other) {
    Octal result; // init
    if(this->_is_positive && other._is_positive) {
        add_intern(other, result);
        result._is_negative = false;
        result._is_positive = true;
    } 
    else if (this->_is_negative && other._is_negative) {
        add_intern(other, result);
        result._is_positive = false;
        result._is_negative = true;
    }
    else if (this->_is_negative && other._is_positive)  {
        if(this->_size > other._size){
            subtract_intern(other, result);
            result._is_positive = false;
            result._is_negative = true;
        }
        else if(this->_size < other._size) {
            other.subtract_intern(*this, result);
            result._is_negative = false;
            result._is_positive = true;
        }

        else if (this->_size == other._size) { // for abs comparing
            this->_is_negative = false;
            this->_is_positive = true;
            if(this->greater(other)){
                subtract_intern(other, result);
                result._is_negative = true;
                result._is_positive = false;
            }
            else if(this->less(other)) {
                other.subtract_intern(*this, result);
                cout << "ar: "<< result._array << endl;
                result._is_negative = false;
                result._is_positive = true;
            }
            else {
                result._array = new unsigned char[1];
                result._array[0] = '0';
                result._size = 1;
            }
            this->_is_negative = true;
            this->_is_positive = false;
        }
    } 
    else if (this->_is_positive && other._is_negative) {
        if(this->_size > other._size){
            subtract_intern(other, result);
            result._is_positive = true;
            result._is_negative = false;
        }
        else if(this->_size < other._size) {
            other.subtract_intern(*this, result);
            result._is_negative = true;
            result._is_positive = false;
        }
        else if (this->_size == other._size) {
            other._is_negative = false;
            other._is_positive = true;
            if(this->greater(other)){
                subtract_intern(other, result);
                result._is_negative = false;
                result._is_positive = true;
            }
            else if(this->less(other)) {
                other.subtract_intern(*this, result);
                result._is_negative = true;
                result._is_positive = false;
            }
            else {
                result._array = new unsigned char[1];
                result._array[0] = '0';
                result._size = 1;
            }
            other._is_negative = true;
            other._is_positive = false;
        }
    }
    return result;
}



void Octal::add_intern(Octal& other, Octal& result) {
    if(this->_size > other._size) {
        result._array = new unsigned char[this->_size + 1];
        result._size = this->_size + 1;
        int iter1 = this->_size - 1;
        int iter2 = other._size - 1;
        int rem = 0; 

        while(iter2 >= 0) {
            
            int digit1 = this->_array[iter1] - '0';
            int digit2 = other._array[iter2] - '0';
            int digit3 = (digit1 + digit2 + rem) % 8;
            rem = (digit1 + digit2 + rem) / 8;

            result._array[iter1 + 1] = (unsigned char)(digit3 + '0');

            --iter1;
            --iter2;
        }
        while(iter1 >= 0) {
            int digit1 = this->_array[iter1] - '0';
            int digit3 = (digit1 + rem) % 8;
            rem = (digit1 + rem) / 8;

            result._array[iter1 + 1] = (unsigned char)(digit3 + '0');

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
            
            int digit1 = this->_array[iter1] - '0';
            int digit2 = other._array[iter2] - '0';
            int digit3 = (digit1 + digit2 + rem) % 8;
            rem = (digit1 + digit2 + rem) / 8;

            result._array[iter2 + 1] = (unsigned char)(digit3 + '0');
            
            --iter1;
            --iter2;
        }
        while(iter2 >= 0) {
            int digit2 = other._array[iter2] - '0';
            int digit3 = (digit2 + rem) % 8;
            rem = (digit2 + rem) / 8;

            result._array[iter2 + 1] = (unsigned char)(digit3 + '0');

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
            
            int digit1 = this->_array[iter1] - '0';
            int digit2 = other._array[iter2] - '0';
            int digit3 = (digit1 + digit2 + rem) % 8;
            rem = (digit1 + digit2 + rem) / 8;

            result._array[iter1 + 1] = (unsigned char)(digit3 + '0');
            
            --iter1;
            --iter2;
        }
        result._array[0] = (unsigned char)(rem + '0'); 
    }
}

Octal Octal::subtract(Octal& other) {
    Octal result;
    
    if(this->_is_positive && other._is_positive) {
        if(this->greater(other)) {
            subtract_intern(other, result);
            result._is_negative = false;
            result._is_positive = true;
        } 
        else if (this->less(other)) {
            other.subtract_intern(*this, result);
            result._is_negative = true;
            result._is_positive = false;
        } 
        else { //for zero
            result._is_negative = false;
            result._is_positive = true;
            result._array = new unsigned char[1];
            result._array[0] = '0';
            result._size = 1;
        }
    }
    else if(this->_is_positive && other._is_negative) {
        add_intern(other, result);
        result._is_negative = false;
        result._is_positive = true;
    }
    else if (this->_is_negative && other._is_negative) {
        if(this->greater(other)) {
            other.subtract_intern(*this, result);
            result._is_negative = false;
            result._is_positive = true;
        } 
        else if (this->less(other)) {
            subtract_intern(other, result);
            result._is_negative = true;
            result._is_positive = false;
        } 
        else {
            result._is_negative = false;
            result._is_positive = true;
            result._array = new unsigned char[1];
            result._array[0] = '0';
            result._size = 1;
        }
    } 
    else if (this->_is_negative && other._is_positive) {
        add_intern(other, result);
        result._is_negative = true;
        result._is_positive = false;
    }

    return result;
}

void Octal::subtract_intern( Octal& other, Octal& result) {
    if(this->_size > other._size) {
        result._array = new unsigned char[this->_size];
        result._size = this->_size;
        int iter1 = this->_size - 1;
        int iter2 = other._size - 1;
        int rem = 0; 

        while(iter2 >= 0) {
            
            int digit1 = this->_array[iter1] - '0';
            int digit2 = other._array[iter2] - '0';
            if(digit1 - rem < digit2) {
                digit1 = digit1 + 8 - rem;
                rem = 1;
            } 
            else {
                digit1 = digit1 - rem;
                rem = 0;
            }
            int digit3 = digit1 - digit2;

            result._array[iter1] = (unsigned char)(digit3 + '0');

            --iter1;
            --iter2;
        }
        while(iter1 >= 0) {
            int digit1 = this->_array[iter1] - '0';
            int digit3;
            if(digit1 - rem < 0) {
                digit1 = digit1 + 8 - rem;
                rem = 1;
            } 
            else {
                digit1 = digit1 - rem;
                rem = 0;
            }
            digit3 = digit1;

            result._array[iter1] = (unsigned char)(digit3 + '0');

            --iter1;
        }
    }
    else if(this->_size == other._size) {
        result._array = new unsigned char[this->_size];
        result._size = this->_size;
        int iter1 = this->_size - 1;
        int iter2 = other._size - 1;
        int rem = 0; 
        // cout  << iter1 << " " << iter2 << endl;
        while(iter2 >= 0) {
            
            int digit1 = this->_array[iter1] - '0';
            int digit2 = other._array[iter2] - '0';
            if(digit1 - rem < digit2) {
                digit1 = digit1 + 8 - rem;
                rem = 1;
            } 
            else {
                digit1 = digit1 - rem;
                rem = 0;
            }
            int digit3 = digit1 - digit2;

            result._array[iter1] = (unsigned char)(digit3 + '0');

            --iter1;
            --iter2;
        }
    } 
    return; 
}

bool Octal::equals(const Octal& other) const {
    if((this->_size == other._size) && (this->_is_negative == other._is_negative) 
    && (this->_is_positive == other._is_positive)) {
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
    if(this->_is_negative && other._is_positive) {
        return false;
    }
    if(this->_is_positive && other._is_negative) {
        return true;
    }
    if(this->_is_positive && other._is_positive) {
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
    else { // both are negative
        if(this->_size > other._size) {
            return false;
        } 
        else if(this->_size < other._size) {
            return true;
        }
        else { // equal size
            for(int i = 0; i < this->_size; ++i) {
                if(this->_array[i] > other._array[i]) {
                    return false;
                } 
                else if (this->_array[i] < other._array[i]) {
                    return true;
                }
            }
            return false;
        }
    }
}

bool  Octal::less(const Octal& other) const {
    if(this->_is_negative && other._is_positive) {
        return true;
    }
    if(this->_is_positive && other._is_negative) {
        return false;
    }
    if(this->_is_positive && other._is_positive) {
        if(this->_size > other._size) {
            return false;
        } 
        else if(this->_size < other._size) {
            return true;
        }
        else { // equal size
            for(int i = 0; i < this->_size; ++i) {
                if(this->_array[i] > other._array[i]) {
                    return false;
                } 
                else if (this->_array[i] < other._array[i]) {
                    return true;
                }
            }
            return false;
        }
    }
    else { // both are negative
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

}
   
void Octal::print() {
    if (this->_size <= 0) {
        return;
    }
    int i = 0;
    if((this->_array[0] == '0') && (this->_size > 1)) {
        i = 1;
    }
    if(this->_is_negative) {
        cout << '-';
    }
    while((this->_array[i] == '0') && (this->_size > 1)) {
        ++i;
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
        _is_negative = false;
        _is_positive = false;
    }
}


Octal operator+(Octal& l, Octal& r) {
    return l.add(r);
}

Octal operator-(Octal& l, Octal& r) {
    return l.subtract(r);
}

bool operator==(Octal& l, const Octal& r) {
    return l.equals(r);
}

bool operator<(Octal& l, const Octal& r) {
    return l.less(r);
}

bool operator>(Octal& l, const Octal& r) {
    return l.greater(r);
}