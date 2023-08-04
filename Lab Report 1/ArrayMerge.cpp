/**
 * @file ArrayMerge.cpp
 * @author Sharif Md. Yousuf - 22101128
 * @brief Merging two arrays into one
 * @date 2023-08-04
 * 
 * @copyright Sharif Md. Yousuf
 * 
 */

#include <iostream>

using namespace std;

int main() {
    int arraySize1;
    cout << "Enter the size of the first array: ";
    cin >> arraySize1;

    // taking array elements as input

    int array1[arraySize1];
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < arraySize1; i++) {
        cin >> array1[i];
    }

    int arraySize2;
    cout << "Enter the size of the second array: ";
    cin >> arraySize2;

    // taking array elements as input

    int array2[arraySize2];
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < arraySize2; i++) {
        cin >> array2[i];
    }

    // merging the arrays

    int arraySize3 = arraySize1 + arraySize2;
    int array3[arraySize3];
    for (int i = 0; i < arraySize1; i++) {
        array3[i] = array1[i]; // copying the elements of the first array
    }
    for (int i = 0; i < arraySize2; i++) {
        array3[arraySize1 + i] = array2[i]; // copying the elements of the second array
    }

    // printing the array

    cout << "The merged array is: ";
    for (int i = 0; i < arraySize3; i++) {
        cout << array3[i] << " ";
    }
    cout << endl;

    return 0;
}