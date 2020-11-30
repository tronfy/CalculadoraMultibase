#include "SomadoraUnica.h"

void SomadoraUnica::setValores(int x, int y, int base) {
    this -> fatorX = x;
    this -> fatorY = y;
    this -> base = base;

    this -> somar();
}

void SomadoraUnica::somar() {
    int soma = fatorX;

    for (int i = 0; i < fatorY; i++) {
        if (soma < base) {
            soma++;
        } else {
            soma = 0;
            carga++;
        }
    }

    this -> soma = soma;
}

int SomadoraUnica::getSoma() {
    return this -> soma;
}

int SomadoraUnica::getCarga() {
    return this -> carga;
}
