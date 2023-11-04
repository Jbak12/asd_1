#include <iostream>
#include <vector>
#include "LinkedQueue.hpp"

int countDigits(int number) {
    return (number < 10) ? 1 : 1 + countDigits(number / 10);
}
void radix(std::vector<int>& v) {
    int moduler_divider = 1;
    int index_to_push;
    int max_num_of_digits = countDigits(*std::max_element(v.begin(),v.end()));
    LinkedQueue<int>* queues = new LinkedQueue<int>[10];
    for(int i = 0; i < max_num_of_digits; i++) {
        for(const int& number : v){
            index_to_push = (number%(moduler_divider*10)-number%moduler_divider)/moduler_divider;
            queues[index_to_push].push(number);
        }
        for(int i = 0; i< 10; i++) {
            std::cout<<"kolejka nr "<<i<<": ";
            (queues[i].printAll());
        }

        moduler_divider = moduler_divider*10;
        
        v = {};
        for(int i = 0; i<10; i++) {
            while(!queues[i].empty()) {
                v.push_back(queues[i].pop());
            }
        }
            std::cout<< "i jeszcze raz ; )"<<std::endl;
    }
    delete[] queues;
}

int main() {
    int x;
    std::vector<int> v;
    while(std::cin >> x)
        v.push_back(x);
    radix(v);
    for (const int& num : v){
        std::cout<<num<<std::endl;
    }
}