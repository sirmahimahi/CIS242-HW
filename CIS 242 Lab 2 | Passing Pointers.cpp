// CIS 242 Lab 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Mao Bergan
// CIS 242
// Due Date: Sep 8th, 2024

/* The following function uses reference variables as parameters. 
Rewrite the function so it uses pointers instead of reference variables,
and then demonstrate the function in a complete program. */

/* The program below will accept two inputs from the user, variable x and y.
The program will take the two inputs, will send the address of the user inputs.
Will multiply the two numbers and return the result to the console. */

#include <iostream>

// prototypes
int multiply(int* x, int* y);

int main() {
    std::cout << "Multiplier" << std::endl;

    std::cout << "Enter first number: ";
    int x;
    std::cin >> x;

    std::cout << "Enter second number: ";
    int y;
    std::cin >> y;
    
    std::cout << multiply(&x, &y); // give the address of x and y. return the sum of x * y.
    return 0;
}

int multiply(int* x, int* y) { // accept address of x and y, store them in a local variable x and y.
    std::cout << *x << " * " << *y << " = ";
    return *y * *x; // dereference x and y to get the actual value instead of the address.
}
