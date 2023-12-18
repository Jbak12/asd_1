
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
            Node* current_node = root;
            sub_insert(root, node_to_insert);
        }

        _size++;

    }

    void sub_insert(Node* root, Node* node_to_insert) {
        if(node_to_insert->val > root->val) {
            if(root->right == nullptr) {
                root->right = node_to_insert;
                return;
            } else {
                sub_insert(root->right,node_to_insert);
            }
        } else {
            if(root->left == nullptr) {
                root->left = node_to_insert;
                return;
            } else {
                sub_insert(root->left,node_to_insert);
            }
        }
    }

    Node* search(int x) {

    }

    Node* searchRecursive(int x) {

    }

    int minimum() {

    }

    int maximum() {
    }

    int depth() {
        return _depth;
    }

    void postorder() {

    }

    void preorder() {

    }
    void inorder() {

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