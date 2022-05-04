#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <iostream>
using namespace std;

template <class T>
class Array {
public:
	Array(int size);
	void changeSize(int newSize);
	T & operator [](int index) const { return els[index]; }
	int length() const { return capacity; }

	Array<T> & operator = (const Array<T> & rhs);
	Array(const Array<T> & rhs);
	~Array() { cout << "destructor" << endl; delete [] els; }
private:
	T * els;
	int capacity;
	void deepCopy(const Array<T> & rhs);
	int errCode;
};

template <class T>
Array<T>::Array(int size){
    cout << "constructor" << endl;
    if(size < 1) {size = 1; errCode = 1;}
    capacity = size;
    els = new T[size];
}
template <class T>
void Array<T>::changeSize(int newSize) {
    if (newSize < 1) {
        errCode = errCode | 2;
        return;
    }
    int howMany;
    if (newSize > capacity) howMany = capacity;
    else howMany = newSize;
    T * temp = new T[newSize];
    for (int i = 0; i < howMany; i++) {
        temp[i] = els[i];
    }
    delete [] els;
    els = temp;
    capacity = newSize;
}

template <class T>
Array<T> & Array<T>::operator = (const Array<T> & rhs) {
    cout << "assignment operator" << endl;
    // this -- address of the calling object
    // & rhs -- address of rhs
    if (this == & rhs) {
        return *this;
    }
    // free up space used by lhs in heap
    delete [] els;
    deepCopy(rhs);
    return *this;
}

template <class T>
Array<T>::Array(const Array<T> & rhs) {
    cout << "copy constructor" << endl;
    deepCopy(rhs);
}

template <class T>
void Array<T>::deepCopy(const Array<T> & rhs) {
    // allocate space in heap for lhs
    els = new T[rhs.capacity];
    for (int i = 0; i < rhs.capacity; i++) {
        els[i] = rhs.els[i];
    }
     capacity = rhs.capacity;
}

#endif // ARRAY_H_INCLUDED







