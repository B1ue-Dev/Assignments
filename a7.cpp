#include <iostream>

class Angle {
public:
    int degrees;
    float minutes;
    char direction_letter;

    Angle(int _degrees, float _minutes, char _direction_letter) :
        degrees(_degrees), minutes(_minutes), direction_letter(_direction_letter) {}

    void getAngle() {
        std::cout << "Enter the degrees: ";
        std::cin >> degrees;
        if (degrees < 0 || degrees >= 180) {
            std::cout << "Invalid degrees. Please enter a valid degrees." << std::endl;
            getAngle();
        }
        std::cout << "Enter the minutes: ";
        std::cin >> minutes;
        if (minutes < 0 || minutes >= 60) {
            std::cout << "Invalid minutes. Please enter a valid minutes." << std::endl;
            getAngle();
        }
        std::cout << "Enter the direction letter: ";
        std::cin >> direction_letter;
        if (direction_letter != 'N' && direction_letter != 'S' && direction_letter != 'E' && direction_letter != 'W') {
            std::cout << "Invalid direction letter. Please enter a valid direction letter." << std::endl;
            getAngle();
        }
    }

    void showAngle() {
        std::string type;
        if ((direction_letter == 'N' || direction_letter == 'S') && degrees <= 90) {
            type = "Latitude";
        } else if ((direction_letter == 'E' || direction_letter == 'W') && degrees <= 180) {
            type = "Longitude";
        }

        std::cout << type << " " << degrees << "\xF8" << minutes << "' " << direction_letter << std::endl;
    }
};

int main() {
    while (true) {
        Angle angle(0, 0, 'N');
        angle.getAngle();
        angle.showAngle();

        std::cout << "Do you want to enter another angle? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice == 'n') {
            break;
        }
    }

    return 0;
}
