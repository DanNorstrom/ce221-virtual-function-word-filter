//
// Created by DN18657(DanNorström) on 02/01/2020.
//

#ifndef ASSIGNMENT2_DERIVEDTWO_H
#define ASSIGNMENT2_DERIVEDTWO_H

#include "ReadFilteredWords.h"
#include <cctype>

class DerivedTwo: public ReadFilteredWords {

    public:
    explicit DerivedTwo(const char *fname): ReadFilteredWords(fname){}

    bool filter(string word) override;

};


#endif //ASSIGNMENT2_DERIVEDTWO_H
