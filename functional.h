//
// Created by Константин Воронин on 06.10.2021.
//

#ifndef ACSHOMEWORK2_FUNCTIONAL_H
#define ACSHOMEWORK2_FUNCTIONAL_H


#include <cstdio>
#include "programming_language.h"

class functional : public programming_language {
public:
    double indexTIOBE;
    char *name;
    int yearOfCreation;
    enum typing {
        PRINCIPAL,
        DYNAMIC
    };

    typing typingScheme;

    bool supportOfLazyComputations;

    void* In(FILE *file) override;

    void* InRnd() override;

    void Out(FILE *file) override;

    // возвращает значение частного
    // от деления objectoriented.yearOfCreation / objectoriented.name.size()
    double Quotient() override;

    functional() {
        indexTIOBE = 0;
        yearOfCreation = 0;
        name = "";
        supportOfLazyComputations = false;
        typingScheme = DYNAMIC;
    }
};


#endif //ACSHOMEWORK2_FUNCTIONAL_H
