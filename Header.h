#ifndef BINARY_SEARCH_TREE_HEADER
#define BINARY_SEARCH_TREE_HEADER

template <class T>
class Node {
    public:
        T data;
        Node* left;
        Node* right;

        Node(T& val) : data(val) left(nullptr), right(nullptr) {};
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
        void delete_(T val);
        bool search(T val) const;

        Node<T>* getMin();
        Node<T>* getMax();
        Node<T>* getPredecessor(Node<T>* node) const;
        Node<T>* getSuccessor(Node<T>* node) const;
        int getHeight() const;
        void inorderedTraverse(Node<T>* root = this->root) const;
        void preorderTraverse(Node<T>* root = this->root) const;
        void postorderTraverse(Node<T>* root = this->root) const;

    private:

        Node<T>* root;

        int getBalanceFactor(Node* root) const {
            return getHeight(root->left) - getHeight(root->right);
        }

        Node* rightRotate(Node* node) {
            Node* y = root->left;
            root->left = y->right;
            y->right = root;
            return y;
        }

        Node* leftRotate(Node* root) {
            Node* y = root->right;
            root->right = y->left;
            y->left = root;
            return y;
        }

        void copyHelper(Node* thisNode, Node* otherNode) {
            if (otherNode == nullptr) return;
            thisNode = new Node(otherNode->data);
            copyHelper(thisNode->left, otherNode->left);
            copyHelper(thisNode->right, otherNode->right);
        }

        bool searchHelper(Node* root, T val) const {
            if (!root) return false;
            if (root->data == val) return true;
            return searchHeper(root->next, val);
        }

        Node<T>* getMinHelper(Node* root) {
            if(!root) return nullptr;
            if (!root->left) return root;
            return getMinHelper(root->left);
        }

        Node<T>* getMaxHelper(Node<T>* root) {
            if(!root) return nullptr;
            if (!root->right) return root;
            return getMinHelper(root->right);
        }

        int getHeightHelper(Node<T>* root) {
           if (!root) return -1;
           return std::max( getHeightHelper(root->left), getHeightHelper(root->right)) + 1;
        }

        Node<T>* insertHelper(Node<T>* root, T val) {
            if (!root) return new Node(val);
            if (val < root->val) root->left = insertHelper(root->left, val);
            else root->right = insertHelper(root->right, val);

            int bf = getBalanceFactor(root);
            if (bf > 1 && root->left->data > val) {
                return rightRotate(root); //LL
            }
            if (bf > 1 && root->left->data < val) {
                root->left = leftRotate(root->left);
                return rightRotate(root); //LR
            }
            if (bf < -1 && root->right->data > val) {
                return leftRotate(root);
            }
            if (bf < -1 && root->right->data > val) {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
            return root;
        }

        Node<T>* delete_Helper(Node<T>* root, T key) {
            if (!root) return nullptr;
            if (key < root->val) root->left = delete_Helper(root->left, key);
            else if (key > root->val) root->right = delete_Helper(root->right, key);
            else {
                if (!root->right) {
                    Node* tmp = root->left;
                    delete root;
                    return tmp;
                }
                if (!root->left) {
                    Node* tmp = root->right;
                    delete root;
                    return tmp;
                }
                    Node* tmp = getMin();
                    root->val = tmp->val;
                    delete_Helper(root->right, tmp->key);
            }
            int bf = getBalanceFactor(root);
            if (bf > 1 && getBalanceFactor(root->left) >= 0) {
                return rightRotate(root);
            }
            if (bf > 1 && getBalanceFactor(root->left) < 0) {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            if (bf < -1 && getBalanceFactor(root->right) <= 0) {
                return leftRotate(root);
            }
            if (bf < -1 && getBalanceFactor(root->right) > 0) {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
            return root;
        }
};

#endif