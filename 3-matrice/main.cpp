#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "rows, cols:";
    cin >> rows >> cols;
    
    int** arr = new int*[rows];
    for(int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
        for(int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < rows; i++){
        delete[] arr[i];
    }

    delete[] arr;
    arr = NULL;

    return 0;
}