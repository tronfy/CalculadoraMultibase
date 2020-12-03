#include <iostream>
#include "Calculator.h"
#include "Utils.h"

#include "Somadora.h"
#include "Multiplicadora.h"

std::string Calculator::calculate(Operacao op)
{
    std::string resp = "0";

    Somadora s;
    Multiplicadora m;

    switch (op.getOperador())
    {
        case '+':
            s.setValores(op.getFatorX(), op.getFatorY(), op.getBase());
            resp = s.getResultado();
            break;

        case '-':
            break;

        case '*':
            m.setValores(op.getFatorX(), op.getFatorY(), op.getBase());
            resp = m.getResultado();
            break;

        case '/':
            break;

        default:
            throw "Impossível executar operação";
    }

    return resp;
}
