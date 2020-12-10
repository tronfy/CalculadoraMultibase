#ifndef CALCULADORAMULTIBASE_UTILS_H
#define CALCULADORAMULTIBASE_UTILS_H


#include <string>

class Utils {
public:
    int toInt(std::string stringNumber);
    char toChar(int number);
	std::string toString(char caracter);
    void matchNumberDigits(std::string &number1, std::string &number2);
    int compareTwoString(std::string number1, std::string number2);
    std::string removeTrailingZeroes(std::string str);
	std::string removeLeadingZeroes(std::string str);
	std::string colocarZeros(std::string str, int qtdZeros);
	void matchNumberDigitsAfterComma(std::string &number1, std::string &number2);
private:
    void matchNumberDigitsBeforeComma(std::string &number1, std::string &number2);
};


#endif //CALCULADORAMULTIBASE_UTILS_H
