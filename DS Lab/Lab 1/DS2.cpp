#include <iostream>
using namespace std;

void printArray(int a[], int size){
    for (int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void insert(int a[], int &size, int index, int e){
    int shifts = size - index;
    for (int i = 0; i < shifts; i++){
        a[size - i] = a[size - i - 1];

    //printArray(a, size+1);
    }

    a[index] = e;

    size++;
}



int main() {
    int a[50];
    //int a[50] = {1, 2, 3, 4, 5};

    int size = 20;
    int index;
    int element;
    for (int i = 0; i  < size; i++){
        cout << "Enter element at index " << i << ":";
        cin >> a[i];
    }
    cout << "Given array: ";
    printArray(a, size);

    cout << "At which position you have to insert element: ";
    cin >> index;
    cout << "Which number you have to insert: ";
    cin >> element;


    insert(a, size, index, element);

    printArray(a, size);

    return 0;
}

