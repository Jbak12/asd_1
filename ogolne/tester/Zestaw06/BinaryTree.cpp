#include<iostream>
#include "BinaryTree.hpp"
int main() {
    int n;
    std::cin>>n;
    BinaryTree tree = BinaryTree();
    while(n--) {
        int x;
        std::cin>>x;
        tree.insert(x);
    }

    std::cout   <<tree.size() << " " 
                << tree.depth() << " "
                << tree.minimum() << " "
                << tree.maximum() 
                << std::endl;

    // std::cout<<"TRAVERSE"<<std::endl;    
    tree.preorder();

    for(int i = 1; i<=9;i++) {
        std::string output_string = (tree.search(i) != nullptr) ? "Yes" : "No";
        std::cout<<output_string<<std::endl;

    }
}