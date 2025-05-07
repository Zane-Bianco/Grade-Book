
// Grade Book Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int maxStudents = 15;
const int numScores = 5;

int readData(ifstream& inFile, string names[], int scores[][numScores]);
void calculateAverages(int scores[][numScores], double averages[], int studentCount);
char calculateLetterGrade(double average);
void CreateReport(string names[], double averages[], int studentCount);

int readData(ifstream& inFile, string names[], int scores[][numScores]) {
    int count = 0;

    while (count<maxStudents && inFile >> names[count]) {
        for (int i = 0; i < numScores; i++) {
            inFile >> scores[count][i];
        }
        count++;
    }
    return count;
}
void calculateAverages(int scores[][numScores], double averages[], int studentCount) { // Calculates averages using each students scores
    for (int i = 0; i < studentCount; i++) {
        int total = 0;
        for (int j = 0; j < numScores;j++) {
            total += scores[i][j];
        }
        averages[i] = static_cast<double>(total) / numScores;
    }

}
char calculateLetterGrade(double average) { // Uses average to calculate letter grade
    if (average >= 90) {
        return 'A';
    }
    else if (average >= 80) {
        return 'B';
    }
    else if (average >= 70) {
        return 'C';
    }
    else if (average >= 60) {
        return 'D';
    }
    else {
        return 'F';
    }
}
void CreateReport(string names[], double averages[], int studentCount) {
    cout << left << setw(20) << "Student Name"
        << setw(15) << "Average Score"
        << setw(10) << "Grade" << endl;

    cout << string(45, '-') << endl;

    
    for (int i = 0; i < studentCount; ++i) {
        cout << left << setw(20) << names[i]
            << setw(15) << fixed << setprecision(2) << averages[i]  // Shows average with 2 decimal places
            << setw(10) << calculateLetterGrade(averages[i]) << endl;
    }
}
int main() {
    

    string names[maxStudents];  
    int scores[maxStudents][numScores]; 
    double averages[maxStudents];  

    ifstream inFile("StudentGrades.txt");  
    if (!inFile) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }
    
    int studentCount = readData(inFile, names, scores);
    calculateAverages(scores, averages, studentCount);
    CreateReport(names, averages, studentCount);
   
    inFile.close();  // Closes the file
    return 0;
}




