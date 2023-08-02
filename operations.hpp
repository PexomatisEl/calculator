const double pi = 3.14159265358979323846;
const double e = 2.71828182845904523536;

void praxis(std::vector<std::string> &string1) // str1
{
    int countPower = count(string1.begin(), string1.end(), "^"); // countp
    // std::string powr = "^";
    
    for (int i = 0; i < countp; i++)
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

    int countMultDiv = count(string1.begin(), string1.end(), "*");
    countmd += count(string1.begin(), string1.end(), "/");
    std::string mlt = "*", dvs = "/";
    
    for (int i = 0; i < countmd; i++)
    {
        std::vector<std::string>::iterator indmin;
        auto indexm = std::find(string1.begin(), string1.end(), mlt);
        auto indexd = std::find(string1.begin(), string1.end(), dvs);
        (indexm < indexd) ? (indmin = indexm) : (indmin = indexd);
        int k = std::distance(string1.begin(), indmin);
        double x = std::stod(string1[k - 1]);
        double y = std::stod(string1[k + 1]);
        double z(0);
        (string1[k] == "*") ? (z = x * y) : (z = x / y);
        std::string h = std::to_string(z);
        string1.emplace(indmin - 1, h);
        indmin = string1.begin() + k;
        string1.erase(indmin, indmin + 3);
    }

    int countas = count(string1.begin(), string1.end(), "+");
    countas += count(string1.begin(), string1.end(), "-");
    std::string addi = "+", subt = "-";
    
    for (int i = 0; i < countas; i++)
    {
        std::vector<std::string>::iterator indmin;
        auto indexa = std::find(string1.begin(), string1.end(), addi);
        auto indexs = std::find(string1.begin(), string1.end(), subt);
        (indexa < indexs) ? (indmin = indexa) : (indmin = indexs);
        int k = std::distance(string1.begin(), indmin);
        double x = std::stod(string1[k - 1]);
        double y = std::stod(string1[k + 1]);
        double z(0);
        (string1[k] == "+") ? (z = x + y) : (z = x - y);
        std::string h = std::to_string(z);
        string1.emplace(indmin - 1, h);
        indmin = string1.begin() + k;
        string1.erase(indmin, indmin + 3);
    }
}
