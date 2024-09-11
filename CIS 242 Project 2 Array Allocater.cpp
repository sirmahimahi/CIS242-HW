// CIS 242 Project 2 Array Allocator.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Mao Bergan
// CIS 242
// Due Date: Sep 8th, 2024

/* Write a function that dynamically allocates an array of integers. 
The function should accept an integer argument indicating the number of elements to allocate. 
The function should return a pointer to the array. */

#include <iostream>
#include <limits> // allows use of numeric.limits.

// prototypes
int* createArray(int arraySize);
void fillArray(int* array, int arraySize);
void displayArray(int* array, int arraySize);

int main() {
    int arraySize;
    bool validNum = false;
    do { // check if number.
        std::cout << "Enter array size: "; // gather array size.
        std::cin >> arraySize;
        if (std::cin.fail()) {
            std::cin.clear(); // clear error.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore input.
            std::cout << "Invalid entry." << std::endl;
        } else {
            validNum = true;
        }
    } while (validNum == false); // continue unless input is a number.
    
    int* array = createArray(arraySize); // dynamically allocate an array based on user input array size.
    fillArray(array, arraySize); // pass array and size to fill elements from user input.
    displayArray(array, arraySize); // pass array and size to display elements in array.

    delete[]array; // free memory
    array = nullptr;

    return 0;
}

int* createArray(int arraySize) {
    int* newArray = new int[arraySize]; // dynamically allocate an array based on user input array size.
    return newArray; // return created array with allocated array size.
}

void fillArray(int* array, int arraySize) {
    for (int i = 0; i < arraySize; i++) { // allocate array with integers based on user input.
        bool validNum = false;
        do { // check if number.
            std::cout << "Enter element number " << i + 1 << ": ";
            std::cin >> array[i];
            if (std::cin.fail()) {
                std::cin.clear(); // clear error.
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore input.
                std::cout << "Invalid entry." << std::endl;
            }
            else {
                validNum = true;
            }
        } while (validNum == false); // continue unless input is a number.
    }
}

void displayArray(int* array, int arraySize) {
    std::cout << "Your array has the following elements: " << std::endl;
    for (int i = 0; i < arraySize; i++) { // print array elements.
        std::cout << "Element " << i + 1 << ": " << array[i] << std::endl; // handles dereferencing.
    }
}