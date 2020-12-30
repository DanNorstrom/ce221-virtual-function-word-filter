#include "Student.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/* This method returns students with higher then the given mark */
void PrintStudentHigh(vector<Student> stu, float mark){

    vector<Student> acceptStu;
    for (Student s : stu) {
        map<string, float> sm = s.getMarks();
        for (pair<string,float> elem : sm) {
            if (elem.second > mark) {
                acceptStu.emplace_back(s);
                break;
            }
        }
    }

    sort(acceptStu.begin(), acceptStu.end());
    for (Student s : acceptStu) {
        cout << "\n" << s;
    }
}

/*  This method returns students with lower then the given mark in a module.  */
void PrintStudentLow(vector<Student> stu, string mod, float mark){

    vector<Student> acceptStu;
    cout << "for module " << mod << ": ";
    bool nomark = true;
    for (Student s : stu) {
        if (s.getMark(mod) == false){
            // no mark
        }
        else if (s.getMark(mod) <= mark) {
            nomark = false;
            acceptStu.emplace_back(s);
        }
    }

    sort(acceptStu.begin(), acceptStu.end());
    for (Student s : acceptStu) {
        cout << "\n" << "name: " << s.getName() << " mark: " << s.getMark(mod);
    }

    if (nomark) {cout << "no students with grades found for module: " << mod;}
}



int main() {
    // input
    vector<Student> stu;
    string file1 = "C:/dn18657/CE221/Assignment2/Assignment2/ex1/studs.txt";
    string file2 = "C:/dn18657/CE221/Assignment2/Assignment2/ex1/marks.txt";

    cout << "please enter filename for Students (studs.txt): " << endl;
    cin >> file1;
    cout << "please enter filename for Marks (marks.txt): " << endl;
    cin >> file2;

    // ## Open Files ##
    try {
        ifstream is(file1);
        string line,a, b, c;
        while (getline(is, line)) {
            stringstream ss(line);
            ss >> a >> b >> c;
            stu.emplace_back(Student(b + " " + c, stoi(a)));
        }


        ifstream is2(file2);
        string a2; int b2; float c2;
        while(getline(is2,line)){
            stringstream ss(line);
            ss >> a2 >> b2 >> c2;
            for (int i = 0; i < stu.size(); i++){
                if (stu[i].getRegNo() == b2) {
                    stu[i].addMark(a2,c2);
                    //cout << stu[i].getMark(a2)<<"\n";
                }
            }
        }

        if (!is.is_open() || !is2.is_open()){
            cout << "Files couldn't be opened";
            exit(1);
        }
        is.close();
        is2.close();
    }
    catch (exception e){e.what();}

    //## print all students and their modules ##
    sort(stu.begin(), stu.end());
    for (Student s: stu){
        map<string,float> marks = s.getMarks();
        cout << "\n" << s.getName() << "\n";
        for (pair<string,float> elem : marks){
            cout << elem.first << ": " << elem.second << "\n";
    }}

    // ## Loop ##
    while (true) {
        string answer;
        cout << "\n""\n""\n" << "To test method 1: type 1. \nFor method 2: type 2. \nIf you want to exit: type exit.\n";
        cin >> answer;

        if (answer == "1") {
            try {
                float answer;
                cout << "\n"<< "This method returns students with higher then the given mark. please type a float integer:";
                cin >> answer;
                PrintStudentHigh(stu, answer);
            }
            catch (exception e){e.what();}
        }
        if (answer == "2") {
            try {
                float mark;
                string mod;
                cout << "\n" << "This method returns students with lower then the given mark in a module. First, please type a float integer for marks:";
                cin >> mark;
                cout << "\n" << "Please type the module number, eg CE151: ";
                cin >> mod;
                PrintStudentLow(stu,mod,mark);
            }
            catch (exception e){e.what();}
        }

        if (answer == "exit") { exit(1);}
    }
}