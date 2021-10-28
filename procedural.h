//
// Created by Константин Воронин on 06.10.2021.
//

#ifndef ACSHOMEWORK2_PROCEDURAL_H
#define ACSHOMEWORK2_PROCEDURAL_H

#include "cstdio"
#include "programming_language.h"

class procedural: public programming_language{
public:
    double indexTIOBE;
    char *name;
    int yearOfCreation;
    bool presenceOfADT;

    void* In(FILE *file) override;

    void* InRnd() override;

    void Out(FILE *file) override;

// возвращает значение частного
// от деления procedural.yearOfCreation / procedural.name.size()
    double Quotient() override;

    procedural() {
        indexTIOBE = 0;
        yearOfCreation = 0;
        name = "";
        presenceOfADT = false;
    }
};


#endif //ACSHOMEWORK2_PROCEDURAL_H
