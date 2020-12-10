#include "Operacao.h"
#include "Algarismos.h"

void Operacao::analisar() {
    std::size_t pos;

    pos = opString.find('+');
    operador = '+';
    if (pos == std::string::npos) {
        operador = '-';
        pos = opString.find('-');
    }
    if (pos == std::string::npos) {
        operador = '*';
        pos = opString.find('*');
    }if (pos == std::string::npos) {
        operador = '/';
        pos = opString.find('/');
    }
    if (pos == std::string::npos) {
        throw "Operacao invalida";
    }

    std::string fatorX = opString.substr(0, pos);
    std::string fatorY = opString.substr(pos+1);

    for (char chr : fatorX) {
        if(chr == ',' || chr == '.')
            continue;

        int val = Algarismos::valorDe(chr);

        if (val >= base)
            throw "Um ou mais algarismos nao pertencem a base";
    }

    for (char chr : fatorY) {
        if(chr == ',' || chr == '.')
            continue;

        int val = Algarismos::valorDe(chr);

        if (val >= base)
            throw "Um ou mais algarismos nao pertencem a base";
    }

    this -> fatorX = fatorX;
    this -> fatorY = fatorY;
}

std::string Operacao::getFatorX() {
    return this -> fatorX;
}

std::string Operacao::getFatorY() {
    return this -> fatorY;
}

int Operacao::getBase() {
    return this -> base;
}

char Operacao::getOperador() {
    return this -> operador;
}