#pragma once

// prototypes
void createFilledRectangle(int& userNumberSelection, bool& isUserNumberValid);
void createUnfilledRectangle(int& userNumberSelection, bool& isUserNumberValid);
void createFilledTriangle(int& userNumberSelection, bool& isUserNumberValid);
void createUnfilledTriangle(int& userNumberSelection, bool& isUserNumberValid);
void validateUserNumber(bool& isUserNumberValid);

class Rectangle {
private:
    int height;
    int width;
    char** rectangleArray;

public:
    Rectangle(int height, int width) { // create the array for the rectangle and store a blank value for each element
        this->height = height;
        this->width = width;

        rectangleArray = new char* [this->height];
        for (int i = 0; i < height; i++) {
            rectangleArray[i] = new char[this->width];
        }

        for (int i = 0; i < this->height; i++) {
            for (int j = 0; j < this->width; j++) {
                rectangleArray[i][j] = ' '; // add placeholder values to each array element
            }
        }
    }

    ~Rectangle() {
        for (int i = 0; i < height; i++) {
            delete[] rectangleArray[i];
        }
        delete[] rectangleArray;
    }

    void printRectangleArray() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                std::cout << rectangleArray[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void setUnfilledRectangleArray() { // display unfilled rectangle image based on user defined size
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                rectangleArray[i][0] = '*';
                rectangleArray[0][j] = '*';
                rectangleArray[i][width - 1] = '*';
                rectangleArray[height - 1][j] = '*';
            }
        }
    }

    void setFilledRectangleArray() { // display filled rectangle image based on user defined size
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                rectangleArray[i][j] = '*';
            }
        }
    }
};

class Triangle {
private:
    int height;
    char** triangleArray;

public:
    Triangle(int height) {
        this->height = height;
        triangleArray = new char* [this->height];
        for (int i = 0; i < height; i++) {
            triangleArray[i] = new char[this->height];
        }
    }

    ~Triangle() {
        for (int i = 0; i < this->height; i++) {
            delete[] triangleArray[i];
        }
        delete[] triangleArray;
    }

    void printTriangleArray() {
        for (int i = 0; i < this->height; i++) {
            for (int j = 0; j <= i; j++) {
                std::cout << triangleArray[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void setFilledTriangleArray() { // display filled triangle image based on user defined size
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < height; j++) {
                if (j <= i) {
                    triangleArray[i][j] = '*';  // fill each array element
                }
                else {
                    triangleArray[i][j] = ' ';
                }
            }
        }
    }

    void setUnfilledTriangleArray() { // display unfilled triangle image based on user defined size
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < height; j++) {
                if (j == 0 || j == i || i == height - 1) { // fill fiest and last array element for the triangle
                    triangleArray[i][j] = '*';
                }
                else {
                    triangleArray[i][j] = ' ';
                }
            }
        }
    }
};

// functions
void createFilledRectangle(int& userNumberSelection, bool& isUserNumberValid) { // filled rectangle
    int userRectangleHeight; // store user input for height of rectangle
    int userRectangleWidth;  // store user input for width of rectangle

    do {
        std::cout << "Enter height for rectangle: ";
        std::cin >> userRectangleHeight;
        validateUserNumber(isUserNumberValid); // check user input
    } while (!isUserNumberValid); // exit loop if user input is valid

    do {
        std::cout << "Enter width for rectangle: ";
        std::cin >> userRectangleWidth;
        validateUserNumber(isUserNumberValid); // check user input
    } while (!isUserNumberValid); // exit loop if user input is valid

    Rectangle filledRectangleArray(userRectangleHeight, userRectangleWidth); // create new object called rectangle1

    filledRectangleArray.setFilledRectangleArray();
    filledRectangleArray.printRectangleArray();
}

void createUnfilledRectangle(int& userNumberSelection, bool& isUserNumberValid) { // unfilled rectangle
    int userRectangleHeight; // store user input for height of rectangle
    int userRectangleWidth;  // store user input for width of rectangle

    do {
        std::cout << "Enter height for rectangle: ";
        std::cin >> userRectangleHeight;
        validateUserNumber(isUserNumberValid); // check user input
    } while (!isUserNumberValid); // exit loop if user input is valid

    do {
        std::cout << "Enter width for rectangle: ";
        std::cin >> userRectangleWidth;
        validateUserNumber(isUserNumberValid); // check user input
    } while (!isUserNumberValid); // exit loop if user input is valid

    Rectangle unfilledRectangle(userRectangleHeight, userRectangleWidth); // create new object called rectangle1

    unfilledRectangle.setUnfilledRectangleArray();
    unfilledRectangle.printRectangleArray();
}

void createFilledTriangle(int& userNumberSelection, bool& isUserNumberValid) {
    int userTriangleHeight;

    do {
        std::cout << "Enter height for triangle: ";
        std::cin >> userTriangleHeight;
        validateUserNumber(isUserNumberValid); // check user input
    } while (!isUserNumberValid); // exit loop if user input is valid

    Triangle filledTriangle(userTriangleHeight); // create new object called triangle1

    filledTriangle.setFilledTriangleArray();
    filledTriangle.printTriangleArray();
}

void createUnfilledTriangle(int& userNumberSelection, bool& isUserNumberValid) {
    int userTriangleHeight;

    do {
        std::cout << "Enter height for triangle: ";
        std::cin >> userTriangleHeight;
        validateUserNumber(isUserNumberValid); // check user input
    } while (!isUserNumberValid); // exit loop if user input is valid

    Triangle unfilledTriangle(userTriangleHeight); // create new object called triangle1

    unfilledTriangle.setUnfilledTriangleArray();
    unfilledTriangle.printTriangleArray();
}

void validateUserNumber(bool& isUserNumberValid) { // check user input for valid number
    if (std::cin.fail()) { // check in input is successful
        std::cin.clear(); // clear error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore input
        std::cout << "Invalid input. Please try again." << std::endl;
        isUserNumberValid = false;
    }
    else {
        isUserNumberValid = true;
    }
}