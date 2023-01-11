#include "../header/studentRecordSystem.h"

grade::grade(int studentId_i, int courseId_i, GRADESYMBOL studentGrade_i){
    studentId = studentId_i;
    courseId = courseId_i;
    studentGrade = studentGrade_i; 
}

int grade::getStudentId(){
    return studentId;
}

int grade::getCourseId(){
    return courseId;
}

GRADESYMBOL grade::getGrade(){
    return studentGrade;
}
