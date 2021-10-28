//
// Created by Константин Воронин on 06.10.2021.
//

#include <cstdlib>
#include "container.h"
#include "programming_language.h"
#include "procedural.h"
#include "objectoriented.h"
#include "functional.h"

void container::Init() {
    this->len = 0;
}

void container::In(FILE *file) {
    while (!feof(file)) {
        programming_language* pl;
        int programming_language_type;
        fscanf(file, "%d", &programming_language_type);
        switch (programming_language_type) {
            case 1:
                pl = new procedural;
                break;
            case 2:
                pl = new objectoriented;
                break;
            case 3:
                pl = new functional;
                break;
            default:
                pl = nullptr;
        }

        if (pl != nullptr) {
            pl->In(file);
            this->content[this->len] = pl;
            this->len++;
        }
    }
}

void container::InRnd(int size) {
    while (this->len < size) {
        int k = rand() % 3 + 1;
        programming_language *pl;
        switch (k) {
            case 1:
                pl = new procedural;
                break;
            case 2:
                pl = new objectoriented;
                break;
            case 3:
                pl = new functional;
                break;
        }
        if (pl != nullptr) {
            pl->InRnd();
            this->content[len] = pl;
            this->len++;
        }
    }
}

void container::Out(FILE *file) {
    fprintf(file, "Container has %d elements.\n", this->len);
    for (int i = 0; i < this->len; i++) {
        this->content[i]->Out(file);
    }
}

container container::DeleteElementsLowerThanAverage() {
    double averageQuotient, sum = 0;
    container newContainer;
    newContainer.Init();
    for (int i = 0; i < this->len; i++) {
        sum += this->content[i]->Quotient();
    }
    averageQuotient = sum / this->len;
    int index = 0;
    int count = 0;
    for (int i = 0; i < this->len; i++) {
        if (this->content[i]->Quotient() > averageQuotient) {
            count++;
        }
    }
    newContainer.InRnd(count);
    for (int i = 0; i < this->len; i++) {
        if (this->content[i]->Quotient() < averageQuotient) {
            continue;
        }
        *(newContainer.content[index]) = *(this->content[i]);
        index++;
    }

    return newContainer;
}

container::~container() {
    for (int i = 0; i < this->len; i++) {
        delete content[i];
    }
    len = 0;
}
