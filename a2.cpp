#include <iostream>
#include <conio.h>

class tollBooth {
public:
    unsigned int totalCars;
    double totalCash;

    tollBooth() {
        totalCars = 0;
        totalCash = 0.0;
    }

    void payingCar() {
        totalCars++;
        totalCash += 0.50;
    }

    void nopayCar() {
        totalCars++;
    }

    void display() const {
        int payCars = 0, nopayCars = 0;
        payCars = totalCash / 0.50;
        nopayCars = totalCars - payCars;
        std::cout << "Number of non-paying cars: " << nopayCars << std::endl;
        std::cout << "Number of paying cars: " << payCars << std::endl;
        std::cout << "Total cars: " << totalCars << std::endl;
        std::cout << "Total cash collected: $" << totalCash << std::endl;
    }
};

int main() {
    tollBooth booth;
    char key;

    std::cout << "Press 'p' for paying car, 'n' for non-paying car, 'Esc' to exit.\n";

    while (true) {
        key = _getch();

        if (key == 27) {
            booth.display();
            break;
        } else if (key == 'p') {
            booth.payingCar();
            std::cout << "Paid car recorded successfully." << std::endl;
        } else if (key == 'n') {
            booth.nopayCar();
            std::cout << "Non-paid car recorded successfully." << std::endl;
        }
    }

    return 0;
}
