#include "../header/studentRecordSystem.h"

course::course(int id_i, std::string name_i, int8_t credits_i){ 
    id = id_i;
    name = name_i; 
    credits = credits_i;
}

int course::getCourseId(){
    return id;
}

std::string course::getCourseName(){ 
    return name;
}

int8_t course::getCredits(){ 
    return credits;
}
