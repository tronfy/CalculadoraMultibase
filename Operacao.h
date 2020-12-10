#ifndef CALCULADORAMULTIBASE_OPERACAO_H
#define CALCULADORAMULTIBASE_OPERACAO_H


#include <string>

class Operacao {
private:
    std::string fatorX, fatorY;
    int base;
    bool xNegativo, yNegativo;
    char operador;
    void analisar();
public:
    explicit Operacao(std::string fatorX, std::string fatorY, char op, int base) {
        this -> fatorX = fatorX;
        this -> fatorY = fatorY;
        this -> base = base;
        operador = op;
        this -> analisar();
    }
    std::string getFatorX();
    std::string getFatorY();
    char getSinalX();
    char getSinalY();
    int getBase();
    char getOperador();
};


#endif //CALCULADORAMULTIBASE_OPERACAO_H
