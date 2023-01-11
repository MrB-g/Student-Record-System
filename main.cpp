#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <fstream>
#include <map>

#include "./header/studentRecordSystem.h"

#include "./resource/student.cpp"
#include "./resource/course.cpp"
#include "./resource/grade.cpp"
#include "./resource/studentRecord.cpp"

using namespace std;

void initializer();
void readAndAddData(string, string, vector<course>&, vector<student>&, vector<grade>&);
GRADESYMBOL enumGradeSymbolConverter(string);

studentRecord SR;

int main(){
    initializer();
    int stdId;
    string print;

    cout << "Type Student ID : ";
    cin >> stdId;
    SR.getReportCard(stdId);

    cout << "Do you want to print that report? ";
    cin >> print;

    if(print == "Yes"){
        cout << "Successly printed. You can check your printed report in the reportcard file." << endl;
        SR.printReportCard(stdId);
    }

    return 0;
}


void initializer(){
    vector<course> courses;
    vector<student> students;
    vector<grade> grades;

    readAndAddData("./data/courses.txt", "course", courses, students, grades);
    readAndAddData("./data/students.txt", "student", courses, students, grades);
    readAndAddData("./data/grades.txt", "grade", courses, students, grades);

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

GRADESYMBOL enumGradeSymbolConverter(string studentGrade){
    map<string, GRADESYMBOL> gradeMap;
    gradeMap["A"] = GRADESYMBOL::A;
    gradeMap["B"] = GRADESYMBOL::B;
    gradeMap["C"] = GRADESYMBOL::C;
    gradeMap["D"] = GRADESYMBOL::D;
    gradeMap["E"] = GRADESYMBOL::E;
    gradeMap["F"] = GRADESYMBOL::F;
    return gradeMap[studentGrade];
}

void readAndAddData(string filePath, string type, vector<course>& cour, vector<student>& stud, vector<grade>& grad){
    fstream readFile;
    readFile.open(filePath, ios::in);
    if(readFile.is_open()){
        string output;
        while(readFile){
            if(type == "course"){
                int id, courseCredit;
                string courseName;
                getline(readFile, output);
                try {
                    id = stoi(output);
                } catch(const invalid_argument& e){}
                getline(readFile, output);
                courseName = output;
                getline(readFile, output);
                try {
                    courseCredit = stoi(output);
                } catch(const invalid_argument& e){}
                getline(readFile, output);
                cour.push_back(course(id, courseName, courseCredit));
            } else if(type == "student"){
                int id;
                string studentName;
                getline(readFile, output);
                try { 
                    id = stoi(output);
                } catch(const invalid_argument& e){}
                getline(readFile, output);
                studentName = output;
                getline(readFile, output);
                stud.push_back(student(id, studentName));
            } else if(type == "grade"){
                int studentId, courseId;
                GRADESYMBOL studentGrade;
                getline(readFile, output);
                try {
                    studentId = stoi(output);
                } catch(const invalid_argument& e){}
                getline(readFile, output);
                try {
                    courseId = stoi(output);
                } catch(const invalid_argument& e){}
                getline(readFile, output);
                studentGrade = enumGradeSymbolConverter(output);
                getline(readFile, output);
                grad.push_back(grade(studentId, courseId, studentGrade));
            }
        }
        readFile.close();
    }
}
