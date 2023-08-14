/
// Created by eduar on 24/02/2023.
//

#ifndef CPP_ARRAYLIST_H
#define CPP_ARRAYLIST_H

#include <bits/stdc++.h>
#include <vector>

template <class T>
class ArrayList {
public:
    ArrayList();
    ArrayList(std::initializer_list<ArrayList<T>>);

    ~ArrayList();

    T& operator[](size_t);

    ArrayList<T>& copy();
    size_t size();
    size_t maxSize();
    void append(T& item);
    void insert(T& item);
    void insert(T& item, size_t pos);
    T& pop();
    T& pop(size_t pos);
    
private:
    T* m_arr;
    size_t m_len;
};

template<class T>
ArrayList<T>::ArrayList() {
    m_arr = new T[10];
    m_arr[0] = 32;
}

template<class T>
ArrayList<T>::ArrayList(std::initializer_list<ArrayList<T>> initial) {

}

template<class T>
ArrayList<T>::~ArrayList() {

}

template<class T>
T& ArrayList<T>::operator[](size_t pos) {
    return m_arr[pos];
}

template<class T>
ArrayList<T>& ArrayList<T>::copy() {
    return nullptr;
}

template<class T>
size_t ArrayList<T>::size() {
    return m_len;
}

template<class T>
size_t ArrayList<T>::maxSize() {
    return 0;
}

template<class T>
void ArrayList<T>::append(T &item) {

}

template<class T>
void ArrayList<T>::insert(T &item) {

}

template<class T>
void ArrayList<T>::insert(T &item, size_t pos) {

}

template<class T>
T& ArrayList<T>::pop() {
    m_len--;
    std::unique_ptr<T> ret(new T(m_arr[m_len]));
//    delete m_arr[m_len];
    return *ret;
}

template<class T>
T& ArrayList<T>::pop(size_t pos) {
    return nullptr;
}

#endif //CPP_ARRAYLIST_H
