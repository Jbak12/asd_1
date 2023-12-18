#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

template <class T>
void sort(std::vector<T>& v) {
    if (v.empty()) {
        return;
    }

    T maxElement = *std::max_element(v.begin(), v.end());
    T minElement = *std::min_element(v.begin(), v.end());

    // Create a count array to store the count of each element
    std::vector<T> count(maxElement - minElement + 1, 0);

    // Count the occurrences of each element in the input vector
    for (const T& elem : v) {
        count[elem - minElement]++;
    }

    // Update the input vector with sorted elements
    size_t index = 0;
    for (T i = minElement; i <= maxElement; ++i) {
        while (count[i - minElement] > 0) {
            v[index++] = i;
            count[i - minElement]--;
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