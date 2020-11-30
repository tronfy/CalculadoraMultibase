#include <iostream>
#include <sstream>

#include "Operacao.h"

int main() {
    try {

        std::cout << "Calculadora de bases\nProjeto II - TopiOO\n" << std::endl;

        int base;
        std::string opString;

        std::cout << "Insira a base desejada:";
        std::cin >> base;

        if (!(2 <= base && base <= 36)) {
            throw "Base invalida";
        }

        std::cout << "Insira uma operacao (ex. 12+34):";
        std::cin >> opString;

        Operacao operacao(opString, base);

        std::string fatorX = operacao.getFatorX();
        std::string fatorY = operacao.getFatorY();

        std::cout << "fatorX: " << operacao.getFatorX() << std::endl;
        std::cout << "operador: " << operacao.getOperador() << std::endl;
        std::cout << "fatorY: " << operacao.getFatorY() << std::endl;

        return 0;

    } catch (char const* err) {
        std::cout << "Erro: " << err << std::endl;
        exit(1);
    } /*catch (...) {
        std::cout << "Erro desconhecido";
        exit(1);
    }*/
}
