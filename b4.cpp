#include <iostream>

class Int {
private:
    int value;
    static const int INT_MAX = 2147483647;
    static const int MIN_INT = -2147483647;

    void checkOverflow(long double result) {
        if (result > INT_MAX || result < MIN_INT) {
           throw "Overflow!";
        }
    }
public:
    Int() : value(0) {}
    Int(int val) : value(val) {}

    void display() {
        std::cout << value << std::endl;
    }

    Int operator+(const Int &_value) {
        long double result = (long double)value + _value.value;
        checkOverflow(result);
        return Int(result);
    }

    Int operator-(const Int &_value) {
        long double result = (long double)value - _value.value;
        checkOverflow(result);
        return Int(result);
    }

    Int operator*(const Int &_value) {
        long double result = (long double)value * _value.value;
        checkOverflow(result);
        return Int(result);
    }

    Int operator/(const Int &_value) {
        if (_value.value == 0) {
            throw "Division by zero!";
        }
        long double result = (long double)value / _value.value;
        checkOverflow(result);
        return Int(result);
    }
};


int main() {
    try {
        Int a(10);
        Int b(20);
        Int c;

        c = a + b;

        std::cout << "Result of a + b: ";
        c.display();

        c = a - b;
        std::cout << "Result of a - b: ";
        c.display();

        c = a * b;
        std::cout << "Result of a * b: ";
        c.display();

        c = a / b;
        std::cout << "Result of a / b: ";
        c.display();

    } catch (const char* msg) {
        std::cerr << "Exception: " << msg << std::endl;
    }

    return 0;
}
