#include <iostream>
#include "Somadora.h"
#include "Utils.h"
#include "SomadoraUnica.h"

Utils utils;
SomadoraUnica somadoraUnica;

void Somadora::setValores(std::string fatorX, std::string fatorY, int base) {
    this -> fatorX = fatorX;
    this -> fatorY= fatorY;
    this -> base = base;

    this -> somar();
}

std::string Somadora::getResultado() {
    return this -> soma;
}

void Somadora::somar() {
    std::string result;

    utils.matchNumberDigits(fatorX, fatorY);

    char carga = '0';
    for(int i = fatorX.length() - 1; i >= 0; i--)
    {
        if(fatorX[i] == ',')
        {
            result.insert(result.begin(), ',');
            continue;
        }

        somadoraUnica.somar(fatorX[i],
                            fatorY[i],
                            carga,
                            base);

        result.insert(result.begin(), somadoraUnica.getSoma());
        carga = somadoraUnica.getCarga();
    }
    if(carga != '0')
        result.insert(result.begin(), carga);

    this -> soma = result;
}
