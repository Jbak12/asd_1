#include <iostream>
#include <vector>
#include "LinkedQueue.hpp"

int countDigits(int number) {
    return floor(log10(number) + 1);  

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

        moduler_divider = moduler_divider*10;
        v = {};

        for(int i = 0; i<10; i++) {
            while(!queues[i].empty()) {
                v.push_back(queues[i].pop());
            }
        }
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