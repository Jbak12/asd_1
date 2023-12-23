#include <iostream>
#include <queue>
#include<stack>
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
        if(_size == 0) {
            root = node_to_insert;
        } else {
            Node* current_node = root;
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
        } else {
            if(root->left == nullptr) {
                root->left = node_to_insert;
                return;
            } else {
                insert(root->left,node_to_insert);
            }

        }
    }


    Node* search(int x) {
        Node* currentNode = root;
        while(currentNode != nullptr && currentNode->val != x){
            if(currentNode->val>x) {
                currentNode = currentNode->left;
            } else {
                currentNode = currentNode->right;
            }
        }
        return currentNode;
    }

    Node* searchRecursive(int x) {
        return searchRecursive(root,x);
    }

    Node* searchRecursive(Node* node, int x) {
        if (node == nullptr or x == node->val) {
            return node;
        }
        if (x < node->val) {
            return searchRecursive(node->left, x);
        } else {
            return searchRecursive(node->right, x);
        }
    }

    int maximum() {
        auto node = root;
        while(node->right!=nullptr) {
            node = node->right;
        }
        return node->val;
    }

    int minimum() {
        auto node = root;
        while(node->left != nullptr) {
            node = node->left;
        }
        return node->val;
    }

    int depth() {
        if (root == nullptr) {
            return 0;
        }
        std::queue<Node*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            int level_size = q.size();

            for (int i = 0; i < level_size; i++) {
                Node* current_node = q.front();
                q.pop();

                if (current_node->right != nullptr) {
                    q.push(current_node->right);
                }

                if (current_node->left != nullptr) {
                    q.push(current_node->left);
                }
            }
            depth++;
        }

        return depth;
    }

     void iterativeInorder() {

        if (root == nullptr) {
            return;
        }
        std::stack<Node*> nodes_stack;
        Node* current = root;

        while (!(current == nullptr && nodes_stack.empty())) {
            
            while (current != nullptr) {
                nodes_stack.push(current);
                current = current->left;
            }

            current = nodes_stack.top();
            std::cout << current->val << std::endl;

            nodes_stack.pop();
            current = current->right;
        }
    }

    void postorder() {
        postorder(root);
    }

    void preorder() {
        preorder(root);
    }

    void inorder() {
        iterativeInorder();
    }

    int size() {
        return _size;
    }

    private:
    Node* root;
    int _size;
    int _depth;

    void postorder(Node* node) {
        if (node!= nullptr) {
            postorder(node->left);
            postorder(node->right);
            std::cout<<node->val<<std::endl;

        }
    }

    void preorder(Node* node) {
        if (node!= nullptr) {
            std::cout<<node->val<<std::endl;
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(Node* node) {
        if (node!= nullptr) {
            inorder(node->left);
            std::cout<<node->val<<std::endl;
            inorder(node->right);
        }
    }


};