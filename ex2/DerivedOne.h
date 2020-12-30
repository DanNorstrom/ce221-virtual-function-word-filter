//
// Created by DN18657(DanNorström) on 02/01/2020.
//

#ifndef _DERIVEDONE_H
#define _DERIVEDONE_H

#include "ReadFilteredWords.h"
#include <cctype>


class DerivedOne: public ReadFilteredWords {

    public:
    explicit DerivedOne(const char *fname): ReadFilteredWords(fname){}

    bool filter(string word) override;

};


#endif //ASSIGNMENT2_DERIVEDONE_H
