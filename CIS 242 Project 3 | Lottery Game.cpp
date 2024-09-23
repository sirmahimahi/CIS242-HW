// CIS 242 Project 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Mao Bergan
// CIS 242
// Due Date: Sep 25th, 2024

/* Write a program that simulates a lottery. The program should have an array of 10
integers named lottery and should generate a random number in the range of 0
through 9 for each element in the array. The user should enter ten digits, which should
be stored in an integer array named user. The program is to compare the corresponding
elements in the two arrays and keep a count of the digits that match */

#include <iostream>
#include <random>
#include "functions.h"

// prototypes
void createLotteryNumbers(int& lotterySize, int* lotteryNumbers);
void userCreatedNumbers(int& lotterySize, int* userNumbers);
void compareLotteryNumbers(int& lotterySize, int* userNumbers, int* lotteryNumbers);
bool validRestart(char restart, bool& validInput);
void printLotteryNumbers(int& lotterySize, int* lotteryNumbers);
void printUserNumbers(int& lotterySize, int* lotteryNumbers);

int main() {
    int lotterySize = 10; // set size of array to store elements
    char playAgain = 'Y';
    bool validInput = false;

    do {
        int* userNumbers = new int[lotterySize];
        int* lotteryNumbers = new int[lotterySize];

        createLotteryNumbers(lotterySize, lotteryNumbers); // create computer lottery
        //printLotteryNumbers(lotterySize, lotteryNumbers); /* DEBUG ONLY */
        userCreatedNumbers(lotterySize, userNumbers); // ask user to select array numbers
        printUserNumbers(lotterySize, userNumbers); // print user numbers
        printLotteryNumbers(lotterySize, lotteryNumbers); // print lottery numbers
        compareLotteryNumbers(lotterySize, userNumbers, lotteryNumbers); // compare array numbers

        delete[] userNumbers;
        delete[] lotteryNumbers;

        do {
            std::cout << "Would you like to try again? (y/n): ";
            std::cin >> playAgain;
            playAgain = toupper(playAgain);
            validRestart(playAgain, validInput);
        } while (!validInput);

    } while (playAgain == 'Y');
    
    return 0;
}

void createLotteryNumbers(int& lotterySize, int* lotteryNumbers) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 9); // random number from 0-9

    for (int i = 0; i < lotterySize; i++) { // set random number for each element in the array
        lotteryNumbers[i] = distr(gen); 
    }
}

void userCreatedNumbers(int& lotterySize, int* userNumbers) {
    std::string input; // store user input
    bool validInput = false;

    std::cout << "Enter 10 digits without spaces from 0 - 9: ";
    do {
        std::cin >> input;

        if (input.length() != lotterySize) { // check to make sure user entered 10 digits
            std::cout << "Invalid Input. Please enter exactly 10 digits from 0 - 9: " << std::endl;
            continue; // start over
        }
        else {
            validInput = true;
        }

        for (int i = 0; i < lotterySize; ++i) { // convert user input to integers and store in user array
            userNumbers[i] = input[i] - '0';
        }

    } while (validInput == false);    
}

void compareLotteryNumbers(int& lotterySize, int* userNumbers, int* lotteryNumbers) {
    int lotteryMatch = 0; // control how many numbers match
    for (int i = 0; i < lotterySize; i++) {
        if (userNumbers[i] == lotteryNumbers[i]) { // compare lottery and user number in each array element
            std::cout << "$" << " ";
        }
        else {
            std::cout << "#" << " ";
        }
    }
    std::cout << "[ Visual Representation ]";
    std::cout << std::endl;

    std::cout << "Matching numbers: ";
    for (int i = 0; i < lotterySize; i++) {
        if (userNumbers[i] == lotteryNumbers[i]) { // compare lottery and user number in each array element
            lotteryMatch = lotteryMatch++; //
            std::cout << userNumbers[i] << " ";
        }
    }
    std::cout << std::endl;
    
    if (lotteryMatch == 10) { // print if all numbers match.
        std::cout << "You won the lottery!" << std::endl << std::endl;
    }
    else {
        std::cout << "Total matching numbers: " << lotteryMatch << std::endl;
        std::cout << "Better luck next time." << std::endl << std::endl;
    }
}

bool validRestart(char restart, bool& validInput) {
    if (restart == 'Y' || restart == 'N') {
        return validInput = true; // valid input, exit loop
    }
    else {
        std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
        return validInput = false; // invalid input, loop again
    }
}

void printLotteryNumbers(int& lotterySize, int* lotteryNumbers) {
    for (int i = 0; i < lotterySize; i++) {
        std::cout << lotteryNumbers[i] << " ";
    }
    std::cout << "[ Lottery Numbers ]"; // display all computer lottery numbers
    std::cout << std::endl;
}

void printUserNumbers(int& lotterySize, int* userNumbers) {
    for (int i = 0; i < lotterySize; ++i) { // display all user lottery numbers
        std::cout << userNumbers[i] << ' ';
    }
    std::cout << "[ User Numbers ]";
    std::cout << std::endl;
}
