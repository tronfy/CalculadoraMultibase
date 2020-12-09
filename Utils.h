#ifndef CALCULADORAMULTIBASE_UTILS_H
#define CALCULADORAMULTIBASE_UTILS_H


#include <string>

class Utils {
public:
    int toInt(std::string stringNumber);
    char toChar(int number);
    void matchNumberDigits(std::string &number1, std::string &number2);
    int compareTwoString(std::string number1, std::string number2);
    std::string removeTrailingZeroes(std::string str);
private:
    void matchNumberDigitsBeforeComma(std::string &number1, std::string &number2);
    void matchNumberDigitsAfterComma(std::string &number1, std::string &number2);
};


#endif //CALCULADORAMULTIBASE_UTILS_H
