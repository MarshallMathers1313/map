#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

template <class T>
class BNode {
public:
    const T& operator*() const;
    T& operator*();
};

template <typename T>
class BinarySearchTree {
private:
    
public:
    typedef BNode* iterator;

    BinarySearchTree();
    ~BinarySearchTree();

    BinarySearchTree(const BinarySearchTree &other);
    BinarySearchTree &operator=(const BinarySearchTree &other);

    void insert(const T &value);
    size_t erase(const iterator it);

    void clear();

    const iterator operator++() const;
    iterator operator++() ;

    const iterator operator--() const;
    iterator operator--();

    size_t size() const;
    bool empty() const;

    const iterator cbegin() const;
    iterator begin();

    const iterator cend() const;
    iterator end();
};

#endif // __BINARY_SEARCH_TREE__
