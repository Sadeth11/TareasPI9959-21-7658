#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_STUDENTS = 10; // Number of students per faculty
const int NUM_FACULTIES = 3; // Number of faculties

void generateGrades(int grades[][4]) {
    srand(time(NULL));
    for(int i=0; i<NUM_STUDENTS; i++) {
        for(int j=0; j<4; j++) {
            grades[i][j] = rand() % 101; // Random grades between 0 and 100
        }
    }
}

void displayGrades(int grades[][4], string faculty) {
    cout << "Grades for " << faculty << " faculty: " << endl;
    for(int i=0; i<NUM_STUDENTS; i++) {
        cout << "Student " << i+1 << ": ";
        for(int j=0; j<4; j++) {
            cout << grades[i][j] << " ";
        }
        cout << endl;
    }
}

void calculateAverages(int grades[][4], double &average, double studentAverages[]) {
    double totalSum = 0;
    for(int i=0; i<NUM_STUDENTS; i++) {
        double studentSum = 0;
        for(int j=0; j<4; j++) {
            studentSum += grades[i][j];
        }
        studentAverages[i] = studentSum / 4.0; // Average of student's grades
        totalSum += studentAverages[i];
    }
    average = totalSum / NUM_STUDENTS; // Average of all students' averages
}

int getBestStudent(double studentAverages[]) {
    int bestStudent = 0;
    for(int i=1; i<NUM_STUDENTS; i++) {
        if(studentAverages[i] > studentAverages[bestStudent]) {
            bestStudent = i;
        }
    }
    return bestStudent;
}

int main() {
    int engineeringGrades[NUM_STUDENTS][4];
    int architectureGrades[NUM_STUDENTS][4];
    int administrationGrades[NUM_STUDENTS][4];

    // Generate grades for each faculty
    generateGrades(engineeringGrades);
    generateGrades(architectureGrades);
    generateGrades(administrationGrades);

    // Display grades for each faculty
    displayGrades(engineeringGrades, "Engineering");
    displayGrades(architectureGrades, "Architecture");
    displayGrades(administrationGrades, "Administration");

    // Calculate averages for each faculty
    double engineeringAverage, architectureAverage, administrationAverage;
    double engineeringStudentAverages[NUM_STUDENTS];
    double architectureStudentAverages[NUM_STUDENTS];
    double administrationStudentAverages[NUM_STUDENTS];

    calculateAverages(engineeringGrades, engineeringAverage, engineeringStudentAverages);
    calculateAverages(architectureGrades, architectureAverage, architectureStudentAverages);
    calculateAverages(administrationGrades, administrationAverage, administrationStudentAverages);

    // Display averages for each faculty
    cout << "Average grades for each faculty:" << endl;
    cout << "Engineering: " << engineeringAverage << endl;
    cout << "Architecture: " << architectureAverage << endl;
    cout << "Administration: " << administrationAverage << endl;

    // Calculate best student per faculty
    int engineeringBestStudent = getBestStudent(engineeringStudentAverages);
    int architectureBestStudent = getBestStudent(architectureStudentAverages);
    int administrationBestStudent = getBestStudent(architectureStudentAverages);
}
