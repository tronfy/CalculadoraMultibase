#include "SomadoraUnica.h"

void SomadoraUnica::setValores(int x, int y, int base) {
    this -> fatorX = x;
    this -> fatorY = y;
    this -> base = base;

    this -> somar();
}

void SomadoraUnica::somar() {
    int soma = fatorX + fatorY;

    this -> carga = soma / base;
    this -> soma = soma % base;
}

int SomadoraUnica::getSoma() {
    return this -> soma;
}

int SomadoraUnica::getCarga() {
    return this -> carga;
}
