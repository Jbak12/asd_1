#include <iostream>
#include "CursorList.hpp"
#include "ArrayList.hpp"

int main() {
    ArrayList<int,10000> list = ArrayList<int,10000>();
    int operations;

    std::cin >> operations;

    for (int i = 0; i < operations; ++i) {
        char input;
        std::cin >> input;

        try {
            switch (input) {
                case 'F': {
                    int value;
                    std::cin >> value;
                    list.push_front(value);
                    break;
                }
                case 'B': {
                    int val;
                    std::cin >> val;
                    list.push_back(val);
                    break;
                }
                case 'f': {
                    auto el_to_p = list.pop_front();
                    std::cout << el_to_p << std::endl;
                    break;
                }
                case 'b': {
                    auto element_to_print = list.pop_back();
                    std::cout << element_to_print << std::endl;
                    break;
                }
                case 'R': {
                    int x,y;  
                    std::cin>>x;
                    std::cin>>y;
                    int find_res = list.find(x);
                    // std::cout<< "index: znalezionego ziomka: " <<find_res <<std::endl;
                    if(find_res == -1) {
                        std::cout<<"FALSE"<<std::endl;
                    } else {
                        list.erase(find_res);
                        list.insert(find_res,y);
                        std::cout<<"TRUE"<<std::endl;
                    }
                    break;
                }
                case 'S': {
                    std::cout<<list.size()<<std::endl;
                    break;
                }

            }
        } catch (const std::out_of_range& e) {
            std::cout << e.what() << std::endl;
        }
    }
}

