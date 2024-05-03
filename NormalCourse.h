
class NormalCourse : public Course {
public:
    NormalCourse(){};
    NormalCourse(string NAME, int LEVEL, int CREDITHOURS) : Course(NAME,LEVEL,CREDITHOURS){
        name = NAME;
        minStudentLevel = LEVEL;
        creditHours = CREDITHOURS;
        code = name + "_N" + to_string(minStudentLevel);
    }
};
#ifndef UNTITLED11_NORMALCOURSE_H
#define UNTITLED11_NORMALCOURSE_H

#endif