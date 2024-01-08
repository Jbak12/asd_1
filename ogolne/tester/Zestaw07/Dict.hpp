#ifndef DICT_HPP
#define DICT_HPP
#include <vector>
#include <string>
#include <limits>
#include <type_traits>
#define BUCKETS 1000


template <typename T>
class LinkedList;

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
        hash_table.clear();
        for(int i = 0; i < BUCKETS;i++) {
            hash_table.push_back(LinkedList<Pair>());
        }
    }
        
    bool erase(const K& k) {
        if(!find(k)) {
            return false;
        }
        unsigned int _hash = hash(k);
        auto node = hash_table[_hash].guard->next;
        int index = 0;
        while(node->value.first != k ) {
            node = node->next;
            index++;
        }
        hash_table[_hash].erase(index);
        _size --;
        return true;

    }

    bool insert(const Pair& p){

        if(find(p.first)) {
            erase(p.first);
        }
        unsigned int _hash = hash(p.first);
        hash_table[_hash].push_back(p);
        _size++;
        return true;
    }

    bool find(const K& k) {
        unsigned int _hash = hash(k);
        auto list = hash_table[_hash];
        auto node = list.guard->next;
        while(node != list.guard) {
            if (node->value.first == k) {
                return true;
            }
            node = node->next;
        }
        return false;
    }

    V& operator[](const K& k ) {
		
		if (!find(k)) {
            std::__throw_out_of_range("No pair with given key");
        }

        unsigned int _hash = hash(k);
        auto list = hash_table[_hash];
        auto node = list.guard->next;
        while(node != list.guard) {
            if(node->value.first == k) {
                return node->value.second;
            }
            node = node->next;
        }
    }

    int size() {
        return _size;
    }
    bool empty() {
        return _size == 0;
    }

    void buckets () {
		int shortest = std::numeric_limits<int>::max();
		int longest = 0;
        int buckets = 0;
		
		for (auto l : hash_table) {
			if (l.size() > longest) {
				longest = l.size();
			}
			if (l.size() < shortest) {
				shortest = l.size();
			}
            if(!l.empty()) {
                buckets ++;
            }
		}
		
		std::cout << "# " << _size << " " << buckets << " " << shortest << " " << longest << std::endl;
	}

    unsigned int hash(const K& k) {
        if constexpr (std::is_same_v<K, std::string>) {
            return hash_string_djb2(k);
        }else {
            return 0;
        }
        
    }  

    unsigned int hash_string_djb2(const std::string& x) {
        unsigned int hash = 5381;  // Initial hash value recommended by djb2 algorithm

        for (char c : x) {
            hash = ((hash << 5) + hash) + static_cast<unsigned int>(c);
        }

        return hash % BUCKETS;
    }


    private:
    bool find_pair(Pair p) {
        unsigned int _hash = hash(p.first);
        

    }
    std::vector<LinkedList<Pair>> hash_table;
    int _size;

};

#endif