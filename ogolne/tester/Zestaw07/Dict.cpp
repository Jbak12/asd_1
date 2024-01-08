#include <iostream>
#include <fstream>
#include "LinkedList.hpp"
#include "Dict.hpp"
#include "Dict.hpp" 

int main(int argc, char const *argv[]) {
    Dict<std::string, std::string> dictionary;
    std::pair<std::string, std::string> entry;

    std::string key;
    std::ifstream inputFile(argv[1]);

    while (inputFile >> entry.first >> entry.second) {
        dictionary.insert(entry);
    }

    while (std::cin >> key) {
        if (dictionary.find(key)) {
            std::cout << dictionary[key] << std::endl;
        } else {
            std::cout << "-" << std::endl;
        }
    }

    return 0;
}
