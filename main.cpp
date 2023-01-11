#include <iostream>
#include <string>
#include <cstdint>
#include <vector>

#include "./header/studentRecordSystem.h"
#include "./resource/student.cpp"
#include "./resource/course.cpp"
#include "./resource/grade.cpp"
#include "./resource/studentRecord.cpp"

using namespace std;
void initializer();

studentRecord SR;

int main(){
    initializer();
    int stdId;

    cout << "Type Student ID : ";
    cin >> stdId;

    SR.getReportCard(stdId);

    return 0;
}

void initializer(){
    vector<course> courses = {course(1, "Algebra", 5), course(2, "Physics", 4), course(3, "English", 3), course(4, "Economics", 4)};
    vector<student> students = {student(1, "Thura"), student(2, "BBee")};
    vector<grade> grades = {grade(1, 1, B), grade(1, 2, A), grade(1, 3, C), grade(2, 1, A), grade(2, 2, A), grade(2, 3, B)};

    for(course& cour: courses){
        SR.addCourse(cour);
    }   

    for(student& stud: students){
        SR.addStudent(stud);
    }

    for(grade& grad: grades){
        SR.addGrade(grad);
    }
}
