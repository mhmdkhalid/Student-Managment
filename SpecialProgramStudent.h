#include "Student.h"

class SpecialProgramStudent : public Student {
public:
    bool registerCourse(Course* course) override {
        if (getNoOfCourses() >= 6) {
            cout << "Maximum courses are already registered." << endl;
            return false;
        }
        courseList[getNoOfCourses()] = course;
        noOfCourses++;
        return true;
    }

    float calculateExpenses() override {
        int totalCreditHours = 0;
        for (int i = 0; i < noOfCourses; ++i) {
            if (courseList[i] != nullptr) {
                totalCreditHours += courseList[i]->getCreditHours();
            }
        }
        return totalCreditHours * 500.0;
    }

    SpecialProgramStudent(int level) {
        this->level = level;
    }

    string getName() override {
        return name;
    }

    int getID() override {
        return ID;
    }

    Course** getCourseList() override {
        return courseList;
    }

    int getNoOfCourses() override {
        return noOfCourses;
    }
};
#ifndef UNTITLED11_SPECIALPROGRAMSTUDENT_H
#define UNTITLED11_SPECIALPROGRAMSTUDENT_H

#endif
