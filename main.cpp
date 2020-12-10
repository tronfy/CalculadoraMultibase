#include <iostream>
#include <sstream>

#include "Operacao.h"
#include "Calculator.h"

int main() {
    try {
        Calculator calculator;

        std::cout << "Calculadora de bases\nProjeto II - TopiOO\n" << std::endl;

        int base;

        std::cout << "Insira a base desejada:";
        std::cin >> base;

        if (!(2 <= base && base <= 36)) {
            throw "Base invalida";
        }

        std::string fatorX;
        std::string fatorY;
        char sinal;

        std::cout << "Insira o primeiro fator: ";
        std::cin >> fatorX;

        std::cout << "Insira o sinal de operacao: ";
        std::cin >> sinal;

        std::cout << "Insira o segundo fator: ";
        std::cin >> fatorY;
		
        Operacao operacao(fatorX, fatorY, sinal, base);
        std::cout << "Resposta: " << calculator.calculate(operacao) << std::endl;

        // std::cout << "sinalX: " << operacao.getSinalX() << std::endl;
        // std::cout << "fatorX: " << operacao.getFatorX() << std::endl;
        // std::cout << "operador: " << operacao.getOperador() << std::endl;
        // std::cout << "sinalX: " << operacao.getSinalY() << std::endl;
        // std::cout << "fatorY: " << operacao.getFatorY() << std::endl;

        return 0;

    } catch (char const* err) {
        std::cout << "Erro: " << err << std::endl;
        exit(1);
    } /*catch (...) {
        std::cout << "Erro desconhecido";
        exit(1);
    }*/
}
