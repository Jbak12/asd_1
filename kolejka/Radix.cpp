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
    std::vector<int> wektorek = {0,4444343,1,24,14,344442,55,10,100,19};
    radix(wektorek);
    for (const int& num : wektorek){
        std::cout<<num<<std::endl;
    }
    LinkedQueue<int> queues[10];
    int x = 13%1;
    queues[2].push(19);
    // std::cout<<"element z kolejki nr 3 "<<queues[2].pop()<<std::endl;
    std::cout<<"maksymalna liczba cyfr w wektorku to "<< countDigits(*std::max_element(wektorek.begin(),wektorek.end()))<<std::endl;
    std::cout<<"10mod10: "<<x<<std::endl;
    std::cout<<"czy jest pusta: "<<(queues[2].empty() ? "pusta jest" : "cos tam jest" )<<std::endl;

}