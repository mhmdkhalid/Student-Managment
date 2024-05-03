
class SummerCourse : public Course {
public:
    SummerCourse(){};
    SummerCourse(string NAME, int LEVEL, int CREDITHOURS) : Course(NAME,LEVEL,CREDITHOURS){
        name = NAME;
        minStudentLevel = LEVEL;
        creditHours = CREDITHOURS;
        code = name + "_S" + to_string(minStudentLevel);
    }
};
#ifndef UNTITLED11_SUMMERCOURSE_H
#define UNTITLED11_SUMMERCOURSE_H

#endif
