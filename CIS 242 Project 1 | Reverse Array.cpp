// Project 1 - Reverse Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Mao Bergan
// CIS 242
// Due Date: Sep 4th, 2024

/* Write a function that accepts an int array and the array's size as arguments. 
The function should create a copy of the array, except that the element values should be reversed in the copy.
The Function should return a pointer to the new array. Demonstrate the function in a complete program. */

#include <iostream>

// prototypes
void populateArray(int& arraySize, int* array);
void displayArray(int& arraySize, int* array, int* reverseArray);
void populateReverseArray(int& arraySize, int* array, int* reverseArray);

int main() {
    const int size = 20;
    int array[size];
    int reverseArray[size];

    // prompt user to specify array size.
    std::cout << "Welcome to the Reverse Array Program!\n";
    std::cout << "How large would you like the array? (1/20): ";
    int arraySize;
    std::cin >> arraySize;
    
    populateArray(arraySize, array);
    populateReverseArray(arraySize, array, reverseArray);
    displayArray(arraySize, array, reverseArray);

    return 0;
}

void populateArray(int& arraySize, int* array) {
    for (int i = 0; i < arraySize; i++) {
        // prompt user to enter number to store in array untill it reaches users specified limit.
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> array[i]; 
    }
}

void displayArray(int& arraySize, int* array, int* reverseArray) {
    for (int i = 0; i < arraySize; i++) {
        // display both original and reverse array side by side.
        std::cout << "Initial element " << i + 1 << ": " << array[i] << "\t"; 
        std::cout << "Reverse element " << i + 1 << ": " << reverseArray[i] << std::endl;
    }
}

void populateReverseArray(int& arraySize, int* array, int* reverseArray) {
    // store original array values backwards in new array.
    for (int i = 0; i < arraySize; i++) {
        reverseArray[i] = array[(arraySize - 1) - i];
    }
}
