#include "Header.h"

#include <iostream>
#include <limits>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <locale>

BankAccount::BankAccount() { // class to store username and password for bank account
    username = "username";
    password = "password";
    userInputUsername = "placeholder";
    userInputPassword = "placeholder";
}

void BankActions::checkAccountCredentials(bool& validSelection) { // inherited from BankAccount
    while (true) {
        std::cout << "[+] Enter username: ";
        std::cin >> userInputUsername;
        std::cout << "[+] Enter password: ";
        std::cin >> userInputPassword;
        try {
            if (userInputUsername != username) { // throw if username is incorrect
                throw "Invalid username. Please try again.\n";
            }
            else if (userInputPassword != password) { // throw if password is incorrect
                throw "Invalid password. Please try again.\n";
            }
            else {
                validSelection = true; // exit loop if username and password are correct
                break;
            }
        }
        catch (const char* operationError) {
            std::cerr << "[ERROR] " << operationError << '\n';
        }
    }
}

BankActions::BankActions() {
    savingsAccountBalance = 28945; // starting balance
    AnnualPercentageYeild = 4.2; // starting APY
    savingsAccountAPY = 0;
}

std::string BankActions::displayBalance() { // control format of bank account currency balance
    std::ostringstream currencyUSD; // assign variable
    currencyUSD.imbue(std::locale("en_US.UTF-8")); // used for handling numbers with comas, such as numbers in the thousands place
    currencyUSD << std::fixed << std::setprecision(2); // set decimal place to 2 digits
    currencyUSD << "$" << std::put_money(savingsAccountBalance * 100); // add dollar sign and format when a coma should be used after every 100
    return currencyUSD.str();
}

std::string BankActions::displayUserInputAmount(double& userDecimalInput) { // control format of user input currency
    std::ostringstream currencyUSD;
    currencyUSD.imbue(std::locale("en_US.UTF-8"));
    currencyUSD << std::fixed << std::setprecision(2);
    currencyUSD << "$" << std::put_money(userDecimalInput * 100);
    return currencyUSD.str();
}

void BankActions::checkValidSelection(int& userNumberInput) { // ask user for a integer number and validate the input
    while (true) {
        std::cin >> userNumberInput;
        try {
            if (std::cin.fail()) { // if input is not a integer
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw "Invalid Operation. Please try again.\n";
            }
            else if (userNumberInput > 4 || userNumberInput < 1) { // if input is out of selection range
                throw "Invalid selection range. Enter selection range from 1-4.\n";
            }
            else { // break out of loop if user input is valid
                break;
            }
        }
        catch (const char* operationError) { // using variable char to point to literal string
            std::cerr << "[ERROR] " << operationError;
            std::cout << "[+] Please enter operation number: ";
        }
    }
}

void BankActions::depositAmount(double& userDecimalInput) {
    std::cout << "\nHow much would you like to deposit?\n";
    std::cout << "[+] Enter amount: ";
    while (true) {
        std::cin >> userDecimalInput;
        try {
            if (std::cin.fail()) { // if input is not a integer
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw "Invalid Operation. Please try again using only numbers.\n";
            }
            else if (userDecimalInput < 1) { // if input is out of selection range
                throw "You cannot enter a negative amount. Please try again.\n";
            }
            else { // break out of loop if user input is valid
                savingsAccountBalance = savingsAccountBalance + userDecimalInput;
                std::cout << ">>> " << displayUserInputAmount(userDecimalInput) << " will be added into your account, effective immediately.\n";
                break;
            }
        }
        catch (const char* operationError) { // using variable char to point to literal string
            std::cerr << "[ERROR] " << operationError;
            std::cout << "[+] Please enter valid amount to deposit: ";
        }
    }
}

void BankActions::withdrawalAmount(double& userDecimalInput) {
    std::cout << "\nHow much would you like to withdrawal?\n";
    std::cout << "[+] Enter amount: ";
    while (true) {
        std::cin >> userDecimalInput;
        try {
            if (std::cin.fail()) { // if input is not a integer
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw "Invalid Operation. Please try again using only numbers.\n";
            }
            else if (userDecimalInput > savingsAccountBalance) { // if input is out of selection range
                throw "Insufficient funds. Please try again.\n";
            }
            else if (userDecimalInput < 0) {
                throw "You cannot enter a negative amount. Please try again.\n";
            }
            else { // break out of loop if user input is valid
                savingsAccountBalance = savingsAccountBalance - userDecimalInput;
                std::cout << ">>> " << displayUserInputAmount(userDecimalInput) << " will be removed from your account, effective immediately.\n";
                break;
            }
        }
        catch (const char* operationError) { // using variable char to point to literal string
            std::cerr << "[ERROR] " << operationError;
            std::cout << "[+] Please enter valid amount to withdrawal: ";
        }
    }
}

void BankActions::displayAnnualPercentageYeild() {
    savingsAccountAPY = savingsAccountBalance * (AnnualPercentageYeild / 100); // equation to calculate APY
    std::cout << "\n>>> Annual Percentage Yeild:  " << AnnualPercentageYeild << "%\n";
    std::cout << ">>> Current gain: " << displayUserInputAmount(savingsAccountAPY) << "\n";
}