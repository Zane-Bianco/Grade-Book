
// Grade Book Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int readDataFromFile(ifstream& file, vector<string>& names, vector<vector<int>>& scores) {
    string name;
    int count = 0;

    // Loops through the file and read data
    while (file >> name) {
        names.push_back(name); // Add student name

        vector<int> studentScores;
        int score;

        // Read all scores for the current student
        while (file >> score) {
            studentScores.push_back(score);

            // Check if next line starts with a name 
            if (file.peek() == '\n' || file.eof()) {
                break;
            }
        }

        scores.push_back(studentScores); // Add the scores for the current student
        count++;
    }

    return count; // Return the number of student records
}
void calculateAverages(const vector<vector<int>>& scores, vector<double>& averages) { // Calculates averages using each students scores
    for (const auto& studentScores : scores) {
        double sum = 0;

        for (int score : studentScores) {
            sum += score;
        }
        double average = sum / studentScores.size();

        averages.push_back(average);
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
void CreateReport(const vector<string>& names, const vector<double>& averages) {
    //Report Header
    cout << left << setw(20) << "Student Name"
        << setw(15) << "Average Score"
        << setw(10) << "Grade" << endl;
    //seperator for design
    cout << string(45, '-') << endl;

    //Output Report
    for (size_t i = 0; i < names.size(); ++i) {
        cout << left << setw(20) << names[i]
            << setw(15) << fixed << setprecision(2) << averages[i]  // Shows average with 2 decimal places
            << setw(10) << calculateLetterGrade(averages[i]) << endl;
    }
}
int main() {
    ifstream inputFile("C:\\Users\\Speedy\\Documents\\StudentGrades.txt");  // Opens the desired file
    if (!inputFile) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    vector<string> names;  // Vector to store student names
    vector<vector<int>> scores;  // Vector of vectors to store scores
    vector<double> averages;  // Vector to store the average scores

    // Call the function to read data from the file
    int numRecords = readDataFromFile(inputFile, names, scores);

    // Call the function to calculate averages
    calculateAverages(scores, averages);
    // Call the function to create and output report
    CreateReport(names, averages);

    inputFile.close();  // Closes the file
    return 0;
}




