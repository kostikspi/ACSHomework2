//
// Created by Константин Воронин on 06.10.2021.
//

#ifndef ACSHOMEWORK2_PROGRAMMING_LANGUAGE_H
#define ACSHOMEWORK2_PROGRAMMING_LANGUAGE_H


#include <cstdio>

class programming_language {
public:
    virtual ~programming_language() = default;

    virtual void *In(FILE *file) = 0;

    virtual void *InRnd() = 0;

    virtual void Out(FILE *file) = 0;

// возвращает значение частного
// от деления programming_language.yearOfCreation / programming_language.name.size()
    virtual double Quotient() = 0;

};



#endif //ACSHOMEWORK2_PROGRAMMING_LANGUAGE_H
