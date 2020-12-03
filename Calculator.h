#ifndef CALCULADORAMULTIBASE_CALCULATOR_H
#define CALCULADORAMULTIBASE_CALCULATOR_H

#include "Operacao.h"

class Calculator {
private:
    std::string sum(std::string number1, std::string number2, int base);
    int subtraction(std::string number1, std::string number2, int base);
    std::string multiplication(std::string number1, std::string number2, int base);
    std::string multiplyNumberToDigit(std::string number1, char number2, int base);
    float division(std::string number1, std::string number2, int base);

public:
    std::string calculate(Operacao operation);
};


#endif //CALCULADORAMULTIBASE_CALCULATOR_H
