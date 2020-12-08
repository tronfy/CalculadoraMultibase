#ifndef CALCULADORAMULTIBASE_SUBTRADORA_H
#define CALCULADORAMULTIBASE_SUBTRADORA_H

#include <string>

class Subtradora {
private:
    void subtrair();
    char subtracaoUnica(char number1, char number2);
public:
    std::string getResultado();
    void setValores(std::string fatorX, std::string fatorY, int base);
    std::string fatorX, fatorY, diferenca;
    int base;
    bool negativo;
};


#endif //CALCULADORAMULTIBASE_SUBTRADORA_H

