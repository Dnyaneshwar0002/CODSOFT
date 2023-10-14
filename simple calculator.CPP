 
#include <iostream>
#include <cmath> // For sqrt function

using namespace std;

int main() {
    double num1, num2, result = 0;
    char operation;

    cout << "Impressive Calculator" << endl;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n";
        cout << "5. Square Root (sqrt)\n";
        cout << "6. Memory Recall (MR)\n";
        cout << "7. Memory Clear (MC)\n";
        cout << "8. Memory Add (M+)\n";
        cout << "9. Memory Subtract (M-)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> operation;

        if (operation == '0') {
            cout << "Goodbye!" << endl;
            break;
        }

        switch (operation) {
            case '1':
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = num1 + num2;
                cout << "Result: " << result << endl;
                break;
            case '2':
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
result = num1 - num2;
                cout << "Result: " << result << endl;
                break;
            case '3':
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = num1 * num2;
                cout << "Result: " << result << endl;
                break;
            case '4':
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error! Division by zero." << endl;
                }
                break;
            case '5':
                cout << "Enter a number: ";
                cin >> num1;
                if (num1 >= 0) {
                    result = sqrt(num1);
                    cout << "Square Root: " << result << endl;
                } else {
                    cout << "Error! Cannot compute square root of a negative number." << endl;
                }
                break;
            case '6':
                cout << "Memory Recall: " << result << endl;
                break;
            case '7':
                result = 0;
                cout << "Memory Cleared!"
<< endl;
                break;
            case '8':
                cout << "Enter a number to add to memory: ";
                cin >> num1;
                result += num1;
                cout << num1 << " added to memory." << endl;
                break;
            case '9':
                cout << "Enter a number to subtract from memory: ";
                cin >> num1;
                result -= num1;
                cout << num1 << " subtracted from memory." << endl;
                break;
            default:
                cout << "Invalid choice. Please select a valid option from the menu." << endl;
        }
    }

    return 0;
}
