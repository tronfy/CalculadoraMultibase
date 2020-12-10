#include <iostream>
#include "Divisora.h"
#include "Subtradora.h"
#include "Multiplicadora.h"
#include "Algarismos.h"
#include "Utils.h"

Utils utilsDiv;
Subtradora subtradoraDiv;
Multiplicadora multiplicadoraDiv;

Algarismos algarismosDiv;

void Divisora::setValores(std::string fatorX, std::string fatorY, int base) {
    this -> fatorX = fatorX;
    this -> fatorY= fatorY;
    this -> base = base;

    this -> dividir();
}

std::string Divisora::getResultado() {
    return this -> quociente;
}

void Divisora::dividir() {
    std::string result = "";
    std::string dividendo = fatorX;
    std::string divisor = fatorY;
    std::string tempDiv;
    char semiQuociente;
	
	while(utilsDiv.compareTwoString(dividendo, divisor) > 0)
	{
        tempDiv = menorNumeroDivisivel(dividendo, divisor);
        semiQuociente = acharQuociente(tempDiv, divisor);		
		
		result.insert(result.end(), semiQuociente);

		multiplicadoraDiv.setValores(divisor, utilsDiv.toString(semiQuociente), base);

		std::string resultadoDivisao = multiplicadoraDiv.getResultado();
		int diferenca = dividendo.length() - tempDiv.length();
		resultadoDivisao = resultadoDivisao.substr(0, resultadoDivisao.find(','));
		
		tempDiv = utilsDiv.colocarZeros(resultadoDivisao, diferenca);
		subtradoraDiv.setValores(dividendo, tempDiv, base);
		dividendo = subtradoraDiv.getResultado();
		dividendo = dividendo.substr(0, dividendo.find(','));

	}
	result.insert(result.end(), ',');
	for(int i = 0; i < 5; i++)
	{
		dividendo.insert(dividendo.end(), '0');
        if(utilsDiv.compareTwoString(dividendo,divisor) > 0)
        {
			semiQuociente = acharQuociente(dividendo, divisor);

			result.insert(result.end(), semiQuociente);
			multiplicadoraDiv.setValores(divisor, utilsDiv.toString(semiQuociente), base);

			std::string resultadoDivisao = multiplicadoraDiv.getResultado();

			resultadoDivisao = resultadoDivisao.substr(0, resultadoDivisao.find(','));

			subtradoraDiv.setValores(dividendo, resultadoDivisao, base);
			dividendo = subtradoraDiv.getResultado();
			dividendo = dividendo.substr(0, dividendo.find(','));
	
        }
        else
        {
            result.insert(result.end(), '0');
        }
	}

	std::cout << result;
}

std::string Divisora::menorNumeroDivisivel(std::string dividendo, std::string divisor)
{
	std::string tempDiv;

    for(int i=0; i<=dividendo.length(); i++)
	{
		tempDiv = dividendo.substr(0, i);
        if(utilsDiv.compareTwoString(tempDiv, divisor) >= 0)
            return tempDiv;
	}

}

char Divisora::acharQuociente(std::string dividendo, std::string divisor) {
    std::string numADividir;
	std::string prox;
    for(int i=0; i<base; i++)
    {
		prox = algarismosDiv.caracterDe(i+1);
		multiplicadoraDiv.setValores(divisor, prox, base);

		numADividir = multiplicadoraDiv.getResultado();
		numADividir = numADividir.substr(0, numADividir.find(','));
        if(utilsDiv.compareTwoString(dividendo, numADividir) < 0)
		{
			return algarismosDiv.caracterDe(i);
		}
    }
}