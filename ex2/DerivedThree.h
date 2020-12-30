//
// Created by DN18657(DanNorström) on 02/01/2020.
//

#ifndef ASSIGNMENT2_DERIVEDTHREE_H
#define ASSIGNMENT2_DERIVEDTHREE_H

#include "ReadFilteredWords.h"
#include <cctype>

class DerivedThree : public ReadFilteredWords {

    public:
    explicit DerivedThree(const char *fname): ReadFilteredWords(fname){}

    bool filter(string word) override;

};


#endif //ASSIGNMENT2_DERIVEDTHREE_H
