#include<iostream>
#include<ctime>
using namespace std;
int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);
	int max = atoi(argv[2]);
	for(int i = 0; i < atoi(argv[1]); i++){
		cout << rand() % atoi(argv[2]) << endl;
	}
}
