#include <iostream>

class SafeArray {
public:
    int upperbound;
    int lowerbound;
    int list[100]{};

    SafeArray(int lower, int upper) {
        lowerbound = lower;
        upperbound = upper;
    }

    int& operator[] (int index) {
        if (index < lowerbound || index > upperbound) {
            throw "Index out of bound.";
        }
        return list[index - lowerbound];
    }


};

int main() {
    try {
        SafeArray sa(100, 175);

        sa[100] = 10;
        sa[175] = 20;

        std::cout << "sa[100] = " << sa[100] << std::endl;
        std::cout << "sa[175] = " << sa[175] << std::endl;

        std::cout << "sa[176] = " << sa[176] << std::endl;
    } catch (const char* msg) {
        std::cerr << "Exception: " << msg << std::endl;
    }

    return 0;
}
