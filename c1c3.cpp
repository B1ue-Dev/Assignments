#include <iostream>
#include <string>

class Publication {
public:
    std::string title;
    float price;

    void getdata() {
        std::cout << "Enter title: ";
        std::cin.ignore();
        std::getline(std::cin, title);
        std::cout << "Enter price: ";
        std::cin >> price;
    }

    void putdata() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: " << price << std::endl;
    }
};

class Book : public Publication {
public:
    int page_count;

    void getdata() {
        std::cout << "Enter book data: \n";
        Publication::getdata();
        std::cout << "Enter page count: ";
        std::cin >> page_count;
    }

    void putdata() const {
        Publication::putdata();
        std::cout << "Page count: " << page_count << std::endl;
    }
};

class Tape : public Publication {
public:
    float play_time;

    void getdata() {
        std::cout << "Enter tape data: \n";
        Publication::getdata();
        std::cout << "Enter play time (in minutes): ";
        std::cin >> play_time;
    }

    void putdata() const {
        Publication::putdata();
        std::cout << "Play time (in minutes): " << play_time << std::endl;
    }
};

int main() {
    Book book;
    Tape tape;

    std::cout << "Enter data for book:" << std::endl;
    book.getdata();

    std::cout << "\nEnter data for tape:" << std::endl;
    tape.getdata();

    std::cout << "\nDisplaying book data:" << std::endl;
    book.putdata();

    std::cout << "\nDisplaying tape data:" << std::endl;
    tape.putdata();

    return 0;
}
