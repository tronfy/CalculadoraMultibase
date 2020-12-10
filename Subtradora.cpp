#include <iostream>
#include "Subtradora.h"
#include "Utils.h"
#include "Algarismos.h"

Utils utilsSub;
Algarismos algarismosSub;


void Subtradora::setValores(std::string fatorX, std::string fatorY, int base) {
    this -> fatorX = fatorX;
    this -> fatorY= fatorY;
    this -> base = base;
	this -> diferenca = "";

    this -> negativo = utilsSub.compareTwoString(fatorX, fatorY) < 0;
    // garante que o fatorX é sempre maior que o fatorY
    if(utilsSub.compareTwoString(fatorX, fatorY) < 0)
    {
        this -> fatorX = fatorY;
        this -> fatorY= fatorX;
    }

    this -> subtrair();
}

std::string Subtradora::getResultado()
{
    return this -> diferenca;
}

void Subtradora::subtrair() {
    std::string result;

    utilsSub.matchNumberDigits(fatorX, fatorY);

    // compareTwoString == 0 -> os dois são iguais
    if(utilsSub.compareTwoString(fatorX, fatorY) == 0)
    {
        this -> diferenca = "0";
        return;
    }

    for(int i = fatorX.length() - 1; i >= 0; i--)
    {
        if(fatorX[i] == ',')
        {
            result.insert(result.begin(), ',');
            continue;
        }

        if(algarismosSub.valorDe(fatorX[i]) >= algarismosSub.valorDe(fatorY[i]))
        {
            result.insert(result.begin(), subtracaoUnica(fatorX[i], fatorY[i]));
        }
        else
        {
            int tempNumber1 = algarismosSub.valorDe(fatorX[i]);
            int tempNumber2 = algarismosSub.valorDe(fatorY[i]);

            tempNumber1 += base;

            result.insert(result.begin(), algarismosSub.caracterDe(tempNumber1 - tempNumber2));

            int temp = i-1;
            while(fatorX[temp] == '0' or fatorX[temp] == ',')
            {
                if(fatorX[temp] == ',')
                {
                    temp--;
                    continue;
                }

                fatorX[temp] = algarismosSub.caracterDe(base - 1);
                temp--;
            }
            fatorX[temp] = algarismosSub.caracterDe(algarismosSub.valorDe(fatorX[temp]) - 1);
        }
    }

    if (negativo)
        this -> diferenca = "-";

    result = utilsSub.removeTrailingZeroes(result);

    this -> diferenca = result;
}

char Subtradora::subtracaoUnica(char number1, char number2)
{
    int diferenca = algarismosSub.valorDe(number1) -
                    algarismosSub.valorDe(number2);

    return algarismosSub.caracterDe(diferenca);

}