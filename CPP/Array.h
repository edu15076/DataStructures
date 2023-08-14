//
// Created by eduar on 21/02/2023.
//

#ifndef CPP_ARRAY_H
#define CPP_ARRAY_H

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Array {
private:
    vector<T>& mVec;
    int b;

public:
    explicit Array(size_t size, const vector<T>& = vector<T>());
    ~Array();

    size_t size() const;
    void resize(size_t);
    vector<T> toVector() const;
    Array<T> copy() const;

    T& operator[](size_t) const;
    Array<T> operator()(const size_t, const size_t) const;
    Array<T> operator+(const Array<T>&) const;
    void operator+=(const Array<T>&);
    bool operator==(const Array<T>&) const;
    void operator<<(const size_t);
    void operator>>(const size_t);
};

template <class T>
size_t Array<T>::size() const { return mVec.size(); }

template <class T>
void Array<T>::resize(size_t size) { mVec.resize(size); }

template <class T>
vector<T> Array<T>::toVector() const {
    vector<T> v = mVec;
    return v;
}

template <class T>
Array<T> Array<T>::copy() const {
    Array<T> array_cpy(size(), mVec);
    return array_cpy;
}

template <class T>
T& Array<T>::operator[](size_t index) const {
    if (index >= size())
        throw std::invalid_argument("Position out of range.");

    return mVec[index];
}

template <class T>
Array<T> Array<T>::operator()(const size_t start, const size_t end) const {
    if (start > end)
        throw invalid_argument("Start cannot be greater than end.");

    if (end >= size())
        throw invalid_argument("Invalid position.");

    size_t size = end - start + 1;

    vector<T> a(size);
    for (int i = 0; i < size; i++)
        a[i] = mVec[i + start];

    Array<T> array(size, a);
    return array;
}

template <class T>
Array<T> Array<T>::operator+(const Array<T>& summed) const {
    size_t size = summed.size() + mVec.size();
    Array<T> array(size, mVec);
    for (int i = mVec.size(); i < size; i++)
        array[i] = summed[i - mVec.size()];

    return array;
}

template <class T>
void Array<T>::operator+=(const Array<T>& summed) {
    size_t previous_size = mVec.size();
    resize(mVec.size() + summed.size());
    for (int i = 0; i < summed.size(); i++)
        mVec[i + previous_size] = summed[i];
}

template <class T>
bool Array<T>::operator==(const Array<T>& eq) const {
    if (size() != eq.size())
        return false;

    for (int i = 0; i < mVec.size(); i++)
        if (mVec[i] != eq[i])
            return false;
    return true;
}

template <class T>
void Array<T>::operator<<(const size_t end) {
    if (end >= size())
        throw invalid_argument("Invalid position.");

    for (size_t i = 0; i < end; i++)
        mVec[i] = mVec[i + 1];
}

template <class T>
void Array<T>::operator>>(const size_t start) {
    if (start >= size())
        throw invalid_argument("Invalid position.");

    for (size_t i = mVec.size() - 1; i > start; i--)
        mVec[i] = mVec[i - 1];
}

template <class T>
Array<T>::Array(const size_t size, const vector<T>& init) : mVec(*(new vector<T>(size))) {
    if (!init.size())
        return;

    for (size_t i = 0; i < size; i++)
        mVec[i] = init[i];
}

template <class T>
Array<T>::~Array() {
    delete &mVec;
}

#endif //CPP_ARRAY_H
