
class GeneralProgramStudent : public Student{
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
        return level * 1000.0;
    }

    GeneralProgramStudent(int level) {
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

#ifndef UNTITLED11_GENERALPROGRAMSTUDENT_H
#define UNTITLED11_GENERALPROGRAMSTUDENT_H

#endif
