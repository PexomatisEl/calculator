const double pi = 3.14159265358979323846;
const double e = 2.71828182845904523536;

void praxis( std::vector<std::string> &string1 ) 
{
    int countPower = count( string1.begin(), string1.end(), "^" );
    
    for ( int i = 0; i < countPower; i++ )
    {
        auto iteratorFirstPower = std::find( string1.begin(), string1.end(), "^" ); 
        int indexFirstPower = std::distance( string1.begin(), iteratorFirstPower ); 
        double base = std::stod( string1[k - 1] );
        double power = std::stod( string1[k + 1] ); 
        double doubleResult = pow( base, power );
        std::string strResulttring = std::to_string( doubleResult );
        string1.emplace( indexp - 1, strResulttring );
        iteratorFirstPower = string1.begin() + indexFirstPower;
        string1.erase( iteratorFirstPower, iteratorFirstPower + 3 );
    }

    int countMultDiv = count( string1.begin(), string1.end(), "*" );
    countMultDiv += count( string1.begin(), string1.end(), "/" );
    
    for ( int i = 0; i < countMultDiv; i++ )
    {
        std::vector<std::string>::iterator iteratorFirstMultDiv; 
        auto iteratorFirstMult = std::find( string1.begin(), string1.end(), "*" ); 
        auto iteratorFirstDiv = std::find( string1.begin(), string1.end(), "/" ); 
        ( iteratorFirstMult < iteratorFirstDiv ) ? ( iteratorFirstMultDiv = iteratorFirstMult ) : ( iteratorFirstMultDiv = iteratorFirstDiv );
        int indexFirstMultDiv = std::distance( string1.begin(), iteratorFirstMultDiv ); 
        double firstOperand = std::stod( string1[indexFirstMultDiv - 1] ); 
        double secondOperand = std::stod( string1[indexFirstMultDiv + 1] ); 
        double doubleResult(0); 
        ( string1[indexFirstMultDiv] == "*" ) ? ( doubleResult = firstOperand * secondOperand ) : ( doubleResult = firstOperand / secondOperand );
        std::string strResulttring = std::to_string( doubleResult ); 
        string1.emplace( iteratorFirstMultDiv - 1, strResulttring );
        iteratorFirstMultDiv = string1.begin() + indexFirstMultDiv;
        string1.erase( iteratorFirstMultDiv, iteratorFirstMultDiv + 3 );
    }

    int countAddSub = count( string1.begin(), string1.end(), "+" );
    countAddSub += count( string1.begin(), string1.end(), "-" );
    
    for ( int i = 0; i < countAddSub; i++ )
    {
        std::vector<std::string>::iterator iteratorFirstAddSub; 
        auto iteratorFirstAdd = std::find( string1.begin(), string1.end(), "+" );
        auto iteratorFirstSub = std::find( string1.begin(), string1.end(), "-" ); 
        ( iteratorFirstAdd < iteratorFirstSub ) ? ( iteratorFirstAddSub = iteratorFirstAdd ) : ( iteratorFirstAddSub = iteratorFirstSub );
        int indexFirstAddSub = std::distance( string1.begin(), iteratorFirstAddSub ); 
        double firstOperand = std::stod( string1[indexFirstAddSub - 1] );
        double secondOperand = std::stod( string1[indexFirstAddSub + 1] );
        double doubleResult(0);
        ( string1[indexFirstAddSub] == "+" ) ? ( doubleResult = firstOperand + secondOperand ) : ( doubleResult = firstOperand - secondOperand );
        std::string strResulttring = std::to_string( doubleResult ); // h
        string1.emplace( iteratorFirstAddSub - 1, strResulttring );
        iteratorFirstAddSub = string1.begin() + indexFirstAddSub;
        string1.erase( iteratorFirstAddSub, iteratorFirstAddSub + 3 );
    }
}
