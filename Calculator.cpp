#include <iostream>
#include "Calculator.h"
#include "Utils.h"

#include "Somadora.h"
#include "Multiplicadora.h"
#include "Subtradora.h"
#include "Divisora.h"

Utils utilsCalc;

Somadora soma;
Multiplicadora multiplicacao;
Subtradora subtracao;
Divisora divisora;

std::string Calculator::calculate(Operacao op)
{
    std::string resp = "0";
	
    switch (op.getOperador())
    {
        case '*':
            multiplicacao.setValores(op.getFatorX(), op.getFatorY(), op.getBase());
            if (op.getSinalX() != op.getSinalY())
                resp = '-';
            resp += multiplicacao.getResultado();
            break;

        case '/':
			divisora.setValores(op.getFatorX(), op.getFatorY(), op.getBase());
            if (op.getSinalX() != op.getSinalY())
                resp = '-';
			resp += divisora.getResultado();
            break;

        default:
            if (op.getSinalX() == '+') {
                if (op.getOperador() == '+') {
                    if (op.getSinalY() == '+') // +++
                        resp = resumoSoma(op, op.getFatorX(), op.getFatorY(), op.getBase());
                    else // ++-
                        resp = resumoSubtracao(op, op.getFatorX(), op.getFatorY(), op.getBase());
                } else {
                    if (op.getSinalY() == '+') // +-+
                        resp = resumoSubtracao(op, op.getFatorX(), op.getFatorY(), op.getBase());
                    else // +--
                        resp = resumoSoma(op, op.getFatorX(), op.getFatorY(), op.getBase());
                }
            } else {
                if (op.getOperador() == '+') {
                    if (op.getSinalY() == '+') // -++
                        resp = resumoSubtracao(op, op.getFatorX(), op.getFatorY(), op.getBase());
                    else // -+-
                        resp = '-' + resumoSoma(op, op.getFatorX(), op.getFatorY(), op.getBase());
                } else {
                    if (op.getSinalY() == '+') // --+
                        resp = '-' + resumoSoma(op, op.getFatorX(), op.getFatorY(), op.getBase());
                    else // ---
                        resp = resumoSubtracao(op, op.getFatorX(), op.getFatorY(), op.getBase());
                }
            }
			

			// throw "Sinal inválido"
    }

    return resp;
}

std::string Calculator::resumoSoma(Operacao op, std::string x, std::string y, int base) {
    soma.setValores(x, y, base);
    return soma.getResultado();
}

std::string Calculator::resumoSubtracao(Operacao op, std::string x, std::string y, int base)
{
    char sinalRes;
    if (utilsCalc.compareTwoString(x, y) > 0)
        sinalRes = op.getSinalX();
    else sinalRes = op.getSinalY();

    subtracao.setValores(x, y, base);
	return sinalRes + subtracao.getResultado();
}