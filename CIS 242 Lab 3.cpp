// CIS 242 Lab 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Mao Bergan
// CIS 242
// Due Date: Sep 16th, 2024

/* Write a program that uses loops to display a pattern,
followed by another pattern that is flipped.
Place pattern A in its own function and pattern B in its own function.
Use pointers. */

#include <iostream>
#include <iomanip> // allows setw();
#include <limits>

// prototypes
char* createArrays(int);
void printArrays(int, char*, char*);
bool validateNum(bool&);
bool validRestart(char, bool&);

int main() {
    char restart = 'y';

    do {
        int rows;
        bool validNum = false;
        bool validInput = false;

        do { // check if number.
            std::cout << "Enter number of rows for pyramid: ";
            std::cin >> rows;
            validateNum(validNum);
        } while (validNum == false); // continue unless input is a number.

        char* initialPyramid = createArrays(rows);
        char* reversedPyramid = createArrays(rows);

        for (int i = 0; i < rows; i++) {
            initialPyramid[i] = '+';
            reversedPyramid[i] = '+';
        }

        printArrays(rows, initialPyramid, reversedPyramid); // pass values and print array side by side

        do {
            std::cout << "Do you want to create another pyramid? (y/n): ";
            std::cin >> restart;
            restart = toupper(restart);
            validRestart(restart, validInput);
        } while (!validInput);

        delete[] initialPyramid;
        delete[] reversedPyramid;
    } while (restart == 'Y');
    return 0;
}

static char* createArrays(int rows) { // create array based on user input
    char* newArray = new char[rows];
    return newArray;
}

static void printArrays(int rows, char* initialPyramid, char* reversedPyramid) {
    int tempNum = rows + rows;
    std::cout << std::endl;
    std::cout << "Pattern A" << std::setw(tempNum) << "Pattern B" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << *(initialPyramid + j); // print initial pyramid row
        }
        tempNum = (rows + rows) - i;
        std::cout << std::setw(tempNum);  // create a space for the two pyramids

        for (int j = 0; j < rows - i; ++j) {
            std::cout << *(reversedPyramid + j); // print reversed pyramid row next to the initial
        }
        std::cout << std::endl; // move down one row to start next column.
    }
    std::cout << std::endl;
}

static bool validateNum(bool& validNum) {
    if (std::cin.fail()) {
        std::cin.clear(); // clear error.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore input.
        std::cout << "Invalid input. Please enter a whole number." << std::endl;
        return validNum = false;
    }
    else {
        return validNum = true;
    }
}

static bool validRestart(char restart, bool& validInput) {
    if (restart == 'Y' || restart == 'N') {
        return validInput = true; // valid input, exit loop
    }
    else {
        std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
        return validInput = false;
    }
}
