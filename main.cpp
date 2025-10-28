/*
Author: Zakaria Rahman
Date: October 26th, 2025
Des15cription: This program collects user inputs and validates if they enter the correct input.
             Also, it demonstrates file handling by writing to a file.
Course: ITCS 2530 (C++ Programming 1)
*/

// header files
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    // Welcome Message
    cout << left << setfill('-') << setw(133) << "" << endl;
    cout << "Welcome to the Math Aptitude Analyzer! Let's see how confident you are with math."
    << " Please enter the following information as prompted." << endl;;
    cout << left << setfill('-') << setw(133) << "" << endl << endl;


    // Declare Variables and Initializing some of them
    string name;
    string favoriteMathSubject;
    int problemsSolvedPerWeek= 0;
    int confidenceLevel = 0;
    double hoursSpentStudyingPerWeek = 1.0;
    double estimatedProblemsPerHour = 0.0;

    // File handling
    ofstream outputFile;
    
    // Prompts for user inputs
    cout << "Enter your full name: ";
    getline(cin, name);
    cout << endl;

    cout << "Enter your favorite Math subject: ";
    getline(cin, favoriteMathSubject); 
    cout << endl;


    cout << "Enter number of Math Problems you solved per week : ";
    // Input Validation
    if (!(cin >> problemsSolvedPerWeek)) {
        cout << "\nInvalid input. Please restart/re-run the program with correct data type for input." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << endl;

    cout << "On a scale of 1 to 10, how confident are you in Math? (1 being least and 10 being most): ";
    if (!(cin >> confidenceLevel)){
        cout << "\nInvalid input. Please restart/re-run the program with correct data type for input." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << endl;

    cout << "Enter number of hours you spend studying Math per week: ";
    if (!(cin >> hoursSpentStudyingPerWeek)){
        cout << "\nInvalid input. Please restart/re-run the program with correct data type for input." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << endl;

    estimatedProblemsPerHour = static_cast<double> (problemsSolvedPerWeek) / hoursSpentStudyingPerWeek;

    outputFile.open("report.txt");
    if (!outputFile.is_open()){
        cout << "Error opening the file." << endl;
        return -1;
    }


    outputFile << fixed << showpoint << setprecision(2);

    outputFile << left << setfill(' ') << setw(50) << "Name:" << right << setw(20) << setfill(' ') << name << endl;
    outputFile << left << setfill(' ') << setw(50) << "Favorite Math Subject:" << right << setw(20) << setfill(' ') << favoriteMathSubject << endl;
    outputFile << left << setfill(' ') << setw(50) << "Confidence Level:" << right << setw(20) << setfill(' ') << confidenceLevel << endl;
    outputFile << left << setfill(' ') << setw(50) << "# of Hours Studying Math:" << right << setw(20) << setfill(' ') << hoursSpentStudyingPerWeek << endl;
    outputFile << left << setfill(' ') << setw(50) << "Estimated Problems Solved Per Hour:" << right << setw(20) << setfill(' ') << estimatedProblemsPerHour << endl;

    return 0;
}
