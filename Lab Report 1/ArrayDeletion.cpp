/**
 * @file ArrayDeletion.cpp
 * @author Sharif Md. Yousuf - 22101128
 * @brief Deleting an element in an array
 * @date 2023-08-04
 * 
 * @copyright Sharif Md. Yousuf
 * 
 */

#include <iostream>

using namespace std;

int main() {
    int arraySize;
    cout << "Enter the size of the array: ";
    cin >> arraySize;

    // taking array elements as input

    int array[arraySize];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < arraySize; i++) {
        cin >> array[i];
    }

    // taking the position of the element to be deleted as input

    int position;
    cout << "Enter the position of the element to be deleted: ";
    cin >> position;

    // shifting the elements to the left

    for (int i = position; i < arraySize - 1; i++) {
        array[i] = array[i + 1];
    }

    // printing the array

    cout << "The array after deletion is: ";
    for (int i = 0; i < arraySize - 1; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}