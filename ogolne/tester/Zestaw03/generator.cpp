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
        int operationType = rand() % 6; 

        switch (operationType) {
            case 0:
                cout << "F " << rand() % 1000 << endl; 
                break;
            case 1:
                cout << "B " << rand() % 1000 << endl; 
                break;
            case 2:
                cout << "f" << endl; 
                break;
            case 3:
                cout << "b" << endl; 
                break;
            case 4:
                cout<< "S" <<endl;
            case 5:
                cout<< "R " <<rand() % 1000<< " " <<rand()%1000 <<endl;

        }
    }

    return 0;
}
