#include <iostream>
#include "Multiplicadora.h"
#include "Somadora.h"
#include "Algarismos.h"
#include "Utils.h"

Utils utilsMulti;

void Multiplicadora::setValores(std::string fatorX, std::string fatorY, int base) {
    this -> fatorX = fatorX;
    this -> fatorY= fatorY;
    this -> base = base;

    this -> multiplicar();
}

std::string Multiplicadora::getResultado() {
    return this -> produto;
}

void Multiplicadora::multiplicar() {
    std::string result = "0";

    utilsMulti.matchNumberDigits(fatorX, fatorY);

    int multiplierOfLine = 0;
    std::string lineOfResult;

    for(int i = fatorY.length() - 1; i >= 0; i--)
    {
        if(fatorX[i] == ',')
            continue;

        lineOfResult = multiplyNumberToDigit(fatorX, fatorY[i], base);
        lineOfResult.insert(lineOfResult.end(), multiplierOfLine, '0'); // == multiplicar por 10 com base na linha

        Somadora s;
        s.setValores(result, lineOfResult, base);
        result = s.getResultado();
        multiplierOfLine++;
    }

    this -> produto = adjustComma(result, fatorX);
}

std::string Multiplicadora::multiplyNumberToDigit(std::string fatorX, char fatorY, int base)
{
    std::string result;
    char carga = '0';
    for(int i = fatorX.length() - 1; i >= 0; i--)
    {
        if(fatorX[i] == ',') {
            continue;
        }

        int multiplicationOfTwoNumbers = Algarismos::valorDe(fatorX[i]) * Algarismos::valorDe(fatorY) + Algarismos::valorDe(carga);
        result.insert(result.begin(), Algarismos::caracterDe(multiplicationOfTwoNumbers%base));
        carga = Algarismos::caracterDe(multiplicationOfTwoNumbers/base);
    }
    if(carga != '0')
        result.insert(result.begin(), carga);

    return result;
}

std::string Multiplicadora::adjustComma(std::string result, std::string someFator)
{
    int algarismoPosVirgula = (someFator.length() - 1 - someFator.find(',')) * 2;

    result.erase(result.find(','));
    result.insert(result.length() - algarismoPosVirgula, ",");

    return result;
}