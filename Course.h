#include <iostream>
using namespace std;

class Course {
protected:
    string name, code;
    int minStudentLevel, creditHours;

public:
    Course(){
        name = "";
        code = "";
        minStudentLevel = 0;
        creditHours = 0;
    };
    Course(string NAME, int LEVEL, int CREDITHOURS){
        name = NAME;
        minStudentLevel = LEVEL;
        creditHours = CREDITHOURS;
    }

    friend ostream& operator<<(ostream& os, const Course& course){
        os << "Course Code: " << course.code<<endl;
        os << "Course Name: " << course.name<<endl;
        os << "Course Credit Hours: " << course.creditHours<<endl;
        os << "Min. Student Level: " << course.minStudentLevel<<endl;
        return os;
    }

    void setName(string NAME){
        name = NAME;
    }
    string getName(){
        return name;
    }
    int getCreditHours(){
        return creditHours;
    }
    int getMinStudentLevel(){
        return minStudentLevel;
    }
    string getCode(){
        return code;
    }

};


#ifndef UNTITLED11_COURSE_H
#define UNTITLED11_COURSE_H

#endif
