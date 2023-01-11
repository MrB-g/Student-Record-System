#include "../header/studentRecordSystem.h"

student::student(int id_i, std::string name_i){ 
    id = id_i;
    name = name_i;
}

int student::getStudentId(){
    return id;
}

std::string student::getStudentName(){
    return name;
}


