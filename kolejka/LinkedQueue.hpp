#include <stdexcept>

template <typename T>
class LinkedQueue {
public:
    struct Node {
        T value;
        Node* next;
        Node(T val) : value(val), next(nullptr) {}
    };

    LinkedQueue() : _size(0), head(nullptr), tail(nullptr) {}

    ~LinkedQueue() {
        while (!empty()) {
            pop();
        }
    }

    T pop() {
        if (empty()) {
            throw std::underflow_error("EMPTY");
        }
        T val_to_return = head->value;
        Node* ptr = head;
        head = head->next;
        ptr = nullptr;
        _size--;
        return val_to_return;
    }

    void push(T x) {
        Node* ptr = new Node(x);
        if (empty()) {
            head = tail = ptr;
        } else {
            tail->next = ptr;
            tail = ptr;
        }
        _size++;
    }

    bool empty() {
        return _size == 0;
    }

    int size() {
        return _size;
    }

    void printAll() {
        Node* current = head;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    int _size;
    Node* head;
    Node* tail;
};
