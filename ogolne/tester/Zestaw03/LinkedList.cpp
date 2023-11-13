#include <iostream>
#include "LinkedList.hpp"

int main() {
    LinkedList<int> list;
    int operations;

    std::cin >> operations;

    for (int i = 0; i < operations; ++i) {
        char input;
        std::cin >> input;

        try {
            switch (input) {
                case 'F':
                    int value;
                    std::cin >> value;
                    list.push_front(value);
                    break;
                case 'B':
                    int val;
                    std::cin >> val;
                    list.push_back(val);
                    break;
                case 'f':  
                    std::cout << list.pop_front() << std::endl;
                    break;
                case 'b':  
                    std::cout << list.pop_back() << std::endl;
                    break;
                case 'R':
                    int x,y;  
                    std::cin>>x;
                    std::cin>>y;
                    int res = list.find(x);
                    if(res == -1) {
                        std::cout<<"FALSE"<<std::endl;
                    } else {
                        list.erase(res);
                        list.insert(res,y);
                        std::cout<<"TRUE"<<std::endl;

                    }
                    std::cout << list.size() << std::endl;
                    break;
                // default:
                //     std::cout << "zle dane" << std::endl;
            }
        } catch (const std::out_of_range& e) {
            std::cout << e.what() << std::endl;
        }
    }

}