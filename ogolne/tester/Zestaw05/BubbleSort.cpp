#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

template <class T>
void sort(std::vector<T>& v) {
    int size_ = v.size();
    for (int i = 0; i < size_-1; ++i) {
        for (int j = 0; j < size_-i-1; ++j) {
            if (v[j] > v[j+1]) {
                std::swap(v[j], v[j+1]);
            }
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

    auto time_ = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    if (argc > 1 && std::string(argv[1]) == "measure_mode") {
        std::ofstream results_file("Bubble_sort_results.txt", std::ios::app);
            if (!results_file.is_open()) {
                results_file.open("Bubble_sort_results.txt");
                // results_file << "Size,Time (ms)\n";  
            }

        results_file << v.size() << "," << time_.count() << "\n";
        results_file.close();
        return 0;
    }
    for(const auto& i : v) {
        std::cout << i << std::endl;
    }


    return 0;
}
