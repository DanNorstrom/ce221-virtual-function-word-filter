//
// Created by DN18657(DanNorström) on 02/01/2020.
//

//#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "DerivedOne.h"
#include "DerivedTwo.h"
#include "DerivedThree.h"

using namespace std;

/* helper method to find all occurances of a given value */
vector<string> find_key(map<string,int> m, int v){
    vector<string> str;
    for (pair<string,int> p: m){
        if (p.second == v) {str.push_back(p.first);}
    }
    return str;
}

int main(){
    cout << "pick filename (1787.txt): ";
    string file; // = "C:\\dn18657\\CE221\\Assignment2\\Assignment2\\ex2\\1787.txt";
    cin >> file;
    const char *filename = file.c_str();

    // check and loop for filtertype
    cout << "\npick Filter 1,2 or 3: ";
    int filtertype;
    cin >> filtertype;

    while( (filtertype != 1) && (filtertype != 2) & (filtertype != 3)) {
        string dummy; // Reset Cin value for menu to work
        cin.clear();
        cin >> dummy;
        cout << "\nPlease type 1,2 or 3: ";
        cin >> filtertype;
    }

    // switch for filter type decision
    ReadFilteredWords* obj = NULL;
    switch(filtertype){
        case 1:
            obj = new DerivedOne(filename);
            break;
        case 2:
            obj = new DerivedTwo(filename);
            break;
        case 3:
            obj = new DerivedThree(filename);
            break;
        default:
            obj = new DerivedOne(filename);
            break;
    }


    // loop to put filtered file content into map
    map<string, int> filterMap = {};
    string nextWord = "PlaceHolder";
    while (nextWord != "") {
        nextWord = obj->getNextFilteredWord();

        if (filterMap.count(nextWord) == 1){
            // exists
            filterMap.at(nextWord) += 1;
        }
        else{
            // dosent
            filterMap.insert(make_pair(nextWord, 1));
        }
    }


    // move to vector to sort and find biggest values
    vector<int> v = {};
    int count_key = 0;
    int count_value = 0;
    for (pair<string,int> key : filterMap){
        cout << "\n" << key.first << " ~ " << key.second;       // shows entire map
        v.push_back(key.second);
        count_key++;
        count_value += key.second;
    }
    sort(v.rbegin(), v.rend());

    // report: One instance of 1st, one of 2nd and up to 10 instances of 3th. as specified in assignment.
    cout << "\n" << "Word Occurances: " << count_value << "\n";
    cout << "Unique Words: " << count_key << "\n";
    cout << "1st: ";
    for (string s: find_key(filterMap,v[0])){
        cout << s <<" ~ "<< v[0] << "\n";
        break;
    }
    cout << "2nd: ";
    for (string s: find_key(filterMap,v[1])){
        cout << s <<" ~ "<< v[1] << "\n";
        break;
    }
    cout << "3th: ";
    int counter;
    for (string s: find_key(filterMap,v[2])){
        if (counter <10){
            cout << s <<" ~ "<< v[2] << "\n";
            cout << "     ";
            counter++;
        }
        else{
            cout << "and " << (find_key(filterMap,v[2]).size() -10) << " more.";
            break;
        }
    }

    return 0;
}