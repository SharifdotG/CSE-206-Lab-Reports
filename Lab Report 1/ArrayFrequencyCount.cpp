/**
 * @file ArrayFrequencyCount.cpp
 * @author Sharif Md. Yousuf - 22101128
 * @brief Counting the frequency of each element in an array
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

    // counting the frequency of each element

    int frequency[arraySize];
    for (int i = 0; i < arraySize; i++) {
        frequency[i] = 0; // initializing the frequency array
    }
    for (int i = 0; i < arraySize; i++) {
        frequency[array[i]]++;
    }

    // printing the frequency of each element

    cout << "The frequency of each element is: " << endl;
    for (int i = 0; i < arraySize; i++) {
        if (frequency[i] != 0) {
            cout << i << " occurs " << frequency[i] << " times" << endl;
        }
    }

    return 0;
}