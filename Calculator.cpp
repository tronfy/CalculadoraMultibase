#include <iostream>
#include "Calculator.h"
#include "Utils.h"

#include "Somadora.h"
#include "Multiplicadora.h"
#include "Subtradora.h"
#include "Divisora.h"

std::string Calculator::calculate(Operacao op)
{
    std::string resp = "0";

    Somadora soma;
    Multiplicadora multiplicacao;
	Subtradora subtracao;
	Divisora divisora;

    switch (op.getOperador())
    {
        case '+':
            soma.setValores(op.getFatorX(), op.getFatorY(), op.getBase());
            resp = soma.getResultado();
            break;

        case '-':
			subtracao.setValores(op.getFatorX(), op.getFatorY(), op.getBase());
			resp = subtracao.getResultado();
            break;

        case '*':
            multiplicacao.setValores(op.getFatorX(), op.getFatorY(), op.getBase());
            resp = multiplicacao.getResultado();
            break;

        case '/':
			divisora.setValores(op.getFatorX(), op.getFatorY(), op.getBase());
			resp = divisora.getResultado();
            break;

        default:
            throw "Impossível executar operação";
    }

    return resp;
}
