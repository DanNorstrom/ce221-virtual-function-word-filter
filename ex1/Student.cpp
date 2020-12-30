#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(const string &name, int regNo): Person(name) {
    this->regNo = regNo;
    marks = {};
}

int Student::getRegNo() const {
    return regNo;
}

map<string,float> Student::getMarks() const {
    return marks;
}

void Student::addMark(const string& module, float mark) {
    if (marks.insert(make_pair(module,mark)).second == false) {
        marks.at(module) = mark;
    }
}

float Student::getMark(const string &module) const{

    try{
        if(marks.at(module) !=false){
            return marks.at(module);
        }
        else{
            throw NoMarkException();
        }
    }
    catch(exception e) {
        return false;}
}

ostream& operator<<(ostream &str, const Student &s){
    // do this ad the end

    float min = 100;
    float max = 0;
    float avg = 0;
    for (pair<string,float> elem : s.marks){
        if(elem.second < min) { min = elem.second; }
        if(elem.second > max) { max = elem.second; }
        avg += elem.second;
    }
    avg /= s.marks.size();
    str << s.getName() << "[RegNo:" << s.getRegNo() << "](min: " << min << ", " << "max: " << max << ", "<< "avg: " << avg << ")";
    return str;
}

bool operator<(Student a, Student b)
{
    if (a.getRegNo() < b.getRegNo()) return true;
    if (a.getRegNo() > b.getRegNo()) return false;
}

