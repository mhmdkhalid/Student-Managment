#include <iostream>

using namespace std;

class Student {
protected:
    string name;
    int ID;
    int level;
    Course* courseList[6];
    int noOfCourses;


public:
    double grades[6];
    Student(){
        level = 0;
        noOfCourses = 0;
        ID = 0;
        name ="";
        for (int i = 0; i < 6; i++) {
            grades[i] = 0.0;
            courseList[i] = nullptr;
        }
    }

    virtual ~Student() {}

    void printRegisteredCourses() {
        if (noOfCourses == 0) {
            cout << "No courses registered yet." << endl;
            return;
        }

        cout << "Registered Courses:" << endl;
        for (int i = 0; i < noOfCourses; ++i) {
            if (courseList[i]) {
                Course* course = courseList[i];
                cout << "- Course " << (i + 1) << ":" << endl;
                cout << "  - Name: " << course->getName() << endl;
                cout << "  - Code: " << course->getCode() << endl;
                cout << "  - Level: " << course->getMinStudentLevel() << endl;
                cout << "  - Credit Hours: " << course->getCreditHours() << endl;
                cout << "  - Grade: " << grades[i] << endl;
            }
        }
    }

    virtual bool registerCourse(Course* course) {

        if (noOfCourses >= 6) {
            cout << "Maximum courses are already registered." << endl;
            return false;
        }
        if (course->getMinStudentLevel() > level) {
            cout << "Cannot register for this course due to level restriction." << endl;
            return false;
        }
        courseList[noOfCourses] = course;
        noOfCourses++;
        return true;
    }

    virtual float calculateExpenses() = 0;

    double getTotalGPA() {
        double totalPoints = 0.0;
        double totalCreditHours = 0.0;

        for (int i = 0; i < noOfCourses; ++i) {
            if (courseList[i]) {
                double courseGPA = getCourseGPA(grades[i]);
                totalPoints += courseGPA * courseList[i]->getCreditHours();
                totalCreditHours += courseList[i]->getCreditHours();
            }
        }

        if (totalCreditHours == 0.0) {
            return 0.0;
        }

        return totalPoints / totalCreditHours;
    }

    double getCourseGPA(double percentage) {
        if (percentage >= 98.0 && percentage <= 100.0){
            return 4.00;
        } else if (percentage >= 93.0 && percentage <= 97.0){
            return 4.00;
        } else if (percentage >= 90.0 && percentage <= 92.0){
            return 3.70;
        } else if (percentage >= 87.0 && percentage <= 89.0){
            return 3.30;
        } else if (percentage >= 83.0 && percentage <= 86.0){
            return 3.00;
        } else if (percentage >= 80.0 && percentage <= 82.0){
            return 2.70;
        } else if (percentage >= 77.0 && percentage <= 79.0){
            return 2.30;
        } else if (percentage >= 73.0 && percentage <= 76.0){
            return 2.00;
        } else if (percentage >= 70.0 && percentage <= 72.0){
            return 1.70;
        } else if (percentage >= 67.0 && percentage <= 69.0){
            return 1.30;
        } else if (percentage >= 63.0 && percentage <= 66.0){
            return 1.00;
        } else if (percentage >= 60.0 && percentage <= 62.0){
            return 0.70;
        } else if (percentage < 60 && percentage >=0){
            return 0.00;
        }
        else cout<<"The percentage you've entered is invalid.";
    }

    void setName(string NAME) {
        name = NAME;
    }

    void setID(int studentID) {
        ID = studentID;
    }

    int getLevel(){
        return level;
    }

    virtual string getName(){
        return name;
    }
    virtual int getID(){
        return ID;
    }
    virtual Course** getCourseList() {
        return courseList;
    }
    virtual int getNoOfCourses(){
        return noOfCourses;
    }

};

#ifndef UNTITLED11_STUDENT_H
#define UNTITLED11_STUDENT_H

#endif
