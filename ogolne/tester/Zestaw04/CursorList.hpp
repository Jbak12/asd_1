#include <stdexcept>

template <typename T, int N>
class CursorList {

    struct Node {
        T val;
        int next;
    };
    public:
    CursorList(): head(-1),tail(-1),spare(0),_size(0) {
        for (int i = 0; i < N-1; i++) {
            list[i].next = i+1;
        }
        list[N-1].next = -1;
    }

    void push_back(T x) {
        check_full();
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
        check_full();
        int old_head = head;
        head = allocate();

        if(_size == 0) {
            tail = head;
            list[head].next = -1;
        } else {
            list[head].next = old_head;
        }
        list[head].val = x;
         _size ++;
    }

    T pop_back() {
        check_empty();
        int tmp_tail = head;
        int new_tail;
        while(list[tmp_tail].next != -1) {
            if(list[tmp_tail].next == tail) {
                break;
            }
            tmp_tail = list[tmp_tail].next;

        }
        T val_to_return = list[tail].val;
        deallocate(tail);
        tail = tmp_tail;
        _size --;
        return val_to_return;
    }

    T pop_front() {
        check_empty();
        int temp_head = head;
        T val_to_return = list[temp_head].val;
        head = list[temp_head].next;
        deallocate(temp_head);
        _size --;
        return val_to_return;
    }

    T erase(int index) {
        check_empty();
        check_range(index);

        if(index == 0) {
            T val = pop_front();
            return val;
        } else if (index == N-1) {
            T val = pop_back();
            return val;
        }

        int to_delete = head;
        int prev = head;
        for (int i = 0; i< index - 1 ; i++) {
            prev = list[prev].next;
        }
        T val_to_return = list[to_delete].val;
        to_delete = list[prev].next;
        list[prev].next = list[to_delete].next;
        deallocate(to_delete);
        _size --;
        return val_to_return;
    }

    void insert(int index, T x) {
        check_full();
        check_range(index);
         _size ++;

        int temp = allocate();
        list[temp].val = x;
        if(index == 0) {
            list[temp].next = head;
            head = temp;
            return;
        }

        int prev = head;
        for(int i = 0;i<index-1;i++) {
            prev = list[prev].next;
        
        }
        list[temp].next = list[prev].next;
        list[prev].next = temp;
    }

    void clear() {
        for (int i = 0; i < N-1; i++) {
            list[i].next = i+1;
        }
        list[N-1].next = -1;
    }

    int find(T x) {
        int temp=head;
        for(int i=0;i<_size;i++) {
            if(list[temp].val==x) {
                return i;
            }
        temp=list[temp].next;
    }
    return -1;
    }

    int remove(T x) {
        int count=0;
        int temp=head;
        for(int i=0;i<_size;i++) {
            if(list[temp].val == x) {
                count++;
                erase(i);
            }
            temp=list[temp].next;
        }
        return count;
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

    inline void check_full() {
        if (_size == N) {
            throw std::out_of_range("FULL");
        }
    }
    inline void check_empty() {
        if (_size == 0) {
            throw std::out_of_range("EMPTY");
        }
    }

    inline void check_range(int i) {
        if (i < 0 || i > _size) {
            throw std::out_of_range("Index out of range");
        }
    }
};