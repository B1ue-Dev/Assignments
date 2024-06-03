#include <iostream>
#include <iomanip>

class Time{
public:
    int gio, phut, giay;
    Time() : gio(0), phut(0), giay(0) {}
    Time(int h, int m, int s) : gio(h), phut(m), giay(s) {}

    Time normalize(const Time &time) const {
        int seconds = giay + (phut * 60) + (gio * 3600);
        Time result;
        result.gio = seconds / 3600;
        result.phut = (seconds % 3600) / 60;
        result.giay = (seconds % 3600) % 60;
        return result;
    }

    void display() const {
        Time result = normalize(*this);
        std::cout << std::setw(2) << std::setfill('0') << result.gio << ":"
                  << std::setw(2) << std::setfill('0') << result.phut << ":"
                  << std::setw(2) << std::setfill('0') << result.giay << std::endl;

    }

    Time operator++() { // ++x
        giay++;
        return *this;
    }

    Time operator++(int) { // x++
        Time res = *this;
        giay++;
        return res;
    }

    Time operator--() { // x--
        giay--;
        return *this;
    }

    Time operator--(int) { // x--
        Time res = *this;
        res.giay--;
        return res;
    }

    Time operator-(const Time &other) const {
        int _gio = gio - other.gio;
        int _phut = phut - other.phut;
        int _giay = giay - other.giay;

        return Time(_gio, _phut, _giay);
    }

    Time operator*(float num) const {
        int _gio = gio * num;
        int _phut = phut * num;
        int _giay = giay * num;

        return Time(_gio, _phut, _giay);
    }

};
int main(){
    const Time time1(36, 123, 634);
    const Time time2(10, 22, 324);
    Time time5(11, 59, 58);
    Time time3;

    ++time5;
    time5.display();

    time5--;
    time5.display();

    time3 = time1 - time2;
    time3.display();

    time3 = time1 * 2.5;
    time3.display();
}
