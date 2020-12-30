//
// Created by DN18657(DanNorström) on 02/01/2020.
//

#include "ReadFilteredWords.h"

/* Checks if getNextWord() is accepted by the filter */
string ReadFilteredWords::getNextFilteredWord() {

    while (isNextWord()) {
        string word = getNextWord();
        if (filter(word)) {
            return word;
        }
    }
    if (!isNextWord()) {
        return "";
    }
}


