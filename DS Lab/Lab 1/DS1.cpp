/*
1) Create an array of size 50 which can take int values and fill it with elements minimum 20 in number.

WAP to traverse the array while printing all its elements in row 

Insert an element in an array at a given index 

WAP to delete an element when its index is given

WAP to search an element in the array
*/

#include <iostream>
using namespace std;

int main() {
    int a[50];
    int size = 20;

    for (int i = 0; i  < size; i++){
        cout << "Enter element at index " << i << ":";
        cin >> a[i];
    }

    cout << "Given array: ";
    for (int i = 0; i < size; i++){
        cout << a[i] << " ";
    }

    return 0;
}
