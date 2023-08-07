#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include "operations.hpp"

int main()
{
    std::string inputStr, temp;
    std::vector<std::string> operationVec;

    std::cout << "Type in an arithmetic expression to be calculated: \n";
    std::getline(std::cin, inputStr);

    int i = 0;
    bool blueFlag = false;

    if (inputStr[0] == '-' && isdigit(inputStr[1]))
    {
        inputStr.erase(inputStr.begin());
        blueFlag = true;
    }

    int counterRightPar = 0;
    bool redFlag = false;

    if (inputStr[0] == '-' && inputStr[1] == '(')
    {
        redFlag = true;
        inputStr.erase(inputStr.begin());
        int counterLeftPar = 1, n = inputStr.size();

        for (int j = 1; j < n; j++)
        {
            if (inputStr[j] == '(')
            {
                counterLeftPar++;
            }
            else if (inputStr[j] == ')')
            {
                counterRightPar++;
            }

            if (counterLeftPar == counterRightPar)
            {
                break;
            }
        }
    }

    bool yellowFlag = false;

    if (inputStr[0] == '-' && isalpha(inputStr[1]))
    {
        inputStr.erase(inputStr.begin());
        yellowFlag = true;
    }

    while (i < inputStr.size())
    {
        while (isalpha(inputStr[i]))
        {
            temp.push_back(inputStr[i]);
            i++;
            if (i >= inputStr.size())
            {
                break;
            }
        }

        if (temp.size())
        {
            operationVec.push_back(temp);
        }

        if (i >= inputStr.size())
        {
            break;
        }

        temp.clear();

        while (isdigit(inputStr[i]) || inputStr[i] == '.')
        {
            temp.push_back(inputStr[i]);
            i++;
            if (i >= inputStr.size())
            {
                break;
            }
        }

        if (temp.size())
        {
            operationVec.push_back(temp);
        }

        if (i >= inputStr.size())
        {
            break;
        }

        temp.clear();
        temp = inputStr[i];
        operationVec.push_back(temp);
        temp.clear();
        i++;
    }
    for (int j = 0; j < operationVec.size(); j++)
    {
        if (operationVec[j] == "pi")
        {
            operationVec[j] = "3.14159265358979323846";
        }

        if (operationVec[j] == "e")
        {
            operationVec[j] = "2.71828182845904523536";
        }
    }

    if (blueFlag)
    {
        double z = stod(operationVec[0]) * (-1);
        operationVec[0] = std::to_string(z);
    }

    bool greenFlag = false;

    if (blueFlag && operationVec[1] == "^")
    {
        greenFlag = true;
    }

    for (int j = 0; j < operationVec.size(); j++)
    {
        std::cout << operationVec[j] << std::endl;
    }

    // Parenthesis
    int c1 = count(operationVec.begin(), operationVec.end(), "("),
        c2 = count(operationVec.begin(), operationVec.end(), ")");
    if (c1 != c2)
    {
        std::cout << "The multitudes of ( and ) don't match.";
        return 0;
    }

    for (int i = 0; i < c2; i++)
    {
        auto iteratorFirstRightPar = find(operationVec.begin(), operationVec.end(), ")");
        int indexLeftPar(0), indexRightPar = distance(operationVec.begin(), iteratorFirstRightPar);

        for (int j = indexRightPar; j >= 0; j--)
        {
            if (operationVec[j] == "(")
            {
                indexLeftPar = j;
                break;
            }
        }

        std::vector<std::string> containsParenthesis;

        for (int j = indexLeftPar + 1; j < indexRightPar; j++)
        {
            if (operationVec[indexLeftPar + 1] == "-" && j == indexLeftPar + 1)
            {
                double y = stod(operationVec[indexLeftPar + 2]) * (-1);
                std::string result = std::to_string(y);
                containsParenthesis.push_back(result);
                j += 2;
            }
            containsParenthesis.push_back(operationVec[j]);
        }

        praxis(containsParenthesis, greenFlag);

        if (redFlag && i + 1 == counterRightPar)
        {
            double k = stod(containsParenthesis[0]) * (-1);
            std::string p = std::to_string(k);
            containsParenthesis.clear();
            containsParenthesis.push_back(p);
            redFlag = false;
        }

        auto iteratorFirstLeftPar = operationVec.begin() + indexLeftPar;
        operationVec.emplace(iteratorFirstLeftPar, containsParenthesis[0]);
        iteratorFirstLeftPar = operationVec.begin() + indexLeftPar + 1;
        iteratorFirstRightPar = operationVec.begin() + indexRightPar + 1;
        operationVec.erase(iteratorFirstLeftPar, iteratorFirstRightPar + 1);

        if (indexLeftPar != 0 && std::all_of(operationVec[indexLeftPar - 1].begin(), operationVec[indexLeftPar - 1].end(), [](char c){return isalpha(c); }))
        {
            double x = stod(operationVec[indexLeftPar]);
            if (operationVec[indexLeftPar - 1] == "sin") { x = sin(x); }
            if (operationVec[indexLeftPar - 1] == "cos") { x = cos(x); }
            if (operationVec[indexLeftPar - 1] == "tan") { x = tan(x); }
            if (operationVec[indexLeftPar - 1] == "cot") { x = 1 / tan(x); }
            if (operationVec[indexLeftPar - 1] == "ln") { if (x <= 0) { std::cout << "Negative number in logarithm!"; return 0; } else { x = log(x); } }
            if (operationVec[indexLeftPar - 1] == "log") { if (x <= 0) { std::cout << "Negative number in logarithm!"; return 0; } else { x = log10(x); } }
            if (operationVec[indexLeftPar - 1] == "sqrt") { if (x < 0) { std::cout << "Negative number in square root!"; return 0; } else { x = sqrt(x); } }
            
            if (yellowFlag)
            {
                x *= (-1);
                yellowFlag = false;
            }

            std::string z = std::to_string(x);
            auto iteratorFirstLeftPar = operationVec.begin() + indexLeftPar - 1;
            operationVec.emplace(iteratorFirstLeftPar, z);
            iteratorFirstLeftPar = operationVec.begin() + indexLeftPar;
            operationVec.erase(iteratorFirstLeftPar, iteratorFirstLeftPar + 2);
        }
    }

    // Final praxis
    praxis(operationVec, greenFlag);

    std::cout << operationVec[0];

    return 0;
}


