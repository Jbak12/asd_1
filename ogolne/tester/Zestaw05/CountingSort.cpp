#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

void sort(std::vector<int>& v) {
    if (v.empty()) {
        return;
    }

    int max = *std::max_element(v.begin(), v.end());

    std::vector<int> count(max + 1, 0);

    for (int value : v) {
        count[value]++;
    }

    int index = 0;
    for (int i = 0; i <= max; ++i) {
        while (count[i] > 0) {
            v[index] = i;
            index++;
            count[i]--;
        }
    }
}


int main(int argc, char *argv[]) {
    std::vector<int> v;
    int num;
    while (std::cin >> num) {
        v.push_back(num);
    }

    auto start_time = std::chrono::high_resolution_clock::now();
    sort(v);
    auto end_time = std::chrono::high_resolution_clock::now();

    auto time_ = std::chrono::duration<double>(end_time - start_time);

    if (argc > 1 && std::string(argv[1]) == "measure_mode") {
        std::ofstream results_file("Counting_sort_results.txt", std::ios::app);
            if (!results_file.is_open()) {
                results_file.open("Counting_sort_results.txt");
                // results_file << "Size,Time (ms)\n";  
            }

        results_file << v.size() << " " << time_.count() << "\n";
        results_file.close();
        return 0;
    }
    for(const auto& i : v) {
        std::cout << i << std::endl;
    }


    return 0;
}