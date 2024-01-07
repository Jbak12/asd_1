#include <vector>
#include <string>
#include <type_traits>
#include "LinkedList.hpp"
#define BUCKETS 100
// typedef Uint Unsigned int

struct hash_table_info {
    int _size;
    int number_of_classes;
    int shortest_list;
    int longest_list;
};
template<class K, class V>
class Dict {
using Pair = std::pair<K,V>;
    public:
    Dict(): _size(0) {
        for(int i = 0; i < BUCKETS;i++) {
            hash_table.push_back(LinkedList<Pair>());
        }
    }
    void clear(){

    }
    bool insert(const Pair& p){
        unsigned int _hash = hash(p->first);
        hash_table[hash].push_back(p);
    }
    bool find(const K& k) {
        unsigned int _hash = hash(k);
        return hash_table[_hash].empty();
    }

    V& operator[](const K& k) {
        hash()
    }

    bool erase(const K& k) {

    }
    int size() {
        return _size;
    }
    bool empty() {
        return _size == 0;
    }

    void buckets() {

    }

    unsigned int hash(const K& k) {
        if constexpr (std::is_same_v<K, std::string>) {
            hash_string_djb2(k);
        }
        
    }  

    unsigned int hash_string_djb2(const std::string& x) {
        unsigned int hash = 5381;  // Initial hash value recommended by djb2 algorithm

        for (char c : x) {
            hash = ((hash << 5) + hash) + static_cast<unsigned int>(c);
        }

        return hash;
    }

    private:
    std::vector<LinkedList<Pair>> hash_table;
    int _size;

};