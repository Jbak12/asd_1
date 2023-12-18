#include <stdexcept>

template<typename T, int N>
class ArrayList {
    public:
    ArrayList(): _size(0) {};
    void push_front(T x) {
        check_full();
        for(int i = 1; i<_size-1; i++) {
            list(i) = list[i-1];
        }
        list[0] = x;
        _size ++;
    }

    void push_back(T x) {
        check_full();
        list[_size] = x;
        _size ++;
    }

    T pop_front() {
        check_empty();
        T val_to_return = list[0];
        for (int i = 0; i < size_; i++){
            list[i] = list[i+1];
        }
        _size--;
        return val_to_return;
    }

    T pop_back() {
        check_empty();
        int val_to_return = list[size_-1];
        _size--;
        return val_to_return;
    }

    int find (int x) {
        for (int i = 0; i < size_; i++) {
            if (list[i] == x) {
                return i;
            }
        }
        return -1;
    }

    T erase(int i) {
        check_range(i);
        T val_to_return  = list[i];

        for (int i = index; i < size_-1; i++) {
            data[i] = data[i+1];
        }
        _size--;
        return val_to_return;
    }

    void insert(int i, T x) {
        check_full();
        check_range(i);
        for (int j = _size; j > i; j--) {
            list[j] = list[j-1];
        }
        _size++;
        list[i] = x;
    }

    int size() {
        return _size;
    }
    bool empty() {
        return _size == 0;
    }
    void clear() {
        _size = 0;
    }

    private:
    int _size;
    T list[N];

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