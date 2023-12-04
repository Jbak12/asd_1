#include <stdexcept>
#define guard(_condition) if (bool(_condition)){}

template <typename T, int N>
class CursorList {

    struct Node {
        T val;
        int next;
    };
    CursorList(): head(0),tail(0),spare(0),_size(0) {
        for (int i = 0; i < N-1; i++) {
            list[i].next = i+1;
        }
        list[N-1].next = -1;
    }

    void push_back(T x) {
        if (_size == N) {
            std::__throw_out_of_range("juz jest n elementow w kolekcji");
        }
        int index_to_insert_to = allocate();
        Node node_to_insert;
        node_to_insert.val = x;
        node_to_insert.next = -1;
        list[tail].next = index_to_insert_to;
        tail = index_to_insert_to;
        list[tail] = node_to_insert;
        _size ++;
    }
    
    void push_front(T x) {
        if (_size == N) {
            std::__throw_out_of_range("juz jest n elementow w kolekcji");
        }
        int index_to_insert_to = allocate();
        Node node_to_insert;
        node_to_insert.val = x;
        node_to_insert.next = head;
        head = index_to_insert_to;
        list[head] = node_to_insert;
        _size ++;

    }

    T pop_back() {
        t--;
        return T{};
    }

    T pop_front() {
        tp--;
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
        int old_spare = spare;
        spare = list[spare].next;
        return old_spare;
    }

    void deallocate(int index) {
        int old_spare = spare;
        int new_spare = head;
        for(int i = 0;i<index;i++){

        }

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