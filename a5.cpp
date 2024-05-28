#include <iostream>

struct Date {
    unsigned int day;
    unsigned int month;
    unsigned int year;

    bool getdate() {
        char slash = '/';
        std::cin >> month >> slash >> day >> slash >> year;
        if (month % 2 != 0) {
            if (day > 31) {
                return false;
            }
        } else if (month == 2) {
            if (year % 4 == 0) {
                if (day > 29) {
                    return false;
                }
            } else {
                if (day > 28) {
                    return false;
                }
            }
        } else {
            if (day > 30) {
                return false;
            }
        }
        return true;
    }

    void showdate() {
        std::cout << day << "/" << month << "/" << year;
    }

};

int main() {
    Date date;
    bool a = date.getdate();
    if (!a) { std::cout << "Incorrect format, try again."; return 1; }
    date.showdate();
    return 0;
}
