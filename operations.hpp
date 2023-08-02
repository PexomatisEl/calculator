const double pi = 3.14159265358979323846;
const double e = 2.71828182845904523536;

void praxis(std::vector<std::string> &str1)
{
    int countp = count(str1.begin(), str1.end(), "^");
    std::string powr = "^";
    
    for (int i = 0; i < countp; i++) {
        auto indexp = std::find(str1.begin(), str1.end(), powr);
        int k = std::distance(str1.begin(), indexp);
        double x = std::stod(str1[k - 1]);
        double y = std::stod(str1[k + 1]);
        double z = pow(x, y);
        std::string h = std::to_string(z);
        str1.emplace(indexp - 1, h);
        indexp = str1.begin() + k;
        str1.erase(indexp, indexp + 3);
    }

    int countmd = count(str1.begin(), str1.end(), "*");
    countmd += count(str1.begin(), str1.end(), "/");
    std::string mlt = "*", dvs = "/";
    
    for (int i = 0; i < countmd; i++)
    {
        std::vector<std::string>::iterator indmin;
        auto indexm = std::find(str1.begin(), str1.end(), mlt);
        auto indexd = std::find(str1.begin(), str1.end(), dvs);
        (indexm < indexd) ? (indmin = indexm) : (indmin = indexd);
        int k = std::distance(str1.begin(), indmin);
        double x = std::stod(str1[k - 1]);
        double y = std::stod(str1[k + 1]);
        double z(0);
        (str1[k] == "*") ? (z = x * y) : (z = x / y);
        std::string h = std::to_string(z);
        str1.emplace(indmin - 1, h);
        indmin = str1.begin() + k;
        str1.erase(indmin, indmin + 3);
    }

    int countas = count(str1.begin(), str1.end(), "+");
    countas += count(str1.begin(), str1.end(), "-");
    std::string addi = "+", subt = "-";
    
    for (int i = 0; i < countas; i++)
    {
        std::vector<std::string>::iterator indmin;
        auto indexa = std::find(str1.begin(), str1.end(), addi);
        auto indexs = std::find(str1.begin(), str1.end(), subt);
        (indexa < indexs) ? (indmin = indexa) : (indmin = indexs);
        int k = std::distance(str1.begin(), indmin);
        double x = std::stod(str1[k - 1]);
        double y = std::stod(str1[k + 1]);
        double z(0);
        (str1[k] == "+") ? (z = x + y) : (z = x - y);
        std::string h = std::to_string(z);
        str1.emplace(indmin - 1, h);
        indmin = str1.begin() + k;
        str1.erase(indmin, indmin + 3);
    }
}
