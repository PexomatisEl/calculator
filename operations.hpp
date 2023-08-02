const double pi = 3.14159265358979323846;
const double e = 2.71828182845904523536;

void praxis(std::vector<std::string> &string1) // str1
{
    int countPower = count(string1.begin(), string1.end(), "^"); // countp
    // std::string powr = "^";
    
    for (int i = 0; i < countPower; i++)
    {
        auto iteratorFirstPower = std::find(string1.begin(), string1.end(), "^"); // indexp
        int indexFirstPower = std::distance(string1.begin(), iteratorFirstPower); // k
        double base = std::stod(string1[k - 1]); // x
        double power = std::stod(string1[k + 1]); // y
        double result = pow(base, power); // z
        std::string resultString = std::to_string(result); // h
        string1.emplace(indexp - 1, resultString);
        iteratorFirstPower = string1.begin() + indexFirstPower;
        string1.erase(iteratorFirstPower, iteratorFirstPower + 3);
    }

    int countMultDiv = count(string1.begin(), string1.end(), "*"); // countmp
    countMultDiv += count(string1.begin(), string1.end(), "/");
    // std::string mlt = "*", dvs = "/";
    
    for (int i = 0; i < countMultDiv; i++)
    {
        std::vector<std::string>::iterator iteratorFirstMultDiv; // indmin
        auto iteratorFirstMult = std::find(string1.begin(), string1.end(), "*"); // indexm
        auto iteratorFirstDiv = std::find(string1.begin(), string1.end(), "/"); // indexd
        (iteratorFirstMult < iteratorFirstDiv) ? (iteratorFirstMultDiv = iteratorFirstMult) : (iteratorFirstMultDiv = iteratorFirstDiv);
        int indexFirstMultDiv = std::distance(string1.begin(), iteratorFirstMultDiv); // k
        double firstOperand = std::stod(string1[indexFirstMultDiv - 1]); // x
        double secondOperand = std::stod(string1[indexFirstMultDiv + 1]); // y
        double result(0); // z
        (string1[indexFirstMultDiv] == "*") ? (result = firstOperand * secondOperand) : (result = firstOperand / secondOperand);
        std::string resultString = std::to_string(result); // h
        string1.emplace(iteratorFirstMultDiv - 1, resultString);
        iteratorFirstMultDiv = string1.begin() + indexFirstMultDiv;
        string1.erase(iteratorFirstMultDiv, iteratorFirstMultDiv + 3);
    }

    int countAddSub = count(string1.begin(), string1.end(), "+"); // countas
    countAddSub += count(string1.begin(), string1.end(), "-");
    // std::string addi = "+", subt = "-";
    
    for (int i = 0; i < countAddSub; i++)
    {
        std::vector<std::string>::iterator iteratorFirstAddSub; // indmin
        auto iteratorFirstAdd = std::find(string1.begin(), string1.end(), "+"); // indexa
        auto iteratorFirstSub = std::find(string1.begin(), string1.end(), "-"); // indexs
        (iteratorFirstAdd < iteratorFirstSub) ? (iteratorFirstAddSub = iteratorFirstAdd) : (iteratorFirstAddSub = iteratorFirstSub);
        int indexFirstAddSub = std::distance(string1.begin(), iteratorFirstAddSub); // k
        double firstOperand = std::stod(string1[indexFirstAddSub - 1]); // x
        double secondOperand = std::stod(string1[indexFirstAddSub + 1]); // y
        double result(0);
        (string1[indexFirstAddSub] == "+") ? (result = firstOperand + secondOperand) : (result = firstOperand - secondOperand);
        std::string resultString = std::to_string(result); // h
        string1.emplace(iteratorFirstAddSub - 1, resultString);
        iteratorFirstAddSub = string1.begin() + indexFirstAddSub;
        string1.erase(iteratorFirstAddSub, iteratorFirstAddSub + 3);
    }
}
