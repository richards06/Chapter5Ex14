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
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> readStudentNamesFromFile() {
    const string filename = "LineUp.txt";
    vector<string> studentNames;
    ifstream inputFile(filename);

    if (!inputFile) {
        cout << "Error: Could not open the file " << filename << endl;
        return studentNames;
    }

    string name;
    while (getline(inputFile, name)) {
        if (!name.empty()) {
            studentNames.push_back(name);
        }
    }

    inputFile.close();
    return studentNames;
}

void displayLineOrder(const vector<string>& studentNames) {
    if (studentNames.empty()) {
        cout << "No student names were provided." << endl;
        return;
    }

    vector<string> sortedNames = studentNames;
    sort(sortedNames.begin(), sortedNames.end());

    cout << "\nThe student at the front of the line is: " << sortedNames[0] << endl;
    cout << "The student at the end of the line is: " << sortedNames[sortedNames.size() - 1] << endl;
}

int main()
{
    vector<string> studentNames = readStudentNamesFromFile();

    displayLineOrder(studentNames);
    
    return 0;
}

