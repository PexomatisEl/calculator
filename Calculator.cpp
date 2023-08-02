#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include "operations.hpp"


int main()
{
    std::string str, temp;
    std::vector<std::string> opmain;

    //std::cout << "Type in an arithmetic expression to be calculated: \n";
    //std::getline(std::cin, str);
    //std::cout << str;

    str = "sin(pi)+e^ln(-5)";
    
    int i = 0;
    if (str[0] == '-' && !(str[1] == '(')) { temp.push_back(str[0]); i++; }
    int counterr = 0;
    bool check = false;
    if (str[0] == '-' && str[1] == '(') {
        check = true;
        str.erase(str.begin());
        int counterl = 1, n = str.size();
        for (int j = 1; j < n; j++) {
            if (str[j] == '(') { counterl++; }
            else if (str[j] == ')') { counterr++; }
            if (counterl == counterr) { break; }
        }
    }

    while (i < str.size()) {
        while (isalpha(str[i])) {
            temp.push_back(str[i]);
            i++;
            if (i >= str.size()) { break; }
        }
        if (temp.size()) { opmain.push_back(temp); }
        if (i >= str.size()) { break; }
        temp.clear();
        while (isdigit(str[i]) || str[i] == '.') {
            temp.push_back(str[i]);
            i++;
            if (i >= str.size()) { break; }
        }
        if (temp.size()) { opmain.push_back(temp); }
        if (i >= str.size()) { break; }
        temp.clear();
        temp = str[i];
        opmain.push_back(temp);
        temp.clear();
        i++;
    }
    for (int i = 0; i < opmain.size(); i++) {
        if (opmain[i] == "pi") { opmain[i] = "3.14159265358979323846"; }
        if (opmain[i] == "e") { opmain[i] = "2.71828182845904523536"; }
    }

    for (int i = 0; i < opmain.size(); i++) {
        std::cout << opmain[i] << std::endl;
    }
    
    // Parenthesis
    int c1 = count(opmain.begin(), opmain.end(), "("),
        c2 = count(opmain.begin(), opmain.end(), ")");
    if (c1 != c2) { std::cout << "The multitudes of ( and ) don't match."; return 0; }
    for (int i = 0; i < c2; i++) {
        auto indexr = find(opmain.begin(), opmain.end(), ")");
        int pos1(0), pos2 = distance(opmain.begin(), indexr);
        for (int j = pos2; j >= 0; j--) {
            if (opmain[j] == "(") { pos1 = j; break; }
        }
        std::vector<std::string> par;
        for (int j = pos1 + 1; j < pos2; j++) {
            if (opmain[pos1 + 1] == "-" && j == pos1 + 1) {
                double y = stod(opmain[pos1 + 2]) * (-1);
                std::string z = std::to_string(y);
                par.push_back(z);
                j += 2;
            }
            par.push_back(opmain[j]);
        }
        praxis(par);
        if (check && i + 1 == counterr) {
            double k = stod(par[0]) * (-1);
            std::string p = std::to_string(k);
            par.clear();
            par.push_back(p);
            check = false;
        }
        auto indexl = opmain.begin() + pos1;
        opmain.emplace(indexl, par[0]);
        indexl = opmain.begin() + pos1 + 1;
        indexr = opmain.begin() + pos2 + 1;
        opmain.erase(indexl, indexr + 1);
        if (std::all_of(opmain[pos1 - 1].begin(), opmain[pos1 - 1].end(), [](char c) {return isalpha(c); }) && pos1 != 0) {
            double x = stod(opmain[pos1]);
            if (opmain[pos1 - 1] == "sin") { x = sin(x); }
            if (opmain[pos1 - 1] == "cos") { x = cos(x); }
            if (opmain[pos1 - 1] == "tan") { x = tan(x); }
            if (opmain[pos1 - 1] == "cot") { x = 1/tan(x); }
            if (opmain[pos1 - 1] == "ln") { if (x <= 0) { std::cout << "Negative number in logarithm!"; return 0; } else { x = log(x); } }
            if (opmain[pos1 - 1] == "log") { if (x <= 0) { std::cout << "Negative number in logarithm!"; return 0; } else { x = log10(x); } }
            if (opmain[pos1 - 1] == "sqrt") { if (x < 0) { std::cout << "Negative number in square root!"; return 0; } else { x = sqrt(x); } }
            std::string z = std::to_string(x);
            auto indexl = opmain.begin() + pos1 - 1;
            opmain.emplace(indexl, z);
            indexl = opmain.begin() + pos1;
            opmain.erase(indexl, indexl + 2);
        }
    }

    // Final praxis
    praxis(opmain);

    std::cout << opmain[0];
    

    return 0;
}
