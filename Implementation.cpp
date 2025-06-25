#include <Header.h>


template <class T>
binarySearchTree<T>::binarySearchTree(const binarySearchTree<T>& ohter) : copyHelper(this->root, other.root) {}

template <class T>
binarySearchTree<T>::binarySearchTree(binarySearchTree<T>&& other) noexcept : root(std::move(other.root)) {}

template <class T>
binarySearchTree<T>& binarySearchTree<T>::operator=(const binarySearchTree<T>& other) {copyHelper(root, other.root);}

template <class T>
binarySearchTree<T>& binarySearchTree<T>::operator=(binarySearchTree<T>&& other) noexcept {root = std::move(other.move);}

template <class T>
bool binarySearchTree<T>::search(T val) const {
    return searchHelper(this->root, val);
}

template <class T>
Node<T>* binarySearchTree<T>::getMin() {
    return getMinHelper(this->root);
}

template <class T>
Node<T>* binarySearchTree<T>::getMax() {
    return getMaxHelper(this->root);
}

template <class T>
Node<T>* binarySearchTree<T>::getPredecessor(Node<T>* node) const {
    return getMaxHelper(root->left);
}

template <class T>
Node<T>* binarySearchTree<T>::getSuccessor(Node<T>* node) const {
    return getMinHelper(root->right);
}

template <class T>
int binarySearchTree<T>::getHeight() const {
    return getHightHelper(this->root);
}

template <class T>
void binarySearchTree<T>::insert(T val) {
    root = insertHelper(this->root, val);
}

template <class T>
void binarySearchTree<T>::delete_(T val) {
    if (!root) return nullptr;
    
}
