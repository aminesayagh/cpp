#include <iostream>
using namespace std;
using std::string;

int main () {
    int size;
    cout << "Size: ";
    cin >> size;
    int *arr = new int[size];
    cout << "\nEnter Array Elements: ";
    for (int i = 0; i < size; i++) {
        cout << "array[" << i << "]";
        cin >> arr[i];
    }

    for(int i = 0; i < size; i++) {
        cout << *(arr+i) << " ";
    }

    delete[]arr;
    arr = NULL;
    return 0;
}