#ifndef CALCULADORAMULTIBASE_MULTIPLICADORA_H
#define CALCULADORAMULTIBASE_MULTIPLICADORA_H


#include <string>

class Multiplicadora {
public:
    void setValores(std::string fatorX, std::string fatorY, int base);
    std::string getResultado();
private:
    std::string fatorX, fatorY, produto;
    int base;
    void multiplicar();
    std::string multiplyNumberToDigit(std::string fatorX, char fatorY, int base);
    std::string adjustComma(std::string result, std::string someFator);
};


#endif //CALCULADORAMULTIBASE_MULTIPLICADORA_H
