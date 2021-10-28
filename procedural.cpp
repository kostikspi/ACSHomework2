
#include <cstdlib>
#include "procedural.h"
#include "filereader.h"
#include "StringRandomizer.h"


void* procedural::In(FILE *file) {
    this->name = ReadStringFromFile(file);
    this->yearOfCreation = ReadIntegerFromFile(file);
    this->indexTIOBE = ReadIntegerFromFile(file);
    this->presenceOfADT = ReadIntegerFromFile(file);
}

void* procedural::InRnd() {
    StringRandomizer stringRandomizer;
    this->name = stringRandomizer.GetRandomString((1 + (rand() % 15)));
    this->yearOfCreation = 1957 + (rand() % 64);
    this->indexTIOBE = rand() % 100;
    this->presenceOfADT = rand() % 2;
}

void procedural::Out(FILE *file) {
    fprintf(file, "Procedural Programming Language: name = %s, yearOfCreation = %d, "
                  "indexTIOBE = %f, presenceOfADT = %d\n", this->name, this->yearOfCreation,
            this->indexTIOBE, this->presenceOfADT);
}

double procedural::Quotient() {
    return this->yearOfCreation / static_cast<double>(strlen(this->name));
}


