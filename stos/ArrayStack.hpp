#include <stdexcept>

template<typename T, int N>
class ArrayStack {
public:
    ArrayStack() {
        length = 0;
    }
    
    void push(T x) {
        if (length >= N) {
            throw std::out_of_range("Zbyt duzo elementow");
        }
        stack[length] = x;
        length++;
    }
    
    T pop() {
        if (length == 0) {
            throw std::out_of_range("EMPTY");
        }
        T value_to_return = stack[length - 1];
        stack[length - 1] = T{}; 
        length--;
        return value_to_return;
    }
    
    int size(){
        return length;
    }
    
    bool empty(){
        return length == 0;
    }

    T top() {
        if (length == 0) {
            throw std::out_of_range("EMPTY");
        }
        T value_to_return = stack[length - 1];
        return value_to_return;
    }

private:
    T stack[N];
    int length;
};
