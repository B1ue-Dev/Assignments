#include <iostream>
#include <string>

struct Date {
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

class Employee {
private:
    int employeeNumber;
    std::string employeeName;
    float compensation;
    Date first_employed;
    int etype;

public:
    void setEmployee(int number, std::string name, float comp) {
        employeeNumber = number;
        employeeName = name;
        compensation = comp;
    }

    void displayEmployee() {
        std::cout << "Employee Number: " << employeeNumber << std::endl;
        std::cout << "Employee Name: " << employeeName << std::endl;
        std::cout << "Compensation: $" << compensation << std::endl;
    }
};

class Employee2 : private Employee {
private:
    double data;
    enum period {hourly, weekly, monthly};
};


class Manager : private Employee2 {
private:

};

int main() {
    Employee emp[3];

    for (int i = 0; i < 3; ++i) {
        int number;
        std::string name;
        float comp;

        std::cout << "Enter details for employee " << i + 1 << ":" << std::endl;
        std::cout << "Employee Number: ";
        std::cin >> number;
        std::cin.ignore();
        std::cout << "Employee Name: ";
        getline(std::cin, name);
        std::cout << "Compensation: $";
        std::cin >> comp;

        emp[i].setEmployee(number, name, comp);
    }

    std::cout << "\nEmployee Details:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "Employee " << i + 1 << ":\n";
        emp[i].displayEmployee();
        std::cout << std::endl;
    }

    return 0;
}
