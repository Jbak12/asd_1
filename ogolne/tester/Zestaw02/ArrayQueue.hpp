#include <stdexcept>
#include <iostream>

template<typename T>
class ArrayQueue {
public:
    ArrayQueue(int n) : queue(new T[n]), length(0), ptr(0), n(n) {}

    ~ArrayQueue() {
        delete[] queue;
    }

    void push(T element) {
        queue[(ptr + length) % n] = element;
        if (length < n) {
            length++;
        } else {
            ptr = (ptr + 1) % n;
        }
    }

    T pop() {
        if (empty()) {
            throw std::out_of_range("EMPTY");
        }
        T value_to_return = queue[ptr];
        ptr = (ptr + 1) % n;
        length--;
        return value_to_return;
    }

    int size() {
        return length;
    }

    bool empty() {
        return length == 0;
    }

    void printAll() {
        int index = ptr;
        for (int i = 0; i < length; i++) {
            std::cout << queue[index] << " ";
            index = (index + 1) % n;
        }
        std::cout << std::endl;
    }

private:
    T* queue;
    int length;
    int ptr;
    int n;
};
