#include <stdexcept>
template <typename T, int N>
class CursorList {

    struct Node {
        T val;
        Node next;
    };
    CursorList(): head(-1),tail(-1),spare(0),_size(0) {
        for (int i = 0; i < N-1; i++) {
            list[i].next = i+1;
        }
        list[N-1] = -1;
    }

    void push_back(T x) {
        int index_to_insert_to = allocate();
        Node node_to_insert;
        node_to_insert.val = x;
        list[tail].next = node_to_insert;
        _size ++;
    }
    
    void push_front(T x) {
        int index_to_insert_to = allocate();
        Node node_to_insert;
        node_to_insert.val = x;
        node_to_insert.next = head;
        list[index_to_insert_to] = node_to_insert;
        _size ++;

    }

    T pop_back() {
        return T{};
    }

    T pop_front() {
        return T{};
    }

    T erase(int index) {
        _size --;
        return T{};
    }

    void insert(int index. T x) {

        _size ++;

    }

    void clear() {

    }

    int find(T x) {
        return -1;
    }

    int allocate() {
        int tmp = spare;
        spare = arr[spare].next;
        return tmp;
    }

    int deallocate() {
        
    } 

    bool empty() {
        return _size == 0;
    }

    int size() {
        return _size;
    }

    private:
    Node list[N];
    int head;
    int tail;
    int _size;
    int spare;


};