#ifndef STUDENT_RECORD_SYSTEM
#define STUDENT_RECORD_SYSTEM

#include <vector>
#include <string>
#include <cstdint>

enum GRADESYMBOL {F, E, D, C, B, A};

class student { 
    public:
        student(int id_i, std::string name_i);
        int getStudentId();
        std::string getStudentName();
    private:
        int id;
        std::string name;
};

class course { 
    public:
        course(int id_i, std::string naem_i, int8_t credits_i);
        int getCourseId();
        std::string getCourseName();
        int8_t getCredits();
    private: 
        int id;
        std::string name;
        int8_t credits;
};

class grade { 
    public:
        grade(int studentId_i, int courseId_i, GRADESYMBOL studentGrade_i);
        int getStudentId();
        int getCourseId();
        GRADESYMBOL getGrade();
    private:
        int studentId;
        int courseId;
        GRADESYMBOL studentGrade;
};

class studentRecord { 
    public:
        void addCourse(course course_i);
        void addStudent(student student_i);
        void addGrade(grade grade_i);
        
        void getReportCard(int);
        void printReportCard(int);
        std::string getStudentName(int);
        std::string getCourseName(int);

        int8_t getTotalCredits();
        float getCourseCredit(int);
        float getTotalPoints(int);
        float getGpa(int);
    private:
        std::vector<course> courses;
        std::vector<student> students;
        std::vector<grade> grades;
};

#endif
