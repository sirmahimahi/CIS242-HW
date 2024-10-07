// CIS 242 Project 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Mao Bergan
// CIS 242
// Due Date: Oct 7th, 2024
// Visual Studio Community v17.11.4 : C++20

/* Create a menu that has 4 options to choose from. ei: filled triangle, unfilled triangle, filled square...
Make sure the program also has an option to have the user exit the program. */

#include <iostream>
#include "Header.h"

int main() {
    bool playAgain = true;
    std::cout << "Welcome to the shape creator!" << std::endl;
    do {
        int userNumberSelection; // used for taking number inputs from user
        bool isUserNumberValid = true; // control whether user number is valid
        do {
            do { // display menu options
                std::cout << "1. Filled Rectangle" << std::endl;
                std::cout << "2. Unfilled Rectangle" << std::endl;
                std::cout << "3. Filled Triangle" << std::endl;
                std::cout << "4. Unfilled Triangle" << std::endl;
                std::cout << "5. Exit program" << std::endl;
                std::cout << "What command would you like to execute? (1-5): ";
                std::cin >> userNumberSelection;
                validateUserNumber(isUserNumberValid); // check user input
            } while (!isUserNumberValid); // exit loop if the user number input is a valid option

            switch (userNumberSelection) { // menu options
            case 1: // filled rectangle shape
                createFilledRectangle(userNumberSelection, isUserNumberValid);
                break;
            case 2: // unfilled rectangle shape
                createUnfilledRectangle(userNumberSelection, isUserNumberValid);
                break;
            case 3: // filled triangle shape
                createFilledTriangle(userNumberSelection, isUserNumberValid);
                break;
            case 4: // unfilled triangle shape
                createUnfilledTriangle(userNumberSelection, isUserNumberValid);
                break;
            case 5: // exit program
                playAgain = false;
                break;
            default:
                std::cout << "Invalid selection range. Please enter whole number 1-5." << std::endl;
                isUserNumberValid = false;
                break;
            }
        } while (!isUserNumberValid); // exit loop if the user number input is a valid option
    } while (playAgain); // exit loop if user wishes to exit program

    return 0;
}