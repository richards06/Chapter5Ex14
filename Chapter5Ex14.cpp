/*
Program Title: Chapter5Ex14
Programmer: Josh Richards
Date: December 6, 2024
Requirements:

Write a program that prompts the user to enter the number of students in the class, then loops to read that many names.

Once all the names have been read, it reports which student would be at the front of the line and

which one would be at the end of the line. You may assume that no two students have the same name.

Input Validation: Do not accept a number less than 1 or greater than 25 for the number of students.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getNumberOfStudents() {
    int numStudents;
    cout << "Enter the number of students in the class (1-25): ";
    cin >> numStudents;

    while(numStudents < 1 || numStudents>25) {
        cout << "Invalid number of students. Please enter a value between 1 and 25: ";
        cin >> numStudents;
    }
    return numStudents;
}

vector<string> getStudentNames(int numStudents) {
    vector<string> studentNames(numStudents);
    cout << "Enter the names of " << numStudents << " students: " << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << (i + 1) << ": ";
        cin >> studentNames[i];
    }
    return studentNames;
}

void displayLineOrder(const vector<string>& studentNames) {
    vector<string> sortedNames = studentNames;
    sort(sortedNames.begin(), sortedNames.end());

    cout << "\nThe student at the front of the live is: " << sortedNames[0] << endl;
    cout << "The student at the end of the line is: " << sortedNames[sortedNames.size() - 1] << endl;
}

int main()
{
    int numStudents = getNumberOfStudents();
    vector<string> studentNames = getStudentNames(numStudents);
    displayLineOrder(studentNames);
    return 0;
}

