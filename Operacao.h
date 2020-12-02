#ifndef CALCULADORAMULTIBASE_OPERACAO_H
#define CALCULADORAMULTIBASE_OPERACAO_H


#include <string>

class Operacao {
private:
    std::string opString;
    std::string fatorX, fatorY;
    int base;
    char operador;
    void analisar();
public:
    explicit Operacao(std::string opString, int base) {
        this -> opString = opString;
        fatorX = fatorY = "";
        this -> base = base;
        operador = '_';
        this -> analisar();
    }
    std::string getFatorX();
    std::string getFatorY();
    int getBase();
    char getOperador();
};


#endif //CALCULADORAMULTIBASE_OPERACAO_H
