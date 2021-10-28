//
// Created by Константин Воронин on 08.10.2021.
//

#include "functional.h"
#include <cstdlib>
#include <cstring>
#include "filereader.h"
#include "StringRandomizer.h"

StringRandomizer stringRandomizer;
functional::typing ReadTypingScheme(FILE *pFile);

void* functional::In(FILE *file) {
    this->name = ReadStringFromFile(file);
    this->yearOfCreation = ReadIntegerFromFile(file);
    this->indexTIOBE = ReadIntegerFromFile(file);
    this->typingScheme = ReadTypingScheme(file);
    this->supportOfLazyComputations = ReadBooleanFromFile(file);
}

void* functional::InRnd() {
    this->name = stringRandomizer.GetRandomString(1 + (rand() % 15));
    this->yearOfCreation = 1957 + (rand() % 64);
    this->indexTIOBE = rand() % 100;
    int typingSchemeNumber = rand() % 2;
    switch (typingSchemeNumber) {
        case 0:
            this->typingScheme = functional::PRINCIPAL;
            break;
        case 1:
            this->typingScheme = functional::DYNAMIC;
            break;
    }
    this->supportOfLazyComputations = rand() % 2;
}

void functional::Out(FILE *file) {

    char *typingScheme;
    switch (this->typingScheme) {
        case 0:
            typingScheme = (char *) "Principle";
            break;
        case 1:
            typingScheme = (char *) "Dynamic";
            break;
    }
    fprintf(file, "Functional Programming Language: name = %s, yearOfCreation = %d,"
                  "indexTIOBE = %f, typingScheme = %s, supportOfLazyComputations = %d\n", this->name, this->yearOfCreation,
            this->indexTIOBE, typingScheme, this->supportOfLazyComputations);
}

double functional::Quotient() {
    return this->yearOfCreation / static_cast<double>(strlen(this->name));
}

functional::typing ReadTypingScheme(FILE *pFile) {
    char *inheritanceType = ReadStringFromFile(pFile);
    if (strcmp(inheritanceType, "Principle"))
        return functional::PRINCIPAL;
    if (strcmp(inheritanceType, "Dynamic"))
        return functional::DYNAMIC;
    return functional::PRINCIPAL;
}
