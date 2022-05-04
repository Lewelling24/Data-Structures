#include <iostream>
#include "Array.h"

using namespace std;

template <class T>
void displayArr(const Array<T> & arr) {
    for (int i = 0; i < arr.length(); ++i) { // loop through array and display contents
        cout << arr[i] << ", ";
    }
    cout << endl;
}

template <class T>
void fn(Array<T> b) {
    Array<int> a(2);
    b[0] = 12;
}


int main()
{
    Array<int> arr(5);
    arr[0] = 10; arr[1] = 20; arr[2] = 30;
    displayArr(arr);
    cout << "fn to be called" << endl;
    fn(arr);
    displayArr(arr);

    Array<int> arr3 = arr;

    Array<int> arr2(2);
    arr2 = arr;
    displayArr(arr2);

    arr2[0] = 11;

    displayArr(arr2);
    displayArr(arr);

    return 0;
}
