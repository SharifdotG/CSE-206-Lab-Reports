/**
 * @file ArrayInsertion.cpp
 * @author Sharif Md. Yousuf - 22101128
 * @brief Inserting an element in an array
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

    // taking the element to be inserted as input

    int element;
    cout << "Enter the element to be inserted: ";
    cin >> element;

    // taking the position of the element to be inserted as input

    int position;
    cout << "Enter the position of the element to be inserted: ";
    cin >> position;

    // shifting the elements to the right

    for (int i = arraySize - 1; i >= position; i--) {
        array[i + 1] = array[i];
    }

    // inserting the element

    array[position] = element;

    // printing the array

    cout << "The array after insertion is: ";
    for (int i = 0; i <= arraySize; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}