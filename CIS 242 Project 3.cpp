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