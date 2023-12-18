#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

template <class T>
void sort(std::vector<T>& v) {
    int size_ = v.size();
    for (int i = 1; i < size_; ++i) {
        T key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            --j;
        }

        v[j + 1] = key;
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

    std::chrono::duration<double> time_ = (end_time - start_time);

    if (argc > 1 && std::string(argv[1]) == "measure_mode") {
        std::ofstream results_file("Insertion_sort_results.txt", std::ios::app);
            if (!results_file.is_open()) {
                results_file.open("Insertion_sort_results.txt");
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

