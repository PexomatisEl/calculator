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
    std::cout << inputStr;

    
    
    int i = 0;
    
    if ( inputStr[0] == '-'  &&  !(inputStr[1] == '(' ) ) 
    {
        temp.push_back(inputStr[0]); 
        i++; 
    }
    int counterRightPar = 0;
    bool check = false;
    
    if (inputStr[0] == '-' && inputStr[1] == '(') 
    {
        check = true;
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

    while (i < inputStr.size()) 
    {
        
        while ( isalpha( inputStr[i] ) ) 
        {
            temp.push_back(inputStr[i]);
            i++;
            if (i >= inputStr.size()) 
            {
                break; 
            }
            
        }
        
        if ( temp.size() ) 
        {
            operationVec.push_back(temp); 
        }
        
        if (i >= inputStr.size()) 
        {
            break; 
        }
        
        temp.clear();
        
        while ( isdigit( inputStr[i] ) || inputStr[i] == '.' ) 
        {
            temp.push_back( inputStr[i] );
            i++;
            if ( i >= inputStr.size() ) 
            {
                break; 
            }
        }
        
        if ( temp.size() ) 
        {
            operationVec.push_back(temp); 
        }
        
        if ( i >= inputStr.size() ) 
        {
            break; 
        }
        
        temp.clear();
        temp = inputStr[i];
        operationVec.push_back(temp);
        temp.clear();
        i++;
    }
    
    for (int i = 0; i < operationVec.size(); i++) 
    {
        if (operationVec[i] == "pi") 
        {
            operationVec[i] = "3.14159265358979323846"; 
        }
        
        if (operationVec[i] == "e") 
        {
            operationVec[i] = "2.71828182845904523536"; 
        }
    }

    for (int i = 0; i < operationVec.size(); i++) 
    {
        std::cout << operationVec[i] << std::endl;
    }
    
    // Parenthesis
    int counterLeftPar = count( operationVec.begin(), operationVec.end(), "(" ),
        counterRightPar = count( operationVec.begin(), operationVec.end(), ")" );
        
    for (int i = 0; i < counterRightPar; i++) 
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
            
            if ( operationVec[indexLeftPar + 1] == "-" && j == indexLeftPar + 1) 
            {
                double doubleResult= stod( operationVec[indexLeftPar + 2] ) * (-1);
                std::string strResult= std::to_string(doubleResult);
                containsParenthesis.push_back(strResult);
                j += 2;
            }
            
            containsParenthesis.push_back( operationVec[j] );
        }
        
        praxis( containsParenthesis );
        
        if (check && i + 1 == counterRightPar) 
        {
            double k = stod(containsParenthesis[0]) * (-1);
            std::string p = std::to_string(k);
            containsParenthesis.clear();
            containsParenthesis.push_back(p);
            check = false;
        }
        
        auto iteratorFirstLeftPar = operationVec.begin() + indexLeftPar;
        operationVec.emplace(iteratorFirstLeftPar, containsParenthesis[0]);
        iteratorFirstLeftPar = operationVec.begin() + indexLeftPar + 1;
        iteratorFirstRightPar = operationVec.begin() + indexRightPar + 1;
        operationVec.erase(iteratorFirstLeftPar, iteratorFirstRightPar + 1);
        
        if (std::all_of(operationVec[indexLeftPar - 1].begin(), operationVec[indexLeftPar - 1].end(), [](char c) {return isalpha(c); }) && indexLeftPar != 0) 
        {
            double x = stod( operationVec[indexLeftPar] );
            
            if (operationVec[indexLeftPar - 1] == "sin")
            {
                x = sin(x); 
            }
            
            if (operationVec[indexLeftPar - 1] == "cos") 
            {
                x = cos(x); 
            }
            
            if (operationVec[indexLeftPar - 1] == "tan") 
            {
                x = tan(x); 
            }
            
            if (operationVec[indexLeftPar - 1] == "cot") 
            {
                x = 1/tan(x); 
            }
            
            if (operationVec[indexLeftPar - 1] == "ln") 
            {
                if (x <= 0) 
                { 
                    std::cout << "Negative number in logarithm!";
                    return 0; 
                } 
                else 
                { 
                    x = log(x); 
                } 
            }
            
            if (operationVec[indexLeftPar - 1] == "log") 
            {
                if (x <= 0) 
                {
                    std::cout << "Negative number in logarithm!"; 
                             return 0; 
                            }
                else 
                {
                    x = log10(x); 
                } 
            }
            
            if (operationVec[indexLeftPar - 1] == "sqrt") 
            {
                if (x < 0) 
                {
                    std::cout << "Negative number in square root!"; 
                    return 0; 
                } 
                else 
                {
                    x = sqrt(x); 
                } 
            }
            
            std::string strResult= std::to_string(x);
            auto iteratorFirstLeftPar = operationVec.begin() + indexLeftPar - 1;
            operationVec.emplace(iteratorFirstLeftPar, strResult);
            iteratorFirstLeftPar = operationVec.begin() + indexLeftPar;
            operationVec.erase(iteratorFirstLeftPar, iteratorFirstLeftPar + 2);
        }
    }

    // Final praxis
    praxis( operationVec );

    std::cout << operationVec[0];
    

    return 0;
}
