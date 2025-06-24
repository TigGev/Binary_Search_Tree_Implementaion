#ifndef BINARY_SEARCH_TREE_HEADER
#define BINARY_SEARCH_TREE_HEADER

template <class T>
class Node {
    public:
        T data;
        Node* left;
        Node* right;

        Node(T& val) : data(val) left(nullptr), right(nullptr) {};
        // Node(T& val, Node* l = nullptr, Node* r = nullptr) : data(val), left(l), right(r) {}
};

template <class T>
class binarySearchTree {
    public:
        binarySearchTree() : root(nullptr) {};
        binarySearchTree(const binarySearchTree& ohter);
        binarySearchTree(binarySearchTree&& other) noexcept;
        binarySearchTree& operator=(const binarySearchTree& other);
        binarySearchTree& operator=(binarySearchTree&& other) noexcept;

        void insert(T val);
        void delete(T val);
        bool search(T val) const;
        T getPredecessor() const;
        T getSuccessor() const;
        size_t getHeight() const;
        void traverse() const;
    private:
        Node* root;

        void copyHelper(Node* thisNode, Node* otherNode) {
            if (otherNode == nullptr) return;
            thisNode = new Node(otherNode->data);
            copyHelper(thisNode->left, otherNode->left);
            copyHelper(thisNode->right, otherNode->right);
        };

};

#endif