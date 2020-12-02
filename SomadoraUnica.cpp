#include "SomadoraUnica.h"
#include "Algarismos.h"

Algarismos algarismos;

void SomadoraUnica::somar(char x, char y, char carga, int base) {
    int soma = algarismos.valorDe(x) +
                algarismos.valorDe(y) +
                algarismos.valorDe(carga);

    this -> carga = algarismos.caracterDe(soma / base);
    this -> soma = algarismos.caracterDe(soma % base);
}

char SomadoraUnica::getSoma() {
    return this -> soma;
}

char SomadoraUnica::getCarga() {
    return this -> carga;
}
