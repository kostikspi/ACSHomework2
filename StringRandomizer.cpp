//
// Created by Константин Воронин on 07.10.2021.
//

#include "StringRandomizer.h"


#include <cstdio>
#include <cstdlib>

char* StringRandomizer::GetRandomString(int length) {
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+#.";
    char *string = (char *) malloc(length);
    for (int i = 0; i < length; i++) {
        int randomChar = rand() % 65;
        string[i] = letters[randomChar];
    }
    return string;
}