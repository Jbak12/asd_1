#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

template <class T>
void sort(std::vector<T>& v) {
    int size = v.size();
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }

        std::swap(v[minIndex], v[i]);
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
        std::ofstream results_file("Selection_results.txt", std::ios::app);
            if (!results_file.is_open()) {
                results_file.open("Selection_results.txt");
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

