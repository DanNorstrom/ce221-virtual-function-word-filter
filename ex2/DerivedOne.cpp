//
// Created by DN18657(DanNorström) on 02/01/2020.
//

#include "DerivedOne.h"

/*looks for words with 1 lower-case, no upper-cases */
bool DerivedOne::filter(string word) {
    bool oneLowercase = false;
    bool noUppercase = true;
    for (char a: word){
        if (isupper(a)){
            noUppercase = false;
        }
        else if (islower(a)){
            oneLowercase = true;
        }
    }
    if (oneLowercase && noUppercase){
        return true;
    }
    else{
        return false;
    }
}