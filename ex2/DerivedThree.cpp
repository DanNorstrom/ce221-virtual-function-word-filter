//
// Created by DN18657(DanNorström) on 02/01/2020.
//

#include "DerivedThree.h"

/*looks for words with at least one letter and one punctuation character */
bool DerivedThree::filter(string word) {
    bool oneLetter = false;
    bool onePunct = false;

    for (char a: word){
        if (isalpha(a)){
            oneLetter = true;
        }
        if (ispunct(a)){
            onePunct = true;
        }
    }

    if (oneLetter && onePunct){
        return true;
    }
    else{
        return false;
    }
}