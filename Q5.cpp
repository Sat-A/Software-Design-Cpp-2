#include <iostream>
#include <array>
using namespace std;

template <class T, int S>
void BinarySearch(array<T, S> arr, T item){
    int size = arr.size();
    int lo = 0, hi = size - 1;
    int mid;
    while (lo <= hi){
        mid = (lo + hi) / 2;
        if (arr[mid] == item){
            cout << "Element found at index: " << mid << endl;
            return;
        } else if (arr[mid] < item){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << "Element not in array" << endl;
}

int main() {
    cout << "Integer array" << endl;
    array<int, 5> arr1 = {1, 2, 4, 5, 6};
    BinarySearch<int, 5>(arr1, 2);
    BinarySearch<int, 5>(arr1, 3);
    BinarySearch<int, 5>(arr1, 100);
    cout << endl << "Character array" << endl;
    array<char, 5> arr2 = {'a', 'b', 'c', 'd', 'f'};
    BinarySearch<char, 5>(arr2, 'a');
    BinarySearch<char, 5>(arr2, 'e');
    BinarySearch<char, 5>(arr2, 'z');
}