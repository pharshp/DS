#include <iostream>
using namespace std;

void printArray(int a[], int size){
    for (int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void del(int a[], int &size, int index){
    //int shifts = size - index - 1;

    for (int i = index; i < size; i++){
        a[i] = a[i + 1];

    //printArray(a, size+1);
    }

    size--;
}



int main() {
    int a[50];
    //int a[50] = {1, 2, 3, 4, 5};

    int size = 20;
    int index;
    for (int i = 0; i  < size; i++){
        cout << "Enter element at index " << i << ":";
        cin >> a[i];
    }
    //printArray(a, size);
    cout << "Given array: ";
    printArray(a, size);

    cout << "Index of element which you have to delete: ";
    cin >> index;


    del(a, size, index);

    printArray(a, size);

    return 0;
}


