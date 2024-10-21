// CIS 242 Midterm Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Mao Bergan
// CIS 242
// Due Date: Oct 27th, 2024
// Visual Studio Community v17.11.4 : C++20

/* Create a program that starting balance, deposits, withdrawal from a Savings Account, and returns the following on the screen:
    Balance use any amount hard-coded in your code.
    Amount withdrawn (input by user)
    Amount Deposit (input from user)
    Interest Accrued (It is whatever equation you come up with from the starting Balance.)
    Exit (Exit out of the program)

If the withdrawal amount is greater than the Starting balance, a message appears stating: Insufficient Funds- It should display a message “Insufficient funds”)
Next you will then ask the user to either exit or go back to the main menu.
    If the withdrawal amount is a negative number, a message should appear stating:
    Negative entries are not allowed. Thereafter you will then ask the user to either exit or go back to the main menu.
    I need a username and password should be the 1st page before you are able to see the menu options.
    Calculate interest at 1% of the Starting Balance this should take place after the user enters their information. It should show them there interest thus far. */

#include "Header.h"
#include <iostream>

int main() {
    int userNumberInput; // store user integer input
    double userDecimalInput;
    bool validSelection = false; // control while loops
    bool endProgram = false;
    
    BankActions Account;
    while (validSelection == false) Account.checkAccountCredentials(validSelection); // ask for username and password. loop if incorrect
    while (endProgram == false) { // loop untill user selection is valid
        std::cout << "\nMain Menu\n";
        std::cout << "Savings Account Balance: " << Account.displayBalance() << '\n';
        std::cout << "  1. Deposit\n";
        std::cout << "  2. Withdrawal\n";
        std::cout << "  3. Annual Percentage Rate\n";
        std::cout << "  4. Exit\n";
        std::cout << "[+] Please enter operation number: ";
        Account.checkValidSelection(userNumberInput);
        switch (userNumberInput) {
        case 1: // deposit
            Account.depositAmount(userDecimalInput);
            break;
        case 2: // withdrawal
            Account.withdrawalAmount(userDecimalInput);
            break;
        case 3: // APY
            Account.displayAnnualPercentageYeild();
            break;
        case 4: // exit program
            endProgram = true;
            break;
        default:
            endProgram = false;
            break;
        }
    }
    return 0;
}