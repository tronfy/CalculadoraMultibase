#include <iostream>
#include <sstream>
#include "Utils.h"

int Utils::toInt(std::string stringNumber)
{
    try {
        int intNumber = 0;

        std::stringstream converterFromString(stringNumber);

        converterFromString >> intNumber;

        return  intNumber;
    }
    catch (char const* err) {
        std::cout << "Erro: " << err << std::endl;
        exit(1);
    }
}
