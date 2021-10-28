#include <iostream>
#include "container.h"
#include <cstdio>
#include <fstream>
#include <cstring>


void errMessage1() {
    std::cout << "incorrect command line!\n"
                 "  Waited:\n"
                 "     command -f infile outfile01 outfile02\n"
                 "  Or:\n"
                 "     command -n number outfile01 outfile02\n";
}

void errMessage2() {
    std::cout << "incorrect qualifier value!\n"
                 "  Waited:\n"
                 "     command -f infile outfile01 outfile02\n"
                 "  Or:\n"
                 "     command -n number outfile01 outfile02\n";
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    std::cout << "Start" << std::endl;
    container c = {};
    c.Init();
    int size;

    ////cout << "argv[1] = " << argv[1] << "\n";
    if (!strcmp(argv[1], "-f")) {
        FILE *file = fopen(argv[2], "rw");
        c.In(file);
        fclose(file);
    } else if (!strcmp(argv[1], "-n")) {
        size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            std::cout << "incorrect number of languages = "
                      << size
                      << ". Set 0 < number <= 10000\n";
            return 3;
        }
        c.InRnd(size);
    } else {
        errMessage2();
        return 2;
    }

    // Автоматическое выделение памяти для массива
    /* programming_language arr[size];
    Init(c, arr);
    std::cout << "size = " << size << "\n"; */


    // Вывод содержимого контейнера в файл
    FILE *outputFile = fopen(argv[3], "w+");
    fprintf(outputFile, "Filled container:\n");
    c.Out(outputFile);

    // The 2nd part of task
    FILE *sortedOutputFile = fopen(argv[4], "w+");
    container sortedContainer = c.DeleteElementsLowerThanAverage();
    fprintf(sortedOutputFile, "Container without elements lower then average: \n");
    sortedContainer.Out(sortedOutputFile);
    
    std::cout << "Stop" << std::endl;
    fclose(outputFile);
    fclose(sortedOutputFile);
    return 0;
}
