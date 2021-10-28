//
// Created by Константин Воронин on 06.10.2021.
//

#include <cstdlib>
#include <cstring>
#include "objectoriented.h"
#include "filereader.h"
#include "StringRandomizer.h"

objectoriented::inheritance ReadInheritanceType(FILE *pFile);

void* objectoriented::In(FILE *file) {
    this->name = ReadStringFromFile(file);
    this->yearOfCreation = ReadIntegerFromFile(file);
    this->indexTIOBE = ReadIntegerFromFile(file);
    this->inheritanceType = ReadInheritanceType(file);
}

void* objectoriented::InRnd() {
    StringRandomizer stringRandomizer;
    this->name = stringRandomizer.GetRandomString(1 + (rand() % 15));
    this->yearOfCreation = 1957 + (rand() % 64);
    this->indexTIOBE = 2 + rand() % 98;
    int inheritanceTypeNumber = rand() % 3;
    switch (inheritanceTypeNumber) {
        case 0:
            this->inheritanceType = objectoriented::SINGLE;
            break;
        case 1:
            this->inheritanceType = objectoriented::MULTIPLE;
            break;
        case 2:
            this->inheritanceType = objectoriented::INTERFACE;
            break;
        default:
            this->inheritanceType = objectoriented::SINGLE;
            break;
    }
}

void objectoriented::Out(FILE *file) {

    char *inheritanceType;
    switch (this->inheritanceType) {
        case 0:
            inheritanceType = (char *) "Single";
            break;
        case 1:
            inheritanceType = (char *) "Multiple";
            break;
        case 2:
            inheritanceType = (char *) "Interface";
            break;

    }
    fprintf(file,
            "Object Oriented Programming Language: name = %s, yearOfCreation = %d,indexTIOBE = %f, inheritanceType = %s\n",
            this->name, this->yearOfCreation, this->indexTIOBE, inheritanceType);
}

double objectoriented::Quotient() {
    return this->yearOfCreation / static_cast<double>(strlen(this->name));
}

objectoriented::inheritance ReadInheritanceType(FILE *pFile) {
    char *inheritanceType = ReadStringFromFile(pFile);
    if (strcmp(inheritanceType, "Single") == 0)
        return objectoriented::SINGLE;
    if (strcmp(inheritanceType, "Multiple") == 0)
        return objectoriented::MULTIPLE;
    if (strcmp(inheritanceType, "Interface") == 0)
        return objectoriented::INTERFACE;
    return objectoriented::MULTIPLE;
}
