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
    
}

template <class T>
template <class T>
template <class T>