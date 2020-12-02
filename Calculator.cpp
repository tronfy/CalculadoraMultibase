#include <iostream>
#include "Calculator.h"
#include "Utils.h"
#include "SomadoraUnica.h"
#include "Algarismos.h"
Utils utils;
SomadoraUnica somadoraUnica;

std::string Calculator::calculate(Operacao operation)
{
    std::string resp = "0";

    switch (operation.getOperador())
    {
        case '+':
            resp = sum(operation.getFatorX(),
                operation.getFatorY(),
                operation.getBase());
            break;
        case '-':
            break;
        case '*':
            break;
        case '/':
            break;
        default:
            throw "Impossível executar operação";
    }

    return resp;
}

std::string Calculator::sum(std::string number1, std::string number2, int base)
{
    std::string result;

    utils.matchNumberDigits(number1, number2);

    char carga = '0';
    for(int i = number1.length() - 1; i >= 0; i--)
    {
        somadoraUnica.somar(number1[i],
                            number2[i],
                            carga,
                            base);

        result.insert(result.begin(), somadoraUnica.getSoma());
        carga = somadoraUnica.getCarga();
    }
    if(carga != '0')
        result.insert(result.begin(), carga);


    return result;
}
