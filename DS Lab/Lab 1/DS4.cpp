#include <iostream>
using namespace std;

void printArray(int a[], int size){
    for (int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int searchElement(int a[], int &size, int e){

    for (int i = 0; i < size; i++){
        if (a[i] == e){
            cout << "First occurrence of Element is at index " << i << " of array" << endl;
            return 0;
        }
    }
    cout << "Element is not present in array" << endl;

}



int main() {
    int a[50];
    //int a[50] = {1, 2, 3, 4, 5};

    int size = 20;
    int element = 6;
    for (int i = 0; i  < size; i++){
        cout << "Enter element at index " << i << ":";
        cin >> a[i];
    }
    cout << "Given array: ";
    printArray(a, size);

    cout << "Which element you have to search: ";
    cin >> element;

    searchElement(a, size, element);


    return 0;
}


