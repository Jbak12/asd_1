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
        guard->next = guard;
        guard->prev = guard;
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
        _size ++;
    }

    T pop_front() {
        if (empty()) {
            throw std::out_of_range("EMPTY");
        }
        auto node_to_delete = guard->next;
        auto value_to_return  = node_to_delete->value;
        auto right = node_to_delete->next;
        guard->next = right;
        right->prev = guard;
        _size --;
        delete node_to_delete;
        return value_to_return;
    }


    T pop_back() {
        if (empty()) {
            throw std::out_of_range("EMPTY");
        }
        auto node_to_delete = guard->prev;
        auto left = node_to_delete->prev;
        auto value_to_return = node_to_delete->value;
        guard->prev = left;
        left->next = guard;
        _size --;
        delete node_to_delete;
        return value_to_return;
    }

     void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    int find(T x) {
        int index = 0;
        auto node = guard->next;
        while (node != guard) {
            if (node->value == x) {
                return index;
            }
            node = node->next;
            index++;
        }

        return -1;
    }
    
    T erase(int index) {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("INDEX OUT OF RANGE");
        }
        auto node = guard->next;
        for(int i = 0; i<index;i++) {
            node = node->next;
        }
        auto value_to_return = node->value;
        auto right = node->next;
        auto left = node->prev;
        right->prev = left;
        left->next = right;
        _size --;
        delete node;
        return value_to_return;
    
    }

    void insert(int index, T x) {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("Index out of range");
            return;
        }

        auto node = guard->next;
        auto reverse = (index > _size / 2); 

        if (reverse) {
            node = guard->prev;
            for (int i = _size; i > index; --i) {
                node = node->prev;
            }
        } else {
            for (int i = 0; i < index; ++i) {
                node = node->next;
            }
        }

        auto node_to_insert = new Node(x, node->prev, node);
        node->prev->next = node_to_insert;
        node->prev = node_to_insert;
        _size++;
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
                _size --;
            }
        }
        return counter;
    }

    int size() {
        return _size;
    }
    bool empty() {
        return (_size == 0);
    }

    //debug
    void printAll() {
        auto node = guard->next;

        while (node != guard) {
            std::cout << node->value << " ";
            node = node->next;
        }

        std::cout << std::endl;
    }

private:
    Node* guard;
    int _size;

};