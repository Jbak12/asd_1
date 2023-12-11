#include <stdexcept>

template <typename T, int N>
class CursorList {

    struct Node {
        T val;
        int next;
    };
    CursorList(): head(-1),tail(-1),spare(0),_size(0) {
        for (int i = 0; i < N-1; i++) {
            list[i].next = i+1;
        }
        list[N-1].next = -1;
    }

    void push_back(T x) {
        if (_size == N) {
            std::__throw_out_of_range("juz jest n elementow w kolekcji");
        }
        int old_tail = tail;
        tail = allocate();

        if(_size == 0) {
            head = tail;
        } else {
            list[old_tail].next = tail;
        }
        list[tail].val = x;
        list[tail].next = -1;
        _size ++;
    }
    
    void push_front(T x) {
        if (_size == N) {
            std::__throw_out_of_range("juz jest n elementow w kolekcji");
        }


        int old_head = head;
        head = allocate();

        if(_size == 0) {
            tail = head;
        } else {
            list[old_head].next = head;
        }
        list[head].val = x;
        list[head].next = old_head;
         _size ++;

    }

    T pop_back() {
        if(_size == 0) {
            std::__throw_underflow_error("EMPTY");
        }
        int tmp = head;
        int new_tail;
        while(list[tmp].next != -1) {
            if(list[tmp].next == tail) {
                new_tail = tmp;
                break;
            }
            tmp = list[tmp].next;

        }

        deallocate(tail);
        T val_to_return = list[tail].val;
        tail = new_tail;
        _size --;
        return ;
    }

    T pop_front() {
        if(_size == 0) {
            std::__throw_underflow_error("EMPTY");
        }
        int old_head = head;
        head = list[old_head].next;
        T val_to_return = list[old_head].val;
        deallocate(old_head);
        _size --;
        return val_to_return;
    }

    T erase(int index) {
        _size --;
        return T{};
    }

    void insert(int index, T x) {
        _size ++;

    }

    void clear() {

    }

    int find(T x) {
        return -1;
    }

    inline int allocate() {
        int old_spare = spare;
        spare = list[spare].next;
        return old_spare;
    }

    void deallocate(int index) {
        int old_spare = spare;
        list[index].next = old_spare;
        spare = index;
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