// Lab 1 - On Operations.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Mao Bergan
// CIS 242
// Due Date: Aug 29th, 2024

/* Have a user input of 2 numbers.
Take those 2 numbers to add, multiply, divide, subtract and mod.
Each operation(+, -, *, / , %) must be a function and include a couple void functions, call by reference functions.
Extra credit a pointer function. */

#include <iostream>

// prototypes.
void startProgram();
int addOperator(int, int);
int subtractOperator(int, int);
double divideOperator(double, double);
int multiplyOperator(int, int);
int modOperator(int, int);

int main() {
    startProgram();
    return 0;
}

void startProgram() {
    char userOperation; // user selected operation.
    char newOperation; // do another operation with new numbers.
    double result;
    do {
        // prompt for first number.
        std::cout << "Enter number 1: ";
        int userNum1;
        std::cin >> userNum1;

        // prompt for second number.
        std::cout << "Enter number 2: ";
        int userNum2;
        std::cin >> userNum2;

        // ask user what operation to use.
        std::cout << "What operation would you like to use?" << std::endl;
        std::cout << "[+] Add\n[-] Subtract\n[*] Multiply\n[/] Divide\n[%] Mod" << std::endl;

        do { // controls user selected operation.
            std::cout << "Enter operation: ";
            std::cin >> userOperation;
            switch (userOperation) {
            case '+':
                result = addOperator(userNum1, userNum2);
                std::cout << "Adding " << userNum1 << " and " << userNum2 << " equals " << result << std::endl;
                break;
            case '-':
                result = subtractOperator(userNum1, userNum2);
                std::cout << "Subtracting " << userNum1 << " and " << userNum2 << " equals " << result << std::endl;
                break;
            case '*':
                result = multiplyOperator(userNum1, userNum2);
                std::cout << "Multiplying " << userNum1 << " and " << userNum2 << " equals " << result << std::endl;
                break;
            case '/':
                result = divideOperator(userNum1, userNum2);
                std::cout << "Dividing " << userNum1 << " and " << userNum2 << " equals " << result << std::endl;
                break;
            case '%':
                result = modOperator(userNum1, userNum2);
                std::cout << "The remainder of " << userNum1 << " divided by " << userNum2 << " equals " << result << std::endl;
                break;
            default:
                std::cout << "Invalid operation, please try again." << std::endl;
            }
        } while (userOperation != '+' && userOperation != '-' && userOperation != '*' && userOperation != '/' && userOperation != '%');

        // prompt user if they want to user operator on new numbers.
        std::cout << "Would you like to do another operation? (y/n): ";
        std::cin >> newOperation;
        newOperation = toupper(newOperation);
    } while (newOperation == 'Y');
}

int addOperator(int num1, int num2) {
    int num3 = num1 + num2;
    return num3;
}

int subtractOperator(int num1, int num2) {
    int num3 = num1 - num2;
    return num3;
}

int multiplyOperator(int num1, int num2) {
    int num3 = num1 * num2;
    return num3;
}

double divideOperator(double num1, double num2) {
    double num3 = num1 / num2;
    return num3;
}

int modOperator(int num1, int num2) {
    int num3 = num1 % num2;
    return num3;
}
