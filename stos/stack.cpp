#include <iostream>
#include "ArrayStack.hpp"
#include <stdexcept>
#include "LinkedStack.hpp"

using namespace std;

int main() {
    int operations;

    cin >> operations;

    ArrayStack<int, 1000000> stack;

    for (int i = 0; i < operations; ++i) {
        char input;
        cin >> input;

        try {
            switch (input) {
                case 'A':
                    int value;
                    cin >> value;
                    stack.push(value);
                    break;
                case 'D':  
                    cout << stack.pop() << endl;
                    break;
                case 'S':  
                    cout << stack.size() << endl;
                    break;
                default:
                    cout << "zle dane" << endl;
            }
        } catch (const std::out_of_range& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}