#include <bits/stdc++.h>

// Se crea una clase que pueda almacenar un numero entero de muchos digitos
class BigInt
{
public:
    std::vector<int> digits;

    BigInt(int n)
    {
        while (n)
        {
            digits.push_back(n % 10);
            n /= 10;
        }
    }


    // multiplicacion de dos numeros 
    BigInt operator*(const BigInt &other) const
    {
        BigInt result(0);
        result.digits.resize(digits.size() + other.digits.size());
        for (int i = 0; i < digits.size(); i++)
        {
            for (int j = 0; j < other.digits.size(); j++)
            {
                result.digits[i + j] += digits[i] * other.digits[j];
            }
        }
        for (int i = 0; i < result.digits.size() - 1; i++)
        {
            result.digits[i + 1] += result.digits[i] / 10;
            result.digits[i] %= 10;
        }
        while (result.digits.back() == 0 && result.digits.size() > 1)
        {
            result.digits.pop_back();
        }
        return result;
    }

    // impresion de su valor numerico
    friend std::ostream &operator<<(std::ostream &os, const BigInt &other)
    {
        for (int i = other.digits.size() - 1; i >= 0; i--)
        {
            os << other.digits[i];
        }
        return os;
    }
};


// similar al factorial pero sin contar los numeros que lo dividen por las letras repetidas
BigInt multiply(std::vector<int> &a)
{
    BigInt fact(1);
    for (int i = 0; i < a.size(); i++)
    {
        fact = fact * BigInt(a[i]);
    }
    return fact;
}

// Dado los numeros del factorial, se "cancelan" los numeros que lo dividen
BigInt divide(std::vector<int> fact_numbers, std::vector<int> divisors)
{
    for (auto &d : divisors)
    {
        auto resultado = std::find(fact_numbers.begin(), fact_numbers.end(), d);
        if ( resultado != fact_numbers.end())
        {
            fact_numbers.erase(resultado);
            divisors.erase(std::find(divisors.begin(), divisors.end(), d));
        }
    }

    for (int i = 0; i < fact_numbers.size(); i++)
    {
        for (int j = 0; j < divisors.size(); j++)
        {
            if (fact_numbers[i] % divisors[j] == 0)
            {
                fact_numbers[i] /= divisors[j];
                divisors.erase(divisors.begin() + j);
            }
        }
    }

    return multiply(fact_numbers);
}

BigInt result(std::string str)
{
    // se cuentan las letras repetidas y unicas
    std::unordered_map<char, int> char_map;
    for (int i = 0; i < str.size(); i++)
    {
        if(char_map.find(str[i]) == char_map.end())
        {
            char_map[str[i]] = 1;
        }
        else
        {
            char_map[str[i]]++;
        }
    }
    std::vector<int> fact_numbers;
    std::vector<int> divisors;
    for (int k = 1; k < str.size()+1; k++)
    {
        fact_numbers.push_back(k);
    }

    for (auto it = char_map.begin(); it != char_map.end(); it++)
    {
        if (it->second > 1)
        {
            divisors.push_back(it->second);
        }
    }

    return divide(fact_numbers, divisors);
}

int main()
{
    std::string cadena;
    while(std::cin >> cadena)
        std::cout<< result(cadena) << std::endl;

    return 0;
}