#include <iostream>

#define MAX 3

struct Pair {
    int x;
    int y;
};

class Stack {
private:
    int st[MAX * 2];
    int top;
public:
    Stack() { top = -1; }
    void push(int var) {
        if (top >= MAX * 2 - 1) {
            throw "Stack Overflow!";
        }
        st[++top] = var;
    }
    int pop() {
        if (top < 0) {
            throw "Stack Underflow!";
        }
        return st[top--];
    }
    void viewStack() {
        for (int j = 0; j <= top; j++) {
            std::cout << st[j] << ' ';
        }
        std::cout << std::endl;
    }
};

class pairStack : public Stack {
public:
    void push(Pair p) {
        Stack::push(p.x);
        Stack::push(p.y);
    }

    Pair pop() {
        Pair temp;
        temp.y = Stack::pop();
        temp.x = Stack::pop();
        return temp;
    }
};

int main() {
    // Initialize a stack.
    try {
        pairStack ps;

        // Creating 3 pairs.
        Pair p1 = {1, 2};
        Pair p2 = {3, 4};
        Pair p3 = {5, 6};
        Pair p4 = {7, 8};

        // Pushing the pairs to the stack.
        ps.push(p1);
        std::cout << "Current Stack: ";
        ps.viewStack();
        ps.push(p2);
        std::cout << "Current Stack: ";
        ps.viewStack();
        ps.push(p3);
        std::cout << "Current Stack: ";
        ps.viewStack();
        ps.push(p4);
        std::cout << "Current Stack: ";
        ps.viewStack();

        // Popping the stack to empty.
        for (int i = 0; i < 3; i++) {
            Pair p = ps.pop();
            std::cout << "Popped pair: (" << p.x << ", " << p.y << ")" << std::endl;
        }
    } catch (const char* msg) {
        std::cout << "Exception: " << msg << std::endl;
    }


    return 0;
}
