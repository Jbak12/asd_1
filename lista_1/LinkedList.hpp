#include <stdexcept>
template <typename T>
class LinkedList {
public:
    struct Node {
        T value;
        Node * prev;
        Node* next;
        Node(T value): value(value), next(nullptr), prev(nullptr) {}
        Node(T value, Node* prev, Node* next): value(value), next(next), prev(prev) {}
        Node(): value(T{}), next(nullptr), prev(nullptr) {}
    };
    LinkedList(): _size(0) {
        guard = new Node();
    }

    void push_front(T x) {
        auto left = guard;
        auto right = guard->next;
        auto node = new Node(x,left, right);
        left->next = node;
        right->prev = node;
        _size ++;
    }

    void push_back(T x) {
        auto right = guard;
        auto left = guard->prev;
        auto node = new Node(x,left,right);
        right->prev = node;
        left->next = node;
        _size --;
    }

    T pop_front() {
        auto node_to_delete = guard->next;
        auto right = node_to_delete->next;
        auto value_to_return  = node_to_delete->value;
        guard->next = right;
        right->prev = guard;
        delete node_to_delete;
        return value_to_return;
    }


    T pop_back() {
        auto node_to_delete = guard->prev;
        auto left = node_to_delete->prev;
        auto value_to_return = node_to_delete->value;
        guard->prev = left;
        left->next = guard;
        delete node_to_delete;
        return value_to_return;
    }


    void clear() {

    }

    int find(T x) {
        if (empty()) { return -1;}
        auto node = guard->next;

        for(int i = 0; i < _size; i++) {
            if (node->value == x) {
                return i;
            }
            node = node->next;
        }
        return -1;
        
    }
    T erase(int index) {
        auto node = guard->next;
        for(int i = 0; i<=index;i++) {
            node = node->next;
        }
        auto value_to_return = node->value;
        auto right = node->next;
        auto left = node->prev;
        right->prev = left;
        left->next = right;
        delete node;
        return value_to_return;
    
    }

    void insert(int index, T x) {
        auto node = guard->next;
        for(int i = 0; i<index;i++) {
            node = node->next;
        }
        auto node_to_insert = new Node(x,node->prev, node);
        node->prev->next = node_to_insert;
        node->prev = node_to_insert;
    }
    int remove(T x) {
        int counter = 0;
        auto node = guard->next;
        for(int i = 0; i<_size; i++) {
            if (node->value == x) {
                counter++;
                node->prev->next = node->next;
                node->next->prev = node->prev;
                auto node_to_delete = node;
                node = node->next;
                delete node_to_delete;
            }
        }
        return counter;
    }
    int size() {
        return _size;
    }
    bool empty() {
        return _size == 0;
    }

private:
    Node* guard;
    int _size;

};