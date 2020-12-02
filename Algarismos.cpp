#include <cstdio>
#include <cctype>
#include "Algarismos.h"

static const char algs[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                 'U', 'V', 'W', 'X', 'Y', 'Z'};

int Algarismos::valorDe(char c) {
    for (int i = 0; i < 36; i++) {
        if (algs[i] == c or algs[i] == toupper(c))
            return i;
    }
    throw "Caracter de algarismo invalido";
}

char Algarismos::caracterDe(int i) {
    if (i < 0 || i >= 36)
        throw "Valor de algarismo invalido";
    return algs[i];
}
