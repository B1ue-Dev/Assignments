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

class Sales {
public:
    float sales[3];

    void getdata() {
        for (int i = 0; i < 3; i++) {
            std::cout << "Enter sales for month " << i + 1 << ": ";
            std::cin >> sales[i];
        }
    }

    void putdata() const {
        for (int i = 0; i < 3; i++) {
            std::cout << "Sales for month " << i + 1 << ": " << sales[i] << std::endl;
        }
    }
};

class Book : public Publication, public Sales {
public:
    int page_count;

    void getdata() {
        std::cout << "Enter book data: \n";
        Publication::getdata();
        std::cout << "Enter page count: ";
        std::cin >> page_count;
        Sales::getdata();
    }

    void putdata() const {
        Publication::putdata();
        std::cout << "Page count: " << page_count << std::endl;
        Sales::putdata();
    }
};

class Tape : public Publication, public Sales {
public:
    float play_time;

    void getdata() {
        std::cout << "Enter tape data: \n";
        Publication::getdata();
        std::cout << "Enter play time (in minutes): ";
        std::cin >> play_time;
        Sales::getdata();
    }

    void putdata() const {
        Publication::putdata();
        std::cout << "Play time (in minutes): " << play_time << std::endl;
        Sales::putdata();
    }
};

class Disk : public Publication, public Sales {
public:
    int type;

    void getdata() {
        char _type;
        std::cout << "Enter disk type (c for CD, d for DVD): ";
        std::cin >> _type;
        type = std::stoi(std::to_string(_type));
    }

    void putdata() const {
        std::cout << "Type: " << (type == 99 ? "CD" : "DVD");
    }

};

int main() {
    Book book;
    Tape tape;
    Disk disk;

    std::cout << "***Enter data for book***" << std::endl;
    book.getdata();

    std::cout << "\n***Enter data for tape***" << std::endl;
    tape.getdata();

    std::cout << "\n***Enter data for disk***" << std::endl;
    disk.getdata();

    std::cout << "\nDisplaying book data:" << std::endl;
    book.putdata();

    std::cout << "\nDisplaying tape data:" << std::endl;
    tape.putdata();

    std::cout << "\nDisplaying disk data:" << std::endl;
    disk.putdata();

    return 0;
}
