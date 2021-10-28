//
// Created by Константин Воронин on 06.10.2021.
//

#ifndef ACSHOMEWORK2_OBJECTORIENTED_H
#define ACSHOMEWORK2_OBJECTORIENTED_H


#include <cstdio>
#include "programming_language.h"

class objectoriented: public programming_language{
public:
    double indexTIOBE;
    char *name;
    int yearOfCreation;
    enum inheritance {
        SINGLE,
        MULTIPLE,
        INTERFACE
    };
    inheritance inheritanceType;
    void* In(FILE *file) override;

    void* InRnd() override;

    void Out(FILE *file) override;

// возвращает значение частного
// от деления objectoriented.yearOfCreation / objectoriented.name.size()
    double Quotient() override;

    objectoriented(){
        indexTIOBE = 0;
        name = "";
        yearOfCreation = 0;
        inheritanceType = SINGLE;
    };
};
#endif //ACSHOMEWORK2_OBJECTORIENTED_H
