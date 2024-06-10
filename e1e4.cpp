#include <iostream>
#include <string>
#include <vector>

class Publication {
public:
    std::string title;
    float price;

    virtual void getdata() {
        std::cout << "Enter title: ";
        std::cin.ignore();
        std::getline(std::cin, title);
        std::cout << "Enter price: ";
        std::cin >> price;
    }

    virtual void putdata() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: " << price << std::endl;
    }

    virtual bool isOversize() = 0;
};

class Book : public Publication {
public:
    int page_count;
    bool isOversize() {
        return page_count > 800;
    }

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
    bool isOversize() {
        return play_time > 90;
    }

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
    std::vector<Publication*> pubarr;

    for (int i = 0; i < 2; i++) {
        char choice;
        std::cout << "Enter data for book/tape (b/t): ";
        std::cin >> choice;

        if (choice == 'b') {
            pubarr.push_back(new Book);
        } else {
            pubarr.push_back(new Tape);
        }

        pubarr[i]->getdata();
    }

    for (int i = 0; i < 2; i++) {
        pubarr[i]->putdata();
        if (pubarr[i]->isOversize()) {
            std::cout << "This publication is oversize.\n";
        }
    }

    return 0;
}
