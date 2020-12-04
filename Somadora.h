#ifndef CALCULADORAMULTIBASE_SOMADORA_H
#define CALCULADORAMULTIBASE_SOMADORA_H


#include <string>

class Somadora {
public:
    void setValores(std::string fatorX, std::string fatorY, int base);
    std::string getResultado();
private:
    std::string fatorX, fatorY, soma;
    int base;
    void somar();
};


#endif //CALCULADORAMULTIBASE_SOMADORA_H
