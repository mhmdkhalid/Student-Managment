#include <iostream>
#include "Course.h"
#include "SpecialProgramStudent.h"
#include "GeneralProgramStudent.h"
#include "NormalCourse.h"
#include "SummerCourse.h"
using namespace std;

Course* COURSES [] = {new NormalCourse("Math", 1, 2),
                      new NormalCourse("Programming_1", 1, 3),
                      new NormalCourse("Technical_Writing", 1, 3),
                      new NormalCourse("Electronics", 2, 4),
                      new NormalCourse("Data_Structures", 2, 3),
                      new NormalCourse("OOP", 2, 3),
                      new NormalCourse("Algorithms", 3, 2),
                      new NormalCourse("Operating_Systems", 3, 3),
                      new NormalCourse("Databases", 3, 3),
                      new NormalCourse("Machine_Learning", 4, 3),
                      new NormalCourse("Compilers", 4, 4),
                      new NormalCourse("Programming_Concepts", 4, 4),
                      new SummerCourse("Math", 1, 2),
                      new SummerCourse("Compilers", 4, 4),

                      new SummerCourse("Algorithms", 3, 2),
                      new SummerCourse("OOP", 2, 3)
};

Course* searchCourse(const string& code) {
    for (int i = 0; i < sizeof(COURSES) / sizeof(COURSES[0]); i++) {
        if (COURSES[i]->getCode() == code) {
            return COURSES[i];
        }
    }
    return nullptr;
}


    int main() {
        const int MAX_STUDENTS = 100;
        cout << "How many users do you want in the system?: ";
        int numOfStudents;
        cin >> numOfStudents;

        Student* students[MAX_STUDENTS];
        int level;

        for (int i = 0; i < numOfStudents; ++i) {
            int studentType;
            cout << "Choose the student type (0: general, 1: special): ";
            cin >> studentType;

            string name;
            int id;
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter student level: ";
            cin >> level;

            Student* newStudent;
            if (studentType == 0) {
                newStudent = new GeneralProgramStudent(level);
            } else {
                newStudent = new SpecialProgramStudent(level);
            }

            int numCourses;
            cout << "Enter number of courses to register: ";
            cin >> numCourses;

            for (int j = 0; j < numCourses; ++j) {
                string courseCode;
                cout << "Enter code for course " << (j + 1) << ": ";
                cin >> courseCode;

                Course* course = searchCourse(courseCode);
                if (!course) {
                    cout << "Course not found! Try to register another course" << endl;
                    j--;
                    continue;
                }

                if (studentType == 0 && course->getMinStudentLevel() > level) {
                    cout << "You cannot register in this course due to the\n"
                            "minimum level restriction. Try to register another course" << endl;
                    j--;
                    continue;
                }

                if (!newStudent->registerCourse(course)) {
                    cout << "Error: Registration failed!" << endl;
                    continue;
                }

                double grade;
                cout << "Enter grade for " << course->getName() << ": ";
                cin >> grade;
                newStudent->grades[j] = grade;
            }
            newStudent->setName(name);
            newStudent->setID(id);
            students[i] = newStudent;
            cout << endl;
        }
        for (int i = 0; i < numOfStudents; ++i) {
            cout << "Student Name: " << students[i]->getName() << endl;
            cout << "ID: " << students[i]->getID() << endl;
            cout << "Level: " << students[i]->getLevel() << endl;
            students[i]->printRegisteredCourses();

            cout << "Overall GPA: " << students[i]->getTotalGPA() << endl;
            cout << "Student Expenses: " << students[i]->calculateExpenses() <<" EGP" <<endl;
            cout << endl;
        }

    for (int i = 0; i < numOfStudents; ++i) {
        delete students[i];
    }

    return 0;
}