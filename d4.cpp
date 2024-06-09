#include <iostream>

struct Node {
    int data;  /// The data that the node holds.
    Node* next;  /// The pointer to the next node.
};

class LinkedList {
private:
    Node* head;  /// The pointer to the first node of the linked list.
public:
    LinkedList() : head(nullptr) {}  /// Constructor of the linked list.

    void insertNew(int data) {
        Node* newNode = new Node;
        newNode->data = data;  /// Assign the data to the node.
        newNode->next = head;  /// newNode points to the current head.
        head = newNode;  /// The new node becomes the head.
    }

    void printList() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    ~LinkedList() {
        Node* temp = head;
        while(temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            std::cout << "Deleted " << temp->data << std::endl;
            temp = next;
        }
    }
};

int main() {
    LinkedList list;  /// Create a linked list object.

    list.insertNew(1);  /// Insert a new node with data 1.
    list.insertNew(2);  /// Insert a new node with data 2.
    list.insertNew(3);  /// Insert a new node with data 3.

    list.printList();  /// Print the linked list.

    return 0;
}
