#include <iostream>
#include <sstream>
#include <iomanip>
#include "Utils.h"
#include "Algarismos.h"

Algarismos algarismosUtil;

int Utils::toInt(std::string stringNumber)
{
    int intNumber = 0;

    for (int i = 0; i < stringNumber.length(); i++) {
        intNumber += algarismosUtil.valorDe(stringNumber[i]);
    }

    return intNumber;
}

char Utils::toChar(int number)
{
    std::string stringNumber = std::to_string(number);
    return stringNumber[0];
}

void Utils::matchNumberDigits(std::string &number1, std::string &number2)
{
    int commaPlace1, commaPlace2;
    std::string beforeComma1, beforeComma2, afterComma1, afterComma2;

    commaPlace1 = number1.find(',');
    commaPlace2 = number2.find(',');

    if(commaPlace1 == -1) {
        beforeComma1 = number1;
        afterComma1 = '0';
    }
    else {
        beforeComma1 = number1.substr(0, commaPlace1);
        afterComma1 = number1.substr(commaPlace1 + 1, number1.length());
    }

    if(commaPlace2 == -1){
        beforeComma2 = number2;
        afterComma2 = '0';
    }
    else{
        beforeComma2 = number2.substr(0, commaPlace2);
        afterComma2 = number2.substr(commaPlace2+1, number2.length());
    }

    matchNumberDigitsBeforeComma(beforeComma1, beforeComma2);
    matchNumberDigitsAfterComma(afterComma1, afterComma2);

    number1 = beforeComma1 + "," + afterComma1;
    number2 = beforeComma2 + "," + afterComma2;
}

void Utils::matchNumberDigitsBeforeComma(std::string &number1, std::string &number2)
{
    int comparator = number1.length() - number2.length();

    if(comparator > 0)
    {
        number2 = std::string(comparator, '0') + number2;
    }
    if(comparator < 0)
    {
        comparator = comparator * -1;
        number1 = std::string(comparator, '0') + number1;
    }
}

void Utils::matchNumberDigitsAfterComma(std::string &number1, std::string &number2)
{

    int comparator = number1.length() - number2.length();

    if(comparator > 0)
    {
        number2 = number2 + std::string(comparator, '0');
    }
    if(comparator < 0)
    {
        comparator = comparator * -1;
        number1 = number1 + std::string(comparator, '0');
    }
}

int Utils::compareTwoString(std::string number1, std::string number2)
{
    matchNumberDigits(number1, number2);

    int comparator = number1.length() - 
    number2.length();
    if(comparator != 0)
        return comparator;
		    
	else{
        for(int i=0; i<number1.length(); i++)
        {
            if(number1[i] == ',')
                continue;

            if(algarismosUtil.valorDe(number1[i]) > algarismosUtil.valorDe(number2[i]))
                return 1;
            if(algarismosUtil.valorDe(number1[i]) < algarismosUtil.valorDe(number2[i]))
                return -1;
        }
        return 0;
    }
}

std::string Utils::removeTrailingZeroes(std::string str) {
    int i = 0;
    while (str[i] == '0')
        i++;

    str.erase(0, i);

    return str;
}
