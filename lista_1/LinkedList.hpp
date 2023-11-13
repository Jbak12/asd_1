#include <stdexcept>
template <typename T>
class LinkedList {
public:
    Struct Node {
        T value;
        Node* next;
        Node * prev;
    }
    LinkedList(): _size(0)
private:
    Node* guard;
    int _size;

};