#include <iostream>
class BinaryTree {
    public:
    struct Node {
        int val;
        Node* right;
        Node* left;
        Node(int val): val(val), left(nullptr),right(nullptr) {}
    };

    BinaryTree(): _size(0), _depth(0){}

    void insert(int x) {
        Node* node_to_insert = new Node(x);
        int current_depth = 0;
        if(_size == 0) {
            root = node_to_insert;
        } else {
            current_depth++;
            insert(root, node_to_insert);
        }

        _size++;

    }

    void insert(Node* root, Node* node_to_insert) {
        if(node_to_insert->val >= root->val) {
            if(root->right == nullptr) {
                root->right = node_to_insert;
                return;
            } else {
                insert(root->right,node_to_insert);
            }
        } else if(node_to_insert->val < root->val)  {
            if(root->left == nullptr) {
                root->left = node_to_insert;
                return;
            } else {
                insert(root->left,node_to_insert);
            }
        }
    }

    Node* search(int x) {
        auto node = root;
        while(!(node == nullptr || x == node-> val)) {
            if(x < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return node;
    }

    

    Node* searchRecursive(int x) {

    }

    int minimum() {
        auto node = root;
        while(node->left != nullptr) {
            node = node->left;
        }
        return node->val;
    }

    int maximum() {
        auto node = root;
        while(node->right != nullptr) {
            node = node->right;
        }
        return node->val;
    }

    int depth() {
        return _depth;
    }

    void postorder() {

    }

    void preorder() {

    }
    void inorder() {
        inorder(root);
    }

    void postorder(Node* node) {
        if (node!= nullptr) {
            inorder(node->left);
            std::cout<<node->val<<std::endl;
            inorder(node->right);

        }
    }

    void preorder(Node* node) {
        if (node!= nullptr) {
            inorder(node->left);
            std::cout<<node->val<<std::endl;
            inorder(node->right);

        }
    }

    void inorder(Node* node) {
        if (node!= nullptr) {
            inorder(node->left);
            std::cout<<node->val<<std::endl;
            inorder(node->right);

        }
    }


    int size();



    private:
    Node* root;
    int _size;
    int _depth;

    // void sub_insert(Node* root, int x) {
    //     if();
    // }


};