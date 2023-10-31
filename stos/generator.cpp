#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define OPERATIONS 1000000
int main() {
    srand(time(nullptr));

    int n = rand() % OPERATIONS; 
    cout << n << endl; 

    for (int i = 0; i < n; i++) {
        int operationType = rand() % 3; 

        switch (operationType) {
            case 0:
                cout << "A " << rand() % 1000000 << endl; 
                break;
            case 1:
                cout << "D" << endl; 
                break;
            case 2:
                cout << "S" << endl; 
                break;
        }
    }

    return 0;
}
