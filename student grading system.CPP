#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Define a structure to store student information
struct Student {
    string name;
    vector<int> scores; // Vector to store scores for multiple subjects
    double average;
    char grade;
};

// Function to calculate the grade based on the average score
char calculateGrade(double average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

// Function to sort students by average score in descending order
bool compareStudents(const Student& a, const Student& b) {
    return a.average > b.average;
}

int main() {
    vector<Student> students;

    int numStudents, numSubjects;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    // Input student data
    for (int i = 0; i < numStudents; i++) {
        Student student;
        cout << "Enter the name of student " << i + 1 << ": ";
        cin.ignore();
        getline(cin, student.name);

        student.scores.resize(numSubjects);

        cout << "Enter scores for " << student.name << " (";
        for (int j = 0; j < numSubjects; j++) {
            cout << "Subject " << j + 1 << ": ";
            cin >> student.scores[j];
        }

        // Calculate the average score
        double sum = 0;
        for (int score : student.scores) {
            sum += score;
        }
        student.average = sum / numSubjects;

        // Calculate the grade
        student.grade = calculateGrade(student.average);

        students.push_back(student);
    }

    // Sort students by average score in descending order
    sort(students.begin(), students.end(), compareStudents);

    // Calculate the class average
    double classAverage = 0;
    for (const Student& student : students) {
        classAverage += student.average;
    }
    classAverage /= numStudents;

    // Display student data, class average, and generate a grade report
    cout << "\nGrade Report:\n";
    cout << "--------------------------------------------------\n";
    cout << setw(20) << left << "Name" << setw(15) << left << "Average" << setw(10) << left << "Grade" << endl;
    cout << "--------------------------------------------------\n";

    for (const Student& student : students) {
        cout << setw(20) << left << student.name << setw(15) << left << setprecision(2) << fixed << student.average << setw(10) << left << student.grade << endl;
    }

    cout << "--------------------------------------------------\n";
    cout << "Class Average: " << setprecision(2) << fixed << classAverage << endl;

    return 0;
} 
