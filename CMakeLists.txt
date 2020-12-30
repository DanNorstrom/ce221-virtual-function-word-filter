cmake_minimum_required(VERSION 3.15)
project(Assignment2)

set(CMAKE_CXX_STANDARD 14)

include_directories(ex1)
include_directories(ex2)

add_executable(Assignment2
#        ex1/marks.txt
#        ex1/Person.cpp
#        ex1/Person.h
#        ex1/Student.h
#        ex1/studs.txt
#        ex1/Student.cpp
#        ex1/main.cpp)

        ex2/ReadFilteredWords.h
        ex2/ReadWords.cpp
        ex2/ReadWords.h ex2/ReadFilteredWords.cpp ex2/DerivedOne.cpp ex2/DerivedOne.h ex2/DerivedTwo.cpp ex2/DerivedTwo.h ex2/DerivedThree.cpp ex2/DerivedThree.h ex2/main.cpp ex2/1787.txt)
