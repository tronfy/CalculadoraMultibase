#ifndef CALCULADORAMULTIBASE_DIVISORA_H
#define CALCULADORAMULTIBASE_DIVISORA_H


#include <string>

class Divisora {
public:
    void setValores(std::string fatorX, std::string fatorY, int base);
    std::string getResultado();
private:
    std::string fatorX, fatorY, quociente;
    int base;
    void dividir();
    char acharQuociente(std::string dividendo, std::string divisor);
	std::string menorNumeroDivisivel(std::string dividendo, std::string divisor);
};


#endif //CALCULADORAMULTIBASE_DIVISORA_H