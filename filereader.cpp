//
// Created by Константин Воронин on 07.10.2021.
//

#include "filereader.h"

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstddef>

int ReadIntegerFromFile(FILE *file) {
    int output = 0;
    fscanf(file, "%d", &output);
    return output;
}

bool ReadBooleanFromFile(FILE *file) {
    bool output = 0;
    fscanf(file, "%d", &output);
    return output;
}

char *ReadStringFromFile(FILE *file) {
    char outputCharArray[1000];
    fscanf(file, "%s", outputCharArray);
    char *output = (char *) malloc(strlen(outputCharArray));
    for (int i = 0; i < strlen(outputCharArray); i++) {
        output[i] = outputCharArray[i];
    }
    return output;
}
