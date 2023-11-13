#include <stdexcept>

template<typename T>
class LinkedStack {
    struct Node
    {
        T value;
        Node* prev;
    };
    
public:
    LinkedStack():length(0) {}
    
    void push(T x) {
        Node* newHead;
        newHead->value = x;
        newHead->prev = head;
        head = newHead;
        length++;
    }
    
    T pop() {
        if (length == 0) {
            throw std::out_of_range("EMPTY");
        }
        Node* newHead = head->prev;
        T value_to_return = head->value;
        delete head;
        head = newHead;
        length--;
        return value_to_return; 
    }   
    
    int size(){
        return length;
    }
    
    bool empty(){
        return length == 0;
    }

private:
    int length;
    Node* head;
};
