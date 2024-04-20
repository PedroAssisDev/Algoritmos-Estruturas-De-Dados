#include <iostream>

using namespace std;

// Function that receives a parameter by value
void passByValue(int x) {
    // Modifies the value of the parameter locally
    x = x * 2;
    cout << "Inside passByValue function, x = " << x << endl;
}

// Function that receives a parameter by reference
void passByReference(int& y) {
    // Modifies the value of the parameter directly
    y = y * 2;
    cout << "Inside passByReference function, y = " << y << endl;
}

int main() {
    int value = 10;

    // Calling the passByValue function
    cout << "Before calling passByValue function, value = " << value << endl;
    passByValue(value);
    cout << "After calling passByValue function, value = " << value << endl;
    cout << endl;

    // Calling the passByReference function
    cout << "Before calling passByReference function, value = " << value << endl;
    passByReference(value);
    cout << "After calling passByReference function, value = " << value << endl;

    return 0;
}
