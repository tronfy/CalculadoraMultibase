#ifndef CALCULADORAMULTIBASE_CALCULATOR_H
#define CALCULADORAMULTIBASE_CALCULATOR_H

#include "Operacao.h"

class Calculator {
public:
    std::string calculate(Operacao op);
private:
    std::string resumoSoma(Operacao op, std::string x, std::string y, int base);
	std::string resumoSubtracao(Operacao op, std::string x, std::string y, int base);
};


#endif //CALCULADORAMULTIBASE_CALCULATOR_H
