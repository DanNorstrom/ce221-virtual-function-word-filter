//
// Created by DN18657(DanNorström) on 02/01/2020.
//

#include "DerivedTwo.h"

/*looks for words with at least 2 Letters and at least 1 numeric digit */
bool DerivedTwo::filter(string word) {
    int countLetters = 0;
    bool twoLetters = false;
    bool oneDigit = false;

    for (char a: word){
        if (isalpha(a)){
            countLetters +=1;
        }
        if (isdigit(a)){
            oneDigit = true;
        }
    }

    if (countLetters >= 2){
        twoLetters = true;
    }

    if (twoLetters && oneDigit){
        return true;
    }
    else{
        return false;
    }
}