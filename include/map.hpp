#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "bst.hpp"

template <class K, class V>
class Map {
public:
    typedef BinarySearchTree<std::pair<K,V>>::iterator iterator;
    
    Map();
    Map(const std::initializer_list<std::pair<K, V>> &pairs);
    ~Map();

    Map(const map<K, V> &other);
    operator=(const map<K, V> &other);

    const V& operator[](const K &key) const;
    V& operator[](const K &key);

    const V& at(const K &key) const;
    V& at(const K &key);

    std::pair<iterator, bool> insert(const std::pair<K, V> &value); 
    size_t erase(const K &key);
    void clear();

    size_t size() const;
    bool empty() const;

    size_t count(const K &key) const;
    const iterator find(const K &key) const;
    iterator find(const K &key);

    const iterator cbegin() const;
    iterator begin();
    
    const iterator cend() const;
    iterator end();

    friend void swap(Map<K, V> &first, Map<K, V> &second);
};

#endif //__MAP_HPP__
