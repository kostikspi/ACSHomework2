//
// Created by Константин Воронин on 06.10.2021.
//

#ifndef ACSHOMEWORK2_CONTAINER_H
#define ACSHOMEWORK2_CONTAINER_H


#include <cstdio>
#include "programming_language.h"
#include "procedural.h"
#include "objectoriented.h"
#include "functional.h"

class container {
public:
    enum {
        max_len = 10000
    };
    int len;
    programming_language *content[max_len];

// Инициализация контейнера
    void Init();


// Ввод содержимого контейнера из указанного потока
    void In(FILE *file);

// Случайный ввод содержимого контейнера
    void InRnd(int size);

// Вывод содержимого контейнера в указанный поток
    void Out(FILE *file);


    container DeleteElementsLowerThanAverage();

    container(){};

    ~container();
};

#endif //ACSHOMEWORK2_CONTAINER_H
