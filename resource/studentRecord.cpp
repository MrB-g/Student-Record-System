#include "../header/studentRecordSystem.h"

void studentRecord::addCourse(course course_i){
    courses.push_back(course_i);
}

void studentRecord::addStudent(student student_i){
    students.push_back(student_i);
}

void studentRecord::addGrade(grade grade_i){
    grades.push_back(grade_i);
}

int8_t studentRecord::getTotalCredits(){
    int8_t totalCredits;
    for(course& cour: courses){
        int8_t courseCredit = cour.getCredits();
        totalCredits += courseCredit;
    } 

    return totalCredits;
}

float studentRecord::getCourseCredit(int courId){
    float courseCredit;
    for(course& cour: courses){
        if(courId == cour.getCourseId()){
            courseCredit = cour.getCredits();
            break;
        } 
    }
    return courseCredit;
}

float studentRecord::getTotalPoints(int stdId){
    float totalPoints;
    for(grade& grd: grades){
        int gradeStudentId = grd.getStudentId();
        if(gradeStudentId == stdId){
            float studentGrade = (float)grd.getGrade();
            int studentCourseId = grd.getCourseId(); 
            float courseCredit = getCourseCredit(studentCourseId);
            totalPoints += (studentGrade * courseCredit);
        } else { 
            continue;
        }
    }
    return totalPoints;
}

float studentRecord::getGpa(int stdId){
    int8_t totalCredits = getTotalCredits();
    float totalPoints = getTotalPoints(stdId);
    float gpt = totalPoints / totalCredits;

    return gpt;
}

std::string studentRecord::getStudentName(int stdId){
    std::string studentName;
    for(student& stud: students){
        if(stud.getStudentId() == stdId){
            studentName = stud.getStudentName();
            break;
        }
    }
    return studentName;
}

std::string studentRecord::getCourseName(int courId){
    std::string courseName; 
    for(course& cour : courses){ 
        if(cour.getCourseId() == courId){
            courseName = cour.getCourseName();
            break;
        }
    }
    return courseName;
}

void studentRecord::getReportCard(int stdId){
    for(grade& grad : grades){
        if(grad.getStudentId() == stdId){
            std::cout << getStudentName(grad.getStudentId()) << " " << getCourseName(grad.getCourseId()) << " " << grad.getGrade() <<  " " << getGpa(stdId) << std::endl; 
        } else {
            continue;
        }
    }
}



