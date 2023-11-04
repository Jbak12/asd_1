#include <vector>
#include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"
#include <iostream>

int main(int argc, char *argv[]) {

    ArrayQueue<int> queue(5);
    LinkedQueue<int> queue_2;

    int operations;

    std::cin >> operations;

    for (int i = 0; i < operations; ++i) {
        char input;
        std::cin >> input;

        try {
            switch (input) {
                case 'A':
                    int value;
                    std::cin >> value;
                    queue_2.push(value);
                    break;
                case 'D':  
                    std::cout << queue_2.pop() << std::endl;
                    break;
                case 'S':  
                    std::cout << queue_2.size() << std::endl;
                    break;
                default:
                    std::cout << "zle dane" << std::endl;
            }
        } catch (const std::underflow_error& e) {
            std::cout << e.what() << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << e.what() << std::endl;
        }
        queue_2.printAll();
    }
}