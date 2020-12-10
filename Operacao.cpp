#include "Operacao.h"
#include "Algarismos.h"

void Operacao::analisar() {
    std::size_t pos;

    this -> xNegativo = false;
    this -> yNegativo = false;

    if (fatorX[0] == '-') {
        xNegativo = true;
        fatorX.erase(0, 1);
    } else if (fatorX[0] == '+') {
        fatorX.erase(0, 1);
    }

    if (fatorY[0] == '-') {
        yNegativo = true;
        fatorY.erase(0, 1);
    } else if (fatorY[0] == '+') {
        fatorY.erase(0, 1);
    }

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
    // return this -> fatorX.substr(1, fatoX.length());
}

std::string Operacao::getFatorY() {
	return this -> fatorY;
    // return this -> fatorY.substr(1, fatorY.length());
}

char Operacao::getSinalX() {
    if (this -> xNegativo)
        return '-';
    else return '+';
}

char Operacao::getSinalY() {
    if (this -> yNegativo)
        return '-';
    else return '+';
}

int Operacao::getBase() {
    return this -> base;
}

char Operacao::getOperador() {
    return this -> operador;
}