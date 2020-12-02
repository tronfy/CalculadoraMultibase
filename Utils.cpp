#include <iostream>
#include <sstream>
#include <iomanip>
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

char Utils::toChar(int number)
{
    std::string stringNumber = std::to_string(number);
    return stringNumber[0];
}

void Utils::matchNumberDigits(std::string &number1, std::string &number2)
{
    std::stringstream tempNum;
    int comparator = number1.length() - number2.length();

    if(comparator > 0)
    {
        tempNum << std::setfill('0') << std::setw(number1.length()) << number2;
        number2 = tempNum.str();
    }
    if(comparator < 0)
    {
        tempNum << std::setfill('0') << std::setw(number2.length()) << number1;
        number1 = tempNum.str();
    }
}
